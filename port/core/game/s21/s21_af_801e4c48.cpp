#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_af_801e4c48.c"
// desc: Appears to be a deleting destructor that installs the vtable pointer, runs member cleanup and deletes the object when the low flag bit is set.
struct S21Object { char pad[28]; Ptr32<void> vtable; };
extern char lbl_80416f38[];
extern int fn_801e4de8(Ptr32<struct S21Object>);
extern void fn_801fe1f8(Ptr32<struct S21Object>);
void w3d_s21_destroy_801e4c48(Ptr32<struct S21Object> self, int flags)
{
    self->vtable = lbl_80416f38;
    fn_801e4de8(self);
    if (flags & 1)
        fn_801fe1f8(self);
}

}
