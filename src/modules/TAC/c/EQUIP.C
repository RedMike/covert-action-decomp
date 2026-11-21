/* EQUIP.C -- the kit screen, where the equipment is chosen.
 */
#include "TAC.H"
#include "KEYCODES.H"
#include "PAGESHOW.H"
#include "CITY.H"
#include "MENU.H"
#include "MAPDRAW.H"
#include "PLAN.H"
#include "ANI_LD2.H"
#include "EQUIP.H"
#include "MODOPTS.H"

#ifdef TAC_EQUIPMENT_GUIDANCE
/* How many of the five are taken, at the bottom left: light grey until all
 * five are and white then. The digit is poked, as TAC links no sprintf. `left`
 * is how many more may still be taken. */
static void c_kit_guidance(INT left)
{
    static char items[] = "Items: 0/5";

    items[7] = '5' - left;
    drv_jump_gfx_copy_rect(shd_map_page, 5, 190, 60, 8, shd_screen, 5, 190);
    c_write_text_trimmed((drv_addr) items, 5, 190, left != 0 ? 7 : 15);
}
#endif

/* The kit screen: walk a highlight over the boxes of the equipment picture and
 * turn each one on or off, five things at a time. The chosen set is the bit
 * mask in asm_kit and the three counts in asm_ammunition; Escape leaves. */
INT c_kit_screen(LONG a)
{
    INT v0j;    /* the pointer's column */
    INT v1k;    /* and its row */
    INT v2l;    /* the sprite, the box or the count being stepped */
    INT v3m;    /* the key just read */
    INT v4o;    /* the box the highlight is leaving */
    INT v5;     /* how many more things may be taken, -1 once done */
    INT v6a;    /* the box the highlight is on */

    /* Cut the kit panel's sprites out of equip2.pic. */
    drv_jump_gfx_pool_alloc();
    c_load_picture(dat_str_equip2_pic, 3);
    for (v2l = 0; v2l < 15; v2l++)
        asm_kit_sprites[v2l] =
            drv_jump_gfx_grab(3,
                dat_kit_sprite_rects[v2l].x1,
                dat_kit_sprite_rects[v2l].y1,
                dat_kit_sprite_rects[v2l].x2
                - dat_kit_sprite_rects[v2l].x1 + 1,
                dat_kit_sprite_rects[v2l].y2
                - dat_kit_sprite_rects[v2l].y1 + 1);
    drv_jump_gfx_pool_release();
    drv_jump_gfx_set_colour_map(&dat_colours_tactical, &dat_colours_tactical);
    /* Move every place the kit panel draws six pixels across. */
    for (v2l = 0; v2l < 13; v2l++)
        dat_kit_points[v2l].x += 6;
    /* A full magazine and three spare, and the street on the plan. */
    asm_rounds_left = 6;
    asm_clips_left = 3;
    asm_rooms[0].flags |= 2;
    c_draw_plan(180, 100, 3);
    /* With the kit handed out there is nothing to choose: fill the screen and go. */
    if ((INT) a == 0) {
        drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 5);
        return;
    }
    /* Five things may be taken, starting from a pistol, with the highlight on the first box. */
    c_sound_command(39);
    v5 = 5;
    asm_kit = 1;
    v6a = 1;
    c_draw_kit_panel();
#ifdef TAC_EQUIPMENT_GUIDANCE
    if (MOD_ON(additional_guidance)) {
        c_write_text_trimmed((drv_addr) "Esc to start", 70, 185, 7);
        c_kit_guidance(v5);
    }
