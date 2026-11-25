#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "genparam_801f8eb8.c"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
void fn_801f8fbc(Ptr32<void> object, int flags);
void fn_80206b40(Ptr32<void> object, int flags);
void fn_8020803c(Ptr32<void> object, int flags);
void fn_8020d36c(Ptr32<void> object, int flags);
void fn_80219edc(Ptr32<void> object, int flags);
void fn_8021a208(Ptr32<void> object, int flags);
void fn_80219fc8(Ptr32<void> object, int flags);
void fn_8021a0b4(Ptr32<void> object, int flags);
void fn_8021a11c(Ptr32<void> object, int flags);

unsigned short w3d_release_801f8eb8(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 4);
    if (count == 0 && object)
        fn_801f8fbc(object, 3);
    return count;
}

unsigned short w3d_release_80206a44(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 4);
    if (count == 0 && object)
        fn_80206b40(object, 3);
    return count;
}

unsigned short w3d_release_80207f3c(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 4);
    if (count == 0 && object)
        fn_8020803c(object, 3);
    return count;
}

unsigned short w3d_release_8020d268(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 4);
    if (count == 0 && object)
        fn_8020d36c(object, 3);
    return count;
}

unsigned short w3d_release_80219ab8(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_80219edc(object, 3);
    return count;
}

unsigned short w3d_release_80219b74(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_8021a208(object, 3);
    return count;
}

unsigned short w3d_release_80219c30(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_80219fc8(object, 3);
    return count;
}

unsigned short w3d_release_80219cec(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_8021a0b4(object, 3);
    return count;
}

unsigned short w3d_release_80219da8(Ptr32<void> object)
{
    unsigned short count = --FIELD(object, unsigned short, 20);
    if (count == 0 && object)
        fn_8021a11c(object, 3);
    return count;
}

}
