// GWMP8P rev0 0x802aea3c. Builds a 48-vertex textured mesh for a menu
// object: creates buffers through the type service, writes pixel UVs scaled
// by 1/64 and white colours, binds the geometry to a mesh, copies the
// material from the named source and attaches the mesh to the object.
// Sibling of 0x802bb360 without an index buffer.
struct Obj;
struct Named { char u[48]; const char *name; };
struct ObjVt { void *u[3]; void (*retain)(Obj *); void (*release)(Obj *); void *u20[11]; void *(*named)(Obj *); void *u68[2]; int (*index)(Obj *); };
struct Obj { ObjVt *vt; };
template <class T> struct Ref {
    T *p;
    Ref(T *o) : p(o) { if (o) o->vt->retain(o); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    T *operator->() const { return p; }
    Ref &operator=(const Ref &o) {
        return *this;
    }
};
template <class T> inline void Assign(T *&slot, T *o) {
    T *old = slot;
    slot = o;
    if (o) o->vt->retain(o);
    if (old) old->vt->release(old);
}
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; unsigned count; unsigned short gen; char u30[2]; int data[1]; };
struct Arr { Hdr *h; };
extern "C" void *fn_801ef048(Arr *, unsigned, int, int);
inline void *Lock(Arr *a, unsigned count, int size) {
    Hdr *h = a->h;
    if (h->refs == 1 && h->count == count) { h->gen++; return h->data; }
    return fn_801ef048(a, count, size, 0);
}
struct Vec2 { float x, y; };
struct Rgba { signed char r, g, b, a; };
struct Buf : Obj { char u4[16]; Arr a20; };
struct Idx : Obj { char u4[20]; Arr a24; };
struct Geom : Obj { char u4[64]; Buf *b68; Buf *b72; char u76[4]; Buf *b80; int prim; char u88[4]; Idx *idx; };
struct Mat : Obj { char u4[24]; Hdr *list; };
struct Mesh : Obj { char u4[44]; Geom *geom; Mat *mat; };
struct Str;
extern "C" Obj *fn_8020b680(void *);
extern "C" void fn_8020c5c4(Str *);
extern "C" void fn_80341588(Str *);
extern "C" Obj *fn_80343808(int);
extern "C" Named *fn_8034bf48(void *);
#define cast_name fn_8034bf48
struct Mat;
struct Item { char u[52]; Mat *mat; };
struct Src : Obj {};
extern "C" Item *fn_80172050(Src *, int);
extern "C" int *fn_801d0858(Mat *, int *);
extern "C" void fn_801d0898(Mat *, int, int);
extern "C" void fn_801d086c(Mat *, int);
extern "C" void fn_801ef174(Obj *, int, int, void *);
extern "C" Obj *fn_801750d4(void *);
extern char lbl_80414518[], lbl_80414870[], lbl_80414830[], lbl_80414780[], lbl_80414660[], lbl_80415b00[];
struct Str2 { int w; Str2(const char *); Str2(const Str2 &); ~Str2() { Str2 *t = this; fn_8020c5c4((Str *)t); fn_80341588((Str *)t); } };
extern "C" int fn_8015ae3c(const Str2 &);
extern "C" int d32l_cube_mesh_setup_b_802aea3c(Obj *self) {
    Ref<Mesh> mesh((Mesh *)fn_8020b680(lbl_80414518));
    Ref<Buf> uvb((Buf *)fn_8020b680(lbl_80414870));
    Ref<Buf> colb((Buf *)fn_8020b680(lbl_80414830));
    Ref<Buf> posb((Buf *)fn_8020b680(lbl_80414780));
    Ref<Geom> geom((Geom *)fn_8020b680(lbl_80414660));
    Lock(&posb->a20, 48, 12);
    Vec2 *uv = (Vec2 *)Lock(&uvb->a20, 48, 8);
    Rgba *col = (Rgba *)Lock(&colb->a20, 48, 4);
    uv[0].x = 3.0f; uv[0].y = 3.0f;
    uv[1].x = 27.0f; uv[1].y = 3.0f;
    uv[2].x = 27.0f; uv[2].y = 27.0f;
    uv[3].x = 3.0f; uv[3].y = 3.0f;
    uv[4].x = 27.0f; uv[4].y = 27.0f;
    uv[5].x = 3.0f; uv[5].y = 27.0f;
    uv[6].x = 59.0f; uv[6].y = 37.0f;
    uv[7].x = 60.0f; uv[7].y = 37.0f;
    uv[8].x = 60.0f; uv[8].y = 61.0f;
    uv[9].x = 59.0f; uv[9].y = 37.0f;
    uv[10].x = 60.0f; uv[10].y = 61.0f;
    uv[11].x = 59.0f; uv[11].y = 61.0f;
    uv[12].x = 27.0f; uv[12].y = 3.0f;
    uv[13].x = 51.0f; uv[13].y = 3.0f;
    uv[14].x = 51.0f; uv[14].y = 27.0f;
    uv[15].x = 27.0f; uv[15].y = 3.0f;
    uv[16].x = 51.0f; uv[16].y = 27.0f;
    uv[17].x = 27.0f; uv[17].y = 27.0f;
    uv[18].x = 59.0f; uv[18].y = 37.0f;
    uv[19].x = 59.0f; uv[19].y = 61.0f;
    uv[20].x = 60.0f; uv[20].y = 61.0f;
    uv[21].x = 59.0f; uv[21].y = 37.0f;
    uv[22].x = 60.0f; uv[22].y = 61.0f;
    uv[23].x = 60.0f; uv[23].y = 37.0f;
    uv[24].x = 59.0f; uv[24].y = 37.0f;
    uv[25].x = 59.0f; uv[25].y = 61.0f;
    uv[26].x = 60.0f; uv[26].y = 61.0f;
    uv[27].x = 59.0f; uv[27].y = 37.0f;
    uv[28].x = 60.0f; uv[28].y = 61.0f;
    uv[29].x = 60.0f; uv[29].y = 37.0f;
    uv[30].x = 3.0f; uv[30].y = 27.0f;
    uv[31].x = 27.0f; uv[31].y = 27.0f;
    uv[32].x = 27.0f; uv[32].y = 51.0f;
    uv[33].x = 3.0f; uv[33].y = 27.0f;
    uv[34].x = 27.0f; uv[34].y = 51.0f;
    uv[35].x = 3.0f; uv[35].y = 51.0f;
    uv[36].x = 59.0f; uv[36].y = 37.0f;
    uv[37].x = 60.0f; uv[37].y = 37.0f;
    uv[38].x = 60.0f; uv[38].y = 61.0f;
    uv[39].x = 59.0f; uv[39].y = 37.0f;
    uv[40].x = 60.0f; uv[40].y = 61.0f;
    uv[41].x = 59.0f; uv[41].y = 61.0f;
    uv[42].x = 27.0f; uv[42].y = 27.0f;
    uv[43].x = 51.0f; uv[43].y = 27.0f;
    uv[44].x = 51.0f; uv[44].y = 51.0f;
    uv[45].x = 27.0f; uv[45].y = 27.0f;
    uv[46].x = 51.0f; uv[46].y = 51.0f;
    uv[47].x = 27.0f; uv[47].y = 51.0f;
    Rgba *c = col;
    Vec2 *q = uv;
    for (unsigned i = 0; i < 48; i++) {
        q->x *= 0.015625f;
        q->y = 1.0f - q->y * 0.015625f;
        c->r = -1;
        c->g = -1;
        c->b = -1;
        c->a = -1;
        q++;
        c++;
    }
    geom->prim = 16;
    Assign(geom->b80, posb.p);
    Assign(geom->b68, uvb.p);
    Assign(geom->b72, colb.p);
    Named *nm = cast_name(self->vt->named(self));
    Ref<Src> src((Src *)fn_80343808(fn_8015ae3c(Str2(nm->name))));
    Src *sp = src.p;
    Item *it = fn_80172050(sp, sp->vt->index(sp));
    Ref<Mat> a(it->mat);
    Ref<Mat> b((Mat *)fn_8020b680(lbl_80415b00));
    Mat *bp = b.p;
    int v = 0;
    int n;
    int *t = fn_801d0858(a.p, &n);
    if (n) v = *t;
    int m;
    fn_801d0858(bp, &m);
    if (m) fn_801d0898(bp, v, 0);
    else fn_801d086c(bp, v);
    Hdr *l = a->list;
    unsigned cnt = l->count;
    int *lp = l->data;
    for (unsigned i = 0; i < cnt; i++) fn_801ef174(b.p, 28, 3, (void *)lp[i]);
    Assign(mesh->geom, geom.p);
    Assign(mesh->mat, b.p);
    Ref<Obj> root(fn_801750d4(self));
    fn_801ef174(root.p, 44, 3, mesh.p);
    return 0;
}
