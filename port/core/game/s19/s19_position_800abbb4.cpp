#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_position_800abbb4.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
typedef Ptr32<void (Ptr32<S19Iface>, int)> S19IfaceFn2;
struct S19V3 { float x, y, z; };
void s19_set_position_800abbb4(Ptr32<void> self, Ptr32<struct S19V3> v)
{
    if (FIELD(self, void *, 120)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 120)->vtable[10])(FIELD(self, S19Iface *, 120));
    }
    FIELD(self, struct S19V3, 132) = *v;
}

}
