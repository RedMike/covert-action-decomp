/* CASE.H -- the case's clues, evidence, buildings and dossiers, declared ahead
 * of use.
 */
#ifndef CASE_H
#define CASE_H

INT c_suspect_scan(INT arg1, INT arg2, INT arg3, LONG arg4);
INT c_evidence_unlock(INT org, INT city, UNSIGNED_INT bits, LONG show);
void c_suspect_release(INT slot);
UNSIGNED_INT c_report_new_fields(INT who, UNSIGNED_INT flags);
INT c_wait_key(void);
INT c_suspect_reserve(INT org, INT city, UNSIGNED_INT bits);
INT c_building_explore(INT org, INT city, UNSIGNED_INT identity_flags);
void c_building_forget(INT org, INT city);
INT c_cell_reveal(INT chip, INT a, INT b);
void c_clue_close_gap(INT from);
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
