#include "w3d_ptr.h"
#line 1 "d40j_material_add_key_801720fc.cpp"
// Material set (Worms 3D GameCube PAL, 0x801720fc): returns the index of a key in
// the set's key array or, for a new key, builds a material with its two mesh
// parts, adds them to the two compact slot arrays, appends the key and an empty
// entry, wires the parts under the object for that key, picks the shader type
// from the set's flags, and resets the parts' bounds to a sphere of radius 5e10 and its box.
// Names are inferred.
#include "compat/stlport_sn_oom.h"
#include <vector>
extern "C" {
Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
void w3d_k5b_iface_array_field_append_801ef174(Ptr32<void>, int, int, Ptr32<void>);
Ptr32<void> malloc(unsigned);
void w3d_handle_storage_release(Ptr32<void>);
Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned int, ...);
void w3d_string_free_8020bb2c(Ptr32<void>);
}
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  Ref() : p(0) {}
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((T *)w3d_p.get()); }
 Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
  Ptr32<T> start; Ptr32<T> finish; Ptr32<T> storage_end;
  void grow() {
    unsigned int used = (Ptr32<char>)finish - (Ptr32<char>)start;
    int a = used + 1, b = used + (used >> 1);
    unsigned int bytes = Max(a, b);
    Ptr32<T> p = (Ptr32<T>)malloc(bytes);
    if (start) {
      memcpy_802eee50(p, start, Min(bytes, used));
      w3d_handle_storage_release(start);
    }
    start = p; finish = (Ptr32<T>)((Ptr32<char>)p + used); storage_end = (Ptr32<T>)((Ptr32<char>)p + bytes);
  }
  void push_back(const T &v) {
    if (finish == storage_end) grow();
    *finish = v;
    finish++;
  }
};
struct Entry {
  Ptr32<char> start; Ptr32<char> finish; Ptr32<char> storage_end; int tag;
  Entry() { storage_end = 0; finish = 0; start = 0; tag = 0; }
  Entry(const Entry &o) {
    unsigned n = o.finish - o.start;
    Ptr32<char> p = (Ptr32<char>)malloc(n);
    start = p; finish = p + n; storage_end = p + n;
    memcpy_802eee50(p, o.start, n);
    tag = o.tag;
  }
  ~Entry() { if (start) w3d_handle_storage_release(start); }
  Entry &operator=(const Entry &);
};
struct Defs { std::vector<Entry> items; Array<unsigned char> names; };
struct SlotsA { unsigned n; int cap; Ptr32<Ptr32<Iface>> d; };
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(Ptr32<SlotsA>, unsigned);
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) { x = o.x; y = o.y; z = o.z; }
  void Set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Sphere { float x, y, z, w; Sphere() {} void Set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Box { int w[6]; };
extern "C" void box_from_sphere_801f5724(Ptr32<Box>, Ptr32<const Sphere>);
struct String { Ptr32<char> p;
  String &operator=(const String &o) { ++*(Ptr32<unsigned short>)(o.p - 6); Ptr32<char> old = p; Ptr32<void> h = old - 6; unsigned short c = --*(Ptr32<unsigned short>)(old - 6); if (c == 0) w3d_string_free_8020bb2c(h); p = o.p; return *this; } };
struct Mesh : Iface {
  struct Bits { char q[4]; unsigned char flags; char w3d_tag_rest[3]; void Or(int m) { flags |= m; } } bits __attribute__((aligned(__alignof__(Iface))));
  char q1[8]; Sphere sphere; String name; int f40; int f44; Ptr32<Iface> mat; Ptr32<Iface> f52;
  char q2[28]; Vec v84; Vec v96;
  void SetSphere(const Sphere &o) { sphere = o; }
  void SetMat(Ptr32<Iface> n) { Ptr32<Iface> old = mat; mat = n; if (n) n->add(); if (old) old->release(); }
  void SetF52(Ptr32<Iface> n) { Ptr32<Iface> old = f52; f52 = n; if (n) n->add(); if (old) old->release(); }

  void SetV96(const Vec &v) { v96 = v; bits.Or(2); }
  void SetV84(const Vec &v) { v84 = v; bits.Or(2); }
  void SetRange(const Vec &a, const Vec &b) { SetV96(a); SetV84(b); }
};
struct Mat : Iface { char q[16] __attribute__((aligned(__alignof__(Iface)))); Box x; int f44; void SetX(const Box &o) { x = o; } };
struct Sub { char q[20]; Ptr32<Iface> r; };
struct Lookup : Iface { void w3d_r_v3() __asm__(W3D_SYM("_ZN6Lookup2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN6Lookup2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN6Lookup2v5Ev")); void w3d_r_v6() __asm__(W3D_SYM("_ZN6Lookup2v6Ev")); void w3d_r_v7() __asm__(W3D_SYM("_ZN6Lookup2v7Ev")); void w3d_r_v8() __asm__(W3D_SYM("_ZN6Lookup2v8Ev")); void w3d_r_v9() __asm__(W3D_SYM("_ZN6Lookup2v9Ev"));
  void w3d_r_v10() __asm__(W3D_SYM("_ZN6Lookup3v10Ev")); void w3d_r_v11() __asm__(W3D_SYM("_ZN6Lookup3v11Ev")); void w3d_r_v12() __asm__(W3D_SYM("_ZN6Lookup3v12Ev")); void w3d_r_v13() __asm__(W3D_SYM("_ZN6Lookup3v13Ev")); void w3d_r_v14() __asm__(W3D_SYM("_ZN6Lookup3v14Ev")); void w3d_r_v15() __asm__(W3D_SYM("_ZN6Lookup3v15Ev")); void w3d_r_v16() __asm__(W3D_SYM("_ZN6Lookup3v16Ev")); void w3d_r_v17() __asm__(W3D_SYM("_ZN6Lookup3v17Ev"));
  void w3d_r_v18() __asm__(W3D_SYM("_ZN6Lookup3v18Ev")); void w3d_r_v19() __asm__(W3D_SYM("_ZN6Lookup3v19Ev")); void w3d_r_v20() __asm__(W3D_SYM("_ZN6Lookup3v20Ev")); void w3d_r_v21() __asm__(W3D_SYM("_ZN6Lookup3v21Ev")); void w3d_r_v22() __asm__(W3D_SYM("_ZN6Lookup3v22Ev")); void w3d_r_v23() __asm__(W3D_SYM("_ZN6Lookup3v23Ev")); void w3d_r_v24() __asm__(W3D_SYM("_ZN6Lookup3v24Ev")); void w3d_r_v25() __asm__(W3D_SYM("_ZN6Lookup3v25Ev"));
  void w3d_r_v26() __asm__(W3D_SYM("_ZN6Lookup3v26Ev")); Ptr32<Sub> w3d_r_find(const unsigned char &) __asm__(W3D_SYM("_ZN6Lookup4findERKh"));  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v23() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v25() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Sub> find(const unsigned char &w3d_a0) { return ((Ptr32<Sub> (*)(w3d_u32, w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 29))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0))); } };
