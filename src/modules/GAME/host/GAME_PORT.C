#ifdef PORT_MODERN
#include "GAME_PORT.H"

unsigned char dat_str_env_sve[8] = "env.sve";
unsigned char dat_str_one_moment_please[22] = "One moment please...\n";
struct SUSPECT shm_suspects[64];
struct BUILDING shm_buildings[256];
struct SHOWN_CLUE shm_clues_shown[80];
INT shm_jailbreak_suspect = -1;
struct RASTPORT dat_picture_page_port = { 2, 0, 0, 319, 199, 0, 15, 4, 0 };
struct RASTPORT *shd_picture_page = (struct RASTPORT *) &dat_picture_page_port;
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
struct COLOUR_MAP shd_colours_paper = {
    0x00,
    0x11,
    0x11,
    0x11,
    0x22,
    0x00,
    0x22,
    0x12,
    0x00,
    0x11,
    0x11,
    0x33,
    0x33,
    0x22,
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
struct COLOUR_MAP dat_colours_statbar = {
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
struct COLOUR_MAP dat_colours_hq = {
    0x00,
    0x11,
    0x11,
    0x33,
    0x21,
    0x00,
    0x12,
    0x33,
    0x00,
    0x11,
    0x11,
    0x23,
    0x22,
    0x32,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_cia_entrance = {
    0x00,
    0x11,
    0x11,
    0x11,
    0x00,
    0x00,
    0x22,
    0x33,
    0x00,
    0x11,
    0x11,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_cia_office = {
    0x00,
    0x11,
    0x11,
    0x11,
    0x00,
    0x00,
    0x22,
    0x33,
    0x00,
    0x33,
    0x11,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_cia_hall = {
    0x00,
    0x11,
    0x11,
    0x11,
    0x00,
    0x00,
    0x22,
    0x33,
    0x00,
    0x33,
    0x11,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_escape_2 = {
    0x00,
    0x11,
    0x11,
    0x11,
    0x20,
    0x00,
    0x22,
    0x03,
    0x11,
    0x33,
    0x11,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_escape = {
    0x00,
    0x11,
    0x11,
    0x11,
    0x20,
    0x00,
    0x00,
    0x33,
    0x00,
    0x33,
    0x11,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_stakeout = {
    0x00,
    0x11,
    0x21,
    0x11,
    0x20,
    0x00,
    0x00,
    0x33,
    0x02,
    0x33,
    0x11,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_building[5] = {
    {
        0x00,
        0x11,
        0x21,
        0x11,
        0x22,
        0x00,
        0x22,
        0x33,
        0x22,
        0x33,
        0x11,
        0x11,
        0x22,
        0x22,
        0x33,
        0x33,
    },
    {
        0x00,
        0x11,
        0x21,
        0x11,
        0x00,
        0x00,
        0x22,
        0x11,
        0x22,
        0x11,
        0x11,
        0x11,
        0x22,
        0x22,
        0x33,
        0x33,
    },
    {
        0x00,
        0x11,
        0x22,
        0x11,
        0x00,
        0x00,
        0x22,
        0x11,
        0x22,
        0x12,
        0x11,
        0x11,
        0x22,
        0x22,
        0x33,
        0x33,
    },
    {
        0x00,
        0x00,
        0x22,
        0x11,
        0x00,
        0x00,
        0x22,
        0x11,
        0x22,
        0x12,
        0x11,
        0x11,
        0x22,
        0x22,
        0x33,
        0x33,
    },
    {
        0x00,
        0x00,
        0x22,
        0x11,
        0x22,
        0x00,
        0x22,
        0x11,
        0x00,
        0x11,
        0x11,
        0x11,
        0x22,
        0x22,
        0x33,
        0x33,
    },
};
struct COLOUR_MAP dat_colours_accuse = {
    0x00,
    0x00,
    0x22,
    0x11,
    0x22,
    0x00,
    0x33,
    0x11,
    0x22,
    0x11,
    0x11,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_advice = {
    0x00,
    0x20,
    0x22,
    0x11,
    0x00,
    0x00,
    0x22,
    0x13,
    0x00,
    0x11,
    0x33,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_city_2 = {
    0x00,
    0x22,
    0x11,
    0x11,
    0x00,
    0x00,
    0x22,
    0x11,
    0x00,
    0x11,
    0x33,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_building_2 = {
    0x00,
    0x11,
    0x11,
    0x21,
    0x00,
    0x00,
    0x22,
    0x00,
    0x22,
    0x11,
    0x33,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_stakeout_2 = {
    0x00,
    0x11,
    0x11,
    0x21,
    0x00,
    0x00,
    0x22,
    0x00,
    0x02,
    0x33,
    0x33,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_accuse_2 = {
    0x00,
    0x11,
    0x12,
    0x11,
    0x22,
    0x00,
    0x22,
    0x33,
    0x20,
    0x33,
    0x11,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct COLOUR_MAP dat_colours_map = {
    0x00,
    0x12,
    0x11,
    0x11,
    0x11,
    0x00,
    0x22,
    0x33,
    0x22,
    0x33,
    0x33,
    0x11,
    0x33,
    0x22,
    0x33,
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
struct COLOUR_MAP dat_colours_city = {
    0x00,
    0x02,
    0x11,
    0x11,
    0x00,
    0x00,
    0x22,
    0x11,
    0x33,
    0x11,
    0x22,
    0x11,
    0x22,
    0x22,
    0x33,
    0x33,
};
struct PALETTE dat_palette_game = {
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
UNSIGNED_INT shd_pan_disk = 0x0002;
unsigned char dat_str_animation_pan[14] = "animation.pan";
unsigned char dat_str_env_sve_2[8] = "env.sve";
unsigned char dat_str_ad_pic[7] = "ad.pic";
unsigned char shd_str_newline_wrap[2] = {
    0x0a, 0x00,
};
unsigned char shd_str_ellipsis_2[6] = " ... ";
unsigned char shd_str_hideout[9] = " hideout";
unsigned char shd_str_agent[7] = " agent";
unsigned char shd_str_safehouse[11] = " safehouse";
unsigned char shd_str_active_cel[12] = " active cel";
unsigned char shd_str_office[8] = " office";
unsigned char dat_str_agent_2[8] = "Agent A";
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
unsigned char dat_str_space_14[3] = " ";
unsigned char *dat_first_names[2][64] = {
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
unsigned char *dat_last_names[64] = {
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
unsigned char dat_str_master_plan[12] = "Master Plan";
unsigned char dat_str_secret[11] = "--SECRET--";
unsigned char dat_str_arrested[9] = "ARRESTED";
unsigned char dat_str_hiding[10] = "IN HIDING";
unsigned char dat_str_turned[8] = " TURNED";
unsigned char dat_str_personnel_file[15] = "Personnel File";
unsigned char dat_str_action_team[13] = " Action Team";
unsigned char dat_str_comma_4[3] = ", ";
unsigned char dat_str_no_activity[14] = "(No activity)";
unsigned char shd_clock_text[9] = "00:00:00";
unsigned char shd_str_incoming_msg[13] = "Incoming Msg";
unsigned char shd_list_printout[588] = {
    0x01, 0x00, 0x00, 0x00, 0x36, 0x00, 0x3f, 0x01, 0x37, 0x00, 0x08, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x38, 0x00, 0x3f, 0x01, 0xc7, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xa9, 0x00, 0x3f, 0x01, 0xa9, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x38, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x39, 0x00, 0x00, 0x00, 0xa7, 0x00, 0x0f, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x00, 0x00, 0xa8, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x01, 0x00, 0x38, 0x00, 0x01, 0x00, 0xa8, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x01, 0x00, 0xa9, 0x00, 0x01, 0x00, 0xa9, 0x00, 0x05, 0x00,
    0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x28, 0x00, 0x05, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x1f, 0x00, 0x62, 0x00, 0x22, 0x01, 0xa5, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x1f, 0x00, 0x61, 0x00, 0x22, 0x01, 0x61, 0x00, 0x05, 0x00,
    0x01, 0x00, 0x1e, 0x00, 0xa6, 0x00, 0x23, 0x01, 0xa8, 0x00, 0x05, 0x00,
    0x00, 0x00, 0x1f, 0x00, 0x71, 0x00, 0x1f, 0x00, 0xa6, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x23, 0x01, 0x61, 0x00, 0x23, 0x01, 0xa7, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x22, 0x01, 0x71, 0x00, 0x22, 0x01, 0xa6, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x1e, 0x00, 0x61, 0x00, 0x1e, 0x00, 0xa7, 0x00, 0x08, 0x00,
    0x01, 0x00, 0x21, 0x00, 0xa0, 0x00, 0x20, 0x01, 0xa5, 0x00, 0x08, 0x00,
    0x01, 0x00, 0x32, 0x00, 0xa3, 0x00, 0x0d, 0x01, 0xa6, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x0e, 0x01, 0xa6, 0x00, 0x0e, 0x01, 0xa6, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x32, 0x00, 0xa7, 0x00, 0x0e, 0x01, 0xa7, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x0e, 0x01, 0xa6, 0x00, 0x0e, 0x01, 0xa6, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x32, 0x00, 0xa7, 0x00, 0x0e, 0x01, 0xa7, 0x00, 0x08, 0x00,
    0x00, 0x00, 0x1e, 0x00, 0xa9, 0x00, 0x23, 0x01, 0xa9, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xb1, 0x00, 0x3f, 0x01, 0xb1, 0x00, 0x0f, 0x00,
    0x01, 0x00, 0x04, 0x00, 0xb8, 0x00, 0x7c, 0x00, 0xc3, 0x00, 0x05, 0x00,
    0x01, 0x00, 0x7b, 0x00, 0xb9, 0x00, 0x7c, 0x00, 0xc2, 0x00, 0x08, 0x00,
    0x01, 0x00, 0x06, 0x00, 0xb9, 0x00, 0x7a, 0x00, 0xc2, 0x00, 0x02, 0x00,
    0x00, 0x00, 0x04, 0x00, 0xc4, 0x00, 0x7c, 0x00, 0xc4, 0x00, 0x0f, 0x00,
    0x01, 0x00, 0x92, 0x00, 0xb7, 0x00, 0xb2, 0x00, 0xc4, 0x00, 0x05, 0x00,
    0x01, 0x00, 0x94, 0x00, 0xb8, 0x00, 0xb0, 0x00, 0xc2, 0x00, 0x07, 0x00,
    0x00, 0x00, 0x93, 0x00, 0xb8, 0x00, 0x93, 0x00, 0xc2, 0x00, 0x0f, 0x00,
    0x00, 0x00, 0x94, 0x00, 0xb9, 0x00, 0x94, 0x00, 0xc1, 0x00, 0x0f, 0x00,
    0x00, 0x00, 0x95, 0x00, 0xb9, 0x00, 0xae, 0x00, 0xb9, 0x00, 0x0f, 0x00,
    0x00, 0x00, 0xb0, 0x00, 0xb9, 0x00, 0xb0, 0x00, 0xc1, 0x00, 0x08, 0x00,
    0x00, 0x00, 0xb1, 0x00, 0xb8, 0x00, 0xb1, 0x00, 0xc2, 0x00, 0x08, 0x00,
    0x02, 0x00, 0x29, 0x00, 0x00, 0x00, 0x03, 0x00, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0e, 0x01, 0xb8, 0x00, 0x3f, 0x01, 0xb8, 0x00, 0x05, 0x00,
    0x01, 0x00, 0x0e, 0x01, 0xb9, 0x00, 0x3f, 0x01, 0xc7, 0x00, 0x08, 0x00,
    0x01, 0x00, 0x10, 0x01, 0xc5, 0x00, 0x3f, 0x01, 0xc7, 0x00, 0x07, 0x00,
    0x01, 0x00, 0x12, 0x01, 0xbd, 0x00, 0x27, 0x01, 0xc1, 0x00, 0x05, 0x00,
    0x01, 0x00, 0x12, 0x01, 0xbc, 0x00, 0x26, 0x01, 0xc0, 0x00, 0x03, 0x00,
    0x00, 0x00, 0x11, 0x01, 0xbc, 0x00, 0x11, 0x01, 0xc0, 0x00, 0x0b, 0x00,
    0x00, 0x00, 0x12, 0x01, 0xbc, 0x00, 0x25, 0x01, 0xbc, 0x00, 0x0b, 0x00,
    0x01, 0x00, 0x2f, 0x01, 0xbd, 0x00, 0x33, 0x01, 0xc1, 0x00, 0x05, 0x00,
    0x01, 0x00, 0x2f, 0x01, 0xbc, 0x00, 0x32, 0x01, 0xc0, 0x00, 0x04, 0x00,
    0x00, 0x00, 0x2e, 0x01, 0xbc, 0x00, 0x2e, 0x01, 0xc0, 0x00, 0x0c, 0x00,
    0x00, 0x00, 0x2f, 0x01, 0xbc, 0x00, 0x31, 0x01, 0xbc, 0x00, 0x0c, 0x00,
    0x02, 0x00, 0x09, 0x00, 0x00, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
unsigned char dat_str_warning_pan[12] = "warning.pan";
unsigned char dat_str_jailbreak[14] = "JailBreak in ";
unsigned char dat_str_bang_nl[3] = "!\n";
unsigned char dat_str_agents_trying_free[28] = " agents\nare trying to\nfree ";
unsigned char dat_str_bang_nl_2[3] = "!\n";
unsigned char dat_str_bustout_pan[12] = "bustout.pan";
unsigned char dat_str_escapes[11] = " escapes!\n";
unsigned char dat_str_escape_attempt_foiled[24] = "Escape attempt foiled!\n";
unsigned char dat_str_car_tracer_leads_new[46] =
    "Your car tracer leads\nyou to a new building.\n";
unsigned char dat_str_carcap[8] = "*carcap";
unsigned char dat_str_wounded_pan[12] = "wounded.pan";
unsigned char dat_str_take_time_recover_from[43] =
    "You take time\nto recover from\nyour wounds\n";
unsigned char dat_str_surprisel[11] = "*surpriseL";
unsigned char dat_str_surprisew[11] = "*surpriseW";
unsigned char dat_str_you_are_in[12] = "You are in ";
unsigned char dat_str_do_go[19] = "\nDo you go to ...\n";
unsigned char dat_str_airport[15] = " The Airport.\n";
unsigned char dat_str_hotel[15] = " Your Hotel.\n ";
unsigned char dat_str_unknown_building[17] = "unknown building";
unsigned char dat_str_nl_space[3] = "\n ";
unsigned char dat_str_nl_space_2[3] = "\n ";
unsigned char dat_str_check_data[12] = "Check Data\n";
unsigned char dat_str_surprise[10] = "*surprise";
unsigned char dat_str_at[16] = "You are at the\n";
unsigned char dat_str_unknown_building_2[17] = "unknown building";
unsigned char dat_str_few_guards_peering[47] =
    "\nA few guards are\npeering through the\nwindows.";
unsigned char dat_str_appears_extra_guards[43] =
    "\nIt appears extra\nguards have been\nposted.";
unsigned char dat_str_building_swarming[39] =
    "\nThe building is\nswarming with guards.";
unsigned char dat_str_do_place_wiretap[28] = "\nDo you ...\n Place wiretap\n";
unsigned char dat_str_break_into_building[22] = " Break into building\n";
unsigned char dat_str_watch_building_check[40] =
    " Watch the building\n Check Data\n Leave\n";
unsigned char dat_str_blding01_pan[13] = "blding01.pan";
unsigned char dat_str_sneakin_pic[12] = "sneakin.pic";
unsigned char dat_str_wiretap_pic[12] = "wiretap.pic";
unsigned char dat_str_guards[16] = "The guards are ";
unsigned char dat_str_will_have[17] = ".\nYou will have ";
unsigned char dat_str_minutes[11] = " minutes.\n";
unsigned char dat_str_followed_pan[13] = "followed.pan";
unsigned char dat_str_followed[10] = "*followed";
unsigned char dat_str_hq_pan[7] = "hq.pan";
unsigned char dat_str_arrive_at_cia_building[61] =
    "You arrive at\nthe CIA building\nand check with\nyour contact.\n";
unsigned char dat_str_binos3_pan[11] = "binos3.pan";
unsigned char dat_str_notice_someone[19] = "You notice someone";
unsigned char dat_str_leaving_building[24] = "\nleaving the building.\n";
unsigned char dat_str_do_wait_follow_car[55] =
    "Do you ...\n Wait\n Follow car.\n Trace car.\n Check Data\n";
unsigned char dat_str_he_looks[10] = "He looks ";
unsigned char dat_str_she_looks[11] = "She looks ";
unsigned char dat_str_nl_dot[3] = "\n.";
unsigned char dat_str_bugcar_pan[11] = "bugcar.pan";
unsigned char dat_str_briefing_pan[13] = "briefing.pan";
unsigned char dat_str_good_job_max_found[29] = "Good job Max, You found the\n";
unsigned char dat_str_should_really_slow_down[50] =
    "!. That should really\nslow down their operation.\n";
unsigned char dat_str_intrgate_pan[13] = "intrgate.pan";
unsigned char dat_str_accuse[12] = "You accuse ";
unsigned char dat_str_taking_part_plot_we[59] =
    "\nof taking part in\nthe plot, 'We know\nthat your role was:\n";
unsigned char dat_str_dot_quote_nl[4] = ".'\n";
unsigned char dat_str_have_no_evidence[30] = "You have no evidence\nagainst ";
unsigned char dat_str_dot_nl_he[5] = ".\nHe";
unsigned char dat_str_dot_nl_she[6] = ".\nShe";
unsigned char dat_str_will_have_released[28] = " will have to\nbe released.\n";
unsigned char dat_str_inter1[8] = "*inter1";
unsigned char dat_str_doublea[9] = "*doublea";
unsigned char dat_str_inter2[8] = "*inter2";
unsigned char dat_str_ask[13] = ",\" you ask. ";
unsigned char dat_str_oh_yeah_i_guess[50] =
    "\"Oh yeah, I guess I did,\" the prisoner responds.\n";
unsigned char dat_str_hmmm_i_don_t[61] =
    "\"Hmmm..., I don't seem to remember.\", the suspect responds.\n";
unsigned char dat_str_mastermind_breaks_down[67] =
    "The MasterMind breaks down and lists the participants in the plot.";
unsigned char dat_str_injail_pan[11] = "injail.pan";
unsigned char dat_str_taken_local_jail[30] =
    "\nis taken to\nthe local jail.\n";
unsigned char dat_str_briefing_pan_2[13] = "briefing.pan";
unsigned char dat_str_nice0[7] = "*nice0";
unsigned char dat_str_prose_dta[10] = "prose.dta";
unsigned char dat_msg_rplc[6] = "$RPLC";
unsigned char dat_str_max_remington[14] = "Max Remington";
unsigned char dat_msg_name[6] = "$NAME";
unsigned char dat_msg_city[6] = "$CITY";
unsigned char dat_msg_org[5] = "$ORG";
unsigned char dat_key_us[4] = "$US";
unsigned char dat_str_surndr01_pan[13] = "surndr01.pan";
unsigned char dat_str_grilled[9] = "*grilled";
unsigned char dat_str_warning_pan_2[12] = "warning.pan";
unsigned char dat_str_jailbreak_2[14] = "JailBreak in ";
unsigned char dat_str_bang_nl_3[3] = "!\n";
unsigned char dat_str_agents_free[14] = " agents\nfree ";
unsigned char dat_str_bang_nl_4[3] = "!\n";
unsigned char dat_str_escape_pan[11] = "escape.pan";
unsigned char dat_str_escape[8] = "*escape";
unsigned char dat_str_no_thanks_squinty_agree[42] =
    " No thanks, Squinty.\n Agree to exchange.\n";
unsigned char dat_str_exchanged[23] = "You are exchanged\nfor ";
unsigned char dat_str_dot_nl[3] = ".\n";
unsigned char dat_str_two_double_agents[20] = "two double agents.\n";
unsigned char dat_str_europe_pic[11] = "europe.pic";
unsigned char dat_str_africa_pic[11] = "africa.pic";
unsigned char dat_str_central_pic[12] = "central.pic";
unsigned char dat_str_re[11] = "You're in ";
unsigned char dat_str_do_travel[23] = "\nDo you travel to ...\n";
unsigned char dat_str_stay_here[12] = " Stay here\n";
unsigned char dat_str_space[2] = " ";
unsigned char dat_str_nl[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_check_data_2[14] = " Check Data\n";
unsigned char asm_leg_x[8] = {
    0x00, 0x01, 0x01, 0x01, 0x00, 0xff, 0xff, 0xff,
};
unsigned char asm_leg_y[8] = {
    0xff, 0xff, 0x00, 0x01, 0x01, 0x01, 0x00, 0xff,
};
unsigned char asm_leg_next[9] = {
    0x07, 0x06, 0x05, 0x00, 0x00, 0x04, 0x01, 0x02, 0x03,
};
unsigned char dat_str_quiet[6] = "quiet";
unsigned char dat_str_unsuspecting[13] = "unsuspecting";
unsigned char dat_str_cautious[9] = "cautious";
unsigned char dat_str_suspicious[11] = "suspicious";
unsigned char dat_str_nervous[8] = "nervous";
unsigned char dat_str_very_nervous[13] = "very nervous";
unsigned char dat_str_briefing_pan_3[13] = "briefing.pan";
unsigned char dat_str_rest_up[24] = "The rest is up to you. ";
unsigned char dat_str_i_ve_assigned_one[81] =
    "I've assigned one of my best research assistants to work with you on this"
    " case. ";
unsigned char dat_str_president_s_counting[56] =
    "The President's counting on you Max, don't let us down.";
unsigned char dat_str_pic[5] = ".pic";
unsigned char dat_str_comma_space[3] = ", ";
unsigned char dat_str_cities_cat[12] = "cities.cat";
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
unsigned char dat_str_coded_message[23] = "       CODED MESSAGE:\n";
unsigned char dat_str_meeting_notes[23] = "       MEETING NOTES:\n";
unsigned char dat_str_new_information[24] = "       NEW INFORMATION\n";
unsigned char dat_str_additional_information[28] =
    "    ADDITIONAL INFORMATION\n";
unsigned char dat_str_space_2[2] = " ";
unsigned char dat_str_dots[6] = "\n... ";
unsigned char dat_str_on[4] = "on ";
unsigned char dat_str_space_2_2[2] = " ";
unsigned char dat_str_of_the[8] = "of the ";
unsigned char dat_str_in[4] = "in ";
unsigned char dat_str_newline[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_empty_4[1];
unsigned char dat_str_space_3[2] = " ";
unsigned char dat_str_in_2[5] = " in ";
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
unsigned char dat_str_empty_5[1];
unsigned char dat_str_has_been_identified_as[52] =
    " has been\nidentified as a participant\nin the plot.\n";
unsigned char dat_str_empty_6;
unsigned char dat_str_has_been_positively[36] =
    " has been positively\nidentified as ";
unsigned char dat_str_newline_2[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_we_have_acquired[34] =
    "We have acquired a\nphotograph of ";
unsigned char dat_str_stop[3] = ".\n";
unsigned char dat_str_empty_7[1];
unsigned char dat_str_has_been_spotted[22] = " has been\nspotted in ";
unsigned char dat_str_newline_3[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_empty_8[1];
unsigned char dat_str_has_been_identified_as_2[41] =
    " has been\nidentified as a member\nof the ";
unsigned char dat_str_newline_4[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_we_have_obtained[52] =
    "We have obtained\nadditional information\nconcerning ";
unsigned char dat_str_newline_5[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_we_have_determined_rank[32] =
    "We have determined\nthe rank of\n";
unsigned char dat_str_newline_6[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_we_found_recruiting[39] =
    "We found recruiting\ninformation about\n";
unsigned char dat_str_newline_7[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_we_found_recruiting_2[39] =
    "We found recruiting\ninformation about\n";
unsigned char dat_str_newline_8[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_recruit[8] = "Recruit";
unsigned char dat_str_operative[10] = "Operative";
unsigned char dat_str_technician[11] = "Technician";
unsigned char dat_str_agent_3[6] = "Agent";
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
    (rt_addr) dat_str_technician, (rt_addr) dat_str_agent_3,
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
unsigned char dat_str_clue[5] = "Clue";
unsigned char dat_str_source_2_2[10] = "\207Source: ";
unsigned char dat_str_slash[2] = "/";
unsigned char dat_str_newline_9[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_method_stop[11] = "\n\207Method: ";
unsigned char dat_str_related_2[16] = "\214Related Clues:";
unsigned char dat_str_newline_10[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_none[8] = "...none";
unsigned char *dat_clue_source[7] = {
    (unsigned char *) dat_str_clandestine_photo,
    (unsigned char *) dat_str_electronic_wiretap,
    (unsigned char *) dat_str_covert_surveillance,
    (unsigned char *) dat_str_file_record_search,
    (unsigned char *) dat_str_local_informant,
    (unsigned char *) dat_str_interpol_data_base,
    (unsigned char *) dat_str_local_authorities,
};
unsigned char dat_msg_key[5] = "$KEY";
unsigned char dat_msg_name_2[6] = "$NAME";
unsigned char dat_msg_org_2[5] = "$ORG";
unsigned char dat_msg_city_2[6] = "$CITY";
unsigned char dat_msg_role[6] = "$ROLE";
unsigned char dat_key_clue[7] = "*C0000";
unsigned char dat_str_clues_txt[11] = "clues.txt";
rt_addr shd_clue_keys[5] = {
    (rt_addr) dat_msg_key, (rt_addr) dat_msg_name_2, (rt_addr) dat_msg_org_2,
    (rt_addr) dat_msg_city_2, (rt_addr) dat_msg_role,
};
unsigned char shd_str_period[2] = ".";
unsigned char dat_str_face[11] = "this face.";
unsigned char dat_str_valkerie[9] = "Valkerie";
unsigned char dat_str_thunderbolt[12] = "Thunderbolt";
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
unsigned char dat_note_01[10] = "hotel.pic";
unsigned char dat_note_02[115] =
    "You are at your\nhotel. Do you...\n Leave Hotel\n Visit the lounge\n Slee"
    "p through case\n Save Game\n Load Game\n \n Quit\n";
unsigned char dat_note_03[8] = "*lounge";
unsigned char dat_note_04[68] =
    "Data Files...\n Clues\n Suspects\n Inside Information\n News Bulletins\n";
unsigned char dat_note_05[59] =
    " Organization Summaries\n City Summaries\n Activity Reports\n";
unsigned char dat_note_06[120] =
    "You are in the CIA building.\nWhich floor ?\n 1. Data Section\n 2. Intell"
    "igence Section\n 3. Crypto Branch\n Leave building\n";
unsigned char dat_note_07[9] = "comm.pan";
unsigned char dat_note_08[112] =
    "Intelligence Section...\n Local Scan\n International Scan\n Active Wire T"
    "aps\n Accuse Double Agent\n Check with Sam\n";
unsigned char dat_note_09[20] = "No new information\n";
unsigned char dat_note_10[20] = "No new information\n";
unsigned char dat_note_11[44] =
    "The local agent confesses\nand is replaced.\n";
unsigned char dat_note_12[52] =
    "You search his files\nfor additional information...\n";
unsigned char dat_note_13[93] =
    "The local agent is checked\nand proved innocent.\nYou are barred from\nus"
    "ing the local office.\n";
unsigned char dat_note_14[13] = "research.pan";
unsigned char dat_note_15[84] =
    "Data Section...\n Review Clues\n Review Suspects\n Inside Information\n N"
    "ews Bulletins\n";
unsigned char dat_note_16[55] =
    " Organization Summary\n City Summary\n Activity Reports\n";
unsigned char dat_note_17[11] = "crypto.pan";
unsigned char dat_note_18[52] =
    "Crypto Branch...\n Coded Messages\n Crime Chronology\n";
unsigned char dat_note_19[24] = "Activity Report Summary";
unsigned char dat_note_20[9] = "WireTaps";
unsigned char dat_str_empty_9[1];
unsigned char dat_str_slash_2[2] = "/";
unsigned char dat_str_dots_2[6] = " ... ";
unsigned char dat_str_percent[3] = "%\n";
unsigned char dat_str_none_2[7] = "none \n";
unsigned char dat_str_which_organization[24] = "Which organization ...\n";
unsigned char dat_str_allies[11] = "Allies: \n ";
unsigned char dat_str_nl_space_3[3] = "\n ";
unsigned char dat_str_none_3[5] = "none";
unsigned char dat_str_known_locations[19] = "Known Locations:\n-";
unsigned char dat_str_in_5[5] = " in ";
unsigned char dat_str_nl_dash[3] = "\n-";
unsigned char dat_str_associates[15] = "Associates: \n ";
unsigned char dat_str_nl_space_4[3] = "\n ";
unsigned char dat_str_none_4[5] = "none";
unsigned char dat_str_space_4[2] = " ";
unsigned char dat_str_newline_11[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_which_city[16] = "Which city ...\n";
unsigned char dat_str_known_locations_2[19] = "Known Locations:\n-";
unsigned char dat_str_unknown_building_3[18] = "Unknown building.";
unsigned char dat_str_nl_dash_2[3] = "\n-";
unsigned char dat_str_none_5[6] = "none\n";
unsigned char dat_str_suspects[12] = "Suspects:\n-";
unsigned char dat_str_slash_3[2] = "/";
unsigned char dat_str_ellipsis[7] = "\n... \214";
unsigned char dat_str_nl_dash_space[4] = "\n- ";
unsigned char dat_str_none_6[6] = "none\n";
unsigned char dat_str_clues[8] = "Clues:\n";
unsigned char dat_str_dash[2] = "-";
unsigned char dat_str_newline_12[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_none_7[6] = "none\n";
unsigned char dat_str_space_5[2] = " ";
unsigned char dat_str_newline_13[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_documents[10] = "Documents";
unsigned char dat_str_select_document[19] = "Select Document:\n ";
unsigned char dat_str_master_plan_2[14] = "Master Plan\n ";
unsigned char dat_str_personel_file[17] = " Personel File\n ";
unsigned char dat_str_none_8[7] = "none \n";
unsigned char dat_str_suspect_files[14] = "Suspect Files";
unsigned char dat_str_space_6[2] = " ";
unsigned char dat_str_of_the_3[9] = " of the ";
unsigned char dat_str_in_6[5] = " in ";
unsigned char dat_str_dot_nl_2[4] = ".\n ";
unsigned char dat_str_bullet[3] = "\214 ";
unsigned char dat_str_space_7[2] = " ";
unsigned char dat_str_arrested_2[11] = "(Arrested)";
unsigned char dat_str_hiding_3[9] = "(Hiding)";
unsigned char dat_str_turned_3[9] = "(Turned)";
unsigned char dat_str_custody[13] = "(In Custody)";
unsigned char dat_str_nl_2[3] = "\n ";
unsigned char dat_str_none_9[7] = "none \n";
unsigned char dat_str_coded_messages[15] = "Coded Messages";
unsigned char dat_str_space_8[2] = " ";
unsigned char dat_str_space_11[2] = " ";
unsigned char dat_str_nl_3[6] = "\n ...";
unsigned char dat_str_nl_4[3] = "\n ";
unsigned char dat_str_none_10[7] = " none\n";
unsigned char dat_str_message_decode[15] = "Message Decode";
unsigned char dat_str_from[6] = "FROM:";
unsigned char dat_str_to_heading[4] = "TO:";
unsigned char dat_str_message[9] = "MESSAGE:";
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
unsigned char dat_str_empty_9_2;
unsigned char dat_str_sloc00[8] = "*SLOC00";
unsigned char dat_str_text_dta[9] = "text.dta";
unsigned char dat_str_rloc00[8] = "*RLOC00";
unsigned char dat_str_text_dta_2[9] = "text.dta";
unsigned char dat_str_sorg00[8] = "*SORG00";
unsigned char dat_str_text_dta_3[9] = "text.dta";
unsigned char dat_str_rorg00[8] = "*RORG00";
unsigned char dat_str_text_dta_4[9] = "text.dta";
unsigned char dat_str_mark_80[2] = {
    0x80, 0x00,
};
unsigned char dat_str_text_dta_5[9] = "text.dta";
unsigned char dat_str_mark_8f[2] = {
    0x8f, 0x00,
};
unsigned char dat_str_fluf00[8] = "*FLUF00";
unsigned char dat_str_text_dta_6[9] = "text.dta";
unsigned char dat_str_alrt00[8] = "*ALRT00";
unsigned char dat_str_text_dta_7[9] = "text.dta";
unsigned char dat_str_aidd00[8] = "*AIDD00";
unsigned char dat_str_text_dta_8[9] = "text.dta";
unsigned char dat_str_text_dta_9[9] = "text.dta";
unsigned char shd_str_msg0000[9] = "*MSG0000";
unsigned char shd_str_facesf_pic[11] = "facesf.pic";
unsigned char shd_str_faces_pic[10] = "faces.pic";
unsigned char dat_str_bulletin[11] = "Bulletin: ";
unsigned char dat_str_has_gone_into_hiding[24] = " has gone into hiding.\n";
unsigned char dat_str_surveillance_team[18] = "Surveillance Team";
unsigned char dat_str_env_sve_3[8] = "env.sve";
unsigned char dat_str_interpol_bulletin[20] = "INTERPOL Bulletin:\n";
unsigned char dat_str_spotted[13] = " spotted in ";
unsigned char dat_str_bang_nl_5[3] = "!\n";
unsigned char dat_str_interpol[9] = "INTERPOL";
unsigned char dat_str_empty_10;
unsigned char dat_str_message_traffic[31] = "Message traffic detected.\n... ";
unsigned char dat_str_from_2[7] = "FROM: ";
unsigned char dat_str_to[5] = "TO: ";
unsigned char dat_str_dots_3[6] = " ...\n";
unsigned char dat_str_satellite_intercept[20] = "Satellite Intercept";
unsigned char dat_str_double_agent[15] = "Double Agent: ";
unsigned char dat_str_wiretap_at[12] = "Wiretap at ";
unsigned char dat_str_slash_4[2] = "/";
unsigned char dat_str_reveals[10] = " reveals ";
unsigned char dat_str_he[4] = "he ";
unsigned char dat_str_she_2[5] = "she ";
unsigned char dat_str_space_13[2] = " ";
unsigned char dat_str_nl_5[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_empty_12[1];
unsigned char dat_str_from_3[7] = "From: ";
unsigned char dat_str_slash_5[2] = "/";
unsigned char dat_str_nl_6[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_has_just_returned_from[35] =
    " has just returned from a trip to ";
unsigned char dat_str_dot_nl_3[3] = ".\n";
unsigned char dat_str_airport_surveillance[21] = "Airport Surveillance";
unsigned char dat_str_empty_13;
unsigned char dat_str_seems_have_departed[30] =
    " seems to have departed from ";
unsigned char dat_str_dot_nl_4[3] = ".\n";
unsigned char dat_str_airport_surveillance_2[21] = "Airport Surveillance";
unsigned char dat_str_bulletin_2[11] = "Bulletin:\n";
unsigned char dat_str_has_come_out_hiding[26] = " has come out of hiding!\n";
unsigned char dat_str_surveillance_team_2[18] = "Surveillance Team";
unsigned char dat_str_bulletin_3[11] = "Bulletin:\n";
unsigned char dat_str_has_come_out_hiding_2[26] = " has come out of hiding!\n";
unsigned char dat_str_surveillance_team_3[18] = "Surveillance Team";
unsigned char dat_str_day_slot[4] = " 10";
unsigned char asm_TIMESTAMP[16] = "00:00 AM Jun 00";
unsigned char dat_str_comma_space_2[4] = ", ";
INT asm_status_bar_y = 0x00ae;
unsigned char dat_str_arrested_3[9] = "ARRESTED";
unsigned char dat_str_turned_4[7] = "TURNED";
unsigned char dat_str_clues_2[6] = "Clues";
INT dat_clue_colours[4] = {
    0x000e, 0x000a, 0x000e, 0x000a,
};
INT asm_clue_selected;
unsigned char dat_str_clue_2[5] = "Clue";
unsigned char dat_str_source_3[10] = "\207Source: ";
unsigned char dat_str_slash_6[2] = "/";
unsigned char dat_str_nl_7[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_nl_8[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_arrested_4[9] = "ARRESTED";
unsigned char dat_str_hiding_4[10] = "IN HIDING";
unsigned char dat_str_turned_5[8] = " TURNED";
unsigned char dat_str_officem_pan[12] = "officem.pan";
unsigned char dat_str_officef_pan[12] = "officef.pan";
unsigned char dat_str_max_i_ve_been[57] =
    "Max, I've been\ngoing over the\ninfo we've got\nso far ...\n";
unsigned char dat_str_i_d_look_into[36] =
    "I'd look into\nthese organizations:\n";
unsigned char dat_str_space_15[2] = " ";
unsigned char dat_str_newline_17[2] = {
    0x0a, 0x00,
};
unsigned char dat_str_mark_8f_2[49] =
    "\217These cities have been\n\217pretty active lately:\n ";
unsigned char dat_str_newline_space[3] = "\n ";
unsigned char dat_str_there_s_not_much[39] =
    "There's not\nmuch to go\nat this point.\n";
unsigned char dat_str_the[5] = "The ";
unsigned char dat_str_has[7] = " has a";
unsigned char dat_str_right_here[16] = " right here in ";
unsigned char dat_str_i_d_suggest_go[60] =
    "! I'd suggest you go there and place a wiretap or break in.";
unsigned char dat_str_message_should_give_us[46] =
    "This message should give us some vital info: ";
unsigned char dat_str_space_16[2] = " ";
unsigned char dat_str_check_crypto_branch[32] =
    ". Check with the Crypto branch.";
unsigned char dat_str_max_we_ve_got[54] =
    "Max, we've got enough evidence to arrest this agent. ";
unsigned char dat_str_max_i_suggest_check[43] =
    "Max, I suggest you check out this person. ";
unsigned char dat_str_he_2[3] = "He";
unsigned char dat_str_she_3[4] = "She";
unsigned char dat_str_s_right_here[18] = "'s right here in ";
unsigned char dat_str_stop_space[3] = ". ";
unsigned char dat_str_advicea[9] = "*advicea";
unsigned char dat_str_advice1[9] = "*advice1";
unsigned char dat_str_advice2[9] = "*advice2";
unsigned char dat_str_advice3[9] = "*advice3";
unsigned char dat_str_advice4[9] = "*advice4";
unsigned char dat_str_advice5[9] = "*advice5";
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
unsigned char dat_str_hq_pan_2[7] = "hq.pan";
unsigned char shd_str_please_insert_disk[20] = "Please insert Disk ";
unsigned char shd_str_if_3_5_insert[23] = "\n(if 3.5\" insert Disk ";
unsigned char shd_str_close_paren[2] = ")";
unsigned char shd_str_press_return_continue[41] =
    ".\n \n     Press Return\n     to continue.\n";
drv_addr shd_disk_names[4] = {
    (drv_addr) dat_str_final_exe, (drv_addr) dat_str_game_exe,
    (drv_addr) dat_str_tac_exe, (drv_addr) dat_str_hq_pan_2,
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
INT shm_frame_toggle = 0x0001;
unsigned char shd_str_pani[5] = "PANI";
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
struct RASTPORT dat_screen_port = { 0, 0, 0, 319, 199, 1, 15, 4, 0 };
struct RASTPORT *shd_screen = (struct RASTPORT *) &dat_screen_port;
rt_addr shd_archive_buffer_end = (rt_addr) &shm_menu_face_x;
INT shd_archive_fd = -1;
UNSIGNED_INT shm_anim_magic = 0x0003;
unsigned char asm_building_pan[16];
UNSIGNED_INT asm_watched;
UNSIGNED_INT asm_watch_odds;
UNSIGNED_INT asm_picture_width;
UNSIGNED_INT asm_picture_height;
unsigned char shm_clue_digits[16];
unsigned char asm_tap_digits[16];
unsigned char shm_message_key[9];
INT asm_jailbreak_target_suspect;
UNSIGNED_INT asm_jailbreak_source_suspect;
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
struct SEQ_BLOCK shm_active_pan;
INT shm_menu_line_start[32];
UNSIGNED_INT shm_menu_colour_plain;
UNSIGNED_INT shm_menu_colour_item;
INT shm_menu_lines;
UNSIGNED_INT shm_menu_colour_pick;
UNSIGNED_INT shm_source_fd;
UNSIGNED_INT shm_source_dst;
UNSIGNED_INT shm_source_src;
INT shm_sprite_width;
INT shm_sprite_height;
INT shm_palette_count;
struct JOYSTICK shm_joystick;
unsigned char shm_scratch[512];
INT shm_difficulty;
UNSIGNED_INT asm_day;
UNSIGNED_INT shm_clock_minutes;
struct CAMPAIGN shm_campaign;
UNSIGNED_INT shm_seed;
INT shm_options;
INT shm_cga;
struct CITY shm_cities[16];
UNSIGNED_INT shm_menu_tick;
INT shm_suspect_count;
struct LOG_ENTRY shm_log[128];
INT shm_menu_face;
INT shm_wire_clue_source;
struct CRIME_EVENT shm_crime_events[64];
INT shm_log_count;
INT shm_menu_first_line;
INT shm_building_count;
INT shm_case_tick;
INT shm_frame_ticks;
UNSIGNED_INT asm_loaded_width;
rt_addr shm_source_at;
UNSIGNED_INT asm_loaded_height;
INT shm_case_city_1;
UNSIGNED_INT shm_case_city_2;
UNSIGNED_INT shm_anim_more;
UNSIGNED_INT shm_pan_playing;
unsigned char shm_anim_palette[774];
UNSIGNED_INT asm_stamp_minute;
UNSIGNED_INT shm_menu_no_pick;
INT asm_last_screen;
struct CAMPAIGN shm_probed_campaign;
INT shm_menu_items;
UNSIGNED_INT shm_anim_segment;
INT asm_hour;
UNSIGNED_INT shm_seq_ticks;
UNSIGNED_INT asm_contact_met;
INT shm_crime_event_count;
UNSIGNED_INT shm_case_seed;
UNSIGNED_INT shm_clue_method;
UNSIGNED_INT shm_menu_relayout;
INT shm_mission;
UNSIGNED_INT shm_menu_colour_bar;
INT shm_case_org_1;
INT shm_menu_text_width;
UNSIGNED_INT shm_case_org_2;
INT asm_menu_choice_count;
UNSIGNED_INT shm_faces_sprites[116];
INT shm_global_alert_level;
UNSIGNED_INT shm_slots_filled;
union REGS shm_regs;
UNSIGNED_INT shm_anim_error;
UNSIGNED_INT shm_double_agent_cities;
INT shm_crime_role_count;
UNSIGNED_INT shm_menu_marked;
struct CRIME_ROLE shm_crime_roles[32];
UNSIGNED_INT shm_seq_done;
rt_addr shm_refill;
unsigned char shm_archive_buffer[512];
UNSIGNED_INT shm_menu_face_x;
UNSIGNED_INT shm_menu_draw_only;
UNSIGNED_INT shm_skills;
UNSIGNED_INT shm_menu_face_y;
struct ORG_STATE shm_orgs[16];
UNSIGNED_INT shm_anim_sprites[250];
UNSIGNED_INT asm_case_ready;
rt_addr shm_anim_name;
INT shm_finished;
unsigned char shm_menu_shortcut[32];
UNSIGNED_INT shm_menu_pick;
struct CRIME_ENTRY shm_crime_block[4];
UNSIGNED_INT shm_menu_right;
unsigned char shm_substitute_tail[256];
struct ROLE_SCAN_STATE shm_role_scan_states[32];
unsigned char shm_graphics_letter;
UNSIGNED_INT shm_menu_bottom;
UNSIGNED_INT shm_seq_stop_asked;
UNSIGNED_INT asm_campaign_state;
INT shm_case_city;
struct ACTIVITY shm_activity;
UNSIGNED_INT shm_orgs_known;
UNSIGNED_INT asm_auto_waiting;
INT shm_slot_pick;
UNSIGNED_INT shm_case_spare_2;
unsigned char shm_anim_row_2[320];
UNSIGNED_INT asm_menu_choices[32];
UNSIGNED_INT shm_anim_block_kind;
INT shm_seq_vars[51];
UNSIGNED_INT shm_case_org;
#endif
