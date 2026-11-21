/* ANIM-READ.C -- c_anim_read, reading bytes from an animation file.
 */

/* Read `size` * `count` bytes into `dest`, a byte at a time. */
INT c_anim_read(char *dest, INT size, INT count)
{
    size = count * size;
    while (size-- != 0)
        *dest++ = (char) c_anim_byte();
}
