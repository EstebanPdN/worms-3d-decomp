#include "w3d_ptr.h"
#line 1 "d30e_add_record_80205c04.cpp"
// (Worms 3D GameCube PAL, 0x80205c04).
//
// Builds a 12-byte record of a counted reference and two strings (default
// constructor 0x803426b8, assignment from text 0x8020bd38) and appends it to
// the vector at +20 through unmodified STLport push_back. Returns 0. Names
// are inferred.

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
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((const char *)w3d_p.get()); }
 String &operator=(const char *);
  String(const String &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &);
};
struct Iface { void w3d_r_v0() __asm__(W3D_SYM("_ZN5Iface2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN5Iface6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN5Iface7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
struct Ref {
  Ptr32<Iface> p;
  Ref() { p = 0; }
  Ref(const Ref &o) { p = o.p; if (p) p->AddRef(); }
  ~Ref() { if (p) p->Release(); }
  template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Iface *)w3d_p.get()); }
 Ref &operator=(Iface *q) { if (q) q->AddRef(); if (p) p->Release(); p = q; return *this; }
  Ref &operator=(const Ref &);
};
struct Rec { Ref ref; String a; String b; };
struct S { char q[20]; std::vector<Rec> items; };
extern "C" int w3d_d30e_add_record_80205c04(Ptr32<S> self, Ptr32<Iface> obj, Ptr32<const char> bname, Ptr32<const char> aname) {
  Rec r;
  r.ref = obj;
  r.a = aname;
  r.b = bname;
  self->items.push_back(r);
  return 0;
}


