/* TEXTOUT.H -- the text writing the TEXTOUT.C target defines.
 */
#ifndef TEXTOUT_H
#define TEXTOUT_H

INT c_write_text(drv_addr text, INT across, INT down, UNSIGNED_INT colour);
INT c_write_text_trimmed(drv_addr text, INT across, INT down,
                         UNSIGNED_INT colour);

#endif
