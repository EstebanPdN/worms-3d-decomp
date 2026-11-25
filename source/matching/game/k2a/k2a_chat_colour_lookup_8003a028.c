extern char w3d_str_803740a0[];
extern char w3d_str_803740b4[];
extern char w3d_str_803740cc[];
extern char w3d_str_803740e4[];
extern unsigned int FUN_800fc370(const char **key, void *out);

unsigned int k2a_chat_colour_lookup_8003a028(void *self, int channel, void *out)
{
    const char *global_key;
    const char *anon_key;
    const char *alliance_key;
    const char *player_key;
    switch (channel) {
    case 0:
        global_key = w3d_str_803740a0;
        return FUN_800fc370(&global_key, out);
    case 3:
        anon_key = w3d_str_803740b4;
        return FUN_800fc370(&anon_key, out);
    case 2:
        alliance_key = w3d_str_803740cc;
        return FUN_800fc370(&alliance_key, out);
    case 1:
        player_key = w3d_str_803740e4;
        return FUN_800fc370(&player_key, out);
    }
    return 0x80004005;
}
