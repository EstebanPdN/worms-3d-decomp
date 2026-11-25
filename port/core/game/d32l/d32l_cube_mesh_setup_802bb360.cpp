#include "w3d_ptr.h"
#line 1 "d32l_cube_mesh_setup_802bb360.cpp"
// GWMP8P rev0 0x802bb360. Builds a 54-vertex textured cube for a menu
// object: creates buffers through the type service, writes indices, pixel
// UVs scaled by 1/128 and white colours, binds the geometry to a mesh,
// copies the material from the named source and attaches the mesh to the
// object.
struct Obj;
struct Named { char u[48]; Ptr32<const char> name; };
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; Ptr32<void> u20[11]; Ptr32<Ptr32<void> (Ptr32<Obj>)> named; Ptr32<void> u68[2]; Ptr32<int (Ptr32<Obj>)> index; };
struct Obj { Ptr32<ObjVt> vt; };
template <class T> struct Ref {
    Ptr32<T> p;
    template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *o) : p(o) { if (o) o->vt->retain(o); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    Ptr32<T> operator->() const { return p; }
    Ref &operator=(const Ref &o) {
        return *this;
    }
};
template <class T> inline void Assign(Ptr32<T> &slot, T *o) {
    Ptr32<T> old = slot;
    slot = o;
    if (o) o->vt->retain(o);
    if (old) old->vt->release(old);
}
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; unsigned count; unsigned short gen; char u30[2]; int data[1]; };
struct Arr { Ptr32<Hdr> h; };
extern "C" Ptr32<void> fn_801ef048(Ptr32<Arr>, unsigned, int, int);
inline Ptr32<void> Lock(Ptr32<Arr> a, unsigned count, int size) {
    Ptr32<Hdr> h = a->h;
    if (h->refs == 1 && h->count == count) { h->gen++; return h->data; }
    return fn_801ef048(a, count, size, 0);
}
struct Vec2 { float x, y; };
struct Rgba { signed char r, g, b, a; };
struct Buf : Obj { char u4[16] __attribute__((aligned(__alignof__(Obj)))); Arr a20; };
struct Idx : Obj { char u4[20] __attribute__((aligned(__alignof__(Obj)))); Arr a24; };
struct Geom : Obj { char u4[64] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Buf> b68; Ptr32<Buf> b72; char u76[4]; Ptr32<Buf> b80; int prim; char u88[4]; Ptr32<Idx> idx; };
struct Mat : Obj { char u4[24] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Hdr> list; };
struct Mesh : Obj { char u4[44] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Geom> geom; Ptr32<Mat> mat; };
struct Str;
extern "C" Ptr32<Obj> fn_8020b680(Ptr32<void>);
extern "C" void fn_8020c5c4(Ptr32<Str>);
extern "C" void fn_80341588(Ptr32<Str>);
extern "C" Ptr32<Obj> fn_80343808(int);
extern "C" Ptr32<Named> fn_8034bf48(Ptr32<void>);
#define cast_name fn_8034bf48
struct Mat;
struct Item { char u[52]; Ptr32<Mat> mat; };
struct Src : Obj {};
extern "C" Ptr32<Item> fn_80172050(Ptr32<Src>, int);
extern "C" Ptr32<int> fn_801d0858(Ptr32<Mat>, Ptr32<int>);
extern "C" void fn_801d0898(Ptr32<Mat>, int, int);
extern "C" void fn_801d086c(Ptr32<Mat>, int);
extern "C" void fn_801ef174(Ptr32<Obj>, int, int, Ptr32<void>);
extern "C" Ptr32<Obj> fn_801750d4(Ptr32<void>);
extern char lbl_80414518[], lbl_80414870[], lbl_80414830[], lbl_80414780[], lbl_804146e0[], lbl_804148d0[], lbl_80415b00[];
struct Str2 { int w; template <class W3dU> Str2(Ptr32<W3dU> w3d_p) : Str2((const char *)w3d_p.get()) {}
 Str2(const char *); Str2(const Str2 &); ~Str2() { Ptr32<Str2> t = this; fn_8020c5c4((Ptr32<Str>)t); fn_80341588((Ptr32<Str>)t); } };
