#include "w3d_ptr.h"
#line 1 "genparamc_801bfb00.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Pair template (later batch): one binding with a three-float default built
 * by an inlined constructor and copied by structure assignment. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
struct W3dVec3 {
    float x, y, z;
    W3dVec3(float a, float b, float c) { x = a; y = b; z = c; }
};
extern "C" char lbl_803ac0ec[];
extern "C" const float lbl_803ac110[];
extern "C" const float lbl_803ac114[];
extern "C" Ptr32<void> fn_801f0210(Ptr32<void>, Ptr32<const char>);
extern "C" void fn_801e8d9c(Ptr32<void>);
extern "C" char lbl_803ac248[];
extern "C" const float lbl_803ac26c[];
extern "C" const float lbl_803ac270[];

extern "C" int w3d_register_vector_binding_801bfb00(Ptr32<void> self)
{
    Ptr32<void> binding = fn_801f0210(self, lbl_803ac0ec);
    W3dVec3 value(lbl_803ac110[0], lbl_803ac110[0], lbl_803ac114[0]);
    FIELD(binding, W3dVec3, 8) = value;
    fn_801e8d9c(self);
    return 0;
}

extern "C" int w3d_register_vector_binding_801bff10(Ptr32<void> self)
{
    Ptr32<void> binding = fn_801f0210(self, lbl_803ac248);
    W3dVec3 value(lbl_803ac26c[0], lbl_803ac26c[0], lbl_803ac270[0]);
    FIELD(binding, W3dVec3, 8) = value;
    fn_801e8d9c(self);
    return 0;
}


