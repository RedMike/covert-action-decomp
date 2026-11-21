/* STRUCTS.H -- every structure the tree defines, in one place. */
#ifndef STRUCTS_H
#define STRUCTS_H

/* FAR and NEAR, and the widths the two builds disagree on. */
#include "PORTING.H"

/* the case's activity counters, one save section: how many names the player
 * has been told in each city and of each organisation
 */
struct ACTIVITY {
    INT city[16];  /* one counter per city */
    INT org[16];   /* one counter per organisation */
};

/* one of the 256 building records, an organisation's building in a city the
 * player knows of; records are emptied in place, never given back. One save
 * section
 */
struct BUILDING {
    INT org;                           /* the organisation, an index into shm_orgs */
    INT city;                          /* the city, an index into shm_cities */
    INT identity_flags;                /* what the player knows of it: 04 the organisation is identified, 08 the car tracer or a tail found it; zero is a forgotten record */
    INT wiretap_level;                 /* how strong the tap on the building is; over 1 puts it on the tap list */
    UNSIGNED_LONG tac_rooms_explored;  /* one bit per room of the break-in layout the player has entered, at most 24 */
};

/* the byte view of REGS, over the first eight */
struct BYTEREGS {
    unsigned char al;
    unsigned char ah;
    unsigned char bl;
    unsigned char bh;
    unsigned char cl;
    unsigned char ch;
    unsigned char dl;
    unsigned char dh;
};

/* the campaign record, the first of the twelve save sections: what outlives a
 * case, with the current mission's mastermind and text
 */
struct CAMPAIGN {
    INT mission_set;                     /* index into dat_mission_sets: 0 for a first case at the lowest difficulty, otherwise 1 to 15 */
    UNSIGNED_INT missions_done;          /* one bit per MISSION_SET.mission[] slot already played in this set */
    UNSIGNED_INT mastermind_flags;       /* SUSPECT.flags of the mastermind, suspect record 0 */
    INT mastermind_org;                  /* SUSPECT.org of record 0 */
    INT mastermind_city;                 /* SUSPECT.city of record 0 */
    UNSIGNED_INT mastermind_visuals;     /* SUSPECT.visuals of record 0 */
    UNSIGNED_INT mastermind_org_known;   /* the low byte of ORG_STATE.known for mastermind_org: the bit number in masterminds_arrested */
    UNSIGNED_INT mission_step;           /* which of the set's eight missions this is; -1 before the first */
    UNSIGNED_INT mission;                /* MISSION_SET.mission[mission_step], which numbers the case's crime file and keys its text blocks */
    UNSIGNED_INT world;                  /* 0..2, the n of WORLDn.DTA */
    INT score;                           /* the career's score */
    INT cases;                           /* how many cases the career has run to, read as months since January 1990; the career ends at 78h */
    INT saved_minutes;                   /* a copy of the campaign clock, taken when a save is written */
    char city_name[12];                  /* CITY.name of the case's city, taken when a save is written */
    INT best_rank;                       /* the lowest rank number reached, 63h at the start */
    UNSIGNED_INT field_28;               /* unused */
    char text[2][40];                    /* MISSION_SET.text[mission_step]: [0] replaces $VICTIM and [1] $OBJECT */
    char player_name[16];                /* the player's code name, copied into FAME_ENTRY.name */
    unsigned char record[512];           /* the career record, four or five bytes a case and closed by 0ffh: mission_set << 4 + mission_step, the case flags, the efficiency high byte then low, and mastermind_org_known where the mastermind was arrested */
    UNSIGNED_LONG masterminds_arrested;  /* one bit per mastermind_org_known value whose mastermind has been arrested */
} PORT_PACKED;

/* one of CHASE's three car records. In a tail car 0 is the suspect's and
 * cars 1 and 2 the player's; in an ambush car 0 is the player's and cars 1
 * and 2 the pursuers'
 */
