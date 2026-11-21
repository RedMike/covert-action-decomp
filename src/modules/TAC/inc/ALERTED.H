/* ALERTED.H -- guards' alertness, noticing, seeing, and the line of sight.
 */
#ifndef ALERTED_H
#define ALERTED_H

INT c_guard_alertness(INT guard);
INT c_guard_sees_player(INT guard);
INT c_guard_sees(INT guard);
INT c_line_of_sight(INT x1, INT y1, INT x2, INT y2);

#endif
