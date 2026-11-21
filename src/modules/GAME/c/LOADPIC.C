/* LOADPIC.C -- loading a city's picture out of its archive, and measuring it.
 */
#include "GAME.H"
#include "LOADDISK.H"
#include "CMP_STRT.H"
#include "ANI_LD2.H"
#include "ARCHIVE.H"
#include "ARCHCLOS.H"

/* Load picture `name` out of cities.cat into the spare buffer, and measure
 * how much of it is drawn. */
INT c_load_city_picture(rt_addr name)
{
    INT v0j;    /* the row or column being looked at */

    /* Without disk 3 in the drive there is no picture: a size of nothing, and disk 2 asked back. */
    if (c_want_disk(3, LONG_LIT(0)) == 0) {
        asm_loaded_width = asm_loaded_height = 0;
        c_want_disk(2, LONG_LIT(1));
        return;
    }
    /* Blank the spare page and decode the picture onto it from the cities archive. */
    drv_real_fill_rect(shd_map_page, 0, 0, 320, 200, 0);
    c_archive_open(dat_str_cities_cat);
    c_load_picture(name, 1);
    c_archive_close();
    /* Back to disk 2 once the picture is in memory. */
    c_want_disk(2, LONG_LIT(1));
    /* On CGA the size is the last lit pixel along the top row and down the left column, within 160 by 100. */
    if (shm_cga != 0) {
        v0j = 0;
        do {
            if (drv_jump_gfx_get_pixel(1, v0j, 0) != 0)
                asm_loaded_width = v0j;
            v0j++;
        } while (v0j < 160);
        for (v0j = 0; v0j < 100; v0j++)
            if (drv_jump_gfx_get_pixel(1, 0, v0j) != 0)
                asm_loaded_height = v0j;
        return;
    }
    /* Otherwise the width is where the top row first goes dark, at most 160. */
    asm_loaded_width = 0;
    while (drv_jump_gfx_get_pixel(1, asm_loaded_width, 0) != 0
           && (INT) asm_loaded_width < 160)
        asm_loaded_width++;
    /* And the height where the left column first goes dark, at most 100. */
    asm_loaded_height = 0;
    while (drv_jump_gfx_get_pixel(1, 0, asm_loaded_height) != 0
           && (INT) asm_loaded_height < 100)
        asm_loaded_height++;
}
