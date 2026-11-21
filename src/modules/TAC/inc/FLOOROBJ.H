/* FLOOROBJ.H -- names for the bits of FLOOR_OBJECT.flags.
 *
 * One name per test the routines make; 80h, set on the Table and never
 * tested, has none.
 */
#ifndef FLOOROBJ_H
#define FLOOROBJ_H

#define FOBJ_SOLID          0x001  /* blocks walking and paths; cover from sight */
#define FOBJ_OPENABLE       0x002  /* opens and shuts; the cell's 80h is open */
#define FOBJ_BUGGABLE       0x004  /* takes a bug */
#define FOBJ_PHOTOGRAPHABLE 0x008  /* takes a photo, once opened if it opens */
#define FOBJ_DOOR           0x010  /* passable open, and opens the facing cell too */
#define FOBJ_OPAQUE         0x020  /* blocks sight outright */
#define FOBJ_TWO_CELL       0x040  /* its partner, index ^ 1, fills the next column */
#define FOBJ_WALL_MOUNTED   0x100  /* placed only against a wall, facing it */
#define FOBJ_TERMINAL       0x200  /* asks the password, and gives up a letter */

#endif
