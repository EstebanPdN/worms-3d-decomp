#include "w3d_ptr.h"
#line 1 "d29e_print_fields_80200494.cpp"
// (Worms 3D GameCube PAL, 0x80200494).
//
// Formats an object as text: if the global service (0x804b063c) knows the
// type it prints it (slots 3 and 4); otherwise assigns the opening text to
// out, gets the type's field table from 0x80200460 and for each of its count
// fields (byte at +17, 12-byte records at +28) has the field's printer (slot
// 15) write the field value into a temporary string, appends a separator or
// the closing text, formats name and value into a line and appends it.
// Returns 0. Names are inferred.

struct String;
extern "C" Ptr32<String> w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" Ptr32<String> w3d_string_append(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
struct String {
  Ptr32<char> p;
  String();
  template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
  String(const String &);
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};

struct Field {
  Ptr32<const char> name;
  unsigned short pad;
  unsigned short offset;
  Ptr32<struct Ops> ops;
};
struct Ops {
  void w3d_r_a0() __asm__(W3D_SYM("_ZN3Ops2a0Ev")); void w3d_r_a1() __asm__(W3D_SYM("_ZN3Ops2a1Ev")); void w3d_r_a2() __asm__(W3D_SYM("_ZN3Ops2a2Ev")); void w3d_r_a3() __asm__(W3D_SYM("_ZN3Ops2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN3Ops2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN3Ops2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN3Ops2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN3Ops2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN3Ops2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN3Ops2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN3Ops3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN3Ops3a11Ev")); void w3d_r_a12() __asm__(W3D_SYM("_ZN3Ops3a12Ev")); void w3d_r_a13() __asm__(W3D_SYM("_ZN3Ops3a13Ev")); void w3d_r_a14() __asm__(W3D_SYM("_ZN3Ops3a14Ev"));void w3d_r_print(String &, Ptr32<void>, Ptr32<void>, int) __asm__(W3D_SYM("_ZN3Ops5printER6StringPvS2_i"));
 __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Ops, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void print(String &w3d_a0, Ptr32<void> w3d_a1, Ptr32<void> w3d_a2, int w3d_a3) { ((void (*)(w3d_u32, w3d_u32, Ptr32<void>, Ptr32<void>, int))w3d::vfn(this->w3d_vptr_Ops, 17))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0)), w3d_a1, w3d_a2, w3d_a3); }  Ptr32<void> w3d_vptr_Ops; };
struct Type { char p[17]; unsigned char count; char q[10]; Ptr32<Field> fields; };
struct Service {
  void w3d_r_v0() __asm__(W3D_SYM("_ZN7Service2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN7Service2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN7Service2v2Ev"));
  int w3d_r_has(Ptr32<void>, Ptr32<void>) __asm__(W3D_SYM("_ZN7Service3hasEPvS0_"));
  int w3d_r_print(Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>) __asm__(W3D_SYM("_ZN7Service5printEPvS0_S0_S0_"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int has(Ptr32<void> w3d_a0, Ptr32<void> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Service, 5))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int print(Ptr32<void> w3d_a0, Ptr32<void> w3d_a1, Ptr32<void> w3d_a2, Ptr32<void> w3d_a3) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<void>))w3d::vfn(this->w3d_vptr_Service, 6))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2, w3d_a3); }  Ptr32<void> w3d_vptr_Service; };
extern Ptr32<Service> lbl_804b063c;
extern char lbl_8045ed94[];
extern "C" Ptr32<Type> w3d_forward_virtual_80200460(Ptr32<void>);
extern const char lbl_803b2a68[], lbl_803b2a6c[], lbl_803b2a70[], lbl_803b2a74[];
extern "C" int w3d_d29e_print_fields_80200494(Ptr32<void> type, Ptr32<String> out, Ptr32<char> data, Ptr32<void> ctx) {
  if (lbl_804b063c->has(type, lbl_8045ed94))
    return lbl_804b063c->print(data, type, out, lbl_8045ed94);
  String text;
  unsigned i = 0;
  w3d_string_assign(out, lbl_803b2a68);
  Ptr32<Type> t = w3d_forward_virtual_80200460(type);
  unsigned n = t->count;
  while (i < n) {
    Field &fd = t->fields[i];
    fd.ops->print(text, data + fd.offset, ctx, 0);
    if ((int)(i + 1) != (int)n) w3d_string_append(&text, lbl_803b2a6c); else w3d_string_append(&text, lbl_803b2a70); String line; i++;
    w3d_string_format(&line, lbl_803b2a74, w3d::VA(fd.name), w3d::VA(text.p));
    w3d_string_append(out, line.p);
  }
  return 0;
}


