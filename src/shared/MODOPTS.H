/* MODOPTS.H -- the mod options, present only under COVERT_MENU_OPTIONS.
 *
 * FINAL's Mod Options menu sets them and saves them to mods.txt, which a
 * module with something to switch reads back at start. None of this is in the
 * shipped game.
 */
#ifndef MODOPTS_H
#define MODOPTS_H

#ifdef COVERT_MENU_OPTIONS

/* One byte an option, 0 for off, and nothing but bytes: the options are
 * walked as an array, so this order is the order of mod_option_names.
 */
struct MOD_OPTIONS {
    unsigned char fast_tac_move;        /* Faster Break-in Movement */
    unsigned char additional_guidance;  /* Additional Guidance Text */
    unsigned char flexible_orientation; /* Flexible Character Orientation */
    unsigned char unimplemented_rooms;  /* Unimplemented Rooms */
    unsigned char player_disguise_sprite; /* Player Disguise On Map */
    unsigned char photos_without_camera; /* Photos without camera, a count */
};

#define MOD_OPTION_COUNT ((INT) sizeof (struct MOD_OPTIONS))
#define MOD_OPTION_BYTES ((unsigned char *) &mod_options)

extern struct MOD_OPTIONS mod_options;
extern char *mod_option_names[];
void c_mod_options_load(void);

/* Whether a change is switched on. */
#define MOD_ON(field) (mod_options.field != 0)

/* A counted option's value; `value` is what a build without the menu uses. */
#define MOD_VALUE(field, value) ((INT) mod_options.field)

#else

/* With no menu to switch it off, a change that is built in is on. */
#define MOD_ON(field) 1
#define MOD_VALUE(field, value) (value)

#endif

#endif /* MODOPTS_H */
