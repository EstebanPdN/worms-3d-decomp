#include "w3d_ptr.h"
#line 1 "d31j_load_mesh_resource_8018a8fc.cpp"
// Loads the mesh resource of an instance node, attaches it to a new node and
// instance, and rebuilds its sorted edges. Ref default constructor does not
// initialise; the texture Ref is declared with the mesh Ref. GWMP8P rev0
// 0x8018a8fc.
extern "C" {
Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
void w3d_string_base_init(Ptr32<void>);
Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_string_release_header(Ptr32<void>);
void w3d_k5b_iface_array_field_append_801ef174(Ptr32<void>, int, int, Ptr32<void>);
int w3d_k8b_iface_add_801b14e8(Ptr32<void>, Ptr32<void>);
}
struct Iface { int w3d_r_query(Ptr32<void>, Ptr32<void>) __asm__(W3D_SYM("_ZN5Iface5queryEPvS0_")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline int query(Ptr32<void> w3d_a0, Ptr32<void> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  Ref() {}
  void attach(Ptr32<T> q) { p = q; if (p) p->add(); }
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((T *)w3d_p.get()); }
 Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
  Ref &operator=(const Ref &o) { Ptr32<T> old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct Str {
  Ptr32<char> p;
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
  Str &operator=(const Str &o) {
    ++*(Ptr32<unsigned short>)(o.p - 6);
    Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
inline void use(Str) {}
struct Vec { float x, y, z; };
struct Sphere { Vec c; float r; };
struct Box { Vec lo; Vec hi; };
struct Bits { char p0[4]; unsigned char flags; char w3d_tag_rest[3]; void mark() { flags |= 2; } };
struct Tex : Iface {
  Bits bits __attribute__((aligned(__alignof__(Iface)))); char pc[60];
  Vec a; Vec b; Vec c;
  void setB(const Vec &v) { b = v; bits.mark(); }
  void setC(const Vec &v) { c = v; bits.mark(); }
};
struct Part { char p0[36]; Ptr32<struct Leaf> leaf; };
struct Leaf { char p0[56]; int dirty; };
struct Blob { char p0[24]; unsigned int count; char p1c[4]; Ptr32<Part> data[1]; };
struct Mesh : Iface { char p4[24] __attribute__((aligned(__alignof__(Iface)))); Ptr32<Blob> parts; };
struct Inst : Iface { void setBound(const Sphere &v) { bound = v; } char p4[16] __attribute__((aligned(__alignof__(Iface)))); Sphere bound; Str name; int z40; char p2c[4]; Ref<Tex> tex; };
struct Node : Iface { void setBound(const Sphere &v) { bound = v; } char p4[16] __attribute__((aligned(__alignof__(Iface)))); Sphere bound; char p24[4]; int z40; char p2c[8]; Ref<Mesh> mesh; };
struct Loader : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN6Loader2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN6Loader2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN6Loader2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN6Loader2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN6Loader2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN6Loader2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN6Loader2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN6Loader3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN6Loader3a11Ev")); int w3d_r_create(Ptr32<void>, int, Ptr32<Ref < Mesh >>) __asm__(W3D_SYM("_ZN6Loader6createEPviP3RefI4MeshE"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int create(Ptr32<void> w3d_a0, int w3d_a1, Ptr32<Ref < Mesh >> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, int, Ptr32<Ref < Mesh >>))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); } };
struct Sink : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN4Sink2a3Ev")); void w3d_r_attach(Ptr32<Mesh>) __asm__(W3D_SYM("_ZN4Sink6attachEP4Mesh"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void attach(Ptr32<Mesh> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Mesh>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); } };
struct Self : Iface {
  void w3d_r_v20() __asm__(W3D_SYM("_ZN4Self3v20Ev")); void w3d_r_v24() __asm__(W3D_SYM("_ZN4Self3v24Ev")); void w3d_r_v28() __asm__(W3D_SYM("_ZN4Self3v28Ev")); void w3d_r_v32() __asm__(W3D_SYM("_ZN4Self3v32Ev")); void w3d_r_v36() __asm__(W3D_SYM("_ZN4Self3v36Ev")); void w3d_r_v40() __asm__(W3D_SYM("_ZN4Self3v40Ev")); void w3d_r_v44() __asm__(W3D_SYM("_ZN4Self3v44Ev")); void w3d_r_v48() __asm__(W3D_SYM("_ZN4Self3v48Ev")); void w3d_r_v52() __asm__(W3D_SYM("_ZN4Self3v52Ev")); void w3d_r_v56() __asm__(W3D_SYM("_ZN4Self3v56Ev")); void w3d_r_v60() __asm__(W3D_SYM("_ZN4Self3v60Ev")); void w3d_r_v64() __asm__(W3D_SYM("_ZN4Self3v64Ev")); void w3d_r_v68() __asm__(W3D_SYM("_ZN4Self3v68Ev")); void w3d_r_v72() __asm__(W3D_SYM("_ZN4Self3v72Ev")); void w3d_r_v76() __asm__(W3D_SYM("_ZN4Self3v76Ev")); void w3d_r_v80() __asm__(W3D_SYM("_ZN4Self3v80Ev")); void w3d_r_v84() __asm__(W3D_SYM("_ZN4Self3v84Ev")); void w3d_r_v88() __asm__(W3D_SYM("_ZN4Self3v88Ev"));
  void w3d_r_set92(int) __asm__(W3D_SYM("_ZN4Self5set92Ei")); void w3d_r_set96(int) __asm__(W3D_SYM("_ZN4Self5set96Ei")); void w3d_r_set100(int) __asm__(W3D_SYM("_ZN4Self6set100Ei"));
  char p4[16] __attribute__((aligned(__alignof__(Iface)))); Str name; int flags; char p1c[4]; Ref<Inst> inst; Ref<Mesh> mesh; Ref<Node> node; char p2c[16]; unsigned short opts; char p3e[2]; Ptr32<void> res;
 __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v80() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void set92(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void set96(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 24))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void set100(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Iface, 25))(w3d::h2g(this), w3d_a0); } };
extern "C" int w3d_d29e_run_file_8020b6e8(Ptr32<void>, Ptr32<void>);
extern "C" void w3d_cx13b_sphere_bounds_801f5724(Ptr32<Box>, Ptr32<Sphere>);
extern "C" int d26j_rebuild_sorted_edges_8018b638(Ptr32<Self>);
extern Ptr32<void> lbl_804b0240; extern Ptr32<void> lbl_804b0244; extern Ptr32<void> lbl_804b0250;
extern Ptr32<Sink> lbl_804b025c; extern Ptr32<Sink> lbl_804b0264; extern Ptr32<Sink> lbl_804b0260; extern Ptr32<Sink> lbl_804b026c;
extern char lbl_8040e058[], lbl_8040e118[], lbl_80414518[], lbl_804144f8[], lbl_80414940[];
extern "C" int d31j_load_mesh_resource_8018a8fc(Ptr32<Self> self) {
  int on = (self->flags >> 15) & 1;
  if (on) return 0x80004005;
  Ref<Iface> file(0);
  Ptr32<Loader> loader;
  if (w3d_d29e_run_file_8020b6e8(self->res, &file) < 0) {
    use(self->name);
    goto bad;
  }
  if (file->query(lbl_8040e058, &loader) < 0) {
    bad:
    return 0x80004005;
  }
  Ref<Mesh> got(0);
  Ref<Tex> tex;
  loader->create(lbl_8040e118, 0, &got);
  loader->release();
  self->mesh = got.p;
  self->node = (Ptr32<Node>)w3d_s10_service_forward_8020b680(lbl_80414518);
  Ptr32<Node> n = self->node.p;
  n->mesh = self->mesh;
  Vec a; Ptr32<Vec> pa = &a;
  Vec b; Ptr32<Vec> pb = &b;
  Box box;
  Sphere s; Ptr32<Sphere> ps = &s;
  Ptr32<Box> pbox = &box;
  Ptr32<Blob> parts = self->mesh.p->parts;
  unsigned int count = parts->count;
  Ptr32<Ptr32<Part>> d = parts->data;
  for (unsigned int i = 0; i < count; i++) d[i]->leaf->dirty = 1;
  w3d_k8b_iface_add_801b14e8(self->mesh.p, lbl_804b0240);
  w3d_k8b_iface_add_801b14e8(self->mesh.p, lbl_804b0244);
  w3d_k8b_iface_add_801b14e8(self->mesh.p, lbl_804b0250);
  lbl_804b025c->attach(self->mesh.p);
  lbl_804b0264->attach(self->mesh.p);
  lbl_804b0260->attach(self->mesh.p);
  lbl_804b026c->attach(self->mesh.p);
  self->inst = (Ptr32<Inst>)w3d_s10_service_forward_8020b680(lbl_804144f8);
  tex.attach((Ptr32<Tex>)w3d_s10_service_forward_8020b680(lbl_80414940));
  a.x = 0.0f; pa->y = 0.0f; pa->z = 0.0f;
  b.x = 0.0f; pb->y = 0.0f; pb->z = 0.0f;
  {
    Ptr32<Inst> ni = self->inst.p;
    ni->name = self->name;
  }
  w3d_k5b_iface_array_field_append_801ef174(self->inst.p, 44, 3, self->node.p);
  self->inst->tex = tex;
  tex->setC(a);
  tex->setB(b);
  self->flags |= 0x8000;
  if (self->opts & 1) self->set92(1); else self->set92(0);
  if (self->opts & 2) self->set96(1); else self->set96(0);
  if (self->opts & 16) self->set100(1); else self->set100(0);
  s.r = 5e10f; s.c.x = 0.0f; ps->c.y = 0.0f; ps->c.z = 0.0f;
  w3d_cx13b_sphere_bounds_801f5724(pbox, ps);
  self->inst->setBound(s);
  self->inst->z40 = 0;
  self->node->setBound(s);
  self->node->z40 = 0;
  return d26j_rebuild_sorted_edges_8018b638(self);
}


