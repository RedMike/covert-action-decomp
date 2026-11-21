/* MAIN-2.C -- the main menu around the module's entry point, which is MAIN.C.
 *
 * With the option, orientation and diagnostics menus the builds can add.
 */
#include "FINAL.H"
#include "ANI_LD2.H"
#include "PRIMS.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "LOADDISK.H"
#include "CSTART.H"
#include "CMISEND.H"
#include "CMISSTRT.H"
#include "CASERUN.H"
#include "SAVELOAD.H"
#include "TEXTDTA.H"
#include "FACES.H"
#include "MAIN.H"
#include "ORIENT.H"

#include "MODOPTS.H"
#include "SETUPTXT.H"
#include "RESULT.H"
#include "ALERTLVL.H"

/* The main menu's items past the image's four, in the order they are added. */
#ifdef SETUP_OPTIONS
#define OPTIONS_ITEM 4
#define MOD_OPTIONS_ITEM 5
#else
#define MOD_OPTIONS_ITEM 4
#endif
#ifdef COVERT_MENU_OPTIONS
#define DIAGNOSTICS_ITEM (MOD_OPTIONS_ITEM + 1)
#else
#define DIAGNOSTICS_ITEM 4
#endif

/* Where a menu under the main one goes: eight rows lower for every extra item
 * above Diagnostics, so it does not cover the last. */
#define SUBMENU_Y (0x88 + ((DIAGNOSTICS_ITEM - 4) << 3))

#ifdef EXTRA_MENU_OPTIONS
#include "KEYCODES.H"

/* One more than the slider item, which Left and Right leave the menu on. */
extern INT menu_sideways;
#endif
