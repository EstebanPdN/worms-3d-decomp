#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_dtor_8003de80.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
extern unsigned char lbl_8040e8b8[];
extern void w3d_actor_handle_member_destroy(Ptr32<void>, int);
extern void w3d_actor_base_destroy(Ptr32<void>, int);

void s19_actor_destroy_8003de80(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = lbl_8040e8b8;
    if (FIELD(self, void *, 108)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 108)->vtable[4])(FIELD(self, S19Iface *, 108));
    }
    if (FIELD(self, void *, 104)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 104)->vtable[4])(FIELD(self, S19Iface *, 104));
    }
    if (FIELD(self, void *, 100)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 100)->vtable[4])(FIELD(self, S19Iface *, 100));
    }
    if (FIELD(self, void *, 96)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 96)->vtable[4])(FIELD(self, S19Iface *, 96));
    }
    w3d_actor_handle_member_destroy((Ptr32<char>)self + 68, 2);
    w3d_actor_base_destroy(self, flags);
}

}
