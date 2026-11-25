#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ev_801e83fc.c"
// desc: Appears to drop a reference of a counted object: when the count at offset 4 reaches zero it unlinks and destroys the object and deletes it, returning the new count.
struct S21Object { Ptr32<void> vtable; unsigned short references; };
extern char lbl_80417010[];
extern void fn_801e82ec(Ptr32<struct S21Object>);
extern void fn_801e828c(Ptr32<unsigned short>, int);
extern void fn_801fe1f8(Ptr32<struct S21Object>);
unsigned short w3d_s21_release_801e83fc(Ptr32<struct S21Object> self)
{
    Ptr32<unsigned short> references = &self->references;
    unsigned short remaining = --self->references;
    if (remaining == 0) {
        fn_801e82ec(self);
        if (self) {
            self->vtable = lbl_80417010;
            fn_801e828c(references, 0);
            fn_801fe1f8(self);
        }
    }
    return remaining;
}

}
