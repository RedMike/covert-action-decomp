/* DASHBOARD.C -- drawing the dashboard.
 */
#include "CHASE.H"
#include "RANDOM.H"
#include "SIGHT.H"
#include "TEXTOUT.H"
#include "BOARDDOT.H"
#include "DASHBOAR.H"
#include "CLOCK.H"
#include "CARSPEC.H"

/* Draw the dashboard: the windscreen and the suspect's car through it at the
 * size the sighting range picks, the gear, the suspicion bar, the clock and
 * the four tracking arrows.
 */
INT c_dashboard(void)
{
    /* The road ahead cycles through its eight frames. */
    if (asm_windscreen_frame > 7)
        asm_windscreen_frame = 0;
    /* A new view of the road replaces the old one, and wipes the car shown on it. */
    if (asm_windscreen_frame != dat_windscreen_shown) {
        drv_jump_gfx_copy_rect(dat_dash_page, (asm_windscreen_frame / 4) * 125, (asm_windscreen_frame % 4) * 47, 116, 44, shd_screen, 201, 1);
        drv_jump_gfx_copy_rect(dat_tile_page, 202, 145, 116, 24, shd_screen, 202, 45);
    }
    /* The suspect's car shows through the windscreen only while it is in sight. */
    asm_windscreen_range = c_sight(asm_active_car);
    if (asm_windscreen_range != 0 && asm_sight_dir != 0) {
        /* The nearer the suspect, the bigger its car and the lower on the windscreen. */
        asm_windscreen_range += (INT) asm_windscreen_range / 2;
        asm_dash_scratch = c_clamp((INT) asm_windscreen_range / 4 - 2, 0, 15);
        asm_windscreen_near = -(c_clamp(asm_windscreen_range, 0, 63) - 63);
        asm_windscreen_car_y = ((asm_windscreen_near * asm_windscreen_near
                              >> 2) * 20 >> 10) + 19;
        /* A suspect heading another way shows off to the side, more so up close. */
        asm_windscreen_car_x = 61;
        if (asm_cars[asm_active_car].facing
            != asm_cars[0].facing)
            asm_windscreen_car_x -=
                (asm_windscreen_near * asm_windscreen_near >> 2)
                * 20 >> 7;
        /* Redraw the car only when it has moved or the road behind it changed. */
        if (asm_windscreen_car_y != dat_windscreen_car_shown
            || asm_windscreen_frame != dat_windscreen_shown) {
            /* An unchanged road still shows the old car, so wipe it first. */
            if (asm_windscreen_frame == dat_windscreen_shown) {
                drv_jump_gfx_copy_rect(dat_dash_page, (asm_windscreen_frame / 4) * 125, (asm_windscreen_frame % 4) * 47, 116, 44, shd_screen, 201, 1);
                drv_jump_gfx_copy_rect(dat_tile_page, 202, 145, 116, 24, shd_screen, 202, 45);
            }
            drv_jump_gfx_sprite_put_clipped(dat_windscreen,
                asm_windscreen_car_x
                - (dat_windscreen_car_rects[asm_dash_scratch][2]
                   - dat_windscreen_car_rects[asm_dash_scratch][0]) / 2,
                asm_windscreen_car_y,
                asm_windscreen_car_sprites[asm_dash_scratch]);
        }
        dat_windscreen_car_shown = asm_windscreen_car_y;
    } else {
        /* Out of sight: wipe a car still showing, unless a new view already did. */
        if (dat_windscreen_car_shown != 0xffff && asm_windscreen_frame == dat_windscreen_shown) {
            drv_jump_gfx_copy_rect(dat_dash_page, (asm_windscreen_frame / 4) * 125, (asm_windscreen_frame % 4) * 47, 116, 44, shd_screen, 201, 1);
            drv_jump_gfx_copy_rect(dat_tile_page, 202, 145, 116, 24, shd_screen, 202, 45);
        }
        dat_windscreen_car_shown = -1;
    }
    dat_windscreen_shown = asm_windscreen_frame;
    /* The speedometer: twenty miles an hour a gear. */
    strcpy(shm_scratch, dat_str_empty_2);
    strcat(shm_scratch,
               itoa(asm_cars[asm_active_car].gear * 20,
                        asm_number_digits, 10));
    shd_screen->bg_pen = 5;
    c_write_text(shm_scratch, 230, 75, 7);
    /* The suspicion bar: how much the suspect has noticed this car, in ten steps. */
    asm_dash_scratch = c_clamp(
        asm_cars[asm_active_car].suspicion * 5
        / asm_suspicion_scale, 0, 10) * 3;
    /* Refreshed every fourth frame, and blinking once full to warn the player. */
    if ((asm_frame_tick & 3) == 0) {
        drv_jump_gfx_copy_rect(dat_tile_page, 288, 186, 30, 2, shd_screen, 288, 85);
        if (asm_dash_scratch != 0
            && ((asm_frame_tick & 7) == 0 || (INT) asm_dash_scratch < 30))
            drv_jump_gfx_fill(shd_screen, 288, 84,
                              asm_dash_scratch, 2, 7, 14);
    }
    /* The time of day the chase has reached. */
    c_write_text(c_clock_text(asm_frame_tick), 290, 75, 9);
    /* The lock-on light blinks while the car drives itself after the suspect. */
    if ((asm_frame_tick & 3) == 0) {
        drv_jump_gfx_copy_rect(dat_tile_page, 275, 185, 10, 10, shd_screen, 275, 84);
        if ((asm_frame_tick & 4) == 0
            && asm_cars[asm_active_car].locked_on == 1)
            drv_jump_gfx_fill(shd_screen, 276, 85, 6, 7, 1,
                              shm_cga != 0 ? 15 : 7);
    }
    /* A car with tracking gets a compass, refreshed every fourth frame. */
    if ((asm_frame_tick & 3) == 0) {
        drv_jump_gfx_copy_rect(dat_tile_page, 273, 175, 14, 10, shd_screen, 273, 74);
        if (asm_cars[asm_active_car].spec & CAR_TRACKING) {
            /* It alternates between the arrows pointing to the suspect... */
            if (asm_frame_tick & 4) {
                asm_compass_dx = asm_cars[0].x
                    - asm_cars[asm_active_car].x;
                asm_compass_dy = asm_cars[0].y
                    - asm_cars[asm_active_car].y;
                if (asm_compass_dx >= 0 && asm_compass_dy <= 0)
                    drv_jump_gfx_fill(shd_screen, 280, 74, 4, 4,
                                      5, 11);
                if (asm_compass_dx >= 0 && asm_compass_dy >= 0)
                    drv_jump_gfx_fill(shd_screen, 280, 79, 4, 4,
                                      5, 11);
                if (asm_compass_dx <= 0 && asm_compass_dy <= 0)
                    drv_jump_gfx_fill(shd_screen, 273, 74, 4, 4,
                                      5, 11);
                if (asm_compass_dx <= 0 && asm_compass_dy >= 0)
                    drv_jump_gfx_fill(shd_screen, 273, 79, 4, 4,
                                      5, 11);
            } else
                /* ...and a dot for the way the player's own car is heading. */
                c_board_dot(
                    dat_side_dx[asm_cars[asm_active_car].facing]
                    + 278,
                    dat_side_dy[asm_cars[asm_active_car].facing]
                    + 78, 9);
        }
    }
}
