#include "w3d_ptr.h"
#line 1 "d30j_solve_attachment_matrix_80181e3c.cpp"
// Compute an attachment matrix: bind a solver to the object and instance, attach
// a temporary node, compute the 48-byte matrix through a second service, copy it
// out and detach the temporary node again. GWMP8P rev0 0x80181e3c.
extern "C" Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
};
struct Mat { float m[12]; };
struct List { char p0[24]; unsigned int count; char p1c[4]; Ptr32<Iface> data[1]; };
struct Owner { char p0[44]; Ptr32<List> list; };
extern "C" void w3d_k5b_iface_array_field_append_801ef174(Ptr32<Owner>, int, int, Ptr32<Iface>);
extern "C" void fn_801ef380(Ptr32<Owner>, int, int, unsigned int, int);
struct X : Iface {
  void w3d_r_s20() __asm__(W3D_SYM("_ZN1X3s20Ev")); int w3d_r_bind(Ptr32<Iface>) __asm__(W3D_SYM("_ZN1X4bindEP5Iface")); void w3d_r_s28() __asm__(W3D_SYM("_ZN1X3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN1X3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN1X3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN1X3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN1X3s44Ev")); int w3d_r_set(Ptr32<Iface>) __asm__(W3D_SYM("_ZN1X3setEP5Iface")); Ptr32<Owner> w3d_r_owner() __asm__(W3D_SYM("_ZN1X5ownerEv"));
  void w3d_r_s56() __asm__(W3D_SYM("_ZN1X3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN1X3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN1X3s64Ev")); void w3d_r_s68() __asm__(W3D_SYM("_ZN1X3s68Ev")); void w3d_r_s72() __asm__(W3D_SYM("_ZN1X3s72Ev")); int w3d_r_solve(Ptr32<Iface>, Ptr32<Iface>, Ptr32<Ptr32<Mat>>) __asm__(W3D_SYM("_ZN1X5solveEP5IfaceS1_PP3Mat"));
 __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int bind(Ptr32<Iface> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int set(Ptr32<Iface> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline Ptr32<Owner> owner() { return ((Ptr32<Owner> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int solve(Ptr32<Iface> w3d_a0, Ptr32<Iface> w3d_a1, Ptr32<Ptr32<Mat>> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<Iface>, Ptr32<Iface>, Ptr32<Ptr32<Mat>>))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); } };
struct Self { char p0[120]; Ptr32<Iface> inst; };
extern char lbl_804164c0[], lbl_804163f8[], lbl_80414a40[], lbl_804140d0[];
extern "C" int d30j_solve_attachment_matrix_80181e3c(Ptr32<Self> self, Ptr32<Iface> a, Ptr32<Mat> out) {
  if (a) {
    Ref<X> x((Ptr32<X>)w3d_s10_service_forward_8020b680(lbl_804164c0));
    x->set(a);
    if (x->bind(self->inst) >= 0) {
      Ref<X> c((Ptr32<X>)w3d_s10_service_forward_8020b680(lbl_804163f8));
      Ref<Iface> d((Ptr32<Iface>)w3d_s10_service_forward_8020b680(lbl_80414a40));
      Ref<X> e((Ptr32<X>)w3d_s10_service_forward_8020b680(lbl_804140d0));
      Ptr32<Owner> o = x->owner();
      w3d_k5b_iface_array_field_append_801ef174(o, 44, 3, d.p);
      Ptr32<Iface> i = self->inst;
      e->set(c.p);
      e->bind(i);
      Ptr32<Mat> m;
      c->solve(d.p, i, &m);
      *out = *m;
      Ptr32<List> l = o->list;
      unsigned int n = l->count;
      Ptr32<Ptr32<Iface>> q = l->data;
      for (unsigned int k = 0; k < n; k++) {
        if (q[k] == d.p) {
          fn_801ef380(o, 44, 3, k, 1);
          return 0;
        }
      }
    }
  }
  return 0x80004005;
}


