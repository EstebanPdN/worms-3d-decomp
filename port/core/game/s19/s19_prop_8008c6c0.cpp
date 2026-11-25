#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_8008c6c0.c"
extern void w3d_auto_800fc270(Ptr32<Ptr32<const char>>, Ptr32<float>);
extern int FUN_800fc4c8(Ptr32<Ptr32<const char>>, float);

void s19_low_gravity_8008c6c0(void) {
    Ptr32<const char> gameDefault = "Low.Gravity.GameDefault";
    float value = 1.0f;
    Ptr32<const char> multiplier;
    w3d_auto_800fc270(&gameDefault, &value);
    multiplier = "Low.Gravity.Multiplier";
    FUN_800fc4c8(&multiplier, value);
}

}
