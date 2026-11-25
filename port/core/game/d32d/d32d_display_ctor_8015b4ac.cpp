#include "w3d_ptr.h"
#line 1 "d32d_display_ctor_8015b4ac.cpp"
// GWMP8P rev0 0x8015b4ac. Display setup constructor: 800x600, 24 bit colour, 32 bit depth, 60 Hz.
// Takes a reference on the service entry, creates the global mode record and
// sets its defaults. Field names are inferred; virtual slots are table views.
#pragma interface
struct Item { void w3d_r_s2() __asm__(W3D_SYM("_ZN4Item2s2Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN4Item6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN4Item7releaseEv"));  __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Item; };
struct Root { void w3d_r_a0() __asm__(W3D_SYM("_ZN4Root2a0Ev"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Root, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Root; };
struct Base_8015be3c : Root { char u4[24] __attribute__((aligned(__alignof__(Root)))); Base_8015be3c(); };
struct Ref { Ptr32<Item> p; void set(Ptr32<Item> e) { if (e) e->retain(); if (p) p->release(); p = e; } };
struct Mode;
extern Ptr32<Mode> mode_804b1880;
struct Mode {
    Ptr32<Item> r;
    unsigned char b7:1; unsigned char kind:7;
    unsigned char c5;
    unsigned short :11; unsigned short d:5;
    template <class W3dU> Mode(Ptr32<W3dU> w3d_p) : Mode((Item *)w3d_p.get()) {}
 Mode(Item *i) : r(i) {
        if (r) r->retain();
        kind = 10;
        b7 = 0;
        c5 = 0;
        d = 6;
        mode_804b1880 = this;
    }
};
extern "C" Ptr32<Item> forward_8020b680(Ptr32<void>);
extern unsigned char desc_80419460[];
struct Display_804110e8 : Base_8015be3c {
    void w3d_r_a0() __asm__(W3D_SYM("_ZN16Display_804110e82a0Ev"));
    int f28 __attribute__((aligned(__alignof__(Base_8015be3c))));
    int width;
    int height;
    unsigned char :5; unsigned char b2:1; unsigned char b1:1; unsigned char b0:1;
    unsigned char colour;
    unsigned char depth;
    unsigned char r43;
    unsigned char r44;
    int f48;
    int f52;
    int f56;
    int u60;
    float f64;
    int f68;
    Ref ref;
    unsigned int :23; unsigned int g8:1; unsigned int g7:1; unsigned int g5:2; unsigned int g4:1; unsigned int g3:1; unsigned int g2:1; unsigned int g1:1; unsigned int g0:1;
    int f80;
    int f84;
    Display_804110e8();
 __attribute__((always_inline)) inline void a0() { this->Base_8015be3c::a0(); } };
Display_804110e8::Display_804110e8() : f48(0), f68(0) { W3D_SET_VPTR(this->Base_8015be3c::w3d_vptr_Root, w3d_vt___vt_16Display_804110e8, "__vt_16Display_804110e8"); 
    b0 = 0;
    b2 = 0;
    ref.p = 0;
    f28 = 2;
    width = 800;
    height = 600;
    colour = 24;
    depth = 32;
    r43 = 60;
    r44 = 60;
    ref.set(forward_8020b680(desc_80419460));
    new Mode(ref.p);
    g1 = 0;
    g2 = 0;
    g3 = 1;
    g8 = 1;
    g4 = 0;
    g0 = 1;
    g7 = 0;
    b1 = 0;
    f56 = 1;
    f64 = 1.0f;
    g5 = 3;
    f80 = 20;
    f52 = 0;
    f84 = 0;
}


