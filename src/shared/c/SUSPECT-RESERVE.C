/* SUSPECT-RESERVE.C -- c_suspect_reserve, finding or making a suspect record.
 */

/* Find the suspect record for `org` in `city` and OR `bits` into its roles, or
 * with nonzero `bits` make one; answer the record, or -1. The mastermind takes
 * slot 0.
 */
INT c_suspect_reserve(INT org, INT city, INT bits)
{
    INT cell;   /* the record being looked at, then the one chosen */

    for (cell = 0; cell < shm_suspect_count; cell++) {
        if (shm_suspects[cell].org == org
            && shm_suspects[cell].city
                   == city) {
            shm_suspects[cell].role |= bits;
            return cell;
        }
    }
    do {
        cell = c_random_below(0x40);
    } while (shm_suspects[cell].visuals != 0
             || cell == 0);
    if (org == shm_campaign.mastermind_org && city == shm_campaign.mastermind_city)
        cell = 0;
    if (bits != 0) {
        shm_suspects[cell].org = org;
        shm_suspects[cell].city = city;
        shm_suspects[cell].flags =
            cell != 0 ? 0 : shm_campaign.mastermind_flags;
        shm_suspects[cell].role = bits;
        shm_suspects[cell].role_known = 0;
        shm_suspects[cell].score = 0;
        if (cell != 0) {
            shm_suspects[cell].visuals =
                c_random_below(0x7ffe) + 1;
            if (c_random_below(3) == 0)
                shm_suspects[cell].visuals |= 1;
        } else {
            shm_suspects[cell].visuals =
                shm_campaign.mastermind_visuals;
        }
        shm_suspects[cell].alert_level = 0;
        return cell;
    }
    return -1;
}
