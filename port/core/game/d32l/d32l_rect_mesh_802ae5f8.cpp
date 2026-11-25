#include "w3d_ptr.h"
#line 1 "d32l_rect_mesh_802ae5f8.cpp"
// GWMP8P rev0 0x802ae5f8. Rebuilds a bordered quad mesh: sixteen corner
// points from the half sizes and border width, expanded through the index
// table at 0x80403c0c into the locked vertex array, then the bounding box
// and sphere are refreshed. Twin of 0x8029358c without the inset.
struct Vec3 { float x, y, z; Vec3() {} void set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Box { Vec3 lo, hi; };
struct Sphere { Vec3 c; float r; };
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; unsigned count; unsigned short gen; char u30[2]; Vec3 data[1]; };
struct Arr { Ptr32<Hdr> h; };
extern "C" Ptr32<Vec3> fn_801ef048(Ptr32<Arr>, unsigned, int, int);
struct Mesh;
struct Geom;
struct Vtx;
struct Obj { Ptr32<ObjVt> vt; };
struct Held {
    Ptr32<Obj> p;
    template <class W3dU> Held(Ptr32<W3dU> w3d_p) : Held((Obj *)w3d_p.get()) {}
 Held(Obj *o) : p(o) { if (o) o->vt->retain(o); }
    Held(const Held &);
    ~Held() { if (p) p->vt->release(p); }
};
struct Vtx : Obj { char u4[16] __attribute__((aligned(__alignof__(Obj)))); Arr verts; };
struct Geom : Obj { char u4[16] __attribute__((aligned(__alignof__(Obj)))); Box box; char u44[36]; Ptr32<Vtx> vtx; void SetBox(const Box &b) { box = b; } };
struct Bound { char u0[4]; unsigned char flags; char w3d_tag_rest[3]; char u8[8]; Sphere sphere; char u32[4]; int zero; void Dirty() { flags &= ~1; } void SetSphere(const Sphere &o) { sphere = o; } };
struct Mesh : Obj { Bound bound __attribute__((aligned(__alignof__(Obj)))); char u44[4]; Ptr32<Geom> geom; };
struct Inst : Obj { char u4[28] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Mesh> mesh; };
struct Root : Obj { char u4[40] __attribute__((aligned(__alignof__(Obj)))); Ptr32<Inst> inst; };
extern "C" Ptr32<Root> fn_801750d4(Ptr32<void>);
extern "C" Ptr32<void> fn_801f55ec(Ptr32<Sphere>, Ptr32<const Box>);
inline const float &Min(const float &a, const float &b) { return b < a ? b : a; }

extern unsigned char lbl_80403c0c[];
inline Ptr32<Vec3> Lock(Ptr32<Arr> a, unsigned count) {
    Ptr32<Hdr> h = a->h;
    if (h->refs == 1) { h->gen++; return h->data; }
    return fn_801ef048(a, count, 12, 2);
}
inline bool Less(const unsigned &a, const unsigned &b) { return a < b; }
extern "C" void d32l_rect_mesh_802ae5f8(Ptr32<Ptr32<void>> source, float border, float w, float h) {
    if (w < border || h < border) {
        border = Min(w, h);
    }
    Held ra(fn_801750d4(*source));
    Held rb(((Ptr32<Root>)ra.p)->inst->mesh);
    Held rc(((Ptr32<Mesh>)rb.p)->geom);
    Held rd(((Ptr32<Geom>)rc.p)->vtx);
    Ptr32<Vtx> vtx = (Ptr32<Vtx>)rd.p;
    unsigned count = vtx->verts.h->count;
    Ptr32<Vec3> out = Lock(&vtx->verts, count);
    Vec3 v[16];
    for (int i = 0; i < 4; i++) {
        v[i].y = h;
        v[i + 4].y = h - border;
        v[i + 8].y = border - h;
        v[i + 12].y = -h;
    }
    for (int i = 0; i < 4; i++) {
        v[i * 4].x = -w;
        v[i * 4 + 1].x = border - w;
        v[i * 4 + 2].x = w - border;
        v[i * 4 + 3].x = w;
    }
    for (unsigned i = 0; Less(i, count); i++) {
        *out = v[lbl_80403c0c[i]];
        out->z = 0.0f;
        out++;
    }
    ((Ptr32<Mesh>)rb.p)->bound.Dirty();
    int none = 0;
    float bw = w, bh = h;
    Box box;
    box.lo.set(-bw, -bh, 0.0f);
    box.hi.set(bw, bh, 0.0f);
    Sphere s;
    fn_801f55ec(&s, &box);
    ((Ptr32<Geom>)rc.p)->SetBox(box);
    ((Ptr32<Mesh>)rb.p)->bound.SetSphere(s);
    ((Ptr32<Mesh>)rb.p)->bound.zero = none;
}


