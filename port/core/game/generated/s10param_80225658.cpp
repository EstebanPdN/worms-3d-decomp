#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_80225658.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10StringObject { Ptr32<void> vtable; char reserved[112]; Ptr32<char> name; } S10StringObject;
extern int fn_8021ef08(Ptr32<S10StringObject>, Ptr32<void>);
extern void fn_8020c5c0(Ptr32<Ptr32<char>>);
extern Ptr32<unsigned short> fn_80341884(Ptr32<Ptr32<char>>);
extern Ptr32<char> lbl_804b06a0[];
extern char lbl_8041a2f8[];

Ptr32<S10StringObject> w3d_s10_string_ctor_80225658(Ptr32<S10StringObject> object, Ptr32<void> arg_r4)
{
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    Ptr32<Ptr32<char>> name = &object->name;
    fn_8021ef08(object, arg_r4);
    object->vtable = lbl_8041a2f8;
    fn_8020c5c0(name);
    *name = *empty;
    ++*fn_80341884(name);
    return object;
}

}
