#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_801b9910.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
typedef struct W3dInterface { Ptr32<Ptr32<void>> vtable; } W3dInterface;
typedef Ptr32<void (Ptr32<W3dInterface>)> W3dInterfaceFn;
extern char w3d_vtable_80415618[];
extern Ptr32<W3dInterface> lbl_804b05a8;
Ptr32<void> fn_801b8928(Ptr32<void> self, Ptr32<void>);
extern char w3d_vtable_80414c40[];
extern Ptr32<W3dInterface> lbl_804b05ac;
Ptr32<void> fn_801ea0ec(Ptr32<void> self, int);
extern char w3d_vtable_80416398[];
Ptr32<void> fn_801c90c0(Ptr32<void> self, Ptr32<void>);
extern char w3d_vtable_804162d0[];
Ptr32<void> fn_801c9320(Ptr32<void> self, Ptr32<void>);
extern char w3d_vtable_8041a0c8[];
extern char w3d_vtable_8041ad88[];
Ptr32<void> fn_8023b59c(Ptr32<void> self, Ptr32<void>);
extern char w3d_vtable_8041ad10[];
Ptr32<void> fn_8023b738(Ptr32<void> self, Ptr32<void>);
extern char w3d_vtable_8041acc0[];

Ptr32<void> w3d_ctor_held_801b9910(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<W3dInterface> held;
    fn_801b8928(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_80415618;
    FIELD(self, W3dInterface *, 20) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 24) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

Ptr32<void> w3d_ctor_held_801c3f60(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<W3dInterface> held;
    fn_801ea0ec(self, w3d::H(arg_r4));
    held = lbl_804b05ac;
    FIELD(self, void *, 0) = w3d_vtable_80414c40;
    FIELD(self, W3dInterface *, 20) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05ac;
    FIELD(self, W3dInterface *, 24) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

Ptr32<void> w3d_ctor_held_801c9320(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<W3dInterface> held;
    fn_801c90c0(self, arg_r4);
    held = lbl_804b05ac;
    FIELD(self, void *, 0) = w3d_vtable_80416398;
    FIELD(self, W3dInterface *, 28) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05ac;
    FIELD(self, W3dInterface *, 32) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

Ptr32<void> w3d_ctor_held_801ca254(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<W3dInterface> held;
    fn_801c9320(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_804162d0;
    FIELD(self, W3dInterface *, 36) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 40) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

Ptr32<void> w3d_ctor_held_80229c80(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<W3dInterface> held;
    fn_801ea0ec(self, w3d::H(arg_r4));
    held = lbl_804b05ac;
    FIELD(self, void *, 0) = w3d_vtable_8041a0c8;
    FIELD(self, W3dInterface *, 20) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05ac;
    FIELD(self, W3dInterface *, 24) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

Ptr32<void> w3d_ctor_held_8023b738(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<W3dInterface> held;
    fn_8023b59c(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_8041ad88;
    FIELD(self, W3dInterface *, 28) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 32) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

Ptr32<void> w3d_ctor_held_8023befc(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<W3dInterface> held;
    fn_8023b738(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_8041ad10;
    FIELD(self, W3dInterface *, 36) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 40) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

Ptr32<void> w3d_ctor_held_8023c470(Ptr32<void> self, Ptr32<void> arg_r4)
{
    Ptr32<W3dInterface> held;
    fn_8023b738(self, arg_r4);
    held = lbl_804b05a8;
    FIELD(self, void *, 0) = w3d_vtable_8041acc0;
    FIELD(self, W3dInterface *, 36) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    held = lbl_804b05a8;
    FIELD(self, W3dInterface *, 40) = held;
    if (held)
        ((W3dInterfaceFn)held->vtable[3])(held);
    return self;
}

}
