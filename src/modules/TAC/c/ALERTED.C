/* ALERTED.C -- how alert a guard is.
 */
#include "TAC.H"
#include "ALERTED.H"

/* How hard a guard is looking: nothing, watchful, or on the alert -- and -1
 * for one the mission has no room for, which is counted and dropped. The
 * unsigned `>= 0` test and the once-through `do` are as shipped. */
INT c_guard_alertness(INT guard)
{
    /* In a jailbreak every guard is watchful. */
    if (asm_mission_kind == 2)
        return 1;
    /* A guard past the slots this building fields, unless stunned, is dropped back into the count still to come. */
    if ((asm_high_security != 0 ? 5 : 3) + shm_difficulty * 2 < guard
        && (UNSIGNED_INT) (guard * 28) >= 0
        && asm_people[guard].stun == 0) {
        asm_guards_to_come++;
        return -1;
    }
    do {
        /* With an alarm on a room, the first three guards keep to their rounds and the rest are watchful. */
        if (asm_guard_alert != 0 && asm_target_room > 0) {
            if (guard < 3)
                break;
            return 1;
        }
        /* The first few keep to their rounds, more of them the more alert the organisation is. */
        if (asm_org_alert_level / 25 + 3 > guard)
            break;
        /* The next two are watchful. */
        if (asm_org_alert_level / 25 + 5 > guard)
            return 1;
        /* At night, unless asm_high_security is set, the rest are on the alert. */
        if (asm_night != 0 && asm_high_security == 0)
            return 2;
    } while (0);
    return 0;
}
