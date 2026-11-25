#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ac_80203d70.c"
// desc: Appears to replace the held interface object, retaining the new one and releasing the old one, unless the object is locked, in which case it returns 0x80004005.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[3]; Ptr32<void (Ptr32<struct S21Ref>)> retain; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Holder { char pad[20]; Ptr32<struct S21Ref> held; int locked; };
int w3d_s21_set_held_80203d70(Ptr32<struct S21Holder> self, Ptr32<struct S21Ref> fresh)
{
    if (self->locked)
        return 0x80004005;
    if (fresh)
        fresh->methods->retain(fresh);
    if (self->held)
        self->held->methods->release(self->held);
    self->held = fresh;
    return 0;
}

}
