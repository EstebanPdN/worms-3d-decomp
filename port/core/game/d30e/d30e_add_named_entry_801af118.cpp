#include "w3d_ptr.h"
#line 1 "d30e_add_named_entry_801af118.cpp"
// (Worms 3D GameCube PAL, 0x801af118).
//
// Appends a 24-byte entry (interface pointer, 16-byte identifier, name
// string) to the vector at +20 with unmodified STLport push_back, then adds
// a reference to the interface. Returns 0. Names are inferred.

#include "compat/stlport_sn_oom.h"
#include <vector>
struct String;
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
struct String {
  Ptr32<char> p;
  template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
  String(const String &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
  String &operator=(const String &);
};
struct Base { void w3d_r_v0() __asm__(W3D_SYM("_ZN4Base2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN4Base6AddRefEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 3))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Base; };
struct Guid { int w0, w1, w2, w3; };
struct Entry { Ptr32<Base> obj; Guid id; String name;
  Entry(Ptr32<Base> o, const Guid &g, const String &n) : obj(o), id(g), name(n) {}
  Entry &operator=(const Entry &);
};
struct S { char q[20]; std::vector<Entry> items; };
extern "C" int w3d_d30e_add_named_entry_801af118(Ptr32<S> self, Ptr32<const Guid> id, Ptr32<Base> obj, Ptr32<const String> name) {
  self->items.push_back(Entry(obj, *id, *name));
  obj->AddRef();
  return 0;
}


