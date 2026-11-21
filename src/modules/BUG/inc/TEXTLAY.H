/* TEXTLAY.H -- the message layout and the phrases it assembles.
 */
#ifndef TEXTLAY_H
#define TEXTLAY_H

INT c_draw_message(INT width, UNSIGNED_INT x, INT y, UNSIGNED_INT colour);
void c_filter_message(INT mask, INT mod);
INT c_worth_the_trip(INT org, INT other, INT city);
INT c_packed_distance(INT a, INT b);
INT c_city_distance(INT a, INT b);
INT c_say_presence(INT city, INT org);
INT c_presence(INT city, INT org);
void c_person_name(INT nth);
void c_person_real_name(INT nth);

#endif
