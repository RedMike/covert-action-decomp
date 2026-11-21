/* JOYSTICK-READ.C -- reading the stick's direction.
 */
#include "CODE.H"
#include "JOYREAD.H"

/* shared_include_start: ../../../../shared/c/JOY-READ.C -- generated */
/* JOY-READ.C -- c_joystick_read, reading the joystick's direction.
 */

/* Read the stick into `*px` and `*py` as -1, 0 or 1 each and answer the
 * direction, 1 to 8 clockwise from up, or -1 if centred or the joystick is
 * off.
 */
INT c_joystick_read(INT *px, INT *py)
{
    if ((shm_options & OPT_JOYSTICK) == 0)
        return -1;
    *(INT *) &shm_joystick = drv_jump_joy_read();
    *px = (char) shm_joystick.x;
    *py = (char) shm_joystick.y;
    if (*px > 0x60)
        *px = 1;
    else if (*px < -0x60)
        *px = -1;
    else
        *px = 0;
    if (*py > 0x60)
        *py = 1;
    else if (*py < -0x60)
        *py = -1;
    else
        *py = 0;
    return *(INT *) ((char *) &shd_joystick_dirs[4] + (*px * 3 + *py) * 2);
}
/* shared_include_end: ../../../../shared/c/JOY-READ.C */
