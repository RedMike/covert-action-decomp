/* ACTREPT.C -- the activity report, charting each city and organisation.
 */
#include "GAME.H"
#include "MISC1.H"
#include "DECODE.H"
#include "DIALOG.H"
#include "CASE.H"

/* Draw the activity report: a bar per city and a bar per organisation, each
 * scaled to its share of the whole. */
INT c_activity_report(void)
{
    INT v0j;    /* what all the organisations add up to */
    INT v1m;    /* what all the cities add up to */
    INT v2;     /* the row the next pair of bars is drawn on */
    INT v3c;    /* the city or organisation being drawn */

    /* The report fills the whole screen. */
    c_menu_box(0, 0, 319, 199, 1);
    /* Total the activity, cities and organisations apart, so each bar is a share of its own whole. */
    v3c = v1m = v0j = 0;
    do {
        v1m += shm_activity.city[v3c];
        v0j += shm_activity.org[v3c];
        v3c++;
    } while (v3c < 16);
    c_write_text(dat_note_19, 96, 6, 15);
    v2 = 20;
    /* Cities down the left, each bar up to 160 pixels long. */
    for (v3c = 0; v3c < 16; v3c++) {
        c_write_text((rt_addr) shm_cities[v3c].name, 2, v2,
                        shm_cga != 0 ? 15 : 3);
        drv_real_fill_rect(shd_screen, 82, v2 + 1,
                          160 * shm_activity.city[v3c] / v1m, 6, 11);
        /* Organisations down the right, one row higher, leaving out organisation 0. */
        if (v3c != 0) {
            c_write_text(shm_orgs[v3c].short_name, 162, v2 - 8, 12);
            drv_real_fill_rect(shd_screen, 242, v2 - 7,
                              160 * shm_activity.org[v3c] / v0j, 6, 14);
        }
        v2 += 8;
    }
    /* Hold the report until a key. */
    c_wait_key();
}
