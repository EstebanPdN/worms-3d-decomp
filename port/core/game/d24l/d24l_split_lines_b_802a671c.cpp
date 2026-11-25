#include "w3d_ptr.h"
#line 1 "d24l_split_lines_b_802a671c.cpp"
// GWMP8P rev0 0x802a671c, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors, so both are BLKmode and their
// freed block-scoped slots can be reused.
struct D24lString {
 Ptr32<char> text;
 D24lString();
 template <class W3dU> D24lString(Ptr32<W3dU> w3d_p) : D24lString((const char *)w3d_p.get()) {}
 D24lString(const char *);
 D24lString(const D24lString &o);
 int empty() const { return ((Ptr32<unsigned short>)text)[-2] == 0; }
 ~D24lString();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<D24lString>);
extern "C" void w3d_string_release_80341588(Ptr32<D24lString>);
extern "C" void w3d_string_init_8020c5c0(Ptr32<D24lString>);
extern "C" Ptr32<unsigned short> w3d_string_header_80341884(Ptr32<D24lString>);
inline D24lString::D24lString(const D24lString &o)
{
 w3d_string_init_8020c5c0(this);
 text = o.text;
 ++*w3d_string_header_80341884(this);
}
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
extern const char lbl_803d611c[];
extern "C" unsigned strcspn(Ptr32<const char>, Ptr32<const char>);
extern "C" int w3d_string_assign_8020bd38(Ptr32<D24lString>, Ptr32<const char>);
struct Hdr { unsigned short refs, length, capacity; };
extern "C" void w3d_release_header_8020bb2c(Ptr32<Hdr>);
struct W {
 Ptr32<char> text;
 operator Ptr32<char>() const { return (char *)this->operator char *(); }
 operator char *() const { return text; }
 W &operator=(const D24lString &o)
 {
  Ptr32<Hdr> a = (Ptr32<Hdr>)(o.text - 6);
  ++a->refs;
  Ptr32<Hdr> b = (Ptr32<Hdr>)(text - 6);
  if (--b->refs == 0) w3d_release_header_8020bb2c(b);
  text = o.text;
  return *this;
 }
};
extern "C" void w3d_truncate_8020c3a0(Ptr32<W>, unsigned);
struct Data { char pad[152]; D24lString line; };
struct P { char pad0[40]; Ptr32<Data> data; char pad44[372]; W lines[41]; int count; int pad584[3]; int done; };
extern "C" void d24l_split_lines_b_802a671c(Ptr32<P> self)
{
 self->count = 0;
 Ptr32<Data> d = self->data;
 if (!d->line.empty()) {
  D24lString rest(d->line);
  while (!rest.empty()) {
   self->lines[self->count + 1] = rest;
   if (self->count == 10) break;
   self->count++;
   Ptr32<char> t = self->lines[self->count];
   unsigned n = strcspn(t, lbl_803d611c);
   if (t[n] == 92) {
    w3d_truncate_8020c3a0(&self->lines[self->count], n);
    n++;
   }
   t = rest.text;
   w3d_string_assign_8020bd38(&rest, t + n);
  }
  self->done = 1;
 }
}


