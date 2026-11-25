#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_gd_8020810c.c"
// desc: Appears to release the held interface at offset 20 and clear it, returning zero, or 0x80004005 when nothing is held.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { char pad[20]; Ptr32<struct S21Ref> held; };
int w3d_s21_release_held_8020810c(Ptr32<struct S21Object> self)
{
    if (self->held != 0) {
        self->held->methods->release(self->held);
        self->held = 0;
        return 0;
    }
    return 0x80004005;
}

}
