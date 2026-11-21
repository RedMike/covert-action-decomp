/* MISC1.H -- drawing, text writers, joystick and key reads, the panel blank.
 */
#ifndef MISC1_H
#define MISC1_H

INT c_draw_line(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour);
INT c_fill_box(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour);
INT c_joystick_button(INT button);
INT c_joystick_key(void);
INT c_joystick_read(INT *px, INT *py);
INT c_menu_key(void);
INT c_pan_blank(void);
INT c_pan_restore(INT x, INT y);
void c_wait_for_release(void);
INT c_wait_retraces(INT n);
INT c_write_text(drv_addr text, INT across, INT down, UNSIGNED_INT colour);
INT c_write_text_trimmed(drv_addr text, INT across, INT down,
                         UNSIGNED_INT colour);

#endif
