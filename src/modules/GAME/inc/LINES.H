/* LINES.H -- drawing and redacting message lines, and city distances.
 */
#ifndef LINES_H
#define LINES_H

INT c_city_distance(INT a, INT b);
INT c_draw_message(INT width, UNSIGNED_INT x, INT y, UNSIGNED_INT colour);
void c_filter_message(INT mask, INT mod);
INT c_packed_distance(INT a, INT b);
INT c_worth_the_trip(INT from, INT to, INT who);

#endif
