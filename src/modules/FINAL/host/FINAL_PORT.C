#ifdef PORT_MODERN
#include "FINAL_PORT.H"

unsigned char dat_str_env_sve[8] = "env.sve";
unsigned char dat_str_move_joystick_upper[54] =
    "Move JOYSTICK to\nupper-left corner\nand press button.\n";
unsigned char dat_str_move_joystick_lower[55] =
    "Move JOYSTICK to\nlower-right corner\nand press button.\n";
unsigned char dat_str_labs_pic[9] = "labs.pic";
unsigned char dat_str_env_sve_2[8] = "env.sve";
unsigned char dat_str_title2_pan[11] = "title2.pan";
unsigned char dat_str_credits_pan[12] = "credits.pan";
unsigned char dat_str_do_want_create_new[101] =
    "Do you want to...\n Create a New Character\n Load a Saved Game\n Practice"
    " a skill\n Review Hall of Fame\n";
unsigned char dat_str_env_sve_3[8] = "env.sve";
unsigned char dat_str_env_sve_4[8] = "env.sve";
struct SUSPECT shm_suspects[64];
struct BUILDING shm_buildings[256];
struct SHOWN_CLUE shm_clues_shown[80];
UNSIGNED_INT shm_jailbreak_suspect = 0xffff;
struct RASTPORT dat_map_page_port = { 1, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *shd_map_page = (struct RASTPORT *) &dat_map_page_port;
struct COLOUR_MAP dat_colours_title = {
    0x00,
    0x00,
    0x01,
    0x00,
    0x02,
    0x00,
    0x00,
    0x02,
    0x00,
    0x01,
    0x03,
    0x01,
    0x02,
    0x01,
    0x00,
    0x03,
};
struct COLOUR_MAP dat_colours_title_2 = {
    0x00,
    0x01,
    0x11,
    0x11,
    0x02,
    0x00,
    0x02,
    0x03,
    0x30,
    0x11,
    0x13,
    0x31,
    0x22,
    0x23,
    0x33,
    0x33,
};
struct COLOUR_MAP shd_colours_screen = {
    0x00,
    0x00,
    0x01,
    0x00,
    0x02,
    0x00,
    0x00,
    0x02,
    0x00,
    0x01,
    0x02,
    0x03,
    0x02,
    0x01,
    0x01,
    0x03,
};
struct COLOUR_MAP shd_colours_screen_2 = {
    0x00,
    0x00,
    0x11,
    0x11,
    0x22,
    0x00,
    0x00,
    0x22,
    0x00,
    0x22,
    0x33,
    0x33,
    0x22,
    0x11,
    0x22,
    0x33,
};
struct COLOUR_MAP dat_colours_report = {
    0x00,
    0x12,
    0x11,
    0x10,
    0x11,
    0x00,
    0x12,
    0x33,
    0x22,
    0x13,
    0x33,
    0x11,
    0x33,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_main = {
    0x00,
    0x12,
    0x00,
    0x00,
    0x22,
    0x00,
    0x00,
    0x13,
    0x02,
    0x11,
    0x00,
    0x00,
    0x00,
    0x00,
    0x33,
    0x33,
};
struct COLOUR_MAP shd_colours_face = {
    0x00,
    0x11,
    0x11,
    0x01,
    0x22,
    0x00,
    0x22,
    0x22,
    0x00,
    0x11,
    0x11,
    0x33,
    0x33,
    0x33,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_badge = {
    0x00,
    0x00,
    0x11,
    0x11,
    0x22,
    0x00,
    0x00,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
    0x22,
    0x11,
    0x22,
    0x33,
};
struct COLOUR_MAP dat_colours_grid = {
    0x00,
    0x00,
    0x11,
    0x11,
    0x22,
    0x00,
    0x00,
    0x22,
    0x00,
    0x22,
    0x33,
    0x33,
    0x22,
    0x11,
    0x22,
    0x33,
};
struct PALETTE dat_palette_title = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
UNSIGNED_INT shd_pan_disk = 0x0001;
unsigned char dat_str_animation_pan[14] = "animation.pan";
unsigned char dat_str_env_sve_5[8] = "env.sve";
unsigned char dat_str_empty_15;
unsigned char dat_str_sloc00[8] = "*SLOC00";
unsigned char dat_str_text_dta[9] = "text.dta";
unsigned char dat_str_rloc00[8] = "*RLOC00";
unsigned char dat_str_text_dta_2[9] = "text.dta";
unsigned char dat_str_sorg00[8] = "*SORG00";
unsigned char dat_str_text_dta_3[9] = "text.dta";
unsigned char dat_str_rorg00[8] = "*RORG00";
unsigned char dat_str_text_dta_4[9] = "text.dta";
unsigned char dat_str_fluf00[8] = "*FLUF00";
unsigned char dat_str_text_dta_5[9] = "text.dta";
unsigned char dat_str_set00_mission0_where[15] = "the US Embassy";
unsigned char dat_str_set00_mission0_what[23] = "a top secret code book";
unsigned char dat_str_set00_mission1_where[1];
unsigned char dat_str_set00_mission1_what[1];
unsigned char dat_str_set00_mission2_where[1];
unsigned char dat_str_set00_mission2_what[1];
unsigned char dat_str_set00_mission3_where[1];
unsigned char dat_str_set00_mission3_what[1];
unsigned char dat_str_set00_mission4_where[1];
unsigned char dat_str_set00_mission4_what[1];
unsigned char dat_str_set00_mission5_where[1];
unsigned char dat_str_set00_mission5_what[1];
unsigned char dat_str_set00_mission6_where[1];
unsigned char dat_str_set00_mission6_what[1];
unsigned char dat_str_set00_mission7_where[1];
unsigned char dat_str_set00_mission7_what[1];
unsigned char dat_str_set01_mission0_where[31] =
    "sattelite expert Xavier Rayban";
unsigned char dat_str_set01_mission0_what[1];
unsigned char dat_str_set01_mission1_where[26] = "the uplink ground station";
unsigned char dat_str_set01_mission1_what[1];
unsigned char dat_str_set01_mission2_where[12] = "CIA storage";
unsigned char dat_str_set01_mission2_what[25] = "X-Band radio transmitter";
unsigned char dat_str_set01_mission3_where[1];
unsigned char dat_str_set01_mission3_what[1];
unsigned char dat_str_set01_mission4_where[1];
unsigned char dat_str_set01_mission4_what[1];
unsigned char dat_str_set01_mission5_where[1];
unsigned char dat_str_set01_mission5_what[1];
unsigned char dat_str_set01_mission6_where[1];
unsigned char dat_str_set01_mission6_what[1];
unsigned char dat_str_set01_mission7_where[1];
unsigned char dat_str_set01_mission7_what[1];
unsigned char dat_str_set02_mission0_where[32] =
    "the Freedom Games security plan";
unsigned char dat_str_set02_mission0_what[1];
unsigned char dat_str_set02_mission1_where[27] = "an Israeli security expert";
unsigned char dat_str_set02_mission1_what[1];
unsigned char dat_str_set02_mission2_where[31] =
    "the Israeli athletic dormitory";
unsigned char dat_str_set02_mission2_what[1];
unsigned char dat_str_set02_mission3_where[1];
unsigned char dat_str_set02_mission3_what[1];
unsigned char dat_str_set02_mission4_where[1];
unsigned char dat_str_set02_mission4_what[1];
unsigned char dat_str_set02_mission5_where[1];
unsigned char dat_str_set02_mission5_what[1];
unsigned char dat_str_set02_mission6_where[1];
unsigned char dat_str_set02_mission6_what[1];
unsigned char dat_str_set02_mission7_where[1];
unsigned char dat_str_set02_mission7_what[1];
unsigned char dat_str_set03_mission0_where[29] =
    "the noted chemist Dr Pasture";
unsigned char dat_str_set03_mission0_what[1];
unsigned char dat_str_set03_mission1_where[29] =
    "a large industrial warehouse";
unsigned char dat_str_set03_mission1_what[10] = "chemicals";
unsigned char dat_str_set03_mission2_where[15] = "new super drug";
unsigned char dat_str_set03_mission2_what[1];
unsigned char dat_str_set03_mission3_where[1];
unsigned char dat_str_set03_mission3_what[1];
unsigned char dat_str_set03_mission4_where[1];
unsigned char dat_str_set03_mission4_what[1];
unsigned char dat_str_set03_mission5_where[1];
unsigned char dat_str_set03_mission5_what[1];
unsigned char dat_str_set03_mission6_where[1];
unsigned char dat_str_set03_mission6_what[1];
unsigned char dat_str_set03_mission7_where[1];
unsigned char dat_str_set03_mission7_what[1];
unsigned char dat_str_set04_mission0_where[16] = "Geraldo Corazon";
unsigned char dat_str_set04_mission0_what[1];
unsigned char dat_str_set04_mission1_where[27] = "the Election Commission HQ";
unsigned char dat_str_set04_mission1_what[1];
unsigned char dat_str_set04_mission2_where[35] =
    "the Social Democrat campaign rally";
unsigned char dat_str_set04_mission2_what[1];
unsigned char dat_str_set04_mission3_where[1];
unsigned char dat_str_set04_mission3_what[1];
unsigned char dat_str_set04_mission4_where[1];
unsigned char dat_str_set04_mission4_what[1];
unsigned char dat_str_set04_mission5_where[1];
unsigned char dat_str_set04_mission5_what[1];
unsigned char dat_str_set04_mission6_where[1];
unsigned char dat_str_set04_mission6_what[1];
unsigned char dat_str_set04_mission7_where[1];
unsigned char dat_str_set04_mission7_what[1];
unsigned char dat_str_set05_mission0_where[17] = "Carlos the Hyena";
unsigned char dat_str_set05_mission0_what[1];
unsigned char dat_str_set05_mission1_where[20] = "summit ID Documents";
unsigned char dat_str_set05_mission1_what[1];
unsigned char dat_str_set05_mission2_where[24] = "a leading Head of State";
unsigned char dat_str_set05_mission2_what[1];
unsigned char dat_str_set05_mission3_where[1];
unsigned char dat_str_set05_mission3_what[1];
unsigned char dat_str_set05_mission4_where[1];
unsigned char dat_str_set05_mission4_what[1];
unsigned char dat_str_set05_mission5_where[1];
unsigned char dat_str_set05_mission5_what[1];
unsigned char dat_str_set05_mission6_where[1];
unsigned char dat_str_set05_mission6_what[1];
unsigned char dat_str_set05_mission7_where[1];
unsigned char dat_str_set05_mission7_what[1];
unsigned char dat_str_set06_mission0_where[15] = "Willie the Pen";
unsigned char dat_str_set06_mission0_what[1];
unsigned char dat_str_set06_mission1_where[22] = "the Treasury Building";
unsigned char dat_str_set06_mission1_what[16] = "Currency Plates";
unsigned char dat_str_set06_mission2_where[29] =
    "medium denomination currency";
unsigned char dat_str_set06_mission2_what[15] = "currency paper";
unsigned char dat_str_set06_mission3_where[1];
unsigned char dat_str_set06_mission3_what[1];
unsigned char dat_str_set06_mission4_where[1];
unsigned char dat_str_set06_mission4_what[1];
unsigned char dat_str_set06_mission5_where[1];
unsigned char dat_str_set06_mission5_what[1];
unsigned char dat_str_set06_mission6_where[1];
unsigned char dat_str_set06_mission6_what[1];
unsigned char dat_str_set06_mission7_where[1];
unsigned char dat_str_set06_mission7_what[1];
unsigned char dat_str_set07_mission0_where[18] = "AirBase Passwords";
unsigned char dat_str_set07_mission0_what[1];
unsigned char dat_str_set07_mission1_where[17] = "AirBase ID Cards";
unsigned char dat_str_set07_mission1_what[1];
unsigned char dat_str_set07_mission2_where[11] = "an AirBase";
unsigned char dat_str_set07_mission2_what[15] = "a Nuclear Bomb";
unsigned char dat_str_set07_mission3_where[1];
unsigned char dat_str_set07_mission3_what[1];
unsigned char dat_str_set07_mission4_where[1];
unsigned char dat_str_set07_mission4_what[1];
unsigned char dat_str_set07_mission5_where[1];
unsigned char dat_str_set07_mission5_what[1];
unsigned char dat_str_set07_mission6_where[1];
unsigned char dat_str_set07_mission6_what[1];
unsigned char dat_str_set07_mission7_where[1];
unsigned char dat_str_set07_mission7_what[1];
unsigned char dat_str_set08_mission0_where[17] = "a chemical plant";
unsigned char dat_str_set08_mission0_what[22] = "explosive propellants";
unsigned char dat_str_set08_mission1_where[16] = "a metal foundry";
unsigned char dat_str_set08_mission1_what[20] = "high-strength tubes";
unsigned char dat_str_set08_mission2_where[17] = "the super cannon";
unsigned char dat_str_set08_mission2_what[16] = "precision lathe";
unsigned char dat_str_set08_mission3_where[1];
unsigned char dat_str_set08_mission3_what[1];
unsigned char dat_str_set08_mission4_where[1];
unsigned char dat_str_set08_mission4_what[1];
unsigned char dat_str_set08_mission5_where[1];
unsigned char dat_str_set08_mission5_what[1];
unsigned char dat_str_set08_mission6_where[1];
unsigned char dat_str_set08_mission6_what[1];
unsigned char dat_str_set08_mission7_where[1];
unsigned char dat_str_set08_mission7_what[1];
unsigned char dat_str_set09_mission0_where[18] = "a breeder reactor";
unsigned char dat_str_set09_mission0_what[14] = "plutonium 235";
unsigned char dat_str_set09_mission1_where[25] = "physicist Dr A. Einstone";
unsigned char dat_str_set09_mission1_what[1];
unsigned char dat_str_set09_mission2_where[15] = "a nuclear bomb";
unsigned char dat_str_set09_mission2_what[20] = "imploding detonator";
unsigned char dat_str_set09_mission3_where[1];
unsigned char dat_str_set09_mission3_what[1];
unsigned char dat_str_set09_mission4_where[1];
unsigned char dat_str_set09_mission4_what[1];
unsigned char dat_str_set09_mission5_where[1];
unsigned char dat_str_set09_mission5_what[1];
unsigned char dat_str_set09_mission6_where[1];
unsigned char dat_str_set09_mission6_what[1];
unsigned char dat_str_set09_mission7_where[1];
unsigned char dat_str_set09_mission7_what[1];
unsigned char dat_str_set10_mission0_where[14] = "train station";
unsigned char dat_str_set10_mission0_what[1];
unsigned char dat_str_set10_mission1_where[25] = "the Veteran's Day parade";
unsigned char dat_str_set10_mission1_what[1];
unsigned char dat_str_set10_mission2_where[24] = "a Supreme Court Justice";
unsigned char dat_str_set10_mission2_what[1];
unsigned char dat_str_set10_mission3_where[1];
unsigned char dat_str_set10_mission3_what[1];
unsigned char dat_str_set10_mission4_where[1];
unsigned char dat_str_set10_mission4_what[1];
unsigned char dat_str_set10_mission5_where[1];
unsigned char dat_str_set10_mission5_what[1];
unsigned char dat_str_set10_mission6_where[1];
unsigned char dat_str_set10_mission6_what[1];
unsigned char dat_str_set10_mission7_where[1];
unsigned char dat_str_set10_mission7_what[1];
unsigned char dat_str_set11_mission0_where[26] = "bacteriologist Edgar Coli";
unsigned char dat_str_set11_mission0_what[1];
unsigned char dat_str_set11_mission1_where[20] = "the medical college";
unsigned char dat_str_set11_mission1_what[23] = "virulent virus samples";
unsigned char dat_str_set11_mission2_where[15] = "deadly virus X";
unsigned char dat_str_set11_mission2_what[25] = "one million Petri dishes";
unsigned char dat_str_set11_mission3_where[1];
unsigned char dat_str_set11_mission3_what[1];
unsigned char dat_str_set11_mission4_where[1];
unsigned char dat_str_set11_mission4_what[1];
unsigned char dat_str_set11_mission5_where[1];
unsigned char dat_str_set11_mission5_what[1];
unsigned char dat_str_set11_mission6_where[1];
unsigned char dat_str_set11_mission6_what[1];
unsigned char dat_str_set11_mission7_where[1];
unsigned char dat_str_set11_mission7_what[1];
unsigned char dat_str_set12_mission0_where[22] = "InterPol Headquarters";
unsigned char dat_str_set12_mission0_what[1];
unsigned char dat_str_set12_mission1_where[24] = "chief drug investigator";
unsigned char dat_str_set12_mission1_what[1];
unsigned char dat_str_set12_mission2_where[1];
unsigned char dat_str_set12_mission2_what[1];
unsigned char dat_str_set12_mission3_where[1];
unsigned char dat_str_set12_mission3_what[1];
unsigned char dat_str_set12_mission4_where[1];
unsigned char dat_str_set12_mission4_what[1];
unsigned char dat_str_set12_mission5_where[1];
unsigned char dat_str_set12_mission5_what[1];
unsigned char dat_str_set12_mission6_where[1];
unsigned char dat_str_set12_mission6_what[1];
unsigned char dat_str_set12_mission7_where[1];
unsigned char dat_str_set12_mission7_what[1];
unsigned char dat_str_set13_mission0_where[21] = "VIP travel itinerary";
unsigned char dat_str_set13_mission0_what[1];
unsigned char dat_str_set13_mission1_where[21] = "the locomotive plant";
unsigned char dat_str_set13_mission1_what[17] = "train schematics";
unsigned char dat_str_set13_mission2_where[18] = "the train station";
unsigned char dat_str_set13_mission2_what[1];
unsigned char dat_str_set13_mission3_where[1];
unsigned char dat_str_set13_mission3_what[1];
unsigned char dat_str_set13_mission4_where[1];
unsigned char dat_str_set13_mission4_what[1];
unsigned char dat_str_set13_mission5_where[1];
unsigned char dat_str_set13_mission5_what[1];
unsigned char dat_str_set13_mission6_where[1];
unsigned char dat_str_set13_mission6_what[1];
unsigned char dat_str_set13_mission7_where[1];
unsigned char dat_str_set13_mission7_what[1];
unsigned char dat_str_set14_mission0_where[20] = "prison visitor pass";
unsigned char dat_str_set14_mission0_what[1];
unsigned char dat_str_set14_mission1_where[18] = "the prison warden";
unsigned char dat_str_set14_mission1_what[1];
unsigned char dat_str_set14_mission2_where[14] = "Manny Noriega";
unsigned char dat_str_set14_mission2_what[1];
unsigned char dat_str_set14_mission3_where[1];
unsigned char dat_str_set14_mission3_what[1];
unsigned char dat_str_set14_mission4_where[1];
unsigned char dat_str_set14_mission4_what[1];
unsigned char dat_str_set14_mission5_where[1];
unsigned char dat_str_set14_mission5_what[1];
unsigned char dat_str_set14_mission6_where[1];
unsigned char dat_str_set14_mission6_what[1];
unsigned char dat_str_set14_mission7_where[1];
unsigned char dat_str_set14_mission7_what[1];
unsigned char dat_str_set15_mission0_where[14] = "fighter pilot";
unsigned char dat_str_set15_mission0_what[1];
unsigned char dat_str_set15_mission1_where[24] = "airbase operation plans";
unsigned char dat_str_set15_mission1_what[1];
unsigned char dat_str_set15_mission2_where[18] = "the secret hangar";
unsigned char dat_str_set15_mission2_what[16] = "stealth fighter";
unsigned char dat_str_set15_mission3_where[1];
unsigned char dat_str_set15_mission3_what[1];
unsigned char dat_str_set15_mission4_where[1];
unsigned char dat_str_set15_mission4_what[1];
unsigned char dat_str_set15_mission5_where[1];
unsigned char dat_str_set15_mission5_what[1];
unsigned char dat_str_set15_mission6_where[1];
unsigned char dat_str_set15_mission6_what[1];
unsigned char dat_str_set15_mission7_where[1];
unsigned char dat_str_set15_mission7_what[1];
unsigned char dat_str_gender_pic[11] = "gender.pic";
unsigned char dat_str_select_one_maximillian[56] =
    "Select one...\n Maximillian Remington\n Maxine Remington\n";
unsigned char dat_str_which_difficulty_level[95] =
    "Which difficulty level?\n Local Disturbance\n National Threat\n Regional "
    "Conflict\n Global Crisis\n";
INT dat_org_table[26][8] = {
    { 0x0000, 0x0001, 0x0002, 0x0002, 0x0002, 0x0002, 0x0003, 0x0001 },
    { 0x0000, 0x0000, 0x0003, 0x0003, 0x0003, 0x0003, 0x0001, 0x0002 },
    { 0x0000, 0x0001, 0x0005, 0x0003, 0x0004, 0x0006, 0x0000, 0x0003 },
    { 0x0000, 0x0000, 0x0008, 0x0004, 0x0006, 0x0001, 0x0003, 0x0001 },
    { 0x0000, 0x0001, 0x0005, 0x0005, 0x0005, 0x0005, 0x0000, 0x0000 },
    { 0x0000, 0x0001, 0x0006, 0x0006, 0x0006, 0x0006, 0x0003, 0x0002 },
    { 0x0000, 0x0001, 0x0004, 0x0008, 0x0005, 0x0002, 0x0003, 0x0001 },
    { 0x0000, 0x0001, 0x0007, 0x0007, 0x0008, 0x0007, 0x0001, 0x0003 },
    { 0x0000, 0x0001, 0x0001, 0x0002, 0x0003, 0x0007, 0x0002, 0x0001 },
    { 0x0000, 0x0001, 0x0003, 0x0001, 0x0008, 0x0005, 0x0003, 0x0003 },
    { 0x0000, 0x0001, 0x0002, 0x0002, 0x0002, 0x0003, 0x0003, 0x0000 },
    { 0x0000, 0x0000, 0x0003, 0x0003, 0x0003, 0x0001, 0x0002, 0x0001 },
    { 0x0000, 0x0001, 0x0004, 0x0008, 0x0005, 0x0003, 0x0003, 0x0002 },
    { 0x0000, 0x0000, 0x0008, 0x0004, 0x0006, 0x0005, 0x0003, 0x0003 },
    { 0x0000, 0x0001, 0x0007, 0x0007, 0x0008, 0x0008, 0x0000, 0x0000 },
    { 0x0000, 0x0001, 0x0006, 0x0006, 0x0006, 0x0008, 0x0003, 0x0003 },
    { 0x0001, 0x0000, 0x0002, 0x0002, 0x0002, 0x0002, 0x0003, 0x0002 },
    { 0x0001, 0x0000, 0x0004, 0x0004, 0x0004, 0x0004, 0x0001, 0x0003 },
    { 0x0001, 0x0000, 0x0007, 0x0001, 0x0008, 0x0005, 0x0000, 0x0003 },
    { 0x0001, 0x0000, 0x0008, 0x0005, 0x0003, 0x0007, 0x0003, 0x0003 },
    { 0x0001, 0x0001, 0x0001, 0x0008, 0x0004, 0x0002, 0x0001, 0x0002 },
    { 0x0001, 0x0001, 0x0004, 0x0007, 0x0002, 0x0001, 0x0000, 0x0002 },
    { 0x0001, 0x0001, 0x0005, 0x0002, 0x0006, 0x0003, 0x0000, 0x0000 },
    { 0x0001, 0x0001, 0x0005, 0x0005, 0x0005, 0x0005, 0x0003, 0x0000 },
    { 0x0001, 0x0000, 0x0005, 0x0003, 0x0001, 0x0006, 0x0003, 0x0001 },
    { 0x0001, 0x0000, 0x0002, 0x0006, 0x0007, 0x0008, 0x0000, 0x0000 },
};
struct MISSION_SET dat_mission_sets[16] = {
    {
        "Welcome Max",
        0x0f00,
        { 1, -1, -1, -1, -1, -1, -1, -1 },
        {
            { dat_str_set00_mission0_where, dat_str_set00_mission0_what },
            { dat_str_set00_mission1_where, dat_str_set00_mission1_what },
            { dat_str_set00_mission2_where, dat_str_set00_mission2_what },
            { dat_str_set00_mission3_where, dat_str_set00_mission3_what },
            { dat_str_set00_mission4_where, dat_str_set00_mission4_what },
            { dat_str_set00_mission5_where, dat_str_set00_mission5_what },
            { dat_str_set00_mission6_where, dat_str_set00_mission6_what },
            { dat_str_set00_mission7_where, dat_str_set00_mission7_what },
        },
    },
    {
        "'KeyHole' Sattelite",
        0x0900,
        { 0, 6, 4, -1, -1, -1, -1, 1 },
        {
            { dat_str_set01_mission0_where, dat_str_set01_mission0_what },
            { dat_str_set01_mission1_where, dat_str_set01_mission1_what },
            { dat_str_set01_mission2_where, dat_str_set01_mission2_what },
            { dat_str_set01_mission3_where, dat_str_set01_mission3_what },
            { dat_str_set01_mission4_where, dat_str_set01_mission4_what },
            { dat_str_set01_mission5_where, dat_str_set01_mission5_what },
            { dat_str_set01_mission6_where, dat_str_set01_mission6_what },
            { dat_str_set01_mission7_where, dat_str_set01_mission7_what },
        },
    },
    {
        "Freedom Games",
        0x0c00,
        { 7, 2, 6, -1, -1, -1, -1, 1 },
        {
            { dat_str_set02_mission0_where, dat_str_set02_mission0_what },
            { dat_str_set02_mission1_where, dat_str_set02_mission1_what },
            { dat_str_set02_mission2_where, dat_str_set02_mission2_what },
            { dat_str_set02_mission3_where, dat_str_set02_mission3_what },
            { dat_str_set02_mission4_where, dat_str_set02_mission4_what },
            { dat_str_set02_mission5_where, dat_str_set02_mission5_what },
            { dat_str_set02_mission6_where, dat_str_set02_mission6_what },
            { dat_str_set02_mission7_where, dat_str_set02_mission7_what },
        },
    },
    {
        "SuperDrug",
        0x0600,
        { 0, 4, 3, -1, -1, -1, -1, 1 },
        {
            { dat_str_set03_mission0_where, dat_str_set03_mission0_what },
            { dat_str_set03_mission1_where, dat_str_set03_mission1_what },
            { dat_str_set03_mission2_where, dat_str_set03_mission2_what },
            { dat_str_set03_mission3_where, dat_str_set03_mission3_what },
            { dat_str_set03_mission4_where, dat_str_set03_mission4_what },
            { dat_str_set03_mission5_where, dat_str_set03_mission5_what },
            { dat_str_set03_mission6_where, dat_str_set03_mission6_what },
            { dat_str_set03_mission7_where, dat_str_set03_mission7_what },
        },
    },
    {
        "Liberian Election",
        0x0900,
        { 11, 6, 8, -1, -1, -1, -1, 1 },
        {
            { dat_str_set04_mission0_where, dat_str_set04_mission0_what },
            { dat_str_set04_mission1_where, dat_str_set04_mission1_what },
            { dat_str_set04_mission2_where, dat_str_set04_mission2_what },
            { dat_str_set04_mission3_where, dat_str_set04_mission3_what },
            { dat_str_set04_mission4_where, dat_str_set04_mission4_what },
            { dat_str_set04_mission5_where, dat_str_set04_mission5_what },
            { dat_str_set04_mission6_where, dat_str_set04_mission6_what },
            { dat_str_set04_mission7_where, dat_str_set04_mission7_what },
        },
    },
    {
        "Summit Conference",
        0x0c00,
        { 10, 9, 2, -1, -1, -1, -1, 1 },
        {
            { dat_str_set05_mission0_where, dat_str_set05_mission0_what },
            { dat_str_set05_mission1_where, dat_str_set05_mission1_what },
            { dat_str_set05_mission2_where, dat_str_set05_mission2_what },
            { dat_str_set05_mission3_where, dat_str_set05_mission3_what },
            { dat_str_set05_mission4_where, dat_str_set05_mission4_what },
            { dat_str_set05_mission5_where, dat_str_set05_mission5_what },
            { dat_str_set05_mission6_where, dat_str_set05_mission6_what },
            { dat_str_set05_mission7_where, dat_str_set05_mission7_what },
        },
    },
    {
        "Rampant Inflation",
        0x0a00,
        { 10, 4, 12, -1, -1, -1, -1, 1 },
        {
            { dat_str_set06_mission0_where, dat_str_set06_mission0_what },
            { dat_str_set06_mission1_where, dat_str_set06_mission1_what },
            { dat_str_set06_mission2_where, dat_str_set06_mission2_what },
            { dat_str_set06_mission3_where, dat_str_set06_mission3_what },
            { dat_str_set06_mission4_where, dat_str_set06_mission4_what },
            { dat_str_set06_mission5_where, dat_str_set06_mission5_what },
            { dat_str_set06_mission6_where, dat_str_set06_mission6_what },
            { dat_str_set06_mission7_where, dat_str_set06_mission7_what },
        },
    },
    {
        "Stolen Nuke",
        0x0c00,
        { 7, 9, 4, -1, -1, -1, -1, 1 },
        {
            { dat_str_set07_mission0_where, dat_str_set07_mission0_what },
            { dat_str_set07_mission1_where, dat_str_set07_mission1_what },
            { dat_str_set07_mission2_where, dat_str_set07_mission2_what },
            { dat_str_set07_mission3_where, dat_str_set07_mission3_what },
            { dat_str_set07_mission4_where, dat_str_set07_mission4_what },
            { dat_str_set07_mission5_where, dat_str_set07_mission5_what },
            { dat_str_set07_mission6_where, dat_str_set07_mission6_what },
            { dat_str_set07_mission7_where, dat_str_set07_mission7_what },
        },
    },
    {
        "Super Cannon",
        0x0b00,
        { 4, 4, 12, -1, -1, -1, -1, 1 },
        {
            { dat_str_set08_mission0_where, dat_str_set08_mission0_what },
            { dat_str_set08_mission1_where, dat_str_set08_mission1_what },
            { dat_str_set08_mission2_where, dat_str_set08_mission2_what },
            { dat_str_set08_mission3_where, dat_str_set08_mission3_what },
            { dat_str_set08_mission4_where, dat_str_set08_mission4_what },
            { dat_str_set08_mission5_where, dat_str_set08_mission5_what },
            { dat_str_set08_mission6_where, dat_str_set08_mission6_what },
            { dat_str_set08_mission7_where, dat_str_set08_mission7_what },
        },
    },
    {
        "Build Nuclear Weapon",
        0x0d00,
        { 4, 0, 12, -1, -1, -1, -1, 1 },
        {
            { dat_str_set09_mission0_where, dat_str_set09_mission0_what },
            { dat_str_set09_mission1_where, dat_str_set09_mission1_what },
            { dat_str_set09_mission2_where, dat_str_set09_mission2_what },
            { dat_str_set09_mission3_where, dat_str_set09_mission3_what },
            { dat_str_set09_mission4_where, dat_str_set09_mission4_what },
            { dat_str_set09_mission5_where, dat_str_set09_mission5_what },
            { dat_str_set09_mission6_where, dat_str_set09_mission6_what },
            { dat_str_set09_mission7_where, dat_str_set09_mission7_what },
        },
    },
    {
        "Terror Campaign",
        0x0c00,
        { 6, 8, 2, -1, -1, -1, -1, -1 },
        {
            { dat_str_set10_mission0_where, dat_str_set10_mission0_what },
            { dat_str_set10_mission1_where, dat_str_set10_mission1_what },
            { dat_str_set10_mission2_where, dat_str_set10_mission2_what },
            { dat_str_set10_mission3_where, dat_str_set10_mission3_what },
            { dat_str_set10_mission4_where, dat_str_set10_mission4_what },
            { dat_str_set10_mission5_where, dat_str_set10_mission5_what },
            { dat_str_set10_mission6_where, dat_str_set10_mission6_what },
            { dat_str_set10_mission7_where, dat_str_set10_mission7_what },
        },
    },
    {
        "Virus X",
        0x0c00,
        { 0, 4, 12, -1, -1, -1, -1, -1 },
        {
            { dat_str_set11_mission0_where, dat_str_set11_mission0_what },
            { dat_str_set11_mission1_where, dat_str_set11_mission1_what },
            { dat_str_set11_mission2_where, dat_str_set11_mission2_what },
            { dat_str_set11_mission3_where, dat_str_set11_mission3_what },
            { dat_str_set11_mission4_where, dat_str_set11_mission4_what },
            { dat_str_set11_mission5_where, dat_str_set11_mission5_what },
            { dat_str_set11_mission6_where, dat_str_set11_mission6_what },
            { dat_str_set11_mission7_where, dat_str_set11_mission7_what },
        },
    },
    {
        "Drug Shortage",
        0x0a00,
        { 6, 2, 3, -1, -1, -1, -1, -1 },
        {
            { dat_str_set12_mission0_where, dat_str_set12_mission0_what },
            { dat_str_set12_mission1_where, dat_str_set12_mission1_what },
            { dat_str_set12_mission2_where, dat_str_set12_mission2_what },
            { dat_str_set12_mission3_where, dat_str_set12_mission3_what },
            { dat_str_set12_mission4_where, dat_str_set12_mission4_what },
            { dat_str_set12_mission5_where, dat_str_set12_mission5_what },
            { dat_str_set12_mission6_where, dat_str_set12_mission6_what },
            { dat_str_set12_mission7_where, dat_str_set12_mission7_what },
        },
    },
    {
        "Train Wreck",
        0x0c00,
        { 7, 5, 6, -1, -1, -1, -1, -1 },
        {
            { dat_str_set13_mission0_where, dat_str_set13_mission0_what },
            { dat_str_set13_mission1_where, dat_str_set13_mission1_what },
            { dat_str_set13_mission2_where, dat_str_set13_mission2_what },
            { dat_str_set13_mission3_where, dat_str_set13_mission3_what },
            { dat_str_set13_mission4_where, dat_str_set13_mission4_what },
            { dat_str_set13_mission5_where, dat_str_set13_mission5_what },
            { dat_str_set13_mission6_where, dat_str_set13_mission6_what },
            { dat_str_set13_mission7_where, dat_str_set13_mission7_what },
        },
    },
    {
        "Prison Break",
        0x0700,
        { 9, 11, 10, -1, -1, -1, -1, -1 },
        {
            { dat_str_set14_mission0_where, dat_str_set14_mission0_what },
            { dat_str_set14_mission1_where, dat_str_set14_mission1_what },
            { dat_str_set14_mission2_where, dat_str_set14_mission2_what },
            { dat_str_set14_mission3_where, dat_str_set14_mission3_what },
            { dat_str_set14_mission4_where, dat_str_set14_mission4_what },
            { dat_str_set14_mission5_where, dat_str_set14_mission5_what },
            { dat_str_set14_mission6_where, dat_str_set14_mission6_what },
            { dat_str_set14_mission7_where, dat_str_set14_mission7_what },
        },
    },
    {
        "Stealth Fighter",
        0x0300,
        { 11, 7, 4, -1, -1, -1, -1, -1 },
        {
            { dat_str_set15_mission0_where, dat_str_set15_mission0_what },
            { dat_str_set15_mission1_where, dat_str_set15_mission1_what },
            { dat_str_set15_mission2_where, dat_str_set15_mission2_what },
            { dat_str_set15_mission3_where, dat_str_set15_mission3_what },
            { dat_str_set15_mission4_where, dat_str_set15_mission4_what },
            { dat_str_set15_mission5_where, dat_str_set15_mission5_what },
            { dat_str_set15_mission6_where, dat_str_set15_mission6_what },
            { dat_str_set15_mission7_where, dat_str_set15_mission7_what },
        },
    },
};
unsigned char dat_key_plot_start[8] = "*PL0090";
unsigned char dat_str_briefing_pan[13] = "briefing.pan";
unsigned char dat_str_plot_txt[9] = "plot.txt";
unsigned char dat_str_max_remington_s[26] = "Max Remington's apartment";
unsigned char dat_str_mattress_full_cash[24] = "a mattress full of cash";
unsigned char dat_str_pl000a[8] = "*PL000A";
unsigned char dat_str_pl000a_2[8] = "*PL000a";
unsigned char dat_str_briefing_pan_2[13] = "briefing.pan";
unsigned char dat_str_plot_txt_2[9] = "plot.txt";
unsigned char dat_str_max_s_code_name[20] = "Max's code name is:";
unsigned char dat_str_which_difficulty_level_2[95] =
    "Which difficulty level?\n Local Disturbance\n National Threat\n Regional "
    "Conflict\n Global Crisis\n";
unsigned char dat_str_combat[7] = "Combat";
unsigned char dat_str_driving[8] = "Driving";
unsigned char dat_str_cryptography[13] = "Cryptography";
unsigned char dat_str_electronics[12] = "Electronics";
unsigned char dat_str_stamina[8] = "Stamina";
unsigned char dat_str_training_pic[13] = "training.pic";
unsigned char dat_str_blank[2] = " ";
unsigned char dat_str_practice[12] = " practice\n ";
unsigned char dat_str_training[12] = " training\n ";
unsigned char *dat_skill_names[5] = {
    (unsigned char *) dat_str_combat, (unsigned char *) dat_str_driving,
    (unsigned char *) dat_str_cryptography,
    (unsigned char *) dat_str_electronics, (unsigned char *) dat_str_stamina,
};
unsigned char dat_str_average[8] = "Average";
unsigned char dat_str_good[5] = "Good";
unsigned char dat_str_excellent[10] = "Excellent";
unsigned char dat_str_awesome[9] = "Awesome";
INT dat_skill_colours[4] = {
    0x0004, 0x0009, 0x0008, 0x0002,
};
struct PALETTE dat_palette_badge = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0f,
    0x0e,
    0x0f,
    0x00,
};
unsigned char dat_str_max_i_m_sure[45] =
    "Max, I'm sure you recognize the head of\nthe ";
unsigned char dat_str_among_these_faces[22] = " among these faces.\n";
unsigned char dat_str_briefing_pan_3[13] = "briefing.pan";
unsigned char dat_str_looks_like_about_wraps[44] =
    "It looks like that about wraps it up, Max. ";
unsigned char dat_str_we_ve_been_able[84] =
    "We've been able to put together a pretty good chronology of this case, ta"
    "ke a look.";
unsigned char dat_str_icons_pic[10] = "icons.pic";
unsigned char dat_key_plot_zero[8] = "*PL0000";
unsigned char dat_note_01[13] = "briefing.pan";
unsigned char dat_note_02[9] = "plot.txt";
unsigned char dat_note_03[85] =
    "Interrogation of the suspects has revealed some additional information ab"
    "out Mr.Big.";
unsigned char dat_note_04[50] =
    "You have captured the MasterMind controlling the ";
unsigned char dat_note_05[53] =
    "! The country has been saved from a dangerous plot. ";
unsigned char dat_note_06[46] =
    "Congratulations, the President commends you.\n";
unsigned char dat_note_07[58] =
    "Congratulations Max, we've decided to promote you from 00";
unsigned char dat_note_08[12] = " rank to 00";
unsigned char dat_note_09[49] =
    " rank. Here's a commendation from the President.";
unsigned char dat_note_10[13] = "briefing.pan";
unsigned char dat_note_11[51] =
    "INCREDIBLE: You have\narrested all 26 Masterminds!\n";
unsigned char dat_note_12[52] =
    "You have completed a\nten year career with the CIA.\n";
unsigned char dat_note_13[52] =
    "You retire to a well-\ndeserved life of relaxation.\n";
unsigned char dat_note_14[55] =
    "Do you want to...\n Continue Game\n Save Game\n End Game\n";
unsigned char dat_note_15[26] = " Change Difficulty Level\n";
unsigned char dat_note_16[95] =
    "Which difficulty level?\n Local Disturbance\n National Threat\n Regional "
    "Conflict\n Global Crisis\n";
unsigned char dat_note_17[44] =
    "Do you want to...\n Continue Game\n End Game\n";
unsigned char dat_note_18[14] = "briefing.pan";
struct RASTPORT dat_replay_page_port = { 2, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *asm_replay_page = (struct RASTPORT *) &dat_replay_page_port;
unsigned char asm_plot_key[8] = "*PL0000";
unsigned char dat_str_empty_2[1];
unsigned char dat_str_paren_open[3] = " (";
unsigned char dat_str_paren_close[3] = ") ";
unsigned char dat_str_space[2] = " ";
unsigned char dat_str_slash[2] = "/";
unsigned char dat_str_sent_message[18] = " sent message to ";
unsigned char dat_str_caret[2] = "^";
unsigned char dat_str_caret_2[2] = "^";
unsigned char dat_str_empty_3[1];
unsigned char dat_str_sent_message_2[16] = "sent message to";
unsigned char dat_str_sent_package[16] = "sent package to";
unsigned char dat_str_empty_4[1];
unsigned char dat_str_paren_open_2[3] = " (";
unsigned char dat_str_paren_close_2[3] = ") ";
unsigned char dat_str_slash_2[2] = "/";
unsigned char dat_str_caret_3[2] = "^";
unsigned char dat_str_caret_4[2] = "^";
unsigned char dat_str_paren_open_3[3] = " (";
unsigned char dat_str_paren_close_3[3] = ") ";
unsigned char dat_str_now_has[13] = "now has the ";
unsigned char dat_str_empty_5[1];
unsigned char dat_str_left[7] = " left ";
unsigned char dat_str_traveled[17] = "You traveled to ";
unsigned char dat_str_broke[17] = "You broke in to ";
unsigned char dat_str_slash_3[2] = "/";
unsigned char dat_str_arrested[14] = "You arrested ";
unsigned char dat_str_confiscated[17] = "You confiscated ";
unsigned char dat_str_went_into_hiding[19] = " went into hiding.";
unsigned char dat_str_mission_completed[19] = "Mission completed.";
unsigned char dat_str_unable[10] = "Unable to";
unsigned char dat_str_complete_mission[18] = "complete mission.";
unsigned char dat_str_came_out_hiding[21] = " came out of hiding.";
unsigned char dat_str_escaped_from_jail[20] = " escaped from jail.";
unsigned char dat_str_released_by_exchange[23] = " released by exchange.";
unsigned char dat_str_turned[12] = "You turned ";
unsigned char dat_str_space_2[2] = " ";
unsigned char dat_str_day_number[4] = " 10";
unsigned char dat_date_template[16] = "00:00 AM Jun 00";
unsigned char dat_str_efficiency_report[18] = "Efficiency Report";
unsigned char dat_str_org_sep[3] = ", ";
unsigned char dat_str_org_slash[2] = "/";
unsigned char dat_str_at_large[9] = "At Large";
unsigned char dat_str_arrested_2[9] = "ARRESTED";
unsigned char dat_str_turned_2[7] = "TURNED";
unsigned char dat_str_ep_0[4] = "EP:";
unsigned char dat_str_ep_of[3] = "\211/";
unsigned char dat_str_ep_50[5] = "EP:0";
unsigned char dat_str_confiscated_2[12] = "CONFISCATED";
unsigned char dat_str_ep_50_2[6] = "EP:50";
unsigned char dat_str_not_found[10] = "Not found";
unsigned char dat_str_of_50[5] = "\211/50";
unsigned char dat_str_of_org[2] = " ";
unsigned char dat_str_ep_blank[7] = "EP: 0/";
unsigned char dat_str_prevented_crime[16] = "Prevented crime";
unsigned char dat_str_ep_100[12] = "EP:100\211/100";
unsigned char dat_str_empty_agents[1];
unsigned char dat_str_double_agent_s[17] = " Double Agent(s)";
unsigned char dat_str_remained_undetected[20] = "remained undetected";
unsigned char dat_str_within_cia[16] = "within the CIA.";
unsigned char dat_str_ep_slash[6] = "EP:0/";
unsigned char dat_str_efficiency_rating[18] = "Efficiency Rating";
unsigned char dat_str_dashes[5] = "--- ";
unsigned char dat_str_dashes_end[5] = " ---";
unsigned char dat_str_ep_total[4] = "EP:";
unsigned char dat_str_ep_total_of[3] = "\211/";
unsigned char dat_str_kidnapping[11] = "Kidnapping";
unsigned char dat_str_theft[6] = "Theft";
unsigned char dat_str_assassination[14] = "Assassination";
unsigned char dat_str_drug_smuggle[13] = "Drug Smuggle";
unsigned char dat_str_theft_2[6] = "Theft";
unsigned char dat_str_photo[6] = "Photo";
unsigned char dat_str_bombing[8] = "Bombing";
unsigned char dat_str_datacrime[10] = "DataCrime";
unsigned char dat_str_terrorist_attack[17] = "Terrorist Attack";
unsigned char dat_str_forgery[8] = "Forgery";
unsigned char dat_str_jail_break[11] = "Jail Break";
unsigned char dat_str_blackmail[10] = "Blackmail";
unsigned char dat_str_manufacture[12] = "Manufacture";
unsigned char dat_str_pfo[4] = "PFO";
unsigned char dat_str_m18[4] = "M18";
unsigned char dat_str_jamaican_gang[14] = "Jamaican Gang";
unsigned char dat_str_haitian_junta[14] = "Haitian Junta";
unsigned char dat_str_red_september[14] = "Red September";
unsigned char dat_str_iraqi_sp[9] = "Iraqi SP";
unsigned char dat_str_muslim_jihad[13] = "Muslim Jihad";
unsigned char dat_str_shining_way[12] = "Shining Way";
unsigned char dat_str_tupamaros[10] = "Tupamaros";
unsigned char dat_str_colombian_cartel[17] = "Colombian Cartel";
unsigned char dat_str_mafia[6] = "Mafia";
unsigned char dat_str_libyan_emb[12] = "Libyan Emb.";
unsigned char dat_str_fln[4] = "FLN";
unsigned char dat_str_amazon_cartel[14] = "Amazon Cartel";
unsigned char dat_str_mercenaries[12] = "Mercenaries";
unsigned char dat_str_death_squads[13] = "Death Squads";
unsigned char dat_str_rev_guards[12] = "Rev. Guards";
unsigned char dat_str_unioncorsique[14] = "UnionCorsique";
unsigned char dat_str_pifa[5] = "PIFA";
unsigned char dat_str_red_army[9] = "Red Army";
unsigned char dat_str_red_battalion[14] = "Red Battalion";
unsigned char dat_str_direct_action[14] = "Direct Action";
unsigned char dat_str_stassi[7] = "Stassi";
unsigned char dat_str_prc[4] = "PRC";
unsigned char dat_str_marxists[9] = "Marxists";
unsigned char dat_str_dignity_bttn[13] = "Dignity Bttn";
unsigned char dat_str_career[7] = "Career";
unsigned char dat_str_career_2[14] = "The Career of";
unsigned char dat_str_max[6] = "Max '";
unsigned char dat_str_remington[12] = "' Remington";
unsigned char dat_str_case[7] = "Case #";
unsigned char dat_str_comma[3] = ", ";
unsigned char dat_str_space_3[2] = " ";
unsigned char dat_str_arrests[13] = ".  Arrests: ";
unsigned char dat_str_ep_colon[6] = " EP: ";
unsigned char dat_str_couldn_t_stop[19] = "... couldn't stop ";
unsigned char dat_str_prevented[15] = "... prevented ";
unsigned char dat_str_slash_4[2] = "/";
unsigned char dat_str_arrested_3[14] = "... arrested ";
unsigned char dat_str_mastermind[13] = " MasterMind!";
unsigned char dat_str_career_3[7] = "Career";
unsigned char dat_str_arrested_masterminds[24] = "Arrested, MasterMinds: ";
unsigned char dat_str_agents[11] = "  Agents: ";
unsigned char dat_str_career_4[7] = "Career";
unsigned char dat_str_masterminds_arrested[21] = "MasterMinds Arrested";
unsigned char *addr_crime_names[13] = {
    (unsigned char *) dat_str_kidnapping, (unsigned char *) dat_str_theft,
    (unsigned char *) dat_str_assassination,
    (unsigned char *) dat_str_drug_smuggle, (unsigned char *) dat_str_theft_2,
    (unsigned char *) dat_str_photo, (unsigned char *) dat_str_bombing,
    (unsigned char *) dat_str_datacrime,
    (unsigned char *) dat_str_terrorist_attack,
    (unsigned char *) dat_str_forgery, (unsigned char *) dat_str_jail_break,
    (unsigned char *) dat_str_blackmail, (unsigned char *) dat_str_manufacture,
};
unsigned char *dat_org_names[26] = {
    (unsigned char *) dat_str_pfo, (unsigned char *) dat_str_m18,
    (unsigned char *) dat_str_jamaican_gang,
    (unsigned char *) dat_str_haitian_junta,
    (unsigned char *) dat_str_red_september,
    (unsigned char *) dat_str_iraqi_sp, (unsigned char *) dat_str_muslim_jihad,
    (unsigned char *) dat_str_shining_way, (unsigned char *) dat_str_tupamaros,
    (unsigned char *) dat_str_colombian_cartel,
    (unsigned char *) dat_str_mafia, (unsigned char *) dat_str_libyan_emb,
    (unsigned char *) dat_str_fln, (unsigned char *) dat_str_amazon_cartel,
    (unsigned char *) dat_str_mercenaries,
    (unsigned char *) dat_str_death_squads,
    (unsigned char *) dat_str_rev_guards,
    (unsigned char *) dat_str_unioncorsique, (unsigned char *) dat_str_pifa,
    (unsigned char *) dat_str_red_army,
    (unsigned char *) dat_str_red_battalion,
    (unsigned char *) dat_str_direct_action, (unsigned char *) dat_str_stassi,
    (unsigned char *) dat_str_prc, (unsigned char *) dat_str_marxists,
    (unsigned char *) dat_str_dignity_bttn,
};
unsigned char dat_str_gender_pic_2[11] = "gender.pic";
unsigned char dat_str_max_2[4] = "Max";
unsigned char dat_str_remington_2[10] = "Remington";
unsigned char dat_str_arrested_4[9] = "ARRESTED";
unsigned char dat_str_arrested_5[9] = "ARRESTED";
unsigned char dat_str_lau[4] = "lau";
unsigned char dat_str_off[4] = "off";
unsigned char dat_str_bch[4] = "bch";
unsigned char dat_str_cas[4] = "cas";
unsigned char dat_str_after_difficult_few[65] =
    "After a difficult few days it's time to head for the LaundroMat.";
unsigned char dat_str_word_latest_case_seems[69] =
    "Word of your latest case seems to have reached the secretarial pool.";
unsigned char dat_str_after_successful_case[61] =
    "After a successful case, you deserve some time at the beach!";
unsigned char dat_str_re_feeling_invincible[64] =
    "You're feeling invincible, time to try your luck at the Casino!";
unsigned char dat_str_final4_cat[11] = "final4.cat";
unsigned char dat_str_final3_cat[11] = "final3.cat";
unsigned char dat_str_back_pic[9] = "back.pic";
unsigned char dat_str_hand[5] = "hand";
unsigned char dat_str_f_pic[6] = "f.pic";
unsigned char dat_str_m_pic[6] = "m.pic";
unsigned char dat_str_laudude1_pic[13] = "laudude1.pic";
unsigned char dat_str_dude[5] = "dude";
unsigned char dat_str_babe[5] = "babe";
unsigned char dat_str_pic[5] = ".pic";
unsigned char *dat_ending_names[4] = {
    (unsigned char *) dat_str_lau, (unsigned char *) dat_str_off,
    (unsigned char *) dat_str_bch, (unsigned char *) dat_str_cas,
};
struct INTERLUDE dat_interlude_table[21] = {
    { 0, { 1, -1, -1, -1 } },
    { 0, { 2, -1, -1, -1 } },
    { 1, { 4, -1, -1, -1 } },
    { 1, { 3, -1, -1, -1 } },
    { 1, { 2, -1, -1, -1 } },
    { 1, { 1, -1, -1, -1 } },
    { 1, { 2, 1, -1, -1 } },
    { 2, { 4, -1, -1, -1 } },
    { 2, { 1, -1, -1, -1 } },
    { 2, { 3, -1, -1, -1 } },
    { 2, { 4, 1, -1, -1 } },
    { 2, { 2, -1, -1, -1 } },
    { 2, { 1, 2, -1, -1 } },
    { 2, { 4, 3, 2, -1 } },
    { 3, { 4, -1, -1, -1 } },
    { 3, { 2, -1, -1, -1 } },
    { 3, { 3, -1, -1, -1 } },
    { 3, { 2, 4, -1, -1 } },
    { 3, { 1, -1, -1, -1 } },
    { 3, { 2, 3, 4, -1 } },
    { 3, { 4, 2, 1, 3 } },
};
unsigned char dat_str_red_herring[12] = "Red Herring";
unsigned char dat_str_we_have_indications[26] = "We have indications that ";
unsigned char dat_str_operation_preparation[45] =
    "an operation is in preparation somewhere in ";
unsigned char dat_str_europe[8] = "Europe.";
unsigned char dat_str_africa_middle_east[20] = "Africa/Middle East.";
unsigned char dat_str_central_america[17] = "Central America.";
unsigned char dat_str_the[6] = " The ";
unsigned char dat_str_known_involved[26] = " is known to be involved.";
unsigned char dat_str_mission_prevent[59] =
    "Your mission is to prevent this operation from succeeding ";
unsigned char dat_str_capture_as_many[56] =
    "and to capture as many of the participants as possible.";
unsigned char dat_str_caution_one_more_double[78] =
    " Caution, one or more Double Agents are believed to be active within the "
    "CIA.";
unsigned char dat_str_i_m_afraid_re[50] =
    "I'm afraid you're not quite up to speed yet Max. ";
unsigned char dat_str_perhaps_should_practice[67] =
    "Perhaps you should practice your skills before you take this case.";
unsigned char dat_str_ok_re_cleared[21] = "OK, you're cleared. ";
unsigned char dat_str_here_some_info_we[59] =
    "Here is some info we've picked up over the last few days. ";
unsigned char dat_str_we_think_s_linked[43] =
    "We think it's linked to this operation...\n";
unsigned char dat_str_briefing_pan_4[13] = "briefing.pan";
unsigned char dat_str_10_dta[7] = "10.dta";
unsigned char dat_CRIME_DTA_NAME[12] = "crime0.dta ";
unsigned char dat_str_world[11] = "world0.dta";
unsigned char dat_str_fame_dta[9] = "fame.dta";
unsigned char dat_str_fame_dta_2[9] = "fame.dta";
unsigned char dat_str_fame_dta_3[9] = "fame.dta";
unsigned char dat_str_fame_dta_4[9] = "fame.dta";
unsigned char dat_str_hall_fame[13] = "Hall of Fame";
unsigned char dat_str_covert_action[14] = "COVERT ACTION";
unsigned char dat_str_hall_fame_2[13] = "HALL OF FAME";
unsigned char dat_str_dashes_2[5] = " ---";
unsigned char dat_str_stop[3] = ". ";
unsigned char dat_str_max_3[6] = "Max '";
unsigned char dat_str_remington_case[21] = "' Remington,  Case #";
unsigned char dat_str_space_4[2] = " ";
unsigned char dat_str_space_5[2] = " ";
unsigned char dat_str_slash_5[2] = "/";
unsigned char dat_str_ep_colon_2[5] = "EP: ";
unsigned char dat_str_score_stop[17] = "    \200--- SCORE: ";
unsigned char dat_str_dashes_3[5] = " ---";
unsigned char dat_str_clear[7] = "C\203lear";
unsigned char dat_str_tied[10] = " tied to ";
unsigned char dat_str_registered[16] = " registered to ";
unsigned char dat_str_acquired_by[14] = " acquired by ";
unsigned char dat_str_delivered[15] = " delivered to ";
unsigned char dat_str_requested[16] = " requested for ";
unsigned char dat_str_tied_2[10] = " tied to ";
unsigned char dat_str_registered_2[16] = " registered to ";
unsigned char dat_str_traced[12] = " traced to ";
unsigned char dat_str_smuggled_into[16] = " smuggled into ";
unsigned char dat_str_requested_2[16] = " requested for ";
unsigned char dat_str_tied_3[10] = " tied to ";
unsigned char dat_str_rented_by[12] = " rented by ";
unsigned char dat_str_frequented_by[16] = " frequented by ";
unsigned char dat_str_is_in[8] = " is in ";
unsigned char dat_str_linked[12] = " linked to ";
unsigned char dat_str_purchased_by[15] = " purchased by ";
unsigned char dat_str_purchased_by_2[15] = " purchased by ";
unsigned char dat_str_traced_2[12] = " traced to ";
unsigned char dat_str_purchased[15] = " purchased in ";
unsigned char dat_str_linked_2[12] = " linked to ";
unsigned char dat_str_received_by[14] = " received by ";
unsigned char dat_str_signed_by[16] = " signed for by ";
unsigned char dat_str_traced_3[12] = " traced to ";
unsigned char dat_str_sent[10] = " sent to ";
unsigned char dat_str_refers[12] = " refers to ";
unsigned char dat_str_withdrawn_by[15] = " withdrawn by ";
unsigned char dat_str_withdrawn_by_2[15] = " withdrawn by ";
unsigned char dat_str_paid_by[10] = " paid by ";
unsigned char dat_str_transaction[17] = " transaction in ";
unsigned char dat_str_requested_3[16] = " requested for ";
unsigned char dat_str_withdrawn_by_3[15] = " withdrawn by ";
unsigned char dat_str_withdrawn_by_4[15] = " withdrawn by ";
unsigned char dat_str_paid_by_2[10] = " paid by ";
unsigned char dat_str_transaction_2[17] = " transaction in ";
unsigned char dat_str_requested_4[16] = " requested for ";
unsigned char dat_str_assigned[14] = " assigned to ";
unsigned char dat_str_assigned_2[14] = " assigned to ";
unsigned char dat_str_assigned_3[14] = " assigned to ";
unsigned char dat_str_used[10] = " used in ";
unsigned char dat_str_assigned_4[14] = " assigned to ";
unsigned char dat_str_jan[4] = "Jan";
unsigned char dat_str_feb[4] = "Feb";
unsigned char dat_str_mar[4] = "Mar";
unsigned char dat_str_apr[4] = "Apr";
unsigned char dat_str_may[4] = "May";
unsigned char dat_str_jun[4] = "Jun";
unsigned char dat_str_jul[4] = "Jul";
unsigned char dat_str_aug[4] = "Aug";
unsigned char dat_str_sep[4] = "Sep";
unsigned char dat_str_oct[4] = "Oct";
unsigned char dat_str_nov[4] = "Nov";
unsigned char dat_str_dec[4] = "Dec";
unsigned char shd_str_coded_message[23] = "       CODED MESSAGE:\n";
unsigned char shd_str_meeting_notes[23] = "       MEETING NOTES:\n";
unsigned char shd_str_new_information[24] = "       NEW INFORMATION\n";
unsigned char shd_str_additional_information[28] =
    "    ADDITIONAL INFORMATION\n";
unsigned char shd_str_space_after_name[2] = " ";
unsigned char shd_str_dots[6] = "\n... ";
unsigned char shd_str_on[4] = "on ";
unsigned char shd_str_space_after_month[2] = " ";
unsigned char shd_str_of_the[8] = "of the ";
unsigned char shd_str_in[4] = "in ";
unsigned char shd_str_newline[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_empty_watch[1];
unsigned char shd_str_space_face[2] = " ";
unsigned char shd_str_in_2[5] = " in ";
unsigned char *shd_clue_phrases[40] = {
    (unsigned char *) dat_str_tied, (unsigned char *) dat_str_registered,
    (unsigned char *) dat_str_acquired_by, (unsigned char *) dat_str_delivered,
    (unsigned char *) dat_str_requested, (unsigned char *) dat_str_tied_2,
    (unsigned char *) dat_str_registered_2, (unsigned char *) dat_str_traced,
    (unsigned char *) dat_str_smuggled_into,
    (unsigned char *) dat_str_requested_2, (unsigned char *) dat_str_tied_3,
    (unsigned char *) dat_str_rented_by,
    (unsigned char *) dat_str_frequented_by, (unsigned char *) dat_str_is_in,
    (unsigned char *) dat_str_linked, (unsigned char *) dat_str_purchased_by,
    (unsigned char *) dat_str_purchased_by_2,
    (unsigned char *) dat_str_traced_2, (unsigned char *) dat_str_purchased,
    (unsigned char *) dat_str_linked_2, (unsigned char *) dat_str_received_by,
    (unsigned char *) dat_str_signed_by, (unsigned char *) dat_str_traced_3,
    (unsigned char *) dat_str_sent, (unsigned char *) dat_str_refers,
    (unsigned char *) dat_str_withdrawn_by,
    (unsigned char *) dat_str_withdrawn_by_2,
    (unsigned char *) dat_str_paid_by, (unsigned char *) dat_str_transaction,
    (unsigned char *) dat_str_requested_3,
    (unsigned char *) dat_str_withdrawn_by_3,
    (unsigned char *) dat_str_withdrawn_by_4,
    (unsigned char *) dat_str_paid_by_2,
    (unsigned char *) dat_str_transaction_2,
    (unsigned char *) dat_str_requested_4, (unsigned char *) dat_str_assigned,
    (unsigned char *) dat_str_assigned_2, (unsigned char *) dat_str_assigned_3,
    (unsigned char *) dat_str_used, (unsigned char *) dat_str_assigned_4,
};
char shd_scan_counts[32] = {
    0x00, 0x01, 0x01, 0x02, 0x01, 0x02, 0x02, 0x03, 0x01, 0x02, 0x02, 0x03,
    0x02, 0x03, 0x03, 0x04, 0x01, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04,
    0x02, 0x03, 0x03, 0x04, 0x03, 0x04, 0x04, 0x05,
};
unsigned char *shd_month_names[12] = {
    (unsigned char *) dat_str_jan, (unsigned char *) dat_str_feb,
    (unsigned char *) dat_str_mar, (unsigned char *) dat_str_apr,
    (unsigned char *) dat_str_may, (unsigned char *) dat_str_jun,
    (unsigned char *) dat_str_jul, (unsigned char *) dat_str_aug,
    (unsigned char *) dat_str_sep, (unsigned char *) dat_str_oct,
    (unsigned char *) dat_str_nov, (unsigned char *) dat_str_dec,
};
unsigned char shd_str_empty_identified[1];
unsigned char shd_str_has_been_identified_as[52] =
    " has been\nidentified as a participant\nin the plot.\n";
unsigned char shd_str_empty_positively[1];
unsigned char shd_str_has_been_positively[36] =
    " has been positively\nidentified as ";
unsigned char shd_str_newline_2[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_we_have_acquired[34] =
    "We have acquired a\nphotograph of ";
unsigned char shd_str_stop[3] = ".\n";
unsigned char shd_str_empty_spotted[1];
unsigned char shd_str_has_been_spotted[22] = " has been\nspotted in ";
unsigned char shd_str_newline_3[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_empty_org[1];
unsigned char shd_str_has_been_identified_as_org[41] =
    " has been\nidentified as a member\nof the ";
unsigned char shd_str_newline_4[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_we_have_obtained[52] =
    "We have obtained\nadditional information\nconcerning ";
unsigned char shd_str_newline_5[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_we_have_determined_rank[32] =
    "We have determined\nthe rank of\n";
unsigned char shd_str_newline_6[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_we_found_recruiting[39] =
    "We found recruiting\ninformation about\n";
unsigned char shd_str_newline_7[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_we_found_recruiting_2[39] =
    "We found recruiting\ninformation about\n";
unsigned char shd_str_newline_8[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_recruit[8] = "Recruit";
unsigned char dat_str_operative[10] = "Operative";
unsigned char dat_str_technician[11] = "Technician";
unsigned char dat_str_agent[6] = "Agent";
unsigned char dat_str_organizer[10] = "Organizer";
unsigned char dat_str_special_agent[14] = "Special Agent";
unsigned char dat_str_group_leader[13] = "Group Leader";
unsigned char dat_str_mastermind_2[11] = "MasterMind";
unsigned char dat_str_car[4] = "CAR";
unsigned char dat_str_wpn[4] = "WPN";
unsigned char dat_str_adr[4] = "ADR";
unsigned char dat_str_tkt[4] = "TKT";
unsigned char dat_str_msg[4] = "MSG";
unsigned char dat_str_dollar_1[2] = "$";
unsigned char dat_str_dollar_2[2] = "$";
unsigned char dat_str_fce[4] = "FCE";
unsigned char dat_str_ford_escort[14] = "Ford Escort #";
unsigned char dat_str_chevy_nova[13] = "Chevy Nova #";
unsigned char dat_str_toyota_tercel[16] = "Toyota Tercel #";
unsigned char dat_str_vw_golf[10] = "VW Golf #";
unsigned char dat_str_mazda_rx7[12] = "Mazda RX7 #";
unsigned char dat_str_honda_civic[14] = "Honda Civic #";
unsigned char dat_str_peugot[9] = "Peugot #";
unsigned char dat_str_chrysler[11] = "Chrysler #";
unsigned char dat_str_walther_ppk[14] = "Walther PPK #";
unsigned char dat_str_smith_wesson_9mm[19] = "Smith&Wesson 9mm #";
unsigned char dat_str_berreta_m92s[15] = "Berreta M92S #";
unsigned char dat_str_browning_9mm[15] = "Browning 9mm #";
unsigned char dat_str_hechler_koch_vp[18] = "Hechler&Koch VP #";
unsigned char dat_str_luger_9mm[12] = "Luger 9mm #";
unsigned char dat_str_colt_45[10] = "Colt 45 #";
unsigned char dat_str_357_magnum[13] = "357 Magnum #";
unsigned char dat_str_rue_laverne[13] = "Rue Laverne ";
unsigned char dat_str_hochstrasse[13] = "HochStrasse ";
unsigned char dat_str_main_st[10] = "Main St. ";
unsigned char dat_str_webley_ct[12] = "Webley Ct. ";
unsigned char dat_str_holmley_park[14] = "Holmley Park ";
unsigned char dat_str_obensgrabbe[13] = "ObensGrabbe ";
unsigned char dat_str_la_paz_blvd[14] = "La Paz Blvd. ";
unsigned char dat_str_north_ave[12] = "North Ave. ";
unsigned char dat_str_panam[8] = "PanAm #";
unsigned char dat_str_united[9] = "United #";
unsigned char dat_str_sabena[9] = "Sabena #";
unsigned char dat_str_lufthansa[12] = "Lufthansa #";
unsigned char dat_str_el_al[8] = "El Al #";
unsigned char dat_str_klm[6] = "KLM #";
unsigned char dat_str_swissair[11] = "SwissAir #";
unsigned char dat_str_boac[7] = "BOAC #";
unsigned char dat_str_w_union[10] = "W.Union #";
unsigned char dat_str_rca[6] = "RCA #";
unsigned char dat_str_telex[8] = "Telex #";
unsigned char dat_str_amtel[8] = "AmTel #";
unsigned char dat_str_intertel[11] = "InterTel #";
unsigned char dat_str_satcomm[10] = "SatComm #";
unsigned char dat_str_teltron[10] = "TelTron #";
unsigned char dat_str_comlink[10] = "ComLink #";
unsigned char dat_str_dollar_3[2] = "$";
unsigned char dat_str_dollar_4[2] = "$";
unsigned char dat_str_dollar_5[2] = "$";
unsigned char dat_str_dollar_6[2] = "$";
unsigned char dat_str_dollar_7[2] = "$";
unsigned char dat_str_dollar_8[2] = "$";
unsigned char dat_str_dollar_9[2] = "$";
unsigned char dat_str_dollar_10[2] = "$";
unsigned char dat_str_dollar_11[2] = "$";
unsigned char dat_str_dollar_12[2] = "$";
unsigned char dat_str_dollar_13[2] = "$";
unsigned char dat_str_dollar_14[2] = "$";
unsigned char dat_str_dollar_15[2] = "$";
unsigned char dat_str_dollar_16[2] = "$";
unsigned char dat_str_dollar_17[2] = "$";
unsigned char dat_str_dollar_18[2] = "$";
unsigned char dat_str_swiss_passport[17] = "Swiss Passport #";
unsigned char dat_str_interpol_id[13] = "InterPol ID#";
unsigned char dat_str_bahamian_passport[20] = "Bahamian Passport #";
unsigned char dat_str_gold_card[12] = "Gold Card #";
unsigned char dat_str_swedish_passport[19] = "Swedish Passport #";
unsigned char dat_str_green_card[13] = "Green Card #";
unsigned char dat_str_vista_card[13] = "VISTA Card #";
unsigned char dat_str_liberian_passport[21] = "Liberian Passport #";
rt_addr shd_clue_kinds[80] = {
    (rt_addr) dat_str_recruit, (rt_addr) dat_str_operative,
    (rt_addr) dat_str_technician, (rt_addr) dat_str_agent,
    (rt_addr) dat_str_organizer, (rt_addr) dat_str_special_agent,
    (rt_addr) dat_str_group_leader, (rt_addr) dat_str_mastermind_2,
    (rt_addr) dat_str_car, (rt_addr) dat_str_wpn, (rt_addr) dat_str_adr,
    (rt_addr) dat_str_tkt, (rt_addr) dat_str_msg, (rt_addr) dat_str_dollar_1,
    (rt_addr) dat_str_dollar_2, (rt_addr) dat_str_fce,
    (rt_addr) dat_str_ford_escort, (rt_addr) dat_str_chevy_nova,
    (rt_addr) dat_str_toyota_tercel, (rt_addr) dat_str_vw_golf,
    (rt_addr) dat_str_mazda_rx7, (rt_addr) dat_str_honda_civic,
    (rt_addr) dat_str_peugot, (rt_addr) dat_str_chrysler,
    (rt_addr) dat_str_walther_ppk, (rt_addr) dat_str_smith_wesson_9mm,
    (rt_addr) dat_str_berreta_m92s, (rt_addr) dat_str_browning_9mm,
    (rt_addr) dat_str_hechler_koch_vp, (rt_addr) dat_str_luger_9mm,
    (rt_addr) dat_str_colt_45, (rt_addr) dat_str_357_magnum,
    (rt_addr) dat_str_rue_laverne, (rt_addr) dat_str_hochstrasse,
    (rt_addr) dat_str_main_st, (rt_addr) dat_str_webley_ct,
    (rt_addr) dat_str_holmley_park, (rt_addr) dat_str_obensgrabbe,
    (rt_addr) dat_str_la_paz_blvd, (rt_addr) dat_str_north_ave,
    (rt_addr) dat_str_panam, (rt_addr) dat_str_united,
    (rt_addr) dat_str_sabena, (rt_addr) dat_str_lufthansa,
    (rt_addr) dat_str_el_al, (rt_addr) dat_str_klm, (rt_addr) dat_str_swissair,
    (rt_addr) dat_str_boac, (rt_addr) dat_str_w_union, (rt_addr) dat_str_rca,
    (rt_addr) dat_str_telex, (rt_addr) dat_str_amtel,
    (rt_addr) dat_str_intertel, (rt_addr) dat_str_satcomm,
    (rt_addr) dat_str_teltron, (rt_addr) dat_str_comlink,
    (rt_addr) dat_str_dollar_3, (rt_addr) dat_str_dollar_4,
    (rt_addr) dat_str_dollar_5, (rt_addr) dat_str_dollar_6,
    (rt_addr) dat_str_dollar_7, (rt_addr) dat_str_dollar_8,
    (rt_addr) dat_str_dollar_9, (rt_addr) dat_str_dollar_10,
    (rt_addr) dat_str_dollar_11, (rt_addr) dat_str_dollar_12,
    (rt_addr) dat_str_dollar_13, (rt_addr) dat_str_dollar_14,
    (rt_addr) dat_str_dollar_15, (rt_addr) dat_str_dollar_16,
    (rt_addr) dat_str_dollar_17, (rt_addr) dat_str_dollar_18,
    (rt_addr) dat_str_swiss_passport, (rt_addr) dat_str_interpol_id,
    (rt_addr) dat_str_bahamian_passport, (rt_addr) dat_str_gold_card,
    (rt_addr) dat_str_swedish_passport, (rt_addr) dat_str_green_card,
    (rt_addr) dat_str_vista_card, (rt_addr) dat_str_liberian_passport,
};
unsigned char dat_str_clandestine_photo[18] = "Clandestine Photo";
unsigned char dat_str_electronic_wiretap[19] = "Electronic WireTap";
unsigned char dat_str_covert_surveillance[20] = "Covert Surveillance";
unsigned char dat_str_file_record_search[19] = "File Record Search";
unsigned char dat_str_local_informant[16] = "Local Informant";
unsigned char dat_str_interpol_data_base[19] = "INTERPOL Data Base";
unsigned char dat_str_local_authorities[18] = "Local Authorities";
unsigned char shd_str_clue[5] = "Clue";
unsigned char shd_str_source_2[10] = "\207Source: ";
unsigned char shd_str_slash_source[2] = "/";
unsigned char shd_str_newline_9[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_method_stop[11] = "\n\207Method: ";
unsigned char shd_str_related_2[16] = "\214Related Clues:";
unsigned char shd_str_newline_10[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_none[8] = "...none";
unsigned char *shd_clue_source[7] = {
    (unsigned char *) dat_str_clandestine_photo,
    (unsigned char *) dat_str_electronic_wiretap,
    (unsigned char *) dat_str_covert_surveillance,
    (unsigned char *) dat_str_file_record_search,
    (unsigned char *) dat_str_local_informant,
    (unsigned char *) dat_str_interpol_data_base,
    (unsigned char *) dat_str_local_authorities,
};
unsigned char dat_msg_key[5] = "$KEY";
unsigned char dat_msg_name[6] = "$NAME";
unsigned char dat_msg_org[5] = "$ORG";
unsigned char dat_msg_city[6] = "$CITY";
unsigned char dat_msg_role[6] = "$ROLE";
unsigned char shd_key_clue[7] = "*C0000";
unsigned char shd_str_clues_txt[10] = "clues.txt";
unsigned char *shd_clue_keys[5] = {
    (unsigned char *) dat_msg_key, (unsigned char *) dat_msg_name,
    (unsigned char *) dat_msg_org, (unsigned char *) dat_msg_city,
    (unsigned char *) dat_msg_role,
};
unsigned char shd_str_period[2] = ".";
unsigned char shd_str_face[11] = "this face.";
unsigned char shd_str_valkerie[9] = "Valkerie";
unsigned char shd_str_thunderbolt[12] = "Thunderbolt";
unsigned char shd_str_00[3] = "00";
unsigned char shd_str_000[4] = "000";
unsigned char shd_key_clue_2[5] = "*C00";
unsigned char shd_key_clue_3[7] = "*C0000";
unsigned char shd_key_clue_4[7] = "*C0000";
unsigned char shd_str_clues_txt_2[10] = "clues.txt";
unsigned char shd_str_empty_dossier[1];
unsigned char shd_str_name[7] = "Name:\200";
unsigned char shd_str_rank[7] = "Rank:\200";
unsigned char shd_str_org[7] = "Org: \200";
unsigned char shd_str_city[8] = "City: \200";
unsigned char shd_str_recruited[10] = "Recruited";
unsigned char shd_str_by[5] = " by ";
unsigned char shd_str_in_3[5] = " in ";
unsigned char shd_str_period_2[2] = ".";
unsigned char shd_str_role[8] = "Role: \200";
unsigned char shd_str_role_2[20] = "Role: \200NOT INVOLVED";
unsigned char shd_str_role_3[15] = "Role: \200unknown";
unsigned char shd_str_under_arrest[15] = "(Under Arrest)";
unsigned char shd_str_hiding[12] = "(In Hiding)";
unsigned char shd_str_turned[9] = "(Turned)";
unsigned char shd_str_empty_dossier_line[1];
unsigned char shd_str_quote[2] = "'";
unsigned char shd_str_quote_2[2] = "'";
unsigned char shd_str_message_not_decoded[22] = "(message not decoded)";
unsigned char shd_str_more[8] = "...more";
unsigned char shd_str_empty_dossier_page[1];
unsigned char shd_str_rcvd_msg_fm[12] = "Rcvd msg fm";
unsigned char shd_str_sent_msg[12] = "Sent msg to";
unsigned char shd_str_space_9[2] = " ";
unsigned char shd_str_someone[9] = " someone";
unsigned char shd_str_of_the_2[9] = " of the ";
unsigned char shd_str_in_4[5] = " in ";
unsigned char shd_str_on_2[5] = " on ";
unsigned char shd_str_space_10[2] = " ";
unsigned char shd_str_period_3[2] = ".";
unsigned char dat_str_victim[8] = "$VICTIM";
unsigned char dat_msg_sndorg[8] = "$SNDORG";
unsigned char dat_msg_rcvorg[8] = "$RCVORG";
unsigned char dat_msg_sndloc[8] = "$SNDLOC";
unsigned char dat_msg_rcvloc[8] = "$RCVLOC";
unsigned char dat_msg_hlporg[8] = "$HLPORG";
unsigned char dat_str_object[8] = "$OBJECT";
unsigned char asm_subst_buffer_0[26] = "                          ";
unsigned char asm_subst_buffer_2[26] = "                         ";
unsigned char asm_subst_buffer_3[26] = "                         ";
unsigned char asm_subst_buffer_4[26] = "                         ";
unsigned char asm_subst_buffer_5[26] = "                         ";
unsigned char asm_subst_buffer_6[26] = "                         ";
unsigned char asm_subst_buffer_7[26] = "                          ";
unsigned char *shd_subst_keys[7] = {
    (unsigned char *) dat_str_victim, (unsigned char *) dat_msg_sndorg,
    (unsigned char *) dat_msg_rcvorg, (unsigned char *) dat_msg_sndloc,
    (unsigned char *) dat_msg_rcvloc, (unsigned char *) dat_msg_hlporg,
    (unsigned char *) dat_str_object,
};
rt_addr shd_subst_values[7] = {
    (rt_addr) asm_subst_buffer_0, (rt_addr) asm_subst_buffer_2,
    (rt_addr) asm_subst_buffer_3, (rt_addr) asm_subst_buffer_4,
    (rt_addr) asm_subst_buffer_5, (rt_addr) asm_subst_buffer_6,
    (rt_addr) asm_subst_buffer_7,
};
unsigned char shd_str_mode_read_text[3] = "rt";
unsigned char shd_fmt_line[7] = "%[^\n]\n";
unsigned char shd_fmt_line_2[7] = "%[^\n]\n";
unsigned char shd_str_space_12[2] = " ";
unsigned char shd_fmt_line_3[7] = "%[^\n]\n";
unsigned char shd_str_information_requires[47] =
    "This information requires security clearance: ";
unsigned char shd_str_empty_message[1];
unsigned char shd_str_sloc00[8] = "*SLOC00";
unsigned char shd_str_text_dta_sloc[9] = "text.dta";
unsigned char shd_str_rloc00[8] = "*RLOC00";
unsigned char shd_str_text_dta_rloc[9] = "text.dta";
unsigned char shd_str_sorg00[8] = "*SORG00";
unsigned char shd_str_text_dta_sorg[9] = "text.dta";
unsigned char shd_str_rorg00[8] = "*RORG00";
unsigned char shd_str_text_dta_rorg[9] = "text.dta";
unsigned char shd_str_mark_80[2] = {
    0x80, 0x00,
};
unsigned char shd_str_text_dta_msg[9] = "text.dta";
unsigned char shd_str_mark_8f[2] = {
    0x8f, 0x00,
};
unsigned char shd_str_fluf00[8] = "*FLUF00";
unsigned char shd_str_text_dta_fluf[9] = "text.dta";
unsigned char shd_str_alrt00[8] = "*ALRT00";
unsigned char shd_str_text_dta_help[9] = "text.dta";
unsigned char shd_str_aidd00[8] = "*AIDD00";
unsigned char shd_str_text_dta_aidd[9] = "text.dta";
unsigned char shd_str_text_dta_event[9] = "text.dta";
unsigned char shd_str_msg0000[9] = "*MSG0000";
unsigned char shd_str_facesf_pic[11] = "facesf.pic";
unsigned char shd_str_faces_pic[11] = "faces.pic";
unsigned char shd_str_newline_wrap[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_ellipsis_2[6] = " ... ";
unsigned char shd_str_hideout[9] = " hideout";
unsigned char shd_str_agent[7] = " agent";
unsigned char shd_str_safehouse[11] = " safehouse";
unsigned char shd_str_active_cel[12] = " active cel";
unsigned char shd_str_office[8] = " office";
unsigned char shd_str_agent_3[8] = "Agent A";
unsigned char dat_str_georgina[9] = "Georgina";
unsigned char dat_str_arkada[7] = "Arkada";
unsigned char dat_str_yuria[6] = "Yuria";
unsigned char dat_str_anatola[8] = "Anatola";
unsigned char dat_str_andra[6] = "Andra";
unsigned char dat_str_nikola[7] = "Nikola";
unsigned char dat_str_viktora[8] = "Viktora";
unsigned char dat_str_ivana[6] = "Ivana";
unsigned char dat_str_natasha[8] = "Natasha";
unsigned char dat_str_svetlana[9] = "Svetlana";
unsigned char dat_str_anna[5] = "Anna";
unsigned char dat_str_ludmilla[9] = "Ludmilla";
unsigned char dat_str_lexandra[9] = "Lexandra";
unsigned char dat_str_katerina[9] = "Katerina";
unsigned char dat_str_olga[5] = "Olga";
unsigned char dat_str_nadia[6] = "Nadia";
unsigned char dat_str_leona[6] = "Leona";
unsigned char dat_str_pat[4] = "Pat";
unsigned char dat_str_carla[6] = "Carla";
unsigned char dat_str_bobbie[7] = "Bobbie";
unsigned char dat_str_jenny[6] = "Jenny";
unsigned char dat_str_frieda[7] = "Frieda";
unsigned char dat_str_alice[6] = "Alice";
unsigned char dat_str_rose[5] = "Rose";
unsigned char dat_str_deirdre[8] = "Deirdre";
unsigned char dat_str_martha[7] = "Martha";
unsigned char dat_str_lisa[5] = "Lisa";
unsigned char dat_str_erica[6] = "Erica";
unsigned char dat_str_liz[4] = "Liz";
unsigned char dat_str_emma[5] = "Emma";
unsigned char dat_str_isadora[8] = "Isadora";
unsigned char dat_str_jane[5] = "Jane";
unsigned char dat_str_omara[6] = "Omara";
unsigned char dat_str_alicia[7] = "Alicia";
unsigned char dat_str_hasana[7] = "Hasana";
unsigned char dat_str_leila[6] = "Leila";
unsigned char dat_str_yasria[7] = "Yasria";
unsigned char dat_str_ailha[6] = "Ailha";
unsigned char dat_str_yousfa[7] = "Yousfa";
unsigned char dat_str_aziza[6] = "Aziza";
unsigned char dat_str_fatima[7] = "Fatima";
unsigned char dat_str_benazir[8] = "Benazir";
unsigned char dat_str_ouida[6] = "Ouida";
unsigned char dat_str_selima[7] = "Selima";
unsigned char dat_str_ismaila[8] = "Ismaila";
unsigned char dat_str_persis[7] = "Persis";
unsigned char dat_str_haurouna[9] = "Haurouna";
unsigned char dat_str_zara[5] = "Zara";
unsigned char dat_str_carlotta[9] = "Carlotta";
unsigned char dat_str_josita[7] = "Josita";
unsigned char dat_str_miguela[8] = "Miguela";
unsigned char dat_str_ramona[7] = "Ramona";
unsigned char dat_str_luisa[6] = "Luisa";
unsigned char dat_str_julia[6] = "Julia";
unsigned char dat_str_juanita[8] = "Juanita";
unsigned char dat_str_raquel[7] = "Raquel";
unsigned char dat_str_isabel[7] = "Isabel";
unsigned char dat_str_maria[6] = "Maria";
unsigned char dat_str_elena[6] = "Elena";
unsigned char dat_str_linda[6] = "Linda";
unsigned char dat_str_carmen[7] = "Carmen";
unsigned char dat_str_agnes[6] = "Agnes";
unsigned char dat_str_celeste[8] = "Celeste";
unsigned char dat_str_phyllis[8] = "Phyllis";
unsigned char dat_str_georgi[7] = "Georgi";
unsigned char dat_str_arkady[7] = "Arkady";
unsigned char dat_str_yuri[5] = "Yuri";
unsigned char dat_str_anatol[7] = "Anatol";
unsigned char dat_str_andrei[7] = "Andrei";
unsigned char dat_str_nikita[7] = "Nikita";
unsigned char dat_str_viktor[7] = "Viktor";
unsigned char dat_str_ivan[5] = "Ivan";
unsigned char dat_str_boris[6] = "Boris";
unsigned char dat_str_nikolai[8] = "Nikolai";
unsigned char dat_str_grigori[8] = "Grigori";
unsigned char dat_str_pavel[6] = "Pavel";
unsigned char dat_str_mischa[7] = "Mischa";
unsigned char dat_str_petrov[7] = "Petrov";
unsigned char dat_str_vladimir[9] = "Vladimir";
unsigned char dat_str_mikhail[8] = "Mikhail";
unsigned char dat_str_leon[5] = "Leon";
unsigned char dat_str_ian[4] = "Ian";
unsigned char dat_str_carl[5] = "Carl";
unsigned char dat_str_bob[4] = "Bob";
unsigned char dat_str_jim[4] = "Jim";
unsigned char dat_str_fred[5] = "Fred";
unsigned char dat_str_alan[5] = "Alan";
unsigned char dat_str_ralph[6] = "Ralph";
unsigned char dat_str_antoine[8] = "Antoine";
unsigned char dat_str_heinrich[9] = "Heinrich";
unsigned char dat_str_eric[5] = "Eric";
unsigned char dat_str_gordon[7] = "Gordon";
unsigned char dat_str_david[6] = "David";
unsigned char dat_str_pierre[7] = "Pierre";
unsigned char dat_str_claude[7] = "Claude";
unsigned char dat_str_gerard[7] = "Gerard";
unsigned char dat_str_omar[5] = "Omar";
unsigned char dat_str_ali[4] = "Ali";
unsigned char dat_str_hasan[6] = "Hasan";
unsigned char dat_str_abdul[6] = "Abdul";
unsigned char dat_str_yasr[5] = "Yasr";
unsigned char dat_str_abu[4] = "Abu";
unsigned char dat_str_yousf[6] = "Yousf";
unsigned char dat_str_saadi[6] = "Saadi";
unsigned char dat_str_achmet[7] = "Achmet";
unsigned char dat_str_ibrahim[8] = "Ibrahim";
unsigned char dat_str_selim[6] = "Selim";
unsigned char dat_str_ismail[7] = "Ismail";
unsigned char dat_str_mahmoud[8] = "Mahmoud";
unsigned char dat_str_haround[8] = "Haround";
unsigned char dat_str_suleiman[9] = "Suleiman";
unsigned char dat_str_yezid[6] = "Yezid";
unsigned char dat_str_carlos[7] = "Carlos";
unsigned char dat_str_jose[5] = "Jose";
unsigned char dat_str_miguel[7] = "Miguel";
unsigned char dat_str_ramon[6] = "Ramon";
unsigned char dat_str_luis[5] = "Luis";
unsigned char dat_str_julio[6] = "Julio";
unsigned char dat_str_juan[5] = "Juan";
unsigned char dat_str_pedro[6] = "Pedro";
unsigned char dat_str_enrique[8] = "Enrique";
unsigned char dat_str_eduardo[8] = "Eduardo";
unsigned char dat_str_arturo[7] = "Arturo";
unsigned char dat_str_jorge[6] = "Jorge";
unsigned char dat_str_manuel[7] = "Manuel";
unsigned char dat_str_hector[7] = "Hector";
unsigned char dat_str_franco[7] = "Franco";
unsigned char dat_str_jaime[6] = "Jaime";
unsigned char dat_str_katkov[7] = "Katkov";
unsigned char dat_str_gorny[6] = "Gorny";
unsigned char dat_str_gromyko[8] = "Gromyko";
unsigned char dat_str_kormarov[9] = "Kormarov";
unsigned char dat_str_molotov[8] = "Molotov";
unsigned char dat_str_charyk[7] = "Charyk";
unsigned char dat_str_markov[7] = "Markov";
unsigned char dat_str_filatov[8] = "Filatov";
unsigned char dat_str_badenov[8] = "Badenov";
unsigned char dat_str_chekhov[8] = "Chekhov";
unsigned char dat_str_gogol[6] = "Gogol";
unsigned char dat_str_zhukov[7] = "Zhukov";
unsigned char dat_str_nevsky[7] = "Nevsky";
unsigned char dat_str_kemidov[8] = "Kemidov";
unsigned char dat_str_dubrovnik[10] = "Dubrovnik";
unsigned char dat_str_kerensky[9] = "Kerensky";
unsigned char dat_str_lorenz[7] = "Lorenz";
unsigned char dat_str_koch[5] = "Koch";
unsigned char dat_str_baader[7] = "Baader";
unsigned char dat_str_brown[6] = "Brown";
unsigned char dat_str_jones[6] = "Jones";
unsigned char dat_str_bloom[6] = "Bloom";
unsigned char dat_str_cahill[7] = "Cahill";
unsigned char dat_str_grivas[7] = "Grivas";
unsigned char dat_str_cook[5] = "Cook";
unsigned char dat_str_muller[7] = "Muller";
unsigned char dat_str_hansen[7] = "Hansen";
unsigned char dat_str_olsen[6] = "Olsen";
unsigned char dat_str_merrick[8] = "Merrick";
unsigned char dat_str_ballard[8] = "Ballard";
unsigned char dat_str_verne[6] = "Verne";
unsigned char dat_str_konrad[7] = "Konrad";
unsigned char dat_str_abbas[6] = "Abbas";
unsigned char dat_str_said[5] = "Said";
unsigned char dat_str_daoud[6] = "Daoud";
unsigned char dat_str_moussa[7] = "Moussa";
unsigned char dat_str_nidal[6] = "Nidal";
unsigned char dat_str_khaled[7] = "Khaled";
unsigned char dat_str_hammid[7] = "Hammid";
unsigned char dat_str_afafat[7] = "Afafat";
unsigned char dat_str_agha[5] = "Agha";
unsigned char dat_str_murad[6] = "Murad";
unsigned char dat_str_akbar[6] = "Akbar";
unsigned char dat_str_hosayn[7] = "Hosayn";
unsigned char dat_str_raisuli[8] = "Raisuli";
unsigned char dat_str_musafir[8] = "Musafir";
unsigned char dat_str_nasr[5] = "Nasr";
unsigned char dat_str_rashid[7] = "Rashid";
unsigned char dat_str_munoz[6] = "Munoz";
unsigned char dat_str_diaz[5] = "Diaz";
unsigned char dat_str_munoz_2[6] = "Munoz";
unsigned char dat_str_perez[6] = "Perez";
unsigned char dat_str_ramirez[8] = "Ramirez";
unsigned char dat_str_alvarez[8] = "Alvarez";
unsigned char dat_str_garcia[7] = "Garcia";
unsigned char dat_str_lopez[6] = "Lopez";
unsigned char dat_str_santos[7] = "Santos";
unsigned char dat_str_diego[6] = "Diego";
unsigned char dat_str_cordoba[8] = "Cordoba";
unsigned char dat_str_valdez[7] = "Valdez";
unsigned char dat_str_santiago[9] = "Santiago";
unsigned char dat_str_enriquez[9] = "Enriquez";
unsigned char dat_str_sanchez[8] = "Sanchez";
unsigned char dat_str_delarosa[9] = "Delarosa";
unsigned char shd_str_space_13[3] = " ";
unsigned char *shd_first_names[2][64] = {
    {
        (unsigned char *) dat_str_georgina, (unsigned char *) dat_str_arkada,
        (unsigned char *) dat_str_yuria, (unsigned char *) dat_str_anatola,
        (unsigned char *) dat_str_andra, (unsigned char *) dat_str_nikola,
        (unsigned char *) dat_str_viktora, (unsigned char *) dat_str_ivana,
        (unsigned char *) dat_str_natasha, (unsigned char *) dat_str_svetlana,
        (unsigned char *) dat_str_anna, (unsigned char *) dat_str_ludmilla,
        (unsigned char *) dat_str_lexandra, (unsigned char *) dat_str_katerina,
        (unsigned char *) dat_str_olga, (unsigned char *) dat_str_nadia,
        (unsigned char *) dat_str_leona, (unsigned char *) dat_str_pat,
        (unsigned char *) dat_str_carla, (unsigned char *) dat_str_bobbie,
        (unsigned char *) dat_str_jenny, (unsigned char *) dat_str_frieda,
        (unsigned char *) dat_str_alice, (unsigned char *) dat_str_rose,
        (unsigned char *) dat_str_deirdre, (unsigned char *) dat_str_martha,
        (unsigned char *) dat_str_lisa, (unsigned char *) dat_str_erica,
        (unsigned char *) dat_str_liz, (unsigned char *) dat_str_emma,
        (unsigned char *) dat_str_isadora, (unsigned char *) dat_str_jane,
        (unsigned char *) dat_str_omara, (unsigned char *) dat_str_alicia,
        (unsigned char *) dat_str_hasana, (unsigned char *) dat_str_leila,
        (unsigned char *) dat_str_yasria, (unsigned char *) dat_str_ailha,
        (unsigned char *) dat_str_yousfa, (unsigned char *) dat_str_aziza,
        (unsigned char *) dat_str_fatima, (unsigned char *) dat_str_benazir,
        (unsigned char *) dat_str_ouida, (unsigned char *) dat_str_selima,
        (unsigned char *) dat_str_ismaila, (unsigned char *) dat_str_persis,
        (unsigned char *) dat_str_haurouna, (unsigned char *) dat_str_zara,
        (unsigned char *) dat_str_carlotta, (unsigned char *) dat_str_josita,
        (unsigned char *) dat_str_miguela, (unsigned char *) dat_str_ramona,
        (unsigned char *) dat_str_luisa, (unsigned char *) dat_str_julia,
        (unsigned char *) dat_str_juanita, (unsigned char *) dat_str_raquel,
        (unsigned char *) dat_str_isabel, (unsigned char *) dat_str_maria,
        (unsigned char *) dat_str_elena, (unsigned char *) dat_str_linda,
        (unsigned char *) dat_str_carmen, (unsigned char *) dat_str_agnes,
        (unsigned char *) dat_str_celeste, (unsigned char *) dat_str_phyllis,
    },
    {
        (unsigned char *) dat_str_georgi, (unsigned char *) dat_str_arkady,
        (unsigned char *) dat_str_yuri, (unsigned char *) dat_str_anatol,
        (unsigned char *) dat_str_andrei, (unsigned char *) dat_str_nikita,
        (unsigned char *) dat_str_viktor, (unsigned char *) dat_str_ivan,
        (unsigned char *) dat_str_boris, (unsigned char *) dat_str_nikolai,
        (unsigned char *) dat_str_grigori, (unsigned char *) dat_str_pavel,
        (unsigned char *) dat_str_mischa, (unsigned char *) dat_str_petrov,
        (unsigned char *) dat_str_vladimir, (unsigned char *) dat_str_mikhail,
        (unsigned char *) dat_str_leon, (unsigned char *) dat_str_ian,
        (unsigned char *) dat_str_carl, (unsigned char *) dat_str_bob,
        (unsigned char *) dat_str_jim, (unsigned char *) dat_str_fred,
        (unsigned char *) dat_str_alan, (unsigned char *) dat_str_ralph,
        (unsigned char *) dat_str_antoine, (unsigned char *) dat_str_heinrich,
        (unsigned char *) dat_str_eric, (unsigned char *) dat_str_gordon,
        (unsigned char *) dat_str_david, (unsigned char *) dat_str_pierre,
        (unsigned char *) dat_str_claude, (unsigned char *) dat_str_gerard,
        (unsigned char *) dat_str_omar, (unsigned char *) dat_str_ali,
        (unsigned char *) dat_str_hasan, (unsigned char *) dat_str_abdul,
        (unsigned char *) dat_str_yasr, (unsigned char *) dat_str_abu,
        (unsigned char *) dat_str_yousf, (unsigned char *) dat_str_saadi,
        (unsigned char *) dat_str_achmet, (unsigned char *) dat_str_ibrahim,
        (unsigned char *) dat_str_selim, (unsigned char *) dat_str_ismail,
        (unsigned char *) dat_str_mahmoud, (unsigned char *) dat_str_haround,
        (unsigned char *) dat_str_suleiman, (unsigned char *) dat_str_yezid,
        (unsigned char *) dat_str_carlos, (unsigned char *) dat_str_jose,
        (unsigned char *) dat_str_miguel, (unsigned char *) dat_str_ramon,
        (unsigned char *) dat_str_luis, (unsigned char *) dat_str_julio,
        (unsigned char *) dat_str_juan, (unsigned char *) dat_str_pedro,
        (unsigned char *) dat_str_enrique, (unsigned char *) dat_str_eduardo,
        (unsigned char *) dat_str_arturo, (unsigned char *) dat_str_jorge,
        (unsigned char *) dat_str_manuel, (unsigned char *) dat_str_hector,
        (unsigned char *) dat_str_franco, (unsigned char *) dat_str_jaime,
    },
};
unsigned char *shd_last_names[64] = {
    (unsigned char *) dat_str_katkov, (unsigned char *) dat_str_gorny,
    (unsigned char *) dat_str_gromyko, (unsigned char *) dat_str_kormarov,
    (unsigned char *) dat_str_molotov, (unsigned char *) dat_str_charyk,
    (unsigned char *) dat_str_markov, (unsigned char *) dat_str_filatov,
    (unsigned char *) dat_str_badenov, (unsigned char *) dat_str_chekhov,
    (unsigned char *) dat_str_gogol, (unsigned char *) dat_str_zhukov,
    (unsigned char *) dat_str_nevsky, (unsigned char *) dat_str_kemidov,
    (unsigned char *) dat_str_dubrovnik, (unsigned char *) dat_str_kerensky,
    (unsigned char *) dat_str_lorenz, (unsigned char *) dat_str_koch,
    (unsigned char *) dat_str_baader, (unsigned char *) dat_str_brown,
    (unsigned char *) dat_str_jones, (unsigned char *) dat_str_bloom,
    (unsigned char *) dat_str_cahill, (unsigned char *) dat_str_grivas,
    (unsigned char *) dat_str_cook, (unsigned char *) dat_str_muller,
    (unsigned char *) dat_str_hansen, (unsigned char *) dat_str_olsen,
    (unsigned char *) dat_str_merrick, (unsigned char *) dat_str_ballard,
    (unsigned char *) dat_str_verne, (unsigned char *) dat_str_konrad,
    (unsigned char *) dat_str_abbas, (unsigned char *) dat_str_said,
    (unsigned char *) dat_str_daoud, (unsigned char *) dat_str_moussa,
    (unsigned char *) dat_str_nidal, (unsigned char *) dat_str_khaled,
    (unsigned char *) dat_str_hammid, (unsigned char *) dat_str_afafat,
    (unsigned char *) dat_str_agha, (unsigned char *) dat_str_murad,
    (unsigned char *) dat_str_akbar, (unsigned char *) dat_str_hosayn,
    (unsigned char *) dat_str_raisuli, (unsigned char *) dat_str_musafir,
    (unsigned char *) dat_str_nasr, (unsigned char *) dat_str_rashid,
    (unsigned char *) dat_str_munoz, (unsigned char *) dat_str_diaz,
    (unsigned char *) dat_str_munoz_2, (unsigned char *) dat_str_perez,
    (unsigned char *) dat_str_ramirez, (unsigned char *) dat_str_alvarez,
    (unsigned char *) dat_str_garcia, (unsigned char *) dat_str_lopez,
    (unsigned char *) dat_str_santos, (unsigned char *) dat_str_diego,
    (unsigned char *) dat_str_cordoba, (unsigned char *) dat_str_valdez,
    (unsigned char *) dat_str_santiago, (unsigned char *) dat_str_enriquez,
    (unsigned char *) dat_str_sanchez, (unsigned char *) dat_str_delarosa,
};
unsigned char shd_str_master_plan[12] = "Master Plan";
unsigned char shd_str_secret[11] = "--SECRET--";
unsigned char shd_str_arrested_upper[9] = "ARRESTED";
unsigned char shd_str_hiding_upper[10] = "IN HIDING";
unsigned char shd_str_turned_upper[8] = " TURNED";
unsigned char shd_str_personnel_file[15] = "Personnel File";
unsigned char shd_str_action_team[13] = " Action Team";
unsigned char shd_str_comma_3[3] = ", ";
unsigned char shd_str_no_activity[14] = "(No activity)";
unsigned char shd_clock_text[9] = "00:00:00";
unsigned char shd_str_nsyn_overflow[15] = "NSYN Overflow\n";
unsigned char shd_str_chronology[11] = "Chronology";
unsigned char shd_str_news[5] = "News";
unsigned char shd_str_sent_msg_2[14] = " sent msg to ";
unsigned char shd_str_met[11] = " met with ";
unsigned char shd_str_quote_3[2] = "'";
unsigned char shd_str_quote_4[2] = "'";
unsigned char shd_str_meeting_noted[14] = "Meeting Noted";
unsigned char shd_str_more_2[8] = "...more";
unsigned char shd_str_chronology_2[11] = "Chronology";
unsigned char shd_str_news_2[5] = "News";
unsigned char shd_str_none_log[5] = "none";
unsigned char shd_str_one_moment_please[21] = "One moment please...";
unsigned char shd_str_sure_want_quit_no_2[41] =
    "Are you sure\nyou want to Quit?\n No\n Yes\n";
UNSIGNED_INT shd_city_on_screen = 0xffff;
INT shd_drive = -1;
UNSIGNED_INT shm_pan_width = 0x0140;
struct PALETTE shd_palette_menu = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x0c,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
struct PALETTE shd_palette_face = {
    0x00,
    0x01,
    0x02,
    0x03,
    0x04,
    0x00,
    0x06,
    0x07,
    0x08,
    0x09,
    0x0a,
    0x0b,
    0x06,
    0x0d,
    0x0e,
    0x0f,
    0x00,
};
unsigned char shd_str_ok[3] = "OK";
unsigned char shd_str_briefing_pan[13] = "briefing.pan";
unsigned char shd_str_bld[4] = "bld";
UNSIGNED_INT shm_pan_building;
unsigned char shd_str_animation_pan[14] = "animation.pan";
UNSIGNED_INT shd_joystick_dirs[9] = {
    0x0008, 0x0007, 0x0006, 0x0001, 0xffff, 0x0005,
    0x0002, 0x0003, 0x0004,
};
unsigned char shd_str_select_load_file[22] = "Select Load File...\n";
unsigned char shd_save_name[10] = "a:cv0.sve";
unsigned char shd_str_sve[4] = "sve";
unsigned char shd_str_max[7] = " Max '";
unsigned char shd_str_remington_00[16] = "' Remington: 00";
unsigned char shd_str_rank_2[12] = " rank\n ... ";
unsigned char shd_str_colon[3] = ": ";
unsigned char shd_str_space_slot[2] = " ";
unsigned char shd_str_comma_2[3] = ", ";
unsigned char shd_str_local[9] = " (Local)";
unsigned char shd_str_national[12] = " (National)";
unsigned char shd_str_regional[12] = " (Regional)";
unsigned char shd_str_global[10] = " (Global)";
unsigned char shd_str_stop_blank[5] = ".\n \n";
unsigned char shd_str_empty_slot[14] = " (EMPTY)\n \n \n";
unsigned char shd_str_select_save_file[21] = "Select Save File...\n";
unsigned char shd_str_game_has_been_saved[22] = "Game has been saved.\n";
unsigned char shd_str_game_not_saved[17] = "Game NOT saved.\n";
unsigned char shd_str_write_access_denied[22] = "Write access denied.\n";
unsigned char shd_str_disk_full[12] = "Disk Full.\n";
unsigned char shd_str_press_key_continue[24] = "Press key to continue.\n";
unsigned char shd_str_sve_2[4] = "sve";
unsigned char shd_str_file_error_write[13] = "File Error: ";
unsigned char shd_str_newline_save[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_save_progress[25] = "\n ... save in progress.\n";
unsigned char shd_str_which_drive_contains[59] =
    "Which drive contains your\nsaved game files?\n\n           \217 ";
unsigned char shd_str_which_drive_contains_2[57] =
    "Which drive contains your\nSave Game disk?\n\n           \217 ";
unsigned char shd_str_press_drive_letter[61] =
    ":\n\n    Press drive letter and\nReturn when disk is inserted.\n";
unsigned char shd_str_press_escape_cancel[29] =
    "    Press Escape to cancel.\n";
unsigned char shd_str_no_disk_drive[21] = "No Disk in Drive A.\n";
unsigned char shd_str_env_sve_put[8] = "env.sve";
unsigned char shd_str_env_sve[8] = "env.sve";
unsigned char shd_str_file_error[13] = "File Error: ";
unsigned char shd_str_newline_12[3] = {
    0x0a, 0x00, 0x00,
};
unsigned char dat_str_final_exe[10] = "final.exe";
unsigned char dat_str_game_exe[9] = "game.exe";
unsigned char dat_str_tac_exe[8] = "tac.exe";
unsigned char dat_str_hq_pan[7] = "hq.pan";
unsigned char shd_str_please_insert_disk[20] = "Please insert Disk ";
unsigned char shd_str_if_3_5_insert[23] = "\n(if 3.5\" insert Disk ";
unsigned char shd_str_close_paren[2] = ")";
unsigned char shd_str_press_return_continue[41] =
    ".\n \n     Press Return\n     to continue.\n";
drv_addr shd_disk_names[4] = {
    (drv_addr) dat_str_final_exe, (drv_addr) dat_str_game_exe,
    (drv_addr) dat_str_tac_exe, (drv_addr) dat_str_hq_pan,
};
unsigned char shd_disk_letter[2] = "A";
struct RASTPORT dat_anim_page_port = { 0, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT dat_anim_page_2_port = { 2, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *shd_anim_page = (struct RASTPORT *) &dat_anim_page_port;
struct RASTPORT *shd_anim_page_2 = (struct RASTPORT *) &dat_anim_page_2_port;
struct RASTPORT dat_rastport_hidden = { 0, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT dat_rastport_shown = { 1, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT dat_rastport_anim = { 2, 0, 0, 319, 199, 0, 15, 4, 0 };
drv_addr drv_page_hidden = (drv_addr) &dat_rastport_hidden;
drv_addr drv_page_shown = (drv_addr) &dat_rastport_shown;
drv_addr drv_page_anim = (drv_addr) &dat_rastport_anim;
UNSIGNED_INT shm_seq_picture;
UNSIGNED_INT shm_frame_toggle = 0x0001;
unsigned char shd_str_pani[5] = "PANI";
struct RASTPORT dat_screen_port = { 0, 0, 0, 319, 199, 1, 15, 4, 0 };
struct RASTPORT *shd_screen = (struct RASTPORT *) &dat_screen_port;
rt_addr shd_archive_buffer_end = (rt_addr) &shm_menu_face_x;
INT shd_archive_fd = -1;
UNSIGNED_INT shm_anim_magic = 0x0003;
INT shm_field_cursor;
UNSIGNED_INT shm_field_char_width;
UNSIGNED_INT shm_field_cursor_x;
unsigned char asm_number_digits[16];
unsigned char asm_number_digits_2[16];
unsigned char asm_number_digits_3[16];
unsigned char asm_number_digits_4[32];
unsigned char asm_number_digits_5[16];
unsigned char shm_clue_digits[32];
unsigned char shm_message_key[9];
struct SEQ_BLOCK shm_active_pan;
INT shm_menu_line_start[32];
UNSIGNED_INT shm_menu_colour_plain;
UNSIGNED_INT shm_menu_colour_item;
INT shm_menu_lines;
UNSIGNED_INT shm_menu_colour_pick;
unsigned char shm_slot_digits[16];
UNSIGNED_INT shm_save_loading;
INT shm_save_errno;
INT shm_slot_fd;
INT shm_slot_word;
unsigned char FAR *shm_save_block;
UNSIGNED_INT shm_save_offset;
INT shm_save_fd;
UNSIGNED_INT shm_seq_frames_left;
UNSIGNED_INT shm_frames_owed;
UNSIGNED_INT shm_seq_wait;
struct SEQ_BLOCK *shm_seq_block;
char FAR *shm_seq_pc;
UNSIGNED_INT shm_seq_depth;
UNSIGNED_INT shm_seq_frames_done;
UNSIGNED_INT shm_seq_sound_queue_count;
struct SEQ_BLOCK shm_fullscreen_pan;
UNSIGNED_LONG shm_frame_deadline;
UNSIGNED_INT shm_seq_op;
INT shm_seq_operand;
UNSIGNED_INT shm_anim_fd;
UNSIGNED_INT shm_anim_magic_read;
UNSIGNED_INT shm_anim_packed;
char shm_anim_signature[5];
unsigned char shm_anim_row[320];
UNSIGNED_INT shm_source_fd;
UNSIGNED_INT shm_source_dst;
UNSIGNED_INT shm_source_src;
UNSIGNED_INT shm_sprite_width;
INT shm_sprite_height;
UNSIGNED_INT shm_palette_count;
struct JOYSTICK shm_joystick;
unsigned char shm_scratch[512];
INT asm_report_slots;
INT shm_difficulty;
UNSIGNED_INT asm_case_day;
INT asm_career_cursor;
INT asm_report_topics;
UNSIGNED_INT shm_clock_minutes;
struct CAMPAIGN shm_campaign;
UNSIGNED_INT shm_seed;
UNSIGNED_INT asm_screen_sprite_a;
UNSIGNED_INT asm_scene_sprites[5];
UNSIGNED_INT asm_screen_sprite_c;
INT shm_options;
INT shm_cga;
struct CITY shm_cities[16];
UNSIGNED_INT shm_menu_tick;
INT shm_suspect_count;
struct LOG_ENTRY shm_log[128];
INT shm_menu_face;
union REGS shm_mouse_regs;
INT shm_wire_clue_source;
struct CRIME_EVENT shm_crime_events[64];
INT shm_log_count;
INT shm_menu_first_line;
INT shm_building_count;
INT shm_case_tick;
INT shm_frame_ticks;
UNSIGNED_INT asm_shown_count;
rt_addr shm_source_at;
INT shm_case_city_1;
UNSIGNED_INT shm_case_city_2;
UNSIGNED_INT shm_anim_more;
UNSIGNED_INT shm_pan_playing;
unsigned char shm_anim_palette[774];
INT asm_report_total;
UNSIGNED_INT asm_case_minute;
UNSIGNED_INT shm_menu_no_pick;
UNSIGNED_INT asm_DAT_20d8_9bee;
struct CAMPAIGN shm_probed_campaign;
INT shm_menu_items;
UNSIGNED_INT shm_anim_segment;
UNSIGNED_INT asm_case_hour;
UNSIGNED_INT shm_seq_ticks;
UNSIGNED_INT asm_DAT_20d8_9e86;
INT shm_crime_event_count;
UNSIGNED_INT shm_case_seed;
UNSIGNED_INT shm_clue_method;
UNSIGNED_INT shm_menu_relayout;
INT shm_mission;
UNSIGNED_INT shm_menu_colour_bar;
INT shm_case_org_1;
INT shm_menu_text_width;
UNSIGNED_INT shm_case_org_2;
UNSIGNED_INT shm_faces_sprites[116];
INT shm_global_alert_level;
UNSIGNED_INT shm_slots_filled;
union REGS shm_regs;
UNSIGNED_INT shm_anim_error;
UNSIGNED_INT shm_double_agent_cities;
INT shm_crime_role_count;
UNSIGNED_INT shm_menu_marked;
struct CRIME_ROLE shm_crime_roles[32];
UNSIGNED_INT asm_fresh_start;
UNSIGNED_INT shm_seq_done;
rt_addr shm_refill;
unsigned char shm_archive_buffer[512];
UNSIGNED_INT shm_menu_face_x;
UNSIGNED_INT shm_menu_draw_only;
UNSIGNED_INT shm_skills;
UNSIGNED_INT shm_mouse_buttons;
UNSIGNED_INT shm_mouse_x;
UNSIGNED_INT shm_mouse_y;
UNSIGNED_INT shm_mouse_count;
UNSIGNED_INT shm_menu_face_y;
struct ORG_STATE shm_orgs[16];
UNSIGNED_INT shm_anim_sprites[250];
rt_addr shm_anim_name;
UNSIGNED_INT asm_case_mastermind;
INT shm_finished;
UNSIGNED_INT asm_case_flags;
unsigned char shm_menu_shortcut[32];
UNSIGNED_INT shm_menu_pick;
UNSIGNED_INT asm_case_city_3;
struct CRIME_ENTRY shm_crime_block[4];
UNSIGNED_INT asm_masterminds_arrested;
UNSIGNED_INT shm_menu_right;
unsigned char shm_substitute_tail[256];
struct ROLE_SCAN_STATE shm_role_scan_states[32];
unsigned char shm_graphics_letter;
UNSIGNED_INT shm_menu_bottom;
UNSIGNED_INT shm_seq_stop_asked;
UNSIGNED_INT asm_set_first;
INT shm_case_city;
struct ACTIVITY shm_activity;
UNSIGNED_INT shm_orgs_known;
UNSIGNED_INT asm_dossier_seen;
INT shm_slot_pick;
UNSIGNED_INT shm_case_spare_2;
unsigned char shm_anim_row_2[320];
struct FAME_ENTRY asm_fame[6];
INT asm_case_points;
UNSIGNED_INT shm_anim_block_kind;
INT asm_grid_in_play;
INT shm_seq_vars[51];
UNSIGNED_INT shm_case_org;
#endif
