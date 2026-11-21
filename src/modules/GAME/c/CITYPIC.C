/* CITYPIC.C -- a city's picture, with its name and country.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "DIALOG.H"
#include "PANEL.H"

/* Draw city `city`'s picture centred on (`x`, `y`) with its name and country
 * above it, loading the picture first if a different city is on screen. */
INT c_city_picture(INT city, INT x, INT y)
{
    /* A new city: its picture's file is its name, spaces out and cut to eight, plus ".pic". */
    if (city != shd_city_on_screen) {
        strcpy(shm_scratch, shm_cities[city].name);
        c_squeeze(shm_scratch);
        if ((INT) strlen(shm_scratch) > 8)
            shm_scratch[8] = 0;
        strcat(shm_scratch, dat_str_pic);
        /* Load it and keep it on the picture page, so the same city is not loaded twice. */
        c_load_city_picture(shm_scratch);
        drv_jump_gfx_copy_rect(shd_map_page, 0, 0, asm_loaded_width, asm_loaded_height, shd_picture_page, 0, 0);
        shd_city_on_screen = city;
        asm_picture_width = asm_loaded_width;
        asm_picture_height = asm_loaded_height;
    }
    /* "City, Country" in white just above the picture's top. */
    y -= (INT) asm_picture_height / 2;
    strcpy(shm_scratch, shm_cities[city].name);
    strcat(shm_scratch, dat_str_comma_space);
    strcat(shm_scratch, shm_cities[city].country);
    c_draw_centred(shm_scratch, x, y - 10, 15);
    /* The picture itself in a white outline, if one was loaded. */
    x -= (INT) asm_picture_width / 2;
    if (asm_loaded_width != 0) {
        c_outline_box(x - 1, y - 1, asm_picture_width + 1,
                        asm_picture_height + 1, 15);
        drv_jump_gfx_copy_rect(shd_picture_page, 0, 0, asm_picture_width, asm_picture_height, shd_screen, x, y);
    }
    /* Leave the background pen at the screen's colour 5. */
    shd_screen->bg_pen = 5;
}
