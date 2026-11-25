#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_prop_8001e2dc.c"
extern void w3d_auto_800fc270(Ptr32<Ptr32<const char>>, Ptr32<float>);

float s19_hop_test_height_8001e2dc(void) {
    Ptr32<const char> name = "Worm.HopTest.Height";
    float v;
    w3d_auto_800fc270(&name, &v);
    v = v * 0.5f;
    return v;
}

}
