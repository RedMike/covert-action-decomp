/* FACES.C -- the portrait sprites, the faces made of them and a face's panel.
 *
 * A face is a packed word: bit 0 picks the bank of forty from facesf.pic or
 * faces.pic, each five groups of eight, and bits 1, 4-6, 7-9, 10-12 and 13-15
 * pick one from each group. Bits 2 and 3 are the overlay painted over them.
 */
#include "FINAL.H"
#include "SPRITES.H"
#include "FILEIO.H"
#include "CMISEND.H"
#include "FACES.H"

/* shared_include_start: ../../../../shared/c/FACES-LOAD.C -- generated */
/* FACES-LOAD.C -- c_faces_load, loading every sprite the face system uses.
 */

/* Load the face system's sprites: the faces, the sixteen 8-by-8 sprites under
 * them in faces.pic, the plane at eight headings and its shadow.
 */
void c_faces_load(void)
{
    INT i;

    drv_jump_gfx_pool_alloc();
    c_faces_cut();
    i = 0;
    do {
        shm_faces_sprites[SPRITE_PLANE + i] =
            drv_jump_gfx_grab(2, i % 8 * 9, i / 8 * 9 + 0xaf, 8, 8);
        i++;
    } while (i < 16);
    drv_jump_gfx_pool_release();
    shm_menu_face = 0xffff;
}
/* shared_include_end: ../../../../shared/c/FACES-LOAD.C */

/* shared_include_start: ../../../../shared/c/DRAW-FACE.C -- generated */
/* DRAW-FACE.C -- c_draw_face, drawing a face from its packed description.
 */

/* Draw the face packed into `flags` at (x, y): five sprites, one from each
 * group of eight in the bank bit 0 picks, then the overlay bits 2 and 3 pick.
 * Leaves shm_menu_face at -1.
 */
void c_draw_face(INT flags, INT x, INT y)
{
    if (flags & 1) {
        c_draw_sprite((flags & 2) * 2 + 0x48, x + 1, y + 1);
        c_draw_sprite((flags >> 4 & 7) + 0x40, x + 1, y + 1);
        c_draw_sprite((flags >> 7 & 7) + 0x38, x + 1, y + 1);
        c_draw_sprite((flags >> 10 & 7) + 0x30, x + 1, y + 1);
        c_draw_sprite((flags >> 13 & 7) + 0x28, x + 1, y + 1);
    } else {
        c_draw_sprite((flags & 2) * 2 + 0x20, x + 1, y + 1);
        c_draw_sprite((flags >> 4 & 7) + 0x18, x + 1, y + 1);
        c_draw_sprite((flags >> 7 & 7) + 0x10, x + 1, y + 1);
        c_draw_sprite((flags >> 10 & 7) + 8, x + 1, y + 1);
        c_draw_sprite(flags >> 13 & 7, x + 1, y + 1);
    }
    if (shm_graphics_letter != 'C') {
        switch (flags >> 2 & 3) {
        case 0:
            drv_jump_gfx_fill(shd_screen, x, y, 0x20, 0x23, 0xb, 0xe);
            break;
        case 1:
            drv_jump_gfx_fill(shd_screen, x, y, 0x20, 0x23, 0xb, 6);
            break;
        case 3:
            drv_jump_gfx_fill(shd_screen, x, y, 0x20, 0x23, 0xc, 6);
            /* fall through */
        case 2:
            drv_jump_gfx_fill(shd_screen, x, y, 0x20, 0x23, 0xb, 5);
            break;
        }
    }
    shm_menu_face = 0xffff;
}
/* shared_include_end: ../../../../shared/c/DRAW-FACE.C */

/* shared_include_start: ../../../../shared/c/FACE-PANEL.C -- generated */
/* FACE-PANEL.C -- c_draw_face_panel, a framed portrait with its shoulders.
 */

