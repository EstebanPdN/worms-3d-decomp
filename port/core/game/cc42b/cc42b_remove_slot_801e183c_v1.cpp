#include "w3d_ptr.h"
#line 1 "cc42b_remove_slot_801e183c_v1.cpp"
// Partial observed refcount interface. Results of acquire/release are ignored;
// their full original interface declarations remain unknown.
struct cc42b_Held;
struct cc42b_HeldVtable {
    unsigned int unknown00[3];
    Ptr32<void (Ptr32<cc42b_Held>)> acquire;
    Ptr32<void (Ptr32<cc42b_Held>)> release;
};
struct cc42b_Held { Ptr32<cc42b_HeldVtable> vtable; };
struct cc42b_Slot {
    Ptr32<cc42b_Held> value;
    void clear() { if (value) value->vtable->release(value); value=0; }
    cc42b_Slot &operator=(const cc42b_Slot &other) {
        if (other.value) other.value->vtable->acquire(other.value);
        if (value) value->vtable->release(value);
        value=other.value;
        return *this;
    }
};
struct cc42b_SlotOwner { cc42b_Slot slots[32]; unsigned int active, extent; };
// Original reloads extent and slots across callbacks; no bounds check is added.
extern "C" void cc42b_remove_slot_801e183c(Ptr32<cc42b_SlotOwner> self, unsigned int index) {
    if ((index+self->slots)->value) {
        unsigned int cursor=index;
        while (cursor < self->extent-1U) {
            self->slots[cursor].clear();
            self->slots[cursor]=self->slots[cursor+1];
            ++cursor;
        }
        self->slots[self->extent-1U].clear();
        --self->active;
    }
}


