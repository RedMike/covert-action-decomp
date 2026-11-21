/* CITY.H -- drawing primitives: lines, boxes, text and the retrace wait.
 */
#ifndef CITY_H
#define CITY_H

INT c_draw_line(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour);
INT c_fill_box(INT x1, INT y1, INT x2, INT y2, UNSIGNED_INT colour);
INT c_wait_retraces(INT n);
INT c_write_text(drv_addr text, INT across, INT down, UNSIGNED_INT colour);
INT c_write_text_trimmed(drv_addr text, INT across, INT down,
                         UNSIGNED_INT colour);

#endif
