#include "w3d_ptr.h"
#line 1 "d31j_add_named_target_80179b24.cpp"
// Adds a target to an animation container: optionally builds a named template
// with sub-objects, pushes them into three compact arrays, appends the item and
// updates the new target. GWMP8P rev0 0x80179b24.
extern "C" {
Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
void w3d_k5b_iface_array_field_append_801ef174(Ptr32<void>, int, int, Ptr32<void>);
Ptr32<void> w3d_handle_storage_allocate(unsigned int);
void w3d_handle_storage_release(Ptr32<void>);
Ptr32<void> memcpy_802eee50(Ptr32<void>, Ptr32<const void>, unsigned int, ...);
}
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
  Ptr32<T> start; Ptr32<T> finish; Ptr32<T> storage_end;
  int size() const { return finish - start; }
  void grow() {
    unsigned int used = (Ptr32<char>)finish - (Ptr32<char>)start;
    int a = used + 1, b = used + (used >> 1);
    unsigned int bytes = Max(a, b) * 4;
    Ptr32<T> p = (Ptr32<T>)w3d_handle_storage_allocate(bytes);
    if (start) {
      memcpy_802eee50(p, start, Min(bytes, used));
      w3d_handle_storage_release(start);
    }
    start = p; finish = (Ptr32<T>)((Ptr32<char>)p + used); storage_end = (Ptr32<T>)((Ptr32<char>)p + bytes);
  }
  void push_back(const T &v) {
    if (finish == storage_end) grow();
    *finish = v;
    finish++;
  }
};
struct SlotsA { unsigned n; int cap; Ptr32<Ptr32<Iface>> d; };
struct SlotsB { unsigned n; int cap; Ptr32<Ptr32<Iface>> d; };
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(Ptr32<SlotsA>, unsigned);
extern "C" void w3d_k5b_task_pool_reserve_801f29d0(Ptr32<SlotsB>, unsigned);
struct Self;
struct Item : Iface { void w3d_r_attach(Ptr32<Self>) __asm__(W3D_SYM("_ZN4Item6attachEP4Self"));  __attribute__((always_inline)) inline void attach(Ptr32<Self> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Self>))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this), w3d_a0); } };
struct Tmpl : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN4Tmpl2a3Ev")); int w3d_r_bind(Ptr32<Iface>) __asm__(W3D_SYM("_ZN4Tmpl4bindEP5Iface")); void w3d_r_a5() __asm__(W3D_SYM("_ZN4Tmpl2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN4Tmpl2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN4Tmpl2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN4Tmpl2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN4Tmpl2a9Ev")); void w3d_r_setName(Ptr32<const char>) __asm__(W3D_SYM("_ZN4Tmpl7setNameEPKc")); Ptr32<Iface> w3d_r_sub() __asm__(W3D_SYM("_ZN4Tmpl3subEv"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int bind(Ptr32<Iface> w3d_a0) { return ((int (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void setName(Ptr32<const char> w3d_a0) { ((void (*)(w3d_u32, Ptr32<const char>))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline Ptr32<Iface> sub() { return ((Ptr32<Iface> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); } };
struct Mgr : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN3Mgr2a3Ev")); void w3d_r_a24(Ptr32<Iface>) __asm__(W3D_SYM("_ZN3Mgr3a24EP5Iface")); void w3d_r_a5() __asm__(W3D_SYM("_ZN3Mgr2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN3Mgr2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN3Mgr2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN3Mgr2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN3Mgr2a9Ev")); void w3d_r_a48(Ptr32<Iface>) __asm__(W3D_SYM("_ZN3Mgr3a48EP5Iface"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a24(Ptr32<Iface> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a48(Ptr32<Iface> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Iface>))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this), w3d_a0); } };
struct Self { char p0[104]; Array <Ptr32<Item> > items; char p74[4]; Ptr32<Iface> r120; char p7c[4]; SlotsA a; SlotsB b; SlotsB c; };
extern Ptr32<Mgr> lbl_804b0160;
extern "C" void d25j_update_one_target_8017a07c(Ptr32<Self>, int);
extern char lbl_804164c0[], lbl_804163f8[], lbl_80414a40[];
extern "C" int d31j_add_named_target_80179b24(Ptr32<Self> self, Ptr32<Item> item, Ptr32<const char> name) {
  if (name && *name) {
    Ref<Tmpl> t((Ptr32<Tmpl>)w3d_s10_service_forward_8020b680(lbl_804164c0));
    t->setName(name);
    if (t->bind(self->r120) < 0) return 0x80004005;
    Ref<Iface> u((Ptr32<Iface>)w3d_s10_service_forward_8020b680(lbl_804163f8));
    Ref<Iface> v((Ptr32<Iface>)w3d_s10_service_forward_8020b680(lbl_80414a40));
    Ref<Iface> w(t->sub());
  {
    Ptr32<Iface> q = u.p;
    SlotsA &sl = self->a;
    w3d_cx11b_compact_vector_grow_80210d54(&sl, self->a.n + 1);
    
    Ptr32<Iface> &slot = *(Ptr32<Ptr32<Iface>>)w3d::G((self->a.n * 4 + (int)w3d::H(sl.d)));
    if (q) q->add();
    if (slot) slot->release();
    slot = q;
    self->a.n++;
  }
  {
    Ptr32<Iface> q = v.p;
    SlotsB &sl = self->b;
    w3d_k5b_task_pool_reserve_801f29d0(&sl, self->b.n + 1);
    
    Ptr32<Iface> &slot = *(Ptr32<Ptr32<Iface>>)w3d::G((self->b.n * 4 + (int)w3d::H(sl.d)));
    if (q) q->add();
    if (slot) slot->release();
    slot = q;
    self->b.n++;
  }
  {
    Ptr32<Iface> q = w.p;
    SlotsB &sl = self->c;
    w3d_k5b_task_pool_reserve_801f29d0(&sl, self->c.n + 1);
    
    Ptr32<Iface> &slot = *(Ptr32<Ptr32<Iface>>)w3d::G((self->c.n * 4 + (int)w3d::H(sl.d)));
    if (q) q->add();
    if (slot) slot->release();
    slot = q;
    self->c.n++;
  }
    w3d_k5b_iface_array_field_append_801ef174(w.p, 44, 3, v.p);
    lbl_804b0160->a48(u.p);
    lbl_804b0160->a24(self->r120);
    lbl_804b0160->a48(0);
  } else {
  {
    Ptr32<Iface> q = 0;
    SlotsA &sl = self->a;
    w3d_cx11b_compact_vector_grow_80210d54(&sl, self->a.n + 1);
    
    Ptr32<Iface> &slot = *(Ptr32<Ptr32<Iface>>)w3d::G((self->a.n * 4 + (int)w3d::H(sl.d)));
    
    if (slot) slot->release();
    slot = q;
    self->a.n++;
  }
  {
    Ptr32<Iface> q = 0;
    SlotsB &sl = self->b;
    w3d_k5b_task_pool_reserve_801f29d0(&sl, self->b.n + 1);
    
    Ptr32<Iface> &slot = *(Ptr32<Ptr32<Iface>>)w3d::G((self->b.n * 4 + (int)w3d::H(sl.d)));
    
    if (slot) slot->release();
    slot = q;
    self->b.n++;
  }
  {
    Ptr32<Iface> q = 0;
    SlotsB &sl = self->c;
    w3d_k5b_task_pool_reserve_801f29d0(&sl, self->c.n + 1);
    
    Ptr32<Iface> &slot = *(Ptr32<Ptr32<Iface>>)w3d::G((self->c.n * 4 + (int)w3d::H(sl.d)));
    
    if (slot) slot->release();
    slot = q;
    self->c.n++;
  }
  }
  self->items.push_back(item);
  item->attach(self);
  d25j_update_one_target_8017a07c(self, self->items.size() - 1);
  return 0;
}


