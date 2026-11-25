#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "d31j_reload_saved_items_8017ce10.cpp"
// Reloads saved items from the kind's file: for each stored item finds the
// matching entry, checks kind and flags and replaces it. GWMP8P rev0 0x8017ce10.
extern "C" {
Ptr32<void> w3d_string_default(Ptr32<void>);
void w3d_string_format(Ptr32<void>, Ptr32<const char>, ...);
void w3d_string_base_init(Ptr32<void>);
Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
int w3d_constant_8020b5c8(int);
void w3d_empty_8020b5d0();
}
struct Iface { int w3d_r_query(Ptr32<void>, Ptr32<void>) __asm__(W3D_SYM("_ZN5Iface5queryEPvS0_")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline int query(Ptr32<void> w3d_a0, Ptr32<void> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  Ref() { p = 0; }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
  Ref &operator=(const Ref &o) { if (o.p) o.p->add(); if (p) p->release(); p = o.p; return *this; }
};
struct Str {
  Ptr32<char> p;
  Str() {}
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
};
inline void use(Str) {}
struct Info { char p0[16]; };
struct Node : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN4Node2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN4Node2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN4Node2a5Ev")); int w3d_r_commit(Ptr32<Node>) __asm__(W3D_SYM("_ZN4Node6commitEPS_")); int w3d_r_size36() __asm__(W3D_SYM("_ZN4Node6size36Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN4Node2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN4Node2a9Ev")); int w3d_r_v48() __asm__(W3D_SYM("_ZN4Node3v48Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN4Node3a11Ev")); void w3d_r_a12() __asm__(W3D_SYM("_ZN4Node3a12Ev")); void w3d_r_a13() __asm__(W3D_SYM("_ZN4Node3a13Ev")); int w3d_r_v64() __asm__(W3D_SYM("_ZN4Node3v64Ev")); const Str &w3d_r_name() __asm__(W3D_SYM("_ZN4Node4nameEv")); Ptr32<unsigned char> w3d_r_kind() __asm__(W3D_SYM("_ZN4Node4kindEv")); void w3d_r_a15() __asm__(W3D_SYM("_ZN4Node3a15Ev")); int w3d_r_v80() __asm__(W3D_SYM("_ZN4Node3v80Ev"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int commit(Ptr32<Node> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<Node>))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline int size36() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v48() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v64() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline const Str &name() { return *(const Str *)w3d::g2h(((w3d_u32 (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this))); }  __attribute__((always_inline)) inline Ptr32<unsigned char> kind() { return ((Ptr32<unsigned char> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v80() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this)); } };
struct Item : Node {};
struct Src : Node { };
struct Holder : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN6Holder2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN6Holder2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN6Holder2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN6Holder2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN6Holder2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN6Holder2a8Ev")); unsigned w3d_r_count() __asm__(W3D_SYM("_ZN6Holder5countEv")); void w3d_r_at(unsigned, Ptr32<Info>, Ptr32<Ref < Iface >>, int) __asm__(W3D_SYM("_ZN6Holder2atEjP4InfoP3RefI5IfaceEi"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline unsigned int count() { return ((unsigned int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void at(unsigned int w3d_a0, Ptr32<Info> w3d_a1, Ptr32<Ref < Iface >> w3d_a2, int w3d_a3) { ((void (*)(w3d_u32, unsigned int, Ptr32<Info>, Ptr32<Ref < Iface >>, int))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2, w3d_a3); } };
struct Self;
struct Entry { char p0[24]; Ref<Node> r; };
struct Self { char p0[9804]; Ptr32<void (unsigned int, unsigned int)> progress; char p2650[16]; Ptr32<const char> fmt; };
extern "C" int d24j_find_named_item_8017e22c(Ptr32<Self>, const Str &, Ptr32<unsigned short>);
extern "C" int w3d_d29e_run_file_8020b6e8(Ptr32<const char>, Ptr32<Ref < Iface >>);
extern int lbl_804a8dd8[];
extern char lbl_8040e058[], lbl_8040ca90[];
extern "C" int d31j_reload_saved_items_8017ce10(Ptr32<Self> self, Ptr32<unsigned char> kind) {
  Ref<Iface> file;
  Str path;
  Ptr32<Str> pp = &path;
  w3d_string_default(pp);
  w3d_string_format(pp, self->fmt, *kind);
  int hr = w3d_d29e_run_file_8020b6e8(path.p, &file);
  if (hr >= 0) {
  Ref<Holder> h;
  hr = file->query(lbl_8040e058, &h);
  if (hr < 0) return hr;
  unsigned n = h->count();
  for (unsigned i = 0; i < n; i++) {
    Info info;
    Ref<Iface> a;
    h->at(i, &info, &a, 0);
    Ref<Node> b;
    a->query(lbl_8040ca90, &b);
    unsigned short idx;
    if (d24j_find_named_item_8017e22c(self, b->name(), &idx) < 0) {
      hr = 0x80004005;
      use(b->name());
    } else {
      int flags = 0;
      Ref<Node> &slot = ((Ref<Node> *)w3d_restab_slots())[idx];   // port (v29): era (self + 24)[idx]
      Ptr32<Node> item = slot.p;
      if (*item->kind() != *kind) flags = 1;
      if (item->size36() != b->size36()) flags |= 2;
      if (item->v64()) flags |= 4;
      if (item->v80()) flags |= 8;
      if (flags == 0) {
        w3d_constant_8020b5c8(-1);
        int r = b->commit(item);
        if (r < 0) hr = r;
        r = b->v48();
        if (r < 0) hr = r;
        slot = b;
        w3d_empty_8020b5d0();
      } else {
        hr = 0x80004005;
        use(b->name()), use(path);
      }
    }
    if (self->progress) self->progress(i, n);
  }
  } else {
    lbl_804a8dd8[*kind] = 0;
  }
  return hr;
}


