/* CLUEMENU.C -- the Clues menu: one entry per crime role a clue is about.
 */
#include "GAME.H"
#include "KEYCODES.H"
#include "MISC1.H"
#include "ADVICE.H"
#include "DIALOG.H"
#include "FRAME.H"
#include "CASE.H"
#include "PANEL.H"
#include "ALERTLVL.H"
#include "ROLEFLAG.H"

/* List the crime roles that have clues, in two alternating columns, and let
 * the player pick one to read. */
INT c_clue_menu(INT nth)
{
    INT v0j;        /* the suspect filling the role */
    register INT v1j;   /* the clue's role, while it is being tried */
    register INT v2j;   /* where the role's record starts */
    INT v3k;        /* the key */
    INT v4k[5];     /* the second line of the entry */
    INT v5k;        /* what the key chose */
    INT v6l;        /* the highlight's column */
    INT v7l;        /* the role this entry stands for */
    INT v8l;        /* the row being drawn */
    INT v9m;        /* the entry being walked */
    INT v10f;       /* declared, and nothing reads it */
    INT v11f;       /* the entry's colour */

    for (;;) {
        /* Blank the strip at the top, and no role is listed yet. */
        drv_real_fill_rect(shd_screen, 0, 0, 320, 20, 8);
        for (v9m = 0; v9m < shm_crime_role_count; v9m++)
            *((char *) &shm_crime_roles[v9m].flags + 1) &= ~(ROLE_LISTED >> 8);
        asm_menu_choice_count = 0;
        v8l = 6;
        /* One entry for each role the player holds a clue about, in the order the clues came. */
        for (v9m = 0; v9m < 80; v9m++) {
            v1j = shm_clues_shown[v9m].role;
            if (v1j == -1)
                continue;
            v7l = v1j;
            v2j = v1j * 48;
            if ((*(INT *) &((struct CRIME_ROLE *) ((char *) shm_crime_roles + v2j))->flags & ROLE_LISTED) != 0)
                continue;
            *((char *) &((struct CRIME_ROLE *) ((char *) shm_crime_roles + v2j))->flags + 1) |= ROLE_LISTED >> 8;
            asm_menu_choices[asm_menu_choice_count++] = v7l;
            /* Its second line says whether the role's suspect has been arrested or turned. */
            v0j = ((struct CRIME_ROLE *) ((char *) shm_crime_roles + v2j))->suspect;
            shm_scratch[0] = 0;
            if (shm_suspects[v0j].alert_level == ALERT_ARRESTED)
                strcpy(shm_scratch, dat_str_arrested_3);
            if (shm_suspects[v0j].alert_level == ALERT_TURNED)
                strcpy(shm_scratch, dat_str_turned_4);
            strcpy((char *) v4k, shm_scratch);
            /* Its first line is the object the clue names. */
            shm_scratch[0] = 0;
            c_clue_thing(shm_clues_shown[v9m].text);
            /* A band in the entry's colour, alternating down the list, one colour on CGA. */
            v11f = dat_clue_colours[asm_menu_choice_count & 3];
            if (shm_cga != 0)
                v11f = 2;
            drv_real_fill_rect(shd_screen, 0, v8l + 8, 320, 8, v11f);
            /* A folder with its label, entries taking the right and left halves in turn. */
            if ((asm_menu_choice_count & 1) != 0) {
                c_folder_header(160, v8l, v11f);
                drv_real_fill_rect(shd_screen, 172, v8l + 1, 134, 9, 7);
                c_draw_centred(shm_scratch, 240, v8l + 2, 0);
                c_draw_centred((str_addr) v4k, 240, v8l + 6, 12);
            } else {
                c_folder_header(0, v8l, v11f);
                drv_real_fill_rect(shd_screen, 12, v8l + 1, 134, 9, 7);
                c_draw_centred(shm_scratch, 80, v8l + 2, 0);
                c_draw_centred((str_addr) v4k, 80, v8l + 6, 12);
            }
            /* The next entry sits a little lower, overlapping in the other half. */
            v8l += 6;
        }
        /* Below the folders, blank the rest and frame the "Clues" title in a panel. */
        drv_real_fill_rect(shd_screen, 0, v8l + 10, 320, 190 - v8l, 8);
        strcpy(shm_scratch, dat_str_clues_2);
        c_write_text_trimmed(shm_scratch, 144, v8l + 16, 15);
        c_outline_box(142, v8l + 14,
                        c_text_width(shm_scratch) + 4, 10, 7);
        c_outline_box(16, v8l + 12, 288, 24, 0);
        v5k = 0;
        do {
            /* Highlight the chosen entry's label, in whichever half it sits. */
            v6l = (asm_clue_selected & 1) != 0 ? 12 : 172;
            v8l = asm_clue_selected * 6 + 7;
            drv_jump_gfx_fill(shd_screen, v6l, v8l, 136, 9, 7, 15);
            c_wait_retraces(20);
            /* Wait for the stick or a key, a key taking precedence. */
            do {
                v3k = c_joystick_key();
            } while (v3k == -1 && drv_jump_keyboard_empty() != 0);
            if (drv_jump_keyboard_empty() == 0)
                v3k = c_menu_key();
            switch (v3k) {
            /* Down and up move through the entries, stopping at the ends. */
            case KEY_DOWN:
                if (asm_menu_choice_count - 1 > asm_clue_selected)
                    asm_clue_selected++;
                break;
            case KEY_UP:
                if (asm_clue_selected > 0)
                    asm_clue_selected--;
                break;
            /* Return or space reads the entry's clues. */
            case KEY_ENTER:
            case KEY_SPACE:
                v5k = 1;
                break;
            /* Escape leaves the menu. */
            case KEY_ESC:
                v5k = -1;
                break;
            }
            /* Take the highlight off again before it moves. */
            drv_jump_gfx_fill(shd_screen, v6l, v8l, 136, 9, 15, 7);
        } while (v5k == 0);
        /* Read the chosen role's clues and come back to the menu, or leave. */
        c_wait_for_release();
        if (v5k != -1)
            c_clue_list(asm_menu_choices[asm_clue_selected]);
        else
            return;
    }
}
