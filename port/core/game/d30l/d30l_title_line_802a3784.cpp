#include "w3d_ptr.h"
#line 1 "d30l_title_line_802a3784.cpp"
// GWMP8P rev0 0x802a3784. Panel title line setup: builds the FE.TitleLine
// sprite's three UV quads once, loads the sprite three times for left,
// middle and right, sets their glyphs, adds them to the group, then lays
// them out from the config position and the title width. Strings and
// literals are from the original; field names are inferred.
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
struct ResVt { char u0[12]; Ptr32<void (Ptr32<Res>)> acquire; Ptr32<void (Ptr32<Res>)> destroy; char u20[56]; Ptr32<void (Ptr32<Res>, const Vec &, int)> pos; char u80[4]; Ptr32<void (Ptr32<Res>, const Vec &, int)> scale; char u88[4]; Ptr32<void (Ptr32<Res>, Ptr32<Res>, int)> add; };
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
struct Cfg { char u0[20]; Vec pos; char u32[84]; float f116; char u120[16]; int w136; };
struct Title {
    char u0[32];
    unsigned char font; char w3d_tag_rest[3];
    char u36[4];
    Ptr32<Cfg> cfg;
    char u44[68];
    Ptr32<Res> group;
    char u116[104];
    Ref left, mid, right;
    float f232;
};
extern "C" {
int fn_8015ae3c(const Str &);
Ptr32<void> fn_80343808(int);
int fn_80171f90(Ptr32<void>);
int fn_80171ee0(Ptr32<void>, int);
Ptr32<Uv> fn_80171fa0(Ptr32<void>); Ptr32<Uv> fn_80171ff8(Ptr32<void>);
Ptr32<void> memset(Ptr32<void>, int, unsigned);
int fn_8015adf4(const Str &, Ptr32<Held>, int);
Ptr32<Res> fn_8034357c(Ptr32<Res>);
int fn_80173f88(Ptr32<Res>, Ptr32<char>);
}

inline void load(Ref &d, const Str &n, unsigned char t) {
    Held h;
    fn_8015adf4(n, &h, t);
    d = fn_8034357c(h.r);
}
extern "C" void d30l_title_line_802a3784(Ptr32<Title> self) {
    if (self->f232 != 0.0f) {
        Ptr32<Cfg> c = self->cfg;
        if (c->w136) {
            Ptr32<void> m = fn_80343808(fn_8015ae3c(Str("FE.TitleLine")));
            if (fn_80171f90(m) != 3) {
                fn_80171ee0(m, 3);
                Ptr32<Uv> p = fn_80171fa0(m);
                Ptr32<Uv> q = fn_80171ff8(m);
                memset(p, 0, 24);
                memset(q, 0, 24);
                p[0].x = 0.0f; p[0].y = 0.0f;
                q[0].x = 0.25f; q[0].y = 1.0f;
                p[1].x = 0.25f; p[1].y = 0.0f;
                q[1].x = 0.5f; q[1].y = 1.0f;
                p[2].x = 0.75f; p[2].y = 0.0f;
                q[2].x = 0.25f; q[2].y = 1.0f;
                p[0].y = 1.0f - p[0].y - q[0].y;
                p[1].y = 1.0f - p[1].y - q[1].y;
                p[2].y = 1.0f - p[2].y - q[2].y;
            }
            load(self->left, Str("FE.TitleLine"), (unsigned char)(self->font + 30));
            load(self->mid, Str("FE.TitleLine"), (unsigned char)(self->font + 30));
            load(self->right, Str("FE.TitleLine"), (unsigned char)(self->font + 30));

            Vec pos, a, b, d;
            Ptr32<Vec> pa = &a; Ptr32<Vec> pb = &b; Ptr32<Vec> pd = &d;
            char c0 = 0;
            fn_80173f88(self->left.p, &c0);
            char c1 = 1;
            fn_80173f88(self->mid.p, &c1);
            char c2 = 2;
            fn_80173f88(self->right.p, &c2);
            self->group->vt->add(self->group, self->left.p, 0);
            self->group->vt->add(self->group, self->mid.p, 0);
            self->group->vt->add(self->group, self->right.p, 0);
            pos.assign(self->cfg->pos);
            float w = c->f116 * 0.25f;
            float h = c->f116 * 0.5f;
            a.x = w; a.y = h; pa->z = 1.0f;
            b.x = self->f232 * 0.5f; b.y = h; pb->z = 1.0f;
            d.x = 0.0f - pos.x - w; d.y = 0.0f - pos.y - w; pd->z = 0.0f;
            self->left.p->vt->pos(self->left.p, *pd, 0);
            self->left.p->vt->scale(self->left.p, *pa, 0);
            pd->x = self->f232 * 0.5f + (pd->x + w);
            self->mid.p->vt->pos(self->mid.p, *pd, 0);
            self->mid.p->vt->scale(self->mid.p, *pb, 0);
            pd->x = self->f232 * 0.5f + pd->x + w;
            self->right.p->vt->pos(self->right.p, *pd, 0);
            self->right.p->vt->scale(self->right.p, *pa, 0);
        }
    }
}


