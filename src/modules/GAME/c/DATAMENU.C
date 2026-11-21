/* DATAMENU.C -- the data-files menu: clues, dossiers, documents and reports.
 */
#include "GAME.H"
#include "SPRITES.H"
#include "BLOCK.H"
#include "CMP_STRT.H"
#include "ADVICE.H"
#include "DECODE.H"

/* The data-files menu's entries, in the order dat_note_04 and dat_note_05 list them. */
enum data_menu_entry {
    DATA_MENU_NO_CHOICE = -1,   /* nothing picked: Escape, or the bar off every entry */
    DATA_MENU_CLUES = 0,
    DATA_MENU_SUSPECTS = 1,
    DATA_MENU_INSIDE_INFORMATION = 2,
    DATA_MENU_NEWS_BULLETINS = 3,
    DATA_MENU_ORGANIZATION_SUMMARIES = 4,
    DATA_MENU_CITY_SUMMARIES = 5,
    DATA_MENU_ACTIVITY_REPORTS = 6
};

/* Run the data-files menu until it is left. */
INT c_data_menu(void)
{
    INT v0j;    /* the entry picked */

    do {
        /* The menu, below the icon for clue source 5. */
        c_clear_for_menu();
        c_draw_sprite(SPRITE_CLUE_SOURCE + 5, 64, 4);
        strcpy(shm_scratch, dat_note_04);
        strcat(shm_scratch, dat_note_05);
        v0j = c_ask_menu(shm_scratch, 20, 31);
        /* Each report comes up on a clean screen, and the menu returns after it. */
        c_clear_for_menu();
        switch (v0j) {
        case DATA_MENU_CLUES:
            c_clue_menu(-1);
            break;
        case DATA_MENU_SUSPECTS:
            c_dossiers();
            break;
        case DATA_MENU_INSIDE_INFORMATION:
            c_document_menu();
            break;
        case DATA_MENU_NEWS_BULLETINS:
            c_log_draw(LONG_LIT(0));
            break;
        case DATA_MENU_ORGANIZATION_SUMMARIES:
            c_org_info();
            break;
        case DATA_MENU_CITY_SUMMARIES:
            c_city_info();
            break;
        case DATA_MENU_ACTIVITY_REPORTS:
            c_activity_report();
            break;
        }
    } while (v0j != DATA_MENU_NO_CHOICE);
}
