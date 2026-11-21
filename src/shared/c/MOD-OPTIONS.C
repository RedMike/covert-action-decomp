/* MOD-OPTIONS.C -- the mod options, set from mods.txt, and their loader.
 */

/* The options, which the loader starts at their defaults for mods.txt to
 * change. */
struct MOD_OPTIONS mod_options;

/* What each is called in mods.txt, in the struct's order. */
char *mod_option_names[] = {
    "fast_tac_move",
    "additional_guidance",
    "flexible_orientation",
    "unimplemented_rooms",
    "player_disguise_sprite",
    "photos_without_camera",
};

/* Read mods.txt beside the game, one `name = n` line per option, 0 for off. An
 * option with no line keeps its default.
 */
void c_mod_options_load(void)
{
    char text[256];
    char *at;
    char *name;
    char *value;
    INT fd;
    INT got;
    INT i;

    for (i = 0; i < MOD_OPTION_COUNT; i++)
        MOD_OPTION_BYTES[i] = 1;
    mod_options.photos_without_camera = 2;
    fd = open((str_addr) "mods.txt", 0x8000);
    if (fd == -1)
        return;
    got = read(fd, (str_addr) text, sizeof text - 1);
    close(fd);
    if (got <= 0)
        return;
    text[got] = 0;
    at = text;
    while (*at != 0) {
        for (i = 0; i < MOD_OPTION_COUNT; i++) {
            name = mod_option_names[i];
            value = at;
            while (*name != 0 && *value == *name) {
                value++;
                name++;
            }
            if (*name != 0)
                continue;
            while (*value == ' ')
                value++;
            if (*value != '=')
                continue;
            do
                value++;
            while (*value == ' ');
            MOD_OPTION_BYTES[i] = 0;
            while (*value >= '0' && *value <= '9')
                MOD_OPTION_BYTES[i] = MOD_OPTION_BYTES[i] * 10 + *value++ - '0';
        }
        while (*at != 0 && *at++ != '\n')
            ;
    }
}
