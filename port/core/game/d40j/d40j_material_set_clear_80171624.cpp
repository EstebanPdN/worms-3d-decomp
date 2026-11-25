#include "w3d_ptr.h"
#line 1 "d40j_material_set_clear_80171624.cpp"
// Material set reset (Worms 3D GameCube PAL, 0x80171624): clears flag 0x8000, and for
// each key removes the selected part from the owner's array field through
// 0x801ef380, clears both compact arrays, frees the entries' storage, empties the
// key array and releases the shared interface. Returns 0. Names are inferred.
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
  void clear(Ptr32<T> q) { if (p) p->release(); p = q; }
};
struct List { char p0[24]; unsigned int count; char p1c[4]; Ptr32<Iface> data[1]; };
struct Owner : Iface { char p4[40] __attribute__((aligned(__alignof__(Iface)))); Ptr32<List> list; };
extern "C" {
void fn_801ef380(Ptr32<Owner>, int, int, unsigned int, int);
Ptr32<Iface> w3d_s20_get_selected_80172088(Ptr32<void>, unsigned char);
void w3d_task_deferred_clear(Ptr32<void>);
void w3d_handle_storage_release(Ptr32<void>);
Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, ...);
}
struct Holder { char p0[20]; Ptr32<Owner> owner; };
struct Mgr { void w3d_r_a0() __asm__(W3D_SYM("_ZN3Mgr2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN3Mgr3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN3Mgr7releaseEv")); void w3d_r_s20() __asm__(W3D_SYM("_ZN3Mgr3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN3Mgr3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN3Mgr3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN3Mgr3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN3Mgr3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN3Mgr3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN3Mgr3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN3Mgr3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN3Mgr3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN3Mgr3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN3Mgr3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN3Mgr3s64Ev")); void w3d_r_s68() __asm__(W3D_SYM("_ZN3Mgr3s68Ev")); void w3d_r_s72() __asm__(W3D_SYM("_ZN3Mgr3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN3Mgr3s76Ev")); void w3d_r_s80() __asm__(W3D_SYM("_ZN3Mgr3s80Ev")); void w3d_r_s84() __asm__(W3D_SYM("_ZN3Mgr3s84Ev")); void w3d_r_s88() __asm__(W3D_SYM("_ZN3Mgr3s88Ev")); void w3d_r_s92() __asm__(W3D_SYM("_ZN3Mgr3s92Ev")); void w3d_r_s96() __asm__(W3D_SYM("_ZN3Mgr3s96Ev")); void w3d_r_s100() __asm__(W3D_SYM("_ZN3Mgr4s100Ev")); void w3d_r_s104() __asm__(W3D_SYM("_ZN3Mgr4s104Ev")); void w3d_r_s108() __asm__(W3D_SYM("_ZN3Mgr4s108Ev")); void w3d_r_s112() __asm__(W3D_SYM("_ZN3Mgr4s112Ev")); Ptr32<Holder> w3d_r_find(Ptr32<unsigned char>) __asm__(W3D_SYM("_ZN3Mgr4findEPh"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s80() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s96() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s100() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s104() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s108() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s112() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Mgr, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Holder> find(Ptr32<unsigned char> w3d_a0) { return ((Ptr32<Holder> (*)(w3d_u32, Ptr32<unsigned char>))w3d::vfn(this->w3d_vptr_Mgr, 29))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Mgr; };
extern Ptr32<Mgr> lbl_804ab5fc;
struct Slot { Ptr32<void> data; char p4[12]; };
struct Cfg { Ptr32<Slot> start; Ptr32<Slot> finish; char p8[8]; Ptr32<unsigned char> ids; Ptr32<unsigned char> ids_end; };
struct Self { char p0[24]; int flags; char p1c[24]; char v52[12]; char v64[12]; Ref<Iface> ref76; Ptr32<Cfg> cfg; };
extern "C" int w3d_d40j_material_set_clear_80171624(Ptr32<Self> self) {
  self->flags &= ~0x8000;
  Ptr32<unsigned char> i = self->cfg->ids;
  if (i != self->cfg->ids_end) {
    do {
      Ref<Owner> a(lbl_804ab5fc->find(i)->owner);
      Ptr32<List> l = a->list;
      unsigned int n = l->count;
      Ptr32<Ptr32<Iface>> d = l->data;
      {
        Ref<Iface> b(w3d_s20_get_selected_80172088(self, *i));
        unsigned int k = 0;
        for (; k < n; k++) {
          if (*(Ptr32<Ptr32<Iface>>)((Ptr32<char>)d + (k << 2)) == b.p) {
            fn_801ef380(a.p, 44, 3, k, 1);
            break;
          }
        }
        i++;
      }
    } while (i != self->cfg->ids_end);
  }
  w3d_task_deferred_clear(self->v52);
  w3d_task_deferred_clear(self->v64);
  {
    Ptr32<Cfg> c = self->cfg;
    Ptr32<Slot> s = c->start;
    Ptr32<Slot> e = c->finish;
    for (Ptr32<Slot> p = s; p != e; p++) if (p->data) w3d_handle_storage_release(p->data);
    c->finish = s;
  }
  {
    Ptr32<unsigned char> &fs = self->cfg->ids;
    Ptr32<unsigned char> b = fs;
    Ptr32<unsigned char> e = (&fs)[1];
    int cnt = e - b;
    fn_802eee50(b, e, 0);
    (&fs)[1] -= cnt;
  }
  self->ref76.clear(0);
  return 0;
}


