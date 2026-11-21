/* CAMPAIGN-START-2.C -- more of the module's own routines in CAMPAIGN-START.C's unit, after shared/CAMPAIGN-START.C. */
#include "FINAL.H"
#include "SPRITES.H"
#include "KEYCODES.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "SCREEN.H"
#include "CMISEND.H"
#include "CMISSTRT.H"
#include "SAVELOAD.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "CSTART.H"
#include "ORIENT.H"

/* Pack organisation `n`'s row of dat_org_table into a visuals word: fields 2
 * to 5 less one, three bits each from bit 4, added to field 1 * 2 + field 6 *
 * 4 - field 0 + 1.
 */
INT c_pack_org(INT n)
{
    INT i;
    INT value;

    /* The low four bits from fields 0, 1 and 6. */
    value = dat_org_table[n][1] * 2
          + dat_org_table[n][6] * 4
          - dat_org_table[n][0] + 1;
    /* Fields 2 to 5, 1 to 8 each, as three-bit fields from bit 4. */
    for (i = 0; i < 4; i++)
        value += (dat_org_table[n][i + 2] - 1)
               << (i * 3 + 4);
    return value;
}

/* Draw organisation `n`'s MasterMind framed at (x, y): nested rectangles, the
 * face, and the body under it, from its visuals word and its table row.
 * `unused_a` and `unused_b` are never read. The (UNSIGNED_INT) casts keep the
 * code as shipped.
 */
void c_draw_mastermind_face_panel(INT n, INT x, INT y, INT unused_a,
                                  INT unused_b)
{
    INT value;

    value = c_pack_org(n);
    /* The frame: nested rectangles in the face colours. */
    drv_jump_gfx_set_colour_map(&shd_colours_face, &shd_colours_face);
    drv_real_fill_rect(shd_screen, x - 2, y - 2, 54, 56, 7);
    drv_real_fill_rect(shd_screen, x - 1, y - 1, 52, 54, 13);
    drv_real_fill_rect(shd_screen, x + 2, y + 2, 46, 45, 5);
    /* The backdrop: colour 7 where bits 2 and 3 of the visuals are both set, except on CGA. */
    drv_real_fill_rect(shd_screen, (UNSIGNED_INT) x + 3,
                      (UNSIGNED_INT) y + 3, 44, 43,
                      (value >> 2 & 3) == 3 && shm_graphics_letter != 'C'
                          ? 7 : 3);
    /* The face, then the body under it from the bank bit 0 picks and the row's field 7. */
    c_draw_face(value, x + 12, y + 3);
    c_draw_sprite((value & 1 ? SPRITE_BODIES_1 : SPRITE_BODIES_0)
                           + dat_org_table[n][7],
                       x + 3, y + 28);
}

/* Show every organisation's MasterMind and name in turn, one to a screen,
 * waiting for a key after each.
 */
void c_show_all_orgs(void)
{
    INT i;

    drv_jump_gfx_set_palette(&dat_palette_badge);
    /* Each of the 26 on a cleared screen, face over name, until a key is pressed. */
    for (i = 0; i < 26; i++) {
        drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 0);
        c_draw_mastermind_face_panel(i, 80, 24, 0, 0);
        c_write_text_trimmed(dat_org_names[i], 80, 100, 15);
        getch();
    }
}

/* The copyright screen: pick a named organisation's head among fifteen faces
 * on a 5 by 3 grid, with the keys or the joystick, and answer whether the pick
 * was right. `faces` records each cell's organisation and is never read.
 */
