#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_damage_scale_8000af90.c"
extern Ptr32<void> w3d_auto_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);

float s19_damage_scale_8000af90(float v) {
    struct { Ptr32<const char> name; int value; int extra[2]; } k;
    k.name = "DoubleDamage";
    w3d_auto_800fc1f0(&k.name, &k.value);
    if (v == 0.0f)
        v = 1.0f;
    if (k.value == 1)
        v += v;
    return v;
}

}
