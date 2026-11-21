/* SCREEN.H -- message layout, page frames, person names and city distances.
 */
#ifndef SCREEN_H
#define SCREEN_H

void c_person_name(INT nth);
void c_person_real_name(INT nth);
void c_folder_header(INT x, INT y, UNSIGNED_INT colour);
INT c_city_distance(INT a, INT b);
void c_draw_centred(str_addr text, INT x, INT y, UNSIGNED_INT colour);
INT c_draw_message(INT width, UNSIGNED_INT x, INT y, UNSIGNED_INT colour);
void c_filter_message(INT mask, INT mod);
INT c_packed_distance(INT a, INT b);
void c_page_frame(rt_addr text, INT colour);
INT c_presence(INT city, INT org);
INT c_say_presence(INT city, INT org);
void c_text_panel(INT x, INT y);
INT c_text_width(rt_addr text);
INT c_worth_the_trip(INT org, INT other, INT city);
void c_wrap_message(INT width);

#endif
