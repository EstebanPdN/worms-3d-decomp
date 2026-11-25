#include "w3d_ptr.h"
#line 1 "genparamc_801bcdc0.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Constructor template: base constructor, vtable, then two float vectors
 * filled by an inlined member constructor. */
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }
struct W3dVec3 {
    float x, y, z;
    W3dVec3(float v) { x = v; y = v; z = v; }
};
extern "C" char lbl_80415258[];
extern "C" const float lbl_803ab9e8[];
extern "C" int fn_801bcb0c(Ptr32<void>, Ptr32<void>);
extern "C" char lbl_80415230[];
extern "C" const float lbl_803aba60[];
extern "C" char lbl_80414dd0[];
extern "C" const float lbl_803ac5e0[];
extern "C" int fn_801c0700(Ptr32<void>, Ptr32<void>);

extern "C" Ptr32<void> w3d_construct_vectors_801bcdc0(Ptr32<void> self, Ptr32<void> arg_r4)
{
    float zero;
    fn_801bcb0c(self, arg_r4);
    *(Ptr32<Ptr32<void>>)self = lbl_80415258;
    zero = lbl_803ab9e8[0];
    new ((Ptr32<char>)self + 112) W3dVec3(zero);
    new ((Ptr32<char>)self + 124) W3dVec3(zero);
    return self;
}

extern "C" Ptr32<void> w3d_construct_vectors_801bcfec(Ptr32<void> self, Ptr32<void> arg_r4)
{
    float zero;
    fn_801bcb0c(self, arg_r4);
    *(Ptr32<Ptr32<void>>)self = lbl_80415230;
    zero = lbl_803aba60[0];
    new ((Ptr32<char>)self + 112) W3dVec3(zero);
    new ((Ptr32<char>)self + 124) W3dVec3(zero);
    return self;
}

extern "C" Ptr32<void> w3d_construct_vectors_801c1638(Ptr32<void> self, Ptr32<void> arg_r4)
{
    float zero;
    fn_801c0700(self, arg_r4);
    *(Ptr32<Ptr32<void>>)self = lbl_80414dd0;
    zero = lbl_803ac5e0[0];
    new ((Ptr32<char>)self + 108) W3dVec3(zero);
    new ((Ptr32<char>)self + 120) W3dVec3(zero);
    return self;
}


