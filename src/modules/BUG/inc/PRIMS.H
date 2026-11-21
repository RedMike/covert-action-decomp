/* PRIMS.H -- text writers, line and box, retrace wait, random draw, clamp.
 */
#ifndef PRIMS_H
#define PRIMS_H

INT c_draw_line(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour);
INT c_wait_retraces(INT n);
INT c_fill_box(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour);
void c_seed_random(void);
INT c_random_below(INT n);
INT c_clamp(INT v, INT lo, INT hi);
INT c_write_text(drv_addr text, INT across, INT down, UNSIGNED_INT colour);
INT c_write_text_trimmed(drv_addr text, INT across, INT down, UNSIGNED_INT colour);

#endif
