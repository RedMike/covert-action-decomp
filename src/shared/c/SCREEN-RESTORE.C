/* SCREEN-RESTORE.C -- c_screen_restore, a screen copy that copies nothing.
 */

void c_screen_restore(void)
{
    drv_jump_gfx_copy_rect((struct RASTPORT *) 2, 0, 0, 0, 0, (struct RASTPORT *) 0, 0x13f, 0xc7);
}