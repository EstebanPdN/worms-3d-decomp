#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ec_801dcb80.c"
// desc: Appears to hand out a held interface: it fails with 0x80004005 when none is held, otherwise retains it, releases the previous value of the output and stores it, returning zero.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { char pad[172]; Ptr32<struct S21Ref> held; };
int w3d_s21_get_held_801dcb80(Ptr32<struct S21Object> self, Ptr32<Ptr32<struct S21Ref>> out)
{
    if (self->held == 0)
        return 0x80004005;
    self->held->methods->retain(self->held);
    if (*out)
        (*out)->methods->release(*out);
    *out = self->held;
    return 0;
}

}
