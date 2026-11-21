/* ANI_OPS.C -- the sequencer's byte-code interpreter.
 *
 * A stack machine over the far data's value stack: 14h yields until the next
 * frame, 02h waits out a countdown, and 15h ends the sequence, answering 1.
 * 06h's `(INT)` casts make its compare signed.
 */
#include "FINAL.H"
#include "ACTORS.H"

/* shared_include_start: ../../../../shared/c/SEQ-CODE.C -- generated */
/* SEQ-CODE.C -- c_seq_code, the animation script interpreter.
 */

INT c_seq_code(void)
{
    while (shm_seq_done == 0) {
        switch (shm_seq_wait) {
        case 0:
        shm_seq_op = *shm_seq_pc;
        if (shm_seq_op == 0) {
            if (shm_seq_data.stack[shm_seq_depth - 6] == -1)
                shm_seq_data.stack[shm_seq_depth - 6] = c_actor_take_slot();
            if (shm_seq_data.stack[shm_seq_depth - 6] > 0
                    && shm_seq_data.stack[shm_seq_depth - 6] <= 0x32)
                c_actor_set(shm_seq_data.stack[shm_seq_depth - 6],
                                shm_seq_data.stack[shm_seq_depth - 7],
                                shm_seq_data.stack[shm_seq_depth - 5],
                                shm_seq_data.stack[shm_seq_depth - 4],
                                shm_seq_data.stack[shm_seq_depth - 3],
                                shm_seq_data.stack[shm_seq_depth - 2],
                                shm_seq_data.stack[shm_seq_depth - 1]);
            shm_seq_depth -= 7;
            shm_seq_pc++;
        }
        if (shm_seq_op == 1) {
            if (shm_seq_data.stack[shm_seq_depth - 1] > 0
                    && shm_seq_data.stack[shm_seq_depth - 1] <= 0x32)
                shm_seq_data.actors[shm_seq_data.stack[shm_seq_depth - 1]
                                   - 1].in_use = 0;
            shm_seq_depth--;
            shm_seq_pc++;
        }
        if (shm_seq_op == 2) {
            shm_seq_depth--;
            shm_seq_operand = shm_seq_data.stack[shm_seq_depth];
            shm_seq_wait = 1;
            shm_seq_pc++;
        }
        if (shm_seq_op == 3) {
            shm_seq_depth--;
            shm_seq_data.queue[shm_seq_sound_queue_count++] =
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 4) {
            if (shm_seq_data.stack[shm_seq_depth - 1] > 0
                    && shm_seq_data.stack[shm_seq_depth - 1] <= 0x32)
                shm_seq_data.actors[shm_seq_data.stack[shm_seq_depth - 1]
                                   - 1].hidden = 1;
            shm_seq_depth--;
            shm_seq_pc++;
        }
        if (shm_seq_op == 5) {
            shm_seq_operand = *(INT FAR *) (shm_seq_pc + 2);
            if (shm_seq_pc[1] != 0)
                shm_seq_operand =
                    shm_seq_vars[shm_seq_operand];
            shm_seq_data.stack[shm_seq_depth++] = shm_seq_operand;
            shm_seq_pc += 4;
        }
        if (shm_seq_op == 6) {
            shm_seq_depth--;
            shm_seq_operand = *(INT FAR *) (shm_seq_pc + 1);
            if (shm_seq_operand >= 0
                    && shm_seq_operand < 0x33)
                shm_seq_vars[shm_seq_operand] =
                    shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc += 3;
        }
        if (shm_seq_op == 7) {
            shm_seq_depth++;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 2];
            shm_seq_pc++;
        }
        if (shm_seq_op == 8) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                == shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 9) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                != shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 10) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                > shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 11) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                < shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 12) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                >= shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 13) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] =
                shm_seq_data.stack[shm_seq_depth - 1]
                <= shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 14) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] +=
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 15) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] -=
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 0x10) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] *=
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 0x11) {
            shm_seq_depth--;
            shm_seq_data.stack[shm_seq_depth - 1] /=
                shm_seq_data.stack[shm_seq_depth];
            shm_seq_pc++;
        }
        if (shm_seq_op == 0x12) {
            shm_seq_depth--;
            if (shm_seq_data.stack[shm_seq_depth] == 0)
                shm_seq_pc += 3;
            else
                SET_POINTER_WITHIN(shm_seq_pc, *(INT FAR *) (shm_seq_pc + 1));
        }
        if (shm_seq_op == 0x13)
            SET_POINTER_WITHIN(shm_seq_pc, *(INT FAR *) (shm_seq_pc + 1));
        if (shm_seq_op == 0x14)
            return 0;
        if (shm_seq_op == 0x15)
            shm_seq_done = 1;
        if (shm_seq_op == 0x17) {
            shm_seq_data.stack[shm_seq_depth++] =
                GET_POINTER_WITHIN(shm_seq_pc) + 3;
            SET_POINTER_WITHIN(shm_seq_pc, *(INT FAR *) (shm_seq_pc + 1));
        }
        if (shm_seq_op == 0x16) {
            shm_seq_depth--;
            SET_POINTER_WITHIN(shm_seq_pc, shm_seq_data.stack[shm_seq_depth]);
        }
            break;
        case 1:
            if (shm_seq_operand-- != 0)
                return 0;
            shm_seq_wait = 0;
            break;
        }
    }
    return 1;
}
/* shared_include_end: ../../../../shared/c/SEQ-CODE.C */
