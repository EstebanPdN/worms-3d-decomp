#include "w3d_ptr.h"
#line 1 "d40n_limit_blend_influences_8019c668.cpp"
// GWMP8P rev0 0x8019c668. Builds a limited skin blend: for each vertex keeps
// the n largest of its source weights (sorted, then insertion), normalises
// them and writes indices and weights into a new blend object held by the
// owner. Names are inferred.
extern "C" Ptr32<void> fn_8020b680(Ptr32<void>);
struct Pair { float weight; int index; };
extern "C" void fn_80351d58(Ptr32<Pair>, Ptr32<Pair>);
extern char type_80363604[];
extern char registry_804148b0[];
struct Rc { void w3d_r_s8() __asm__(W3D_SYM("_ZN2Rc2s8Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN2Rc6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN2Rc7releaseEv"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Rc, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Rc, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Rc, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Rc; };
struct Store;
extern "C" Ptr32<void> fn_801ef048(Ptr32<Ptr32<Store>>, unsigned, unsigned, unsigned);
struct Store { char u0[4]; unsigned short refs; char u6[18]; int count; unsigned short locks; short u30; char data[1]; };
struct Blend : Rc { char u4[16] __attribute__((aligned(__alignof__(Rc)))); Ptr32<Store> weights; unsigned short perVertex; char u26[2]; Ptr32<Store> indices;
};
inline Ptr32<void> lockArray(Ptr32<Ptr32<Store>> st, unsigned n, unsigned size) {
    Ptr32<Store> s = *st;
    Ptr32<void> p;
    if (s->refs == 1 && n == s->count) { ++s->locks; p = s->data; }
    else p = fn_801ef048(st, n, size, 1);
    return p;
}
struct InputApi { void w3d_r_s8() __asm__(W3D_SYM("_ZN8InputApi2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN8InputApi3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN8InputApi3s16Ev")); Ptr32<char> w3d_r_Type() __asm__(W3D_SYM("_ZN8InputApi4TypeEv"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputApi, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputApi, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputApi, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<char> Type() { return ((Ptr32<char> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_InputApi, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_InputApi; };
struct Input : InputApi { char u4[16] __attribute__((aligned(__alignof__(InputApi)))); Ptr32<Store> data; unsigned short stride; };
struct NodeApi { void w3d_r_s8() __asm__(W3D_SYM("_ZN7NodeApi2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN7NodeApi3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN7NodeApi3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN7NodeApi3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN7NodeApi3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN7NodeApi3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN7NodeApi3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN7NodeApi3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN7NodeApi3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN7NodeApi3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN7NodeApi3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN7NodeApi3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN7NodeApi3s56Ev")); unsigned w3d_r_Influences() __asm__(W3D_SYM("_ZN7NodeApi10InfluencesEv"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline unsigned int Influences() { return ((unsigned int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_NodeApi, 15))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_NodeApi; };
struct Second { void w3d_r_z8() __asm__(W3D_SYM("_ZN6Second2z8Ev"));  __attribute__((always_inline)) inline void z8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Second, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Second; };
struct Owner : NodeApi, Second { char u8[36] __attribute__((aligned(__alignof__(NodeApi)), aligned(__alignof__(Second)))); Ptr32<Blend> blend; };
extern "C" int w3d_d40n_limit_blend_influences_8019c668(Ptr32<Second> a, Ptr32<Input> in) {
    Ptr32<Owner> self = w3d::sc<Owner *>(a);
    unsigned n = self->Influences();
    if (in->Type() != type_80363604) return 0;
    Ptr32<Blend> b = (Ptr32<Blend>)fn_8020b680(registry_804148b0);
    if (b) b->retain();
    if (self->blend) self->blend->release();
    self->blend = b;
    unsigned bytes = n * sizeof(Pair);
    Ptr32<float> src = (Ptr32<float>)in->data->data;
    unsigned stride = in->stride;
    unsigned entries = in->data->count / stride;
    Ptr32<Pair> top = (Ptr32<Pair>)__builtin_alloca(bytes);
    Ptr32<char> idx;
    Ptr32<float> w;
    idx = (Ptr32<char>)lockArray(&b->indices, n * entries, 1);
    w = (Ptr32<float>)lockArray(&b->weights, n * entries, 4);
    b->perVertex = n;
    for (unsigned e = 0; e < entries; e++) {
        for (unsigned j = 0; j < n; j++) { top[j].weight = src[j]; top[j].index = j; }
        fn_80351d58(top, top + n);
        for (unsigned k = n; k < stride; k++) {
            for (unsigned j = 0; j < n; j++) {
                if (top[j].weight < src[k]) {
                    for (unsigned m = n - 1; m > j; m--) top[m] = top[m - 1];
                    top[j].weight = src[k];
                    top[j].index = k;
                    break;
                }
            }
        }
        float sum = 0.0f;
        unsigned j;
        for (j = 0; j < n; j++) sum += top[j].weight;
        float inv = 1.0f / sum;
        for (j = 0; j < n; j++) { idx[j] = top[j].index; w[j] = top[j].weight * inv; }
        idx += n; w += n; src += stride;
    }
    return 0;
}


