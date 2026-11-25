#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_m.c"
extern unsigned char lbl_8041e780[];
extern void w3d_auto_80118268(Ptr32<void>, Ptr32<void>);
extern int FUN_80118aac(Ptr32<void>, float, Ptr32<float>, int);
extern int FUN_8001b830(Ptr32<void>, float);

int s19_probe_value_8001b8f0(Ptr32<void> p, float t) {
    struct { float v; int extra[2]; } k;
    w3d_auto_80118268(lbl_8041e780, p);
    if (FUN_80118aac(lbl_8041e780, t, &k.v, 0) == 0)
        return 0;
    return FUN_8001b830(p, k.v);
}

}
