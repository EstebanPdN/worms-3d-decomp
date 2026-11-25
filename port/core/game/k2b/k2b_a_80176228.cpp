#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_80176228.c"
struct K2bItem { unsigned char pad0[4]; unsigned char kind; unsigned char pad5[3]; int param; int extra; };
struct K2bHandler { Ptr32<Ptr32<void>> vtable; };
extern Ptr32<void> w3d_s20_forward_held_8019013c(Ptr32<struct K2bItem> item);
int w3d_k2b_apply_held_items_80176228(Ptr32<struct K2bHandler> self, Ptr32<struct K2bItem> items, unsigned int count)
{
    int result = 0;
    unsigned int i = 0;
    Ptr32<struct K2bItem> p;
    if (i < count) {
        p = items;
        do {
            Ptr32<Ptr32<void>> vtable = self->vtable;
            int status = ((Ptr32<int (Ptr32<struct K2bHandler>, Ptr32<struct K2bItem>, Ptr32<void>, int, int)>)vtable[14])(self, p, w3d_s20_forward_held_8019013c(p), p->kind, p->param);
            if (status < 0)
                result = status;
            i++;
            p++;
        } while (i < count);
    }
    return result;
}
// desc: Appears to apply each item of an array with its forwarded held object through a virtual handler and return the last negative status.

}
