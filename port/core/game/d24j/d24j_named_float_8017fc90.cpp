#include "w3d_ptr.h"
#line 1 "d24j_named_float_8017fc90.cpp"
// Read a named float of a mesh's material (Worms 3D GameCube PAL, 0x8017fc90).
//
// Prepares the source at +40 when needed (0x8017ffbc; "Cound't..." is reported
// through 0x801fcb64 when it stays empty), queries its array interface
// (0x8040e0a8), holds it in a handle and scans the name/value pairs. Writes the
// value and returns 0, or returns 0x80004005 when the name is absent. The
// source is a real virtual call (built with -fvtable-thunks): the virtual call
// keeps the object in its own register and copies it to r3.

extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int fn_8017ffbc(Ptr32<void>);
extern "C" int fn_801fcb64(Ptr32<const char>, int);
extern char text_803a779c[];
extern char iid_8040e0a8[];
// The handle is one word, held in an inline helper with its own stack block.

struct Pair { Ptr32<const char> name; float value; };
struct Count { int u; unsigned count; };
struct Array { Ptr32<Ptr32<void>> vtable;
    void retain() { ((Ptr32<void (Ptr32<Array>)>)vtable[3])(this); }
    void release() { ((Ptr32<void (Ptr32<Array>)>)vtable[4])(this); }
    Ptr32<const Count> counts() { return ((Ptr32<Ptr32<const Count> (Ptr32<Array>)>)vtable[8])(this); }
    Ptr32<const Pair> at(unsigned i) { return ((Ptr32<Ptr32<const Pair> (Ptr32<Array>, unsigned int)>)vtable[9])(this, i); }
};
struct Handle { Ptr32<Array> p;
    Handle() { p = 0; }
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Array *)w3d_p.get()) {}
 Handle(Array *v) { p = v; if (v) v->retain(); }
    ~Handle() { if (p) p->release(); }
};
struct Source {
    void w3d_r_slot_0() __asm__(W3D_SYM("_ZN6Source6slot_0Ev"));
    void w3d_r_slot_1() __asm__(W3D_SYM("_ZN6Source6slot_1Ev"));
    void w3d_r_slot_2() __asm__(W3D_SYM("_ZN6Source6slot_2Ev"));
    void w3d_r_slot_3() __asm__(W3D_SYM("_ZN6Source6slot_3Ev"));
    void w3d_r_slot_4() __asm__(W3D_SYM("_ZN6Source6slot_4Ev"));
    void w3d_r_slot_5() __asm__(W3D_SYM("_ZN6Source6slot_5Ev"));
    void w3d_r_slot_6() __asm__(W3D_SYM("_ZN6Source6slot_6Ev"));
    void w3d_r_slot_7() __asm__(W3D_SYM("_ZN6Source6slot_7Ev"));
    void w3d_r_slot_8() __asm__(W3D_SYM("_ZN6Source6slot_8Ev"));
    void w3d_r_slot_9() __asm__(W3D_SYM("_ZN6Source6slot_9Ev"));
    void w3d_r_slot_10() __asm__(W3D_SYM("_ZN6Source7slot_10Ev"));
    void w3d_r_slot_11() __asm__(W3D_SYM("_ZN6Source7slot_11Ev"));
    void w3d_r_query(Ptr32<void> iid, int z, Ptr32<Ptr32<Array>> out) __asm__(W3D_SYM("_ZN6Source5queryEPviPP5Array"));
 __attribute__((always_inline)) inline void slot_0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void slot_11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Source, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void query(Ptr32<void> w3d_a0, int w3d_a1, Ptr32<Ptr32<Array>> w3d_a2) { ((void (*)(w3d_u32, Ptr32<void>, int, Ptr32<Ptr32<Array>>))w3d::vfn(this->w3d_vptr_Source, 14))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_Source; };
inline void query_array(Ptr32<Source> s, Ptr32<Ptr32<Array>> out) { *out = 0; s->query(iid_8040e0a8, 0, out); }
struct Mesh { char u[40]; Ptr32<Source> source; };
inline Ptr32<Array> get_array(Ptr32<Source> s) {
    Ptr32<Array> raw = 0;
    s->query(iid_8040e0a8, 0, &raw);
    Ptr32<Array> p = raw;
    if (p) p->release();
    return p;
}
inline int find_value(Ptr32<Mesh> m, Ptr32<const char> name, Ptr32<float> out) {
    Ptr32<Array> raw;
    query_array(m->source, &raw);
    Ptr32<Array> p = raw;
    if (p) p->release();
    Handle h(p);
    for (unsigned i = 0; i < h.p->counts()->count; i++) {
        if (strcmp(h.p->at(i)->name, name) == 0) {
            *out = h.p->at(i)->value;
            return 0;
        }
    }
    return 0x80004005;
}

extern "C" int d24j_named_float_8017fc90(Ptr32<Mesh> m, Ptr32<const char> name, Ptr32<float> out)
{
    if (m->source == 0) {
        fn_8017ffbc(m);
        if (m->source == 0) fn_801fcb64(text_803a779c, 0);
    }
    return find_value(m, name, out);
}