extern "C" int fn_8015ae3c(const Str2 &);
extern "C" int d32l_cube_mesh_setup_802bb360(Ptr32<Obj> self) {
    Ref<Mesh> mesh((Ptr32<Mesh>)fn_8020b680(lbl_80414518));
    Ref<Buf> uvb((Ptr32<Buf>)fn_8020b680(lbl_80414870));
    Ref<Buf> colb((Ptr32<Buf>)fn_8020b680(lbl_80414830));
    Ref<Buf> posb((Ptr32<Buf>)fn_8020b680(lbl_80414780));
    Ref<Geom> geom((Ptr32<Geom>)fn_8020b680(lbl_804146e0));
    Ref<Idx> idx((Ptr32<Idx>)fn_8020b680(lbl_804148d0));
    Ptr32<unsigned short> ip = (Ptr32<unsigned short>)Lock(&idx->a24, 54, 2);
    for (unsigned i = 0; i < 54; i++) ip[i] = i;
    Assign(geom->idx, w3d::R(idx.p));
    Lock(&posb->a20, 54, 12);
    Ptr32<Vec2> uv = (Ptr32<Vec2>)Lock(&uvb->a20, 54, 8);
    Ptr32<Rgba> col = (Ptr32<Rgba>)Lock(&colb->a20, 54, 4);
    uv[0].x = 85.0f; uv[0].y = 5.0f;
    uv[1].x = 108.0f; uv[1].y = 5.0f;
    uv[2].x = 108.0f; uv[2].y = 28.0f;
    uv[3].x = 85.0f; uv[3].y = 5.0f;
    uv[4].x = 108.0f; uv[4].y = 28.0f;
    uv[5].x = 85.0f; uv[5].y = 28.0f;
    uv[6].x = 109.0f; uv[6].y = 5.0f;
    uv[7].x = 110.0f; uv[7].y = 5.0f;
    uv[8].x = 110.0f; uv[8].y = 28.0f;
    uv[9].x = 109.0f; uv[9].y = 5.0f;
    uv[10].x = 110.0f; uv[10].y = 28.0f;
    uv[11].x = 109.0f; uv[11].y = 28.0f;
    uv[12].x = 108.0f; uv[12].y = 5.0f;
    uv[13].x = 85.0f; uv[13].y = 5.0f;
    uv[14].x = 85.0f; uv[14].y = 28.0f;
    uv[15].x = 108.0f; uv[15].y = 5.0f;
    uv[16].x = 85.0f; uv[16].y = 28.0f;
    uv[17].x = 108.0f; uv[17].y = 28.0f;
    uv[18].x = 85.0f; uv[18].y = 29.0f;
    uv[19].x = 108.0f; uv[19].y = 29.0f;
    uv[20].x = 108.0f; uv[20].y = 30.0f;
    uv[21].x = 85.0f; uv[21].y = 29.0f;
    uv[22].x = 108.0f; uv[22].y = 30.0f;
    uv[23].x = 85.0f; uv[23].y = 30.0f;
    uv[24].x = 108.0f; uv[24].y = 29.0f;
    uv[25].x = 85.0f; uv[25].y = 29.0f;
    uv[26].x = 85.0f; uv[26].y = 30.0f;
    uv[27].x = 108.0f; uv[27].y = 29.0f;
    uv[28].x = 85.0f; uv[28].y = 30.0f;
    uv[29].x = 108.0f; uv[29].y = 30.0f;
    uv[30].x = 85.0f; uv[30].y = 28.0f;
    uv[31].x = 108.0f; uv[31].y = 28.0f;
    uv[32].x = 108.0f; uv[32].y = 5.0f;
    uv[33].x = 85.0f; uv[33].y = 28.0f;
    uv[34].x = 108.0f; uv[34].y = 5.0f;
    uv[35].x = 85.0f; uv[35].y = 5.0f;
    uv[36].x = 109.0f; uv[36].y = 28.0f;
    uv[37].x = 110.0f; uv[37].y = 28.0f;
    uv[38].x = 110.0f; uv[38].y = 5.0f;
    uv[39].x = 109.0f; uv[39].y = 28.0f;
    uv[40].x = 110.0f; uv[40].y = 5.0f;
    uv[41].x = 109.0f; uv[41].y = 5.0f;
    uv[42].x = 108.0f; uv[42].y = 28.0f;
    uv[43].x = 85.0f; uv[43].y = 28.0f;
    uv[44].x = 85.0f; uv[44].y = 5.0f;
    uv[45].x = 108.0f; uv[45].y = 28.0f;
    uv[46].x = 85.0f; uv[46].y = 5.0f;
    uv[47].x = 108.0f; uv[47].y = 5.0f;
    uv[48].x = 99.0f; uv[48].y = 19.0f;
    uv[49].x = 100.0f; uv[49].y = 19.0f;
    uv[50].x = 100.0f; uv[50].y = 20.0f;
    uv[51].x = 99.0f; uv[51].y = 19.0f;
    uv[52].x = 100.0f; uv[52].y = 20.0f;
    uv[53].x = 99.0f; uv[53].y = 20.0f;
    Ptr32<Rgba> c = col;
    Ptr32<Vec2> q = uv;
    for (unsigned i = 0; i < 54; i++) {
        q->x *= 0.0078125f;
        q->y = 1.0f - q->y * 0.0078125f;
        c->r = -1;
        c->g = -1;
        c->b = -1;
        c->a = -1;
        q++;
        c++;
    }
    geom->prim = 18;
    Assign(geom->b80, w3d::R(posb.p));
    Assign(geom->b68, w3d::R(uvb.p));
    Assign(geom->b72, w3d::R(colb.p));
    Ptr32<Named> nm = cast_name(self->vt->named(self));
    Ref<Src> src((Ptr32<Src>)fn_80343808(fn_8015ae3c(Str2(nm->name))));
    Ptr32<Src> sp = src.p;
    Ptr32<Item> it = fn_80172050(sp, sp->vt->index(sp));
    Ref<Mat> a(it->mat);
    Ref<Mat> b((Ptr32<Mat>)fn_8020b680(lbl_80415b00));
    Ptr32<Mat> bp = b.p;
    int v = 0;
    int n;
    Ptr32<int> t = fn_801d0858(a.p, &n);
    if (n) v = *t;
    int m;
    fn_801d0858(bp, &m);
    if (m) fn_801d0898(bp, v, 0);
    else fn_801d086c(bp, v);
    Ptr32<Hdr> l = a->list;
    unsigned cnt = l->count;
    Ptr32<int> lp = l->data;
    for (unsigned i = 0; i < cnt; i++) fn_801ef174(b.p, 28, 3, (Ptr32<void>)w3d::G(lp[i]));
    Assign(mesh->geom, w3d::R(geom.p));
    Assign(mesh->mat, w3d::R(b.p));
    Ref<Obj> root(fn_801750d4(self));
    fn_801ef174(root.p, 44, 3, mesh.p);
    return 0;
}


