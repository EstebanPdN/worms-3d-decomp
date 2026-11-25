#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ck_80225ef0.c"
// desc: Appears to construct an object on a base constructor, install a vtable, store a count of twenty and retain a shared global interface.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { Ptr32<void> vtable; char pad[16]; int count; Ptr32<struct S21Ref> held; };
extern Ptr32<struct S21Ref> lbl_804b05b0;
extern char lbl_8041a2a8[];
extern Ptr32<void> fn_801ea0ec(Ptr32<struct S21Object>, int);
Ptr32<struct S21Object> w3d_s21_construct_80225ef0(Ptr32<struct S21Object> self, Ptr32<void> arg_r4)
{
    Ptr32<struct S21Ref> shared;
    fn_801ea0ec(self, w3d::H(arg_r4));
    shared = lbl_804b05b0;
    self->vtable = lbl_8041a2a8;
    self->count = 20;
    self->held = shared;
    if (shared)
        shared->methods->retain(shared);
    return self;
}

}
