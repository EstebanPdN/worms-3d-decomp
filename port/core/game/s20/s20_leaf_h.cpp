#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_leaf_h.c"
/* Handle table lookup, bounds-checked vector read and service forwarding. */
typedef struct S20Slot { char pad0[12]; Ptr32<void> object; char pad1[4]; int id; char pad3[12]; } S20Slot;
typedef struct S20SlotVector { Ptr32<S20Slot> slots; } S20SlotVector;
typedef struct S20HandleTable { char pad[28]; Ptr32<S20SlotVector> vector; } S20HandleTable;
extern Ptr32<S20HandleTable> lbl_804b178c;

Ptr32<void> w3d_s20_lookup_handle_object_80164fc8(int handle) {
    Ptr32<S20HandleTable> table = lbl_804b178c;
    Ptr32<S20SlotVector> vector = table->vector;
    Ptr32<S20Slot> found;
    if (handle == -1) {
        found = 0;
    } else {
        Ptr32<S20Slot> slot = vector->slots + (handle & 4095);
        found = slot->id == handle ? w3d::R(slot) : 0;
    }
    if (found == 0)
        return 0;
    return found->object;
}

int w3d_s20_get_vector_item_800ffca4(Ptr32<char> self, unsigned int index, Ptr32<int> out) {
    Ptr32<int> begin = *(Ptr32<Ptr32<int>>)(self + 4);
    unsigned int count = (*(Ptr32<int>)(self + 8) - (int)w3d::H(begin)) >> 2;
    if (index < count) {
        { unsigned int offset = index << 2; *out = *(Ptr32<int>)((Ptr32<char>)begin + offset); }
        return 0;
    }
    return 0x80004005;
}

typedef struct S20Registry { int words[4]; } S20Registry;
extern Ptr32<S20Registry> lbl_804b1754;

Ptr32<S20Registry> w3d_s20_init_registry_8016130c(Ptr32<S20Registry> self) {
    self->words[0] = 0;
    self->words[1] = 0;
    self->words[2] = 0;
    self->words[3] = 0;
    lbl_804b1754 = self;
    return self;
}

}
