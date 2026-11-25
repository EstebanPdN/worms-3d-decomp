#include "w3d_ptr.h"
#line 1 "d31e_combine_chain_801d2400.cpp"
// (Worms 3D GameCube PAL, 0x801d2400).
//
// Multiplies the local matrices of a bone chain: visits each bone through
// the visitor at +68, copies the first bone's matrix into a pair of working
// matrices, then multiplies each next bone into the other working matrix
// with 0x801f740c. Stores the final product, or the identity at 0x8045e748
// when the chain is empty, in the chain's matrix at +36. Names are inferred.

struct Mat {
    float m[12];
    Mat() { }
    ~Mat() { }
};
struct Bone { char pad[20]; Mat local; };
struct Chain { char pad[24]; int count; char pad28[4]; Ptr32<Ptr32<Bone>> items; Mat world; };
struct ChainRef { Ptr32<Chain> p; };
struct Visitor { void w3d_r_v0() __asm__(W3D_SYM("_ZN7Visitor2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN7Visitor2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN7Visitor2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN7Visitor2v3Ev")); int w3d_r_visit(Ptr32<Bone>) __asm__(W3D_SYM("_ZN7Visitor5visitEP4Bone"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Visitor, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Visitor, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Visitor, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Visitor, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int visit(Ptr32<Bone> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<Bone>))w3d::vfn(this->w3d_vptr_Visitor, 6))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Visitor; };
struct Self { char pad[68]; Ptr32<Visitor> visitor; };
extern Mat g_identity[];
extern "C" void w3d_auto_801f740c(Ptr32<Mat>, Ptr32<const Mat>, Ptr32<const Mat>);
extern "C" void w3d_d31e_combine_chain_801d2400(Ptr32<Self> self, Ptr32<ChainRef> chain)
{
    bool first = true;
    Mat m[2];
    int cur = 0;
    Ptr32<Chain> c = chain->p;
    Ptr32<Ptr32<Bone>> p = c->items;
    Ptr32<Ptr32<Bone>> end = p + c->count;
    for (; p != end; p++) {
        self->visitor->visit(*p);
        if (first) {
            m[0] = (*p)->local;
            first = false;
        } else {
            cur ^= 1;
            w3d_auto_801f740c(&m[cur], &(*p)->local, &m[cur ^ 1]);
        }
    }
    if (first) chain->p->world = g_identity[0];
    else chain->p->world = m[cur];
}


