#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_80176664.c"
struct K2bInterface { Ptr32<Ptr32<void>> vtable; };
struct K2bTable { unsigned char pad0[24]; Ptr32<Ptr32<struct K2bInterface>> entries; };
extern int w3d_table_find_80177eb0(Ptr32<struct K2bTable> self, Ptr32<void> key, Ptr32<unsigned short> slot);
int w3d_k2b_table_acquire_80176664(Ptr32<struct K2bTable> self, int key, Ptr32<Ptr32<struct K2bInterface>> out)
{
    unsigned short slot;
    int status = w3d_table_find_80177eb0(self, w3d::G(key), &slot);
    if (status < 0) {
        if (*out)
            ((Ptr32<void (Ptr32<struct K2bInterface>)>)(*out)->vtable[4])(*out);
        *out = 0;
        return status;
    } else {
        unsigned int index = slot;
        Ptr32<Ptr32<struct K2bInterface>> entries = self->entries;
        if (entries[index])
            ((Ptr32<void (Ptr32<struct K2bInterface>)>)entries[index]->vtable[3])(entries[index]);
        if (*out)
            ((Ptr32<void (Ptr32<struct K2bInterface>)>)(*out)->vtable[4])(*out);
        *out = entries[index];
        return 0;
    }
}
// desc: Appears to look up a table slot, retain its interface and replace the caller's held interface, or clear it on failure.

}
