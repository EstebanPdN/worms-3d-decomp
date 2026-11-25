#include "w3d_ptr.h"
#line 1 "d30k_cube_mesh_build_8025e56c.cpp"
// GWMP8P rev0 0x8025e56c. Builds a textured 48-vertex cube mesh: creates the
// geometry objects through 0x8020b680, fills the indices, the 48 texture
// coordinates (a 128-pixel atlas, scaled and flipped) and white colours,
// then attaches the objects and the shared shader state. Names and layouts
// are partial views inferred from use. Owns the float literals at
// 0x803caa88.
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; Ptr32<void> u20[11]; Ptr32<void (Ptr32<Obj>)> touch; Ptr32<void> u68[2]; Ptr32<int (Ptr32<Obj>)> index; };
struct Hdr { char u0[4]; unsigned short refs; char u6[18]; int count; unsigned short gen; char u30[2]; char data[1]; };
struct Arr { Ptr32<Hdr> h; };
extern "C" Ptr32<void> fn_801ef048(Ptr32<Arr>, int, int, int);
inline Ptr32<void> Lock(Ptr32<Arr> a, int count, int size, int flag) {
 Ptr32<Hdr> h = a->h;
 if (h->refs == 1 && h->count == count) { h->gen++; return h->data; }
 return fn_801ef048(a, count, size, flag);
}
struct Uv { float x, y; void set(float a, float b) { x = a; y = b; } };
struct List { char u[24]; unsigned n; char u28[4]; Ptr32<Obj> items[1]; };
struct Obj { Ptr32<ObjVt> vt; char u4[16]; Arr a20; Arr a24; Ptr32<List> list; char u32[16]; Ptr32<Obj> f48; Ptr32<Obj> f52; char u56[12]; Ptr32<Obj> f68; Ptr32<Obj> f72; char u76[4]; Ptr32<Obj> f80; int f84; char u88[4]; Ptr32<Obj> f92; };
struct Str { Ptr32<char> p; template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *); Str(const Str &); ~Str(); };
extern "C" void fn_8020c5c4(Ptr32<Str>);
extern "C" void fn_80341588(Ptr32<Str>);
inline Str::~Str() { fn_8020c5c4(this); fn_80341588(this); }
struct Ref {
 Ptr32<Obj> p;
 template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->release(p); }
 Ptr32<Obj> operator->() const { return p; }
};
inline void Set(Ptr32<Obj> &f, Ptr32<Obj> q) { Ptr32<Obj> old = f; f = q; if (q) q->vt->retain(q); if (old) old->vt->release(old); }
struct Holder { char u[48]; Ptr32<const char> name; };
extern "C" Ptr32<Obj> fn_8020b680(Ptr32<void>);
extern "C" Ptr32<Holder> fn_8034bf48();
extern "C" Ptr32<void> fn_8015ae3c(const Str &);
extern "C" Ptr32<Obj> fn_80343808(Ptr32<void>);
extern "C" Ptr32<Obj> fn_80172050(Ptr32<Obj>, int);
extern "C" Ptr32<void> fn_801d0858(Ptr32<Obj>, Ptr32<int>);
extern "C" void fn_801d0898(Ptr32<Obj>, Ptr32<void>, int);
extern "C" void fn_801d086c(Ptr32<Obj>, Ptr32<void>);
extern "C" void fn_801ef174(Ptr32<Obj>, int, int, Ptr32<Obj>);
extern "C" Ptr32<Obj> fn_801750d4(Ptr32<Obj>);
extern char lbl_80414518[], lbl_80414870[], lbl_80414830[], lbl_80414780[], lbl_804146e0[], lbl_804148d0[], lbl_80415b00[];
extern "C" int w3d_d30k_cube_mesh_build_8025e56c(Ptr32<Obj> self) {
 Ref a8(fn_8020b680(lbl_80414518));
 Ref a16(fn_8020b680(lbl_80414870));
 Ref a24(fn_8020b680(lbl_80414830));
 Ref a32(fn_8020b680(lbl_80414780));
 Ref a40(fn_8020b680(lbl_804146e0));
 Ref a48(fn_8020b680(lbl_804148d0));
 Ptr32<short> idx = (Ptr32<short>)Lock(&a48->a24, 48, 2, 0);
 for (unsigned i = 0; i < 48; i++) idx[i] = i;
 Set(a40->f92, a48.p);
 Lock(&a32->a20, 48, 12, 0);
 Ptr32<Uv> uv = (Ptr32<Uv>)Lock(&a16->a20, 48, 8, 0);
 Ptr32<char> col = (Ptr32<char>)Lock(&a24->a20, 48, 4, 0);
 uv[0].x = 1.0f; uv[0].y = 1.0f;
 uv[1].x = 23.0f; uv[1].y = 1.0f;
 uv[2].x = 23.0f; uv[2].y = 23.0f;
 uv[3].x = 1.0f; uv[3].y = 1.0f;
 uv[4].x = 23.0f; uv[4].y = 23.0f;
 uv[5].x = 1.0f; uv[5].y = 23.0f;
 uv[6].x = 2.0f; uv[6].y = 59.0f;
 uv[7].x = 62.0f; uv[7].y = 59.0f;
 uv[8].x = 62.0f; uv[8].y = 81.0f;
 uv[9].x = 2.0f; uv[9].y = 59.0f;
 uv[10].x = 62.0f; uv[10].y = 81.0f;
 uv[11].x = 2.0f; uv[11].y = 81.0f;
 uv[12].x = 25.0f; uv[12].y = 1.0f;
 uv[13].x = 47.0f; uv[13].y = 1.0f;
 uv[14].x = 47.0f; uv[14].y = 23.0f;
 uv[15].x = 25.0f; uv[15].y = 1.0f;
 uv[16].x = 47.0f; uv[16].y = 23.0f;
 uv[17].x = 25.0f; uv[17].y = 23.0f;
 uv[18].x = 64.0f; uv[18].y = 18.0f;
 uv[19].x = 86.0f; uv[19].y = 18.0f;
 uv[20].x = 86.0f; uv[20].y = 78.0f;
 uv[21].x = 64.0f; uv[21].y = 18.0f;
 uv[22].x = 86.0f; uv[22].y = 78.0f;
 uv[23].x = 64.0f; uv[23].y = 78.0f;
 uv[24].x = 64.0f; uv[24].y = 78.0f;
 uv[25].x = 86.0f; uv[25].y = 78.0f;
 uv[26].x = 86.0f; uv[26].y = 18.0f;
 uv[27].x = 64.0f; uv[27].y = 78.0f;
 uv[28].x = 86.0f; uv[28].y = 18.0f;
 uv[29].x = 64.0f; uv[29].y = 18.0f;
 uv[30].x = 1.0f; uv[30].y = 25.0f;
 uv[31].x = 23.0f; uv[31].y = 25.0f;
 uv[32].x = 23.0f; uv[32].y = 47.0f;
 uv[33].x = 1.0f; uv[33].y = 25.0f;
 uv[34].x = 23.0f; uv[34].y = 47.0f;
 uv[35].x = 1.0f; uv[35].y = 47.0f;
 uv[36].x = 62.0f; uv[36].y = 59.0f;
 uv[37].x = 2.0f; uv[37].y = 59.0f;
 uv[38].x = 2.0f; uv[38].y = 81.0f;
 uv[39].x = 62.0f; uv[39].y = 59.0f;
 uv[40].x = 2.0f; uv[40].y = 81.0f;
 uv[41].x = 62.0f; uv[41].y = 81.0f;
 uv[42].x = 25.0f; uv[42].y = 25.0f;
 uv[43].x = 47.0f; uv[43].y = 25.0f;
 uv[44].x = 47.0f; uv[44].y = 47.0f;
 uv[45].x = 25.0f; uv[45].y = 25.0f;
 uv[46].x = 47.0f; uv[46].y = 47.0f;
 uv[47].x = 25.0f; uv[47].y = 47.0f;
 for (int i = 0; i < 48; i++) {
  uv[i].x = uv[i].x * 0.0078125f;
  uv[i].y = 1.0f - uv[i].y * 0.0078125f;
  col[i*4] = -1; col[i*4+1] = -1; col[i*4+2] = -1; col[i*4+3] = -1;
 }
 a40->f84 = 16;
 Set(a40->f80, a32.p);
 Set(a40->f68, a16.p);
 Set(a40->f72, a24.p);
 self->vt->touch(self);
 Ref a56(fn_80343808(fn_8015ae3c(Str(fn_8034bf48()->name))));
 Ref a64(fn_80172050(a56.p, a56->vt->index(a56.p))->f52);
 Ref a72(fn_8020b680(lbl_80415b00));
 {
  Ptr32<Obj> o = a72.p;
  int f88, f92;
  Ptr32<void> v = 0;
  Ptr32<void> r = fn_801d0858(a64.p, &f88);
  if (f88) v = *(Ptr32<Ptr32<void>>)r;
  fn_801d0858(o, &f92);
  if (f92) fn_801d0898(o, v, 0);
  else fn_801d086c(o, v);
 }
 {
  Ptr32<List> l = a64->list;
  unsigned n = l->n;
  Ptr32<Ptr32<Obj>> b = l->items;
  for (unsigned i = 0; i < n; i++) fn_801ef174(a72.p, 28, 3, b[i]);
 }
 Set(a8->f48, a40.p);
 Set(a8->f52, a72.p);
 Ref a80(fn_801750d4(self));
 fn_801ef174(a80.p, 44, 3, a8.p);
 return 0;
}


