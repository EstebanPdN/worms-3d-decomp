#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_hp_80262124.c"
// desc: Appears to build a property key for the game-over game type string and pass it to the property reader.
struct S21Key { Ptr32<const char> name; };
extern const char lbl_803cae50[];
extern int fn_800fc550(Ptr32<struct S21Key>, int);
int w3d_s21_read_game_type_80262124(Ptr32<void> self, int fallback)
{
    struct S21Key key;
    key.name = lbl_803cae50;
    return fn_800fc550(&key, fallback);
}

}
