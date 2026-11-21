/* PHOTO.C -- taking a photograph.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "PAGESHOW.H"
#include "CITY.H"
#include "CASE.H"
#include "MAPDRAW.H"
#include "PLAN.H"
#include "NOTHING.H"
#include "RESTORE.H"
#include "RADAR.H"
#include "BUGROOM.H"
#include "CENTRE.H"
#include "CLOCK.H"
#include "REVEAL.H"
#include "CAMERA.H"

/* Photograph the cell the cursor is over: only a fitting cell counts, only
 * once each, and only while there is film left. A photograph that lands scores
 * the room and shows what it turns up about the case. */
INT c_take_photo(void)
{
    INT v0j;    /* the difficulty, put back after the case is scanned */
    INT v1m;    /* what the picture is worth */
    INT v2;     /* whether the shot was taken */
    INT v3c;    /* what stands on the cell */

    /* Aim at what is ahead, and say there is nothing to photograph unless it fits. */
    c_aim_cursor();
    v3c = (char) asm_floor_map[(asm_cursor_col << 5)
        + asm_cursor_row];
    v2 = 0;
    strcpy(shm_scratch,
               dat_str_nothing_photograph);
    if (v3c != -1
        && (dat_floor_objects[(v3c & 0x3f)].flags & FOBJ_PHOTOGRAPHABLE)
           != 0) {
        /* A thing is photographed only once. */
        if ((v3c & 0x40) != 0)
            strcpy(shm_scratch,
                       dat_str_already_photographed);
        /* Open, or with nothing to open, it is photographed and marked so. */
        else if ((v3c & 0x80) != 0
                 || (dat_floor_objects[(v3c & 0x3f)].flags & FOBJ_OPENABLE) == 0) {
            strcpy(shm_scratch,
                       ((char *) dat_floor_objects[(v3c & 0x3f)].name));
            strcat(shm_scratch, dat_str_photographed);
            asm_floor_map[(asm_cursor_col << 5)
                + asm_cursor_row] |= 0x40;
            v2 = 1;
        } else {
            /* A closed one has to be opened first. */
            strcpy(shm_scratch, dat_str_open);
            strcat(shm_scratch,
                       ((char *) dat_floor_objects[(v3c & 0x3f)].name));
            strcat(shm_scratch, dat_str_first);
        }
    }
    /* With the film used up nothing is taken, whatever was ahead. */
    if ((INT) asm_photos_taken >= CAMERA_FILM(asm_kit, asm_mission_kind)) {
        v2 = 0;
        strcpy(shm_scratch, dat_str_out_film);
    }
    c_write_centred((rt_addr) shm_scratch);
    if (v2 == 0)
        return;
    /* Use up a shot, score the room's kind, and update the count of shots left. */
    asm_photos_taken++;
    asm_photo_score +=
        dat_room_kinds[asm_rooms[asm_room_last].kind].score;
    c_clock_draw();
    /* The camera's flash: another palette and a sound for five retraces. */
    c_set_palette_record(1);
    c_sound_command(9);
    c_wait_retraces(5);
    c_set_palette_record(0);
    /* What it is worth: files, desks and the like 2, a wall safe 3, the floor safe a tip. */
    v3c &= 0x3f;
    if (v3c >= 24)
        v1m = 2;
    if (v3c >= 29)
        v1m = 3;
    if (v3c >= 32)
        v1m = 2;
    if (v3c == 28)
        v1m = 4;
    /* Nothing more comes of it without asm_film_left set, or in practice. */
    if (asm_film_left == 0)
        return;
    if ((shm_options & OPT_PRACTICE) != 0)
        return;
    /* The case's findings pop up over the thing photographed. */
    asm_panel_x =
        ((asm_cursor_col
          - asm_rooms[asm_room_last].left) << 4)
        + asm_view_left;
    asm_panel_y =
        ((asm_cursor_row
          - asm_rooms[asm_room_last].top) << 4)
        + asm_view_top;
    /* Scan the case at the campaign's own difficulty, not the break-in's. */
    v0j = shm_difficulty;
    shm_difficulty = asm_difficulty_was;
    c_view_save();
    /* The worth weighs the room's score, except the floor safe, which gives a tip. */
    if (v1m != 4)
        c_suspect_scan(shm_case_org, shm_case_city,
                        dat_room_kinds[asm_rooms[asm_room_last].kind].score
                        * v1m, v1m);
    else
        c_give_tip();
    /* Back to the break-in's colours and screen. */
    drv_jump_gfx_set_colour_map(&dat_colours_tactical, &dat_colours_tactical);
    c_view_restore();
    shd_screen->bg_pen = 1;
    /* After a tip, the map and the panel are drawn again. */
    if (v1m == 4) {
        c_draw_plan(180, 100, 3);
        c_draw_kit_panel();
    }
    shm_difficulty = v0j;
}
