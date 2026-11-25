#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_dtor_80036e68.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
extern unsigned char lbl_8040e5e8[];
extern void w3d_auto_8025e0c4(Ptr32<void>, int);
extern void w3d_s4_scroll_handle_destroy(Ptr32<void>, int);
extern void w3d_service_destroy_801628ec(Ptr32<void>, int);

void s19_screen_destroy_80036e68(Ptr32<void> self, int flags)
{
    unsigned i;
    FIELD(self, void *, 0) = lbl_8040e5e8;
    for (i = 0; i <= 9; i++) {
        if (FIELD(self, void *, 36 + i * 4))
            w3d_auto_8025e0c4(FIELD(self, void *, 36 + i * 4), 3);
    }
    if (FIELD(self, void *, 76))
        w3d_s4_scroll_handle_destroy(FIELD(self, void *, 76), 3);
    if (FIELD(self, void *, 32)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 32)->vtable[4])(FIELD(self, S19Iface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((S19IfaceFn)FIELD(self, S19Iface *, 28)->vtable[4])(FIELD(self, S19Iface *, 28));
    }
    w3d_service_destroy_801628ec(self, flags);
}

}
