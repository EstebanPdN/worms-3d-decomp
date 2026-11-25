#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20param_801789ec.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Shared-string field assignment: copy the argument string, release the old value and store the new one. */
typedef struct W3dStringHeader { unsigned short references; } W3dStringHeader;
typedef struct W3dString { Ptr32<char> text; } W3dString;
extern Ptr32<void> fn_8020bb54(Ptr32<W3dString>, Ptr32<char>);
extern void fn_8020bb2c(Ptr32<W3dStringHeader>);
extern void fn_8020c5c4(Ptr32<W3dString>);
extern void fn_80341588(Ptr32<W3dString>);

int w3d_s20_assign_string_801789ec(Ptr32<char> self, Ptr32<Ptr32<char>> source) {
    Ptr32<char> owner = *(Ptr32<Ptr32<char>>)(self + 4);
    W3dString copy;
    fn_8020bb54(&copy, source[0]);
    ++((Ptr32<W3dStringHeader>)(copy.text - 6))->references;
    {
        Ptr32<W3dStringHeader> old = (Ptr32<W3dStringHeader>)(*(Ptr32<Ptr32<char>>)(owner + 24) - 6);
        if (--old->references == 0)
            fn_8020bb2c(old);
    }
    source = &copy.text;
    *(Ptr32<Ptr32<char>>)(owner + 24) = *source;
    fn_8020c5c4(&copy);
    fn_80341588(&copy);
    return 0;
}

}
