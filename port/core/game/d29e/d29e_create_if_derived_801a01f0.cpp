#include "w3d_ptr.h"
#line 1 "d29e_create_if_derived_801a01f0.cpp"
// (Worms 3D GameCube PAL, 0x801a01f0).
//
// Queries the service at 0x8020b648 for the interface 0x804138b0 into a held
// reference, looks up an entry by name (slot 3) and, if the entry exists and
// base is null or found on the entry's parent chain at +20, returns the
// result of the entry's create call at table offset 88; otherwise returns 0.
// Names are inferred.

struct Obj {
  char p[20];
  Ptr32<Obj> parent;
  bool isA(Ptr32<Obj> base) {
    Ptr32<Obj> t = this;
    while (t != base) {
      Ptr32<Obj> n = t->parent;
      if (t == n) return false;
      t = n;
    }
    return true;
  }
};
struct Made;
struct Thing : Obj {};
struct Registry {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN8Registry2v0Ev"));
  void w3d_r_v1() __asm__(W3D_SYM("_ZN8Registry2v1Ev"));
  void w3d_r_release() __asm__(W3D_SYM("_ZN8Registry7releaseEv"));
  Ptr32<Obj> w3d_r_find(Ptr32<void>) __asm__(W3D_SYM("_ZN8Registry4findEPv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Registry, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Registry, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Registry, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Obj> find(Ptr32<void> w3d_a0) { return ((Ptr32<Obj> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Registry, 5))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Registry; };
struct Svc { int w3d_r_query(Ptr32<const void>, Ptr32<void>) __asm__(W3D_SYM("_ZN3Svc5queryEPKvPv"));  __attribute__((always_inline)) inline int query(Ptr32<const void> w3d_a0, Ptr32<void> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<const void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Svc, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Svc; };
extern char lbl_804138b0[];
extern "C" Ptr32<Svc> w3d_auto_8020b648();
struct Ref {
  Ptr32<Registry> p;
  Ref() : p(0) {}
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
};
struct Fac { void w3d_r_a() __asm__(W3D_SYM("_ZN3Fac1aEv"));  __attribute__((always_inline)) inline void a() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Fac, 2))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Fac; };
typedef Ptr32<Ptr32<void> (Ptr32<Obj>)> Create;
extern "C" Ptr32<void> w3d_d29e_create_if_derived_801a01f0(Ptr32<void> name, Ptr32<Obj> base) {
  Ptr32<Svc> s = w3d_auto_8020b648();
  Ref m;
  if (s) s->query(lbl_804138b0, &m.p);
  Ptr32<Obj> o = m.p->find(name);
  if (!o || (base && !o->isA(base))) return 0;
  return (*(Ptr32<Create>)(*(Ptr32<Ptr32<char>>)o + 88))(o);
}


