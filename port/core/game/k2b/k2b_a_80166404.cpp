#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_80166404.c"
struct K2bService { Ptr32<Ptr32<void>> vtable; };
struct K2bHolder { unsigned char pad0[20]; Ptr32<struct K2bService> service; };
struct K2bTable { unsigned char pad0[16]; int entries[1]; };
int w3d_k2b_service_lookup_entry_80166404(Ptr32<struct K2bHolder> self, Ptr32<char> key, int index)
{
    Ptr32<struct K2bService> service = self->service;
    Ptr32<struct K2bTable> table = ((Ptr32<Ptr32<struct K2bTable> (Ptr32<struct K2bService>, Ptr32<char>)>)service->vtable[13])(service, key ? w3d::R(key + 4) : 0);
    if (table != 0) {
        return table->entries[index];
    }
    return 0;
}
// desc: Appears to ask a held service for a table keyed by the object's secondary base and return one of its entries.

}
