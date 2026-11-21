/* PERSONNEL-FILE.C -- the Master Plan screen and one organisation's file.
 *
 * One routine draws both, the Master Plan when given no organisation. Either
 * way the organisation's bit in shm_orgs_known marks its file as looked at.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "CASERUN.H"
#include "FACES.H"
#include "SCREEN.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* shared_include_start: ../../../../shared/c/PERSONNEL-FILE.C -- generated */
/* PERSONNEL-FILE.C -- c_personnel_file, the Master Plan and Personnel Files.
 */

/* Draw the Master Plan (`org` 0) or `org`'s Personnel File and wait for a key.
 * `reveal` first turns on each listed suspect's record.
 */
void c_personnel_file(INT org, INT reveal)
{
    INT x;
    INT row;
    INT blank;
    INT i;
    INT y;
    INT spare;

    switch (org) {
    case 0:
        shm_orgs_known |= 1;
        c_page_frame(shd_str_master_plan, 9);
        y = 0x20;
        (shm_scratch)[0] = 0;
        for (i = 0; i < 5; i++)
            strcat(shm_scratch, shd_str_secret);
        c_write_text_trimmed((rt_addr) shm_scratch, 0xc, 0x10, 0xe);
        c_write_text_trimmed((rt_addr) shm_scratch, 0xc, 0xbc, 0xe);
        for (i = 0; shm_crime_role_count - shm_difficulty * 4 > i;
             i++) {
            if ((*(INT *) &shm_crime_roles[i].flags & ROLE_MASTERMIND)
                == 0) {
                x = (i & 3) * 0x48 + 0x1c;
                if (i == 4)
                    y += 0x50;
                row = shm_crime_roles[i].suspect;
                if ((shm_suspects[row].flags & (SUSPECT_PHOTO | SUSPECT_PHOTO_LOST))
                    != SUSPECT_PHOTO_LOST)
                    c_draw_face_panel(shm_suspects[row].visuals, x, y);
                (shm_scratch)[0] = 0;
                if (shm_suspects[row].alert_level == ALERT_ARRESTED)
                    strcpy(shm_scratch, shd_str_arrested_upper);
                if (shm_suspects[row].alert_level == ALERT_HIDING)
                    strcpy(shm_scratch, shd_str_hiding_upper);
                if (shm_suspects[row].alert_level == ALERT_TURNED)
                    strcpy(shm_scratch, shd_str_turned_upper);
                c_write_text_trimmed((rt_addr) shm_scratch, x - 1,
                                   y + 0x10, 5);
                c_write_text_trimmed((rt_addr) shm_scratch, x - 2,
                                   y + 0x10, 0xc);
                strcpy(shm_scratch, shm_crime_roles[i].name);
                c_draw_centred(shm_scratch, x + 0x19,
                                   y + 0x38, 0xc);
                y ^= 8;
            }
        }
        break;
    default:
        shm_orgs_known |= 1 << org;
        c_page_frame(shd_str_personnel_file, 9);
        strcpy(shm_scratch, shm_orgs[org].long_name);
        strcat(shm_scratch, shd_str_action_team);
        c_write_text_trimmed((rt_addr) shm_scratch, 0x50, 0x10, 5);
        y = 0x20;
        blank = 1;
        for (i = 1; i < shm_suspect_count; i++) {
            if (shm_suspects[i].org == org
                && (shm_suspects[i].role & 0x7fff)
                   != 0) {
                if (reveal != 0)
                    shm_suspects[i].flags |= SUSPECT_NAME | SUSPECT_ORG | SUSPECT_CITY;
                (shm_scratch)[0] = 0;
                c_person_name(i);
                if (shm_suspects[i].flags & SUSPECT_CITY) {
                    strcat(shm_scratch, shd_str_comma_3);
                    strcat(shm_scratch,
                               shm_cities[shm_suspects[i].city].name);
                }
                c_write_text_trimmed((rt_addr) shm_scratch, 0x50, y,
                                   0xc);
                y += 8;
                blank = 0;
            }
        }
        if (blank != 0)
            c_write_text_trimmed(shd_str_no_activity, 0x50, y, 0xc);
    }
    c_wait_key();
}
/* shared_include_end: ../../../../shared/c/PERSONNEL-FILE.C */
