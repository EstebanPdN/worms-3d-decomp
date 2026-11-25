#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801b1e48.c"
struct K4bIface { Ptr32<Ptr32<void>> vtable; };
struct K4bLookup { Ptr32<Ptr32<void>> vtable; };
struct K4bScanner {
    char pad0[52];
    unsigned int count;
    char pad38[4];
    Ptr32<Ptr32<struct K4bIface>> items;
    char pad40[12];
    Ptr32<struct K4bLookup> lookup;
};
typedef Ptr32<void (Ptr32<struct K4bLookup>)> K4bLookupBegin;
typedef Ptr32<int (Ptr32<struct K4bLookup>, Ptr32<struct K4bIface>)> K4bLookupFind;
int w3d_k4b_scanner_has_missing_801b1e48(Ptr32<struct K4bScanner> self)
{
    Ptr32<Ptr32<struct K4bIface>> it = self->items;
    Ptr32<Ptr32<struct K4bIface>> end = it + self->count;
    ((K4bLookupBegin)self->lookup->vtable[12])(self->lookup);
    for (; it != end; it++) {
        if (((K4bLookupFind)self->lookup->vtable[6])(self->lookup, *it) == 0)
            return 1;
    }
    return 0;
}
// desc: w3d_k4b_scanner_has_missing_801b1e48: Appears to prepare a lookup object, then return one if any item of the list is not found by its sixth-slot query, otherwise zero.

}
