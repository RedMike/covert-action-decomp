/* BUGROOM.C -- planting a bug.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "PAGESHOW.H"
#include "BUGROOM.H"
#include "CENTRE.H"
#include "THUNK.H"

/* Plant a bug on the cell the cursor is over: only a fitting cell counts, only
 * one bug goes in a room, and either way the panel says what happened. */
INT c_plant_bug(void)
{
    INT v0j;    /* what stands on the cell */

    /* Look at what stands on the cell ahead of the player. */
    c_aim_cursor();
    v0j = (char) asm_floor_map[(asm_cursor_col << 5)
        + asm_cursor_row];
    /* With no bugs left, the key does nothing. */
    if (asm_bugs_left == 0)
        return;
    /* Something buggable, in a room with no bug yet, takes one. */
    if (v0j != -1
        && (dat_floor_objects[(v0j & 0x3f)].flags
            & FOBJ_BUGGABLE) != 0
        && (asm_rooms[asm_room_last].flags & 4) == 0) {
        /* The bug scores what this kind of room is worth, and marks the room bugged. */
        asm_bugs_planted++;
        c_sound_command(10);
        asm_bug_score +=
            dat_room_kinds[asm_rooms[asm_room_last].kind].score;
        asm_rooms[asm_room_last].flags |= 4;
        /* One bug fewer on the kit panel. */
        asm_bugs_left--;
        c_refresh_kit();
        /* Say what was bugged. */
        strcpy(shm_scratch, &dat_str_empty_17);
        strcat(shm_scratch,
                   ((char *) dat_floor_objects[(v0j & 0x3f)].name));
        strcat(shm_scratch, dat_str_bugged);
    } else
        /* Otherwise say why not: the room has its bug already, or nothing here takes one. */
        strcpy(shm_scratch,
                   (asm_rooms[asm_room_last].flags & 4) != 0
                   ? dat_str_room_already_bugged : dat_str_nothing_bug);
    /* Either way the message goes up in the strip along the top. */
    c_write_centred((rt_addr) shm_scratch);
}
