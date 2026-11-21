/* DRIVE-READY.C -- c_drive_ready, whether a drive has a disk in it.
 */

/* Whether drive `drive` holds a readable disk, by a BIOS verify tried three
 * times; any drive past B is taken as ready.
 */
INT c_drive_ready(INT drive)
{
    INT tries;
    INT err;
    INT disk[7];

    if (drive > 1)
        return 1;
    disk[0] = drive;
    disk[1] = 0;
    disk[2] = 0;
    disk[3] = 2;
    disk[4] = 1;
    for (tries = 0; tries < 3; tries++) {
        err = _bios_disk(4, (rt_addr) disk);
        if ((err & 0xff00) == 0)
            return 1;
        _bios_disk(0, 0);
    }
    return 0;
}
