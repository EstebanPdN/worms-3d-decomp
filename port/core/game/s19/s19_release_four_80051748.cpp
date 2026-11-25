#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_release_four_80051748.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
void s19_release_four_80051748(Ptr32<void> self)
{
    int i;
    Ptr32<void> zero = 0;
    for (i = 4; i != 0; i--) {
        if (FIELD(self, void *, 60 - i * 4))
            ((S19IfaceFn)FIELD(self, S19Iface *, 60 - i * 4)->vtable[4])(FIELD(self, S19Iface *, 60 - i * 4));
        FIELD(self, void *, 60 - i * 4) = zero;
    }
}

}
