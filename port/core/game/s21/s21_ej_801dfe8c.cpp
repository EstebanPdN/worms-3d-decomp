#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_ej_801dfe8c.c"
// desc: Appears to shut down an object: it flushes and destroys each of the 32 objects in its slot array through the vtable pointer at offset 28, releases the held interface and returns zero.
struct S21Slot;
struct S21SlotMethods { Ptr32<void (void)> reserved[2]; Ptr32<void (Ptr32<struct S21Slot>, int)> destroy; Ptr32<void (Ptr32<struct S21Slot>)> flush; Ptr32<void (void)> reserved1[6]; Ptr32<void (Ptr32<struct S21Slot>)> stop; };
struct S21Slot { char pad[28]; Ptr32<struct S21SlotMethods> methods; };
struct S21Ref;
struct S21RefMethods { Ptr32<void (void)> reserved[4]; Ptr32<void (Ptr32<struct S21Ref>)> release; };
struct S21Ref { Ptr32<struct S21RefMethods> methods; };
struct S21Object { char pad[20]; Ptr32<struct S21Ref> held; char pad1[24]; Ptr32<struct S21Slot> slots[32]; };
int w3d_s21_shutdown_801dfe8c(Ptr32<struct S21Object> self)
{
    unsigned i = 0;
    Ptr32<struct S21Slot> none = 0;
    Ptr32<Ptr32<struct S21Slot>> slot = self->slots;
    do {
        if (*slot) {
            (*slot)->methods->flush(*slot);
            (*slot)->methods->stop(*slot);
            if (*slot)
                (*slot)->methods->destroy(*slot, 3);
            *slot = none;
        }
        i++;
        slot++;
    } while (i <= 31);
    if (self->held)
        self->held->methods->release(self->held);
    self->held = 0;
    return 0;
}

}
