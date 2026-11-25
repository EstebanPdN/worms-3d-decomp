#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_channels_800ae220.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
extern void FUN_800ae7d4(Ptr32<void>, int, int);
void s19_start_channels_800ae220(Ptr32<void> self)
{
    FUN_800ae7d4(self, 0, 0);
    FUN_800ae7d4(self, 1, 0);
    FUN_800ae7d4(self, 2, 0);
    ((S19IfaceFn)FIELD(self, S19Iface *, 84)->vtable[6])(FIELD(self, S19Iface *, 84));
    ((S19IfaceFn)FIELD(self, S19Iface *, 88)->vtable[6])(FIELD(self, S19Iface *, 88));
}

}
