#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_release_members_80093780.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
extern void w3d_handle_member_destroy_801265a4(Ptr32<void>, int);

void s19_release_members_80093780(Ptr32<void> self)
{
    Ptr32<void> zero = 0;
    if (FIELD(self, void *, 32)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 32)->vtable[4])(FIELD(self, S19Iface *, 32));
    }
    FIELD(self, void *, 32) = zero;
    if (FIELD(self, void *, 36)) {
        w3d_handle_member_destroy_801265a4(FIELD(self, void *, 36), 3);
        FIELD(self, void *, 36) = zero;
    }
}

}
