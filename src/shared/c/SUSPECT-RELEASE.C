/* SUSPECT-RELEASE.C -- c_suspect_release, freeing a suspect record nothing holds.
 */

/* Free suspect record `slot` unless a crime role still holds it: a face of
 * zero marks it free.
 */
void c_suspect_release(INT slot)
{
    if (shm_suspects[slot].role & 0x7fff)
        goto held;
    shm_suspects[slot].visuals = 0;
    shm_suspects[slot].org = -1;
    shm_suspects[slot].city = -1;
    shm_suspects[slot].flags = 0;
held:
    ;
}
