#include "w3d_ptr.h"
#line 1 "d30e_add_named_iface_80206358.cpp"
// (Worms 3D GameCube PAL, 0x80206358).
//
// Grows the compact array at +36 by one, stores the interface in the new
// slot with reference counting and appends its name string to the vector at
// +48 through unmodified STLport push_back. Returns 0. Names are inferred.

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
struct Slots { unsigned n; int cap; Ptr32<Ptr32<Iface>> d; Ptr32<Iface> & at(unsigned i) { return d[i]; } };
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(Ptr32<Slots>, unsigned);
struct S { char q[36]; Slots slots; std::vector<String> names; };
extern "C" int w3d_d30e_add_named_iface_80206358(Ptr32<S> self, Ptr32<Iface> obj, Ptr32<const char> name) {
  Slots &sl = self->slots;
  w3d_cx11b_compact_vector_grow_80210d54(&sl, self->slots.n + 1);
  Ptr32<Iface> &slot = *(Ptr32<Ptr32<Iface>>)w3d::G((self->slots.n * 4 + (int)w3d::H(sl.d)));
  if (obj) obj->AddRef();
  if (slot) slot->Release();
  slot = obj;
  self->slots.n++;
  self->names.push_back(String(name));
  return 0;
}


