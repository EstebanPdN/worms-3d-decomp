#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s11dtor_802afc40.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_8041c610[];
void fn_8020c5c4(Ptr32<void>);
void fn_80341588(Ptr32<void>);
void fn_801fe1f8(Ptr32<void>);

void w3d_dtor_802afc40(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 180) = w3d_vtable_8041c610;
    if (FIELD(self, void *, 176)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 176)->vtable[4])(FIELD(self, W3dInterface *, 176));
    }
    if (FIELD(self, void *, 132)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 132)->vtable[4])(FIELD(self, W3dInterface *, 132));
    }
    if (FIELD(self, void *, 88)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 88)->vtable[4])(FIELD(self, W3dInterface *, 88));
    }
    if (FIELD(self, void *, 84)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 84)->vtable[4])(FIELD(self, W3dInterface *, 84));
    }
    fn_8020c5c4((Ptr32<char>)self + 80);
    fn_80341588((Ptr32<char>)self + 80);
    if (FIELD(self, void *, 76)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 76)->vtable[4])(FIELD(self, W3dInterface *, 76));
    }
    if (FIELD(self, void *, 72)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 72)->vtable[4])(FIELD(self, W3dInterface *, 72));
    }
    if (FIELD(self, void *, 68)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 68)->vtable[4])(FIELD(self, W3dInterface *, 68));
    }
    if (FIELD(self, void *, 64)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 64)->vtable[4])(FIELD(self, W3dInterface *, 64));
    }
    if (FIELD(self, void *, 60)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 60)->vtable[4])(FIELD(self, W3dInterface *, 60));
    }
    if (FIELD(self, void *, 56)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 56)->vtable[4])(FIELD(self, W3dInterface *, 56));
    }
    if (FIELD(self, void *, 52)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 52)->vtable[4])(FIELD(self, W3dInterface *, 52));
    }
    if (FIELD(self, void *, 48)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 48)->vtable[4])(FIELD(self, W3dInterface *, 48));
    }
    if (FIELD(self, void *, 44)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 44)->vtable[4])(FIELD(self, W3dInterface *, 44));
    }
    if (FIELD(self, void *, 40)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 40)->vtable[4])(FIELD(self, W3dInterface *, 40));
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
    if (FIELD(self, void *, 24)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 24)->vtable[4])(FIELD(self, W3dInterface *, 24));
    }
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    if (FIELD(self, void *, 16)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 16)->vtable[4])(FIELD(self, W3dInterface *, 16));
    }
    if (FIELD(self, void *, 12)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 12)->vtable[4])(FIELD(self, W3dInterface *, 12));
    }
    if (FIELD(self, void *, 8)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 8)->vtable[4])(FIELD(self, W3dInterface *, 8));
    }
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

}
