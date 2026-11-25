#include "w3d_ptr.h"
#line 1 "d32d_debug_text_setup_8015d2f4.cpp"
// GWMP8P rev0 0x8015d2f4. Debug text setup: creates the text mesh and material,
// loads the font texture, and fills one quad size and one uv pair for every
// 16x16 cell of the font. Names are inferred; virtual slots are table views.
#pragma interface
extern "C" void string_finish_8020c5c4(Ptr32<void>);
extern "C" void string_release_80341588(Ptr32<void>);
extern "C" void string_release_header_8020bb2c(Ptr32<void>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    void operator=(const String &o) {
        ++*(Ptr32<unsigned short>)(o.text - 6);
        Ptr32<unsigned short> header = (Ptr32<unsigned short>)(text - 6);
        if (--*header == 0) string_release_header_8020bb2c(header);
        text = o.text;
    }
};
struct Item { void w3d_r_s2() __asm__(W3D_SYM("_ZN4Item2s2Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN4Item6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN4Item7releaseEv")); void w3d_r_s5() __asm__(W3D_SYM("_ZN4Item2s5Ev")); void w3d_r_attach(Ptr32<Item>) __asm__(W3D_SYM("_ZN4Item6attachEPS_"));  __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void attach(Ptr32<Item> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Item>))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Item; };
struct Ref {
    Ptr32<Item> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Item *)w3d_p.get()); }
 void operator=(Item *e) { if (e) e->retain(); if (p) p->release(); p = e; }
    void put(Ptr32<Item> e) { Ptr32<Item> old = p; p = e; if (e) e->retain(); if (old) old->release(); }
};
struct Loader;
struct Local {
    inline int load(Ptr32<Loader> l, Ptr32<const char> file);
    Ptr32<Item> p;
    Local() { p = 0; }
    template <class W3dU> Local(Ptr32<W3dU> w3d_p) : Local((Item *)w3d_p.get()) {}
 Local(Item *e) { p = e; if (e) e->retain(); }
    Local(const Local &);
    ~Local() { if (p) p->release(); }
};
struct Flags { char u[4]; unsigned char v; char w3d_tag_rest[3]; };
struct Hdr { char u0[4]; unsigned short kind; char u6[18]; int count; unsigned short refs; char u30[2]; };
struct Field;
extern "C" Ptr32<void> lock_801ef048(Ptr32<Field>, int, int, int);
struct Field {
    Ptr32<Hdr> h;
    Ptr32<void> lock(int n) {
        Ptr32<Hdr> p = h;
        if (p->kind == 1 && n == p->count) { p->refs++; return p + 1; }
        return lock_801ef048(this, n, 8, 1);
    }
};
struct Vec2 { float x, y; float Y() const { return y; } void SetY(float v) { y = v; } };
struct Mesh : Item { char u4[32] __attribute__((aligned(__alignof__(Item)))); Field sizes; Field uvs; };
struct Texture : Item { char u4[40] __attribute__((aligned(__alignof__(Item)))); unsigned short w; unsigned short h; int u48; };
struct TexProp : Item { char u4[52] __attribute__((aligned(__alignof__(Item)))); int f56; Ref tex; char u64[16]; int f80; };
struct Text : Item { char u4[32] __attribute__((aligned(__alignof__(Item)))); String name; char u40[8]; Ref mat; Ref mesh; };
struct P1 { char u0[4]; Flags flags; char u12[20]; int f32; int f36; };
struct P2 { char u0[4]; Flags flags; char u12[40]; int f52; };
struct P3 { char u0[4]; Flags flags; char u12[12]; float f24; int f28; int f32; };
struct P4 { char u0[4]; Flags flags; char u12[12]; int f24; int f28; };
struct P5 { char u0[4]; Flags flags; char u12[12]; int f24; };
struct Loader { void w3d_r_a2() __asm__(W3D_SYM("_ZN6Loader2a2Ev")); void w3d_r_a3() __asm__(W3D_SYM("_ZN6Loader2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN6Loader2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN6Loader2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN6Loader2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN6Loader2a7Ev")); int w3d_r_load(Ptr32<const char>, Ptr32<Local>) __asm__(W3D_SYM("_ZN6Loader4loadEPKcP5Local"));  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Loader, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int load(Ptr32<const char> w3d_a0, Ptr32<Local> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const char>, Ptr32<Local>))w3d::vfn(this->w3d_vptr_Loader, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Loader; };
inline int Local::load(Ptr32<Loader> l, Ptr32<const char> file) { return l->load(file, this); }
struct Service {
    void w3d_r_s2() __asm__(W3D_SYM("_ZN7Service2s2Ev"));
    void w3d_r_s3() __asm__(W3D_SYM("_ZN7Service2s3Ev"));
    void w3d_r_s4() __asm__(W3D_SYM("_ZN7Service2s4Ev"));
    void w3d_r_s5() __asm__(W3D_SYM("_ZN7Service2s5Ev"));
    void w3d_r_s6() __asm__(W3D_SYM("_ZN7Service2s6Ev"));
    void w3d_r_s7() __asm__(W3D_SYM("_ZN7Service2s7Ev"));
    void w3d_r_s8() __asm__(W3D_SYM("_ZN7Service2s8Ev"));
    void w3d_r_s9() __asm__(W3D_SYM("_ZN7Service2s9Ev"));
    void w3d_r_s10() __asm__(W3D_SYM("_ZN7Service3s10Ev"));
    void w3d_r_s11() __asm__(W3D_SYM("_ZN7Service3s11Ev"));
    void w3d_r_s12() __asm__(W3D_SYM("_ZN7Service3s12Ev"));
    void w3d_r_s13() __asm__(W3D_SYM("_ZN7Service3s13Ev"));
    void w3d_r_s14() __asm__(W3D_SYM("_ZN7Service3s14Ev"));
    void w3d_r_s15() __asm__(W3D_SYM("_ZN7Service3s15Ev"));
    void w3d_r_s16() __asm__(W3D_SYM("_ZN7Service3s16Ev"));
    void w3d_r_s17() __asm__(W3D_SYM("_ZN7Service3s17Ev"));
    void w3d_r_s18() __asm__(W3D_SYM("_ZN7Service3s18Ev"));
    void w3d_r_s19() __asm__(W3D_SYM("_ZN7Service3s19Ev"));
    void w3d_r_s20() __asm__(W3D_SYM("_ZN7Service3s20Ev"));
    void w3d_r_s21() __asm__(W3D_SYM("_ZN7Service3s21Ev"));
    void w3d_r_s22() __asm__(W3D_SYM("_ZN7Service3s22Ev"));
    Ptr32<Loader> w3d_r_find(Ptr32<void>) __asm__(W3D_SYM("_ZN7Service4findEPv"));
 __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Loader> find(Ptr32<void> w3d_a0) { return ((Ptr32<Loader> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Service, 23))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Service; };
extern "C" Ptr32<void> forward_8020b680(Ptr32<void>);
extern "C" Ptr32<Service> service_8020b648();
extern "C" Ptr32<void> count_801d0858(Ptr32<Mesh>, Ptr32<int>);
extern "C" void add_801d086c(Ptr32<Mesh>, Ptr32<TexProp>);
extern "C" void add_801d0898(Ptr32<Mesh>, Ptr32<TexProp>, int);
extern "C" void append_801ef174(Ptr32<Mesh>, int, int, Ptr32<void>);
extern unsigned char d_80414518[], d_80414610[], d_80415b50[], d_804143e0[], d_80415d60[], d_80415c10[], d_80415c80[], d_80415bb0[], d_80415cb0[], d_80415c30[], d_804166b0[], d_80414260[];
struct Self { char u0[16]; Ref text; Ref mat; };
inline Ptr32<Loader> find(Ptr32<void> d) { return service_8020b648()->find(d); }
extern "C" void w3d_d32d_debug_text_setup_8015d2f4(Ptr32<Self> self, Ptr32<const char> file) {
    self->text = (Ptr32<Item>)forward_8020b680(d_80414518);
    self->mat = (Ptr32<Item>)forward_8020b680(d_80414610);
    Ptr32<Mesh> m = (Ptr32<Mesh>)forward_8020b680(d_80415b50);
    Ptr32<Loader> l = find(d_804143e0);
    Local tex;
    if (tex.load(l, file) < 0) return;
    Ptr32<TexProp> tp = (Ptr32<TexProp>)forward_8020b680(d_80415d60);
    tp->tex.put(tex.p);
    tp->f56 = 1;
    tp->f80 = 1;
    int n;
    count_801d0858(m, &n);
    if (n) add_801d0898(m, tp, 0);
    else add_801d086c(m, tp);
    {
        Ptr32<P1> p = (Ptr32<P1>)forward_8020b680(d_80415c10);
        Ptr32<Flags> f = &p->flags;
        p->f32 = 1;
        f->v |= 2;
        p->f36 = 1;
        f->v |= 3;
        append_801ef174(m, 28, 3, p);
    }
    {
        Ptr32<P2> p = (Ptr32<P2>)forward_8020b680(d_80415c80);
        Ptr32<Flags> f = &p->flags;
        p->f52 = 0;
        f->v |= 3;
        append_801ef174(m, 28, 3, p);
    }
    {
        Ptr32<P3> p = (Ptr32<P3>)forward_8020b680(d_80415bb0);
        Ptr32<Flags> f = &p->flags;
        p->f28 = 4;
        f->v |= 2;
        p->f24 = 0.05f;
        f->v |= 2;
        p->f32 = 1;
        f->v |= 3;
        append_801ef174(m, 28, 3, p);
    }
    {
        Ptr32<P4> p = (Ptr32<P4>)forward_8020b680(d_80415cb0);
        Ptr32<Flags> f = &p->flags;
        p->f28 = 6;
        f->v |= 2;
        p->f24 = 7;
        f->v |= 2;
        append_801ef174(m, 28, 3, p);
    }
    {
        Ptr32<P5> p = (Ptr32<P5>)forward_8020b680(d_80415c30);
        Ptr32<Flags> f = &p->flags;
        p->f24 = 0;
        f->v |= 3;
        append_801ef174(m, 28, 3, p);
    }
    Ptr32<Texture> t = (Ptr32<Texture>)tex.p;
    Vec2 c;
    c.x = 16.0f / (float)(int)t->h;
    c.SetY(16.0f / (float)(int)t->w);
    int cells = (((Ptr32<Texture>)tex.p)->h >> 4) * (((Ptr32<Texture>)tex.p)->w >> 4);
    int i = 0;
    Ptr32<Vec2> uv = (Ptr32<Vec2>)m->uvs.lock(cells);
    Ptr32<Vec2> size = (Ptr32<Vec2>)m->sizes.lock(cells);
    for (float v = 1.0f - c.Y(); v >= 0.0f; v -= c.Y()) {
        for (float u = 0.0f; u <= 1.0f - c.x; u += c.x) {
            size[i] = c;
            uv[i].x = u;
            uv[i].y = v;
            i++;
        }
    }
    {
        Ptr32<Text> o = (Ptr32<Text>)self->text.p;
        o->name = String("Debug Text");
    }
    ((Ptr32<Text>)self->text.p)->mat.put(self->mat.p);
    ((Ptr32<Text>)self->text.p)->mesh.put(m);
    Local a((Ptr32<Item>)forward_8020b680(d_804166b0));
    a.p->attach(self->text.p);
    Local b((Ptr32<Item>)forward_8020b680(d_80414260));
    b.p->attach(self->text.p);
}


