/* CMISSTRT.H -- generating a case, reading its files and briefing the player.
 */
#ifndef CMISSTRT_H
#define CMISSTRT_H

void c_case_generate(void);
void c_clear_happen_ticks(void);
INT c_place_participant(INT slot);
void c_briefing(INT region);
void c_read_crime(INT n);
void c_read_world(INT n);

#endif
