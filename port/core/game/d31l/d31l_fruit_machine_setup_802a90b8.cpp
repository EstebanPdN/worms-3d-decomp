#include "w3d_ptr.h"
#line 1 "d31l_fruit_machine_setup_802a90b8.cpp"
// GWMP8P rev0 0x802a90b8. Wormpot fruit-machine setup: resolves the three
// game-data values, loads the body and three reel models, plays the intro
// clip, fills the eleven button and reel slots with screen rectangles, clip
// names and tips, then binds the sounds. Strings, literals and vtable slots
// come from the original; field names are inferred.
extern "C" void fn_8020c5c0(Ptr32<void>), fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
    unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); }
};
inline void trace(Str) {}
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Res;
struct ResVt { char u0[12]; Ptr32<void (Ptr32<Res>)> acquire; Ptr32<void (Ptr32<Res>)> destroy; char u20[56]; Ptr32<int (Ptr32<Res>, const Vec &, int)> pos; Ptr32<int (Ptr32<Res>, const Vec &, int)> rot; Ptr32<int (Ptr32<Res>, const Vec &, int)> scale; char u88[4]; Ptr32<void (Ptr32<Res>, Ptr32<Res>, Ptr32<const char>)> add; };
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
struct Key { Ptr32<char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((char *)w3d_p.get()) {}
 Key(char *n) : name(n) {} };
