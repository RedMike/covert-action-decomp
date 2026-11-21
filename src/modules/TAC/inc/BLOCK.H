/* BLOCK.H -- what messages and clues say, read from tagged blocks of text.
 */
#ifndef BLOCK_H
#define BLOCK_H

void c_say_message(INT nth);
INT c_message_tag(INT a, INT b);
INT c_say_block_with(rt_addr name, rt_addr key, rt_addr *keys,
                     rt_addr *values, INT count);
INT c_say_event_text(INT nth);
INT c_say_one_of(rt_addr name, char *key, INT n);
INT c_substitute(char *line, rt_addr *keys, rt_addr *values,
                 INT count);

#endif
