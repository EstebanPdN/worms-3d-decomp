#include "w3d_ptr.h"
#line 1 "d29e_prune_children_801b1ed4.cpp"
// (Worms 3D GameCube PAL, 0x801b1ed4).
//
// Walks the child array at +28 of a node through the scanner (self minus 4
// when non-null): optionally marks each child's flag bit, records the index
// of a child whose parent is an ancestor or whose references are missing,
// and replaces a flagged child with the result of the scanner factory's
// virtual slot 10; then erases the recorded indices through 0x801ef380,
// adjusting for prior removals. Returns 0. Names are inferred.

struct Parent { char w3d_empty; };
struct ItemBase {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN8ItemBase2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN8ItemBase2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN8ItemBase2v2Ev"));
  Ptr32<Parent> w3d_r_parent() __asm__(W3D_SYM("_ZN8ItemBase6parentEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ItemBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ItemBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ItemBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Parent> parent() { return ((Ptr32<Parent> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ItemBase, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_ItemBase; };
struct Item : ItemBase {
  struct Bits { char p[4]; unsigned char flags; char w3d_tag_rest[3]; } bits __attribute__((aligned(__alignof__(ItemBase))));
};
struct Array { char p[24]; unsigned count; int locks; Ptr32<Item> items[1]; };
struct Node { char p[28]; Ptr32<Array> items; };
struct Factory { void w3d_r_a0() __asm__(W3D_SYM("_ZN7Factory2a0Ev")); void w3d_r_a1() __asm__(W3D_SYM("_ZN7Factory2a1Ev")); void w3d_r_a2() __asm__(W3D_SYM("_ZN7Factory2a2Ev")); void w3d_r_a3() __asm__(W3D_SYM("_ZN7Factory2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN7Factory2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN7Factory2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN7Factory2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN7Factory2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN7Factory2a8Ev"));
  Ptr32<Item> w3d_r_convert(Ptr32<Item>) __asm__(W3D_SYM("_ZN7Factory7convertEP4Item"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Item> convert(Ptr32<Item> w3d_a0) { return ((Ptr32<Item> (*)(w3d_u32, Ptr32<Item>))w3d::vfn(this->w3d_vptr_Factory, 11))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Factory; };
struct Scanner { char p[72]; Ptr32<Factory> factory; char q[4]; int mark; };
struct Second { int x; };
extern "C" int w3d_s10_has_ancestor_801b1de0(Ptr32<Scanner>, Ptr32<Parent>);
extern "C" int w3d_k4b_scanner_has_missing_801b1e48(Ptr32<Scanner>, Ptr32<Item>);
extern "C" void w3d_k5b_iface_array_field_set_801ef2ec(Ptr32<Node>, int, int, Ptr32<Item>, int);
extern "C" void fn_801ef380(Ptr32<Node>, int, int, int, int);
extern "C" int w3d_d29e_prune_children_801b1ed4(Ptr32<Second> base, Ptr32<Node> node) {
  Ptr32<Scanner> s = base ? w3d::R((Ptr32<Scanner>)((Ptr32<char>)base - 4)) : 0;
  unsigned char removed[64];
  unsigned k = 0;
  Ptr32<Array> a = node->items;
  unsigned n = a->count;
  Ptr32<Ptr32<Item>> items = a->items;
  unsigned i = 0;
  if (i < n) {
    Ptr32<Ptr32<Item>> p = items;
    do {
      Ptr32<Item> item = *p++;
      if (s->mark) { Item::Bits &b = item->bits; b.flags |= 1; }
      if (w3d_s10_has_ancestor_801b1de0(s, item->parent()) || w3d_k4b_scanner_has_missing_801b1e48(s, item)) {
        removed[k++] = i;
      } else if (item->bits.flags & 1) {
        w3d_k5b_iface_array_field_set_801ef2ec(node, 28, 3, s->factory->convert(item), i);
      }
      i++;
    } while (i < n);
  }
  for (unsigned j = 0; j < k; j++) fn_801ef380(node, 28, 3, removed[j] - j, 1);
  return 0;
}


