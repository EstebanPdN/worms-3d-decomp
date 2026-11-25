#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_8002b3a0.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_8040e368[];
void fn_8015ff2c(Ptr32<void> self, int flags);
extern char w3d_vtable_8040e6d8[];
extern char w3d_vtable_8040e878[];
extern char w3d_vtable_8040fcc8[];
extern char w3d_vtable_8040fe00[];
extern char w3d_vtable_804102a8[];
void fn_801628ec(Ptr32<void> self, int flags);
extern char w3d_vtable_804103a8[];
extern char w3d_vtable_80410560[];
void fn_8002a978(Ptr32<void> self, int flags);
extern char w3d_vtable_80412120[];
void fn_80190384(Ptr32<void> self, int flags);
extern char w3d_vtable_80419cb0[];

void w3d_dtor_forward_8002b3a0(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8040e368;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_8003a4e0(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8040e6d8;
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_8003d3cc(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8040e878;
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_800d53ac(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8040fcc8;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_800da2a0(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_8040fe00;
    held = FIELD(self, W3dInterface *, 32);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_800efbb4(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_804102a8;
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801628ec(self, flags);
}

void w3d_dtor_forward_800f1e88(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_804103a8;
    held = FIELD(self, W3dInterface *, 28);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8015ff2c(self, flags);
}

void w3d_dtor_forward_800fe3a8(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80410560;
    held = FIELD(self, W3dInterface *, 64);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_8002a978(self, flags);
}

void w3d_dtor_forward_80174354(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80412120;
    held = FIELD(self, W3dInterface *, 40);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_80190384(self, flags);
}

void w3d_dtor_forward_8021cc18(Ptr32<void> self, int flags)
{
    Ptr32<W3dInterface> held;
    FIELD(self, void *, 0) = w3d_vtable_80419cb0;
    held = FIELD(self, W3dInterface *, 36);
    if (held)
        ((W3dInterfaceFn)held->vtable[4])(held);
    fn_801628ec(self, flags);
}

}
