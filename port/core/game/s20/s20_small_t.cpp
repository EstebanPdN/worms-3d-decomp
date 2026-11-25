#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_t.c"
/* Counted destructor, guarded forwards and an indexed lookup through a virtual call. */
typedef struct S20Object { Ptr32<Ptr32<void>> vtable; } S20Object;
extern int fn_801858fc(Ptr32<char>, int);
extern char lbl_80412068[];
extern int lbl_804ab580;

int w3d_s20_destruct_counted_80172b64(Ptr32<char> self, int flags) {
    int count = lbl_804ab580;
    Ptr32<S20Object> held = *(Ptr32<Ptr32<S20Object>>)(self + 128);
    *(Ptr32<Ptr32<char>>)self = lbl_80412068;
    lbl_804ab580 = count - 1;
    if (held != 0)
        ((Ptr32<void (Ptr32<S20Object>)>)held->vtable[4])(held);
    return fn_801858fc(self, flags);
}

}
