#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s12_string_property_8019b1fc.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

typedef struct S12PropertyInfo {
    Ptr32<const char> name;
    unsigned short size;
    unsigned char elementType;
    unsigned char type;
    Ptr32<void> descriptor;
    Ptr32<void> extra;
    int reserved16;
} S12PropertyInfo;
typedef struct S12StringBinding { char reserved[8]; Ptr32<char> value; } S12StringBinding;
extern Ptr32<S12StringBinding> fn_801ed24c(Ptr32<void>, Ptr32<const char>);
extern Ptr32<void> fn_801ec52c(Ptr32<void>, Ptr32<const char>);
extern void fn_8020c5c0(Ptr32<void>);
extern Ptr32<unsigned short> fn_80341884(Ptr32<void>);
extern void fn_8020bb2c(Ptr32<void>);
extern void fn_8020c5c4(Ptr32<void>);
extern void fn_80341588(Ptr32<void>);
extern Ptr32<char> lbl_804b06a0[];
extern char lbl_803a9500[], lbl_803a9530[], lbl_803a9558[], lbl_803fe938[], lbl_8045e004[];
extern S12PropertyInfo lbl_8045cd0c;
extern int lbl_804b02f8;
extern Ptr32<void> fn_801eff8c(Ptr32<void>, Ptr32<S12PropertyInfo>);
extern void fn_801e8d9c(Ptr32<void>);
Ptr32<void> memset(Ptr32<void>, int, unsigned int);

int w3d_s12_init_string_property_8019b1fc(Ptr32<void> object)
{
    Ptr32<S12StringBinding> binding = fn_801ed24c(object, lbl_803a9500);
    typedef struct S12String { Ptr32<char> data; } S12String;
    /* Observed local layout: string at sp+8, descriptor at sp+16. */
    struct { S12String string; int reserved; S12PropertyInfo property; } frame;
    Ptr32<S12String> temporary = (Ptr32<S12String>)&frame.string;
    Ptr32<Ptr32<char>> empty = lbl_804b06a0;
    unsigned short remaining;
    Ptr32<unsigned short> oldHeader;
    fn_8020c5c0(temporary);
    temporary->data = *empty;
    ++*fn_80341884(temporary);
    ++*(Ptr32<unsigned short>)(temporary->data - 6);
    oldHeader = (Ptr32<unsigned short>)(binding->value - 6);
    remaining = --*oldHeader;
    if (remaining == 0)
        fn_8020bb2c(oldHeader);
    binding->value = temporary->data;
    fn_8020c5c4(temporary);
    fn_80341588(temporary);
    fn_801ec52c(object, lbl_803a9530);
    if (!lbl_804b02f8) {
        Ptr32<S12PropertyInfo> target = &lbl_8045cd0c;
        memset(&frame.property, 0, sizeof frame.property);
        frame.property.name = lbl_803a9558;
        frame.property.size = 20;
        frame.property.elementType = 2;
        frame.property.type = 9;
        frame.property.descriptor = lbl_8045e004;
        frame.property.extra = lbl_803fe938;
        *target = frame.property;
        lbl_804b02f8 = 1;
    }
    fn_801eff8c(object, &lbl_8045cd0c);
    fn_801e8d9c(object);
    return 0;
}

}
