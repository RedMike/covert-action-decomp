/* CRIMEVNT.H -- names for the bits of a CRIME_EVENT's `flags` and `objects`,
 * each one word as the tests mask them.
 */
#ifndef CRIMEVNT_H
#define CRIMEVNT_H

/* `flags`, high byte: what kind of event this is. A kind and its receiving
 * side are two names ORed together; CRIME_KIND masks the nibble compared.
 */
#define CRIME_RECEIVED      0x100   /* the receiving side of an event */
#define CRIME_MESSAGE       0x200   /* a coded message */
#define CRIME_PACKAGE       0x400   /* an object handed over */
#define CRIME_MEETING       0x800   /* meeting notes */
#define CRIME_UNKNOWN_10    0x1000  /* purpose unknown */
#define CRIME_BULLETIN      0x2000  /* the event reads as a news bulletin */
#define CRIME_REVEALED      0x8000  /* set on every event by c_reveal_case at the end of the case */

#define CRIME_KIND          0xf00   /* the kind nibble alone */
#define CRIME_IN_USE        0xfff   /* both halves: the event carries anything */

/* `flags`, low byte: the participant grid cell at the far end of the event, in
 * each form the shipped code reads it. CRIME_FAR_CELL zero-extends the byte to
 * an INT.
 */
#define CRIME_FAR_NIBBLE    0xf
#define CRIME_FAR_BYTE      0xff
#define CRIME_FAR_CELL(ev)      ((INT) *(unsigned char *) &(ev).flags)
#define CRIME_FAR_CELL_CHAR(ev) (*(char *) &(ev).flags)

/* `objects`: the low byte is what the event hands over and the high byte what
 * it destroys, one bit per object.
 */
#define CRIME_OBJECT_ADDED(n)     (1 << (n))
#define CRIME_OBJECT_DESTROYED(n) (0x100 << (n))

/* Print the crime event list field by field for a debugging session, flagging
 * a cell outside 0..cells-1 other than the -1 terminator.
 */
#ifdef PORT_MODERN
#include "STRUCTS.H"

#if PORT_DEBUG
static void port_dump_crime_events(const char *where,
                                   struct CRIME_EVENT *events,
                                   INT count, INT cells) __attribute__((unused));

static void port_dump_crime_events(const char *where,
                                   struct CRIME_EVENT *events,
                                   INT count, INT cells)
{
    INT i, cell, far_cell;

    DEBUG_MESSAGE3("%s: %d crime event(s) over %d grid cell(s)",
                   where, (int) count, (int) cells);
    if (count < 0 || count > 64) {
        DEBUG_MESSAGE1("  count %d is outside 0..64; not walking the list",
                       (int) count);
        return;
    }
    for (i = 0; i < count; i++) {
        cell = events[i].main_participant;
        far_cell = CRIME_FAR_CELL(events[i]);
        DEBUG_MESSAGE4("  [%2d] cell %-4d pad %02x  tick %d",
                       (int) i, (int) cell,
                       (unsigned) events[i].field_1,
                       (int) events[i].happen_tick);
        DEBUG_MESSAGE4("       msg %-5d flags %04x (far %d kind %03x)",
                       (int) events[i].message_id,
                       (unsigned) (events[i].flags & 0xffff),
                       (int) far_cell,
                       (unsigned) (events[i].flags & CRIME_KIND));
        DEBUG_MESSAGE3("       objects %04x  score %d  text \"%.32s\"",
                       (unsigned) (events[i].objects & 0xffff),
                       (int) events[i].score, events[i].description);
        if (cell != -1 && (cell < 0 || cell >= cells))
            DEBUG_MESSAGE2("       *** cell %d is outside 0..%d",
                           (int) cell, (int) cells - 1);
        if ((events[i].flags & CRIME_IN_USE) && far_cell >= cells)
            DEBUG_MESSAGE2("       *** far cell %d is outside 0..%d",
                           (int) far_cell, (int) cells - 1);
    }
}

#define CRIME_EVENT_DUMP(where, events, count, cells) \
    port_dump_crime_events((where), (events), (count), (cells))
#else
#define CRIME_EVENT_DUMP(where, events, count, cells) ((void) 0)
#endif

#else
#define CRIME_EVENT_DUMP(where, events, count, cells) ((void) 0)
#endif

#endif /* CRIMEVNT_H */
