#!/usr/bin/env python3
"""Microsoft EXEPACK (stub_277) unpacker / packer: unpack (plain input copied
through), pack, and verify (round-trip in memory). The encoder models LINK
3.65's own /EXEPACK, which no build runs.
"""

import argparse
import os
import struct
import sys

# --- format constants -------------------------------------------------------

SIGNATURE = b"RB"
VARS_LEN = 16               # 7 words + signature (implicit skip_len variant)
ERRSTR = b"Packed file is corrupt"
RELOC_SECTIONS = 16
MAX_BLOCK = 0xFFFF
# LINK 3.65 /EXEPACK's encoder thresholds.
RUN_THRESHOLD = 8           # a run inside the stream becomes a fill at 8
TOP_THRESHOLD = 2           # the run the image ends in, with the pad merged
HEAD_THRESHOLD = 55         # the stream starts at the lowest fill this long
PACKED_HDR_PARAS = 32       # packed files always use a 512-byte MZ header

# EXEPACK drops the original `hdrsize`; LINK rounds the MZ header up to this.
HDR_ALIGN_BYTES = 512
PACKED_SP = 0x0080          # the stub's stack, that far above the stub's end

# stub_277: the 255 bytes of decompressor code that precede the error string.
STUB = bytes.fromhex(
    "8cc00510000e1fa3040003060c008ec0"
    "8b0e06008bf94f8bf7fdf3a450b83200"
    "50cb8cc38cd8488ed88ec0bf0f00b910"
    "00b0fff3ae478bf78bc3488ec0bf0f00"
    "b1048bc6f7d0d3e874098cda2bd08eda"
    "83cef08bc7f7d0d3e874098cc22bd08e"
    "c283cff0ac8ad04ead8bc8468ac224fe"
    "3cb07506acf3aaeb07903cb2756bf3a4"
    "8ac2a80174babe25010e1f8b1e0400fc"
    "33d2ad8bc8e3138bc203c38ec0ad8bf8"
    "83ffff741126011de2f381fa00f07416"
    "81c20010ebdc8cc0408ec083ef102601"
    "1d488ec0ebe28bc38b3e08008b360a00"
    "03f0010602002d10008ed88ec0bb0000"
    "fa8ed68be7fb2eff2fb440bb0200b916"
    "008cca8edaba0f01cd21b8ff4ccd21"
)
assert len(STUB) == 255, f"embedded stub is {len(STUB)} bytes, expected 255"

RELOC_TABLE_OFFSET = VARS_LEN + len(STUB) + len(ERRSTR)   # 0x125, hardcoded in the stub


class ExepackError(Exception):
    pass


