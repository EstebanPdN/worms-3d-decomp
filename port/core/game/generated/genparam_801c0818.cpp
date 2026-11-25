#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_801c0818.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80414e48[];
void fn_801b5bd4(Ptr32<void> self, int flags);
void fn_801ea740(Ptr32<void> self);
extern char w3d_vtable_80414da8[];
extern char w3d_vtable_80416320[];
void fn_801c9134(Ptr32<void> self, int flags);
extern char w3d_vtable_804162a8[];
extern char w3d_vtable_80415d80[];
void fn_801ce064(Ptr32<void> self, int flags);
extern char w3d_vtable_8041ae00[];
void fn_801ea138(Ptr32<void> self, int flags);

void w3d_dtor_interfaces6_801c0818(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80414e48;
    held = FIELD(self, W3dInterface *, 100);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 96);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 88);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 84);
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

void w3d_dtor_interfaces6_801c1970(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80414da8;
    held = FIELD(self, W3dInterface *, 88);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
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

void w3d_dtor_interfaces6_801c9c04(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80416320;
    held = FIELD(self, W3dInterface *, 68);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 64);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
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
    fn_801c9134(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces6_801ca65c(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_804162a8;
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 48);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 44);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
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

void w3d_dtor_interfaces6_801cf034(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80415d80;
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
    held = FIELD(self, W3dInterface *, 60);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801ce064(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

void w3d_dtor_interfaces6_8023aff0(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8041ae00;
    held = FIELD(self, W3dInterface *, 64);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
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
    fn_801ea138(self, 0);
    if (flags & 1)
        fn_801ea740(self);
}

}
