#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b27_worm_state_8013ea30.c"
/* Worm state transition: when the worm is not current and its state is one of
   two consecutive values, stores a computed value, registers a local record
   and writes a code into the object returned for the worm's handle. Struct
   offsets are observed; field names and meanings are inferred. */
typedef struct { int a; int b; } Tmp;
typedef struct { char p0[112]; int handle; char p1[380]; int state; char p2[180]; int value; } Worm;
extern int fn_80139158(Ptr32<Worm>);
extern int fn_801190d0(Ptr32<void>);
extern Ptr32<char> fn_800fc710(int, Ptr32<Tmp>);
extern void fn_80178474(Ptr32<Tmp>, int);
void tsonnet_b27_worm_state_8013ea30(Ptr32<Worm> w, int arg) {
    if (!fn_80139158(w) && (unsigned)(w->state - 21) <= 1) {
        Tmp t;
        int code = 34;
        w->value = fn_801190d0(w3d::G(arg));
        t.a = 0;
        t.b = 0xe3a8;
        *(Ptr32<int>)(fn_800fc710(w->handle, &t) + 128) = code;
        fn_80178474(&t, 2);
    }
}

}