#endif
    do {
        /* Highlight the box the cursor is on. */
        drv_jump_gfx_fill(shd_screen,
            dat_kit_slot_rects[v6a].x1,
            dat_kit_slot_rects[v6a].y1,
            dat_kit_slot_rects[v6a].x2
            - dat_kit_slot_rects[v6a].x1 + 1,
            dat_kit_slot_rects[v6a].y2
            - dat_kit_slot_rects[v6a].y1 + 1,
            1, 11);
        c_wait_retraces(15);
        /* Wait for a key or the joystick: fire picks, the other button leaves. */
        do {
            v3m = -1;
            if ((shm_options & OPT_JOYSTICK) != 0 && kbhit() == 0) {
                v3m = c_joystick_read(&v0j, &v1k);
                if (c_joystick_button(0) != 0)
                    v3m = KEY_SPACE;
                if (c_joystick_button(1) != 0)
                    v3m = KEY_ESC;
            } else
                v3m = c_menu_key();
        } while (v3m == -1);
        /* Move the highlight; a diagonal is two moves in turn. */
        v4o = v6a;
        switch (v3m) {
        case JOY_UP_RIGHT:
        case KEY_PGUP:
            v6a = dat_kit_boxes[v6a].right;
            /* fall through */
        case JOY_UP:
        case KEY_UP:
            v6a = dat_kit_boxes[v6a].up;
            break;
        case JOY_DOWN_LEFT:
        case KEY_END:
            v6a = dat_kit_boxes[v6a].left;
            /* fall through */
        case JOY_DOWN:
        case KEY_DOWN:
            v6a = dat_kit_boxes[v6a].down;
            break;
        case JOY_UP_LEFT:
        case KEY_HOME:
            v6a = dat_kit_boxes[v6a].up;
            /* fall through */
        case JOY_LEFT:
        case KEY_LEFT:
            v6a = dat_kit_boxes[v6a].left;
            break;
        case JOY_DOWN_RIGHT:
        case KEY_PGDN:
            v6a = dat_kit_boxes[v6a].down;
            /* fall through */
        case JOY_RIGHT:
        case KEY_RIGHT:
            v6a = dat_kit_boxes[v6a].right;
            break;
        case KEY_ENTER:
        case KEY_SPACE:
            /* Put the thing back and untick its box, or tick it while there is room. */
            if (((INT) asm_kit & 1 << v6a) != 0) {
                asm_kit &= ~(1 << v6a);
                drv_jump_gfx_copy_rect(shd_map_page, dat_kit_slot_rects[v6a].x1, dat_kit_slot_rects[v6a].y1, dat_kit_slot_rects[v6a].x2
                    - dat_kit_slot_rects[v6a].x1
                    + 1, dat_kit_slot_rects[v6a].y2
                    - dat_kit_slot_rects[v6a].y1
                    + 1, shd_screen, dat_kit_slot_rects[v6a].x1, dat_kit_slot_rects[v6a].y1);
                v5++;
            } else if (v5 != 0) {
                asm_kit |= 1 << v6a;
                drv_jump_gfx_copy_rect(asm_saved_page, dat_kit_slot_rects[v6a].x1, dat_kit_slot_rects[v6a].y1, dat_kit_slot_rects[v6a].x2
                    - dat_kit_slot_rects[v6a].x1
                    + 1, dat_kit_slot_rects[v6a].y2
                    - dat_kit_slot_rects[v6a].y1
                    + 1, shd_screen, dat_kit_slot_rects[v6a].x1, dat_kit_slot_rects[v6a].y1);
                v5--;
            }
            /* The pistol comes along exactly when the Uzi does not, and the floor plan never. */
            asm_kit = (asm_kit & 0x7ffe)
                                + ((asm_kit & 2) == 0);
            /* Bugs come ten to a kit. */
            asm_bugs_left = (asm_kit & 8) != 0 ? 10 : 0;
            /* Grenades: two of each in the assorted kit, eight of a kind otherwise. */
            for (v2l = 0; v2l < 3; v2l++)
                asm_ammunition[v2l] = 0;
            if ((asm_kit & 0x800) != 0) {
                asm_ammunition[0] = 2;
                asm_ammunition[1] = 2;
                asm_ammunition[2] = 2;
            }
            for (v2l = 0; v2l < 3; v2l++)
                if ((asm_kit & 0x100 << v2l) != 0)
                    asm_ammunition[v2l] = 8;
            c_draw_kit_panel();
#ifdef TAC_EQUIPMENT_GUIDANCE
            if (MOD_ON(additional_guidance))
                c_kit_guidance(v5);
#endif
            break;
        /* Escape starts the mission. */
        case KEY_ESC:
            v5 = -1;
            break;
        }
        /* Put back the box the highlight was on, ticked or not. */
        drv_jump_gfx_copy_rect((asm_kit & 1 << v4o) != 0 ? asm_saved_page
                                                : shd_map_page, dat_kit_slot_rects[v4o].x1, dat_kit_slot_rects[v4o].y1, dat_kit_slot_rects[v4o].x2
            - dat_kit_slot_rects[v4o].x1 + 1, dat_kit_slot_rects[v4o].y2
            - dat_kit_slot_rects[v4o].y1 + 1, shd_screen, dat_kit_slot_rects[v4o].x1, dat_kit_slot_rects[v4o].y1);
    } while (v5 != -1);
    c_sound_command(1);
}
