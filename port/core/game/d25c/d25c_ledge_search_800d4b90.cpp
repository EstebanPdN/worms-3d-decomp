#include "w3d_ptr.h"
#line 1 "d25c_ledge_search_800d4b90.cpp"
// d25c: 0x800d4b90. Search for a clear motion: read the two axis endpoints (0x800d4e3c), try the current heading
// offset by +/- i * pi/4 for i = 0..3, then the descriptor's base height. Names are inferred. -mps-float
// explains the 40 bytes between the second vector and the conversion slot (five saved FPRs).
struct Desc { char u0[64]; float base; };
struct Self { char u0[136]; Ptr32<void> h136; char u140[36]; float f176; float f180; };
struct Vec3 { float x, y, z; Vec3() {} };
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" void prepare_800d4e3c(Ptr32<Self>, Ptr32<Vec3>, Ptr32<Vec3>);
extern "C" int test_800d4cec(Ptr32<Self>, float, float, Ptr32<Vec3>, Ptr32<Vec3>);
extern float quarter_pi_80388d38[];
extern "C" int d25c_ledge_search_800d4b90(Ptr32<Self> self, Ptr32<float> ox, Ptr32<float> oy) {
    Vec3 a, b;
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h136));
    float angle = quarter_pi_80388d38[0];
    prepare_800d4e3c(self, &a, &b);
    float y = self->f180;
    for (unsigned i = 0; i <= 3; i++) {
        float step = (float)i * angle;
        float x = self->f176 + step;
        if (test_800d4cec(self, x, y, &a, &b)) { *ox = x; *oy = y; return 1; }
        x = self->f176 - step;
        if (test_800d4cec(self, x, y, &a, &b)) { *ox = x; *oy = y; return 1; }
    }
    float y2 = d->base;
    float x2 = self->f176;
    if (test_800d4cec(self, x2, y2, &a, &b)) { *ox = x2; *oy = y2; return 1; }
    return 0;
}


