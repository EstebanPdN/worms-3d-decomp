#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8dtor_800e7ed8.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_804101b0[];
void fn_8015ff2c(Ptr32<void>, int);

void s8_destroy_800e7ed8(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_804101b0;
    if (FIELD(self, void *, 208)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 208)->vtable[4])(FIELD(self, W3dInterface *, 208));
    }
    if (FIELD(self, void *, 204)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 204)->vtable[4])(FIELD(self, W3dInterface *, 204));
    }
    if (FIELD(self, void *, 200)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 200)->vtable[4])(FIELD(self, W3dInterface *, 200));
    }
    if (FIELD(self, void *, 180)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 180)->vtable[4])(FIELD(self, W3dInterface *, 180));
    }
    if (FIELD(self, void *, 176)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 176)->vtable[4])(FIELD(self, W3dInterface *, 176));
    }
    if (FIELD(self, void *, 172)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 172)->vtable[4])(FIELD(self, W3dInterface *, 172));
    }
    if (FIELD(self, void *, 168)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 168)->vtable[4])(FIELD(self, W3dInterface *, 168));
    }
    if (FIELD(self, void *, 152)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 152)->vtable[4])(FIELD(self, W3dInterface *, 152));
    }
    if (FIELD(self, void *, 148)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 148)->vtable[4])(FIELD(self, W3dInterface *, 148));
    }
    if (FIELD(self, void *, 144)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 144)->vtable[4])(FIELD(self, W3dInterface *, 144));
    }
    if (FIELD(self, void *, 140)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 140)->vtable[4])(FIELD(self, W3dInterface *, 140));
    }
    if (FIELD(self, void *, 136)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 136)->vtable[4])(FIELD(self, W3dInterface *, 136));
    }
    if (FIELD(self, void *, 132)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 132)->vtable[4])(FIELD(self, W3dInterface *, 132));
    }
    if (FIELD(self, void *, 128)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 128)->vtable[4])(FIELD(self, W3dInterface *, 128));
    }
    if (FIELD(self, void *, 124)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 124)->vtable[4])(FIELD(self, W3dInterface *, 124));
    }
    if (FIELD(self, void *, 120)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 120)->vtable[4])(FIELD(self, W3dInterface *, 120));
    }
    if (FIELD(self, void *, 116)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 116)->vtable[4])(FIELD(self, W3dInterface *, 116));
    }
    if (FIELD(self, void *, 112)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 112)->vtable[4])(FIELD(self, W3dInterface *, 112));
    }
    if (FIELD(self, void *, 108)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 108)->vtable[4])(FIELD(self, W3dInterface *, 108));
    }
    if (FIELD(self, void *, 104)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 104)->vtable[4])(FIELD(self, W3dInterface *, 104));
    }
    if (FIELD(self, void *, 100)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 100)->vtable[4])(FIELD(self, W3dInterface *, 100));
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
