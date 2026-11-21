/* SEQ-PICTURE.C -- c_seq_set_picture, choosing a sequence's picture.
 */

/* Set the sequence's current picture to `entry`. */
INT c_seq_set_picture(INT entry)
{
    shm_seq_picture = entry;
}