struct Reg2 : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN4Reg22a3Ev")); void w3d_r_Add(Ptr32<Mesh>) __asm__(W3D_SYM("_ZN4Reg23AddEP4Mesh"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Add(Ptr32<Mesh> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Mesh>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); } };
extern Ptr32<Lookup> lbl_804ab5fc;
extern Ptr32<Reg2> lbl_804b0148; extern Ptr32<Reg2> lbl_804b014c;
extern char t_80414518[], t_804144f8[], t_80414af0[], t_80414b20[], t_80414b10[], t_80414940[];
struct Self { char q0[20]; String name; char q1[26]; unsigned short flags; SlotsA a; SlotsA b; Ptr32<Iface> f76; Ptr32<Defs> defs; };
static inline void PutSlot(Ptr32<Self> self, SlotsA &sl, Ptr32<Iface> q) {
  w3d_cx11b_compact_vector_grow_80210d54(&sl, sl.n + 1);
  Ptr32<Iface> &slot = *(Ptr32<Ptr32<Iface>>)w3d::G((sl.n * 4 + (int)w3d::H(sl.d)));
  if (q) q->add();
  if (slot) slot->release();
  slot = q;
  sl.n++;
}
extern "C" int w3d_d40j_material_add_key_801720fc(Ptr32<Self> self, unsigned char key) {
  int i = 0;
  Array<unsigned char> &nm = self->defs->names;
  for (Ptr32<unsigned char> p = nm.start; p != nm.finish; p++, i++)
    if (*p == key) return i;
  Ref<Mesh> a((Ptr32<Mesh>)w3d_s10_service_forward_8020b680(t_80414518));
  Ref<Mesh> b((Ptr32<Mesh>)w3d_s10_service_forward_8020b680(t_804144f8));
  b->bits.Or(4);
  PutSlot(self, self->a, a.p);
  PutSlot(self, self->b, b.p);
  self->defs->names.push_back(key);
  self->defs->items.push_back(Entry());
  {
  Ref<Iface> c(lbl_804ab5fc->find(key)->r);
  w3d_k5b_iface_array_field_append_801ef174(c.p, 44, 3, b.p);
  w3d_k5b_iface_array_field_append_801ef174(b.p, 44, 3, a.p);
  Ref<Mat> mat;
  unsigned short fl = self->flags;
  if (fl & 4) mat = (Ptr32<Mat>)w3d_s10_service_forward_8020b680(t_80414b10);
  else if (fl & 0x800) mat = (Ptr32<Mat>)w3d_s10_service_forward_8020b680(t_80414b20);
  else mat = (Ptr32<Mat>)w3d_s10_service_forward_8020b680(t_80414af0);
  a->name = self->name;
  a->SetMat((Ptr32<Iface>)mat.p);
  a->SetF52(self->f76);
  lbl_804b0148->Add(a.p);
  lbl_804b014c->Add(a.p);
  Ref<Mesh> s((Ptr32<Mesh>)w3d_s10_service_forward_8020b680(t_80414940));
  float k = 0.0f;
  Vec v1; Ptr32<Vec> p1 = &v1; p1->Set(k, k, k); Vec v2; Ptr32<Vec> p2 = &v2; p2->Set(k, k, k);
  b->SetMat(s.p);
  s->SetV96(v1);
  s->SetV84(v2);
  Box x;
  Sphere q; q.w = 5e10f; Ptr32<Sphere> pq = &q; pq->Set(k, k, k);
  box_from_sphere_801f5724(&x, &q);
  b->SetSphere(q); b->f40 = 0;
  a->SetSphere(q); a->f40 = 0;
  mat->SetX(x); mat->f44 = 0;
  }
  return i;
}


