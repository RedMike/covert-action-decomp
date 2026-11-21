/* DOSSIERS.C -- the suspect files, picked from a list and shown in turn.
 */
#include "GAME.H"
#include "DECODE.H"
#include "FRAME.H"
#include "CASE.H"

/* Show the suspect files, one after another, until the list is left. */
INT c_dossiers(void)
{
    INT v0j;
    INT v1n;    /* the suspect picked */
    INT v2b;

    for (;;) {
        /* The Suspect Files list, with slot 0 for Escape; show whoever is picked. */
        c_page_frame(dat_str_suspect_files, 7);
        asm_menu_choice_count = 1;
        asm_menu_choices[0] = -1;
        v1n = c_suspect_menu();
        if (v1n == -1)
            break;
        /* The suspect's file, a page of its own, until a key is pressed. */
        c_dossier(v1n, 0, 0);
        c_wait_key();
    }
}
