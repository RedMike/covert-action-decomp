/* CASE-LOG.C -- appending one record to the case log.
 */
#include "FINAL.H"
#include "CMISEND.H"
#include "LOGKINDS.H"
#include "CRIMEVNT.H"

/* shared_include_start: ../../../../shared/c/LOG-ADD.C -- generated */
/* LOG-ADD.C -- c_log_add, adding a record to the case log.
 */

/* Add a record of `kind` about `slot` to the case log at the current minute; a
 * message also records its sender and recipient. Records past the 128th still
 * write past the end.
 */
INT c_log_add(INT kind, INT slot)
{
    INT sender;
    INT to;
    INT row;

    shm_log[shm_log_count].minute = shm_clock_minutes;
    shm_log[shm_log_count].kind = kind;
    shm_log[shm_log_count].slot = slot;
    shm_log[shm_log_count].known = 0;
    shm_log[shm_log_count].from = 0xff;
    shm_log[shm_log_count].status = 0;
    DEBUG_MESSAGE4("c_log_add: [%d] kind=%d (%s) minute=%d",
                   shm_log_count,
                   shm_log[shm_log_count].kind,
                   LOG_KIND_NAME(shm_log[shm_log_count].kind),
                   shm_log[shm_log_count].minute);
    DEBUG_MESSAGE3("  slot=%d known=%x status=%d",
                   shm_log[shm_log_count].slot,
                   shm_log[shm_log_count].known,
                   shm_log[shm_log_count].status);
    if (kind == LOG_MESSAGE) {
        sender = shm_crime_roles[shm_crime_events[slot].main_participant].suspect;
        shm_log[shm_log_count].from = sender;
        row = sender * 16;
        shm_log[shm_log_count].from_city = shm_suspects[sender].city;
        shm_log[shm_log_count].status = shm_suspects[sender].alert_level;
        if (shm_crime_events[slot].flags & CRIME_IN_USE) {
            to = shm_crime_roles[CRIME_FAR_CELL(shm_crime_events[slot])].suspect;
            shm_log[shm_log_count].to = to;
            shm_log[shm_log_count].to_city = shm_suspects[to].city;
        }
        DEBUG_MESSAGE3("  from=%d from_city=%d (%s)",
                       shm_log[shm_log_count].from,
                       shm_log[shm_log_count].from_city,
                       shm_cities[shm_log[shm_log_count].from_city].name);
        DEBUG_MESSAGE3("  to=%d to_city=%d (%s)",
                       shm_log[shm_log_count].to,
                       shm_log[shm_log_count].to_city,
                       shm_cities[shm_log[shm_log_count].to_city].name);
    }
    shm_log_count++;
    if (shm_log_count >= 128) {
        strcpy(shm_scratch, shd_str_nsyn_overflow);
        c_ask_menu((rt_addr) shm_scratch, 0x32, 0x32);
    }
}
/* shared_include_end: ../../../../shared/c/LOG-ADD.C */
