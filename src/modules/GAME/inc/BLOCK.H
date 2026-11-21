/* BLOCK.H -- the case log, the keyed block reader, and its substitution.
 *
 * c_log_draw takes a long, as its sites push it.
 */
#ifndef BLOCK_H
#define BLOCK_H

INT c_log_add(INT kind, INT slot);
void c_log_draw(LONG full);
INT c_say_block(rt_addr name, rt_addr key);
INT c_say_block_with(rt_addr name, rt_addr key, rt_addr *keys,
                     rt_addr *values, INT count);
void c_say_message(INT nth);
INT c_say_one_of(rt_addr name, char *key, INT n);
INT c_substitute(char *line, rt_addr *keys, rt_addr *values,
                 INT count);

#endif
