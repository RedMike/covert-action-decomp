/* LIST-DRAW.C -- c_draw_display_list, drawing a list of lines and boxes.
 */

/* Draw the display list at `list`: 12-byte records ending at kind -1. Kind 0
 * is a line, 1 a filled box, 3 an outlined one, and 2 repeats the records
 * before it, shifted each time.
 */
INT c_draw_display_list(char *list)
{
    INT again;
    INT pos;
    INT v2l;   /* the running x offset the repeat accumulates */
    INT v3m;   /* and the y one */

    pos = v2l = v3m = 0;
    do {
        switch (*(INT *) (list + pos * 0xc)) {
        case 0:
            c_draw_line(*(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            break;
        case 1:
            c_fill_box(*(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            break;
        case 2:
            if (*(INT *) (list + pos * 0xc + 0xa) == 0) {
                v2l = v3m = 0;
                again = *(INT *) (list + pos * 0xc + 6);
                *(INT *) (list + pos * 0xc + 0xa) = 1;
            }
            again--;
            if (again != 0) {
                v2l += *(INT *) (list + pos * 0xc + 2);
                v3m += *(INT *) (list + pos * 0xc + 4);
                pos -= *(INT *) (list + pos * 0xc + 8) + 1;
            } else {
                *(INT *) (list + pos * 0xc + 0xa) = 0;
                v2l = v3m = 0;
            }
            break;
        case 3:
            c_draw_line(*(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            c_draw_line(*(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            c_draw_line(*(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 4) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
            c_draw_line(*(INT *) (list + pos * 0xc + 6) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 2) + v2l,
                            *(INT *) (list + pos * 0xc + 8) + v3m,
                            *(INT *) (list + pos * 0xc + 0xa));
        break;
        case -1:
        pos = -1;
        break;
        }
        pos++;
    } while (pos != 0);
}
