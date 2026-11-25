#include "w3d_ptr.h"
#line 1 "d30e_add_named_item_801b2fc0.cpp"
// (Worms 3D GameCube PAL, 0x801b2fc0).
//
// Appends a name string to the vector at +28 and an interface pointer to the
// vector at +44 through unmodified STLport push_back, then adds a reference.
// Returns 0x80070057 for a null name or interface, otherwise 0. Names are
// inferred.

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
struct Iface { void w3d_r_v0() __asm__(W3D_SYM("_ZN5Iface2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN5Iface6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN5Iface7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Iface, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Iface; };
struct S { char q[28]; std::vector<String> names; _STL::vector <Ptr32<Iface> > items; };
extern "C" int w3d_d30e_add_named_item_801b2fc0(Ptr32<S> self, Ptr32<const char> name, Ptr32<Iface> obj) {
  if (!obj || !name) return 0x80070057;
  self->names.push_back(String(name));
  self->items.push_back(obj);
  obj->AddRef();
  return 0;
}


