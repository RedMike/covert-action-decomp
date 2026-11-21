/* DOCMENU.C -- the documents menu: the master plan and personnel files taken.
 */
#include "GAME.H"
#include "CMP_STRT.H"
#include "DECODE.H"
#include "FRAME.H"
#include "SUSPECTS.H"

/* Run the documents menu: one entry per organisation whose papers have been
 * taken, and the master plan above them. */
INT c_document_menu(void)
{
    INT v0j;    /* the organisation being listed */
    INT v1a;    /* the one picked */

    do {
        /* The Documents page and its prompt. */
        c_page_frame(dat_str_documents, 7);
        strcpy(shm_scratch, dat_str_select_document);
        /* Slot 0 is what Escape picks: nothing. */
        asm_menu_choices[0] = -1;
        asm_menu_choice_count = 1;
        /* A line per document held: 0 is the Master Plan, every other organisation its personnel file. */
        for (v0j = 0; v0j < 16; v0j++)
            if ((shm_orgs_known & 1 << v0j) != 0) {
                asm_menu_choices[asm_menu_choice_count++] = v0j;
                if (v0j != 0) {
                    strcat(shm_scratch, shm_orgs[v0j].long_name);
                    strcat(shm_scratch, dat_str_personel_file);
                } else
                    strcat(shm_scratch, dat_str_master_plan_2);
            }
        /* With none held, a "none" line that opens nothing. */
        if (asm_menu_choice_count == 1) {
            strcat(shm_scratch, dat_str_none_8);
            asm_menu_choices[1] = -1;
        }
        /* Show the document picked, and ask again until nothing is. */
        v1a = asm_menu_choices[c_ask_menu(shm_scratch, 20, 23) + 1];
        if (v1a != -1)
            c_personnel_file(v1a, 0, 0);
    } while (v1a != -1);
}
