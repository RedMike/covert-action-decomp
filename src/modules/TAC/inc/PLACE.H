/* PLACE.H -- placing a person, a doorway's cell, and flooding a path.
 */
#ifndef PLACE_H
#define PLACE_H

INT c_doorway_cell(INT from, INT to, INT *col, INT *row);
INT c_flood_path(INT floor, INT who, INT gc, INT gr, INT col, INT row);
void c_place_person(INT who);

#endif
