#include "w3d_ptr.h"
#line 1 "d30d_game_update_8015e0e0.cpp"
// GWMP8P rev0 0x8015e0e0. Per-frame scene update and render: creates the four
// named profile records on first use (RenderScene, CullSort, Draw, OverlayDraw),
// advances the clock by the elapsed milliseconds, updates the visible items, and
// times the cull, draw and overlay stages into +152, +156 and +160. Virtual slots
// are reference-ABI table views; names are inferred.
struct Obj;
struct Item { char u0[20]; int f20; };
struct ObjVt {
    char u0[12];
    Ptr32<void (Ptr32<Obj>)> retain;
    Ptr32<void (Ptr32<Obj>)> release;
    char u14[4];
    Ptr32<Ptr32<Obj> (Ptr32<Obj>, Ptr32<void>)> s24;
    char u1c[4];
    Ptr32<Ptr32<Obj> (Ptr32<Obj>)> s32;
    Ptr32<void (Ptr32<Obj>)> s36;
    Ptr32<void (Ptr32<Obj>)> s40;
    char u2c[4];
    Ptr32<void (Ptr32<Obj>, int)> s48;
    Ptr32<void (Ptr32<Obj>, int, int)> s52;
    Ptr32<void (Ptr32<Obj>)> s56;
    char u3c[4];
    Ptr32<void (Ptr32<Obj>, Ptr32<Obj>)> s64;
    Ptr32<Ptr32<Obj> (Ptr32<Obj>)> s68;
    Ptr32<void (Ptr32<Obj>)> s72;
    Ptr32<void (Ptr32<Obj>, int)> s76;
    char u50[4];
    Ptr32<int (Ptr32<Obj>, int)> s84;
    char u58[4];
    Ptr32<void (Ptr32<Obj>, Ptr32<Obj>)> s92;
    Ptr32<void (Ptr32<Obj>, float)> s96;
    Ptr32<void (Ptr32<Obj>, float)> s100;
    char u68[8];
    Ptr32<void (Ptr32<Obj>, float)> s112;
    Ptr32<Ptr32<Item> (Ptr32<Obj>, Ptr32<unsigned char>)> s116;
    char u78[64];
    Ptr32<unsigned char (Ptr32<Obj>)> s184;
    Ptr32<unsigned char (Ptr32<Obj>)> s188;
};
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
    Ptr32<Obj> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) { p = o; if (p) p->vt->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
};
struct CurVt { char u0[24]; Ptr32<Ptr32<Obj> (Ptr32<struct Cur>)> s24; char u1c[4]; Ptr32<int (Ptr32<struct Cur>)> s32; };
struct Cur { Ptr32<CurVt> vt; };
struct Current { char u0[8]; Ptr32<Ptr32<Cur>> cur; };
struct Timer { long long t; Timer() {} Timer(const Timer &); void start(); int delta(); };
struct Self {
    Ptr32<ObjVt> vt; char u4[44]; unsigned f48; float f52; Ptr32<Obj> f56; Ptr32<Obj> f60; char u40[4]; Ptr32<Obj> f68; Current f72; unsigned char f87; char u54[3]; char u58[4]; Ptr32<Obj> f92; Ptr32<Obj> f96; Ptr32<Obj> f100; char u68[8]; int f112; char u74[36]; int f152; int f156; int f160; int f164;
};
extern "C" {
void stamp_801fc790(Ptr32<void>, Ptr32<const char>);
long long elapsed_801fe4d8();
int ticks_801fe508(int);
Ptr32<void> pair_80343994();
void poll_801fdbec(Ptr32<void>, int);
Ptr32<void> service_80344278();
void reset_801fe314(Ptr32<void>);
}
extern int rec0_804b0090, guard0_804b0098, rec1_804b009c, guard1_804b00a4, rec2_804b00a8, guard2_804b00b0, rec3_804b00b4, guard3_804b00bc;
extern char name0_803a44d0[], name1_803a44dc[], name2_803a44e8[], name3_803a44f0[];
extern Ptr32<Obj> global_804b1884;
inline void Timer::start() { t = elapsed_801fe4d8(); }
inline int Timer::delta() { return (int)elapsed_801fe4d8() - (int)t; }
inline const unsigned char &minimum(const unsigned char &a, const unsigned char &b) { return b < a ? b : a; }
extern "C" int d30d_game_update_8015e0e0(Ptr32<Self> self, int ms) {
    if (!guard0_804b0098) { stamp_801fc790(&rec0_804b0090, name0_803a44d0); guard0_804b0098 = 1; }
    if (!guard1_804b00a4) { stamp_801fc790(&rec1_804b009c, name1_803a44dc); guard1_804b00a4 = 1; }
    if (!guard2_804b00b0) { stamp_801fc790(&rec2_804b00a8, name2_803a44e8); guard2_804b00b0 = 1; }
    if (!guard3_804b00bc) { stamp_801fc790(&rec3_804b00b4, name3_803a44f0); guard3_804b00bc = 1; }
    float dt = (float)ms / 1000.0f;
    if (self->f164 < 0) self->f56->vt->s112(self->f56, dt);
    self->f52 += dt;
    self->f68->vt->s100(self->f68, self->f52);
    self->f100->vt->s96(self->f100, self->f52);
    Timer t;
    t.start();
    self->f68->vt->s72(self->f68);
    unsigned char last = minimum((unsigned char)self->f56->vt->s188(self->f56), (unsigned char)(self->f87 - 1));
    Ptr32<Current> cam = &self->f72;
    for (unsigned char i = self->f56->vt->s184(self->f56); i <= last; i++) {
        Ptr32<Item> item = self->f56->vt->s116(self->f56, &i);
        if (item && item->f20) {
            self->f60->vt->s24(self->f60, item);
            int v = ((Ptr32<int (Ptr32<Self>, int)>)self->vt->s84)(self, i);
            self->f68->vt->s52(self->f68, v, 0);
            self->f68->vt->s24(self->f68, item);
        }
    }
    Ref r(self->f68->vt->s68(self->f68));
    self->f152 = ticks_801fe508(t.delta());
    self->f96->vt->s36(self->f96);
    self->f96->vt->s48(self->f96, self->f48 & 0x40000000 ? 3 : 2);
    ((Ptr32<void (Ptr32<Obj>, int)>)self->f96->vt->s84)(self->f96, (*cam->cur)->vt->s32(*cam->cur));
    self->f100->vt->s64(self->f100, (*cam->cur)->vt->s24(*cam->cur));
    global_804b1884->vt->s92(global_804b1884, (*cam->cur)->vt->s24(*cam->cur));
    if (self->f112) self->f100->vt->s76(self->f100, self->f112);
    t.start();
    self->f100->vt->s24(self->f100, r.p);
    self->f156 = ticks_801fe508(t.delta());
    self->f96->vt->s40(self->f96);
    poll_801fdbec(pair_80343994(), 1);
    reset_801fe314(service_80344278());
    t.start();
    self->f92->vt->s56(self->f92);
    self->f160 = ticks_801fe508(t.delta());
    return 0;
}


