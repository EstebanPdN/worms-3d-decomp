#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k5b_a_801758e8.c"
struct K5bIface { Ptr32<Ptr32<void>> vtable; };
struct K5bSlotTable {
    char head[20];
    int active;
    Ptr32<Ptr32<struct K5bIface>> slots;
    char body[2064];
    unsigned int used;
    char mid[20];
    unsigned int capacity;
};
int w3d_k5b_slot_table_release_all_801758e8(Ptr32<struct K5bSlotTable> self)
{
    unsigned int i;
    for (i = 0; i < self->capacity; i++) {
        Ptr32<Ptr32<struct K5bIface>> slots = self->slots;
        if (slots[i] != 0)
            ((Ptr32<void (Ptr32<struct K5bIface>)>)slots[i]->vtable[4])(slots[i]);
        slots[i] = 0;
    }
    self->active = 0;
    self->used = self->capacity;
    return 0;
}
// desc: w3d_k5b_slot_table_release_all_801758e8: Appears to release every interface in the slot array at +24 through virtual slot 4, clear the slots, reset +20 and copy the capacity at +2116 to +2092.

}
