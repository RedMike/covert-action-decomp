/* DECODE.C -- decoding an intercepted message and showing it.
 *
 * `v6j` and `v11d` are never used.
 */
#include "GAME.H"
#include "RANDOM.H"
#include "MISC1.H"
#include "DECODE.H"
#include "CASE.H"
#include "LINES.H"
#include "MESSAGE.H"
#include "TAG.H"
#include "SUSPFLAG.H"
#include "CRIMEVNT.H"

/* Decode one intercepted message: fill in what the two ends now know about
 * each other, then put the message on screen. */
INT c_decode_message(INT nth)
{
    INT v0j;    /* the crime role at the message's far end */
    INT v1j;    /* set when the two ends were swapped, and never read */
    INT v2j;    /* the crime event the message is */
    INT v3j;    /* the sender */
    INT v4j;    /* the swap's spare */
    INT v5j;    /* the message being scanned */
    INT v6j;    /* never used */
    INT v7k;    /* how many bits this pass adds */
    INT v8k;    /* what the bits were before the pass */
    INT v9k;    /* the other message on the same wire */
    INT v10d;   /* the recipient */
    INT v11d;   /* never used */

    /* A printout headed "Message Decode". */
    c_draw_paper();
    c_write_text_trimmed(dat_str_message_decode, 120, 18, 5);
    /* The event the message is, the role at its far end, and who sent it to whom. */
    v2j = shm_log[nth].slot;
    v0j = shm_crime_events[v2j].flags & CRIME_FAR_BYTE;
    v3j = shm_log[nth].from;
    v10d = shm_log[nth].to;
    if (v2j >= 0) {
        /* Logged from the receiving side, the two ends are turned round to read sender first. */
        v1j = 0;
        if ((shm_crime_events[v2j].flags & CRIME_KIND)
            == (CRIME_MESSAGE | CRIME_RECEIVED)) {
            v4j = v3j;
            v3j = v10d;
            v10d = v4j;
            v1j = 1;
        }
        /* Both halves of the exchange, logged the same minute: */
        for (v5j = 0; v5j < shm_log_count; v5j++) {
            if (shm_log[nth].minute != shm_log[v5j].minute)
                continue;
            /* each yields up to two new facts, one at difficulty 1 and none above, */
            for (v7k = 0; v7k < 2 - shm_difficulty; v7k++) {
                v8k = shm_log[v5j].known;
                do
                    shm_log[v5j].known |= 1 << c_random_below(4);
                while (shm_log[v5j].known == v8k
                       && (v8k & 0xe) != 0xe);
            }
            /* and at least the name at its other end. */
            if ((shm_log[v5j].known & 0xe) == 0)
                shm_log[v5j].known |= 2;
            if (v5j != nth)
                v9k = v5j;
        }
        /* Each sender's record gains the facts the other half of the exchange revealed. */
        shm_suspects[shm_log[nth].from].flags |= shm_log[v9k].known & 0xe;
        shm_suspects[shm_log[v9k].from].flags |= shm_log[nth].known & 0xe;
        /* Both ends' parts in the plot are now known. */
        shm_suspects[shm_log[nth].from].role_known
            |= 1 << shm_crime_events[v2j].main_participant;
        shm_suspects[shm_log[nth].to].role_known |= 1 << v0j;
        /* And each half shows whatever was already known of the other end. */
        shm_log[nth].known |= shm_suspects[shm_log[v9k].from].flags
                              & (SUSPECT_NAME | SUSPECT_ORG | SUSPECT_CITY);
        shm_log[v9k].known |= shm_suspects[shm_log[nth].from].flags
                              & (SUSPECT_NAME | SUSPECT_ORG | SUSPECT_CITY);
    } else {
        /* A message that is no crime event gives away every real role of both ends. */
        shm_suspects[v3j].role_known |= shm_suspects[v3j].role & 0x7fff;
        shm_suspects[v10d].role_known |= shm_suspects[v10d].role & 0x7fff;
        v9k = nth;
    }
    /* FROM: and TO:, each with the dossier of an end the player knows anything of. */
    c_write_text_trimmed(dat_str_from, 32, 48, 5);
    c_write_text_trimmed(dat_str_to_heading, 160, 48, 5);
    if (shm_suspects[v3j].flags != 0)
        c_dossier(v3j, 32, 56);
    if (shm_suspects[v10d].flags != 0)
        c_dossier(v10d, 160, 56);
    /* MESSAGE: and its text, until the player has read it. */
    c_write_text_trimmed(dat_str_message, 32, 119, 5);
    shm_scratch[0] = 0;
    c_say_event_text(v2j);
    c_draw_message(30, 32, 127, 0);
    shm_pan_width = 320;
    c_wait_key();
    /* Both halves are now decoded and spent. */
    shm_log[nth].known |= 0x8000;
    shm_log[v9k].known |= 0x8000;
}