def ceil_div(a, b):
    return -(-a // b)


# --- MZ header --------------------------------------------------------------

MZ_FIELDS = (
    "lastsize nblocks nreloc hdrsize minalloc maxalloc "
    "ss sp cksum ip cs relocoff noverlay"
).split()


def parse_mz(data):
    if data[:2] not in (b"MZ", b"ZM"):
        raise ExepackError("not an MZ executable")
    vals = struct.unpack_from("<13H", data, 2)
    hdr = dict(zip(MZ_FIELDS, vals))
    hdr["hdr_bytes"] = hdr["hdrsize"] * 16
    last = hdr["lastsize"]
    hdr["image_end"] = (hdr["nblocks"] - 1) * 512 + (last if last else 512)
    return hdr


def build_mz(hdr, total_size):
    nblocks = ceil_div(total_size, 512)
    lastsize = total_size % 512
    return struct.pack(
        "<2s13H",
        b"MZ", lastsize, nblocks, hdr["nreloc"], hdr["hdrsize"], hdr["minalloc"],
        hdr["maxalloc"], hdr["ss"], hdr["sp"], hdr["cksum"], hdr["ip"], hdr["cs"],
        hdr["relocoff"], hdr["noverlay"],
    )


def is_exepack(data):
    try:
        hdr = parse_mz(data)
    except ExepackError:
        return False
    if hdr["ip"] != VARS_LEN:
        return False
    vo = hdr["hdr_bytes"] + hdr["cs"] * 16
    return data[vo + VARS_LEN - 2: vo + VARS_LEN] == SIGNATURE


# --- relocation table -------------------------------------------------------

def decode_relocs(table):
    """EXEPACK reloc table -> list of (segment, offset), in file order."""
    relocs, o = [], 0
    for section in range(RELOC_SECTIONS):
        if o + 2 > len(table):
            raise ExepackError(f"reloc table truncated at section {section}")
        (count,) = struct.unpack_from("<H", table, o)
        o += 2
        if o + 2 * count > len(table):
            raise ExepackError(f"reloc section {section} overruns table")
        for (off,) in struct.iter_unpack("<H", table[o: o + 2 * count]):
            relocs.append((section * 0x1000, off))
        o += 2 * count
    if o != len(table):
        raise ExepackError(f"reloc table has {len(table) - o} trailing bytes")
    return relocs


def encode_relocs(relocs):
    """list of (segment, offset) -> the sixteen-section table, one per 64 KB.
    Pairs are normalised by linear address; LINK's are not in section form."""
    sections = [[] for _ in range(RELOC_SECTIONS)]
    for seg, off in relocs:
        linear = seg * 16 + off
        index = linear >> 16
        if not 0 <= index < RELOC_SECTIONS:
            raise ExepackError(
                f"relocation {seg:#06x}:{off:#06x} is past the "
                f"{RELOC_SECTIONS * 64} KB the table can address")
        sections[index].append(linear & 0xFFFF)
    out = bytearray()
    for entries in sections:
        out += struct.pack("<H", len(entries))
        for off in entries:
            out += struct.pack("<H", off)
    return bytes(out)


# --- compressed stream ------------------------------------------------------

def decode_stream(packed, dest_len):
    """Decode backwards.  Returns (image, head_len, blocks)."""
    image = bytearray(dest_len * 16)
    src = len(packed)
    pad = 0
    while src > 0 and packed[src - 1] == 0xFF and pad < 16:
        src -= 1
        pad += 1
    dst = len(image)
    blocks = []
    while True:
        if src < 3:
            raise ExepackError("compressed stream underran")
        op = packed[src - 1]
        src -= 1
        (length,) = struct.unpack_from("<H", packed, src - 2)
        src -= 2
        if length > dst:
            raise ExepackError("block would write below the start of the image")
        if op & 0xFE == 0xB0:
            value = packed[src - 1]
            src -= 1
            dst -= length
            image[dst: dst + length] = bytes([value]) * length
            blocks.append(("fill", length, value))
        elif op & 0xFE == 0xB2:
            src -= length
            if src < 0:
                raise ExepackError("copy block underran the stream")
            dst -= length
            image[dst: dst + length] = packed[src: src + length]
            blocks.append(("copy", length, None))
        else:
            raise ExepackError(f"bad opcode {op:#04x}")
        if op & 1:
            break
    if src != dst:
        raise ExepackError(
            f"stream and image pointers disagree: src={src} dst={dst}"
        )
    image[:dst] = packed[:dst]      # the uncompressed head, already in place
    return bytes(image), dst, blocks


def _fill(blocks, length, value):
    """Rule 5: a fill longer than a block's 16-bit length is several."""
    while length:
        take = min(length, MAX_BLOCK)
        blocks.append(("fill", take, value))
        length -= take


def greedy_blocks(image, length):
    """Encoder rules 1, 2, 3 and 5; returns (blocks, head_len), top-down.
    `length` is LINK's image; the paragraph pad goes in the top block."""
    pad = (-length) % 16
    blocks = []
    i = length

    # Rule 3: the top run is a fill at TOP_THRESHOLD, LINK's pad merged in.
    run_start = i
    last = image[i - 1]
    while run_start > 0 and image[run_start - 1] == last:
        run_start -= 1
    if i - run_start >= TOP_THRESHOLD:
        _fill(blocks, i - run_start + pad, last)
        i = run_start
    elif pad:
        _fill(blocks, pad, last)    # a lone last byte: the pad fills on its own

    # Rule 1: greedy backward RLE, a fill at RUN_THRESHOLD, copies between.
    while i > 0:
        run_start = i
        value = image[i - 1]
        while run_start > 0 and image[run_start - 1] == value:
            run_start -= 1
        if i - run_start >= RUN_THRESHOLD:
            _fill(blocks, i - run_start, value)
            i = run_start
            continue
        # accumulate a copy until a compressible run appears
        k = i
        while k > 0:
            j = k
            c = image[k - 1]
            while j > 0 and image[j - 1] == c:
                j -= 1
            if k - j >= RUN_THRESHOLD:
                break
            k = j
        remaining = i - k
        while remaining:
            take = min(remaining, MAX_BLOCK)
            blocks.append(("copy", take, None))
            remaining -= take
        i = k

    # Rule 2: the raw head -- below the lowest fill of HEAD_THRESHOLD or more.
    for index in range(len(blocks) - 1, -1, -1):
        kind, blk_len, _ = blocks[index]
        if kind == "fill" and blk_len >= HEAD_THRESHOLD:
            keep = index + 1
            break
    else:
        raise ExepackError(
            "not suitable for EXEPACK: no run of %d or more bytes for the "
            "compressed stream to start at" % HEAD_THRESHOLD)
    head_len = sum(blk_len for _, blk_len, _ in blocks[keep:])
    return blocks[:keep], head_len


def encode_stream(image, length, dest_len):
    """Build the compressed stream (rules 1-5)."""
    blocks, head_len = greedy_blocks(image, length)
    if not blocks:
        raise ExepackError("nothing to compress")

    # Decoded from the end down, so laid out in reverse: lowest block terminal.
    out = bytearray(image[:head_len])
    pos = head_len
    for n, (kind, blk_len, value) in enumerate(reversed(blocks)):
        terminal = 1 if n == 0 else 0
        if kind == "fill":
            out.append(value)
            out += struct.pack("<H", blk_len)
            out.append(0xB0 | terminal)
        else:
            out += image[pos: pos + blk_len]
            out += struct.pack("<H", blk_len)
            out.append(0xB2 | terminal)
        pos += blk_len

    while len(out) % 16:
        out.append(0xFF)
    if len(out) > dest_len * 16:
        raise ExepackError(
            f"packed stream ({len(out)}) exceeds the unpacked image "
            f"({dest_len * 16}); in-place decompression would corrupt itself"
        )
    return bytes(out)


# --- unpack / pack ----------------------------------------------------------

def unpack(data):
    hdr = parse_mz(data)
    if not is_exepack(data):
        raise ExepackError("not an EXEPACK file")

    vo = hdr["hdr_bytes"] + hdr["cs"] * 16
    real_ip, real_cs, mem_start, exepack_size, real_sp, real_ss, dest_len = \
        struct.unpack_from("<7H", data, vo)

    if mem_start != 0:
        raise ExepackError(f"mem_start is {mem_start:#06x}, expected 0 on disk")
    stub = data[vo + VARS_LEN: vo + VARS_LEN + len(STUB)]
    if stub != STUB:
        raise ExepackError("unrecognised stub; only stub_277 is supported")
    errstr_at = vo + VARS_LEN + len(STUB)
    if data[errstr_at: errstr_at + len(ERRSTR)] != ERRSTR:
        raise ExepackError("error string missing or altered")
    if len(data) != vo + exepack_size:
        raise ExepackError(
            f"file is {len(data)} bytes, expected {vo + exepack_size} "
            "(overlay data is not supported)"
        )

    relocs = decode_relocs(data[vo + RELOC_TABLE_OFFSET: vo + exepack_size])
    packed = data[hdr["hdr_bytes"]: vo]
    image, head_len, blocks = decode_stream(packed, dest_len)

    # The loader's image: `dest_len` paragraphs, LINK's own length unrecorded.
    length = dest_len * 16

    # The word at 0x1c, below relocoff 0x1e, is unexplained; carry it through.
    relocoff = hdr["relocoff"]
    gap = data[0x1C:relocoff]
    out_hdrsize = (ceil_div(relocoff + 4 * len(relocs), HDR_ALIGN_BYTES)
                   * (HDR_ALIGN_BYTES // 16))
    esz_paras = ceil_div(exepack_size, 16)
    out_hdr = {
        "nreloc": len(relocs),
        "hdrsize": out_hdrsize,
        # memory beyond the load image is unchanged by unpacking
        "minalloc": hdr["minalloc"] + hdr["cs"] + esz_paras - dest_len,
        "maxalloc": hdr["maxalloc"],
        "ss": real_ss, "sp": real_sp,
        "cksum": hdr["cksum"],
        "ip": real_ip, "cs": real_cs,
        "relocoff": relocoff,
        "noverlay": hdr["noverlay"],
    }
    if out_hdr["minalloc"] < 0:
        raise ExepackError("computed a negative minalloc")

    header = bytearray(out_hdrsize * 16)
    header[:0x1C] = build_mz(out_hdr, out_hdrsize * 16 + length)
    header[0x1C:relocoff] = gap
    o = relocoff
    for seg, off in relocs:
        struct.pack_into("<HH", header, o, off, seg)
        o += 4
    return bytes(header) + image[:length]


def pack(data):
    hdr = parse_mz(data)
    if is_exepack(data):
        raise ExepackError("input is already EXEPACK'd")

    length = hdr["image_end"] - hdr["hdr_bytes"]
    image = data[hdr["hdr_bytes"]: hdr["image_end"]]
    if len(image) != length:
        raise ExepackError("image is shorter than the header claims")

    relocs = []
    o = hdr["relocoff"]
    if o < 0x1C:
        raise ExepackError(f"relocoff {o:#06x} overlaps the MZ header")
    for _ in range(hdr["nreloc"]):
        off, seg = struct.unpack_from("<HH", data, o)
        relocs.append((seg, off))
        o += 4
    reloc_table = encode_relocs(relocs)

    dest_len = ceil_div(length, 16)
    stream = encode_stream(image, length, dest_len)
    exepack_size = RELOC_TABLE_OFFSET + len(reloc_table)
    esz_paras = ceil_div(exepack_size, 16)

    vars_block = struct.pack(
        "<7H", hdr["ip"], hdr["cs"], 0, exepack_size, hdr["sp"], hdr["ss"], dest_len
    ) + SIGNATURE

    # The need beyond the image is preserved, under LINK's floor for the stub.
    stream_paras = len(stream) // 16
    minalloc = max(
        hdr["minalloc"] + dest_len - (stream_paras + esz_paras),
        dest_len + PACKED_SP // 16 - stream_paras,
    )
    out_hdr = {
        "nreloc": 0,
        "hdrsize": PACKED_HDR_PARAS,
        "minalloc": minalloc,
        "maxalloc": hdr["maxalloc"],
        "ss": dest_len + esz_paras,
        "sp": PACKED_SP,
        "cksum": 0,             # /EXEPACK writes none, where a plain link does
        "ip": VARS_LEN,
        "cs": len(stream) // 16,
        "relocoff": hdr["relocoff"],
        "noverlay": hdr["noverlay"],
    }
    if out_hdr["minalloc"] < 0:
        raise ExepackError("computed a negative minalloc")

    total = PACKED_HDR_PARAS * 16 + len(stream) + exepack_size
    header = bytearray(PACKED_HDR_PARAS * 16)
    header[:0x1C] = build_mz(out_hdr, total)
    header[0x1C:hdr["relocoff"]] = data[0x1C:hdr["relocoff"]]
    return bytes(header) + stream + vars_block + STUB + ERRSTR + reloc_table


# --- CLI --------------------------------------------------------------------

def cmd_unpack(args):
    data = open(args.input, "rb").read()
    if not is_exepack(data):
        print(f"{os.path.basename(args.input)}: not EXEPACK, copying through")
        out = data
    else:
        out = unpack(data)
    open(args.output, "wb").write(out)
    print(f"{args.input} -> {args.output} ({len(data)} -> {len(out)} bytes)")


def cmd_pack(args):
    data = open(args.input, "rb").read()
    out = pack(data)
    open(args.output, "wb").write(out)
    print(f"{args.input} -> {args.output} ({len(data)} -> {len(out)} bytes)")


def cmd_verify(args):
    failures = 0
    for path in args.files:
        name = os.path.basename(path)
        data = open(path, "rb").read()
        if not is_exepack(data):
            print(f"  SKIP  {name:12s} not EXEPACK")
            continue
        try:
            plain = unpack(data)
            again = pack(plain)
        except ExepackError as exc:
            print(f"  FAIL  {name:12s} {exc}")
            failures += 1
            continue
        if again == data:
            print(f"  PASS  {name:12s} {len(data)} bytes, round-trip identical "
                  f"(unpacked {len(plain)})")
        else:
            failures += 1
            print(f"  FAIL  {name:12s} {len(data)} in, {len(again)} out")
            limit = min(len(data), len(again))
            diffs = [i for i in range(limit) if data[i] != again[i]]
            print(f"        {len(diffs)} differing bytes"
                  + (f", first at {diffs[0]:#x}: "
                     f"{data[diffs[0]]:02x} -> {again[diffs[0]]:02x}" if diffs else ""))
            for i in diffs[:8]:
                print(f"          {i:#08x}  orig {data[i]:02x}  ours {again[i]:02x}")
    return 1 if failures else 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("unpack"); p.add_argument("input"); p.add_argument("output")
    p.set_defaults(func=cmd_unpack)
    p = sub.add_parser("pack"); p.add_argument("input"); p.add_argument("output")
    p.set_defaults(func=cmd_pack)
    p = sub.add_parser("verify"); p.add_argument("files", nargs="+")
    p.set_defaults(func=cmd_verify)
    args = ap.parse_args(argv)
    try:
        return args.func(args) or 0
    except ExepackError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    sys.exit(main())
