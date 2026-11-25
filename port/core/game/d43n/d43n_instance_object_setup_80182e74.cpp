#include "w3d_ptr.h"
#line 1 "d43n_instance_object_setup_80182e74.cpp"
// GWMP8P rev0 0x80182e74. Sets up an instance object: base init, service-
// fetched instance and texture, a name built from 'Instance-' and the item's
// text, default colour vectors, stored item, registry append. Names are
// inferred from use.
struct Src;
extern "C" {
Ptr32<void> w3d_s10_service_forward_8020b680(Ptr32<void>);
int w3d_auto_80179aec(Ptr32<void>, Ptr32<void>, unsigned char);
Ptr32<char> strcat(Ptr32<char>, Ptr32<const char>);
Ptr32<char> strcpy(Ptr32<char>, Ptr32<const char>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
void w3d_string_release_header(Ptr32<void>);
Ptr32<void> w3d_empty_8034cc30(Ptr32<void>);
struct Geo;
Ptr32<Geo> w3d_s21_fetch_801ea470(Ptr32<void>);
void w3d_k5b_iface_array_field_append_801ef174(Ptr32<void>, int, int, Ptr32<void>);
}
struct Iface { void w3d_r_a0() __asm__(W3D_SYM("_ZN5Iface2a0Ev")); void w3d_r_add() __asm__(W3D_SYM("_ZN5Iface3addEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Iface7releaseEv"));  __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void add() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
template <class T> struct Ref {
  Ptr32<T> p;
  Ref() { p = 0; }
  template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Ptr32<T> operator->() { return p; }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((T *)w3d_p.get()); }
 Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
  Ref &operator=(const Ref &o) { Ptr32<T> old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct String_8020bb54 {
  Ptr32<char> p;
  template <class W3dU> String_8020bb54(Ptr32<W3dU> w3d_p) : String_8020bb54((const char *)w3d_p.get()) {}
 String_8020bb54(const char *);
  String_8020bb54(const String_8020bb54 &);
  ~String_8020bb54() { w3d_string_base_finish(this); w3d_string_release(this); }
  String_8020bb54 &operator=(const String_8020bb54 &o) {
    ++*(Ptr32<unsigned short>)(o.p - 6);
    Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
struct Vec { float x, y, z; void set(float f) { x = f; y = f; z = f; } };
struct Bits { char p0[4]; unsigned char flags; char w3d_tag_rest[3]; void mark() { flags |= 2; } };
struct Tex : Iface {
  Bits bits __attribute__((aligned(__alignof__(Iface)))); char pc[60];
  Vec a; Vec b; Vec c;
  void setA(const Vec &v) { a = v; bits.mark(); }
  void setB(const Vec &v) { b = v; bits.mark(); }
  void setC(const Vec &v) { c = v; bits.mark(); }
};
struct Inst : Iface { char p4[32] __attribute__((aligned(__alignof__(Iface)))); String_8020bb54 name; char p28[8]; Ref<Tex> tex; };
struct Item : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN4Item2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN4Item2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN4Item2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN4Item2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN4Item2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN4Item2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN4Item2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN4Item3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN4Item3a11Ev")); void w3d_r_a12() __asm__(W3D_SYM("_ZN4Item3a12Ev")); void w3d_r_a13() __asm__(W3D_SYM("_ZN4Item3a13Ev")); void w3d_r_a14() __asm__(W3D_SYM("_ZN4Item3a14Ev")); const String_8020bb54 &w3d_r_text() __asm__(W3D_SYM("_ZN4Item4textEv"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline const String_8020bb54 &text() { return *(const String_8020bb54 *)w3d::g2h(((w3d_u32 (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this))); } };
struct Holder { char p0[20]; Ptr32<Iface> value; };
struct Reg : Iface { void w3d_r_a3() __asm__(W3D_SYM("_ZN3Reg2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN3Reg2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN3Reg2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN3Reg2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN3Reg2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN3Reg2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN3Reg2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN3Reg3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN3Reg3a11Ev")); void w3d_r_a12() __asm__(W3D_SYM("_ZN3Reg3a12Ev")); void w3d_r_a13() __asm__(W3D_SYM("_ZN3Reg3a13Ev")); void w3d_r_a14() __asm__(W3D_SYM("_ZN3Reg3a14Ev")); void w3d_r_a15() __asm__(W3D_SYM("_ZN3Reg3a15Ev")); void w3d_r_a16() __asm__(W3D_SYM("_ZN3Reg3a16Ev")); void w3d_r_a17() __asm__(W3D_SYM("_ZN3Reg3a17Ev")); void w3d_r_a18() __asm__(W3D_SYM("_ZN3Reg3a18Ev")); void w3d_r_a19() __asm__(W3D_SYM("_ZN3Reg3a19Ev")); void w3d_r_a20() __asm__(W3D_SYM("_ZN3Reg3a20Ev")); void w3d_r_a21() __asm__(W3D_SYM("_ZN3Reg3a21Ev")); void w3d_r_a22() __asm__(W3D_SYM("_ZN3Reg3a22Ev")); void w3d_r_a23() __asm__(W3D_SYM("_ZN3Reg3a23Ev")); void w3d_r_a24() __asm__(W3D_SYM("_ZN3Reg3a24Ev")); void w3d_r_a25() __asm__(W3D_SYM("_ZN3Reg3a25Ev")); void w3d_r_a26() __asm__(W3D_SYM("_ZN3Reg3a26Ev")); Ptr32<Holder> w3d_r_find(Ptr32<unsigned char>) __asm__(W3D_SYM("_ZN3Reg4findEPh"));  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a23() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a25() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Holder> find(Ptr32<unsigned char> w3d_a0) { return ((Ptr32<Holder> (*)(w3d_u32, Ptr32<unsigned char>))w3d::vfn(this->w3d_vptr_Iface, 29))(w3d::h2g(this), w3d_a0); } };
extern Ptr32<Reg> lbl_804ab5fc;
extern int lbl_804ab650;
extern char lbl_804144f8[], lbl_80414940[], lbl_80414600[];
extern "C" Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, ...);
struct Blob { char p0[4]; unsigned short kind; char p6[18]; int count; unsigned short locks; char p1e[2]; char data[1]; };
struct Handle;
extern "C" Ptr32<void> w3d_k5b_array_ref_lock_801ef048(Ptr32<Handle>, int, int, int);
struct Handle {
  Ptr32<Blob> b;
  Ptr32<void> lock(int count, int stride, unsigned fl) {
    Ptr32<Blob> x = b;
    unsigned flags = fl; int size; if (flags & 2) size = x->count + count; else size = count;
    if (x->kind == 1 && size == x->count) { x->locks++; return x->data; }
    return w3d_k5b_array_ref_lock_801ef048(this, size, stride, flags);
  }
};
struct Geo;
struct Src { char p0[44]; Ptr32<Geo> shape; };
struct Mod : Iface { char p4[80] __attribute__((aligned(__alignof__(Iface)))); unsigned char blend; };
struct Geo : Iface { char p4[32] __attribute__((aligned(__alignof__(Iface)))); Handle uv; Handle st; char p2c[4]; Ref<Iface> sp; Ref<Geo> next; };
struct Clr { Ptr32<char> a; Ptr32<char> b; };
struct Self {
  Ptr32<void> vt; int p4; int flags; Vec c; Vec b; Vec a; int p30; char p34[64]; Ref<Iface> item; Ref<Inst> inst; char p7c[44]; int on; int count;
};
extern "C" int w3d_d43n_instance_object_setup_80182e74(Ptr32<Self> self, Ptr32<Item> item, unsigned char kind) {
  int hr = w3d_auto_80179aec(self, item, kind);
  if (hr < 0) return hr;
  self->inst = (Ptr32<Inst>)w3d_s10_service_forward_8020b680(lbl_804144f8);
  Ref<Tex> tex((Ptr32<Tex>)w3d_s10_service_forward_8020b680(lbl_80414940));
  int one = 1;
  char name[256];
  strcpy(name, "Instance-");
  strcat(name, item->text().p);
  self->inst->name = String_8020bb54(name);
  self->a.set(1.0f);
  self->c.set(0.0f);
  self->b.set(0.0f);
  tex->setA(self->a);
  tex->setC(self->c);
  tex->setB(self->b);
  self->inst->tex = tex;
  self->item = item;
  w3d_empty_8034cc30(item);
  {
    Ref<Iface> reg(lbl_804ab5fc->find(&kind)->value);
    w3d_k5b_iface_array_field_append_801ef174(reg.p, 44, 3, self->inst.p);
    self->flags |= 1;
    self->p30 = 0;
    self->on = one;
    self->count = 0;
    lbl_804ab650++;
  }
  return 0;
}


