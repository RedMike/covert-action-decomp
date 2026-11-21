/* ADVICE.H -- the campaign clock and ticks, the cues, briefing and clue menu.
 *
 * c_advance_clock's `forced` is a long, as its sites push it;
 * c_test_for_jailbreak's `nth` and c_clue_menu's are pushed and never read.
 */
#ifndef ADVICE_H
#define ADVICE_H

INT c_campaign_tick(INT minutes);
INT c_case_due(INT nth);
INT c_test_for_jailbreak(INT who, INT nth);
INT c_chief_briefing(void);
INT c_clue_list(INT nth);
INT c_clue_menu(INT nth);
INT c_forget(INT who, INT bit);
INT c_hook_repaint(void);
INT c_advance_clock(INT minutes, LONG forced);
rt_addr c_timestamp(UNSIGNED_INT minutes);

#endif
