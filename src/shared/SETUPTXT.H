/* SETUPTXT.H -- setup.txt, read by COVERT and written by FINAL's Options menu.
 *
 * DOS only: COVERT reads it under COVERT_SKIP_INTRO, once, before loading the
 * drivers, so the menu (COVERT_MENU_OPTIONS too) can only write it and end the
 * session; the flag tells COVERT to say why once the screen is text again.
 */
#ifndef SETUPTXT_H
#define SETUPTXT_H

#if defined(COVERT_SKIP_INTRO) && !defined(PORT_MODERN)

#ifdef COVERT_MENU_OPTIONS
#define SETUP_OPTIONS
#endif

/* The byte of spare_05 the flag sits in, outside what a save keeps. */
#define COMM_SETUP_RESTART 0

/* What COVERT prints on the way out once FINAL has set the flag. */
#define SETUP_RESTART_NOTE \
    "Settings saved to setup.txt. Restart the game to use them.\r\n"

#endif

#endif /* SETUPTXT_H */
