#include "w3d_ptr.h"
#line 1 "d29e_reset_scene_801acb34.cpp"
// (Worms 3D GameCube PAL, 0x801acb34).
//
// Resets a scene node: recomputes its transform through 0x801acd6c with the
// table at 0x8045e748, marks it ready at +136, clears the tree at +100 and
// the 16-byte element vector at +116 (STLport erase with an empty copy and a
// destroy loop), then replaces the held service at +132 with the one found
// for 0x80413b28 (add, release old, store) and calls its virtual slot 12
// with 0. Returns 0. Names are inferred.

extern "C" void f4c_inverse_transpose_801acd6c(Ptr32<void>, Ptr32<void>);
extern char lbl_8045e748[];
extern char lbl_80413b28[];
struct Service {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN7Service2v0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN7Service3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN7Service7releaseEv"));
  void w3d_r_w3() __asm__(W3D_SYM("_ZN7Service2w3Ev")); void w3d_r_w4() __asm__(W3D_SYM("_ZN7Service2w4Ev")); void w3d_r_w5() __asm__(W3D_SYM("_ZN7Service2w5Ev")); void w3d_r_w6() __asm__(W3D_SYM("_ZN7Service2w6Ev")); void w3d_r_w7() __asm__(W3D_SYM("_ZN7Service2w7Ev")); void w3d_r_w8() __asm__(W3D_SYM("_ZN7Service2w8Ev")); void w3d_r_w9() __asm__(W3D_SYM("_ZN7Service2w9Ev")); void w3d_r_w10() __asm__(W3D_SYM("_ZN7Service3w10Ev")); void w3d_r_w11() __asm__(W3D_SYM("_ZN7Service3w11Ev"));
  void w3d_r_bind(int) __asm__(W3D_SYM("_ZN7Service4bindEi"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void bind(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Service, 14))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Service; };
extern "C" Ptr32<Service> w3d_s10_service_forward_8020b680(Ptr32<void>);
extern "C" void w3d_auto_801f2758(Ptr32<void>, int);
extern "C" void w3d_auto_80355800(Ptr32<void>, Ptr32<void>);
struct Node { int p0; Ptr32<Node> parent; Ptr32<Node> left; Ptr32<Node> right; };
struct Tree {
  int p0;
  Ptr32<Node> header;
  int count;
  void erase(Ptr32<Node> n) { w3d_auto_80355800(this, n); }
  void clear() {
    if (count != 0) {
      erase(header->parent);
      header->left = header;
      header->parent = 0;
      header->right = header;
      count = 0;
    }
  }
};
struct Elem { char p[16]; ~Elem() { w3d_auto_801f2758(this, 2); } };
template<class T> inline void v_dist(T *first, T *last, int &n) { n += last - first; }
template<class T> inline Ptr32<T> v_copy(T *first, T *last, T *out) {
    int n = 0;
    v_dist(w3d::R(first), w3d::R(last), n);
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
template<class T> inline void v_destroy(T *first, T *last) { for (; first != last; ++first) first->~T(); }
struct Vec { Ptr32<Elem> b; Ptr32<Elem> e;
  Ptr32<Elem> begin() { return b; } Ptr32<Elem> end() { return e; }
  void erase(Ptr32<Elem> first, Ptr32<Elem> last) {
    Ptr32<Elem> n = v_copy(w3d::R(last), w3d::R(e), w3d::R(first));
    { Ptr32<Elem> l = e; v_destroy(w3d::R(n), w3d::R(l)); }
    e = n;
  }
  void clear() { erase(begin(), end()); }
};
struct Scene {
  char p0[100];
  Tree tree;
  char p1[4];
  Vec vec;
  char p2[8];
  Ptr32<Service> service;
  int ready;
};
extern "C" int w3d_d29e_reset_scene_801acb34(Ptr32<Scene> self) {
  f4c_inverse_transpose_801acd6c(self, lbl_8045e748);
  self->ready = 1;
  self->tree.clear();
  self->vec.clear();
  Ptr32<Service> s = w3d_s10_service_forward_8020b680(lbl_80413b28);
  if (s) s->add();
  if (self->service) self->service->release();
  self->service = s;
  s->bind(0);
  return 0;
}


