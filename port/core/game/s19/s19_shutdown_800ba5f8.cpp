#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s19_shutdown_800ba5f8.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct S19Iface { Ptr32<Ptr32<void>> vtable; } S19Iface;
typedef Ptr32<void (Ptr32<S19Iface>)> S19IfaceFn;
extern int FUN_800b9a48(Ptr32<void>);
extern int FUN_800b9b0c(Ptr32<void>);
extern void FUN_8009081c(Ptr32<void>, int);
extern Ptr32<S19Iface> lbl_804ae548;
extern Ptr32<void> lbl_804b183c;
extern int lbl_804aad30;

void s19_shutdown_800ba5f8(Ptr32<void> self)
{
    Ptr32<void> zero = 0;
    FUN_800b9a48(self);
    FUN_800b9b0c(self);
    if (lbl_804ae548) {
        ((S19IfaceFn)lbl_804ae548->vtable[4])(lbl_804ae548);
    }
    lbl_804ae548 = zero;
    if (lbl_804b183c)
        FUN_8009081c(lbl_804b183c, 3);
    lbl_804b183c = zero;
    lbl_804aad30 = (int)w3d::H(zero);
}

}
