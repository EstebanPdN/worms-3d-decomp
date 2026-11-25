#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_801b5454.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80414528[];
void fn_801b4c6c(Ptr32<void> self, int flags);
void fn_801ea740(Ptr32<void> self);
extern char w3d_vtable_80415618[];
void fn_801b8964(Ptr32<void> self, int flags);
extern char w3d_vtable_80414ce0[];
extern char w3d_vtable_80414c40[];
void fn_801ea138(Ptr32<void> self, int flags);
extern char w3d_vtable_80416398[];
void fn_801c9134(Ptr32<void> self, int flags);
extern char w3d_vtable_804162d0[];
void fn_801c939c(Ptr32<void> self, int flags);
extern char w3d_vtable_8041a0c8[];
extern char w3d_vtable_8041ae28[];
extern char w3d_vtable_8041ad88[];
void fn_8023b5f0(Ptr32<void> self, int flags);
extern char w3d_vtable_8041ad10[];
void fn_8023b7b4(Ptr32<void> self, int flags);
extern char w3d_vtable_8041acc0[];

void w3d_dtor_interfaces_801b5454(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80414528;
    held = FIELD(self, W3dInterface *, 52);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 48);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b4c6c(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801b998c(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80415618;
    held = FIELD(self, W3dInterface *, 24);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 20);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b8964(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801c33c8(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80414ce0;
    held = FIELD(self, W3dInterface *, 60);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 44);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b4c6c(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801c3fdc(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80414c40;
    held = FIELD(self, W3dInterface *, 24);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 20);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801ea138(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801c939c(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80416398;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801c9134(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_801ca2d0(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_804162d0;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801c939c(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_80229cfc(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8041a0c8;
    held = FIELD(self, W3dInterface *, 24);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 20);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801ea138(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_8023ac9c(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8041ae28;
    held = FIELD(self, W3dInterface *, 56);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 60);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801ea138(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_8023b7b4(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8041ad88;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8023b5f0(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_8023bf78(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8041ad10;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8023b7b4(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces_8023c4ec(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8041acc0;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8023b7b4(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

}
