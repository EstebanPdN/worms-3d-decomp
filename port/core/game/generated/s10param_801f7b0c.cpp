#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_801f7b0c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10Registry { unsigned char reserved[0x20]; unsigned short count; unsigned short w3d_flags_high; } S10Registry;
extern S10Registry lbl_8045e7b8;
extern void fn_801f7c18(Ptr32<void>);
extern void fn_8020fd2c(Ptr32<S10Registry>, Ptr32<void>);

void w3d_s10_registry_remove_801f7b0c(Ptr32<void> object)
{
    fn_801f7c18(object);
    fn_8020fd2c(&lbl_8045e7b8, (Ptr32<char>)object + 4);
    --lbl_8045e7b8.count;
}

}