struct Slot {
    int type;
    Str name;
    int i8;
    float left, top, right, bottom;
    int a, c, d, e;
    Ptr32<const char> x; Ptr32<const char> y; Ptr32<const char> z;
    int h0, h1, h2;
    Str tip;
};
struct Cfg { char u0[20]; Vec size; Vec pos; char u44[100]; Str s144, s148, s152; };
struct Ctx { char u[52]; int w52; };
struct Root;
struct RootVt { char u[92]; Ptr32<void (Ptr32<Root>, Ptr32<const char>, Ptr32<int>)> bind; Ptr32<void (Ptr32<Root>, Ptr32<const char>, const Vec &)> set; };
struct Root { Ptr32<RootVt> vt; };
struct Scene { char u[108]; Ptr32<Root> root; };
struct Menu {
    char u0[28];
    char sub[12];
    Ptr32<Cfg> cfg;
    char u44[64];
    Str err;
    Ptr32<Res> node;
    char u116[96];
    int w212, w216, w220;
    char u224[4];
    int w228, w232, w236, w240;
    Ref model, reel[3];
    int clip;
    char u264[4];
    int w268;
    float f272, f276, f280, f284;
    int w288, w292, w296, w300, w304, w308, w312, w316, w320, w324;
    Str s328;
    Slot slots[11];
    char u1124[192];
    int v[3];
    char u1328[12];
    int w1340;
    char u1344[12];
    int w1356, w1360;
    int w1364[3];
};
extern Ptr32<Scene> scene_804b1788;
extern unsigned char font_804abb63;
extern Vec table_8045e788;
extern char  str_803d66c4[], str_803d66d4[], str_803d66e4[], str_803d6714[], str_803d6720[], str_803d6730[], str_803d6740[], str_803d6750[], str_803d6774[], str_803d6784[], str_803d6794[], str_803d67a4[], str_803d67b0[], str_803d67c0[], str_803d67d0[], str_803d67e0[], str_803d67f0[], str_803d6800[], str_803d6810[], str_803d6820[], str_803d682c[], str_803d6840[], str_803d6850[], str_803d6860[], str_803d6870[], str_803d687c[], str_803d688c[], str_803d66f4[], str_803d6704[], str_803d6760[], str_803d689c[];
extern char str_803d6654[], str_803d6678[], str_803d6688[], str_803d6698[], str_803d669c[], str_803d66a0[], str_803d66a4[], str_803d66b4[], str_803d68ac[], str_803d68c0[], str_803d68d4[], str_803d68e0[];
extern "C" {
void fn_8020c510(Ptr32<void>, Ptr32<const char>, ...);
Ptr32<Str> fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
Ptr32<Ctx> fn_80165254();
void fn_802b0b84(Ptr32<char>, Ptr32<Menu>, int);
int fn_800fc1b0(const Key &, Ptr32<Held>);
int fn_800fd62c(Ptr32<Str>, Ptr32<void (Ptr32<void>, Ptr32<void>)>, Ptr32<Menu>, Ptr32<int>);
int fn_802aa544(Ptr32<void>, Ptr32<void>);
int fn_802aa498(Ptr32<void>, Ptr32<void>);
int fn_802aa3ec(Ptr32<void>, Ptr32<void>);
int fn_802aa5f0(Ptr32<Menu>, Str);
int fn_802ab378(Ptr32<Menu>, int, int);
int fn_8015adf4(const Str &, Ptr32<Held>, unsigned char);
Ptr32<Res> fn_80343584(Ptr32<Res>);
int fn_80181640(Ptr32<Res>, Ptr32<const char>, Ptr32<int>, int, float, float, float);
void fn_802aaf5c(Ptr32<Menu>, int, int);
}
inline int pos0(int v) { if (v < 0) v = 0; return v; }
inline void load(Ref &d, const Str &n, unsigned char t) {
    Held h;
    fn_8015adf4(n, &h, t);
    d = fn_80343584(h.r);
}
extern "C" void d31l_fruit_machine_setup_802a90b8(Ptr32<Menu> self) {
    fn_802b0b84(self->sub, self, fn_80165254()->w52);
    Ptr32<Cfg> c = self->cfg;
    Held h;
    {
        Str &s = c->s152;
        if (s.length()) {
            Key k(c->s152.p);
            if (fn_800fc1b0(k, &h) < 0) {
                trace(c->s152);
                fn_8020c510(&self->err, str_803d6654, w3d::VA(c->s152.p));
            } else
                fn_800fd62c(&s, (Ptr32<void (Ptr32<void>, Ptr32<void>)>)fn_802aa3ec, self, &self->w212);
        }
    }
    {
        Str &s = c->s148;
        if (s.length()) {
            Key k(c->s148.p);
            if (fn_800fc1b0(k, &h) < 0) {
                trace(c->s148);
                fn_8020c510(&self->err, str_803d6654, w3d::VA(c->s148.p));
            } else
                fn_800fd62c(&s, (Ptr32<void (Ptr32<void>, Ptr32<void>)>)fn_802aa498, self, &self->w216);
        }
    }
    {
        Str &s = c->s144;
        if (s.length()) {
            Key k(c->s144.p);
            if (fn_800fc1b0(k, &h) < 0) {
                trace(c->s144);
                fn_8020c510(&self->err, str_803d6654, w3d::VA(c->s144.p));
            } else
                fn_800fd62c(&s, (Ptr32<void (Ptr32<void>, Ptr32<void>)>)fn_802aa544, self, &self->w220);
        }
    }
    self->w228 = fn_802aa5f0(self, c->s152);
    self->w232 = fn_802aa5f0(self, c->s148);
    self->w236 = fn_802aa5f0(self, c->s144);
    int n = fn_802ab378(self, 0, self->w228);
    self->v[0] = n < 0 ? 0 : n;
    n = fn_802ab378(self, 1, self->w232);
    self->v[1] = n < 0 ? 0 : n;
    n = fn_802ab378(self, 2, self->w236);
    self->v[2] = n < 0 ? 0 : n;
    unsigned char t = font_804abb63 + 29;
    load(self->model, Str(str_803d6678), t);
    Ptr32<Vec> sz = &c->size;
    self->model.p->vt->pos(self->model.p, c->pos, 0);
    self->model.p->vt->scale(self->model.p, *sz, 0);
    self->node->vt->add(self->node, self->model.p, 0);
    load(self->reel[0], Str(str_803d6688), t);
        Vec r(0.0f, -1.57079637f, 0.0f);
        self->reel[0].p->vt->pos(self->reel[0].p, table_8045e788, 0);
        self->reel[0].p->vt->scale(self->reel[0].p, *sz, 0);
        self->reel[0].p->vt->rot(self->reel[0].p, r, 0);
        self->model.p->vt->add(self->model.p, self->reel[0].p, str_803d6698);
        load(self->reel[1], Str(str_803d6688), t);
        self->reel[1].p->vt->pos(self->reel[1].p, table_8045e788, 0);
        self->reel[1].p->vt->scale(self->reel[1].p, *sz, 0);
        self->reel[1].p->vt->rot(self->reel[1].p, r, 0);
        self->model.p->vt->add(self->model.p, self->reel[1].p, str_803d669c);
        load(self->reel[2], Str(str_803d6688), t);
        self->reel[2].p->vt->pos(self->reel[2].p, table_8045e788, 0);
        self->reel[2].p->vt->scale(self->reel[2].p, *sz, 0);
        self->reel[2].p->vt->rot(self->reel[2].p, r, 0);
        self->model.p->vt->add(self->model.p, self->reel[2].p, str_803d66a0);
    fn_80181640(self->model.p, str_803d66a4, &self->clip, 0, 1.0f, 0.0f, 0.0f);
    Vec v(0.0f, 0.0f, 1.0f);
    scene_804b1788->root->vt->set(scene_804b1788->root, str_803d66b4, v);
    self->f272 = 0.0f;
    self->f280 = 0.0f;
    self->f276 = 0.0f;
    self->f284 = 0.0f;
    self->w268 = 0;
    self->w288 = 1;
    self->w292 = 1;
    self->w296 = 1;
    self->w300 = 1;
    self->w304 = 0;
    self->w308 = 0;
    self->w312 = 0;
    self->w316 = 0;
    self->w320 = 0;
    self->w324 = 0;
    fn_8020bd38(&self->s328, 0);
    self->slots[0].type = 1;
    fn_8020bd38(&self->slots[0].name, 0);
    self->slots[0].i8 = 2;
    self->slots[0].left = -102.0f;
    self->slots[0].right = -77.0f;
    self->slots[0].top = 107.0f;
    self->slots[0].bottom = 137.0f;
    self->slots[0].a = 2;
    self->slots[0].c = 1;
    self->slots[0].d = 2;
    self->slots[0].e = 5;
    self->slots[0].x = str_803d66c4;
    self->slots[0].y = str_803d66d4;
    self->slots[0].z = str_803d66e4;
    self->slots[0].h0 = 0;
    self->slots[0].h1 = 0;
    self->slots[0].h2 = 0;
    fn_8020bd38(&self->slots[0].tip, str_803d66f4);
    self->slots[1].type = 0;
    fn_8020bd38(&self->slots[1].name, str_803d6704);
    self->slots[1].i8 = 1;
    self->slots[1].left = -123.0f;
    self->slots[1].right = -74.0f;
    self->slots[1].top = -21.0f;
    self->slots[1].bottom = 88.0f;
    self->slots[1].a = 2;
    self->slots[1].c = 3;
    self->slots[1].d = 1;
    self->slots[1].e = 4;
    self->slots[1].x = str_803d6714;
    self->slots[1].y = 0;
    self->slots[1].z = str_803d6720;
    self->slots[1].h0 = 0;
    self->slots[1].h1 = 0;
    self->slots[1].h2 = 0;
    fn_8020bd38(&self->slots[1].tip, 0);
    self->slots[2].type = 1;
    fn_8020bd38(&self->slots[2].name, 0);
    self->slots[2].i8 = 3;
    self->slots[2].left = -167.0f;
    self->slots[2].right = -114.0f;
    self->slots[2].top = -122.0f;
    self->slots[2].bottom = -78.0f;
    self->slots[2].a = 1;
    self->slots[2].c = 12;
    self->slots[2].d = 3;
    self->slots[2].e = 6;
    self->slots[2].x = str_803d6730;
    self->slots[2].y = str_803d6740;
    self->slots[2].z = str_803d6750;
    self->slots[2].h0 = 0;
    self->slots[2].h1 = 0;
    self->slots[2].h2 = 0;
    fn_8020bd38(&self->slots[2].tip, str_803d6760);
    self->slots[3].type = 0;
    fn_8020bd38(&self->slots[3].name, str_803d6704);
    self->slots[3].i8 = 5;
    self->slots[3].left = -14.0f;
    self->slots[3].right = 24.0f;
    self->slots[3].top = 107.0f;
    self->slots[3].bottom = 136.0f;
    self->slots[3].a = 5;
    self->slots[3].c = 4;
    self->slots[3].d = 2;
    self->slots[3].e = 8;
    self->slots[3].x = str_803d6774;
    self->slots[3].y = str_803d6784;
    self->slots[3].z = str_803d6794;
    self->slots[3].h0 = 0;
    self->slots[3].h1 = 0;
    self->slots[3].h2 = 0;
    fn_8020bd38(&self->slots[3].tip, str_803d66f4);
    self->slots[4].type = 0;
    fn_8020bd38(&self->slots[4].name, str_803d6704);
    self->slots[4].i8 = 4;
    self->slots[4].left = -30.0f;
    self->slots[4].right = 42.0f;
    self->slots[4].top = -27.0f;
    self->slots[4].bottom = 93.0f;
    self->slots[4].a = 5;
    self->slots[4].c = 6;
    self->slots[4].d = 1;
    self->slots[4].e = 7;
    self->slots[4].x = str_803d67a4;
    self->slots[4].y = 0;
    self->slots[4].z = str_803d67b0;
    self->slots[4].h0 = 0;
    self->slots[4].h1 = 0;
    self->slots[4].h2 = 0;
    fn_8020bd38(&self->slots[4].tip, 0);
    self->slots[5].type = 1;
    fn_8020bd38(&self->slots[5].name, 0);
    self->slots[5].i8 = 6;
    self->slots[5].left = -57.0f;
    self->slots[5].right = 10.0f;
    self->slots[5].top = -130.0f;
    self->slots[5].bottom = -78.0f;
    self->slots[5].a = 4;
    self->slots[5].c = 12;
    self->slots[5].d = 3;
    self->slots[5].e = 9;
    self->slots[5].x = str_803d67c0;
    self->slots[5].y = str_803d67d0;
    self->slots[5].z = str_803d67e0;
    self->slots[5].h0 = 0;
    self->slots[5].h1 = 0;
    self->slots[5].h2 = 0;
    fn_8020bd38(&self->slots[5].tip, str_803d6760);
    self->slots[6].type = 0;
    fn_8020bd38(&self->slots[6].name, str_803d6704);
    self->slots[6].i8 = 8;
    self->slots[6].left = 85.0f;
    self->slots[6].right = 128.0f;
    self->slots[6].top = 112.0f;
    self->slots[6].bottom = 155.0f;
    self->slots[6].a = 8;
    self->slots[6].c = 7;
    self->slots[6].d = 5;
    self->slots[6].e = 10;
    self->slots[6].x = str_803d67f0;
    self->slots[6].y = str_803d6800;
    self->slots[6].z = str_803d6810;
    self->slots[6].h0 = 0;
    self->slots[6].h1 = 0;
    self->slots[6].h2 = 0;
    fn_8020bd38(&self->slots[6].tip, str_803d66f4);
    self->slots[7].type = 0;
    fn_8020bd38(&self->slots[7].name, str_803d6704);
    self->slots[7].i8 = 7;
    self->slots[7].left = 64.0f;
    self->slots[7].right = 155.0f;
    self->slots[7].top = -30.0f;
    self->slots[7].bottom = 95.0f;
    self->slots[7].a = 8;
    self->slots[7].c = 9;
    self->slots[7].d = 4;
    self->slots[7].e = 10;
    self->slots[7].x = str_803d6820;
    self->slots[7].y = 0;
    self->slots[7].z = str_803d682c;
    self->slots[7].h0 = 0;
    self->slots[7].h1 = 0;
    self->slots[7].h2 = 0;
    fn_8020bd38(&self->slots[7].tip, 0);
    self->slots[8].type = 1;
    fn_8020bd38(&self->slots[8].name, 0);
    self->slots[8].i8 = 9;
    self->slots[8].left = 71.0f;
    self->slots[8].right = 147.0f;
    self->slots[8].top = -158.0f;
    self->slots[8].bottom = -98.0f;
    self->slots[8].a = 7;
    self->slots[8].c = 12;
    self->slots[8].d = 6;
    self->slots[8].e = 10;
    self->slots[8].x = str_803d6840;
    self->slots[8].y = str_803d6850;
    self->slots[8].z = str_803d6860;
    self->slots[8].h0 = 0;
    self->slots[8].h1 = 0;
    self->slots[8].h2 = 0;
    fn_8020bd38(&self->slots[8].tip, str_803d6760);
    self->slots[9].type = 0;
    fn_8020bd38(&self->slots[9].name, str_803d6704);
    self->slots[9].i8 = 10;
    self->slots[9].left = 215.0f;
    self->slots[9].right = 281.0f;
    self->slots[9].top = 15.0f;
    self->slots[9].bottom = 73.0f;
    self->slots[9].a = 8;
    self->slots[9].c = 12;
    self->slots[9].d = 7;
    self->slots[9].e = 10;
    self->slots[9].x = str_803d6870;
    self->slots[9].y = str_803d687c;
    self->slots[9].z = str_803d688c;
    self->slots[9].h0 = 0;
    self->slots[9].h1 = 0;
    self->slots[9].h2 = 0;
    fn_8020bd38(&self->slots[9].tip, str_803d689c);
    self->slots[10].type = 0;
    fn_8020bd38(&self->slots[10].name, str_803d68ac);
    fn_802aaf5c(self, 0, 2);
    self->w1340 = 2;
    Ptr32<Root> root = scene_804b1788->root;
    if (root) {
        root->vt->bind(root, str_803d68c0, &self->w1356);
        scene_804b1788->root->vt->bind(scene_804b1788->root, str_803d68d4, &self->w1360);
        for (unsigned i = 0; i < 3; i++)
            scene_804b1788->root->vt->bind(scene_804b1788->root, str_803d68e0, &self->w1364[i]);
    }
    self->w240 = 1;
}


