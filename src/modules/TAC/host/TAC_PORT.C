#ifdef PORT_MODERN
#include "TAC_PORT.H"

unsigned char dat_str_env_sve[8] = "env.sve";
unsigned char dat_str_camera_pic[11] = "camera.pic";
unsigned char dat_str_guys3_pic[10] = "guys3.pic";
unsigned char dat_str_guys2_pic[10] = "guys2.pic";
unsigned char dat_str_equip1_pic[11] = "equip1.pic";
unsigned char dat_str_equip1m_pic[12] = "equip1m.pic";
unsigned char dat_str_env_sve_2[8] = "env.sve";
struct ROOM_KIND dat_room_kinds[10] = {
    { "Office", 4, 2, 7 },
    { "File Room", 6, 1, 7 },
    { "Computer Room", 8, 4, 7 },
    { "Cafeteria", 2, 4, 7 },
    { "Lounge", 2, 2, 7 },
    { "Cipher Room", 12, 1, 7 },
    { "Bed Room", 6, 2, 0 },
    { "Bathroom", 12, 1, 7 },
    { "Kitchen", 4, 2, 0 },
    { "Storage Room", 4, 4, 7 },
};
struct FLOOR_OBJECT dat_floor_objects[62] = {
    { "Wall", 0, 0, 0, 0 },
    { "Wall", 16, 0, 0, 0 },
    { "Wall", 32, 0, 0, 0 },
    { "Wall", 48, 0, 0, 0 },
    { "Wall", 64, 0, 0, 0 },
    { "Wall", 80, 0, 0, 0 },
    { "Wall", 96, 0, 0, 0 },
    { "Wall", 112, 0, 0, 0 },
    { "Door", 64, 16, 18, 0 },
    { "Door", 80, 16, 18, 0 },
    { "Door", 96, 16, 18, 0 },
    { "Door", 112, 16, 18, 0 },
    { "Chair", 128, 0, 1, 537 },
    { "Chair", 144, 0, 1, 536 },
    { "Chair", 160, 0, 1, 537 },
    { "Chair", 176, 0, 1, 536 },
    { "Terminal", 192, 0, 513, 37 },
    { "Typewriter", 208, 0, 5, 3 },
    { "Terminal", 224, 0, 513, 33 },
    { "Typewriter", 240, 0, 5, 3 },
    { "Chair", 256, 0, 1, 1093 },
    { "Plant", 272, 0, 5, 1105 },
    { "Chair", 288, 0, 1, 1093 },
    { "Plant", 304, 0, 5, 1105 },
    { "Files", 128, 16, 299, 519 },
    { "Files", 144, 16, 299, 551 },
    { "Files", 160, 16, 299, 519 },
    { "Files", 176, 16, 299, 551 },
    { "Floor Safe", 192, 16, 299, 102 },
    { "Wall Safe", 208, 16, 266, 35 },
    { "Picture", 224, 16, 262, 1113 },
    { "Wall Safe", 240, 16, 266, 1123 },
    { "Table", 64, 48, 129, 792 },
    { "Table", 80, 48, 129, 792 },
    { "Desk", 32, 16, 75, 1 },
    { "Desk", 48, 16, 75, 1 },
    { "Desk", 0, 16, 75, 1 },
    { "Desk", 16, 16, 75, 1 },
    { "Couch", 96, 48, 69, 1553 },
    { "Couch", 112, 48, 69, 1553 },
    { "Toilet", 0, 64, 267, 128 },
    { "Toilet", 16, 64, 267, 128 },
    { "Sink", 96, 64, 267, 128 },
    { "Sink", 112, 64, 267, 128 },
    { "Bathtub", 128, 64, 65, 128 },
    { "Bathtub", 144, 64, 65, 128 },
    { "Bed", 192, 48, 65, 64 },
    { "Bed", 208, 48, 65, 64 },
    { "Range", 160, 64, 257, 256 },
    { "Range", 176, 64, 257, 256 },
    { "Refrigerator", 192, 80, 289, 256 },
    { "Refrigerator", 208, 80, 289, 256 },
    { "Stereo", 224, 48, 257, 1616 },
    { "Television", 240, 48, 257, 1088 },
    { "Lamp", 256, 48, 257, 1544 },
    { "Television", 272, 48, 257, 1024 },
    { "Computer", 0, 48, 293, 36 },
    { "Drawers", 16, 96, 267, 1088 },
    { "Computer", 32, 48, 293, 36 },
    { "Drawers", 48, 96, 267, 1088 },
    { "MacGuffin  ", 0, 96, 3, 0 },
    { "Local Agent", 256, 16, 3, 0 },
};
INT dat_move_dx[9] = {
    0x0000, 0x0000, 0x0002, 0x0003, 0x0002, 0x0000,
    -2, -3, -2,
};
INT dat_move_dy[9] = {
    0x0000, -3, -2, 0x0000, 0x0002, 0x0003,
    0x0002, 0x0000, -2,
};
INT dat_step_dx[9] = {
    0x0000, 0x0000, 0x0001, 0x0001, 0x0001, 0x0000,
    -1, -1, -1,
};
INT dat_step_dy[9] = {
    0x0000, -1, -1, 0x0000, 0x0001, 0x0001,
    0x0001, 0x0000, -1,
};
INT dat_side_dx[5] = {
    0x0000, 0x0001, 0x0000, -1, 0x0000,
};
INT dat_side_dy[5] = {
    -1, 0x0000, 0x0001, 0x0000, -1,
};
struct RASTPORT dat_status_page_port = { 2, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *asm_status_page = (struct RASTPORT *) &dat_status_page_port;
struct RASTPORT dat_cast_frames_port = { 2, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *dat_cast_frames = (struct RASTPORT *) &dat_cast_frames_port;
struct RASTPORT dat_saved_page_port = { 3, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *asm_saved_page = (struct RASTPORT *) &dat_saved_page_port;
struct SUSPECT shm_suspects[64];
struct BUILDING shm_buildings[256];
struct SHOWN_CLUE shm_clues_shown[80];
UNSIGNED_INT shm_jailbreak_suspect = 0xffff;
struct RASTPORT dat_map_page_port = { 1, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *shd_map_page = (struct RASTPORT *) &dat_map_page_port;
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
struct COLOUR_MAP dat_colours_tactical = {
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
INT asm_game_speed = 0x0001;
UNSIGNED_INT dat_room_mask = 0x0001;
UNSIGNED_INT shd_pan_disk = 0x0003;
struct PALETTE shd_palette_records[5] = {
    {
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
        0x00,
        0x0e,
        0x0f,
        0x00,
    },
    {
        0x00,
        0x01,
        0x02,
        0x0f,
        0x04,
        0x00,
        0x06,
        0x07,
        0x08,
        0x09,
        0x0a,
        0x0b,
        0x0c,
        0x00,
        0x0e,
        0x0f,
        0x00,
    },
    {
        0x00,
        0x01,
        0x02,
        0x03,
        0x04,
        0x00,
        0x06,
        0x0c,
        0x08,
        0x09,
        0x0a,
        0x0b,
        0x0c,
        0x00,
        0x0e,
        0x0f,
        0x00,
    },
    {
        0x00,
        0x01,
        0x02,
        0x0e,
        0x04,
        0x00,
        0x06,
        0x07,
        0x08,
        0x09,
        0x0a,
        0x0b,
        0x0c,
        0x00,
        0x0e,
        0x0f,
        0x00,
    },
    {
        0x00,
        0x01,
        0x02,
        0x00,
        0x04,
        0x00,
        0x06,
        0x07,
        0x08,
        0x09,
        0x0a,
        0x0b,
        0x0c,
        0x00,
        0x0e,
        0x0f,
        0x00,
    },
};
UNSIGNED_INT asm_page_3;
unsigned char dat_str_empty_15;
unsigned char dat_str_which_door[16] = "Which door?  \n ";
unsigned char dat_str_door_5[7] = "Door #";
unsigned char dat_str_newline_13[4] = "\n ";
INT asm_facing = 0x0004;
INT asm_facing_goal = 0x0004;
unsigned char dat_str_paused[8] = "PAUSED\n";
unsigned char dat_str_sure_want_quit_no[42] =
    "Are you sure\nyou want to Quit?\n No\n Yes\n";
INT dat_joystick_keys[9] = {
    0x0000, 0x0048, 0x0049, 0x004d, 0x0051, 0x0050,
    0x004f, 0x004b, 0x0047,
};
UNSIGNED_INT asm_shot_fired;
char dat_meter_colours[5] = {
    0x00, 0x08, 0x03, 0x07, 0x0f,
};
unsigned char dat_str_set_trap_cancel_remote[47] =
    "Set trap\n Cancel\n Remote Control\n Booby Trap\n";
unsigned char dat_str_empty_16;
unsigned char dat_str_do_want_arrest[23] = "Do you want to\narrest ";
unsigned char dat_str_question[12] = "?\n Yes\n No\n";
unsigned char dat_str_bug[9] = " ... bug";
unsigned char dat_str_photo[11] = " ... photo";
unsigned char dat_str_closed[9] = " closed.";
unsigned char dat_str_nothing_photograph[23] = "Nothing to photograph.";
unsigned char dat_str_already_photographed[22] = "Already photographed.";
unsigned char dat_str_photographed[15] = " photographed.";
unsigned char dat_str_open[6] = "Open ";
unsigned char dat_str_first[8] = " first.";
unsigned char dat_str_out_film[13] = "Out of film.";
unsigned char dat_str_empty_17;
unsigned char dat_str_bugged[9] = " bugged.";
unsigned char dat_str_room_already_bugged[21] = "Room already bugged.";
unsigned char dat_str_nothing_bug[16] = "Nothing to bug.";
unsigned char dat_str_gas[4] = "GAS";
unsigned char dat_str_disguise[9] = "Disguise";
unsigned char dat_str_overcome_by_gas_pass[39] =
    "You are overcome\nby gas and pass out.\n";
unsigned char dat_str_slump_ground_overcome[51] =
    "You slump to\nthe ground, overcome\nby your wounds.\n";
unsigned char dat_str_prisoner_released_while[57] =
    "The prisoner is\nreleased while you\nare out of the room.\n";
unsigned char dat_str_have_eliminated_all[42] =
    "You have eliminated\nall of your enemies.\n";
unsigned char dat_str_quickly_slip_out[39] =
    "You quickly slip\nout of the building.\n";
unsigned char dat_str_cia_agent[18] = "The CIA agent in\n";
unsigned char dat_str_double_agent[22] = " is\na double agent!!\n";
unsigned char dat_str_now[9] = " now\nin ";
unsigned char dat_str_bang_2[3] = "!\n";
unsigned char dat_str_find[10] = "You find\n";
unsigned char dat_str_bang_3[3] = "!\n";
unsigned char dat_str_empty_18[1];
unsigned char dat_str_has_been_identified_as[52] =
    " has\nbeen identified as\na participant\nin the plot.\n";
unsigned char dat_str_find_incriminating[49] =
    "You find incriminating\nevidence which will\nturn ";
unsigned char dat_str_into_double_agent[23] = "\ninto a double agent!\n";
INT dat_tip_items[8] = {
    0x0002, 0x0005, 0x0006, 0x0007, 0x0008, 0x0009,
    0x000a, 0x000f,
};
unsigned char dat_str_mode_read_text_2[3] = "rt";
unsigned char dat_str_text_dta[9] = "text.dta";
unsigned char dat_fmt_word[5] = "%32s";
unsigned char dat_fmt_word_2[5] = "%32s";
unsigned char dat_password_hint_initial[11] = "..........";
unsigned char dat_str_enter_password[16] = "Enter PassWord:";
unsigned char dat_str_empty_19[1];
unsigned char dat_str_access_confirmed[17] = "Access CONFIRMED";
unsigned char dat_str_access_denied[14] = "Access DENIED";
unsigned char dat_str_search[12] = "Search for:";
unsigned char dat_str_has[6] = " has\n";
unsigned char dat_str_a[2] = "a";
unsigned char dat_str_no_operatives[14] = "no operatives";
unsigned char dat_str_newline_in[5] = "\nin ";
unsigned char dat_str_newline_14[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_has_no_operatives[19] = " has\nno operatives";
unsigned char dat_str_newline_in_2[5] = "\nin ";
unsigned char dat_str_newline_15[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_now_2[9] = " now\nin ";
unsigned char dat_str_bang[3] = "!\n";
unsigned char dat_str_empty_20[1];
unsigned char dat_str_no_data[9] = "No Data";
char dat_wall_tiles[16] = {
    0x00, 0x00, 0x01, 0x04, 0x02, 0x00, 0x05, 0x00, 0x03, 0x07, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00,
};
unsigned char dat_str_street[7] = "Street";
unsigned char dat_str_spritesf_pic[13] = "spritesf.pic";
unsigned char dat_str_sprites_pic[12] = "sprites.pic";
INT dat_step_facing[9] = {
    0x0008, 0x0007, 0x0006, 0x0001, 0x0000, 0x0005,
    0x0002, 0x0003, 0x0004,
};
UNSIGNED_INT dat_no_room = 0xffff;
unsigned char dat_str_pistol[7] = "Pistol";
unsigned char dat_str_uzi[4] = "Uzi";
unsigned char dat_str_camera[7] = "Camera";
unsigned char dat_str_bugs[5] = "Bugs";
unsigned char dat_str_safecracking_tools[19] = "Safecracking Tools";
unsigned char dat_str_gas_mask[9] = "Gas Mask";
unsigned char dat_str_kevlar_vest[12] = "Kevlar Vest";
unsigned char dat_str_motion_detector[16] = "Motion Detector";
unsigned char dat_str_fragmentation_grenades[23] = "Fragmentation Grenades";
unsigned char dat_str_gas_grenades[13] = "Gas Grenades";
unsigned char dat_str_stun_grenades[14] = "Stun Grenades";
unsigned char dat_str_assorted_grenades[18] = "Assorted Grenades";
unsigned char dat_str_empty_kit_1[1];
unsigned char dat_str_empty_kit_2[1];
unsigned char dat_str_empty_kit_3[1];
unsigned char dat_str_floor_plan[11] = "Floor Plan";
unsigned char dat_str_equip2_pic[11] = "equip2.pic";
unsigned char *addr_kit_names[16] = {
    (unsigned char *) dat_str_pistol, (unsigned char *) dat_str_uzi,
    (unsigned char *) dat_str_camera, (unsigned char *) dat_str_bugs,
    (unsigned char *) dat_str_safecracking_tools,
    (unsigned char *) dat_str_gas_mask, (unsigned char *) dat_str_kevlar_vest,
    (unsigned char *) dat_str_motion_detector,
    (unsigned char *) dat_str_fragmentation_grenades,
    (unsigned char *) dat_str_gas_grenades,
    (unsigned char *) dat_str_stun_grenades,
    (unsigned char *) dat_str_assorted_grenades,
    (unsigned char *) dat_str_empty_kit_1,
    (unsigned char *) dat_str_empty_kit_2,
    (unsigned char *) dat_str_empty_kit_3,
    (unsigned char *) dat_str_floor_plan,
};
struct KIT_BOX dat_kit_boxes[12] = {
    { 0, 0, 0, 0 },
    { 1, 2, 1, 5 },
    { 1, 3, 2, 6 },
    { 2, 8, 3, 6 },
    { 6, 4, 8, 4 },
    { 5, 6, 1, 7 },
    { 7, 4, 2, 6 },
    { 7, 6, 5, 7 },
    { 3, 9, 8, 4 },
    { 8, 10, 9, 4 },
    { 9, 11, 10, 4 },
    { 10, 11, 11, 4 },
};
struct POINT dat_kit_points[13] = {
    { 170, 48 },
    { 166, 46 },
    { 216, 73 },
    { 229, 7 },
    { 252, 70 },
    { 247, 0 },
    { 247, 31 },
    { 266, 0 },
    { 172, 3 },
    { 172, 17 },
    { 172, 31 },
    { 172, 71 },
    { 172, 80 },
};
struct RECT dat_kit_sprite_rects[15] = {
    { 162, 25, 189, 38 },
    { 162, 71, 220, 93 },
    { 272, 101, 296, 122 },
    { 258, 41, 264, 45 },
    { 220, 172, 273, 198 },
    { 254, 1, 291, 31 },
    { 223, 71, 270, 132 },
    { 246, 41, 255, 58 },
    { 285, 137, 293, 149 },
    { 285, 152, 293, 164 },
    { 285, 167, 293, 179 },
    { 201, 41, 203, 47 },
    { 188, 41, 198, 55 },
    { 162, 95, 170, 101 },
    { 298, 101, 312, 113 },
};
struct RECT dat_kit_slot_rects[12] = {
    { 0, 0, 0, 0 },
    { 2, 15, 62, 39 },
    { 2, 54, 62, 72 },
    { 2, 88, 62, 105 },
    { 69, 136, 157, 184 },
    { 69, 15, 113, 50 },
    { 69, 60, 157, 126 },
    { 116, 15, 157, 50 },
    { 2, 122, 62, 138 },
    { 2, 140, 62, 154 },
    { 2, 156, 62, 170 },
    { 2, 172, 62, 186 },
};
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
unsigned char shd_str_empty_positively;
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
unsigned char dat_str_mastermind[11] = "MasterMind";
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
unsigned char dat_str_liberian_passport[20] = "Liberian Passport #";
rt_addr shd_clue_kinds[80] = {
    (rt_addr) dat_str_recruit, (rt_addr) dat_str_operative,
    (rt_addr) dat_str_technician, (rt_addr) dat_str_agent,
    (rt_addr) dat_str_organizer, (rt_addr) dat_str_special_agent,
    (rt_addr) dat_str_group_leader, (rt_addr) dat_str_mastermind,
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
unsigned char shd_str_clues_txt[11] = "clues.txt";
rt_addr shd_clue_keys[5] = {
    (rt_addr) dat_msg_key, (rt_addr) dat_msg_name, (rt_addr) dat_msg_org,
    (rt_addr) dat_msg_city, (rt_addr) dat_msg_role,
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
unsigned char shd_str_empty_message;
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
unsigned char shd_str_faces_pic[10] = "faces.pic";
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
unsigned char shd_str_no_activity[15] = "(No activity)";
unsigned char shd_clock_text[9] = "00:00:00";
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
struct RASTPORT dat_screen_port = { 0, 0, 0, 319, 199, 1, 15, 4, 0 };
struct RASTPORT *shd_screen = (struct RASTPORT *) &dat_screen_port;
rt_addr shd_archive_buffer_end = (rt_addr) &asm_view_left;
INT shd_archive_fd = -1;
union REGS asm_regs;
unsigned char asm_number_digits_3[10];
INT asm_blip_x[9];
INT asm_blip_y[9];
INT asm_cast_x[9];
INT asm_cast_y[9];
UNSIGNED_INT asm_signs_here;
UNSIGNED_INT asm_disguise_label_shown;
UNSIGNED_INT asm_gas_label_shown;
UNSIGNED_INT asm_move_cost;
UNSIGNED_INT asm_direction_keycode;
UNSIGNED_INT asm_shooter;
UNSIGNED_INT asm_flash_x;
UNSIGNED_INT asm_flash_y;
INT shm_field_cursor;
UNSIGNED_INT shm_field_char_width;
UNSIGNED_INT shm_field_cursor_x;
INT asm_room_doorways[24];
char asm_step_map[9][1280];
INT asm_last_grenade_tick;
unsigned char asm_path_queue_col[256];
unsigned char asm_path_queue_row[256];
unsigned char asm_number_digits[26];
unsigned char shm_clue_digits[32];
unsigned char shm_message_key[9];
struct SEQ_BLOCK shm_active_pan;
INT shm_menu_line_start[32];
UNSIGNED_INT shm_menu_colour_plain;
UNSIGNED_INT shm_menu_colour_item;
INT shm_menu_lines;
UNSIGNED_INT shm_menu_colour_pick;
unsigned char FAR *shm_save_block;
UNSIGNED_INT shm_save_offset;
INT shm_save_fd;
UNSIGNED_INT shm_source_fd;
UNSIGNED_INT shm_source_dst;
UNSIGNED_INT shm_source_src;
INT shm_sprite_width;
INT shm_sprite_height;
UNSIGNED_INT shm_palette_count;
INT asm_org_alert_level;
UNSIGNED_INT asm_photo_score;
struct JOYSTICK shm_joystick;
UNSIGNED_INT asm_clips_left;
INT asm_palette_flash;
unsigned char shm_scratch[512];
UNSIGNED_INT asm_guard_seen;
UNSIGNED_INT asm_disguised;
UNSIGNED_INT asm_night;
INT shm_difficulty;
UNSIGNED_INT asm_panel_x;
UNSIGNED_INT asm_panel_y;
INT shm_clock_minutes;
INT asm_guard_alert;
UNSIGNED_INT asm_jump_ticks;
char asm_floor_map[1280];
INT asm_guard_room;
UNSIGNED_INT asm_guards_at_target;
INT asm_crouch_walk_ticks;
UNSIGNED_INT asm_shot_timer;
UNSIGNED_INT asm_rounds_left;
struct DOORWAY asm_doorways[96];
struct CAMPAIGN shm_campaign;
UNSIGNED_INT shm_seed;
INT shm_options;
UNSIGNED_INT asm_room_right;
INT shm_cga;
UNSIGNED_INT asm_radar_sprite;
UNSIGNED_INT asm_readout_sprite;
UNSIGNED_INT asm_kit;
UNSIGNED_INT asm_room_bottom;
INT asm_effect;
struct GRENADE asm_grenades[16];
struct CITY shm_cities[16];
UNSIGNED_INT asm_photos_taken;
UNSIGNED_INT asm_player_cell;
UNSIGNED_INT asm_kit_sprites[15];
UNSIGNED_INT asm_player_cell_row;
struct ROOM asm_rooms[24];
INT asm_room_seen_tick[24];
UNSIGNED_INT asm_room_seen;
UNSIGNED_INT shm_menu_tick;
INT shm_suspect_count;
INT asm_mission_kind;
struct LOG_ENTRY shm_log[128];
INT shm_menu_face;
UNSIGNED_INT asm_throw_frames;
UNSIGNED_INT asm_bugs_planted;
INT asm_frame_tick;
INT shm_wire_clue_source;
struct CRIME_EVENT shm_crime_events[64];
INT shm_log_count;
INT shm_menu_first_line;
UNSIGNED_INT asm_seen_longest;
UNSIGNED_INT asm_guard_sees;
INT asm_room_count;
INT asm_player_col;
INT shm_building_count;
UNSIGNED_INT asm_guard_in_room;
INT shm_case_tick;
INT asm_cursor_col;
INT asm_player_row;
char asm_room_map[1280];
INT asm_cursor_row;
UNSIGNED_INT asm_last_move_type;
UNSIGNED_INT asm_room_left;
INT asm_payload_room;
rt_addr shm_source_at;
UNSIGNED_INT asm_room_top;
INT shm_case_city_1;
INT asm_guard_distances[24];
UNSIGNED_INT shm_case_city_2;
INT asm_ammunition[3];
UNSIGNED_INT shm_pan_playing;
UNSIGNED_INT asm_walked;
UNSIGNED_INT asm_bug_score;
UNSIGNED_INT shm_menu_no_pick;
INT shm_menu_items;
INT asm_crouched;
INT asm_hour;
UNSIGNED_INT asm_walk_frame;
UNSIGNED_INT asm_film_left;
INT shm_crime_event_count;
UNSIGNED_INT asm_high_security;
UNSIGNED_INT asm_alarm_sounded;
UNSIGNED_INT asm_bugs_left;
UNSIGNED_INT asm_guard_tick;
INT asm_player_x;
UNSIGNED_INT shm_case_seed;
UNSIGNED_INT shm_clue_method;
UNSIGNED_INT shm_menu_relayout;
unsigned char asm_outcome;
INT asm_player_y;
INT shm_mission;
UNSIGNED_INT shm_menu_colour_bar;
UNSIGNED_INT asm_guard_turn_at;
INT shm_case_org_1;
INT shm_menu_text_width;
UNSIGNED_INT shm_case_org_2;
UNSIGNED_INT shm_faces_sprites[116];
UNSIGNED_INT asm_tile_sprites[176];
INT asm_suspect_here;
INT asm_room_last;
INT shm_global_alert_level;
union REGS shm_regs;
UNSIGNED_INT shm_double_agent_cities;
INT shm_crime_role_count;
UNSIGNED_INT shm_menu_marked;
struct CRIME_ROLE shm_crime_roles[32];
rt_addr shm_refill;
unsigned char shm_archive_buffer[512];
UNSIGNED_INT asm_view_left;
UNSIGNED_INT shm_menu_face_x;
UNSIGNED_INT shm_menu_draw_only;
INT shm_skills;
UNSIGNED_INT asm_view_top;
struct ORG_STATE shm_orgs[16];
UNSIGNED_INT shm_menu_face_y;
unsigned char asm_password_text[33];
INT shm_finished;
INT asm_target_room;
struct PERSON asm_people[9];
unsigned char shm_menu_shortcut[32];
unsigned char asm_password_hint[11];
UNSIGNED_INT asm_belt_text;
UNSIGNED_INT shm_menu_pick;
struct CRIME_ENTRY shm_crime_block[4];
UNSIGNED_INT asm_end_line;
UNSIGNED_INT shm_menu_right;
unsigned char shm_substitute_tail[256];
struct ROLE_SCAN_STATE shm_role_scan_states[32];
UNSIGNED_INT asm_guards_awake;
INT asm_wounds;
unsigned char shm_graphics_letter;
UNSIGNED_INT shm_menu_bottom;
UNSIGNED_INT asm_sound_arg_1;
UNSIGNED_INT asm_sound_arg_2;
INT asm_seen_count;
INT shm_case_city;
struct ACTIVITY shm_activity;
UNSIGNED_INT shm_orgs_known;
UNSIGNED_INT shm_case_spare_2;
unsigned char shm_anim_row_2[320];
INT asm_difficulty_was;
UNSIGNED_INT asm_conspicuous;
INT asm_doorway_count;
INT asm_guards_to_come;
char asm_wall_map[1280];
INT shm_case_org;
#endif
