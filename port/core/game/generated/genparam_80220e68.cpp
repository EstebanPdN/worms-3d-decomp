#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_80220e68.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
extern char w3d_vtable_8041a528[];
extern int lbl_804b06a0[];
int fn_8021ef08(Ptr32<void> self, Ptr32<void>);
void fn_8020c5c0(Ptr32<void> string);
Ptr32<unsigned short> fn_80341884(Ptr32<void> string);
extern char w3d_vtable_8041a8d8[];
Ptr32<void> fn_801ea0ec(Ptr32<void> self, int);
extern char w3d_vtable_8041a770[];
extern char w3d_vtable_8041a720[];
extern char w3d_vtable_8041abd0[];
int fn_8023b59c(Ptr32<void> self, Ptr32<void>);
extern char w3d_vtable_8041ab80[];
int fn_8023d32c(Ptr32<void> self, Ptr32<void>);
extern char w3d_vtable_8041ab58[];
int fn_8023d574(Ptr32<void> self, Ptr32<void>);

Ptr32<void> w3d_ctor_strings_80220e68(Ptr32<void> self, Ptr32<void> arg_r4)
{
    fn_8021ef08(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041a528;
    fn_8020c5c0((Ptr32<char>)self + 116);
    FIELD(self, int, 116) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 116))++;
    fn_8020c5c0((Ptr32<char>)self + 120);
    FIELD(self, int, 120) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 120))++;
    return self;
}

Ptr32<void> w3d_ctor_strings_80235bc0(Ptr32<void> self, Ptr32<void> arg_r4)
{
    fn_801ea0ec(self, w3d::H(arg_r4));
    FIELD(self, void *, 0) = w3d_vtable_8041a8d8;
    fn_8020c5c0((Ptr32<char>)self + 20);
    FIELD(self, int, 20) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 20))++;
    fn_8020c5c0((Ptr32<char>)self + 24);
    FIELD(self, int, 24) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 24))++;
    return self;
}

Ptr32<void> w3d_ctor_strings_80237438(Ptr32<void> self, Ptr32<void> arg_r4)
{
    fn_801ea0ec(self, w3d::H(arg_r4));
    FIELD(self, void *, 0) = w3d_vtable_8041a770;
    fn_8020c5c0((Ptr32<char>)self + 20);
    FIELD(self, int, 20) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 20))++;
    fn_8020c5c0((Ptr32<char>)self + 24);
    FIELD(self, int, 24) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 24))++;
    return self;
}

Ptr32<void> w3d_ctor_strings_802379a0(Ptr32<void> self, Ptr32<void> arg_r4)
{
    fn_801ea0ec(self, w3d::H(arg_r4));
    FIELD(self, void *, 0) = w3d_vtable_8041a720;
    fn_8020c5c0((Ptr32<char>)self + 20);
    FIELD(self, int, 20) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 20))++;
    fn_8020c5c0((Ptr32<char>)self + 24);
    FIELD(self, int, 24) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 24))++;
    return self;
}

Ptr32<void> w3d_ctor_strings_8023d6dc(Ptr32<void> self, Ptr32<void> arg_r4)
{
    fn_8023b59c(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041abd0;
    fn_8020c5c0((Ptr32<char>)self + 28);
    FIELD(self, int, 28) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 28))++;
    fn_8020c5c0((Ptr32<char>)self + 32);
    FIELD(self, int, 32) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 32))++;
    return self;
}

Ptr32<void> w3d_ctor_strings_8023db50(Ptr32<void> self, Ptr32<void> arg_r4)
{
    fn_8023d32c(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041ab80;
    fn_8020c5c0((Ptr32<char>)self + 32);
    FIELD(self, int, 32) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 32))++;
    fn_8020c5c0((Ptr32<char>)self + 36);
    FIELD(self, int, 36) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 36))++;
    return self;
}

Ptr32<void> w3d_ctor_strings_8023de5c(Ptr32<void> self, Ptr32<void> arg_r4)
{
    fn_8023d574(self, arg_r4);
    FIELD(self, void *, 0) = w3d_vtable_8041ab58;
    fn_8020c5c0((Ptr32<char>)self + 28);
    FIELD(self, int, 28) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 28))++;
    fn_8020c5c0((Ptr32<char>)self + 32);
    FIELD(self, int, 32) = lbl_804b06a0[0];
    (*fn_80341884((Ptr32<char>)self + 32))++;
    return self;
}

}
