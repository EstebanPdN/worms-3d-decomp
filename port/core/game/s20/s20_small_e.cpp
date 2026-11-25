#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_e.c"
/* Counted object construction and destruction. */
extern Ptr32<void> fn_8017990c(Ptr32<void>);
extern int fn_801799d4(Ptr32<void>, Ptr32<void>);
extern char lbl_80412180[];
extern int lbl_804ab5a0;

Ptr32<void> w3d_s20_construct_counted_80174b38(Ptr32<void> self) {
    int count;
    fn_8017990c(self);
    count = lbl_804ab5a0;
    *(Ptr32<Ptr32<char>>)self = lbl_80412180;
    lbl_804ab5a0 = count + 1;
    return self;
}

int w3d_s20_destruct_counted_80174b80(Ptr32<void> self, Ptr32<void> arg_r4) {
    int count = lbl_804ab5a0;
    *(Ptr32<Ptr32<char>>)self = lbl_80412180;
    lbl_804ab5a0 = count - 1;
    return fn_801799d4(self, arg_r4);
}

}
