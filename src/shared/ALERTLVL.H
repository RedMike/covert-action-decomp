/* ALERTLVL.H -- the named values of SUSPECT's `alert_level`. Zero and up is
 * how alert a suspect still in play is; below zero the suspect is out of
 * play, and the value says why.
 */
#ifndef ALERTLVL_H
#define ALERTLVL_H

#define ALERT_ARRESTED (-1)     /* arrested and held */
#define ALERT_HIDING (-2)       /* gone into hiding */
#define ALERT_TURNED (-3)       /* arrested and turned double agent */
#define ALERT_FREED 99          /* back in play after release, escape or exchange */

/* Unused: c_suspect_menu shows it as "(In Custody)", but nothing sets it. */
#define ALERT_IN_CUSTODY (-4)

#endif /* ALERTLVL_H */
