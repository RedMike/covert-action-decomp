/* PRISONER.H -- the exchange and the jailbreak, removing a crime object, and a replace.
 */
#ifndef PRISONER_H
#define PRISONER_H

INT c_player_captured_menu(void);
INT c_prisoner_exchange(void);
INT c_replace(char *find, char *repl);
INT c_remove_crime_object(INT object);

#endif
