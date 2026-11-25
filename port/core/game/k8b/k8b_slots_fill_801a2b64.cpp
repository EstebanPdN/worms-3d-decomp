#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k8b_slots_fill_801a2b64.c"
struct K8bSlot { char pad0[20]; unsigned short index; };
struct K8bSlotVector { Ptr32<Ptr32<struct K8bSlot>> begin; Ptr32<Ptr32<struct K8bSlot>> end; };
struct K8bSlotOwner { char pad0[36]; struct K8bSlotVector slots; };
struct K8bSlotTable { char pad0[20]; Ptr32<Ptr32<struct K8bSlot>> defaults; };
extern Ptr32<struct K8bSlotTable> lbl_804ab74c;
static inline unsigned k8b_slot_count(Ptr32<struct K8bSlotVector> v) { return v->end - v->begin; }

int w3d_k8b_slots_fill_801a2b64(Ptr32<struct K8bSlotOwner> self, Ptr32<Ptr32<struct K8bSlot>> items, unsigned count)
{
    unsigned i;
    unsigned j;
    int off;
    Ptr32<struct K8bSlotTable> table;
    for (i = 0; i < k8b_slot_count(&self->slots); i++) {
        table = lbl_804ab74c;
        off = i * 4;
        *(Ptr32<Ptr32<struct K8bSlot>>)((Ptr32<char>)self->slots.begin + off) = *(Ptr32<Ptr32<struct K8bSlot>>)((Ptr32<char>)table->defaults + off);
    }
    for (j = 0; j < count; j++) {
        Ptr32<struct K8bSlot> item = *items++;
        *(Ptr32<Ptr32<struct K8bSlot>>)((Ptr32<char>)self->slots.begin + (item->index << 2)) = item;
    }
    return 0;
}

}
