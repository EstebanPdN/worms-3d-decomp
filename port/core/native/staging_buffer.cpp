// Búfer de escritura diferida: guarda los datos en una zona libre de su espacio de 9 MB y apunta la petición.
#include "native_common.h"

namespace {
struct Extent { w3d_u32 start; w3d_u32 size; };
struct StagingBuffer {
    w3d_u32 base;
    w3d_u32 pad;
    w3d_u32 limit;          // +8
    w3d_u32 pad2;
    Extent free_list[256];  // +0x10
    w3d_u32 free_count;     // +0x810
};
const w3d_u32 kNotFound = 0xffffffffu;
}
extern "C" {
void A8020f3f0(void *buffer, w3d_u32 bytes);
void A8020f3b8(void *request, void *source, w3d_u32 start, w3d_u32 bytes);
void A8020f940(void *buffer, void *request);
void A8020f8ac(void *buffer, Extent *entry);

// 0x8020f4b0: el primer tamaño exacto o, si no lo hay, el menor que quepa. El límite se comprueba con la última zona mirada, que no es
// necesariamente la elegida: así lo hace el original.
w3d_u32 A8020f4b0(Ptr32<StagingBuffer> buffer, Ptr32<void> source, w3d_u32 bytes, Ptr32<void> request) {
    if (!buffer->base) A8020f3f0(buffer.get(), 0x900000);
    const w3d_u32 needed = (bytes + 31) & ~31u;
    w3d_u32 chosen = kNotFound, smallest = kNotFound;
    const Extent *last = nullptr;
    for (w3d_u32 i = 0; i < buffer->free_count; i++) {
        last = &buffer->free_list[i];
        if (last->size < needed) continue;
        if (last->size == needed) { chosen = i; break; }
        if (last->size < smallest) { smallest = last->size; chosen = i; }
    }
    if (chosen == kNotFound || last->start + last->size > buffer->limit) return 0;
    Extent *entry = &buffer->free_list[chosen];
    A8020f3b8(request.get(), source.get(), entry->start, needed);
    A8020f940(buffer.get(), request.get());
    if (entry->size == needed) {
        A8020f8ac(buffer.get(), entry);
    } else {
        entry->start += needed;
        entry->size -= needed;
    }
    return 1;
}
}
