#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fs_801f90e8.c"
// desc: Appears to advance a cursor field a given number of steps, starting it from the owner when empty and stepping from the current value otherwise, returning zero.
struct S21Object { char pad[20]; int owner; char pad1[4]; int cursor; };
extern int fn_801f8de0(Ptr32<void>);
extern int fn_801f8df8(Ptr32<void>, int);
int w3d_s21_advance_801f90e8(Ptr32<struct S21Object> self, unsigned steps)
{
    unsigned i = 0;
    for (; i < steps; i++) {
        if (self->cursor == 0)
            self->cursor = fn_801f8de0(w3d::G(self->owner));
        else
            self->cursor = fn_801f8df8(w3d::G(self->owner), self->cursor);
    }
    return 0;
}

}
