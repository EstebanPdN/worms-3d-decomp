#include "w3d_ptr.h"
#line 1 "d42e_node_set_value_801dcdc0.cpp"
// (Worms 3D GameCube PAL, 0x801dcdc0).
//
// Value setter of a node with a child list: id 20 stores a non-negative value
// and forwards it to the first ready child, ids 21 to 23 store 0-or-1
// settings, and an invalid value returns E_FAIL.

struct Item {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN4Item2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN4Item2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN4Item2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN4Item2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN4Item2v4Ev"));
  int w3d_r_ready() __asm__(W3D_SYM("_ZN4Item5readyEv"));
  void w3d_r_w6() __asm__(W3D_SYM("_ZN4Item2w6Ev")); void w3d_r_w7() __asm__(W3D_SYM("_ZN4Item2w7Ev")); void w3d_r_w8() __asm__(W3D_SYM("_ZN4Item2w8Ev")); void w3d_r_w9() __asm__(W3D_SYM("_ZN4Item2w9Ev")); void w3d_r_w10() __asm__(W3D_SYM("_ZN4Item3w10Ev"));
  void w3d_r_w11() __asm__(W3D_SYM("_ZN4Item3w11Ev")); void w3d_r_w12() __asm__(W3D_SYM("_ZN4Item3w12Ev")); void w3d_r_w13() __asm__(W3D_SYM("_ZN4Item3w13Ev")); void w3d_r_w14() __asm__(W3D_SYM("_ZN4Item3w14Ev")); void w3d_r_w15() __asm__(W3D_SYM("_ZN4Item3w15Ev"));
  int w3d_r_set(Ptr32<int> value) __asm__(W3D_SYM("_ZN4Item3setEPi"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int ready() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void w15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int set(Ptr32<int> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<int>))w3d::vfn(this->w3d_vptr_Item, 18))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Item; };
struct List { unsigned count; int cap; Ptr32<Ptr32<Item>> items; };
struct Node {
  char p0[48];
  List list;
  char p1[44];
  int v104, v108, v112;
  char p2[4];
  int v120;
};
// Stores a 0-or-1 setting, or takes the invalid-value exit.
#define SET_BOOL(field, v) do { if (v != 1) if (v != 0) goto bad; self->field = v; } while (0)

extern "C" int w3d_d42e_node_set_value_801dcdc0(Ptr32<Node> self, int id, Ptr32<int> value) {
  switch (id) {
    case 20: {
      int v = *value;
      if (v < 0) goto bad;
      self->v120 = v;
      for (unsigned i = 0; i < self->list.count; i++) {
        List &list = self->list;
        if (list.items[i]->ready() == 1) return list.items[i]->set(value);
      }
      break;
    }
    case 21: {
      int v = *value;
      SET_BOOL(v112, v);
      return 0;
    }
    case 22: {
      int v = *value;
      SET_BOOL(v104, v);
      break;
    }
    case 23: {
      int v = *value;
      SET_BOOL(v108, v);
      return 0;
    }
    bad:
      return 0x80004005;
  }
  return 1;
}


