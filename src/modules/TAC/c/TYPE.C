/* TYPE.C -- typing a line into the message buffer.
 */
#include "TAC.H"
#include "KEYCODES.H"
#include "CITY.H"
#include "MENU.H"
#include "GUARD.H"
#include "TYPE.H"

/* Let the player type into the message buffer: a blinking cursor, the arrows
 * and Insert and Delete and Backspace, the first printable key clearing what
 * was there, Return accepting and Escape giving up. */
INT c_type_message(INT left, INT top, INT width)
{
    char v0j[64];   /* the tail of the line, while a character is squeezed in */
    INT v1m;        /* set until the first key, so it replaces the whole line */
    INT v2;         /* the character being blanked */
    INT v3c;        /* the key */

    /* Clear the field's box, seven pixels a character, with the cursor at
     * the start. */
    drv_real_fill_rect(shd_screen, left, top + 1, width * 7, 9, 5);
    shd_screen->bg_pen = 5;
    shm_field_cursor = 0;
    v1m = 1;
    /* Pad what is already there with spaces to the full width. */
    for (v2 = strlen(shm_scratch); v2 < width; v2++)
        *((char *) shm_scratch + v2) = ' ';
    *((char *) shm_scratch + width) = 0;
    c_text_field_draw(left, top, width);
    /* Start from a quiet keyboard, with the keypad giving arrows. */
    c_wait_for_release();
    NUM_LOCK_OFF();
    for (;;) {
        /* Blink the cursor until a key comes. */
        while (drv_jump_keyboard_empty() != 0) {
            drv_jump_gfx_fill(shd_screen, shm_field_cursor_x, top + 1,
                              shm_field_char_width, 10, 5, 2);
            c_wait_retraces(10);
            drv_jump_gfx_fill(shd_screen, shm_field_cursor_x, top + 1,
                              shm_field_char_width, 10, 2, 5);
            if (drv_jump_keyboard_empty() != 0)
                c_wait_retraces(10);
        }
        v3c = c_menu_key();
        /* Return accepts the line, and the keypad goes back to the game. */
        if (v3c == KEY_ENTER) {
            NUM_LOCK_ON();
            v2 = width - 1;
            break;
        }
        /* The arrows move the cursor within the field. */
        if (v3c == KEY_LEFT && shm_field_cursor != 0)
            shm_field_cursor--;
        if (v3c == KEY_RIGHT && width - 1 > shm_field_cursor)
            shm_field_cursor++;
        /* Insert opens a space at the cursor, losing the last character. */
        if (v3c == KEY_INS) {
            strcpy(v0j, (char *) shm_scratch + shm_field_cursor);
            strcpy((char *) shm_scratch + 1 + shm_field_cursor,
                       v0j);
            *((char *) shm_scratch + shm_field_cursor) = ' ';
            *((char *) shm_scratch + width) = 0;
        }
        /* Delete closes the line up over the cursor's character. */
        if (v3c == KEY_DEL) {
            strcpy((char *) shm_scratch + shm_field_cursor,
                       (char *) shm_scratch + 1 + shm_field_cursor);
            *((char *) shm_scratch + shm_field_cursor) = ' ';
            *((char *) shm_scratch - 1 + width) = ' ';
            *((char *) shm_scratch + width) = 0;
        }
        /* Backspace closes the line up over the character before the cursor. */
        if (v3c == KEY_BACKSPACE && shm_field_cursor != 0) {
            strcpy((char *) shm_scratch - 1 + shm_field_cursor,
                       (char *) shm_scratch + shm_field_cursor);
            *((char *) shm_scratch - 1 + width) = ' ';
            *((char *) shm_scratch + width) = 0;
            shm_field_cursor--;
        }
        /* A printable key overwrites at the cursor and moves it on; as the
         * first key it wipes the old line first. */
        if (v3c < 128 && v3c >= ' ') {
            if (v1m != 0)
                for (v2 = 0; v2 < width; v2++)
                    *((char *) shm_scratch + v2) = ' ';
            *((char *) shm_scratch + shm_field_cursor) = v3c;
            if (width - 1 > shm_field_cursor)
                shm_field_cursor++;
        }
        /* Escape gives up. */
        if (v3c == KEY_ESC)
            return -1;
        v1m = 0;
        c_text_field_draw(left, top, width);
    }
    /* Drop the padding from the end of the line. */
    for (; v2 >= 0 && *((char *) shm_scratch + v2) == ' '; v2--)
        *((char *) shm_scratch + v2) = 0;
    return 1;
}
