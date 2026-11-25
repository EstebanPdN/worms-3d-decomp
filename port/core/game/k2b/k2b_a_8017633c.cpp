#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8017633c.c"
struct K2bColor { unsigned char r, g, b, a; };
struct K2bItem { unsigned char pad0[4]; unsigned char kind; unsigned char pad5[3]; int param; struct K2bColor color; };
struct K2bHandler { Ptr32<Ptr32<void>> vtable; };
int w3d_k2b_apply_color_items_8017633c(Ptr32<struct K2bHandler> self, Ptr32<struct K2bItem> items, unsigned int count)
{
    int result = 0;
    unsigned int i = 0;
    Ptr32<struct K2bItem> p;
    if (i < count) {
        p = items;
        do {
            struct K2bColor color;
            int status;
            color.r = p->color.r;
            color.g = p->color.g;
            color.b = p->color.b;
            color.a = p->color.a;
            status = ((Ptr32<int (Ptr32<struct K2bHandler>, Ptr32<struct K2bItem>, Ptr32<struct K2bColor>, int, int)>)self->vtable[16])(self, p, &color, p->kind, p->param);
            if (status < 0)
                result = status;
            i++;
            p++;
        } while (i < count);
    }
    return result;
}
// desc: Appears to apply each item of an array with a copy of its color through a virtual handler and return the last negative status.

}
