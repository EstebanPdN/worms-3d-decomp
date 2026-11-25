#include "w3d_ptr.h"
#line 1 "d24l_key_border_802c7e20.cpp"
// GWMP8P rev0 0x802c7e20, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors, so both are BLKmode and their
// freed block-scoped slots can be reused.
struct D24lString {
 Ptr32<char> text;
 template <class W3dU> D24lString(Ptr32<W3dU> w3d_p) : D24lString((const char *)w3d_p.get()) {}
 D24lString(const char *);
 D24lString(const D24lString &);
 ~D24lString();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<D24lString>);
extern "C" void w3d_string_release_80341588(Ptr32<D24lString>);
inline D24lString::~D24lString()
{
 w3d_string_finish_8020c5c4(this);
 w3d_string_release_80341588(this);
}
struct D24lVec3 {
 float x, y, z;
 D24lVec3(float a, float b, float c) : x(a), y(b), z(c) {}
 D24lVec3(const D24lVec3 &o);
};
struct D24lColour { signed char r, g, b; unsigned char a; };
struct D24lObject;
struct D24lObjectVtable {
 Ptr32<void> slots0[3];
 Ptr32<void (Ptr32<D24lObject>)> retain;                     // +12
 Ptr32<void (Ptr32<D24lObject>)> release;                    // +16
 Ptr32<void> slots20[16];
 Ptr32<void (Ptr32<D24lObject>, const D24lVec3 &, int)> set_scale; // +84
 Ptr32<void> slot88;
 Ptr32<void (Ptr32<D24lObject>, Ptr32<D24lObject>, int)> attach;  // +92
 Ptr32<void (Ptr32<D24lObject>, Ptr32<D24lObject>)> detach;       // +96
};
struct D24lObject { Ptr32<D24lObjectVtable> vtable; };
extern "C" int w3d_handle_set_name_8015adf4(const D24lString &, Ptr32<Ptr32<D24lObject>>, unsigned char);
struct D24lRef {
 Ptr32<D24lObject> value;
 D24lRef() : value(0) {}
 D24lRef(const D24lString &n, unsigned char t) : value(0) { w3d_handle_set_name_8015adf4(n, &value, t); }
 D24lRef(const D24lRef &);
 ~D24lRef() { if (value) value->vtable->release(value); }
};
inline int d24l_load_resource(const D24lString &n, Ptr32<Ptr32<D24lObject>> o, unsigned char t) { return w3d_handle_set_name_8015adf4(n, o, t); }
struct D24lHeld {
 Ptr32<D24lObject> value;
 template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((D24lObject *)w3d_p.get()); }
 D24lHeld &operator=(D24lObject *p)
 {
  if (p) p->vtable->retain(p);
  if (value) value->vtable->release(value);
  value = p;
  return *this;
 }
};
extern int w3d_resource_base_804abb60;
extern "C" Ptr32<D24lObject> w3d_as_mesh_8034357c(Ptr32<D24lObject>);

extern "C" void fn_802c7f60(Ptr32<struct Key>);
extern "C" void w3d_set_panel_vectors_802c7d24(Ptr32<struct Key>);
extern "C"  int  w3d_s20_store_byte_value_80173f88(Ptr32<D24lObject>, const unsigned char &);
struct Key { unsigned w0[7]; Ptr32<D24lObject> panel; unsigned w32[8]; D24lHeld border; int enabled; unsigned w72[3]; int alt; unsigned w88[5]; int ready; };
extern "C" void d24l_key_border_802c7e20(Ptr32<Key> self)
{
 if (self->border.value == 0 && self->ready != 0 && self->enabled != 0) {
  fn_802c7f60(self);
  {
   int base = w3d_resource_base_804abb60;
   D24lString name("FE.K.KeyBdr");
    self->border = w3d_as_mesh_8034357c(D24lRef(name, self->alt == 0 ? base + 31 : base + 32).value); 
  }
  w3d_s20_store_byte_value_80173f88(self->border.value, 9);
  self->panel->vtable->attach(self->panel, self->border.value, 0);
 }
 w3d_set_panel_vectors_802c7d24(self);
}


