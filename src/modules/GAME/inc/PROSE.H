/* PROSE.H -- reading out a prose block, and writing up an arrest.
 *
 * c_show_prose's calls pass two to four arguments, so UNCHECKED_PARAMS2 spells
 * the ellipsis after `wait`; the portable build passes a null `repl` and a
 * zero `num` for what a short call leaves off.
 */
#ifndef PROSE_H
#define PROSE_H

INT c_arrest(INT who);
INT c_show_prose(char *name, INT wait, UNCHECKED_PARAMS2(char *repl, INT num));

#endif
