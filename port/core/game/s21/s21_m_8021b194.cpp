#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_m_8021b194.c"
// desc: Appears to dispatch on a flag of the target's owner and a lookup predicate, calling one of two handlers.
struct S21Owner { char pad[32]; unsigned flags; };
struct S21Target { char pad[24]; Ptr32<struct S21Owner> owner; };
struct S21Holder { char pad[36]; Ptr32<struct S21Target> target; };
extern Ptr32<void> fn_8021ec2c(Ptr32<void>);
extern Ptr32<void> fn_80240994(Ptr32<void>);
extern int fn_8021ed14(Ptr32<void>);
extern void fn_8021b1f8(Ptr32<struct S21Holder>);
extern void fn_8021b388(Ptr32<struct S21Holder>);
void w3d_s21_dispatch_8021b194(Ptr32<struct S21Holder> self)
{
    if (self->target->owner->flags & 1) {
        if (fn_8021ed14(fn_80240994(fn_8021ec2c(self->target))))
            fn_8021b1f8(self);
        else
            fn_8021b388(self);
    }
}

}
