/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Constructor template: base constructor, vtable, then two float vectors
 * filled by an inlined member constructor. */
inline void *operator new(unsigned int, void *place) { return place; }
struct W3dVec3 {
    float x, y, z;
    W3dVec3(float v) { x = v; y = v; z = v; }
};
extern "C" char lbl_80415258[];
extern "C" const float lbl_803ab9e8[];
extern "C" int fn_801bcb0c(void *, void *);
extern "C" char lbl_80415230[];
extern "C" const float lbl_803aba60[];
extern "C" char lbl_80414dd0[];
extern "C" const float lbl_803ac5e0[];
extern "C" int fn_801c0700(void *, void *);

extern "C" void *w3d_construct_vectors_801bcdc0(void *self, void * arg_r4)
{
    float zero;
    fn_801bcb0c(self, arg_r4);
    *(void **)self = lbl_80415258;
    zero = lbl_803ab9e8[0];
    new ((char *)self + 112) W3dVec3(zero);
    new ((char *)self + 124) W3dVec3(zero);
    return self;
}

extern "C" void *w3d_construct_vectors_801bcfec(void *self, void * arg_r4)
{
    float zero;
    fn_801bcb0c(self, arg_r4);
    *(void **)self = lbl_80415230;
    zero = lbl_803aba60[0];
    new ((char *)self + 112) W3dVec3(zero);
    new ((char *)self + 124) W3dVec3(zero);
    return self;
}

extern "C" void *w3d_construct_vectors_801c1638(void *self, void * arg_r4)
{
    float zero;
    fn_801c0700(self, arg_r4);
    *(void **)self = lbl_80414dd0;
    zero = lbl_803ac5e0[0];
    new ((char *)self + 108) W3dVec3(zero);
    new ((char *)self + 120) W3dVec3(zero);
    return self;
}
