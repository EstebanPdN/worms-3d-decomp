// Lista de estados del material (0x801a936c): si hay cambios pendientes, ordena cada tramo {inicio, fin, -, clase} con el algoritmo
// de su clase y la recompila. Si no, devuelve la que ya tiene.
#include "native_common.h"

namespace {
struct StateEntry { w3d_u32 begin, end, pad, kind; };
struct MaterialStates {
    char pad[0xa0];
    int mode;                 // +0xa0
    char pad2[0xb0 - 0xa4];
    w3d_u32 compiled_list;    // +0xb0
    char pad3[0x11c - 0xb4];
    int pending;              // +0x11c
    Ptr32<StateEntry> entries;      // +0x120
    Ptr32<StateEntry> entries_end;  // +0x124
};
}
extern "C" {
void A80353ff0(void *, void *);
void A80354734(void *, void *);
void A80354e78(void *, void *);
w3d_u32 A801a9478(void *);

w3d_u32 A801a936c(Ptr32<MaterialStates> self) {
    if (self->pending == 0) return self->compiled_list;
    const int count = (int)(self->entries_end.v - self->entries.v) >> 4;
    w3d_u32 last = 0;
    for (w3d_u32 i = 0; i < (w3d_u32)count; i++) {
        const StateEntry &entry = self->entries[i];
        // Los tres algoritmos de ordenación tienen la misma firma: el comparador de la clase es un parámetro vacío en el original.
        if (entry.kind == 0) A80353ff0(g2h(entry.begin), g2h(entry.end));
        else if (entry.kind == 1) A80354734(g2h(entry.begin), g2h(entry.end));
        else if (entry.kind == 2) A80354e78(g2h(entry.begin), g2h(entry.end));
    }
    if (self->mode == 0) return A801a9478(self.get());
    return last;
}
}
