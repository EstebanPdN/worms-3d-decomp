#include "w3d_ptr.h"
#line 1 "cc39c_seek_slot_level_800a7ee4_v1.cpp"
// cc39c: 0x800a7ee4 (248 bytes), seek the highest requested slot level.
// Observed in the original DOL: eight words at +132..+160 are scanned from the
// top (+160) down; the first word that is not -1 is the target. Unsigned
// compares step a 52-byte element array (first word of the object at +172)
// from the index at +164 up to the target and from the index at +168 down to
// it, calling 0x800a7488 (void; no final r3 write) with each element. Both
// indices then become the target and bit 0x200000 is set in the word at +96.
// With no requested slot the indices become 0 and 14 and the bit is cleared.
// Names and views are inferred; unknown bytes are not recovered layout.
struct cc39c_Element52 { unsigned char unknown00[52]; };   // stride witnessed by mulli/addi 52
struct cc39c_ElementArray { Ptr32<cc39c_Element52> items; };      // only the first word is read
struct cc39c_LevelOwner {
    unsigned char unknown00[96];
    unsigned int flags;                  // +96
    unsigned char unknown64[32];
    unsigned int slots[8];               // +132
    unsigned int current;                // +164
    unsigned int last;                   // +168
    Ptr32<cc39c_ElementArray> elements;        // +172
};
extern "C" void cc39c_apply_element_800a7488(Ptr32<cc39c_LevelOwner>, Ptr32<cc39c_Element52>);
extern "C" void cc39c_seek_slot_level_800a7ee4(Ptr32<cc39c_LevelOwner> self) {
    Ptr32<unsigned int> slot = &self->slots[7];
    for (int i = 7; i >= 0; i--) {
        unsigned int target = *slot--;
        if (target != 0xffffffff) {
            if (target > self->current)
                for (unsigned int j = self->current; j < target; j++)
                    cc39c_apply_element_800a7488(self, &self->elements->items[j]);
            if (target < self->last)
                for (unsigned int j = self->last; j > target; j--)
                    cc39c_apply_element_800a7488(self, &self->elements->items[j]);
            self->last = target;
            self->current = target;
            self->flags |= 0x200000;
            return;
        }
    }
    self->current = 0;
    self->last = 14;
    self->flags &= ~0x200000;
}


