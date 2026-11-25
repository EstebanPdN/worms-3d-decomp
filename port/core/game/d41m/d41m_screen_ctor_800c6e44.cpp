#include "w3d_ptr.h"
#line 1 "d41m_screen_ctor_800c6e44.cpp"
// GWMP8P rev0 0x800c6e44. Text screen constructor: runs the base
// constructor, installs the table, clears the eight font handles, the box
// and counters, then resets the screen. Same class as 0x800c71f8. Names are
// inferred.
#pragma interface
struct Font;
struct FontVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Font>)> addref; Ptr32<void (Ptr32<Font>)> release; };
struct Font { Ptr32<FontVt> vt; };
struct FontRef {
    Ptr32<Font> p;
    FontRef() { p = 0; }
    FontRef(const FontRef &);
    ~FontRef() { if (p) p->vt->release(p); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Font *)w3d_p.get()); }
 void operator=(Font *f) { if (f) f->vt->addref(f); if (p) p->vt->release(p); p = f; }
};
struct Line { float x, y, width; int count; Ptr32<const unsigned char> text; };
struct Bits { unsigned int rest:27; unsigned int b4:1; unsigned int b3:1; unsigned int b2:1; unsigned int b1:1; unsigned int b0:1; };
struct Root { void w3d_r_a0() __asm__(W3D_SYM("_ZN4Root2a0Ev"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Root, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Root; };
struct Base_801628b0 : Root { char u4[24] __attribute__((aligned(__alignof__(Root)))); Base_801628b0(); };
struct Screen_8040faa8 : Base_801628b0 {
    int f28 __attribute__((aligned(__alignof__(Base_801628b0)))); char u32[160]; FontRef fonts[8]; unsigned count; int f228; int u232; int f236; FontRef x; Ptr32<Font> box; Bits bits;
    Screen_8040faa8();
    void Reset(Ptr32<Font> const &z);
};
inline void Screen_8040faa8::Reset(Ptr32<Font> const &z) {
    x = z;
    f228 = 0;
    for (int i = 0; i < 8; i++) fonts[i] = 0;
    count = 0;
    bits.b0 = 0; bits.b1 = 0; bits.b2 = 0; bits.b4 = 0;
}
Screen_8040faa8::Screen_8040faa8() { W3D_SET_VPTR(this->Base_801628b0::w3d_vptr_Root, w3d_vt___vt_15Screen_8040faa8, "__vt_15Screen_8040faa8"); 
    f28 = 0;
    box = 0;
    f236 = 0;
    Reset(0);
}


