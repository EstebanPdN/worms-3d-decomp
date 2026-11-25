#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "gendtor_80218f1c.c"
/* Deleting destructors synthesized by tools/gen_dtor_units.py and verified
 * identical to the original after linking. Offsets are literal and externs are
 * named by original address; member types and class names are pending. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80419778[];
extern char w3d_vtable_804181c0[];
void fn_80210990(Ptr32<void>, int);
void fn_801fe1f8(Ptr32<void>);
extern char w3d_vtable_80419858[];
int fn_802198a0(Ptr32<void>);
void fn_801fe2e0(Ptr32<void>);
extern char w3d_vtable_8041c9a0[];
void fn_802e03e0(Ptr32<void>);
extern int lbl_804b190c;
extern char w3d_vtable_8041c9f8[];
extern char w3d_vtable_8041ca60[];
extern char w3d_vtable_8041cab8[];

void w3d_dtor_80218f1c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419778;
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_804181c0;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_80219578(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_80419858;
    fn_802198a0(self);
    if (FIELD(self, void *, 28)) {
        fn_801fe2e0(FIELD(self, void *, 28));
    }
    FIELD(self, int, 28) = 0;
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_804181c0;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_802e028c(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041c9a0;
    fn_802e03e0(self);
    lbl_804b190c = 0;
    FIELD(self, void *, 0) = w3d_vtable_8041c9f8;
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

void w3d_dtor_802e2ca0(Ptr32<void> self, int flags)
{
    FIELD(self, void *, 0) = w3d_vtable_8041ca60;
    if (FIELD(self, void *, 24)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 24)->vtable[4])(FIELD(self, W3dInterface *, 24));
    }
    if (FIELD(self, void *, 20)) {
        ((W3dInterfaceFn)FIELD(self, W3dInterface *, 20)->vtable[4])(FIELD(self, W3dInterface *, 20));
    }
    FIELD(self, void *, 0) = w3d_vtable_8041cab8;
    fn_80210990((Ptr32<char>)self + 4, 0);
    if (flags & 1) {
        fn_801fe1f8(self);
    }
}

}
