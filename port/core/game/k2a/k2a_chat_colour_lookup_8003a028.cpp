#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_chat_colour_lookup_8003a028.c"
extern char w3d_str_803740a0[];
extern char w3d_str_803740b4[];
extern char w3d_str_803740cc[];
extern char w3d_str_803740e4[];
extern unsigned int FUN_800fc370(Ptr32<Ptr32<const char>> key, Ptr32<void> out);

unsigned int k2a_chat_colour_lookup_8003a028(Ptr32<void> self, int channel, Ptr32<void> out)
{
    Ptr32<const char> global_key;
    Ptr32<const char> anon_key;
    Ptr32<const char> alliance_key;
    Ptr32<const char> player_key;
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

}
