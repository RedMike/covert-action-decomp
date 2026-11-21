/* CASERUN.H -- the hall of fame, the scan for clues and evidence, the clues'
 * display, and the dossier.
 *
 * c_evidence_unlock's `show` is a long, as its sites push it; only its low
 * word is read.
 */
#ifndef CASERUN_H
#define CASERUN_H

void c_fame_load(void);
void c_fame_save(void);
INT c_fame_screen(INT fresh);
INT c_fame_add(INT ep);
INT c_evidence_unlock(INT org, INT city, INT bits, LONG show);
UNSIGNED_INT c_report_new_fields(INT who, UNSIGNED_INT flags);
INT c_wait_key(void);
INT c_suspect_reserve(INT org, INT city, INT bits);
INT c_building_explore(INT org, INT city, UNSIGNED_INT identity_flags);
INT c_cell_reveal(INT chip, INT a, INT b);
UNSIGNED_INT c_clue_record(INT org, INT city, INT cell, INT bit);
INT c_clue_about(INT nth, INT bit);
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