struct CAR {
    INT x;          /* the position across the board */
    INT y;          /* the position down the board */
    INT facing;     /* which of the four ways it points; (facing + 2) & 3 is the way back */
    INT locked_on;  /* on a car the player drives, 1 while it drives itself (F10); on one the player watches, 1 when it was in contact this step */
    INT from_x;     /* on a car the player watches, where it was last seen, across; in a tail, car 1's is also the point the player's cars steer at, -1 once reached */
    INT from_y;     /* the same, down */
    INT goal;       /* on a car the player drives, the turn an arrow key asked for, -1 for none; on one the player watches, the way it pointed when last seen */
    INT suspicion;  /* in units of asm_suspicion_scale: on the suspect's car, how suspicious the suspect is; on the player's, how much the suspect has noticed that car */
    INT gear;       /* the gear, which is also the engine note the sound driver is given */
    INT spec;       /* the flag word the player picked, whose bits CARSPEC.H names; 0 for car 0 */
};

/* one of the sixteen city records WORLDn.DTA loads */
struct CITY {
    char name[12];        /* the city's name */
    char country[12];     /* the country, printed after the city's name */
    UNSIGNED_INT where;   /* a cell on the 16x16 grid the organisations are placed on; not the map position */
    INT rank;             /* how big the city is, which scales an organisation's reach there */
    INT known_orgs;       /* one bit per organisation whose building here the player has been told about */
    INT visited_cia;      /* one bit per organisation whose building here the player has walked into, cleared at noon and midnight; never read */
    unsigned char map_x;  /* the map column */
    unsigned char map_y;  /* the map row */
};

/* one of the two tables the CGA driver maps colours through, an entry per
 * logical colour
 */
struct COLOUR_MAP {
    unsigned char col_0;   /* what logical colour 0 is drawn as */
    unsigned char col_1;   /* what logical colour 1 is drawn as */
    unsigned char col_2;   /* what logical colour 2 is drawn as */
    unsigned char col_3;   /* what logical colour 3 is drawn as */
    unsigned char col_4;   /* what logical colour 4 is drawn as */
    unsigned char col_5;   /* what logical colour 5 is drawn as */
    unsigned char col_6;   /* what logical colour 6 is drawn as */
    unsigned char col_7;   /* what logical colour 7 is drawn as */
    unsigned char col_8;   /* what logical colour 8 is drawn as */
    unsigned char col_9;   /* what logical colour 9 is drawn as */
    unsigned char col_10;  /* what logical colour 10 is drawn as */
    unsigned char col_11;  /* what logical colour 11 is drawn as */
    unsigned char col_12;  /* what logical colour 12 is drawn as */
    unsigned char col_13;  /* what logical colour 13 is drawn as */
    unsigned char col_14;  /* what logical colour 14 is drawn as */
    unsigned char col_15;  /* what logical colour 15 is drawn as */
};

/* the state COVERT keeps resident for every module to read and write, 12000
 * bytes
 */
struct COMM_BLOCK {
    unsigned char next_module;         /* index into COVERT's module table */
    unsigned char mission_started;     /* the mission is under way, so GAME does not start a fresh one */
    unsigned char graphics_driver;     /* what COVERT builds ?graphic.exe from */
    unsigned char sound_driver;        /* and ?sound.ca */
    unsigned char joystick_enabled;    /* joystick chosen, not keyboard only */
    unsigned char spare_05[2];         /* no known use */
    unsigned char handover;            /* a third dispatch byte */
    unsigned char result[8];           /* the minigame result block */
    unsigned char spare_10[16];        /* no known use */
    UNSIGNED_INT case_city;            /* the case's city, an index into shm_cities */
    UNSIGNED_INT case_org;             /* the case's organisation, an index into shm_orgs */
    UNSIGNED_INT options;              /* option bits, named in CMP_OPTS.H */
    UNSIGNED_INT mission;              /* the case's mission, CAMPAIGN.mission carried across a handover */
    UNSIGNED_INT case_org_1;           /* the case's first organisation, paired with case_city_1 */
    UNSIGNED_INT case_org_2;           /* the case's second organisation, paired with case_city_2 */
    UNSIGNED_INT case_city_1;          /* the city paired with case_org_1 */
    UNSIGNED_INT case_city_2;          /* the city paired with case_org_2 */
    UNSIGNED_INT clock_minutes;        /* the campaign clock in minutes; / 60 % 24 is the hour */
    UNSIGNED_INT suspect_count;        /* how many of the SUSPECT records the case runs over, set to 40h */
    UNSIGNED_INT building_count;       /* how many BUILDING records are in use, and so where the next one goes */
    UNSIGNED_INT case_tick;            /* the case's clock in half-days */
    UNSIGNED_INT carried_38;           /* set to -1 and carried, but never read */
    UNSIGNED_INT difficulty;           /* 0..4 */
    UNSIGNED_INT case_seed;            /* the case's random seed, time(0) & 7fffh */
    UNSIGNED_INT crime_role_count;     /* how many CRIME_ROLE records the case has, which sizes their save sections */
    UNSIGNED_INT crime_event_count;    /* how many crime events the case has */
    UNSIGNED_INT prisoner;             /* the arrested suspect a jailbreak is coming for, a SUSPECT index or -1 */
    UNSIGNED_INT graphics_letter;      /* the graphics driver's letter, a character such as 'C' */
    UNSIGNED_INT log_count;            /* how many LOG_ENTRY records the case has written */
    UNSIGNED_INT org_alert_level;      /* how alert the local organisation is, which GAME sets on every handover */
    UNSIGNED_INT double_agent_cities;  /* one bit per city whose CIA office holds a double agent */
    UNSIGNED_INT orgs_known;           /* one bit per organisation */
    UNSIGNED_INT skills;               /* four 2-bit levels; 0x555 resets */
    UNSIGNED_INT game_50;              /* a copy of the difficulty, kept across a hand-over */
    UNSIGNED_INT carried_52;           /* cleared and carried, but never read */
    unsigned char spare_54[12];        /* no known use */
    UNSIGNED_INT driver_segment[3];    /* the graphics, second and sound driver segments */
    unsigned char spare_66[410];       /* no known use */
    unsigned char message[11488];      /* the message CODE deciphers, then the room the case's save sections are kept in */
};

