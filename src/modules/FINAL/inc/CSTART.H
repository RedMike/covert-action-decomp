/* CSTART.H -- starting a campaign and a mission, and the screens they use.
 *
 * c_training_screen's `practice` is a long, as its sites push it. Practising,
 * it answers the skill picked or -1, as c_difficulty_menu does.
 */
#ifndef CSTART_H
#define CSTART_H

void c_campaign_start(void);
void c_set_start(void);
void c_mission_pick(void);
void c_code_name_screen(void);
INT c_difficulty_menu(void);
INT c_training_screen(LONG practice);
void c_skill_rows(INT *skill);
void c_text_field(INT x, UNSIGNED_INT y, INT n);
void c_text_field_draw(INT x, UNSIGNED_INT y, INT n);
void c_draw_mastermind_face_panel(INT n, INT x, INT y, INT unused_a,
                                  INT unused_b);
INT c_pack_org(INT n);
INT c_copy_protection(void);
void c_clear_message_panel(void);

#endif
