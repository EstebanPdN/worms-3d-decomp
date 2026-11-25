#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_l.c"
struct S19G { char pad0[188]; float tolerance; };
struct S19T { char pad0[16]; int mode; int v20[3]; int v32[2]; int flag; };
extern Ptr32<struct S19G> lbl_804aa6d8;
extern unsigned char lbl_8041d3a0[];
extern int FUN_80009674(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, float);
extern int FUN_80009a94(Ptr32<void>, Ptr32<void>, Ptr32<void>, float);

int s19_probe_8001744c(Ptr32<struct S19T> p) {
    Ptr32<void> a = p->v32;
    Ptr32<void> b = lbl_8041d3a0;
    Ptr32<void> c = p->v20;
    int r = FUN_80009674(a, b, c, p->mode, lbl_804aa6d8->tolerance);
    if (p->flag && r == 0)
        r = FUN_80009a94(a, b, c, lbl_804aa6d8->tolerance);
    return r;
}

extern Ptr32<void> lbl_804b1758;
extern int FUN_8001e328(Ptr32<void>, Ptr32<void>, Ptr32<short>, Ptr32<short>, Ptr32<int>);
extern float FUN_8001a02c(short, short, int, int, float, float);

void s19_forward_8001a02c_80019fb4(int a, int b, float x, float y) {
    struct { short s1; short s2; int s3; int extra[4]; } k;
    FUN_8001e328(lbl_804b1758, w3d::G(a), &k.s1, &k.s2, &k.s3);
    FUN_8001a02c(k.s1, k.s2, k.s3, b, x, y);
}

}
