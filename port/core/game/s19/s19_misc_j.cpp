#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_j.c"
extern int FUN_80009b04(Ptr32<void>, Ptr32<void>, Ptr32<void>, float);
extern int FUN_80009f08(Ptr32<void>, Ptr32<void>, Ptr32<void>, float);

int s19_try_two_checks_80009a94(Ptr32<void> p, int a, int b, float f) {
    if (FUN_80009b04(p, w3d::G(a), w3d::G(b), f))
        return 1;
    if (FUN_80009f08(p, w3d::G(a), w3d::G(b), f))
        return 1;
    return 0;
}

struct S19G { char pad0[60]; float f60; };
struct S19P { char pad0[36]; int f36; };
extern Ptr32<struct S19G> lbl_804aa6d8;
extern float FUN_8001b660(Ptr32<int>);
extern void FUN_8000affc(Ptr32<struct S19P>, float, int);

void s19_apply_scaled_length_8000d004(Ptr32<struct S19P> p) {
    float s = lbl_804aa6d8->f60;
    int n = (int)FUN_8001b660(&p->f36);
    FUN_8000affc(p, s, n);
}

}
