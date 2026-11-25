#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_en_801e4de8.c"
// desc: Appears to stop a playing voice: when active it closes the voice handle, resets the handle fields to minus one and clears the link, returning one, or zero when nothing was active.
struct S21Owner { char pad[56]; int voice; };
struct S21Voice { int pad0; int link_state; int remaining; Ptr32<struct S21Owner> owner; int handle; };
extern int fn_801e4fcc(Ptr32<struct S21Voice>);
extern Ptr32<void> fn_803228f8(int);
int w3d_s21_stop_801e4de8(Ptr32<struct S21Voice> self)
{
    int none;
    if (fn_801e4fcc(self) == 0 && self->remaining == 0)
        return 0;
    none = -1;
    if (self->handle == -1)
        return 0;
    fn_803228f8(self->handle);
    self->handle = none;
    if (self->owner)
        self->owner->voice = none;
    self->link_state = 0;
    return 1;
}

}
