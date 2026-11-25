#include "w3d_ptr.h"
#line 1 "d29e_print_array_801ef970.cpp"
// (Worms 3D GameCube PAL, 0x801ef970).
//
// Writes the elements of the array property at the prop's offset in object:
// through the type's write slot if 0x801fff60 says it is a kind-three type,
// otherwise printing each element into a temporary string and writing that;
// elements are separated by the text at 0x803b0d60 plus an optional line
// break and indent, and printing stops with the text at 0x803b0d68 at the
// given limit. Names are inferred.

struct String;
extern "C" void w3d_string_assign(Ptr32<String>, Ptr32<const char>);
extern "C" void w3d_string_append(Ptr32<String>, Ptr32<const char>);
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

struct Writer;
struct TypeInfo {
  void w3d_r_a0() __asm__(W3D_SYM("_ZN8TypeInfo2a0Ev")); void w3d_r_a1() __asm__(W3D_SYM("_ZN8TypeInfo2a1Ev")); void w3d_r_a2() __asm__(W3D_SYM("_ZN8TypeInfo2a2Ev")); void w3d_r_a3() __asm__(W3D_SYM("_ZN8TypeInfo2a3Ev")); void w3d_r_a4() __asm__(W3D_SYM("_ZN8TypeInfo2a4Ev")); void w3d_r_a5() __asm__(W3D_SYM("_ZN8TypeInfo2a5Ev")); void w3d_r_a6() __asm__(W3D_SYM("_ZN8TypeInfo2a6Ev")); void w3d_r_a7() __asm__(W3D_SYM("_ZN8TypeInfo2a7Ev")); void w3d_r_a8() __asm__(W3D_SYM("_ZN8TypeInfo2a8Ev")); void w3d_r_a9() __asm__(W3D_SYM("_ZN8TypeInfo2a9Ev")); void w3d_r_a10() __asm__(W3D_SYM("_ZN8TypeInfo3a10Ev")); void w3d_r_a11() __asm__(W3D_SYM("_ZN8TypeInfo3a11Ev")); void w3d_r_a12() __asm__(W3D_SYM("_ZN8TypeInfo3a12Ev")); void w3d_r_a13() __asm__(W3D_SYM("_ZN8TypeInfo3a13Ev")); void w3d_r_a14() __asm__(W3D_SYM("_ZN8TypeInfo3a14Ev"));
  void w3d_r_print(String &, Ptr32<char>, int, int) __asm__(W3D_SYM("_ZN8TypeInfo5printER6StringPcii"));
  void w3d_r_a16() __asm__(W3D_SYM("_ZN8TypeInfo3a16Ev")); void w3d_r_a17() __asm__(W3D_SYM("_ZN8TypeInfo3a17Ev")); void w3d_r_a18() __asm__(W3D_SYM("_ZN8TypeInfo3a18Ev"));
  void w3d_r_write(Ptr32<Writer>, Ptr32<char>, int) __asm__(W3D_SYM("_ZN8TypeInfo5writeEP6WriterPci"));
 __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void print(String &w3d_a0, Ptr32<char> w3d_a1, int w3d_a2, int w3d_a3) { ((void (*)(w3d_u32, w3d_u32, Ptr32<char>, int, int))w3d::vfn(this->w3d_vptr_TypeInfo, 17))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0)), w3d_a1, w3d_a2, w3d_a3); }  __attribute__((always_inline)) inline void a16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeInfo, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void write(Ptr32<Writer> w3d_a0, Ptr32<char> w3d_a1, int w3d_a2) { ((void (*)(w3d_u32, Ptr32<Writer>, Ptr32<char>, int))w3d::vfn(this->w3d_vptr_TypeInfo, 21))(w3d::h2g(this), w3d_a0, w3d_a1, w3d_a2); }  Ptr32<void> w3d_vptr_TypeInfo; };
struct Prop { int p0; unsigned short offset; short p6; Ptr32<TypeInfo> type; };
struct PropRef { Ptr32<Prop> prop; };
struct Array { char p[24]; unsigned count; char q[4]; char data[1]; };
extern "C" int w3d_auto_80200050(Ptr32<TypeInfo>);
extern "C" int w3d_s21_kind_is_three_801fff60(Ptr32<TypeInfo>);
extern "C" Ptr32<Writer> w3d_s21_write_text_8020d82c(Ptr32<Writer>, const String &);
extern "C" Ptr32<Writer> w3d_cx8b_text_line_break_8020d5a8(Ptr32<Writer>);
extern "C" Ptr32<Writer> w3d_s21_write_text_8020dbf8(Ptr32<Writer>, Ptr32<const char>);
extern const char lbl_803b0d60[], lbl_803b0d68[];
extern "C" void w3d_d29e_print_array_801ef970(Ptr32<PropRef> self, Ptr32<Writer> w, Ptr32<char> object, unsigned limit, Ptr32<const char> indent) {
  if (!object) return;
  Ptr32<Array> a = *(Ptr32<Ptr32<Array>>)(object + self->prop->offset);
  unsigned n = a->count;
  Ptr32<char> p = a->data;
  int size = w3d_auto_80200050(self->prop->type);
  Ptr32<TypeInfo> printer = 0;
  if (w3d_s21_kind_is_three_801fff60(self->prop->type)) printer = self->prop->type;
  String s;
  unsigned i = 0;
  for (;;) {
  goto test;
next:
  if (printer) {
    printer->write(w, p, 0);
  } else {
    self->prop->type->print(s, p, 0, 0);
    w3d_s21_write_text_8020d82c(w, s);
  }
  p += size;
  if (i < n - 1) {
    w3d_s21_write_text_8020dbf8(w, lbl_803b0d60);
    if (indent) w3d_s21_write_text_8020dbf8(w3d_cx8b_text_line_break_8020d5a8(w), indent);
  }
  i++;
test:
  if (i < n) {
    if (i != limit) goto next;
    w3d_s21_write_text_8020dbf8(w, lbl_803b0d68);
  }
  break;
  }
}


