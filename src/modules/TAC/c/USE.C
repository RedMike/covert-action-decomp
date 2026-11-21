/* USE.C -- using the cell ahead of the player.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "PAGESHOW.H"
#include "PANEL.H"
#include "CASE.H"
#include "MAPDRAW.H"
#include "PROMPT.H"
#include "RANGE.H"
#include "NOTHING.H"
#include "RESTORE.H"
#include "RADAR.H"
#include "BUGROOM.H"
#include "CENTRE.H"
#include "DOOR.H"
#include "REVEAL.H"
#include "SUSPFLAG.H"

/* Use the cell the cursor is over: the crime's item is taken, the suspect
 * offers the arrest, a terminal gives up a letter of the password, and what
 * opens is opened or closed; the top strip says what the cell holds. */
INT c_primary_interact(void)
{
    INT v0j;    /* never read */
    INT v1m;    /* likewise reserved */
    INT v2;     /* the answer to the arrest question */
    INT v3c;    /* what stands on the cell */

    /* Look at what stands on the cell ahead of the player; an empty cell says nothing. */
    c_aim_cursor();
    strcpy(shm_scratch, &dat_str_empty_16);
    v3c = (char) asm_floor_map[(asm_cursor_col << 5)
        + asm_cursor_row];
    if (v3c != -1) {
        v3c &= 0x3f;
        /* The crime's item is picked up once, which tells the building's
         * suspect's part in the plot, and leaves the cell empty. */
        if (v3c == 60) {
            if ((asm_outcome & 1) != 0)
                return;
            asm_outcome |= 1;
            if (asm_suspect_here != -1)
                shm_suspects[asm_suspect_here].role_known |=
                    shm_suspects[asm_suspect_here].role;
            asm_floor_map[(asm_cursor_col << 5) + asm_cursor_row] = -1;
        }
        /* The agent: never in a jailbreak, where he is the prisoner. */
        if (v3c == 61) {
            if (asm_mission_kind == 2)
                return;
            /* Going up to him sets the alarm off here, and one arrest is enough. */
            c_room_distances(asm_room_last, 240);
            if ((asm_outcome & 2) != 0)
                return;
            /* Over the room, in the plain palette, the player gets a look at his
             * face, which goes into the dossier as a photograph would. */
            c_view_save();
            NUM_LOCK_OFF();
            c_set_palette_record(0);
            if (asm_suspect_here != -1) {
                shm_suspects[asm_suspect_here].flags |= SUSPECT_PHOTO;
                c_dossier(asm_suspect_here, 0, 0);
            }
            /* Ask whether to arrest him by name. */
            strcpy(shm_scratch,
                       dat_str_do_want_arrest);
            c_person_name(asm_suspect_here);
            strcat(shm_scratch, dat_str_question);
            v2 = c_ask_menu((rt_addr) shm_scratch, 100, 140);
            /* Back to the room as it was. */
            NUM_LOCK_ON();
            drv_jump_gfx_set_colour_map(&dat_colours_tactical, &dat_colours_tactical);
            c_view_restore();
            /* Anything but Yes leaves him be. */
            if (v2 != 0)
                return;
            asm_outcome |= 2;
            shm_scratch[0] = 0;
        }
        /* Name the thing, tagged where it takes a bug or a photo. */
        v3c &= 0x3f;
        strcpy(shm_scratch,
                   ((char *) dat_floor_objects[v3c].name));
        if ((dat_floor_objects[asm_floor_map[(asm_cursor_col << 5) + asm_cursor_row] & 0x3f].flags
             & FOBJ_BUGGABLE) != 0)
            strcat(shm_scratch, dat_str_bug);
        if ((dat_floor_objects[asm_floor_map[(asm_cursor_col << 5) + asm_cursor_row] & 0x3f].flags
             & FOBJ_PHOTOGRAPHABLE) != 0)
            strcat(shm_scratch, dat_str_photo);
        /* A terminal gives up one letter of the password, once; 40h marks it used. */
        if ((dat_floor_objects[(asm_floor_map[(asm_cursor_col << 5)
            + asm_cursor_row] & 0x3f)].flags & FOBJ_TERMINAL)
            != 0
            && (asm_floor_map[(asm_cursor_col << 5)
                + asm_cursor_row] & 0x40) == 0) {
            asm_floor_map[(asm_cursor_col << 5)
                + asm_cursor_row] |= 0x40;
            c_reveal_letter();
        }
        /* What opens is opened or shut, the three safes only with the safecracking tools. */
        if ((dat_floor_objects[v3c].flags & FOBJ_OPENABLE) != 0
            && ((((unsigned char) v3c & 0xfd) != 29 && v3c != 28)
                || (asm_kit & 0x10) != 0)) {
            /* Shutting it says so; the count of things left open in the room drops. */
            if ((asm_floor_map[(asm_cursor_col << 5)
                + asm_cursor_row] & 0x80) != 0) {
                strcpy(shm_scratch,
                           ((char *) dat_floor_objects[v3c].name));
                strcat(shm_scratch, dat_str_closed);
                asm_room_seen--;
                c_sound_command((dat_floor_objects[(v3c & 0x3f)].flags & FOBJ_DOOR) != 0 ? 14 : 17);
            } else {
                /* Opening it adds to that count. */
                asm_room_seen++;
                c_sound_command((dat_floor_objects[(v3c & 0x3f)].flags & FOBJ_DOOR) != 0 ? 13 : 16);
            }
            /* Flip it and draw it the new way. */
            asm_floor_map[(asm_cursor_col << 5) + asm_cursor_row] ^= 0x80;
            c_draw_cell(asm_cursor_col, asm_cursor_row);
        }
    }
    /* The strip along the top says what the cell holds, or what happened to it. */
    c_write_centred((rt_addr) shm_scratch);
}
