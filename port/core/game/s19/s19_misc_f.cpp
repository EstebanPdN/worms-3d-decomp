#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_misc_f.c"
extern void w3d_auto_800158b8(Ptr32<float> p, float v);

void s19_randomize_three_80015910(Ptr32<float> p, float v) {
    w3d_auto_800158b8(p, v);
    w3d_auto_800158b8(p + 1, v);
    w3d_auto_800158b8(p + 2, v);
}

struct S19Poll;
struct S19PollVT { char pad0[8]; Ptr32<int (Ptr32<struct S19Poll>)> ready; };
struct S19Poll { char pad0[12]; Ptr32<struct S19PollVT> vt; };
extern void FUN_80015f80(Ptr32<struct S19Poll>);
extern void FUN_80016494(Ptr32<struct S19Poll>);

void s19_poll_then_80015f38(Ptr32<struct S19Poll> p) {
    if (p->vt->ready(p))
        FUN_80015f80(p);
}

void s19_poll_then_8001644c(Ptr32<struct S19Poll> p) {
    if (p->vt->ready(p))
        FUN_80016494(p);
}

}
