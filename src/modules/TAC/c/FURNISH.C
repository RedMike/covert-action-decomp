/* FURNISH.C -- furnishing a room, and the recolouring the mod options add.
 */
#include "TAC.H"
#include "FLOOROBJ.H"
#include "MODOPTS.H"
#include "RANDOM.H"
#include "WALLCELL.H"

/* Give one room a use and fill it: pick a kind that fits its size and the
 * building, then drop one piece of furniture at a time on free cells until the
 * room has as many as it takes. */
INT c_furnish_room(INT room)
{
    INT v0j;    /* how many cells have been tried */
    INT v1j;    /* what the room is for */
    INT v2j;    /* which size band it falls in */
    INT v3j;    /* the cell being tried, across */
    INT v4j;    /* and down */
    INT v5j;    /* how many pieces are in */
    INT v6j;    /* the name's twelfth byte, put back after it is copied */
    INT v7j;    /* whether the cell has room around it */
    INT v8j;    /* which way round is being looked at */
    INT v9j;    /* which piece of furniture */
    INT v10c;   /* never read */
    INT v11c;   /* how big the room is */
    INT v12c;   /* how far into the room the cell is, across */
    INT v13c;   /* and down */
    INT v14c;   /* which way the piece faces */

    /* A scrapped room stays empty. */
    if ((asm_rooms[room].flags & 1) != 0)
        return;
    /* Small, middling or large, by floor area. */
    v11c = asm_rooms[room].width
        * asm_rooms[room].height;
    v2j = 1;
    if (v11c > 40)
        v2j = 2;
    if (v11c > 72)
        v2j = 4;
    /* Pick a kind of room made for this size and allowed in this building,
     * each on a coin toss in turn, until one is taken. */
    v1j = -1;
    do {
        for (v5j = 0; v5j < 10; v5j++)
            if ((dat_room_kinds[v5j].field_12
                 & v2j) != 0
                && ((dat_room_kinds[v5j].field_14 & dat_room_mask) != 0
#ifdef TAC_UNIMPLEMENTED_ROOMS
                    /* the Bed Room and the Kitchen, the two kinds with 0 here */
                    || MOD_ON(unimplemented_rooms)
#endif
                    )
#ifdef TAC_UNIMPLEMENTED_ROOMS
                /* 40% a kind rather than half, so the kinds after the first
                 * few, the Kitchen among them, come up more often */
                && (MOD_ON(unimplemented_rooms) ? c_random_below(5) < 2
                                                : c_random_below(2) != 0)
#else
                && c_random_below(2) != 0
#endif
                ) {
                v1j = v5j;
                break;
            }
    } while (v1j == -1);
    /* In an ambush every room is an Office. */
    if (asm_mission_kind == 3)
        v1j = 0;
    asm_rooms[room].kind = v1j;
    /* A piece for every six cells of floor. */
    for (v5j = 0; v11c / 6 > v5j; v5j++) {
        /* Up to 99 random cells of the room for each. */
        v0j = 0;
        do {
            v3j = c_random_below(asm_rooms[room].width)
                + asm_rooms[room].left;
            v4j = c_random_below(asm_rooms[room].height)
                + asm_rooms[room].top;
            v9j = -1;
            /* An empty cell takes a free-standing piece. */
            if (asm_floor_map[(v3j << 5) + v4j] == -1) {
                /* Only with nothing numbered above 4 on any side, which keeps
                 * it from beside doors and other pieces. */
                v7j = 1;
                for (v8j = 0; v8j < 4; v8j++)
                    if (asm_floor_map[((dat_side_dx[v8j] + v3j) << 5)
                        + dat_side_dy[v8j] + v4j] > 4)
                        v7j = 0;
                if (v7j != 0) {
                    /* Its facing, from where in the room the cell lies. */
                    v12c = v3j - asm_rooms[room].left;
                    v13c = v4j - asm_rooms[room].top;
                    if (v12c > v13c)
                        v14c = asm_rooms[room].width / 2 < v12c ? 1 : 3;
                    else
                        v14c = asm_rooms[room].height / 2 < v13c ? 2 : 0;
                    /* Any piece made in that facing, but not a wall-mounted
                     * one. */
                    do
                        v9j = (c_random_below(16) << 2) + v14c + 12;
                    while (v9j >= 61);
                    if ((dat_floor_objects[v9j].flags & FOBJ_WALL_MOUNTED) != 0)
                        v9j = -1;
                }
            /* A wall cell takes a wall-mounted piece, in the wall's facing. */
            } else if (asm_floor_map[(v3j << 5) + v4j]
                       < 4) {
                do
                    v9j = ((c_random_below(16) << 2)
                           + (asm_floor_map[(v3j << 5) + v4j] & 3)) + 12;
                while (v9j >= 61);
                if ((dat_floor_objects[v9j].flags & FOBJ_WALL_MOUNTED) == 0)
                    v9j = -1;
            }
            /* Keep it only if it belongs in this kind of room. */
            if (v9j != -1
                && ((dat_floor_objects[v9j].field_12 & 1 << v1j) != 0
#ifdef TAC_UNIMPLEMENTED_ROOMS
                    /* the Television facing 3, which names no kind, in a Bed Room */
                    || (MOD_ON(unimplemented_rooms) && v9j == 55 && v1j == 6)
#endif
                    ))
                break;
        } while (++v0j < 99);
        /* Put it down; a two-cell piece puts its other half in the next
         * column, whatever is there. */
        if (v0j < 99) {
            asm_floor_map[(v3j << 5) + v4j] = v9j;
            if ((dat_floor_objects[v9j].flags & FOBJ_TWO_CELL)
                != 0) {
                if ((v9j & 1) != 0)
                    asm_floor_map[(v3j << 5) + v4j - 32] =
                        v9j - 1;
                else
                    asm_floor_map[(v3j << 5) + v4j + 32] =
                        v9j + 1;
            }
        }
    }
    /* The rest is for the payload room alone. */
    if (room != asm_payload_room)
        return;
    /* It holds something only with a suspect here and not on an escape
     * from capture, or in a jailbreak. */
    if ((asm_suspect_here == -1 || asm_mission_kind == 1)
        && asm_mission_kind != 2)
        return;
    /* A crime record tied to the suspect puts its item in the middle of the
     * room, picture and name, and sets asm_high_security. */
    for (v5j = 0; v5j < 4; v5j++)
        if (shm_crime_block[v5j].u2
            == asm_suspect_here
            && asm_suspect_here != -1) {
            asm_floor_map[((asm_rooms[room].width / 2
                + asm_rooms[room].left) << 5) + asm_rooms[room].height / 2 + asm_rooms[room].top] = 60;
            dat_floor_objects[60].sprite_x += shm_crime_block[v5j].u1 << 4;
            /* The record's name, cut to the eleven characters the item's
             * name holds, and then made whole again. */
            v6j = (char) shm_crime_block[v5j].name[11];
            shm_crime_block[v5j].name[11] = 0;
            strcpy(dat_floor_objects[60].name, shm_crime_block[v5j].name);
            shm_crime_block[v5j].name[11] = v6j;
            asm_high_security = 1;
        }
    /* The Local Agent stands just above the middle, the picture picked by
     * the suspect's gender bit. */
    asm_floor_map[((asm_rooms[room].width / 2 + asm_rooms[room].left) << 5)
        + asm_rooms[room].height / 2 + asm_rooms[room].top - 1] = 61;
    if ((shm_suspects[asm_suspect_here].visuals & 1) == 0)
        dat_floor_objects[61].sprite_x += 16;
}

