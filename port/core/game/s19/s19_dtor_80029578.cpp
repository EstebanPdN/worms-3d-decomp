#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_dtor_80029578.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
extern unsigned char lbl_8040e288[];
extern int lbl_804aa860;
extern void w3d_service_destroy_801628ec(Ptr32<void>, int);

void s19_service_destroy_80029578(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = lbl_8040e288;
    if (FIELD(self, void *, 28)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 28)->vtable[6])(FIELD(self, S19Iface *, 28));
    }
    if (FIELD(self, void *, 32)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 32)->vtable[6])(FIELD(self, S19Iface *, 32));
    }
    {
        Ptr32<S19Iface> h = FIELD(self, S19Iface *, 52);
        lbl_804aa860 = 0;
        if (h) {
            ((S19IfaceFn)h->vtable[4])(h);
        }
    }
    if (FIELD(self, void *, 48)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 48)->vtable[4])(FIELD(self, S19Iface *, 48));
    }
    if (FIELD(self, void *, 44)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 44)->vtable[4])(FIELD(self, S19Iface *, 44));
    }
    if (FIELD(self, void *, 32)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 32)->vtable[4])(FIELD(self, S19Iface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 28)->vtable[4])(FIELD(self, S19Iface *, 28));
    }
    w3d_service_destroy_801628ec(self, flags);
}

}