/* one of the four records at the end of CRIMEn.DTA */
struct CRIME_ENTRY {
    unsigned char name[16];  /* what the record is called: Pilot, Payoff, Escapee */
    char u1;                 /* added to the room score, shifted left four */
    char u2;                 /* the suspect who holds the object, -1 where the record is unused or the object destroyed */
};

/* one step of the crime a case is about, up to 64 of them out of CRIMEn.DTA.
 * One save section
 */
struct CRIME_EVENT {
    char main_participant;  /* the participant grid cell the event is about */
    unsigned char field_1;  /* unused and zero in every CRIMEn.DTA */
    INT happen_tick;        /* the case tick the event happened on: 999 until it comes due, -1 where it is cancelled */
    INT message_id;         /* the *MSGaabb tag in TEXT.DTA the event's text is read from; not unique */
    char description[32];   /* the sentence the event is described by, straight out of the file */
    INT flags;              /* the low byte is the grid cell at the far end and the high byte the kind, as CRIMEVNT.H names them; signed, as the shipped code multiplies it */
    INT objects;            /* the low byte is what the event hands over and the high byte what it destroys, one bit per object */
    INT score;              /* what the event is worth */
};

/* one of the case's 32 crime roles: the participant records of CRIMEn.DTA,
 * then four red herrings per difficulty level. One save section
 */
struct CRIME_ROLE {
    INT suspect;            /* the suspect filling the role, an index into shm_suspects; FFFFh until one is placed */
    INT exposure;           /* how fast the role gives itself away: 0 to 6 from the file, 3 to 6 for a red herring */
    char name[32];          /* what the role is called, from the file, or Red Herring */
    INT clue_id;            /* which clue object the role's clue names, a random word: bits 5-7 the column of shd_clue_kinds, bits 1-6 the number printed after it */
    UNSIGNED_INT flags;     /* from the file, zero for a red herring; ROLEFLAG.H names the bits */
    INT clues_known;        /* which of the role's five clues the player has been shown; CLUEFACT.H names the bits */
    INT clue_type;          /* what kind of clue the role gives: 0 vehicle, 1 weapon, 2 address, 3 airline ticket, 4 telegram, 5 and 6 money, 7 identity document */
    INT rank;               /* the role's rank, 0 to 7, Recruit to MasterMind */
    UNSIGNED_INT field_2e;  /* unused */
};

/* one of TAC's 96 doorway records, one per doorway cut between two rooms,
 * looked up by the pair of rooms in either order
 */
struct DOORWAY {
    char from;    /* the room on the side the doorway was cut from, 0 once that room is scrapped */
    char to;      /* the room on the other side, 0 in the same way */
    char col;     /* the column of the doorway's cell on the from side */
    char row;     /* the row of that cell */
    char facing;  /* which way the doorway faces from the from side, 0 to 3; (facing + 2) & 3 is the way back */
};