#ifdef TAC_UNIMPLEMENTED_ROOMS
/* Drawers, whose own pictures are the crime's payload row, borrow the Files
 * facing the same way while the option is on. */
INT c_fobj_sprite(INT obj)
{
    /* The two Drawers, 57 and 59, take Files 25 and 27. */
    if (MOD_ON(unimplemented_rooms) && (obj == 57 || obj == 59))
        return obj - 32;
    return obj;
}

/* What a borrowed picture's colours become, a pair a fill. */
static char fobj_tints[] = {
    14, 6,      /* yellow to brown */
    3, 4,       /* teal to red */
    11, 4,      /* cyan to red */
    15, 6,      /* white to brown */
    7, 6,       /* light grey to brown */
};
#endif

#ifdef TAC_ROOM_RECOLOUR
/* A Bed Room's floor, walls, doors and furniture, dark grey first so the
 * light blue that becomes it stays. */
static char fobj_bed_room_tints[] = {
    8, 6,       /* dark grey to brown */
    9, 8,       /* light blue to dark grey */
    10, 5,      /* light green to 5, black in TAC's palette */
};

/* The Bed, before the room's so its light green goes to cyan, not black. */
static char fobj_bed_tints[] = {
    10, 11,     /* light green to cyan */
    2, 3,       /* dark green to teal */
};

