#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s10param_8022572c.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S10PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> descriptor;
    Ptr32<void> extra;
    int reserved16;
} S10PropertyInfo;
typedef struct S10StringBinding { char reserved[8]; Ptr32<char> value; } S10StringBinding;
extern Ptr32<S10StringBinding> fn_801ed24c(Ptr32<void>, Ptr32<const char>);
extern void fn_801ecc6c(Ptr32<void>, Ptr32<const char>);
extern void fn_8020c5c0(Ptr32<void>);
extern Ptr32<unsigned short> fn_80341884(Ptr32<void>);
extern void fn_8020bb2c(Ptr32<void>);
extern void fn_8020c5c4(Ptr32<void>);
extern void fn_80341588(Ptr32<void>);
extern Ptr32<char> lbl_804b06a0[];
extern char lbl_803b7d00[], lbl_803a94cc[], lbl_803a94f0[], lbl_803fe92c[], lbl_8045e004[];
extern S10PropertyInfo lbl_8045ccf8;
extern int lbl_804b02f4;
extern void fn_801eff8c(Ptr32<void>, Ptr32<S10PropertyInfo>);
extern void fn_801e8d9c(Ptr32<void>);
Ptr32<void> memset();

int w3d_s10_init_string_property_8022572c(Ptr32<void> object)
{
    Ptr32<S10StringBinding> binding = fn_801ed24c(object, lbl_803b7d00);
    struct { Ptr32<char> data; } temporary;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    unsigned short remaining;
    Ptr32<unsigned short> oldHeader;
    fn_8020c5c0(&temporary);
    temporary.data = *empty;
    ++*fn_80341884(&temporary);
    ++*(Ptr32<unsigned short>)(temporary.data - 6);
    oldHeader = (Ptr32<unsigned short>)(binding->value - 6);
    remaining = --*oldHeader;
    if (remaining == 0)
        fn_8020bb2c(oldHeader);
    binding->value = temporary.data;
    fn_8020c5c4(&temporary);
    fn_80341588(&temporary);
    fn_801e8d9c(object);
    return 0;
}

}