/* one of the six hall of fame records, highest score first */
struct FAME_ENTRY {
    INT score;         /* what orders the table, -1 in an empty record */
    char name[32];     /* the player's code name, copied from CAMPAIGN.player_name */
    INT difficulty;    /* shm_difficulty, with 80h in the low byte for a female agent */
    INT mission_set;   /* CAMPAIGN.mission_set */
    INT mission_step;  /* CAMPAIGN.mission_step */
    INT points;        /* the case's efficiency points, printed */
    INT cases;         /* CAMPAIGN.cases, how many cases the career ran to */
};

/* one of TAC's 62 floor objects, record i for the thing a grid cell
 * holding i shows: walls, doors, furniture, the MacGuffin and the local
 * agent
 */
struct FLOOR_OBJECT {
    char name[12];  /* what the panel calls it */
    INT sprite_x;   /* where its 16-by-16 picture sits across asm_status_page */
    INT sprite_y;   /* and down; 10h further for a cell with 80h set */
    INT flags;      /* bits tested one at a time, 4 when planting a bug and 8 for a photo among them */
    INT field_12;   /* one bit of it is tested when furnishing a room */
};

/* one of TAC's sixteen grenade slots, thrown or set, the first free one
 * taken
 */
struct GRENADE {
    INT x;      /* where it is, across */
    INT y;      /* where it is, down */
    INT dir;    /* which of the eight ways it is travelling */
    INT timer;  /* starts at the animation times 10 when there is one, and at -9999 for the prompt's first choice */
    INT flags;  /* -1 in a free slot; otherwise the kind in the low seven bits, an index into asm_ammunition, and 80h for a guard's grenade */
};

/* one scene of FINAL's interlude between cases: where it is set and who
 * joins the agent there
 */
struct INTERLUDE {
    INT place;       /* the place, 0 to 3: the LaundroMat, the secretarial pool, the beach or the Casino */
    INT company[4];  /* the picture number of each dude or babe who joins the agent, in the order they arrive; -1 ends the list early */
};

/* the joystick's position as the driver returns it, one word over both
 * bytes
 */
struct JOYSTICK {
    unsigned char x;  /* across, the low byte */
    unsigned char y;  /* down, the high byte */
};

/* one of TAC's twelve kit screen boxes, record i for box i: the box each
 * direction moves the highlight to; record 0 is zero
 */
struct KIT_BOX {
    INT up;     /* the box above; Home takes this and then left */
    INT down;   /* the box below; PgDn takes this and then right */
    INT left;   /* the box to the left; End takes this and then down */
    INT right;  /* the box to the right; PgUp takes this and then up */
};

/* one of the 128 case-log records. One save section */
struct LOG_ENTRY {
    INT kind;            /* which event this is, one of the LOG_ values */
    INT minute;          /* the campaign minute it happened at; signed, as the shipped code divides it */
    INT slot;            /* what the record is about, packed differently per kind */
    UNSIGNED_INT known;  /* what the player has learnt of it: bit 0 shows the date, 8000h marks a message decoded or overheard */
    INT status;          /* the sender's alert level; 15 or less means none to report */
    char from;           /* the suspect it came from; 0ffh where kind is not LOG_MESSAGE */
    char from_city;      /* the city it came from */
    char to;             /* the suspect it went to */
    char to_city;        /* the city it went to */
};

struct MISSION_SET {
    char name[24];
    UNSIGNED_INT field_18;
    INT mission[8];
    unsigned char *text[8][2];
};

struct ORG_RECORD {
    unsigned char name[20];
    UNSIGNED_INT where;
    UNSIGNED_INT strength;
    UNSIGNED_INT scale;
    unsigned char known;
    unsigned char field_1b;
    unsigned char nationality;
    unsigned char field_1d[7];
};

/* one of the sixteen organisation records, read straight out of WORLDn.DTA.
 * One save section
 */
struct ORG_STATE {
    char short_name[6];      /* the short form, which an intercept line puts after the article */
    char long_name[20];      /* the name in full: Local Contact, CIA, Marxists */
    INT where;               /* the map position, each coordinate packed to a nibble; signed, as the shipped code divides it */
    INT strength;            /* what the city's rank is multiplied by for the organisation's presence there */
    INT scale;               /* what that presence is divided by */
    INT known;               /* what the player has learnt about it. In WORLDn.DTA the meaning is different */
    char nationality;        /* where its people's names start in shd_first_names and shd_last_names: sixteen entries from nationality * 2 */
    unsigned char field_23;  /* unused, and zero in every WORLDn.DTA */
};

