/* REPORT.H -- reporting what the case turns up: clues, evidence, dossiers, messages.
 */
#ifndef REPORT_H
#define REPORT_H

UNSIGNED_INT c_report_new_fields(INT who, UNSIGNED_INT flags);
INT c_wait_key(void);
INT c_building_explore(INT org, INT city, UNSIGNED_INT identity_flags);
INT c_cell_reveal(INT chip, INT a, INT b);
UNSIGNED_INT c_clue_record(INT org, INT city, INT cell, INT bit);
INT c_clue_about(INT slot, INT what);
INT c_clue_text(INT cell, INT full);
void c_clue_line(INT nth);
INT c_clue_phrase(INT about, INT kind);
void c_clue_subject(INT nth, INT about);
void c_clue_thing(INT about);
void c_clue_line_full(INT nth);
void c_clue_from_file(INT about, INT kind, INT nth);
void c_dossier(INT nth, INT x, INT y);
void c_intercept_line(INT nth);

#endif
