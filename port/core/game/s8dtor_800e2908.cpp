#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8dtor_800e2908.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80410018[];
void fn_8015ff2c(Ptr32<void>, int);

void s8_destroy_800e2908(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80410018;
    if (FIELD(self, void *, 48)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 48)->vtable[4])(FIELD(self, W3dInterface *, 48));
    }
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
    }
    if (FIELD(self, void *, 32)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 32)->vtable[4])(FIELD(self, W3dInterface *, 32));
    }
    fn_8015ff2c(self, flags);
}

}