/* the table the set-palette entry loads: sixteen palette registers and the
 * border, as INT 10h AX=1002h takes them
 */
struct PALETTE {
    unsigned char col_0;   /* palette register 0 */
    unsigned char col_1;   /* palette register 1 */
    unsigned char col_2;   /* palette register 2 */
    unsigned char col_3;   /* palette register 3 */
    unsigned char col_4;   /* palette register 4 */
    unsigned char col_5;   /* palette register 5 */
    unsigned char col_6;   /* palette register 6 */
    unsigned char col_7;   /* palette register 7 */
    unsigned char col_8;   /* palette register 8 */
    unsigned char col_9;   /* palette register 9 */
    unsigned char col_10;  /* palette register 10 */
    unsigned char col_11;  /* palette register 11 */
    unsigned char col_12;  /* palette register 12 */
    unsigned char col_13;  /* palette register 13 */
    unsigned char col_14;  /* palette register 14 */
    unsigned char col_15;  /* palette register 15 */
    unsigned char border;  /* the border, the overscan register */
};

/* one of TAC's nine people on the floor, record 0 the player, whose own
 * state is copied into it
 */
struct PERSON {
    INT flags;           /* the flag word: 80h not yet on the floor, 1 heading through a doorway, 2 and 4 change how they are drawn, 8 hidden from view */
    INT x;               /* where they stand, across */
    INT y;               /* where they stand, down */
    INT field_6;         /* used by the patrol, starting at -1 */
    INT field_8;         /* used by the patrol */
    INT kind;            /* the sprite column the person is drawn from: 0 at first, 4 while alert, 7 while flag 4 is set */
    INT facing;          /* which of the eight ways they are turned, and the sprite row they are drawn from */
    INT last_move_type;  /* for the player asm_last_move_type, 0 for everyone else; never read */
    INT shot_timer;      /* set to shoot, it counts down as the person is drawn and the shot goes off at 1 */
    INT room;            /* which room they are in */
    INT field_14;        /* used by the patrol, starting at 0 */
    INT alert;           /* how hard they are looking */
    INT field_18;        /* counted up each patrol step and cleared otherwise, the largest becoming asm_seen_longest */
    INT stun;            /* how far out of action: over 20h a guard slumps, from 3e7h he is out cold, and 270fh is for good */
};

/* a place on the screen */
struct POINT {
    INT x;  /* across */
    INT y;  /* down */
};

/* a window into a screen: the boundaries it clips to and addresses relative
 * to, the pens it draws in and the font it writes with. Every C-callable
 * drawing routine takes one
 */
struct RASTPORT {
    INT page;       /* which graphics page the window is on */
    INT origin_x;   /* added to every x, so a window addresses relatively */
    INT origin_y;   /* and to every y */
    INT clip_x;     /* the clip boundary, 319 in every RASTPORT in the game */
    INT clip_y;     /* and 199 */
    INT draw_mode;  /* 0 while trimmed text is written and 1 after */
    INT fg_pen;     /* the pen text is drawn in */
    INT bg_pen;     /* the other pen */
    INT font;       /* which font text is written with */
};

/* a rectangle by its corners, inclusive, so its width is x2 - x1 + 1 */
struct RECT {
    INT x1;  /* the left edge */
    INT y1;  /* the top edge */
    INT x2;  /* the right edge */
    INT y2;  /* the bottom edge */
};

/* one of the case's 32 role scan states, indexed as the crime roles are: what
 * a scan needs to turn up clues about the role. One save section
 */
struct ROLE_SCAN_STATE {
    INT clue_visible_since;  /* the case tick from which scans build clue_visibility for the role, -1 for never so far */
    INT clue_visibility;     /* how visible the role has become to scans: zeroed at placement, halved when a fact is lost */
    INT unused_4;            /* unused, but kept in every save */
};

/* one of TAC's 24 room records, 1 to asm_room_count; record 0 is the street
 * outside
 */
