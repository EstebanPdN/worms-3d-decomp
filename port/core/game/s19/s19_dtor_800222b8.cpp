#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_dtor_800222b8.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
extern unsigned char lbl_8040ddb8[];
extern void w3d_handle_storage_release(Ptr32<void>);
extern void w3d_actor_base_destroy(Ptr32<void>, int);

void s19_destroy_800222b8(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = lbl_8040ddb8;
    if (FIELD(self, void *, 48)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 48)->vtable[4])(FIELD(self, S19Iface *, 48));
    }
    if (FIELD(self, void *, 44)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 44)->vtable[4])(FIELD(self, S19Iface *, 44));
    }
    if (FIELD(self, void *, 40)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 40)->vtable[4])(FIELD(self, S19Iface *, 40));
    }
    if (FIELD(self, void *, 28))
        w3d_handle_storage_release(FIELD(self, void *, 28));
    w3d_actor_base_destroy(self, flags);
}

}
