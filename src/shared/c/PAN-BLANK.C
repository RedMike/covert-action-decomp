/* PAN-BLANK.C -- c_pan_blank, blanking the animation area.
 */

/* Blank the animation area to colour 5 and let the repaint hook redraw what
 * sits over it.
 */
INT c_pan_blank(void)
{
    drv_real_fill_rect(shd_screen, 0, 0, shm_pan_width, 0xc8, 5);
    c_hook_repaint();
    shd_screen->bg_pen = 5;
}