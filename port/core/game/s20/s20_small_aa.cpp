#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_aa.c"
/* Guarded global forwards, float forwarding and a virtual toggle. */
extern int fn_800fdcf4(Ptr32<void>, int, int, int, int, int, int);
extern Ptr32<void> lbl_804aaf64;

int w3d_s20_forward_global6_800fdc80(int a, int b, int c, int d, int e, int f) {
    if (lbl_804aaf64 == 0)
        return 0x80004005;
    return fn_800fdcf4(lbl_804aaf64, a, b, c, d, e, f);
}

}
