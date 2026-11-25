#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_cm_8023ac08.c"
// desc: Appears to construct an object on a base constructor, install a vtable, zero ten words, retain a shared global interface and set an integer property of 30000.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { Ptr32<void> vtable; char pad[16]; int w[9]; int tail; Ptr32<struct S21Ref> held; };
extern Ptr32<struct S21Ref> lbl_804b05ac;
extern char lbl_8041ae28[];
extern Ptr32<void> fn_801ea0ec(Ptr32<struct S21Object>, int);
extern void fn_802408a0(Ptr32<struct S21Object>, int);
Ptr32<struct S21Object> w3d_s21_construct_8023ac08(Ptr32<struct S21Object> self, Ptr32<void> arg_r4)
{
    Ptr32<struct S21Ref> shared;
    fn_801ea0ec(self, w3d::H(arg_r4));
    shared = lbl_804b05ac;
    self->vtable = lbl_8041ae28;
    self->w[0] = 0;
    self->w[1] = 0;
    self->w[2] = 0;
    self->w[3] = 0;
    self->w[4] = 0;
    self->w[5] = 0;
    self->w[6] = 0;
    self->w[7] = 0;
    self->w[8] = 0;
    self->tail = 0;
    self->held = shared;
    if (shared)
        shared->methods->retain(shared);
    fn_802408a0(self, 30000);
    return self;
}

}
