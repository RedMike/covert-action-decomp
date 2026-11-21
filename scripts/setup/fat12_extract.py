#!/usr/bin/env python3
"""Extract the contents of a raw FAT12 floppy image, as the MSC 5.1 and MASM
5.1 distribution disks are, with no emulator and no mount.

Usage:
    python fat12_extract.py IMAGE... --dest DIR [--list] [--flat]

    --dest   directory to extract into; one subdirectory per image,
             named after the image's stem
    --list   print the directory tree, extract nothing
    --flat   ignore subdirectories in the image, extract everything into
             one directory

File timestamps from the directory entries are preserved.
"""

import argparse
import datetime
import os
import struct
import sys

ATTR_VOLUME_LABEL = 0x08
ATTR_DIRECTORY = 0x10

DELETED = 0xE5
END_OF_DIR = 0x00


class Fat12Error(Exception):
    pass


class Fat12:
    def __init__(self, data):
        self.data = data
        if len(data) < 512:
            raise Fat12Error("image is shorter than one sector")

        # BPB, at offset 11 in the boot sector.
        (
            self.bytes_per_sector,
            self.sectors_per_cluster,
            self.reserved_sectors,
            self.num_fats,
            self.root_entries,
            self.total_sectors,
            _media,
            self.sectors_per_fat,
        ) = struct.unpack_from("<HBHBHHBH", data, 11)

        if self.bytes_per_sector not in (512, 1024):
            raise Fat12Error(f"implausible sector size {self.bytes_per_sector}")
        if not self.sectors_per_cluster or not self.num_fats:
            raise Fat12Error("BPB has a zero cluster or FAT count")

        self.fat_start = self.reserved_sectors * self.bytes_per_sector
        self.root_start = self.fat_start + (
            self.num_fats * self.sectors_per_fat * self.bytes_per_sector
        )
        root_bytes = self.root_entries * 32
        self.data_start = self.root_start + root_bytes
        self.cluster_size = self.sectors_per_cluster * self.bytes_per_sector

    def fat_entry(self, cluster):
        """Read one 12-bit FAT entry. Entries are packed three bytes per pair."""
        offset = self.fat_start + (cluster * 3) // 2
        pair = struct.unpack_from("<H", self.data, offset)[0]
        return pair & 0x0FFF if cluster % 2 == 0 else pair >> 4

    def cluster_chain(self, first):
        """Walk the FAT from `first`, yielding each cluster number in order."""
        cluster = first
        seen = set()
        while 0x002 <= cluster <= 0xFEF:
            if cluster in seen:
                raise Fat12Error(f"cluster chain loops at {cluster}")
            seen.add(cluster)
            yield cluster
            cluster = self.fat_entry(cluster)

    def read_chain(self, first, size=None):
        out = bytearray()
        for cluster in self.cluster_chain(first):
            # Cluster numbering starts at 2, and cluster 2 is the first
            # cluster of the data area.
            offset = self.data_start + (cluster - 2) * self.cluster_size
            out += self.data[offset : offset + self.cluster_size]
        return bytes(out[:size]) if size is not None else bytes(out)

    def read_dir(self, first_cluster=None):
        """Yield (name, attr, first_cluster, size, mtime) for one directory.

        Passing None reads the fixed-position root directory.
        """
        if first_cluster is None:
            raw = self.data[self.root_start : self.data_start]
        else:
            raw = self.read_chain(first_cluster)

        for i in range(0, len(raw), 32):
            entry = raw[i : i + 32]
            if len(entry) < 32 or entry[0] == END_OF_DIR:
                return
            if entry[0] == DELETED:
                continue

            attr = entry[11]
            if attr & ATTR_VOLUME_LABEL:
                continue
            # Long-filename entries, attribute 0x0F, are skipped.
            if attr == 0x0F:
                continue

            stem = entry[0:8].decode("cp437").rstrip()
            ext = entry[8:11].decode("cp437").rstrip()
            if stem in (".", ".."):
                continue
            name = f"{stem}.{ext}" if ext else stem

            time_word, date_word, cluster, size = struct.unpack_from("<HHHI", entry, 22)
            yield name, attr, cluster, size, dos_timestamp(date_word, time_word)


def dos_timestamp(date_word, time_word):
    """Convert a packed DOS date/time pair to a POSIX timestamp, or None."""
    year = ((date_word >> 9) & 0x7F) + 1980
    month = (date_word >> 5) & 0x0F
    day = date_word & 0x1F
    hour = (time_word >> 11) & 0x1F
    minute = (time_word >> 5) & 0x3F
    second = (time_word & 0x1F) * 2
    try:
        return datetime.datetime(year, month, day, hour, minute, second).timestamp()
    except ValueError:
        return None


def walk(fs, cluster=None, prefix=""):
    """Yield (path, is_dir, first_cluster, size, mtime) depth-first."""
    for name, attr, first, size, mtime in fs.read_dir(cluster):
        path = f"{prefix}{name}"
        if attr & ATTR_DIRECTORY:
            yield path, True, first, 0, mtime
            yield from walk(fs, first, prefix=f"{path}/")
        else:
            yield path, False, first, size, mtime


def extract_image(image_path, dest_root, list_only=False, flat=False):
    with open(image_path, "rb") as handle:
        fs = Fat12(handle.read())

    stem = os.path.splitext(os.path.basename(image_path))[0]
    dest = os.path.join(dest_root, stem) if dest_root else None
    print(f"=== {stem}")

    count = 0
    total = 0
    for path, is_dir, first, size, mtime in walk(fs):
        if is_dir:
            print(f"    {path}/")
            if not (list_only or flat):
                os.makedirs(os.path.join(dest, path), exist_ok=True)
            continue

        print(f"    {path:<24} {size:>8}")
        count += 1
        total += size
        if list_only:
            continue

        out_name = os.path.basename(path) if flat else path
        out_path = os.path.join(dest, out_name)
        os.makedirs(os.path.dirname(out_path), exist_ok=True)
        # A zero-length file has no cluster chain to follow.
        payload = fs.read_chain(first, size) if size else b""
        if len(payload) != size:
            raise Fat12Error(
                f"{path}: chain yielded {len(payload)} bytes, directory says {size}"
            )
        with open(out_path, "wb") as out:
            out.write(payload)
        if mtime is not None:
            os.utime(out_path, (mtime, mtime))

    print(f"    -- {count} files, {total} bytes")
    return count, total


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("images", nargs="+", help="raw FAT12 .img files")
    parser.add_argument("--dest", help="destination directory")
    parser.add_argument("--list", action="store_true", help="list only")
    parser.add_argument("--flat", action="store_true", help="drop subdirectories")
    args = parser.parse_args(argv)

    if not args.list and not args.dest:
        parser.error("--dest is required unless --list is given")

    files = 0
    for image in args.images:
        try:
            count, _ = extract_image(image, args.dest, args.list, args.flat)
        except Fat12Error as exc:
            print(f"{image}: {exc}", file=sys.stderr)
            return 1
        files += count

    print(f"\n{files} files from {len(args.images)} image(s)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
