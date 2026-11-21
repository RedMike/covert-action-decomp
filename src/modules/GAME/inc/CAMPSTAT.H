/* CAMPSTAT.H -- the values of asm_campaign_state: the handover GAME last made,
 * named in NEXTMOD.H since it is the next_module GAME handed over, or one of
 * the two of GAME's own, prefixed NONE_.
 */
#ifndef CAMPSTAT_H
#define CAMPSTAT_H

#include "NEXTMOD.H"

#define NONE_NOTHING_PENDING 0      /* nothing to deal with on the way back */
#define NONE_CAMPAIGN_START 0x63    /* a campaign just begun */

#endif
