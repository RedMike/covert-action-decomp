/* PROSE.C -- a block of prose from prose.dta, filled in and wrapped.
 */
#include "GAME.H"
#include "PROSE.H"
#include "BLOCK.H"
#include "PRISONER.H"
#include "WRAP.H"

/* Append a block of prose to shm_scratch: a name ending in `0` is numbered by
 * `num` first, then the block is read out of prose.dta, its keys filled in and
 * the text wrapped to `wait` characters. */
INT c_show_prose(char *name, INT wait, char *repl, INT num)
{
    INT v0j;    /* how long the name is */

    /* One of a numbered set of blocks: pick the variant. */
    v0j = strlen(name);
    if (*(v0j + name - 1) == '0')
        *(v0j + name - 1) += num;
    /* The block itself, with the first message key filled in. */
    c_say_block_with(dat_str_prose_dta, name, shd_subst_keys,
                    shd_subst_values, 1);
    /* $RPLC the caller's word, $NAME always Max Remington, $CITY and $ORG here, $US the CIA. */
    c_replace(dat_msg_rplc, repl);
    c_replace(dat_msg_name, dat_str_max_remington);
    c_replace(dat_msg_city, shm_cities[shm_case_city].name);
    c_replace(dat_msg_org, shm_orgs[(INT) shm_case_org].long_name);
    c_replace(dat_key_us, shm_orgs[1].long_name);
    /* Wrapped for the screen it goes on. */
    c_wrap_message(wait);
}
