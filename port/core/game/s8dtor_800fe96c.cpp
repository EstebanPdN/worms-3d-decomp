#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8dtor_800fe96c.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_804105b8[];
void fn_8015ff2c(Ptr32<void>, int);

void s8_destroy_800fe96c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804105b8;
    if (FIELD(self, void *, 92)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 92)->vtable[4])(FIELD(self, W3dInterface *, 92));
    }
    if (FIELD(self, void *, 88)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 88)->vtable[4])(FIELD(self, W3dInterface *, 88));
    }
    if (FIELD(self, void *, 84)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 84)->vtable[4])(FIELD(self, W3dInterface *, 84));
    }
    if (FIELD(self, void *, 80)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 80)->vtable[4])(FIELD(self, W3dInterface *, 80));
    }
    if (FIELD(self, void *, 76)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 76)->vtable[4])(FIELD(self, W3dInterface *, 76));
    }
    if (FIELD(self, void *, 72)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 72)->vtable[4])(FIELD(self, W3dInterface *, 72));
    }
    if (FIELD(self, void *, 68)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 68)->vtable[4])(FIELD(self, W3dInterface *, 68));
    }
    if (FIELD(self, void *, 52)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 52)->vtable[4])(FIELD(self, W3dInterface *, 52));
    }
    if (FIELD(self, void *, 36)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 36)->vtable[4])(FIELD(self, W3dInterface *, 36));
    }
    if (FIELD(self, void *, 32)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 32)->vtable[4])(FIELD(self, W3dInterface *, 32));
    }
    if (FIELD(self, void *, 28)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 28)->vtable[4])(FIELD(self, W3dInterface *, 28));
    }
    fn_8015ff2c(self, flags);
}

}
