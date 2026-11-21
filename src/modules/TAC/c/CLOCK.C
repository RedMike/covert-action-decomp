/* CLOCK.C -- drawing the count of photos left.
 */
#include "TAC.H"
#include "CITY.H"
#include "CLOCK.H"
#include "CAMERA.H"

/* Redraw the counter in the corner: how many photos are left on the film. */
INT c_clock_draw(void)
{
    INT v0j;
    INT v1n;
    INT v2b;

    /* Blank the old count. */
    drv_real_fill_rect(shd_screen, 222, 86, 15, 9, 0);
    /* The film carried less the photos already taken, in decimal. */
    shm_scratch[0] = 0;
    strcat(shm_scratch,
               itoa(CAMERA_FILM(asm_kit, asm_mission_kind) - asm_photos_taken,
                    asm_number_digits, 10));
    c_write_text_trimmed(shm_scratch, 224, 87, 10);
}
