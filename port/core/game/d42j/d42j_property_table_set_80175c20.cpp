#include "w3d_ptr.h"
#line 1 "d42j_property_table_set_80175c20.cpp"
// Adds or updates a named member of a property table: an existing entry of kind 5 is checked against the
// requested key and flags and its target replaced or cleared; otherwise a new member is created and bound.
// Field and method names are inferred from the callees.
struct Type;
extern "C" Ptr32<Type> w3d_auto_801fff3c(int);
struct IVal {
  void w3d_r_a0() __asm__(W3D_SYM("_ZN4IVal2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN4IVal3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN4IVal7releaseEv")); int w3d_r_id() __asm__(W3D_SYM("_ZN4IVal2idEv"));
 __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int id() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_IVal; };
struct Val : IVal { unsigned short used __attribute__((aligned(__alignof__(IVal)))); };
struct Desc {
  int a; int b;
  Desc(int x) { a = x; b = 58280; }
  ~Desc();
};
extern "C" void w3d_s20_destroy_owned_80178474(Ptr32<Desc>, int);
inline Desc::~Desc() { w3d_s20_destroy_owned_80178474(this, 2); }
struct Prop;
struct Member : Val {
  int w3d_r_kind() __asm__(W3D_SYM("_ZN6Member4kindEv")); void w3d_r_a5() __asm__(W3D_SYM("_ZN6Member2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN6Member2a6Ev")); int w3d_r_key() __asm__(W3D_SYM("_ZN6Member3keyEv"));
  void w3d_r_a8() __asm__(W3D_SYM("_ZN6Member2a8Ev")); void w3d_r_setA(int) __asm__(W3D_SYM("_ZN6Member4setAEi")); void w3d_r_setB(int) __asm__(W3D_SYM("_ZN6Member4setBEi")); void w3d_r_setC(int) __asm__(W3D_SYM("_ZN6Member4setCEi"));
 __attribute__((always_inline)) inline int kind() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int key() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_IVal, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setA(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_IVal, 11))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void setB(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_IVal, 12))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void setC(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_IVal, 13))(w3d::h2g(this), w3d_a0); } };
extern "C" {
Ptr32<Member> w3d_empty_80341584(Ptr32<Member>);
void w3d_s20_clear_target_80179770(Ptr32<Member>);
Ptr32<Val> w3d_auto_801797b4(Ptr32<Member>);
void w3d_s20_replace_target_801795d4(Ptr32<Member>, Ptr32<Val>);
int cc42a_bind_typed_8017963c(Ptr32<Member>, Ptr32<Type>);
Ptr32<Prop> w3d_auto_80179598(Ptr32<Member>, Ptr32<Desc>);
void f3c_propagate_tag_801ea4c8(Ptr32<Prop>, Ptr32<Val>);
Ptr32<void> w3d_heap_allocate_entry_a(unsigned int);
Ptr32<Member> s9_beam_80179428(Ptr32<void>);
}
struct MRef { Ptr32<Member> p; Ptr32<Member> operator->() { return p; } void set(Ptr32<Member> q) { if (q) q->add(); if (p) p->release(); p = q; } };
struct Loc { unsigned short idx; Loc() {} Loc(const Loc &); };
struct Self { char p0[24]; Ptr32<MRef> table; char p1c[2064]; int freeSlots; };
extern "C" int d24j_find_table_slot_80177eb0(Ptr32<Self>, int, Ptr32<Loc>);
extern int lbl_804ab5b0;
extern "C" int property_table_set_80175c20(Ptr32<Self> self, int key, Ptr32<Val> val, int b, int flags) {
  Loc loc;
  if (d24j_find_table_slot_80177eb0(self, key, &loc) >= 0) {
    if (self->table[loc.idx]->kind() != 5) goto bad;
    {
      Ptr32<Member> m;
      if (flags & 4) b = self->table[loc.idx]->key();
      if (self->table[loc.idx]->key() != b) goto bad;
      if (flags & 1) {
        m = w3d_empty_80341584(self->table[loc.idx].p);
        if (val == 0) { w3d_s20_clear_target_80179770(m); return 0; }
        if (flags) {
          if (w3d_auto_801797b4(m) && w3d_auto_801797b4(m)->id() != val->id()) return 0x80004005;
          w3d_s20_replace_target_801795d4(m, val);
          return 0;
        }
        if (w3d_auto_801797b4(m) == 0) cc42a_bind_typed_8017963c(m, w3d_auto_801fff3c(val->id()));
        if (w3d_auto_801797b4(m)->id() != val->id()) {
        bad:
          return 0x80004005;
        }
        Desc d(flags);
        f3c_propagate_tag_801ea4c8(w3d_auto_80179598(m, &d), val);
        return 0;
      }
    }
    goto bad;
  }
  Ptr32<Member> m = s9_beam_80179428(w3d_heap_allocate_entry_a(20));
  self->table[loc.idx].set(m);
  m->setA(key);
  m->setB(b);
  m->setC(flags);
  self->freeSlots--;
  lbl_804ab5b0++;
  if (val) {
    cc42a_bind_typed_8017963c(m, w3d_auto_801fff3c(val->id()));
    Desc d(0);
    f3c_propagate_tag_801ea4c8(w3d_auto_80179598(m, &d), val);
    if (val->used == 0) { val->add(); val->release(); }
  }
  return 0;
}


