/* CAR-PICK.C -- choosing the cars.
 */
#include "CHASE.H"
#include "KEYCODES.H"
#include "RANDOM.H"
#include "SETUP.H"
#include "JOYWAIT.H"
#include "BOXES.H"
#include "CARPICK.H"
#include "RETRACE.H"
#include "ANI_LD2.H"
#include "TEXTOUT.H"
#include "KEYREAD.H"
#include "CARSPEC.H"

/* Offer four cars, each a word of CAR.spec flags, and let cars 1 and 2 take
 * one each. The four are drawn at random until each rates `3 - difficulty` and
 * no two match.
 *
 * The locals' names fix their frame slots.
 */
void c_pick_cars(void)
{
    UNSIGNED_INT v0j;                   /* the row the first car took */
    INT v1j[4];                         /* which colours are recoloured */
    INT v2j;                            /* the row the highlight is on */
    INT v3j;                            /* the car being made */
    INT v4j;                            /* how it rates against the difficulty */
    INT v5k;                            /* the key */
    INT v6k;                            /* whether this player has settled */
    INT v7k;                            /* the strip its picture comes from */
    INT v8k;                            /* where the next line of text goes */
    INT v9l;                            /* the car offered, then choosing */
    INT v10e;                           /* an earlier car, then nothing */
    INT v11e;                           /* its visibility, hence colour */
    INT v12e[4];                        /* the four on offer */

    c_sound_command(0x27);
    c_load_picture(dat_str_cars_pic, 1);
    drv_jump_gfx_copy_rect(shd_map_page, 0x9a, 0, 0xa6, 0xc8, shd_screen, 0x9a, 0);
    for (v9l = 0; v9l < 4; v9l++)
        v1j[v9l] = 0;
    for (v9l = 0; v9l < 4; v9l++) {
        do {
            v3j = c_random_below(0x40);
            v4j = v3j & CAR_SPEED;
            if (v3j & CAR_TRACKING)
                v4j += 2;
            if (v3j & CAR_HANDLING)
                v4j++;
            v4j -= (v3j & CAR_VISIBILITY) >> CAR_VISIBILITY_SHIFT;
            for (v10e = 0; v10e < v9l; v10e++)
                if (v12e[v10e] == v3j)
                    v4j = -1;
        } while (v4j != 3 - shm_difficulty || ((char) v3j & CAR_SPEED) == 3);
        v12e[v9l] = v3j;
        v7k = 2;
        if ((v3j & CAR_VISIBILITY) == 0)
            v7k = 3;
        if (v3j & CAR_HANDLING && v3j & CAR_SPEED)
            v7k = 1;
        if (((char) v3j & CAR_SPEED) == 2)
            v7k = 0;
        drv_jump_gfx_copy_rect(shd_map_page, 0, v7k * 0x32, 0x9a, 0x32, shd_screen, 0, v9l * 0x32);
        v11e = (v3j & CAR_VISIBILITY) >> CAR_VISIBILITY_SHIFT;
        if (v1j[v11e] == 0 && shm_cga == 0) {
            drv_jump_gfx_fill(shd_screen, 0, v9l * 0x32, 0x9a, 0x32, 0xb,
                              *(INT *) ((char *) &asm_car_stats + 7 + v11e * 4));
            drv_jump_gfx_fill(shd_screen, 0, v9l * 0x32, 0x9a, 0x32, 3,
                              *(INT *) ((char *) &asm_car_stats + 9 + v11e * 4));
        }
        v1j[v11e] = 1;
        v8k = v9l * 0x32 + 0xb;
        if (v3j & CAR_TRACKING)
            c_write_text_trimmed(dat_str_tracking, 0x100, v8k, 0xf);
        v8k += 9;
        strcpy(shm_scratch, &dat_str_empty);
        strcat(shm_scratch,
                   itoa((v3j & CAR_SPEED) * 0x14 + 0x28,
                        asm_number_digits, 10));
        strcat(shm_scratch, dat_str_mph);
        c_write_text_trimmed(shm_scratch, 0x100, v8k, 0xf);
        v8k += 9;
        strcpy(shm_scratch,
                   v3j & CAR_HANDLING ? dat_str_excellent : dat_str_fair);
        c_write_text_trimmed(shm_scratch, 0x100, v8k, 0xf);
        v8k += 9;
        switch ((v3j & CAR_VISIBILITY) >> CAR_VISIBILITY_SHIFT) {
        case 0:
            strcpy(shm_scratch, dat_str_low);
            break;
        case 1:
            strcpy(shm_scratch, dat_str_moderate);
            break;
        case 2:
            strcpy(shm_scratch, dat_str_high);
            break;
        case 3:
            strcpy(shm_scratch, dat_str_extreme);
            break;
        }
        c_write_text_trimmed(shm_scratch, 0x100, v8k, 0xf);
        v8k += 9;
    }
    c_wait_for_release();
    drv_jump_gfx_set_colour_map(&dat_colours_car_pick, &dat_colours_car_pick);
    v0j = -1;
    for (v9l = 1; v9l <= 2; v9l++) {
        v2j = v0j == 0;
        if (shm_cga != 0)
            c_outline_box(0, v2j * 0x32 + 9, 0x13f, 0x25, 0xf);
        else
            drv_jump_gfx_fill(shd_screen, 0, v2j * 0x32, 0x140, 0x32, 1, 9);
        v6k = 0;
        do {
            while (drv_jump_keyboard_empty() != 0) {
                if (shm_cga != 0)
                    c_outline_box(0, v2j * 0x32 + 9, 0x13f, 0x25, 0);
                else
                    drv_jump_gfx_fill(shd_screen, 0, v2j * 0x32,
                                      0x140, 0x32, 9, 1);
                c_wait_retraces(10);
                if (shm_cga != 0)
                    c_outline_box(0, v2j * 0x32 + 9, 0x13f, 0x25, 0xf);
                else
                    drv_jump_gfx_fill(shd_screen, 0, v2j * 0x32,
                                      0x140, 0x32, 1, 9);
                c_wait_retraces(10);
            }
            if (shm_cga != 0)
                c_outline_box(0, v2j * 0x32 + 9, 0x13f, 0x25, 4);
            else
                drv_jump_gfx_fill(shd_screen, 0, v2j * 0x32,
                                  0x140, 0x32, 9, 1);
            v5k = c_menu_key();
            switch (v5k) {
            case KEY_DOWN:
                if (v2j < 3)
                    v2j++;
                break;
            case KEY_UP:
                if (v2j > 0)
                    v2j--;
                break;
            case KEY_ENTER:
            case KEY_SPACE:
                v6k = 1;
            }
            if (v2j == v0j) {
                if ((v5k == KEY_DOWN && v2j < 3) || v2j == 0)
                    v2j++;
                else
                    v2j--;
            }
            if (shm_cga != 0)
                c_outline_box(0, v2j * 0x32 + 9, 0x13f, 0x25, 0xf);
            else
                drv_jump_gfx_fill(shd_screen, 0, v2j * 0x32,
                                  0x140, 0x32, 1, 9);
        } while (v6k == 0);
        asm_cars[v9l].spec = v12e[v2j];
        v0j = v2j;
        strcpy(shm_scratch, (char *) asm_car_stats);
        strcat(shm_scratch, itoa(v9l, asm_number_digits, 10));
        c_write_text_trimmed(shm_scratch, 0x9a, v2j * 0x32 + 9, 0xf);
    }
    c_sound_command(1);
}
