#include "w3d_ptr.h"
#line 1 "d30l_key_box_setup_802b3148.cpp"
// GWMP8P rev0 0x802b3148. On-screen keyboard box setup: creates the
// FE.BasicBox handle and its transform from the zero vector, builds the
// FE.K.BoxBdr sprite's six UV quads once, loads six border parts, sets glyph
// and colour bytes, adds them to the group and marks the box ready. Strings,
// UV literals and glyph values are from the original; field names are
// inferred.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &);
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
};
struct Vec {
    float x, y, z;
    Vec() {}
    void assign(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Res;
struct ResVt { char u0[12]; Ptr32<void (Ptr32<Res>)> acquire; Ptr32<void (Ptr32<Res>)> destroy; char u20[72]; Ptr32<void (Ptr32<Res>, Ptr32<Res>, int)> add; };
struct Res { Ptr32<ResVt> vt; };
struct Ref {
    Ptr32<Res> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Res *)w3d_p.get()); }
 void operator=(Res *q) {
        if (q) q->vt->acquire(q);
        if (p) p->vt->destroy(p);
        p = q;
    }
};
struct Held {
    Ptr32<Res> r;
    Held() : r(0) {}
    Held(const Held &);
    ~Held() { if (r) r->vt->destroy(r); }
};
struct Uv { float x, y; };
struct Colour { unsigned char r, g, b, a; };
struct SColour { signed char r, g, b, a; };
struct Hnd { Ptr32<void> v; };
struct Box {
    char u0[28];
    Ptr32<Res> group;
    char u32[4];
    Ref part[6];
    int ready;
    float f64;
    char u68[12];
    float f80, f84;
    Ptr32<void> w88;
    char u92[4];
    int w96;
    Ptr32<Hnd> handle;
};
extern int base_804abb60;
extern const Vec zero_8045e788[];
extern "C" {
Ptr32<void> fn_801fe1d8(int);
Ptr32<Hnd> fn_802ae4d8(Ptr32<void>, Ptr32<const char>, unsigned char);
void fn_802ae5f8(Ptr32<Hnd>, float, float, float);
void fn_802af220(Ptr32<Hnd>, const Vec &);
void fn_802af254(Ptr32<Hnd>, Ptr32<Res>);
int fn_8015ae3c(const Str &);
Ptr32<void> fn_80343808(int);
int fn_80171f90(Ptr32<void>);
int fn_80171ee0(Ptr32<void>, int);
Ptr32<Uv> fn_80171fa0(Ptr32<void>); Ptr32<Uv> fn_80171ff8(Ptr32<void>);
Ptr32<void> memset(Ptr32<void>, int, unsigned);
int fn_8015adf4(const Str &, Ptr32<Held>, unsigned char);
Ptr32<Res> fn_8034357c(Ptr32<Res>);
int fn_80173f88(Ptr32<Res>, Ptr32<char>);
Ptr32<Colour> fn_80178f54(Ptr32<void>);
int fn_80173df0(Ptr32<Res>, Ptr32<const SColour>);
}
inline void load(Ref &d, const Str &n, unsigned char t) {
    Held h;
    fn_8015adf4(n, &h, t);
    d = fn_8034357c(h.r);
}

extern "C" void d30l_key_box_setup_802b3148(Ptr32<Box> self) {
    float s = 0.5f;
    Vec v;
    Ptr32<Vec> pv = &v;
    int b = base_804abb60;
    float w = self->f64;
    self->handle = fn_802ae4d8(fn_801fe1d8(4), "FE.BasicBox", (unsigned char)(b + 30));
    pv->assign(zero_8045e788[0]);
    fn_802ae5f8(self->handle, w, self->f80 * s, self->f84 * s);
    fn_802af220(self->handle, v);
    fn_802af254(self->handle, self->group);
    Ptr32<void> m = fn_80343808(fn_8015ae3c(Str("FE.K.BoxBdr")));
    if (fn_80171f90(m) != 6) {
        fn_80171ee0(m, 6);
        Ptr32<Uv> p = fn_80171fa0(m);
        Ptr32<Uv> q = fn_80171ff8(m);
        memset(p, 0, 48);
        memset(q, 0, 48);
        p[0].x = 0.046875f; p[0].y = 0.046875f; p[1].x = 0.421875f; p[1].y = 0.046875f; p[2].x = 0.421875f; p[2].y = 0.421875f; p[3].x = 0.046875f; p[3].y = 0.421875f; p[4].x = 0.921875f; p[4].y = 0.578125f; p[5].x = 0.875f; p[5].y = 0.1875f; 
        q[0].x = 0.375f; q[0].y = 0.375f; q[1].x = 0.375f; q[1].y = 0.375f; q[2].x = 0.375f; q[2].y = 0.375f; q[3].x = 0.375f; q[3].y = 0.375f; q[4].x = 0.015625f; q[4].y = 0.375f; q[5].x = 0.015625f; q[5].y = 0.015625f; 
        for (int i = 0; i < 6; i++) p[i].y = 1.0f - p[i].y - q[i].y;
    }
            load(self->part[0], Str("FE.K.BoxBdr"), (unsigned char)(b + 29));
            load(self->part[1], Str("FE.K.BoxBdr"), (unsigned char)(b + 29));
            load(self->part[2], Str("FE.K.BoxBdr"), (unsigned char)(b + 29));
            load(self->part[3], Str("FE.K.BoxBdr"), (unsigned char)(b + 29));
            load(self->part[4], Str("FE.K.BoxBdr"), (unsigned char)(b + 29));
            load(self->part[5], Str("FE.K.BoxBdr"), (unsigned char)(b + 29));

    char c0 = 1; fn_80173f88(self->part[0].p, &c0);
    char c1 = 3; fn_80173f88(self->part[1].p, &c1);
    char c2 = 2; fn_80173f88(self->part[2].p, &c2);
    char c3 = 4; fn_80173f88(self->part[3].p, &c3);
    char c4 = 4; fn_80173f88(self->part[4].p, &c4);
    char c5 = 5; fn_80173f88(self->part[5].p, &c5);
    self->group->vt->add(self->group, self->part[0].p, 0);
    self->group->vt->add(self->group, self->part[1].p, 0);
    self->group->vt->add(self->group, self->part[2].p, 0);
    self->group->vt->add(self->group, self->part[3].p, 0);
    self->group->vt->add(self->group, self->part[4].p, 0);
    self->group->vt->add(self->group, self->part[5].p, 0);
    Colour t = *fn_80178f54(self->w88);
    if (!self->w96) t.a = 255; else t.a = 150;
    SColour c;
    Ptr32<SColour> pc = &c;
    int al = t.a;
    c.r = -1; pc->g = -1; pc->b = -1; pc->a = al;
    fn_80173df0(self->part[5].p, pc);
    c.r = 0; pc->g = 0; pc->b = 0; pc->a = -128;
    fn_80173df0(self->part[4].p, pc);
    fn_80173df0(self->part[3].p, pc);
    fn_80173df0(self->part[2].p, pc);
    fn_80173df0(self->part[1].p, pc);
    fn_80173df0(self->part[0].p, pc);
    self->ready = 1;
}


