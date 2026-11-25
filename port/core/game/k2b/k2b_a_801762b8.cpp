#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_801762b8.c"
struct K2bItem { unsigned char pad0[4]; unsigned char kind; unsigned char pad5[3]; int param; };
struct K2bHandler { Ptr32<Ptr32<void>> vtable; };
int w3d_k2b_apply_plain_items_801762b8(Ptr32<struct K2bHandler> self, Ptr32<struct K2bItem> items, unsigned int count)
{
    int result = 0;
    unsigned int i = 0;
    Ptr32<struct K2bItem> p;
    if (i < count) {
        p = items;
        do {
            int status = ((Ptr32<int (Ptr32<struct K2bHandler>, Ptr32<struct K2bItem>, Ptr32<void>, int, int)>)self->vtable[15])(self, p, 0, p->kind, p->param);
            if (status < 0)
                result = status;
            i++;
            p++;
        } while (i < count);
    }
    return result;
}
// desc: Appears to apply each item of an array with no extra object through a virtual handler and return the last negative status.

}
