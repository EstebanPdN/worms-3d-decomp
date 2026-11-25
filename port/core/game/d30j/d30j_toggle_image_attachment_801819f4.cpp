#include "w3d_ptr.h"
#line 1 "d30j_toggle_image_attachment_801819f4.cpp"
// Attach or detach the default image of a resource: fetch the image from the
// store; to attach, create a node holding it and append it to the instance; to
// detach, find the node of the right type holding it and remove it. Keeps the
// state in a flag. GWMP8P rev0 0x801819f4.
extern "C" Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  Ref() { p = 0; }
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
  Ref &operator=(const Ref &o) { Ptr32<T> old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct Type { char p0[20]; Ptr32<Type> parent; };
extern char lbl_80362844[];
extern char lbl_8040e0d8[], lbl_80414518[];
struct Node : Iface { Ptr32<Type> w3d_r_type() __asm__(W3D_SYM("_ZN4Node4typeEv")); char p4[44] __attribute__((aligned(__alignof__(Iface)))); Ref<Iface> image; 
  bool isA(Ptr32<Type> t) {
    Ptr32<Type> c = type();
    while (c != t) {
      if (c == c->parent) return false;
      c = c->parent;
    }
    return true;
  }
 __attribute__((always_inline)) inline Ptr32<Type> type() { return ((Ptr32<Type> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); } };
struct List { char p0[24]; unsigned int count; char p1c[4]; Ptr32<Node> data[1]; };
struct Owner { char p0[44]; Ptr32<List> list; };
extern "C" void w3d_k5b_iface_array_field_append_801ef174(Ptr32<Owner>, int, int, Ptr32<Node>);
extern "C" void fn_801ef380(Ptr32<Owner>, int, int, unsigned int, int);
struct Store : Iface { void w3d_r_s20() __asm__(W3D_SYM("_ZN5Store3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN5Store3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN5Store3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN5Store3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN5Store3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN5Store3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN5Store3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN5Store3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN5Store3s52Ev")); int w3d_r_get(Ptr32<void>, int, Ptr32<Ref < Iface >>) __asm__(W3D_SYM("_ZN5Store3getEPviP3RefI5IfaceE"));  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int get(Ptr32<void> w3d_a0, int w3d_a1, Ptr32<Ref < Iface >> w3d_a2) { return ((int (*)(w3d_u32, Ptr32<void>, int, Ptr32<Ref < Iface >>))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); } };
struct Res { char p0[40]; Ptr32<Store> store; };
extern "C" Ptr32<Res> w3d_empty_80341348(Ptr32<void>);
struct Self { char p0[116]; Ptr32<void> item; Ptr32<Owner> inst; char p7c[56]; unsigned int flags; };
extern "C" int d30j_toggle_image_attachment_801819f4(Ptr32<Self> self, int on) {
  if (on == (int)((self->flags >> 30) & 1)) return 0;
  Ref<Iface> t;
  int hr = w3d_empty_80341348(self->item)->store->get(lbl_8040e0d8, 0, &t);
  Ref<Iface> u(t.p);
  if (hr < 0) return hr;
  if (on) {
    Ref<Node> n((Ptr32<Node>)w3d_s10_service_forward_8020b680(lbl_80414518));
    n->image = u;
    w3d_k5b_iface_array_field_append_801ef174(self->inst, 44, 3, n.p);
    self->flags |= 0x40000000;
  } else {
    Ptr32<List> l = self->inst->list;
    unsigned int c = l->count;
    Ptr32<Ptr32<Node>> q = l->data;
    for (unsigned int k = 0; k < c; k++) {
      if (q[k]->isA((Ptr32<Type>)lbl_80362844) && q[k]->image.p == u.p) {
        fn_801ef380(self->inst, 44, 3, k, 1);
        self->flags &= ~0x40000000;
        return 0;
      }
    }
    return 0x80004005;
  }
  return 0;
}


