/* SPRITES.H -- names for the indices into shm_faces_sprites.
 *
 * A name is where a run of sprites starts, and the site adds what picks one
 * out of it: the heading, the clue's source, the low bits of a packed face.
 */
#ifndef SPRITES_H
#define SPRITES_H

#define SPRITE_FACES_0      0x00    /* face parts out of facesf.pic, forty */
#define SPRITE_FACES_1      0x28    /* and out of faces.pic; bit 0 of a packed face picks the bank */
#define SPRITE_PLANE        0x50    /* the plane, + the heading, 0 to 7 */
#define SPRITE_PLANE_SHADOW 0x58    /* its shadow, + the heading */
#define SPRITE_CLUE_SOURCE  0x60    /* + the clue's source, 0 to 6 */
#define SPRITE_BODIES_1     0x68    /* shoulders to neck for the faces.pic bank, four */
#define SPRITE_PAPERCLIP    0x6c    /* on the page views */
#define SPRITE_FOLDER_START 0x6d    /* the folder edge a page's heading starts with */
#define SPRITE_FOLDER_END   0x6e    /* and the one it ends with */
#define SPRITE_TYPEWRITER   0x6f    /* the typewriter head */
#define SPRITE_BODIES_0     0x70    /* shoulders to neck for the facesf.pic bank, four */

#endif /* SPRITES_H */
