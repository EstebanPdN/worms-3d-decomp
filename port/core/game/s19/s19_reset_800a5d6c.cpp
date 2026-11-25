#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_reset_800a5d6c.c"
struct S19V3 { int x, y, z; };
extern void FUN_800a5e04(Ptr32<void>);
struct S19Obj { char pad0[36]; struct S19V3 v; };
static inline void s19_clear(Ptr32<struct S19V3> q) {
    q->z = 0;
    q->y = 0;
    q->x = 0;
}
Ptr32<void> s19_reset_range_800a5d6c(Ptr32<struct S19Obj> self)
{
    s19_clear(&self->v);
    FUN_800a5e04(self);
    return self;
}

}