INT c_copy_protection(void)
{
    INT used[26];
    INT faces[15];
    INT done;
    INT key;
    INT ax;
    INT bx;
    INT ry;
    INT ib;
    INT cx;
    INT slotj;
    INT group;
    INT right;

    /* The organisation to recognise, and which of the fifteen cells it will sit in. */
    drv_jump_gfx_set_palette(&dat_palette_badge);
    for (ib = 0; ib < 26; ib++)
        used[ib] = 0;
    right = c_random_below(26);
    slotj = c_random_below(15);
    used[right] = 1;
    /* Name it in the question, drawn without waiting for an answer. */
    drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 5);
    strcpy(shm_scratch, dat_str_max_i_m_sure);
    strcat(shm_scratch, dat_org_names[right]);
    strcat(shm_scratch, dat_str_among_these_faces);
    shm_menu_draw_only = 1;
    c_ask_menu((rt_addr) shm_scratch, 16, 1);

    /* Fill the 5 by 3 grid: the right one in its cell, fourteen others never repeated. */
    for (ib = 0; ib < 15; ib++) {
        if (ib == slotj) {
            group = right;
        } else {
            do {
                group = c_random_below(26);
            } while (used[group] != 0);
            used[group] = 1;
        }
        c_draw_mastermind_face_panel(group, (ib % 5) * 64 + 4,
                                     (ib / 5) * 60 + 24, 0, 0);
        faces[ib] = group;
    }

    /* The cursor starts on the middle cell. */
    cx = 2;
    ry = 1;
    ib = 7;
    done = 0;
    do {
        /* Blink: the highlight comes off the cell, for a moment while no key waits. */
        if (shm_cga != 0)
            c_outline_box((ib % 5) * 64 + 1, (ib / 5) * 60 + 21,
                               55, 57, 0);
        else
            drv_jump_gfx_fill(shd_screen, (ib % 5) * 64 + 3,
                              (ib / 5) * 60 + 23, 54, 56, 0, 13);
        if (drv_jump_keyboard_empty() != 0)
            c_wait_retraces(15);
        /* A move from the stick, the button as Enter, or else a key. */
        key = c_joystick_read((INT *) &ax, (INT *) &bx);
        if ((shm_options & OPT_JOYSTICK) && c_joystick_button(0) != 0)
            key = KEY_ENTER;
        if (key == -1 && drv_jump_keyboard_empty() == 0)
            key = c_menu_key();
        if (key != -1) {
            /* Stick directions 1 to 8 clockwise from up, or the matching keys, move the cursor. */
            switch (key) {
            case 1:
            case KEY_UP:
                ry--;
                break;
            case 2:
            case KEY_PGUP:
                cx++;
                ry--;
                break;
            case 3:
            case KEY_RIGHT:
                cx++;
                break;
            case 4:
            case KEY_PGDN:
                cx++;
                ry++;
                break;
            case 5:
            case KEY_DOWN:
                ry++;
                break;
            case 6:
            case KEY_END:
                cx--;
                ry++;
                break;
            case 7:
            case KEY_LEFT:
                cx--;
                break;
            case 8:
            case KEY_HOME:
                cx--;
                ry--;
                break;
            /* Enter, Escape or Space settles on the cell under the cursor. */
            case KEY_ENTER:
            case KEY_ESC:
            case KEY_SPACE:
                done = 1;
                break;
            }
            /* The cursor stays on the grid. */
            cx = c_clamp(cx, 0, 4);
            ry = c_clamp(ry, 0, 2);
            ib = ry * 5 + cx;
        }
        /* Highlight the cell the cursor is on. */
        if (shm_cga != 0)
            c_outline_box((ib % 5) * 64 + 1, (ib / 5) * 60 + 21,
                               55, 57, 15);
        else
            drv_jump_gfx_fill(shd_screen, (ib % 5) * 64 + 3,
                              (ib / 5) * 60 + 23, 54, 56, 13, 0);
        c_wait_retraces(15);
    } while (done == 0);

    /* Clear the screen and switch to the title palette. */
    drv_real_fill_rect(shd_screen, 0, 0, 320, 200, 5);
    drv_jump_gfx_set_palette(&dat_palette_title);
    /* The shipped file NOPs out this compare's JNE, so any pick answers 1;
     * `copyright_patch` redoes that after the link, and COPYRIGHT_ANSWER gives
     * the portable build the same answer. */
    return COPYRIGHT_ANSWER(ib == slotj);
}

/* Clear the bottom message panel to the background colour, 5. */
void c_clear_message_panel(void)
{
    drv_real_fill_rect(shd_screen, 4, 149, 312, 48, 5);
}
