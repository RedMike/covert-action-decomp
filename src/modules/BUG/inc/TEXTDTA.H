/* TEXTDTA.H -- the keyed text.dta reader, and the message text built on it.
 */
#ifndef TEXTDTA_H
#define TEXTDTA_H

INT c_say_block(rt_addr name, rt_addr key);
INT c_say_block_with(rt_addr name, rt_addr key, rt_addr *keys,
                    rt_addr *values, INT count);
INT c_substitute(char *line, rt_addr *keys, rt_addr *values,
                    INT count);
INT c_say_one_of(rt_addr name, char *key, INT n);
INT c_say_event_text(INT nth);
INT c_message_tag(INT a, INT b);

#endif
