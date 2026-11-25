#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "tsonnet_b29_release_8013f6b4.c"
/* Releases the object's registered handle: when a handle id is set, applies two
   values to the attached interface (virtual slot 24), flags the object the
   handle resolves to and clears the id. Offsets are observed; field names and
   meanings are inferred. The cleared id is an inline parameter because the
   original keeps it in a saved register across the calls; the do-while
   wrapper was found with the permuter and is what keeps it there. */
typedef struct { Ptr32<Ptr32<void>> vtable; } Iface;
typedef struct { char p0[32]; int a; int b; char p1[116]; int handle; char p2[4]; Ptr32<Iface> attached; } Holder;
extern Ptr32<void> fn_80164fc8(int);
extern void fn_80122af8(Ptr32<void>);
static inline void release(Ptr32<Holder> h, int none) {
    if (h->handle != -1) {
        if (h->attached) {
            ((Ptr32<void (Ptr32<Iface>, int)>)h->attached->vtable[24])(h->attached, h->a);
            ((Ptr32<void (Ptr32<Iface>, int)>)h->attached->vtable[24])(h->attached, h->b);
        }
        {
            Ptr32<void> o = fn_80164fc8(h->handle);
            if (o) fn_80122af8(o);
        }
        h->handle = none;
    }
}
void tsonnet_b29_release_8013f6b4(Ptr32<Holder> h) {
    do { release(h, -1); } while (0);
}

}
