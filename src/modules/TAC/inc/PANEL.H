/* PANEL.H -- text pages and panels: messages, names, presence, distances.
 *
 * c_personnel_file's second parameter is unchecked: it is defined as an INT
 * but called with a long.
 */
#ifndef PANEL_H
#define PANEL_H

void c_wrap_message(INT width);
void c_filter_message(INT mask, INT period);
void c_person_name(INT who);
void c_person_real_name(INT nth);
void c_personnel_file(INT org, UNCHECKED_PARAMS(INT reveal));
void c_page_frame(rt_addr text, INT colour);
void c_folder_header(INT x, INT y, UNSIGNED_INT colour);
void c_text_panel(INT x, INT y);
void c_draw_centred(str_addr text, INT x, INT y, UNSIGNED_INT colour);
INT c_city_distance(INT a, INT b);
rt_addr c_clock_text(INT seconds);
INT c_draw_message(INT width, UNSIGNED_INT x, INT y, UNSIGNED_INT colour);
INT c_packed_distance(INT a, INT b);
INT c_presence(INT city, INT org);
INT c_say_presence(INT city, INT org);
INT c_text_width(rt_addr text);
INT c_worth_the_trip(INT from, INT to, INT who);

#endif
