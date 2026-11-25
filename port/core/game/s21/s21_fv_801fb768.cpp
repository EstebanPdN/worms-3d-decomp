#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_fv_801fb768.c"
// desc: Appears to synchronize a four-entry table with a source table: it records a source object when its virtual slot 13 reports one and the slot is empty, and clears the slot otherwise, returning zero.
struct S21Item;
struct S21ItemMethods { Ptr32<void (void)> reserved[13]; Ptr32<int (Ptr32<struct S21Item>)> active; };
struct S21Item { Ptr32<struct S21ItemMethods> methods; };
struct S21Object { char pad[36]; Ptr32<Ptr32<struct S21Item>> sources; char pad1[12]; Ptr32<Ptr32<struct S21Item>> slots; };
int w3d_s21_sync_slots_801fb768(Ptr32<struct S21Object> self)
{
    Ptr32<Ptr32<struct S21Item>> source = self->sources;
    unsigned i = 0;
    Ptr32<Ptr32<struct S21Item>> slot = self->slots;
    Ptr32<struct S21Item> none = 0;
    do {
        if ((*source)->methods->active(*source) == 1) {
            if (*slot == 0)
                *slot = *source;
        } else if (*slot != 0)
            *slot = none;
        i++;
        source++;
        slot++;
    } while (i <= 3);
    return 0;
}

}
