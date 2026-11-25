#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ck_80237744.c"
// desc: Appears to construct an object on a base constructor, install a vtable, retain the same shared global interface and run a second setup helper.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { Ptr32<void> vtable; char pad[16]; Ptr32<struct S21Ref> held; };
extern Ptr32<struct S21Ref> lbl_804b05ac;
extern char lbl_8041a748[];
extern Ptr32<void> fn_801ea0ec(Ptr32<struct S21Object>, int);
extern void fn_8025d5a4(Ptr32<struct S21Object>);
Ptr32<struct S21Object> w3d_s21_construct_80237744(Ptr32<struct S21Object> self, Ptr32<void> arg_r4)
{
    Ptr32<struct S21Ref> shared;
    fn_801ea0ec(self, w3d::H(arg_r4));
    shared = lbl_804b05ac;
    self->vtable = lbl_8041a748;
    self->held = shared;
    if (shared)
        shared->methods->retain(shared);
    fn_8025d5a4(self);
    return self;
}

}
