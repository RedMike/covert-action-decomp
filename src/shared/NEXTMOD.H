/* NEXTMOD.H -- names for COMM_BLOCK's `next_module`: what COVERT runs next.
 *
 * Each value is an index into COVERT's module table, prefixed with the module
 * it runs. `next_module` stays a byte and the names an anonymous enum, because
 * an enum type is two bytes under MSC 5.1 but four on a modern compiler.
 */
#ifndef NEXTMOD_H
#define NEXTMOD_H

enum {
    GAME_CAMPAIGN = 0x0,        /* back to the campaign */
    TAC_BREAK_IN = 0x1,         /* breaking into a building */
    CODE_MESSAGE_DECODE = 0x2,  /* deciphering a message at the CIA */
    CHASE_SUSPECT = 0x3,        /* tailing a suspect from a stakeout */
    BUG_WIRETAP = 0x4,          /* tapping a building's line */
    CHASE_UNUSED = 0x5,         /* a chase of its own kind nothing hands over to */
    CHASE_AMBUSHED = 0x6,       /* followed out of a building */
    TAC_CAPTURE_ESCAPE = 0x7,   /* escaping after capture */
    TAC_JAILBREAK = 0x8,        /* agents freeing the prisoner */
    FINAL_CAMPAIGN_OVER = 0x9,  /* the campaign has ended */
    TAC_FIGHT_AMBUSHED = 0xa,   /* set upon in the city */
    FINAL_TITLE = 0xb,          /* the session starting: title and main menu */
    BUG_CAR_TRACER = 0xc,       /* a car tracer from a stakeout */
    TAC_PRACTICE = 0xd,         /* practising combat */
    CHASE_PRACTICE = 0xe,       /* practising driving */
    CODE_PRACTICE = 0xf,        /* practising cryptography */
    BUG_PRACTICE = 0x10,        /* practising electronics */
    FINAL_PRACTICE_OVER = 0x11, /* back from practice */
    CODEVIEW_DEBUG = 0x63,      /* 'c': a module under CodeView; nothing sets it */
    NONE_EXIT = 0xff            /* nothing runs next: the session ends */
};

#endif /* NEXTMOD_H */
