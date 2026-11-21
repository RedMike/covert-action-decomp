/* PRIMS.H -- text, lines and boxes, the retrace wait and the random draw.
 */
#ifndef PRIMS_H
#define PRIMS_H

INT c_draw_line(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour);
INT c_fill_box(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour);
INT c_random_below(INT n);
INT c_wait_retraces(INT n);
INT c_write_text(drv_addr text, INT across, INT down, UNSIGNED_INT colour);
INT c_write_text_trimmed(drv_addr text, INT across, INT down, UNSIGNED_INT colour);

#endif
