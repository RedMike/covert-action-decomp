/* ACTORS.H -- the actors a sequence puts on screen, and their far data.
 */
#ifndef ACTORS_H
#define ACTORS_H

/* One animated thing on screen: where it is, what it is drawn as, and the
 * byte-code that moves it. 52 bytes, fifty of them in the far data.
 */
struct ACTOR {
    INT in_use;             /* non-zero while the slot is taken */
    INT hidden;             /* set to keep it off this frame */
    INT parent;             /* slot it hangs off, less one; -2 is none */
    INT home_x;             /* offset from the parent, or the position */
    INT home_y;
    INT x;                  /* where it is now, relative to the parent */
    INT y;
    INT rate;               /* what `speed` is put back to on a reset */
    INT speed;              /* added to `credit` on every call */
    INT credit;             /* a step happens each time it passes 255 */
    INT loops[10];          /* the byte-code's loop counters */
    INT depth;              /* how many of them are in use */
    INT script;             /* offset the byte-code starts at */
    INT overlay;            /* chooses which of the two draws is used */
    char FAR *pc;           /* where in the byte-code it has reached */
    unsigned char frame;    /* the picture to draw, 0ffh for none */
    unsigned char pad;
};

/* The whole far data segment: the sequencer's value stack, the queue of sound
 * commands still to play, then the actors.
 */
struct SEQ {
    INT stack[1000];
    UNSIGNED_INT queue[30];
    struct ACTOR actors[50];
};

INT c_actor_take_slot(void);
void c_actor_set(INT slot, INT script, INT parent, INT home_x, INT home_y,
                     INT rate, INT overlay);
void c_actor_clear_all(void);
void c_actor_clear_hidden(void);
void c_actor_draw(INT slot);
void c_actor_draw_all(void);
void c_actor_draw_hidden(void);
void c_actor_where(INT slot, INT *x, INT *y);
void c_actor_step(INT slot);
void c_actor_step_all(void);
INT c_seq_code(void);
INT c_seq_drain_queue(void);
void c_seq_reset(void);

#endif