struct ROOM {
    char left;                 /* the column of the room's top left cell */
    char top;                  /* the row of that cell */
    char width;                /* how many cells across, 10 at most */
    char height;               /* how many cells down, 10 at most */
    UNSIGNED_LONG neighbours;  /* one bit per room a doorway leads to, 1 << room, read as a signed long */
    char flags;                /* 1 seen only on rooms at distance -1; 2 once the player has been in the room; 4 once a bug is planted in it; 8 and 10h are set and tested as the player moves */
    unsigned char field_9;
    INT kind;                  /* what the room is, an index into dat_room_kinds */
    INT distance;              /* how many rooms lie between this one and the room last measured from: -1 where it cannot be reached, and 999 for the street */
};

/* one of TAC's ten kinds of room, record i for a ROOM.kind of i */
struct ROOM_KIND {
    char name[16];  /* what the panel calls it */
    INT score;      /* what a bug or a photo in such a room adds to the score */
    INT field_12;   /* a mask furnishing tests against a bit it picks */
    INT field_14;   /* a mask furnishing tests against dat_room_mask */
};

/* the seven words an animation sequence is described by: the one a screen
 * runs in the background, or one played full-screen to its end
 */
struct SEQ_BLOCK {
    str_addr name;          /* the animation file */
    UNSIGNED_INT spare;     /* left to whatever set it last */
    UNSIGNED_INT picture;   /* the picture, -1 to keep the current one */
    UNSIGNED_INT duration;  /* in ticks, -1 for the whole animation */
    UNSIGNED_INT page_a;    /* the pages' origin x, -1 to leave it */
    UNSIGNED_INT page_b;    /* the pages' origin y, -1 to leave it */
    UNSIGNED_INT rate;      /* ticks per frame, -1 for the file's */
};

/* one of the 80 clues the player has turned up, kept packed. One save section
 */
struct SHOWN_CLUE {
    char org;                    /* the organisation the clue came from, an index into shm_orgs; over 1 means the wire, and the hotel gives 0 */
    char city;                   /* the city the clue came from, an index into shm_cities */
    INT role;                    /* the crime role the clue is about, an index into shm_crime_roles, -1 where the record is free */
    INT subject;                 /* what the clue tells: the fact's bit in the high byte, as CLUEFACT.H names it, and in the low byte the suspect, organisation, city or role it names */
    INT text;                    /* what the clue reads like: the role's clue_type in the high byte and its clue_id, halved, in the low */
    unsigned char unused_08[4];  /* unused, but moved and saved with the record */
};

/* the two ends of the street along one side of a CHASE block on one axis,
 * as offsets within the 8-pixel block; one per facing
 */
struct STREET_SPAN {
    INT from;  /* the first end */
    INT to;    /* the second end */
};

/* one of the 64 suspect records; a free record is org -1 with visuals 0. One
 * save section
 */
struct SUSPECT {
    INT org;          /* the organisation the person belongs to, an index into shm_orgs, -1 where the record is free */
    INT visuals;      /* the whole person in one random word, zero in a free record: as a portrait, bit 0 the sprite bank and the rest the face parts; as an identity, bit 0 the gender, 1-4 the first name and 5-8 the surname */
    INT city;         /* the city the person works from, an index into shm_cities, -1 where the record is free */
    INT flags;        /* the evidence on the person, one bit per fact the player has learnt, and a few for what has happened to the suspect; SUSPFLAG.H names them */
    INT role;         /* one bit per crime role this person fills; bit 15 marks a record reserved for a red herring */
    INT role_known;   /* the bits of `role` the player has learnt, one Role: line each in the dossier */
    INT score;        /* what the record is worth: a scan stops adding evidence once the facts, at 25 apiece, reach this */
    INT alert_level;  /* how alert the person is; negative is out of play, with ALERTLVL.H's names */
};

/* the word view of REGS */
struct WORDREGS {
    UNSIGNED_INT ax;
    UNSIGNED_INT bx;
    UNSIGNED_INT cx;
    UNSIGNED_INT dx;
    UNSIGNED_INT si;
    UNSIGNED_INT di;
    UNSIGNED_INT cflag;
};

/* the register block int86 takes: MSC declares the same fourteen bytes as
 * seven words or as eight bytes
 */
union REGS {
    struct WORDREGS x;  /* the words */
    struct BYTEREGS h;  /* the bytes AX..DX are made of */
};

#endif /* STRUCTS_H */
