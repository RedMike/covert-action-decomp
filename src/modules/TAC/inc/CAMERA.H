/* CAMERA.H -- the film the player has, kit bit 4 being the camera.
 *
 * `kit` and `kind` are asm_kit and asm_mission_kind, passed because only a .C
 * has its names rewritten. TAC_PHOTOS_BY_DEFAULT gives a kit with no camera
 * the photos_without_camera count, save in kinds 1 to 3, whose kit is fixed.
 */
#ifndef CAMERA_H
#define CAMERA_H

#include "MODOPTS.H"

#ifdef TAC_PHOTOS_BY_DEFAULT
#define CAMERA_FILM(kit, kind) (((kit) & 4) != 0 ? 0x24 \
    : (kind) == 1 || (kind) == 2 || (kind) == 3 ? 0 \
    : MOD_VALUE(photos_without_camera, 2))
#define CAMERA_CARRIED(kit, kind) (((kit) & 4) != 0 \
                                   || CAMERA_FILM(kit, kind) != 0)
#else
#define CAMERA_FILM(kit, kind) 0x24
#define CAMERA_CARRIED(kit, kind) (((kit) & 4) != 0)
#endif

#endif /* CAMERA_H */
