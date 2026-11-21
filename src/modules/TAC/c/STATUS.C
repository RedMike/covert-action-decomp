/* STATUS.C -- the status strip above the map.
 */
#include "TAC.H"
#include "CITY.H"
#include "PANEL.H"
#include "STATUS.H"

/* Redraw the strip above the map: the clock, taking turns with a warning of
 * gas in the room or a note that the player is disguised. */
INT c_draw_status(void)
{
    /* Clear the strip; it swaps what it shows every four ticks. */
    c_fill_box(123, 2, 168, 9, 1);
    if ((asm_frame_tick & 4) != 0) {
        /* For four ticks a gassed room's warning stands in for the clock, */
        if ((asm_rooms[asm_room_last].flags
             & 0x10) != 0)
            c_write_text_trimmed(dat_str_gas, 132, 2, 12);
        else
            c_write_text_trimmed((rt_addr) c_clock_text(asm_frame_tick),
                            124, 2, 15);
    } else if (asm_disguised != 0)
        /* and for the next four the disguise does. */
        c_write_text_trimmed(dat_str_disguise, 124, 2, 2);
    else
        c_write_text_trimmed((rt_addr) c_clock_text(asm_frame_tick),
                        124, 2, 15);
}
