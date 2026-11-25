#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_800157cc.c"
extern Ptr32<void> w3d_auto_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);

int s19_weapons_dont_end_turn_800157cc(void) {
    Ptr32<const char> name = "AI.WeaponsDontEndTurn";
    int value;
    w3d_auto_800fc1f0(&name, &value);
    return value == 1;
}

}
