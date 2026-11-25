#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_8018f23c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80413098[];
void fn_801ea138(Ptr32<void> self, int flags);
void fn_801ea740(Ptr32<void> self);
extern char w3d_vtable_80414d30[];
void fn_801b52d8(Ptr32<void> self, int flags);
extern char w3d_vtable_8041b870[];
void fn_8024cd58(Ptr32<void> self, int flags);

void w3d_dtor_interfaces8_8018f23c(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80413098;
    held = FIELD(self, W3dInterface *, 48);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 44);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
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

void w3d_dtor_interfaces8_801c2520(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80414d30;
    held = FIELD(self, W3dInterface *, 48);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 44);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 24);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 20);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b52d8(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces8_8024cfb0(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8041b870;
    held = FIELD(self, W3dInterface *, 92);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 88);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 84);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 72);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 68);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 96);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 80);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 76);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8024cd58(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

}
