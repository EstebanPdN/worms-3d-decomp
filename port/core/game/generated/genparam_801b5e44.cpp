#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_801b5e44.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80415aa0[];
void fn_801b5bd4(Ptr32<void> self, int flags);
void fn_801ea740(Ptr32<void> self);
extern char w3d_vtable_80415a78[];
extern char w3d_vtable_80415a50[];
extern char w3d_vtable_80415028[];
void fn_801b4c6c(Ptr32<void> self, int flags);
extern char w3d_vtable_80414c18[];
void fn_801ea138(Ptr32<void> self, int flags);

void w3d_dtor_interfaces5_801b5e44(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80415aa0;
    held = FIELD(self, W3dInterface *, 80);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 76);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 72);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 68);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 64);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b5bd4(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces5_801b63cc(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80415a78;
    held = FIELD(self, W3dInterface *, 76);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 80);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 72);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 68);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 64);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b5bd4(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces5_801b687c(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80415a50;
    held = FIELD(self, W3dInterface *, 80);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 76);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 72);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 68);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 64);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b5bd4(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces5_801beb74(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80415028;
    held = FIELD(self, W3dInterface *, 60);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 56);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 52);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 48);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 44);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801b4c6c(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces5_801c4370(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80414c18;
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

}
