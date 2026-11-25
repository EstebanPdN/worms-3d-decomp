#include "w3d_ptr.h"
#line 1 "d30e_read_entries_801aecf0.cpp"
// (Worms 3D GameCube PAL, 0x801aecf0).
//
// Reads the entry list from a reader: gets the count through slot 40,
// reserves the vector at +20, then for each entry reads its identifier
// (Type), object (Graph) and name (Name) through slots 36, 6 and 35 and
// appends it with unmodified STLport push_back. Returns the last result; a
// failure stops at once. Names are inferred.

#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
struct String {
  Ptr32<char> p;
  String();
  template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
  String(const String &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &);
};

struct Guid { int w0, w1, w2, w3; };
struct Entry { Ptr32<void> obj; Guid id; String name;
  Entry() { obj = 0; }
  Entry &operator=(const Entry &);
};
extern char lbl_803aa754[], lbl_803aa75c[], lbl_803aa764[];
struct Reader { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Reader2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN6Reader2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN6Reader2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN6Reader2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN6Reader2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN6Reader2v5Ev")); int w3d_r_graph(Ptr32<void>, Ptr32<const char>) __asm__(W3D_SYM("_ZN6Reader5graphEPvPKc")); void w3d_r_v7() __asm__(W3D_SYM("_ZN6Reader2v7Ev")),w3d_r_v8() __asm__(W3D_SYM("_ZN6Reader2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN6Reader2v9Ev")),w3d_r_v10() __asm__(W3D_SYM("_ZN6Reader3v10Ev")),w3d_r_v11() __asm__(W3D_SYM("_ZN6Reader3v11Ev")),w3d_r_v12() __asm__(W3D_SYM("_ZN6Reader3v12Ev")),w3d_r_v13() __asm__(W3D_SYM("_ZN6Reader3v13Ev")),w3d_r_v14() __asm__(W3D_SYM("_ZN6Reader3v14Ev")),w3d_r_v15() __asm__(W3D_SYM("_ZN6Reader3v15Ev")),w3d_r_v16() __asm__(W3D_SYM("_ZN6Reader3v16Ev")),w3d_r_v17() __asm__(W3D_SYM("_ZN6Reader3v17Ev")),w3d_r_v18() __asm__(W3D_SYM("_ZN6Reader3v18Ev")),w3d_r_v19() __asm__(W3D_SYM("_ZN6Reader3v19Ev")),w3d_r_v20() __asm__(W3D_SYM("_ZN6Reader3v20Ev")),w3d_r_v21() __asm__(W3D_SYM("_ZN6Reader3v21Ev")),w3d_r_v22() __asm__(W3D_SYM("_ZN6Reader3v22Ev")),w3d_r_v23() __asm__(W3D_SYM("_ZN6Reader3v23Ev")),w3d_r_v24() __asm__(W3D_SYM("_ZN6Reader3v24Ev")),w3d_r_v25() __asm__(W3D_SYM("_ZN6Reader3v25Ev")),w3d_r_v26() __asm__(W3D_SYM("_ZN6Reader3v26Ev")),w3d_r_v27() __asm__(W3D_SYM("_ZN6Reader3v27Ev")),w3d_r_v28() __asm__(W3D_SYM("_ZN6Reader3v28Ev")),w3d_r_v29() __asm__(W3D_SYM("_ZN6Reader3v29Ev")),w3d_r_v30() __asm__(W3D_SYM("_ZN6Reader3v30Ev")),w3d_r_v31() __asm__(W3D_SYM("_ZN6Reader3v31Ev")),w3d_r_v32() __asm__(W3D_SYM("_ZN6Reader3v32Ev")),w3d_r_v33() __asm__(W3D_SYM("_ZN6Reader3v33Ev")),w3d_r_v34() __asm__(W3D_SYM("_ZN6Reader3v34Ev")); int w3d_r_name(Ptr32<String>, Ptr32<const char>) __asm__(W3D_SYM("_ZN6Reader4nameEP6StringPKc")); int w3d_r_guid(Ptr32<Guid>, Ptr32<const char>) __asm__(W3D_SYM("_ZN6Reader4guidEP4GuidPKc")); void w3d_r_v37() __asm__(W3D_SYM("_ZN6Reader3v37Ev")),w3d_r_v38() __asm__(W3D_SYM("_ZN6Reader3v38Ev")),w3d_r_v39() __asm__(W3D_SYM("_ZN6Reader3v39Ev")); int w3d_r_count(Ptr32<unsigned int>, Ptr32<const char>) __asm__(W3D_SYM("_ZN6Reader5countEPjPKc"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int graph(Ptr32<void> w3d_a0, Ptr32<const char> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<void>, Ptr32<const char>))w3d::vfn(this->w3d_vptr_Reader, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v23() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v25() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v27() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v29() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v30() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v31() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v33() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 35))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v34() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 36))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int name(Ptr32<String> w3d_a0, Ptr32<const char> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<String>, Ptr32<const char>))w3d::vfn(this->w3d_vptr_Reader, 37))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline int guid(Ptr32<Guid> w3d_a0, Ptr32<const char> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<Guid>, Ptr32<const char>))w3d::vfn(this->w3d_vptr_Reader, 38))(w3d::h2g(this), w3d_a0, w3d_a1); }  __attribute__((always_inline)) inline void v37() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 39))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v38() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 40))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v39() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Reader, 41))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int count(Ptr32<unsigned int> w3d_a0, Ptr32<const char> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<unsigned int>, Ptr32<const char>))w3d::vfn(this->w3d_vptr_Reader, 42))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Reader; };
typedef std::vector<Entry> Items;
template <> void Items::reserve(unsigned);
struct S { char q[20]; Items items; };
extern "C" int w3d_d30e_read_entries_801aecf0(Ptr32<S> self, Ptr32<Reader> r) {
  unsigned n;
  int hr = r->count(&n, lbl_803aa754);
  if (hr < 0) return hr;
  self->items.reserve(n);
  while (n--) {
    Entry e;
    hr = r->guid(&e.id, lbl_803aa754);
    if (hr < 0) return hr;
    hr = r->graph(&e.obj, lbl_803aa75c);
    if (hr < 0) return hr;
    hr = r->name(&e.name, lbl_803aa764);
    if (hr < 0) return hr;
    self->items.push_back(e);
  }
  return hr;
}


