// 0x80163754: reparte un mensaje a los hijos de un objeto de la tabla global de asas. La lista se copia antes de llamar porque
// los receptores pueden añadir o quitar hijos, y por eso cada asa se vuelve a resolver antes de usarla.
#include "native_common.h"

namespace {
struct ObjectEntry {   // 36 B
    char pad[6];
    uint16_t first_child;   // +6
    char pad2[2];
    uint16_t next_sibling;  // +0xa
    char pad3[8];
    w3d_u32 handle;         // +0x14
    char pad4[0xc];
};
struct ObjectTable { Ptr32<ObjectEntry> entries; };
struct Engine { char pad[0x1c]; Ptr32<ObjectTable> objects; };
const int kInvalidHandle = (int)0x80004005;   // El HRESULT de "no implementado".
}
extern "C" {
extern Ptr32<Engine> A804b178c;
w3d_u32 A80212fd4(w3d_u32);
void A802134fc(void *);
void A802eee50(void *, const void *, w3d_u32);
w3d_u32 A8034b974(void *table, void *handle);

int A80163754(Ptr32<void> message, w3d_u32 handle) {
    ObjectTable *table = A804b178c->objects;
    ObjectEntry *entry = nullptr;
    if (handle != 0xffffffffu) {
        ObjectEntry *candidate = table->entries + (handle & 0xfff);
        if (candidate->handle == handle) entry = candidate;
    }
    if (!entry) return kInvalidHandle;

    w3d_u32 *list = nullptr, *list_end = nullptr, *list_capacity = nullptr;
    for (uint16_t child = entry->first_child; child != 0; child = table->entries[child].next_sibling) {
        if (list_end == list_capacity) {
            // Crecimiento del original: la capacidad se mide en bytes y se multiplica por 4.
            const w3d_u32 used = (char *)list_end - (char *)list;
            const int grown = used + (used >> 1), next = used + 1;
            const w3d_u32 bytes = (w3d_u32)(next < grown ? grown : next) << 2;
            w3d_u32 *storage = at<w3d_u32>(A80212fd4(bytes));
            if (list) {
                A802eee50(storage, list, used < bytes ? used : bytes);
                A802134fc(list);
            }
            list = storage;
            list_end = (w3d_u32 *)((char *)storage + used);
            list_capacity = (w3d_u32 *)((char *)storage + bytes);
        }
        *list_end++ = table->entries[child].handle;
    }
    int result = 0;
    for (w3d_u32 *it = list; it != list_end; it++) {
        const w3d_u32 object = A8034b974(table, arg(*it));
        // core/open llega aquí con r5-r10 a cero. En el original son restos de lo anterior; se pasan a cero para que sea determinista.
        if (object) result = call_virtual<int>(g2h(object), 0x24, message.get(), (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0);
        if (result < 0) break;
    }
    if (list) A802134fc(list);
    return result;
}
}
