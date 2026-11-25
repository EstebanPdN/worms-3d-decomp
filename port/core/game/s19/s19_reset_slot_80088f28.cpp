#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_reset_slot_80088f28.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
extern void FUN_8008dc28(Ptr32<void>);
int s19_reset_slot_80088f28(Ptr32<void> self)
{
    Ptr32<void> zero;
    if (FIELD(self, void *, 356)) {
        zero = 0;
        ((S19IfaceFn)FIELD(self, S19Iface *, 356)->vtable[4])(FIELD(self, S19Iface *, 356));
        FIELD(self, void *, 356) = zero;
    }
    FUN_8008dc28(self);
    return 20;
}

}
