/* CAMPAIGN-MISSION-START.C -- generating a case and briefing the player on it.
 */
#include "FINAL.H"
#include "PRIMS.H"
#include "CLAMP.H"
#include "SEQUENCE.H"
#include "MENUS.H"
#include "SCREEN.H"
#include "CSTART.H"
#include "CMISEND.H"
#include "CASERUN.H"
#include "CMISSTRT.H"
#include "ROLEFLAG.H"

/* Generate the next case and brief it: its organisations and cities, a suspect
 * for each participant, the leads known at the start and the red herrings.
 * Each pick rerolls against what is chosen; 999 tries restart the selection.
 * `spare` is never read.
 */
void c_case_generate(void)
{
    INT herring_org;
    INT dist2;
    INT freed;
    INT tally;
    INT distb;
    INT retry;
    INT pick;
    INT town;
    INT world;
    INT i;
    INT runner;
    INT j;
    INT redo;
    INT spare;
    INT score;
    INT held;
    INT value;

    /* The agent starts at the CIA in Washington, with nobody on alert. */
    shm_case_city = 1;
    shm_case_org = 1;
    shm_global_alert_level = 0;
    /* The mission's type picks the crime file and the region the world file. */
    shm_mission = shm_campaign.mission;
    world = shm_campaign.world;
    c_read_crime(shm_mission);
    c_read_world(world);
    /* No clues turned up yet. */
    for (i = 0; i < 80; i++)
        shm_clues_shown[i].role = -1;
    /* Every city and organisation starts with the same small activity count. */
    for (i = 0; i < 16; i++)
        shm_activity.city[i] = shm_activity.org[i] = 2;
    /* A double agent in a random city's CIA office per difficulty level, never Washington's. */
    shm_double_agent_cities = 0;
    for (i = 0; i < shm_difficulty; i++)
        shm_double_agent_cities |= 1 << c_random_below(16);
    *(unsigned char *) &shm_double_agent_cities &= 0xfd;
    /* Lay out the case, starting over whenever the tries run out. */
    for (;;) {
        /* Every suspect record free and unalerted. */
        for (i = 0; i < 64; i++) {
            shm_suspects[i].org = -1;
            shm_suspects[i].visuals = 0;
            shm_suspects[i].flags = 0;
            shm_suspects[i].alert_level = 0;
        }
        /* All 64 records in play, the case clock at 99 and a word of no known use at -1. */
        shm_suspect_count = 64;
        shm_case_tick = 99;
        shm_case_spare_2 = -1;
        retry = 0;
        /* Find the crime event list's end marker; the index found is never used. */
        freed = -1;
        while (*(unsigned char *) &shm_crime_events[++freed].main_participant != 0xff)
            ;
        /* ROLE_MASTERMIND_ORG's organisation: within 10 of the CIA on the grid, and not the CIA. */
        do {
            asm_case_mastermind = c_random_below(15) + 1;
            distb = c_packed_distance(
                shm_orgs[1].where,
                shm_orgs[(INT) asm_case_mastermind].where);
            if (distb <= 10 && asm_case_mastermind != 1)
                break;
            retry++;
        } while (retry < 999);
        /* Organisation 1: 8 or more from the CIA, within 8 of the mastermind's, column over 4. */
        do {
            shm_case_org_1 = c_random_below(15) + 1;
            distb = c_packed_distance(
                shm_orgs[1].where,
                shm_orgs[shm_case_org_1].where);
            dist2 = c_packed_distance(
                shm_orgs[shm_campaign.mastermind_org].where,
                shm_orgs[shm_case_org_1].where);
            if (distb >= 8 && dist2 <= 8
                && (shm_orgs[shm_case_org_1].where & 0xf) > 4)
                break;
            retry++;
        } while (retry < 999);
        /* Organisation 2: within 8 of the first, in a grid column over 4. */
        do {
            shm_case_org_2 = c_random_below(15) + 1;
            distb = c_packed_distance(
                shm_orgs[shm_case_org_1].where,
                shm_orgs[(INT) shm_case_org_2].where);
            if (distb <= 8
                && (shm_orgs[(INT) shm_case_org_2].where & 0xf) > 4)
                break;
            retry++;
        } while (retry < 999);
        /* City 1: 8 or more from the CIA, organisation 1 present, not the mastermind's city. */
        do {
            shm_case_city_1 = c_random_below(16);
            distb = c_packed_distance(
                shm_orgs[1].where,
                shm_cities[shm_case_city_1].where);
            if (distb >= 8
                && c_presence(shm_case_city_1, shm_case_org_1)
                && shm_campaign.mastermind_city != shm_case_city_1)
                break;
            retry++;
        } while (retry < 999);
        /* City 2: within 12 of city 1, organisation 2 present, not the mastermind's city. */
        do {
            shm_case_city_2 = c_random_below(16);
            distb = c_packed_distance(
                shm_cities[shm_case_city_1].where,
                shm_cities[(INT) shm_case_city_2].where);
            if (distb <= 12
                && c_presence(shm_case_city_2, shm_case_org_2)
                && shm_campaign.mastermind_city != shm_case_city_2)
                break;
            retry++;
        } while (retry < 999);
        /* City 3: within 10 of the CIA, with ROLE_MASTERMIND_ORG's organisation present. */
        do {
            asm_case_city_3 = c_random_below(16);
            distb = c_packed_distance(
                shm_orgs[1].where,
                shm_cities[(INT) asm_case_city_3].where);
            if (distb <= 10
                && c_presence(asm_case_city_3, asm_case_mastermind))
                break;
            retry++;
        } while (retry < 999);
        /* The five draws share 999 tries; spending them all starts the case over. */
        if (retry >= 999)
            continue;
        /* Organisations in grid column 8 or over drift up to two cells each way, kept on the grid. */
        for (j = 0; j < 16; j++) {
            if ((shm_orgs[j].where & 0xf)
                >= 8) {
                i = c_clamp(
                    (INT) c_random_below(5)
                        + (shm_orgs[j].where & 0xf)
                        - 2,
                    0, 15);
                tally = c_clamp(
                    c_random_below(5)
                        + shm_orgs[j].where / 16
                        - 2,
                    0, 15);
                shm_orgs[j].where
                    = (tally << 4) + i;
            }
        }
        /* Place every participant; one that cannot be placed starts the case over. */
        for (i = 0; i < shm_crime_role_count; i++)
            retry += c_place_participant(i) ? 0 : 999;
        if (retry < 999)
            break;
    }
    /* No crime event has happened yet; brief the player. */
    c_clear_happen_ticks();
    c_briefing(world);
    /* Nothing is known of any organisation yet. */
    for (j = 0; j < 16; j++)
        shm_orgs[j].known = 0;
    /* For each organisation, which of its buildings the CIA already knows: */
    for (j = 0; j < 16; j++) {
        score = 999;
        pick = runner = -1;
        for (i = 0; i < 16; i++) {
            /* Is the organisation worth the trip here from the CIA, and does it work here at all? */
            held = c_worth_the_trip(1, j, i);
            value = c_presence(i, j);
            /* Track its nearest city and the nearest before that, until a city is revealed. */
            if (value) {
                value = c_packed_distance(
                    shm_cities[i].where,
                    shm_orgs[j].where);
                if (value < score) {
                    score = value;
                    runner = pick;
                    pick = i;
                }
            }
            /* Reveal its building where it is worth the trip, and in every city for Local Contact. */
            if (held || j == 0) {
                c_building_explore(j, i, 4);
                shm_cities[i].known_orgs
                    |= 1 << j;
                shm_orgs[j].known
                    |= 1;
                score = -1;
            }
        }
        /* And in the two nearest cities found. */
        if (pick != -1) {
            c_building_explore(j, pick, 4);
            shm_cities[pick].known_orgs
                |= 1 << j;
        }
        if (runner != -1) {
            c_building_explore(j, runner, 4);
            shm_cities[runner].known_orgs
                |= 1 << j;
        }
    }
    /* Then each city, against the organisations past Local Contact, the CIA, MI6 and Mossad: */
    for (i = 0; i < 16; i++) {
        tally = 0;
        score = 999;
        pick = runner = -1;
        /* count those worth the trip there, and track the nearest present and the one before; */
        for (j = 4; j < 16; j++) {
            held = c_worth_the_trip(1, j, i);
            value = c_presence(i, j);
            if (value) {
                value = c_packed_distance(
                    shm_cities[i].where,
                    shm_orgs[j].where);
                if (value < score) {
                    score = value;
                    runner = pick;
                    pick = j;
                }
            }
            if (held)
                tally++;
        }
        /* where fewer than two or three were worth the trip, reveal the nearest one or two too. */
        if (tally < 2 && pick != -1) {
            c_building_explore(pick, i, 4);
            shm_cities[i].known_orgs
                |= 1 << pick;
        }
        if (tally < 3 && runner != -1) {
            c_building_explore(runner, i, 4);
            shm_cities[i].known_orgs
                |= 1 << runner;
        }
    }
    /* Four red herrings per difficulty level, after the real roles: */
    for (i = shm_crime_role_count;
         shm_difficulty * 4 + shm_crime_role_count > i; i++) {
        /* an organisation from 4 on, not the mastermind's, in a city it works in, nobody there yet; */
        do {
            do
                herring_org = c_random_below(12) + 4;
            while (herring_org == shm_campaign.mastermind_org);
            do
                town = c_random_below(16);
            while (!c_presence(town, herring_org));
        } while (c_suspect_reserve(herring_org, town, 0) != -1);
        /* a decoy suspect there, called Red Herring, giving itself away at a rate of 3 to 6; */
        shm_crime_roles[i].suspect
            = c_suspect_reserve(herring_org, town, 0x8000);
        strcpy(shm_crime_roles[i].name,
                   dat_str_red_herring);
        shm_crime_roles[i].exposure
            = c_random_below(4) + 3;
        /* a clue object whose printed number no earlier role has; */
        do {
            shm_crime_roles[i].clue_id
                = c_random_below(0x7fff);
            redo = 1;
            for (j = 0; j < i; j++)
                if ((shm_crime_roles[i].clue_id & 0x7e)
                    == (*(unsigned char *) &shm_crime_roles[j].clue_id & 0x7e))
                    redo = 0;
        } while (redo == 0);
        /* no flags, nothing known, scans building on it from a random early tick; */
        *(INT *) &shm_crime_roles[i].flags = 0;
        shm_crime_roles[i].clues_known = 0;
        shm_role_scan_states[i].clue_visible_since
            = c_random_below(shm_crime_event_count / 2) + 4;
        shm_role_scan_states[i].clue_visibility = 0;
        /* and a random kind of clue and rank, short of MasterMind. */
        shm_crime_roles[i].clue_type = c_random_below(7);
        shm_crime_roles[i].rank = c_random_below(7);
    }
    /* The herrings count among the case's roles from here on. */
    shm_crime_role_count += shm_difficulty * 4;
}
