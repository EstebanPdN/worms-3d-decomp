#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_8020ddfc.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Registry { unsigned char reserved[0x20]; unsigned short count; unsigned short w3d_flags_high; } S10Registry;
extern S10Registry lbl_80463360;
extern void fn_8020df08(Ptr32<void>);
extern void fn_8020fd2c(Ptr32<S10Registry>, Ptr32<void>);

void w3d_s10_registry_remove_8020ddfc(Ptr32<void> object)
{
    fn_8020df08(object);
    fn_8020fd2c(&lbl_80463360, (Ptr32<char>)object + 4);
    --lbl_80463360.count;
}

}
