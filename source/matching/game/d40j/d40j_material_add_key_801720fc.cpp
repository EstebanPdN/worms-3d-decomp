// Material set (Worms 3D GameCube PAL, 0x801720fc): returns the index of a key in
// the set's key array or, for a new key, builds a material with its two mesh
// parts, adds them to the two compact slot arrays, appends the key and an empty
// entry, wires the parts under the object for that key, picks the shader type
// from the set's flags, and resets the parts' bounds to a sphere of radius 5e10 and its box.
// Names are inferred.
#include "compat/stlport_sn_oom.h"
#include <vector>
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
void w3d_k5b_iface_array_field_append_801ef174(void *, int, int, void *);
void *malloc(unsigned);
void w3d_handle_storage_release(void *);
void *memcpy_802eee50(void *, const void *, unsigned int, ...);
void w3d_string_free_8020bb2c(void *);
}
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref() : p(0) {}
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
  T *start, *finish, *storage_end;
  void grow() {
    unsigned int used = (char *)finish - (char *)start;
    int a = used + 1, b = used + (used >> 1);
    unsigned int bytes = Max(a, b);
    T *p = (T *)malloc(bytes);
    if (start) {
      memcpy_802eee50(p, start, Min(bytes, used));
      w3d_handle_storage_release(start);
    }
    start = p; finish = (T *)((char *)p + used); storage_end = (T *)((char *)p + bytes);
  }
  void push_back(const T &v) {
    if (finish == storage_end) grow();
    *finish = v;
    finish++;
  }
};
struct Entry {
  char *start, *finish, *storage_end; int tag;
  Entry() { storage_end = 0; finish = 0; start = 0; tag = 0; }
  Entry(const Entry &o) {
    unsigned n = o.finish - o.start;
    char *p = (char *)malloc(n);
    start = p; finish = p + n; storage_end = p + n;
    memcpy_802eee50(p, o.start, n);
    tag = o.tag;
  }
  ~Entry() { if (start) w3d_handle_storage_release(start); }
  Entry &operator=(const Entry &);
};
struct Defs { std::vector<Entry> items; Array<unsigned char> names; };
struct SlotsA { unsigned n; int cap; Iface **d; };
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(SlotsA *, unsigned);
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) { x = o.x; y = o.y; z = o.z; }
  void Set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Sphere { float x, y, z, w; Sphere() {} void Set(float a, float b, float c) { x = a; y = b; z = c; } };
struct Box { int w[6]; };
extern "C" void box_from_sphere_801f5724(Box *, const Sphere *);
struct String { char *p;
  String &operator=(const String &o) { ++*(unsigned short *)(o.p - 6); char *old = p; void *h = old - 6; unsigned short c = --*(unsigned short *)(old - 6); if (c == 0) w3d_string_free_8020bb2c(h); p = o.p; return *this; } };
struct Mesh : Iface {
  struct Bits { char q[7]; unsigned char flags; void Or(int m) { flags |= m; } } bits;
  char q1[8]; Sphere sphere; String name; int f40; int f44; Iface *mat; Iface *f52;
  char q2[28]; Vec v84; Vec v96;
  void SetSphere(const Sphere &o) { sphere = o; }
  void SetMat(Iface *n) { Iface *old = mat; mat = n; if (n) n->add(); if (old) old->release(); }
  void SetF52(Iface *n) { Iface *old = f52; f52 = n; if (n) n->add(); if (old) old->release(); }

  void SetV96(const Vec &v) { v96 = v; bits.Or(2); }
  void SetV84(const Vec &v) { v84 = v; bits.Or(2); }
  void SetRange(const Vec &a, const Vec &b) { SetV96(a); SetV84(b); }
};
struct Mat : Iface { char q[16]; Box x; int f44; void SetX(const Box &o) { x = o; } };
struct Sub { char q[20]; Iface *r; };
struct Lookup : Iface { virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
  virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
  virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
  virtual void v26(); virtual Sub *find(const unsigned char &); };
struct Reg2 : Iface { virtual void a3(); virtual void Add(Mesh *); };
extern Lookup *lbl_804ab5fc;
extern Reg2 *lbl_804b0148, *lbl_804b014c;
extern char t_80414518[], t_804144f8[], t_80414af0[], t_80414b20[], t_80414b10[], t_80414940[];
struct Self { char q0[20]; String name; char q1[26]; unsigned short flags; SlotsA a; SlotsA b; Iface *f76; Defs *defs; };
static inline void PutSlot(Self *self, SlotsA &sl, Iface *q) {
  w3d_cx11b_compact_vector_grow_80210d54(&sl, sl.n + 1);
  Iface *&slot = *(Iface **)(sl.n * 4 + (int)sl.d);
  if (q) q->add();
  if (slot) slot->release();
  slot = q;
  sl.n++;
}
extern "C" int w3d_d40j_material_add_key_801720fc(Self *self, unsigned char key) {
  int i = 0;
  Array<unsigned char> &nm = self->defs->names;
  for (unsigned char *p = nm.start; p != nm.finish; p++, i++)
    if (*p == key) return i;
  Ref<Mesh> a((Mesh *)w3d_s10_service_forward_8020b680(t_80414518));
  Ref<Mesh> b((Mesh *)w3d_s10_service_forward_8020b680(t_804144f8));
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
  if (fl & 4) mat = (Mat *)w3d_s10_service_forward_8020b680(t_80414b10);
  else if (fl & 0x800) mat = (Mat *)w3d_s10_service_forward_8020b680(t_80414b20);
  else mat = (Mat *)w3d_s10_service_forward_8020b680(t_80414af0);
  a->name = self->name;
  a->SetMat((Iface*)mat.p);
  a->SetF52(self->f76);
  lbl_804b0148->Add(a.p);
  lbl_804b014c->Add(a.p);
  Ref<Mesh> s((Mesh *)w3d_s10_service_forward_8020b680(t_80414940));
  float k = 0.0f;
  Vec v1; Vec *p1 = &v1; p1->Set(k, k, k); Vec v2; Vec *p2 = &v2; p2->Set(k, k, k);
  b->SetMat(s.p);
  s->SetV96(v1);
  s->SetV84(v2);
  Box x;
  Sphere q; q.w = 5e10f; Sphere *pq = &q; pq->Set(k, k, k);
  box_from_sphere_801f5724(&x, &q);
  b->SetSphere(q); b->f40 = 0;
  a->SetSphere(q); a->f40 = 0;
  mat->SetX(x); mat->f44 = 0;
  }
  return i;
}
