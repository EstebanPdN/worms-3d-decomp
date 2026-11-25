#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_bs_802182cc.c"
// desc: Appears to install a vtable pointer, clear a global singleton pointer and forward to the base destructor helper.
struct S21Object { Ptr32<void> vtable; };
extern char lbl_804197d8[];
extern int lbl_804abaa4;
extern int fn_8021837c(Ptr32<struct S21Object>, Ptr32<void>);
int w3d_s21_destroy_802182cc(Ptr32<struct S21Object> self, Ptr32<void> arg_r4)
{
    self->vtable = lbl_804197d8;
    lbl_804abaa4 = 0;
    return fn_8021837c(self, arg_r4);
}

}
