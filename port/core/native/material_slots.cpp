// Lista de elementos de un material, uno por clase. Añadir uno de una clase que ya está lo sustituye.
#include "native_game.h"

namespace {
struct SlotItem { char pad[6]; uint16_t kind; };
struct SlotList {
    char pad[0x74];
    Ptr32<void> compiled;        // +0x74
    char pad2[0x88 - 0x78];
    int count;                   // +0x88
    w3d_u32 capacity;            // +0x8c
    Ptr32<Ptr32<SlotItem>> items;  // +0x90
};
}
extern "C" {
int A801a2350(w3d_u32 kind);
void A801f29d0(void *list, int count);
void A801a2b64(void *compiled, w3d_u32 state, w3d_u32 size);

// 0x8034bc68
w3d_u32 A8034bc68(Ptr32<SlotList> self, Ptr32<SlotItem> item) {
    const int wanted = A801a2350(item->kind);
    Ptr32<SlotItem> *slot = self->items, *end = slot + self->count;
    for (; slot != end; slot++) {
        if (A801a2350((*slot)->kind) == wanted) break;
    }
    if (slot == end) {
        A801f29d0(&self->count, self->count + 1);
        slot = &self->items[self->count];
        self->count++;
    }
    assign_reference(*slot, item.get());
    w3d_u32 size;
    const w3d_u32 state = call_virtual(self.get(), 0x58, &size);
    A801a2b64(self->compiled.get(), state, size);
    return 0;
}
}
