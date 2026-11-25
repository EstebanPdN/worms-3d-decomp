#include "w3d_ptr.h"
#line 1 "d30e_load_sample_801dd0e8.cpp"
// (Worms 3D GameCube PAL, 0x801dd0e8).
//
// Creates a sound sample object from a description: loads a .wav or .vag
// file by extension, or copies an already registered sample found by name
// when it reports ready; applies the description's fields through virtual
// slots 9 and 11 and setters at 0x801df1dc to 0x801df280, then appends it to
// the manager. Returns 0 or 0x80004005. Reference counted through a one-word
// holder. Names are inferred.

struct Obj { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Obj2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Obj6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Obj7ReleaseEv")); void w3d_r_v3() __asm__(W3D_SYM("_ZN3Obj2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN3Obj2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN3Obj2v5Ev")); int w3d_r_v32() __asm__(W3D_SYM("_ZN3Obj3v32Ev")); void w3d_r_v36(int) __asm__(W3D_SYM("_ZN3Obj3v36Ei")); void w3d_r_v8() __asm__(W3D_SYM("_ZN3Obj2v8Ev")); void w3d_r_v44(int) __asm__(W3D_SYM("_ZN3Obj3v44Ei"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int v32() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v36(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Obj, 9))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v44(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Obj, 11))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Obj; };
struct Ref {
  Ptr32<Obj> p;
  template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) { p = o; if (p) p->AddRef(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->Release(); }
};
struct Mgr;
struct Desc { int a; char q[8]; Ptr32<char> name; int count; int b; int c; float d, e, f, g, h; int i; int j; };
extern char lbl_8036564c[];
extern char lbl_803b0110[], lbl_803b0118[];

extern "C" Ptr32<char> strstr(Ptr32<const char>, Ptr32<const char>);
extern "C" Ptr32<Obj> w3d_r24b_invoke_ready_callback_8020fcb4(Ptr32<void>);
extern "C" int w3d_s21_has_name_801ddff4(Ptr32<Mgr>, Ptr32<char>);
extern "C" int w3d_s21_index_of_name_801de080(Ptr32<Mgr>, Ptr32<char>);
extern "C" Ptr32<Obj> w3d_s21_get_item_801de10c(Ptr32<Mgr>, int);
extern "C" int w3d_s21_copy_from_801df11c(Ptr32<Obj>, Ptr32<Obj>);
extern "C" int w3d_constant_801df10c(Ptr32<Obj>, Ptr32<char>, int);
extern "C" int w3d_constant_801df114(Ptr32<Obj>, Ptr32<char>);
extern "C" void w3d_set_801df234(Ptr32<Obj>, int);
extern "C" void w3d_set_801df1dc(Ptr32<Obj>, int);
extern "C" void w3d_setf_801df1fc(Ptr32<Obj>, float);
extern "C" void w3d_auto_801df1e4(Ptr32<Obj>, float, float);
extern "C" void w3d_setf_801df204(Ptr32<Obj>, float);
extern "C" void w3d_auto_801df1f0(Ptr32<Obj>, float, float);
extern "C" int w3d_auto_801df20c(Ptr32<Obj>, Ptr32<char>);
extern "C" void w3d_set_801df280(Ptr32<Obj>, int);
extern "C" int w3d_s21_append_ref_801ddf5c(Ptr32<Mgr>, Ptr32<Obj>);
extern "C" int w3d_d30e_load_sample_801dd0e8(Ptr32<void> self, Ptr32<Mgr> mgr, Ptr32<Desc> d) {
  Ref r(w3d_r24b_invoke_ready_callback_8020fcb4(lbl_8036564c));
  if (!strstr(d->name, lbl_803b0110) && !strstr(d->name, lbl_803b0118)) {
    if (!w3d_s21_has_name_801ddff4(mgr, d->name)) return 0x80004005;
    Ref t(w3d_s21_get_item_801de10c(mgr, w3d_s21_index_of_name_801de080(mgr, d->name)));
    if (!t.p->v32()) return 0x80004005;
    w3d_s21_copy_from_801df11c(r.p, t.p);
  } else if (strstr(d->name, lbl_803b0110)) {
    if (!w3d_constant_801df10c(r.p, d->name, d->i)) return 0x80004005;
  } else if (strstr(d->name, lbl_803b0118)) {
    if (!w3d_constant_801df114(r.p, d->name)) return 0x80004005;
  }
  r.p->v36(d->a);
  if (d->count > 0) w3d_set_801df234(r.p, d->count);
  r.p->v44(d->b);
  w3d_set_801df1dc(r.p, d->c);
  w3d_setf_801df1fc(r.p, d->d);
  w3d_auto_801df1e4(r.p, d->e, 0.0f);
  w3d_setf_801df204(r.p, d->f);
  w3d_auto_801df1f0(r.p, d->g, d->h);
  w3d_auto_801df20c(r.p, d->name);
  w3d_set_801df280(r.p, d->j);
  if (!w3d_s21_append_ref_801ddf5c(mgr, r.p)) return 0x80004005;
  return 0;
}


