/* ORGPLAN.C -- raising the suspects' alert after the player acts somewhere.
 */
#include "GAME.H"
#include "LINES.H"
#include "ORGPLAN.H"

/* Raise the global alert level by half of `alert`, and the alert level of
 * every suspect in play by `alert` at organisation `who` in city `where`, the
 * more the nearer the suspect's own organisation and city are to them. */
INT c_raise_alert(INT who, INT where, INT alert)
{
    INT v0j;    /* the suspect being stepped */
    INT v1k;    /* never used */
    INT v2l;    /* how far its organisation is from `who` */
    INT v3m;    /* what it gains this time */
    INT v4n;    /* how far its city is */
    INT v5o;    /* its organisation */
    INT v6;     /* its city */
    INT v7a;    /* how long a step costs it */

    /* Nothing the player did was noticed. */
    if (alert <= 0)
        return;
    /* Every organisation hears of it a little. */
    shm_global_alert_level += alert / 2;
    /* Only suspects who exist and are still at large grow wary. */
    for (v0j = 0; v0j < shm_suspect_count; v0j++) {
        if (shm_suspects[v0j].visuals == 0
            || shm_suspects[v0j].alert_level < 0)
            continue;
        /* How far the suspect's organisation and city are from where it happened. */
        v5o = shm_suspects[v0j].org;
        v6 = shm_suspects[v0j].city;
        v2l = c_packed_distance(
                  shm_orgs[who].where,
                  shm_orgs[v5o].where);
        v4n = c_packed_distance(
                  shm_cities[where].where,
                  shm_cities[v6].where);
        /* The gain falls with both distances and grows with the size of the alert. */
        v7a = (LONG) ((v2l + 4) * (v4n + 2)) * 256 / (alert + 1);
        v3m = 2500 / v7a;
        shm_suspects[v0j].alert_level += v3m;
    }
}
