#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s8dtor_800deb44.c"
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_8040ff68[];
void fn_800e0400(Ptr32<void>);
void fn_8020c5c4(Ptr32<void>);
void fn_80341588(Ptr32<void>);
void fn_800de958(Ptr32<void>);

void s8_destroy_800deb44(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 228) = w3d_vtable_8040ff68;
    fn_800e0400(self);
    if (FIELD(self, void *, 216)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 216)->vtable[4])(FIELD(self, W3dInterface *, 216));
    }
    if (FIELD(self, void *, 212)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 212)->vtable[4])(FIELD(self, W3dInterface *, 212));
    }
    if (FIELD(self, void *, 208)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 208)->vtable[4])(FIELD(self, W3dInterface *, 208));
    }
    fn_8020c5c4((Ptr32<char>)self + 140);
    fn_80341588((Ptr32<char>)self + 140);
    if (FIELD(self, void *, 136)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 136)->vtable[4])(FIELD(self, W3dInterface *, 136));
    }
    if (FIELD(self, void *, 132)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 132)->vtable[4])(FIELD(self, W3dInterface *, 132));
    }
    if (FIELD(self, void *, 128)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 128)->vtable[4])(FIELD(self, W3dInterface *, 128));
    }
    if (flags & 1) {
        fn_800de958(self);
    }
}

}
