/* EVIDENCE-UNLOCK.C -- c_evidence_unlock, adding evidence about a suspect.
 */

/* Add evidence `bits` about the suspect of `org` in `city`, making a record if
 * there is none, and answer it or -1; with `show` the new fields are reported.
 */
INT c_evidence_unlock(INT org, INT city, INT bits, LONG show)
{
    INT slot;
    INT keep;
    INT step;
    INT held;

    for (slot = 0; slot < shm_suspect_count; slot++)
        if (shm_suspects[slot].org == org
            && shm_suspects[slot].city == city) {
            held = shm_suspects[slot].flags;
            if ((shm_suspects[slot].flags |= bits)
                != 0) {
tell:
                if ((INT) show != 0)
                    c_report_new_fields(slot, held);
                return slot;
            }
            return -1;
        }
    do
        slot = c_random_below(0x3f) + 1;
    while (shm_suspects[slot].visuals != 0);
    if (org == shm_campaign.mastermind_org && city == shm_campaign.mastermind_city) {
        slot = 0;
        bits |= shm_campaign.mastermind_flags;
    }
    if (bits == 0)
        return -1;
    held = shm_suspects[slot].flags;
    shm_suspects[slot].org = org;
    shm_suspects[slot].city = city;
    shm_suspects[slot].flags = bits;
    shm_suspects[slot].role = 0;
    shm_suspects[slot].role_known = 0;
    do {
        keep = 1;
        shm_suspects[slot].visuals =
            c_random_below(0x7fff);
        for (step = 0; step < shm_suspect_count; step++)
            /* `==` binds before `&`: only a face of 3fh counts, as shipped. */
            if ((shm_suspects[slot].visuals
                 & (0x3f == shm_suspects[step].visuals)
                 & 0x3f)
                && slot != step)
                keep = 0;
    } while (keep == 0);
    goto tell;
}
