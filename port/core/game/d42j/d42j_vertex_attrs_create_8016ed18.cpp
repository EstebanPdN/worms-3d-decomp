#include "w3d_ptr.h"
#line 1 "d42j_vertex_attrs_create_8016ed18.cpp"
// Creates the four vertex attribute objects of a mesh format from a constant table and returns the array.
// Names are inferred: the table entries are the four values handed to the attribute setter.
struct Attr {
    void w3d_r_s0() __asm__(W3D_SYM("_ZN4Attr2s0Ev")); void w3d_r_addRef() __asm__(W3D_SYM("_ZN4Attr6addRefEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN4Attr7releaseEv"));
 __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Attr, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void addRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Attr, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Attr, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Attr; };
struct AttrDesc { unsigned short a, b; unsigned char c, d; };
extern const AttrDesc table_803a645c[];
extern char type_80361ad8[];
extern "C" Ptr32<Attr> w3d_r24b_invoke_ready_callback_8020fcb4(Ptr32<void>);
extern "C" void w3d_auto_8016f8a0(Ptr32<Attr>, unsigned short, unsigned short, unsigned short, unsigned char);
struct Ptr { Ptr32<Attr> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Attr *)w3d_p.get()); }
 Ptr &operator=(Attr *q) { if (q) q->addRef(); if (p) p->release(); p = q; return *this; }
};
struct Arr {
    unsigned size; unsigned short cap; Ptr32<Ptr> data;
    Ptr32<Ptr> begin() { return data; }
};
extern "C" void w3d_d30k_compact_vector_resize_80210b90(Ptr32<Arr>, int);
struct Self { char u[20]; Arr arr; };
inline void resize(Arr &a, int n) { w3d_d30k_compact_vector_resize_80210b90(&a, n); }

extern "C" Ptr32<Ptr> vertex_attrs_create_8016ed18(Ptr32<Self> self, Ptr32<int> count)
{
    int n = 4;
    *count = n;
    resize(self->arr, n);
    for (unsigned i = 0; i < n; ++i) {
        Ptr32<Attr> o = w3d_r24b_invoke_ready_callback_8020fcb4(type_80361ad8);
        Ptr32<Ptr> slots = self->arr.begin();
        slots[i] = o;
        w3d_auto_8016f8a0(o, table_803a645c[i].a, table_803a645c[i].b, table_803a645c[i].c, table_803a645c[i].d);
    }
    return self->arr.begin();
}


