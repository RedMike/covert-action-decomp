/* UNTAP.C -- taking a crime object out of play once it has been found.
 */
#include "GAME.H"
#include "BLOCK.H"
#include "PRISONER.H"
#include "LOGKINDS.H"

/* Take crime `object` out of play: set every event sharing a message with
 * the role that obtained it back to not yet happened, then log the loss and
 * free the object's slot. */
INT c_remove_crime_object(INT object)
{
    INT v0j;    /* the crime role that obtained the object */
    INT v1l;    /* the crime event that message records */
    INT v2n;    /* the message being walked */
    INT v3;     /* the event being set back */
    INT v4b;    /* the object's own bit */

    /* Through the intercepted traffic, find the role that was handed the object. */
    v4b = 1 << object;
    v0j = -1;
    for (v2n = 0; v2n < shm_log_count; v2n++)
        if (shm_log[v2n].kind == LOG_MESSAGE) {
            v1l = shm_log[v2n].slot;
            if ((shm_crime_events[v1l].objects & v4b) != 0)
                v0j = (char) shm_crime_events[v1l].main_participant;
            /* Only that role's traffic, from the hand-over on, is undone. */
            if (v0j == -1)
                continue;
            if ((char) shm_crime_events[v1l].main_participant != v0j)
                continue;
            /* Every event carrying the same message has to happen again. */
            for (v3 = 0; v3 < shm_crime_event_count; v3++)
                if (shm_crime_events[v1l].message_id
                    == shm_crime_events[v3].message_id)
                    shm_crime_events[v3].happen_tick = 999;
        }
    /* Record the loss in the case log, and free the object's record. */
    c_log_add(LOG_OBJECT_REMOVED, object);
    shm_crime_block[object].u2 = -1;
}
