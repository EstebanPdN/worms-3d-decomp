#include "w3d_ptr.h"
#line 1 "d24l_text_list_lines_8029f598.cpp"
// GWMP8P rev0 0x8029f598, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors (the handle copy with retain is
// witnessed by value at 0x802a047c), which makes them BLKmode.
struct D24lString {
 Ptr32<char> text;
 D24lString();
 template <class W3dU> D24lString(Ptr32<W3dU> w3d_p) : D24lString((const char *)w3d_p.get()) {}
 D24lString(const char *);
 D24lString(const struct W &);
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
struct W { Ptr32<char> text; operator Ptr32<char>() const { return (char *)this->operator char *(); }
 operator char *() const { return text; } int empty() const { return ((Ptr32<unsigned short>)text)[-2] == 0; } };
inline D24lString::D24lString(const W &o)
{
 w3d_string_init_8020c5c0(this);
 text = o.text;
 struct H { unsigned short refs, length, capacity; }; Ptr32<struct H> h = (Ptr32<H>)w3d_string_header_80341884(this);
 ++h->refs;
}
struct PropertyKey { Ptr32<const char> name; template <class W3dU> PropertyKey(Ptr32<W3dU> w3d_p) : PropertyKey((const char *)w3d_p.get()) {}
 PropertyKey(const char *n) : name(n) {} };
struct Klass { char pad[20]; Ptr32<Klass> parent; };
inline int d24l_is_a(Ptr32<Klass> t, Ptr32<Klass> key)
{
 while (t != key) {
  Ptr32<Klass> n = t->parent;
  if (t == n) return 0;
  t = n;
 }
 return 1;
}
extern "C" Ptr32<char> strchr(Ptr32<const char>, int);
extern "C" void fn_8029f48c(Ptr32<struct Tl>);
extern "C" int fn_8020c0fc(Ptr32<D24lString>, const D24lString &, int);
extern "C" void w3d_truncate_8020c3a0(Ptr32<D24lString>, int);
extern "C" void fn_8029f714(Ptr32<struct Tl>, Ptr32<char>, float, float);
extern D24lString lbl_804b06a0[];
extern "C" void w3d_release_header_8020bb2c(Ptr32<void>);
struct Tl { char pad[268]; float a268; };
extern "C" void d24l_text_list_lines_8029f598(Ptr32<Tl> self, Ptr32<const char> text, float a, float b)
{
 fn_8029f48c(self);
 D24lString rest(text);
 self->a268 = 0.0f;
 while (!rest.empty()) {
  Ptr32<char> nl = strchr(rest.text, 10);
  if (nl) {
   D24lString line(rest);
   int len = nl - rest.text;
   fn_8020c0fc(&rest, line, ((Ptr32<unsigned short>)rest.text)[-2] - len - 1);
   w3d_truncate_8020c3a0(&line, len);
   fn_8029f714(self, line.text, a, b);
  } else {
   fn_8029f714(self, rest.text, a, b);
   ++((Ptr32<unsigned short>)lbl_804b06a0[0].text)[-3];
   Ptr32<unsigned short> h = (Ptr32<unsigned short>)(rest.text - 6);
   if (--*h == 0) w3d_release_header_8020bb2c(h);
   rest.text = lbl_804b06a0[0].text;
  }
 }
}