/* Draw the framed portrait of face `flags` at (x, y): frame, face and
 * shoulders. The casts on `x + 3` and `y + 3` keep the code as shipped.
 */
void c_draw_face_panel(INT flags, INT x, INT y)
{
    INT spare;

    drv_jump_gfx_set_colour_map(&shd_colours_face, &shd_colours_face);
    drv_real_fill_rect(shd_screen, x - 2, y - 2, 0x36, 0x38, 7);
    drv_real_fill_rect(shd_screen, x - 1, y - 1, 0x34, 0x36, 0xf);
    drv_real_fill_rect(shd_screen, x + 2, y + 2, 0x2e, 0x2d, 0);
    drv_real_fill_rect(shd_screen, (UNSIGNED_INT) x + 3,
                      (UNSIGNED_INT) y + 3, 0x2c, 0x2b,
                      (flags >> 2 & 3) == 3 && shm_graphics_letter != 'C'
                      ? 7 : 3);
    c_draw_face(flags, x + 0xd, y + 3);
    if (shm_graphics_letter != 'C') {
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 8, 5);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 0xc, 7);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 0xe, 0xf);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 6, 8);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 4, 8);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 1, 8);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 10, 7);
        drv_jump_gfx_fill(shd_screen, x, y, 0x32, 0x32, 9, 7);
    }
    c_draw_sprite((flags & 1 ? SPRITE_BODIES_1 : SPRITE_BODIES_0) + (flags & 3), x + 3, y + 0x1c);
    drv_jump_gfx_set_colour_map(&shd_colours_screen, &shd_colours_screen_2);
}
/* shared_include_end: ../../../../shared/c/FACE-PANEL.C */

/* shared_include_start: ../../../../shared/c/FACES-CUT.C -- generated */
/* FACES-CUT.C -- c_faces_cut, cutting the face sprites out of their pictures.
 */

/* Cut the face sprites out of facesf.pic and faces.pic: forty face parts and
 * four bodies from each, then faces.pic's clue sources, paperclip, folder ends
 * and typewriter.
 */
void c_faces_cut(void)
{
    INT i;
    INT spare;

    c_decode_picture(2, shd_str_facesf_pic);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_FACES_0 + i] =
            drv_jump_gfx_grab(2, i % 8 * 32 + 1, i / 8 * 0x23 + 1, 0x1e, 0x21);
        i++;
    } while (i < 40);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_BODIES_0 + i] =
            drv_jump_gfx_grab(2, 0x101, i * 20, 0x2c, 0x12);
        i++;
    } while (i < 4);
    c_decode_picture(2, shd_str_faces_pic);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_FACES_1 + i] =
            drv_jump_gfx_grab(2, i % 8 * 32 + 1, i / 8 * 0x23 + 1, 0x1e, 0x21);
        i++;
    } while (i < 40);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_CLUE_SOURCE + i] =
            drv_jump_gfx_grab(2, i * 32 + 0x60, 0xae, 0x20, 0x1a);
        i++;
    } while (i < 7);
    i = 0;
    do {
        shm_faces_sprites[SPRITE_BODIES_1 + i] =
            drv_jump_gfx_grab(2, 0x101, i * 20, 0x2c, 0x12);
        i++;
    } while (i < 4);
    shm_faces_sprites[SPRITE_PAPERCLIP] =
        drv_jump_gfx_grab(2, 0x49, 0xaf, 0x15, 0x16);
    shm_faces_sprites[SPRITE_FOLDER_START] =
        drv_jump_gfx_grab(2, 0x133, 0, 0xb, 8);
    shm_faces_sprites[SPRITE_FOLDER_END] =
        drv_jump_gfx_grab(2, 0x133, 9, 0xc, 8);
    shm_faces_sprites[SPRITE_TYPEWRITER] =
        drv_jump_gfx_grab(2, 0x101, 0xa0, 0x1a, 0xe);
}
/* shared_include_end: ../../../../shared/c/FACES-CUT.C */
