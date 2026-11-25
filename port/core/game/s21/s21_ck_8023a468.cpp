#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ck_8023a468.c"
// desc: Appears to construct an object on a base constructor, install a vtable, clear a field and retain a third shared global interface.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { Ptr32<void> vtable; char pad[16]; char pad2[20]; int cleared; Ptr32<struct S21Ref> held; };
extern Ptr32<struct S21Ref> lbl_804b05a8;
extern char lbl_8041aea0[];
extern int fn_80239d60(Ptr32<struct S21Object>, Ptr32<void>);
Ptr32<struct S21Object> w3d_s21_construct_8023a468(Ptr32<struct S21Object> self, Ptr32<void> arg_r4)
{
    Ptr32<struct S21Ref> shared;
    fn_80239d60(self, arg_r4);
    shared = lbl_804b05a8;
    self->vtable = lbl_8041aea0;
    self->cleared = 0;
    self->held = shared;
    if (shared)
        shared->methods->retain(shared);
    return self;
}

}
