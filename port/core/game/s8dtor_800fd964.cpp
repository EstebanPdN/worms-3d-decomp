#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8dtor_800fd964.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80410520[];
extern int lbl_804aaf64;
void fn_801628ec(Ptr32<void>, int);

void s8_destroy_800fd964(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> firstInterface = FIELD(self, W3dInterface *, 36);
    FIELD(self, void *, 0) = w3d_vtable_80410520;
    lbl_804aaf64 = 0;
    if (firstInterface) {
        ((W3dInterfaceFn)firstInterface->vtable[4])(firstInterface);
    }
    if (FIELD(self, void *, 32)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 32)->vtable[4])(FIELD(self, W3dInterface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    fn_801628ec(self, flags);
}

}
