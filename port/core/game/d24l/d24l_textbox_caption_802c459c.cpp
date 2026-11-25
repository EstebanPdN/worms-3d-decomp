#include "w3d_ptr.h"
#line 1 "d24l_textbox_caption_802c459c.cpp"
// GWMP8P rev0 0x802c459c, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors, so both are BLKmode and their
// freed block-scoped slots can be reused.
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
extern "C" int w3d_set_name_view_8015adf4(const W &, Ptr32<Ptr32<D24lObject>>, unsigned char);
struct Txt;
struct TxtVt { Ptr32<void> s0[3]; Ptr32<void (Ptr32<Txt>)> retain; Ptr32<void (Ptr32<Txt>)> release; };
struct Txt { Ptr32<TxtVt> vt; };
struct TRef { Ptr32<Txt> value; TRef() : value(0) {} TRef(const TRef &); ~TRef() { if (value) value->vt->release(value); } };
struct Node;
struct NodeVt { Ptr32<void> s0[21]; Ptr32<int (Ptr32<Node>, Ptr32<const float>, int)> set_scale; Ptr32<void> s88; Ptr32<int (Ptr32<Node>, Ptr32<D24lObject>, int)> attach; Ptr32<int (Ptr32<Node>, Ptr32<D24lObject>)> detach; };
struct Node { Ptr32<NodeVt> vt; };
extern "C" int w3d_lookup_800fc1b0(const PropertyKey &, Ptr32<Ptr32<Txt>>);
extern "C" Ptr32<void> w3d_as_80343744(Ptr32<Txt>);
extern "C" Ptr32<Ptr32<const char>> w3d_text_80179170(Ptr32<void>);
extern "C" Ptr32<Node> w3d_as_node_80343580(Ptr32<D24lObject>);
extern "C" int w3d_string_assign_8020bd38(Ptr32<D24lString>, Ptr32<const char>);
extern "C" int w3d_string_format_8020c510(Ptr32<D24lString>, Ptr32<const char>, ...);
extern "C" int w3d_int_8020c5cc(Ptr32<D24lString>);
extern "C" void fn_802c38cc(Ptr32<struct Bx>, int), fn_802c4744(Ptr32<struct Bx>);
extern const char lbl_803d86a4[];
extern const char lbl_803d8758[];
struct Bx { char pad0[36]; Ptr32<Node> panel; char pad40[204]; Ptr32<D24lObject> cap; W prop; W name; D24lString text; int unknown260; int value; };
extern "C" void d24l_textbox_caption_802c459c(Ptr32<Bx> self)
{
 if (self->panel != 0 && !self->name.empty()) {
  if (self->cap) {
   self->panel->vt->detach(self->panel, self->cap);
   if (self->cap) self->cap->vtable->release(self->cap);
   self->cap = 0;
  }
  w3d_string_assign_8020bd38(&self->text, lbl_803d86a4);
  int base = w3d_resource_base_804abb60;
  w3d_set_name_view_8015adf4(self->name, &self->cap, base + 30);
  self->panel->vt->attach(self->panel, self->cap, 0);
  Ptr32<Node> n = w3d_as_node_80343580(self->cap);
  struct V { float x, y, z; } v; Ptr32<V> p = &v;
  p->x = 30.0f; p->y = 30.0f; p->z = 1.0f;
  n->vt->set_scale(n, &p->x, 0);
  TRef ref;
  if (!self->prop.empty() && w3d_lookup_800fc1b0(PropertyKey(self->prop), &ref.value) >= 0) {
   w3d_string_format_8020c510(&self->text, lbl_803d8758, w3d::VA(*w3d_text_80179170(w3d_as_80343744(ref.value))));
   if ((self->value = w3d_int_8020c5cc(&self->text)) != 0) fn_802c38cc(self, 2);
  }
  fn_802c4744(self);
 }
}


