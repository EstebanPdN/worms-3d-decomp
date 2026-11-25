#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_n_801e7174.c"
// desc: Appears to construct an object with a base constructor, two vtable pointers and two zeroed three-word members.
struct S21Triple { int a; int b; int c; };
struct S21Object { Ptr32<void> vtable; char pad[8]; Ptr32<void> vtable2; char pad1[32]; int flag; struct S21Triple first; struct S21Triple second; };
extern Ptr32<void> fn_8020fbd0(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>);
extern char lbl_80417048[];
extern char lbl_80417070[];
static inline void s21_clear(Ptr32<struct S21Triple> t)
{
    t->c = 0;
    t->b = 0;
    t->a = 0;
}
Ptr32<struct S21Object> w3d_s21_construct_801e7174(Ptr32<struct S21Object> self, Ptr32<void> arg_r4, Ptr32<void> arg_r5, Ptr32<void> arg_r6, Ptr32<void> arg_r7, Ptr32<void> arg_r8)
{
    fn_8020fbd0(self, arg_r4, arg_r5, arg_r6, arg_r7, arg_r8);
    self->vtable2 = lbl_80417048;
    self->vtable = lbl_80417070;
    self->flag = 0;
    s21_clear(&self->first);
    s21_clear(&self->second);
    return self;
}

}
