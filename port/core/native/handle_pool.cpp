// Conjunto de asas: cada entrada recuerda su tipo, y las libres se guardan por índice.
#include "native_game.h"

namespace {
struct HandleEntry {
    w3d_u32 pad;
    w3d_u32 object;   // +4
    uint16_t kind;    // +8
    uint16_t pad2;
    w3d_u32 generation;  // +0xc
    w3d_u32 flags;    // +0x10
    w3d_u32 pad3;
};
static_assert(sizeof(HandleEntry) == 24, "las asas ocupan 24 B");
struct HandlePool {
    char pad[0x18];
    Ptr32<Ptr32<void>> kinds;  // +0x18
    char pad2[0x830 - 0x1c];
    Ptr32<HandleEntry> entries;  // +0x830
    char pad3[4];
    WordVector free_list;  // +0x838
};
}
extern "C" {
int w3d_env_int(const char *, int *);
void diag_stack_trace(const char *);
// 0x80176814: libera una entrada: avisa al tipo (método 0x3c) y devuelve lo que devuelva.
w3d_u32 A80176814(Ptr32<HandlePool> self, Ptr32<HandleEntry> entry) {
#if defined(__3DS__)
    { static int trap = -1; if (trap == -1) { trap = 0; w3d_env_int("W3D_TRAP_ENTRY", &trap); } if (trap && (int)entry->kind == trap) diag_stack_trace("liberando entrada"); }
#endif
    const w3d_u32 index = (w3d_u32)(entry.get() - self->entries.get());
    // El método lee la entrada en el segundo registro (r4 sigue vivo en el original).
    void *kind = self->kinds[entry->kind].get();
    const w3d_u32 result = ((w3d_u32 (*)(w3d_u32, w3d_u32))g2h(*(w3d_u32 *)((char *)g2h(*(w3d_u32 *)kind) + 0x3c)))(h2g(kind), entry.v);
    entry->flags = 0;
    entry->kind = 0xffff;
    entry->object = 0;
    entry->generation = 0;
    self->free_list.push_back(index);
    return result;
}
}
