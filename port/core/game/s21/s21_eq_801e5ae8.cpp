#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_eq_801e5ae8.c"
// desc: Appears to be a deleting destructor: it installs a vtable pointer, runs cleanup, frees the aligned block at offset 60, clears two pointer slots, releases the held interface and deletes the object when the low flag bit is set.
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { char pad[44]; Ptr32<struct S21Ref> held; char pad1[12]; int slots[2]; char pad2[100]; Ptr32<void> vtable; };
extern char lbl_80416f78[];
extern void fn_801e5dfc(Ptr32<struct S21Object>);
extern void fn_801fe2e0(Ptr32<void>);
extern void fn_801fe1f8(Ptr32<struct S21Object>);
void w3d_s21_destroy_801e5ae8(Ptr32<struct S21Object> self, int flags)
{
    Ptr32<int> slot;
    Ptr32<int> cursor;
    self->vtable = lbl_80416f78;
    fn_801e5dfc(self);
    slot = self->slots;
    if (slot)
        fn_801fe2e0(slot);
    cursor = slot;
    do {
        *cursor = 0;
        cursor++;
    } while (cursor <= self->slots + 1);
    if (self->held)
        self->held->methods->release(self->held);
    if (flags & 1)
        fn_801fe1f8(self);
}

}
