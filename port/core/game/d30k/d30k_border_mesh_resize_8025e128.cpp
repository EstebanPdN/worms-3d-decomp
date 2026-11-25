#include "w3d_ptr.h"
#line 1 "d30k_border_mesh_resize_8025e128.cpp"
// GWMP8P rev0 0x8025e128. Lays out a nine-patch border mesh: clamps the
// corner size to the smaller half extent, builds the 16 grid corners, writes
// the triangle vertices from the index table at 0x804012c0, and updates the
// bounding box and sphere. Names are inferred from use. Built with -mps-
// float: frame gap only without it.
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; unsigned count; unsigned short gen; char u30[2]; char data[1]; };
extern "C" Ptr32<void> fn_801ef048(Ptr32<void>, unsigned, int, int);
struct Vec { float x, y, z; Vec() {} void Set(float a, float b, float c) { Ptr32<Vec> p = this; x = a; y = b; p->z = c; } };
struct Box { Vec min, max; Box() {} Box(float a,float b,float c,float d,float e,float f){ min.Set(a,b,c); max.Set(d,e,f);} };
struct Sphere { float v[4]; };
struct Arr { Ptr32<Hdr> h; };
struct Mark { char u[4]; unsigned char f; char w3d_tag_rest[3]; void Clear() { f &= 0xfe; } };
struct Obj { Ptr32<ObjVt> vt; Mark mark; char u12[8]; Arr a20; Box &box() { return *(Ptr32<Box>)&a20; } Sphere &sphere() { return *(Ptr32<Sphere>)&a20; } };
struct Obj2 { char u[40]; int f40; void Set40(int v) { f40 = v; } };
struct Obj3 { char u[32]; Ptr32<Obj> f32; char u36[8]; Ptr32<Obj3> f44; Ptr32<Obj> f48; char u52[28]; Ptr32<Obj> f80; };
struct Ref {
 Ptr32<Obj> p;
 template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->release(p); }
 Ptr32<Obj> operator->() const { return p; }
 Ptr32<Obj3> x() const { return (Ptr32<Obj3>)p; }
};
struct Owner { Ptr32<Obj> o; };
extern "C" Ptr32<Obj> fn_801750d4(Ptr32<Obj>);
extern "C" Ptr32<void> fn_801f55ec(Ptr32<Sphere>, Ptr32<Box>);
extern const unsigned char lbl_804012c0[];
inline unsigned Id(const unsigned &v) { return v; }
inline const float &Min(const float &a, const float &b) { return b < a ? b : a; }
inline void Put(Box &d, const Box &v) { d = v; }
inline void Put(Sphere &d, const Sphere &v) { d = v; }
extern "C" void w3d_d30k_border_mesh_resize_8025e128(Ptr32<Owner> self, float r, float a, float b) {
 if (a < r || b < r) r = Min(a, b);
 Ref o(fn_801750d4(self->o));
 Ref m(o.x()->f44->f32);
 Ref g(m.x()->f48);
 Ref e(g.x()->f80);
 Ptr32<Arr> arr = &e->a20;
 Ptr32<Hdr> h = arr->h; unsigned n = h->count; Ptr32<Vec> q; if (h->refs == 1) { h->gen++; q = (Ptr32<Vec>)h->data; } else q = (Ptr32<Vec>)fn_801ef048(arr, n, 12, 2);
 Vec v[16];
 for (unsigned i = 0; i < 4; i++) { v[i].y = b; v[i + 4].y = b - r; v[i + 8].y = r - b; v[i + 12].y = -b; }
 for (unsigned i = 0; i < 4; i++) { v[i * 4].x = -a; v[i * 4 + 1].x = r - a; v[i * 4 + 2].x = a - r; v[i * 4 + 3].x = a; }
 for (unsigned i = 0; i < Id(n); i++) { *q = v[lbl_804012c0[i]]; q->z = 0.0f; q++; }
 m->mark.Clear();
 int z = 0;
 Box box(-a, -b, 0.0f, a, b, 0.0f); Sphere s;
 fn_801f55ec(&s, &box);
 Put(g->box(), box);
 Put(m->sphere(), s);
 ((Ptr32<Obj2>)m.p)->Set40(z);
}


