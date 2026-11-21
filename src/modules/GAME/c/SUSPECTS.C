/* SUSPECTS.C -- a suspect's real name, the master plan and personnel files.
 */
#include "GAME.H"
#include "SUSPECTS.H"
#include "MISC1.H"
#include "FRAME.H"
#include "CASE.H"
#include "SUSPECT.H"
#include "PANEL.H"
#include "FACES.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"

/* Append the real name of suspect `nth`: a first name and a surname out of
 * tables, picked by the organisation's nationality and the suspect's face. */
void c_person_real_name(INT nth)
{
    INT spare;

    /* The first name, by sex, from the run the organisation's nationality gives. */
    strcat(shm_scratch,
               dat_first_names
                   [shm_suspects[nth].visuals & 1]
                   [shm_orgs[shm_suspects[nth].org].nationality * 2
                    + (shm_suspects[nth].visuals >> 1
                       & 0xf)]);
    /* Then the surname, from the same nationality's run. */
    strcat(shm_scratch, dat_str_space_14);
    strcat(shm_scratch,
               dat_last_names
                   [shm_orgs[shm_suspects[nth].org].nationality * 2
                    + (shm_suspects[nth].visuals >> 5
                       & 0xf)]);
}

/* Draw the Master Plan, or `org`'s Personnel File, and wait for a key. */
void c_personnel_file(INT org, INT reveal, INT unused)
{
    INT x;
    INT row;
    INT blank;
    INT i;
    INT y;
    INT spare;

    switch (org) {
    /* The Master Plan, which once seen is held among the documents. */
    case 0:
        shm_orgs_known |= 1;
        c_page_frame(dat_str_master_plan, 9);
        y = 32;
        /* A --SECRET-- banner across the top and the foot. */
        (shm_scratch)[0] = 0;
        for (i = 0; i < 5; i++)
            strcat(shm_scratch, dat_str_secret);
        c_write_text_trimmed((rt_addr) shm_scratch, 12, 16, 14);
        c_write_text_trimmed((rt_addr) shm_scratch, 12, 188, 14);
        /* Every role the difficulty leaves in play, bar the mastermind's. */
        for (i = 0; shm_crime_role_count - shm_difficulty * 4 > i;
             i++) {
            if ((*(INT *) &shm_crime_roles[i].flags & ROLE_MASTERMIND)
                == 0) {
                /* Four to a row by role number, the second row 80 lower. */
                x = (i & 3) * 72 + 28;
                if (i == 4)
                    y += 80;
                /* The suspect's face, unless their photograph was taken away. */
                row = shm_crime_roles[i].suspect;
                if ((shm_suspects[row].flags & (SUSPECT_PHOTO | SUSPECT_PHOTO_LOST))
                    != SUSPECT_PHOTO_LOST)
                    c_draw_face_panel(shm_suspects[row].visuals, x, y);
                /* What has become of them, stamped across the face with a shadow. */
                (shm_scratch)[0] = 0;
                if (shm_suspects[row].alert_level == ALERT_ARRESTED)
                    strcpy(shm_scratch, dat_str_arrested);
                if (shm_suspects[row].alert_level == ALERT_HIDING)
                    strcpy(shm_scratch, dat_str_hiding);
                if (shm_suspects[row].alert_level == ALERT_TURNED)
                    strcpy(shm_scratch, dat_str_turned);
                c_write_text_trimmed((rt_addr) shm_scratch, x - 1,
                                   y + 16, 5);
                c_write_text_trimmed((rt_addr) shm_scratch, x - 2,
                                   y + 16, 12);
                /* The role's name beneath. */
                strcpy(shm_scratch, shm_crime_roles[i].name);
                c_draw_centred(shm_scratch, x + 25,
                                y + 56, 12);
                /* Stagger alternate faces up and down by 8. */
                y ^= 8;
            }
        }
        break;
    /* An organisation's Personnel File, which once seen is held among the documents. */
    default:
        shm_orgs_known |= 1 << org;
        c_page_frame(dat_str_personnel_file, 9);
        strcpy(shm_scratch, shm_orgs[org].long_name);
        strcat(shm_scratch, dat_str_action_team);
        c_write_text_trimmed((rt_addr) shm_scratch, 80, 16, 5);
        y = 32;
        blank = 1;
        /* A line for each of its people with a real role, revealing them first if asked. */
        for (i = 1; i < shm_suspect_count; i++) {
            if (shm_suspects[i].org == org
                && (shm_suspects[i].role & 0x7fff)
                   != 0) {
                if (reveal != 0)
                    shm_suspects[i].flags |= SUSPECT_NAME | SUSPECT_ORG | SUSPECT_CITY;
                (shm_scratch)[0] = 0;
                c_person_name(i);
                if (shm_suspects[i].flags & SUSPECT_CITY) {
                    strcat(shm_scratch, dat_str_comma_4);
                    strcat(shm_scratch,
                               shm_cities[shm_suspects[i].city].name);
                }
                c_write_text_trimmed((rt_addr) shm_scratch, 80, y,
                                   12);
                y += 8;
                blank = 0;
            }
        }
        /* Nobody: say there has been no activity. */
        if (blank != 0)
            c_write_text_trimmed(dat_str_no_activity, 80, y, 12);
    }
    /* Hold the page until a key is pressed. */
    c_wait_key();
}