/* A Kitchen's floor, walls, doors and Tables, light grey first so the light
 * blue that becomes it stays. */
static char fobj_kitchen_tints[] = {
    7, 8,       /* light grey to dark grey */
    9, 7,       /* light blue to light grey */
};

/* The Refrigerator, which takes none of the Kitchen's own. */
static char fobj_refrigerator_tints[] = {
    14, 15,     /* yellow to white */
};

/* The Range, which takes none of the Kitchen's own. */
static char fobj_range_tints[] = {
    14, 7,      /* yellow to light grey */
};
#endif

#if defined(TAC_UNIMPLEMENTED_ROOMS) || defined(TAC_ROOM_RECOLOUR)
/* Running one table's fills over a rectangle of the screen. */
static void c_fobj_fills(char *tints, INT bytes, INT x, INT y, INT w, INT h)
{
    INT i;

    /* Each pair turns its first colour into its second, in order. */
    for (i = 0; i < bytes; i += 2)
        drv_jump_gfx_fill(shd_screen, x, y, w, h, tints[i], tints[i + 1]);
}
#endif

#ifdef TAC_ROOM_RECOLOUR
/* The kind of `room` to recolour by, or -1 for none: for `room` -1, with the
 * option off, or on CGA, whose tiles keep their own fill. */
static INT c_fobj_room_kind(INT room)
{
    if (room < 0 || shm_cga != 0 || !MOD_ON(unimplemented_rooms))
        return -1;
    return asm_rooms[room].kind;
}

/* Recolouring the floor of `room`, drawn and nothing on it yet. */
void c_fobj_floor_tint(INT room, INT x, INT y, INT w, INT h)
{
    INT kind;

    /* Only a Bed Room, kind 6, and a Kitchen, kind 8, are recoloured. */
    kind = c_fobj_room_kind(room);
    if (kind == 6)
        c_fobj_fills(fobj_bed_room_tints, sizeof fobj_bed_room_tints,
                     x, y, w, h);
    else if (kind == 8)
        c_fobj_fills(fobj_kitchen_tints, sizeof fobj_kitchen_tints,
                     x, y, w, h);
}
#endif

#if defined(TAC_UNIMPLEMENTED_ROOMS) || defined(TAC_ROOM_RECOLOUR)
/* Recolouring what stands on a cell of `room`, just drawn at (x, y), by the
 * room's kind and the piece. */
void c_fobj_tint(INT obj, INT room, INT x, INT y, INT size)
{
#ifdef TAC_ROOM_RECOLOUR
    INT kind;
#endif

    /* CGA keeps its own colours. */
    if (shm_cga != 0)
        return;
#ifdef TAC_UNIMPLEMENTED_ROOMS
    /* A borrowed picture is recoloured inside its edge. */
    if (c_fobj_sprite(obj) != obj)
        c_fobj_fills(fobj_tints, sizeof fobj_tints,
                     x + 1, y + 1, size - 2, size - 2);
#endif
#ifdef TAC_ROOM_RECOLOUR
    kind = c_fobj_room_kind(room);
    if (kind == 6) {
        /* A Bed Room leaves the Stereo, 52, and the Televisions, 53 and 55. */
        if (obj == 52 || obj == 53 || obj == 55)
            return;
        /* The Bed, 46 and 47, takes its own first. */
        if (obj == 46 || obj == 47)
            c_fobj_fills(fobj_bed_tints, sizeof fobj_bed_tints,
                         x, y, size, size);
        c_fobj_fills(fobj_bed_room_tints, sizeof fobj_bed_room_tints,
                     x, y, size, size);
    } else if (kind == 8) {
        /* In a Kitchen the Range, 48 and 49, and the Refrigerator, 50 and 51,
         * take their own; walls, doors and the Tables, 32 and 33, the room's. */
        if (obj == 48 || obj == 49)
            c_fobj_fills(fobj_range_tints, sizeof fobj_range_tints,
                         x, y, size, size);
        else if (obj == 50 || obj == 51)
            c_fobj_fills(fobj_refrigerator_tints,
                         sizeof fobj_refrigerator_tints, x, y, size, size);
        else if (obj < 12 || obj == 32 || obj == 33)
            c_fobj_fills(fobj_kitchen_tints, sizeof fobj_kitchen_tints,
                         x, y, size, size);
    }
#endif
}
#endif
