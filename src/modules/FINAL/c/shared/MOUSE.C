/* MOUSE.C -- the INT 33h mouse driver calls.
 *
 * Dead code: the game reads the keyboard and joystick and never calls these.
 * Each puts a function number in the register block, makes the call and copies
 * back what it answers.
 */
#include "FINAL.H"

/* shared_include_start: ../../../../shared/c/MOUSE-INIT.C -- generated */
/* MOUSE-INIT.C -- c_mouse_reset, an INT 33h mouse-driver call.
 */

/* INT 33h AX=0 -- reset the driver and ask whether one is installed. */
void c_mouse_reset(void)
{
    shm_mouse_regs.x.ax = 0;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-INIT.C */

/* shared_include_start: ../../../../shared/c/MOUSE-SHOW.C -- generated */
/* MOUSE-SHOW.C -- c_mouse_show, an INT 33h mouse-driver call.
 */

/* INT 33h AX=1 -- show the pointer. */
void c_mouse_show(void)
{
    shm_mouse_regs.x.ax = 1;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-SHOW.C */

/* shared_include_start: ../../../../shared/c/MOUSE-HIDE.C -- generated */
/* MOUSE-HIDE.C -- c_mouse_hide, an INT 33h mouse-driver call.
 */

/* INT 33h AX=2 -- hide the pointer. */
void c_mouse_hide(void)
{
    shm_mouse_regs.x.ax = 2;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-HIDE.C */

/* shared_include_start: ../../../../shared/c/MOUSE-WHERE.C -- generated */
/* MOUSE-WHERE.C -- c_mouse_where, an INT 33h mouse-driver call.
 */

/* INT 33h AX=3 -- where the pointer is and which buttons are down. */
void c_mouse_where(void)
{
    shm_mouse_regs.x.ax = 3;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
    shm_mouse_buttons = shm_mouse_regs.x.bx;
    shm_mouse_x = shm_mouse_regs.x.cx;
    shm_mouse_y = shm_mouse_regs.x.dx;
}
/* shared_include_end: ../../../../shared/c/MOUSE-WHERE.C */

/* shared_include_start: ../../../../shared/c/MOUSE-MOVE.C -- generated */
/* MOUSE-MOVE.C -- c_mouse_move, an INT 33h mouse-driver call.
 */

/* Put the mouse pointer at (`across`, `down`) through INT 33h AX=4. */
void c_mouse_move(INT across, INT down)
{
    shm_mouse_regs.x.ax = 4;
    shm_mouse_regs.x.cx = across;
    shm_mouse_regs.x.dx = down;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-MOVE.C */

/* shared_include_start: ../../../../shared/c/MOUSE-PRESSES.C -- generated */
/* MOUSE-PRESSES.C -- c_mouse_presses, an INT 33h mouse-driver call.
 */

/* Read the press counter for one button through INT 33h AX=5, and copy the
 * four register words out into the mouse variables.
 */
void c_mouse_presses(INT button)
{
    shm_mouse_regs.x.ax = 5;
    shm_mouse_regs.x.bx = button;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
    shm_mouse_buttons = shm_mouse_regs.x.ax;
    shm_mouse_count = shm_mouse_regs.x.bx;
    shm_mouse_x = shm_mouse_regs.x.cx;
    shm_mouse_y = shm_mouse_regs.x.dx;
}
/* shared_include_end: ../../../../shared/c/MOUSE-PRESSES.C */

/* shared_include_start: ../../../../shared/c/MOUSE-RELEASES.C -- generated */
/* MOUSE-RELEASES.C -- c_mouse_releases, an INT 33h mouse-driver call.
 */

/* Read the release counter for one button through INT 33h AX=6, and copy the
 * four register words out into the mouse variables.
 */
void c_mouse_releases(INT button)
{
    shm_mouse_regs.x.ax = 6;
    shm_mouse_regs.x.bx = button;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
    shm_mouse_buttons = shm_mouse_regs.x.ax;
    shm_mouse_count = shm_mouse_regs.x.bx;
    shm_mouse_x = shm_mouse_regs.x.cx;
    shm_mouse_y = shm_mouse_regs.x.dx;
}
/* shared_include_end: ../../../../shared/c/MOUSE-RELEASES.C */

/* shared_include_start: ../../../../shared/c/MOUSE-FENCE.C -- generated */
/* MOUSE-FENCE.C -- c_mouse_fence, an INT 33h mouse-driver call.
 */

/* Fence the pointer in, INT 33h AX=7 for the columns and AX=8 for the rows. */
void c_mouse_fence(INT left, INT top, INT right, INT bottom)
{
    shm_mouse_regs.x.ax = 7;
    shm_mouse_regs.x.cx = left;
    shm_mouse_regs.x.dx = right;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
    shm_mouse_regs.x.ax = 8;
    shm_mouse_regs.x.cx = top;
    shm_mouse_regs.x.dx = bottom;
    INTERRUPT(0x33, &shm_mouse_regs, &shm_mouse_regs);
}
/* shared_include_end: ../../../../shared/c/MOUSE-FENCE.C */
