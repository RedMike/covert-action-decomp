/* DRAW-PAPER.C -- c_draw_paper, a blank sheet of printer paper.
 */

/* Draw a blank sheet of continuous-feed paper: a white page, two tractor rails
 * with sprocket holes, and ruled bands.
 */
INT c_draw_paper(void)
{
    INT high;
    INT rule;

    drv_real_fill_rect(shd_screen, 0, 0, 0x140, 200, 0xf);
    c_draw_line(8, 0, 8, 199, 7);
    c_draw_line(0x137, 0, 0x137, 199, 7);
    high = 4;
    do {
        drv_real_fill_rect(shd_screen, 2, high, 4, 4, 8);
        drv_real_fill_rect(shd_screen, 0x13a, high, 4, 4, 8);
        high += 0xc;
    } while (high < 199);
    for (high = 0x20; high < 199; high += 0x40) {
        c_draw_line(0x17, high + 1, 0x17, high + 0x1d, 0xb);
        c_draw_line(0x128, high + 1, 0x128, high + 0x1d, 0xb);
        for (rule = 0; rule < 0x20; rule += 2)
            c_draw_line(0x18, high + rule, 0x127, high + rule, 0xb);
    }
}
