/* MAIN-6.C -- more of the module's own routines in MAIN.C's unit, after stubs/HOOK-REPAINT.C. */
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

/* The case's opening blurb: two organisations and two cities drawn for the
 * $-keys, free to repeat, then five text.dta paragraphs in a random order,
 * each once, copied into the shared block's message for the next module.
 */
void c_opening_blurb(void)
{
    INT done;
    INT i;
    INT n;

    /* For $-keys 1 to 4: two organisations from records 4 to 15 and two cities, repeats allowed. */
    strcpy(shd_subst_values[1],
               shm_orgs[4 + (INT) c_random_below(12)].long_name);
    strcpy(shd_subst_values[2],
               shm_orgs[4 + (INT) c_random_below(12)].long_name);
    strcpy(shd_subst_values[3],
               shm_cities[(INT) c_random_below(16)].name);
    strcpy(shd_subst_values[4],
               shm_cities[(INT) c_random_below(16)].name);

    /* The five kinds of paragraph, each once in a random order, appended to an empty buffer. */
    done = 0;
    strcpy(shm_scratch, &dat_str_empty_15);
    do {
        n = c_random_below(5);
        if ((done & (1 << n)) == 0) {
            done |= 1 << n;
            /* Each a random phrasing of its tag: eight to pick from, twelve for the last. */
            switch (n) {
            case 0:
                c_say_one_of(dat_str_text_dta, dat_str_sloc00, 8);
                break;
            case 1:
                c_say_one_of(dat_str_text_dta_2, dat_str_rloc00, 8);
                break;
            case 2:
                c_say_one_of(dat_str_text_dta_3, dat_str_sorg00, 8);
                break;
            case 3:
                c_say_one_of(dat_str_text_dta_4, dat_str_rorg00, 8);
                break;
            case 4:
                c_say_one_of(dat_str_text_dta_5, dat_str_fluf00, 12);
                break;
            }
        }
    } while (done != 0x1f);

    /* Hand the blurb on through the shared block's 512-byte message. */
    for (i = 0; i < 512; i++)
        COMM()->message[i] = (shm_scratch)[i];
}

