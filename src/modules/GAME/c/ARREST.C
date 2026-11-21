/* ARREST.C -- arresting a suspect and interrogating the prisoner.
 */
#include "GAME.H"
#include "ADVICE.H"
#include "PROSE.H"
#include "CMP_STRT.H"
#include "MISC1.H"
#include "DECODE.H"
#include "DIALOG.H"
#include "BLOCK.H"
#include "CASE.H"
#include "SUSPECT.H"
#include "ANI_PLAY.H"
#include "ORGPLAN.H"
#include "WRAP.H"
#include "LOGKINDS.H"
#include "RESULT.H"
#include "ALERTLVL.H"
#include "SUSPFLAG.H"
#include "ROLEFLAG.H"
#include "CRIMEVNT.H"

/* Interrogate a prisoner: put every plot he is tied to, then either release
 * him for want of evidence or take what he gives up -- the messages he
 * confirms, the plotters a mastermind names -- and jail him. */
INT c_arrest(INT who)
{
    char v0j[20];   /* his name, while the message buffer is rebuilt */
    INT v1j;        /* a plotter the mastermind names */
    INT v2j;
    INT v3k;        /* set while he is one of ours */
    INT v4k;
    INT v5l;        /* the plot he runs */
    INT v6l;        /* the plot being put to him */
    INT v7m;        /* set once a plot has stuck */
    INT v8m;        /* the message being put to him */
    INT v9n;
    INT v10g;

    /* The prisoner is questioned at the CIA, his face beside the interrogation room. */
    shm_case_org = 1;
    shm_menu_face_x = 24;
    shm_menu_face_y = 37;
    shm_menu_face = shm_suspects[who].visuals;
    drv_jump_gfx_set_colour_map(&dat_colours_accuse, &dat_colours_accuse);
    c_pan_arm(dat_str_intrgate_pan, 224, 0);
    c_seq_set_var(0, (shm_suspects[who].visuals & 1)
                       != 0 ? -1 : 1);
    /* Whether the minigame turned him into a double agent. */
    v3k = !COMM()->result[RES_ROLE_HIDDEN];
    /* "You accuse <name> of taking part in the plot, 'We know that you...'" */
    strcpy(shm_scratch, dat_str_accuse);
    c_person_name(who);
    strcat(shm_scratch, dat_str_taking_part_plot_we);
    /* Turning him lays every part he plays open. */
    if (v3k != 0)
        shm_suspects[who].role_known |=
            shm_suspects[who].role & 0x7fff;
    /* Put each real (not red herring) part he is known to play, and find the one he fills. */
    v7m = 0;
    v5l = -1;
    for (v6l = 0;
         v6l < shm_crime_role_count - shm_difficulty * 4; v6l++) {
        if ((shm_suspects[who].role_known
             & 1 << v6l) != 0) {
            v7m = 1;
            strcat(shm_scratch,
                       shm_crime_roles[v6l].name);
            strcat(shm_scratch, dat_str_dot_quote_nl);
        }
        if (shm_crime_roles[v6l].suspect == who)
            v5l = v6l;
    }
    /* Unless he is turned, or one of the CIA's own, his organisation's building in his city is forgotten. */
    if (shm_suspects[who].org != 1 && v3k == 0)
        c_building_forget(shm_suspects[who].org,
                        shm_suspects[who].city);
    /* Nothing known against him: he has to be let go, alerted and back at large. */
    if (v7m == 0) {
        shm_suspects[who].alert_level = ALERT_ARRESTED;
        strcpy(shm_scratch, dat_str_have_no_evidence);
        c_person_name(who);
        strcat(shm_scratch,
                   (shm_suspects[who].visuals & 1) != 0
                   ? dat_str_dot_nl_he : dat_str_dot_nl_she);
        strcat(shm_scratch, dat_str_will_have_released);
        c_ask_menu(shm_scratch, 16, 21);
        shm_suspects[who].alert_level = ALERT_FREED;
        c_raise_alert(shm_suspects[who].org,
                        shm_suspects[who].city, 99);
        c_log_add(LOG_AT_LARGE, who);
        /* A released prisoner needs no jailbreak. */
        if (who == shm_jailbreak_suspect)
            shm_jailbreak_suspect = -1;
        return;
    }
    /* The accusation sticks; the CIA's building in this city is made known. */
    c_ask_menu(shm_scratch, 16, 21);
    c_building_explore(1, shm_case_city, 0xc);
    /* He is held, or turned, and the prose says which. */
    shm_scratch[0] = 0;
    if (v3k == 0) {
        if (v7m != 0) {
            shm_suspects[who].alert_level = ALERT_ARRESTED;
#ifdef PORT_MODERN
            c_show_prose(dat_str_inter1, 24, (char *) 0, 0);
#else
            c_show_prose(dat_str_inter1, 24);
#endif
        }
    } else {
        shm_suspects[who].alert_level = ALERT_TURNED;
#ifdef PORT_MODERN
        c_show_prose(dat_str_doublea, 24, (char *) 0, 0);
#else
        c_show_prose(dat_str_doublea, 24);
#endif
    }
    c_log_add(v3k != 0 ? LOG_TURNED : LOG_ARRESTED, who);
    c_pan_blank();
    c_ask_menu(shm_scratch, 16, 21);
    /* Question him on his logged messages: partly known ones, or all on the two easiest levels or once turned. */
    for (v8m = 0; v8m < shm_log_count; v8m++)
        if (v7m != 0
            && shm_log[v8m].kind == LOG_MESSAGE
            && shm_log[v8m].from == who
            && ((shm_log[v8m].known & 0xf) != 0
                || shm_difficulty < 2
                || shm_suspects[who].alert_level
                   == ALERT_TURNED)) {
            /* Only a meeting or a message is worth asking about. */
            if ((shm_crime_events[shm_log[v8m].slot].flags & CRIME_MEETING) == 0
                && (shm_crime_events[shm_log[v8m].slot].flags & CRIME_MESSAGE) == 0)
                continue;
            /* The question: the message as it is known, and "," you ask." */
            shm_scratch[0] = 0;
#ifdef PORT_MODERN
            c_show_prose(dat_str_inter2, 24, (char *) 0, 0);
#else
            c_show_prose(dat_str_inter2, 24);
#endif
            c_intercept_line(v8m);
            strcat(shm_scratch, dat_str_ask);
            /* He owns up once enough of it is known for the difficulty, or always once turned. */
            if (shd_scan_counts[
                    shm_log[v8m].known & 0x1f]
                    >= shm_difficulty * 2
                || shm_suspects[who].alert_level
                   == ALERT_TURNED) {
                strcat(shm_scratch, dat_str_oh_yeah_i_guess);
                c_wrap_message(24);
                c_pan_blank();
                c_ask_menu(shm_scratch, 16, 21);
                /* Decode the message, keeping the right-hand strip to put back after. */
                drv_jump_gfx_copy_rect(shd_screen, 224, 0, 96, 200, shd_map_page, 224, 0);
                c_decode_message(v8m);
                drv_real_fill_rect(shd_screen, 0, 0, 224, 200, 5);
                drv_jump_gfx_copy_rect(shd_map_page, 224, 0, 96, 200, shd_screen, 224, 0);
                shm_pan_width = 224;
            } else {
                /* Otherwise he denies it: "Hmmm, I don't..." */
                strcat(shm_scratch, dat_str_hmmm_i_don_t);
                c_wrap_message(24);
                c_pan_blank();
                c_ask_menu(shm_scratch, 16, 21);
            }
        }
    /* His identity, his part in the plot and his background go on file. */
    shm_suspects[who].flags |= SUSPECT_IDENTITY | SUSPECT_PARTICIPANT | SUSPECT_BACKGROUND;
    if (v3k != 0
        || shm_suspects[who].role_known != 0) {
        /* A mastermind breaks down and lists the parts the others played. */
        if ((*(INT *) &shm_crime_roles[v5l].flags & ROLE_MASTERMIND)
            != 0) {
            strcpy(shm_scratch, dat_str_mastermind_breaks_down);
            c_wrap_message(24);
            c_pan_blank();
            c_ask_menu(shm_scratch, 16, 21);
        }
        for (v6l = 0;
             v6l < shm_crime_role_count - shm_difficulty * 4;
             v6l++) {
            /* Every clue fact about his own part is shown. */
            if (shm_crime_roles[v6l].suspect == who)
                shm_crime_roles[v6l].clues_known |= 0x1f;
            /* From a mastermind, every plotter is identified, his part revealed and his dossier shown. */
            if ((*(INT *) &shm_crime_roles[v5l].flags
                 & ROLE_MASTERMIND) != 0) {
                v1j = shm_crime_roles[v6l].suspect;
                shm_suspects[v1j].flags |= SUSPECT_IDENTITY | SUSPECT_PARTICIPANT;
                shm_suspects[v1j].role_known |=
                    shm_suspects[v1j].role & 0x7fff;
                c_dossier(v1j, 0, 0);
                c_wait_key();
            }
        }
        /* One not turned is seen taken to the local jail. */
        if (v3k == 0) {
            c_clear_for_menu();
            shm_menu_face_x = 101;
            shm_menu_face_y = 19;
            shm_menu_face = shm_suspects[who].visuals;
            drv_jump_gfx_set_colour_map(&dat_colours_accuse_2, &dat_colours_accuse_2);
            c_pan_arm(dat_str_injail_pan, 168, 0);
            c_seq_set_var(0,
                (shm_suspects[who].visuals & 1) != 0
                ? -1 : 1);
            shm_scratch[0] = 0;
            c_person_name(who);
            strcat(shm_scratch, dat_str_taken_local_jail);
            c_ask_menu(shm_scratch, 24, 21);
        }
        /* Back in the briefing room, the chief's word on the catch, by how senior his part was. */
        c_clear_for_menu();
        drv_jump_gfx_set_colour_map(&dat_colours_report, &dat_colours_report);
        c_pan_arm(dat_str_briefing_pan_2, 0, 0);
        c_seq_set_var(0, 2);
        shm_scratch[0] = 0;
        c_person_name(who);
        strcpy(v0j, shm_scratch);
        shm_scratch[0] = 0;
        c_show_prose(dat_str_nice0, 36, v0j,
                           (shm_crime_roles[v5l].rank - 1) / 3);
        c_wrap_message(40);
        c_ask_menu(shm_scratch, 16, 149);
    }
    /* The arrest takes four hours, and the world takes its half-day turn regardless. */
    c_advance_clock(240, (LONG) 1);
}
