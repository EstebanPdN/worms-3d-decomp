#include "w3d_ptr.h"
#line 1 "d24l_choice_icon_802a62bc.cpp"
// GWMP8P rev0 0x802a62bc, observed partial layouts. Names describe observed use only.
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
struct Nd;
struct NdVt { Ptr32<void> s0[4]; Ptr32<void (Ptr32<Nd>)> release; Ptr32<void> s20[14]; Ptr32<int (Ptr32<Nd>, Ptr32<const float>, int)> set_pos; Ptr32<void> s80; Ptr32<int (Ptr32<Nd>, Ptr32<const float>, int)> set_scale; Ptr32<void> s88; Ptr32<int (Ptr32<Nd>, Ptr32<Nd>, int)> attach; Ptr32<int (Ptr32<Nd>, Ptr32<Nd>)> detach; };
struct Nd { Ptr32<NdVt> vt; };
struct V { float x, y, z; };
struct Data { char pad[20]; V pos; };
extern "C" void fn_802a671c(Ptr32<struct Ch>), fn_802a6878(Ptr32<struct Ch>);
extern "C" int w3d_named_802b1510(Ptr32<char>, Ptr32<const char>, Ptr32<Ptr32<Nd>>, unsigned char);
extern "C" int w3d_format_8020c510(Ptr32<D24lString>, Ptr32<const char>, ...);
extern const char lbl_803d6030[];
struct Ch { char pad0[28]; char sub[4]; unsigned char base; char w3d_tag_rest[3]; char pad36[4]; Ptr32<Data> data; char pad44[64]; char err[4]; Ptr32<Nd> panel; char pad116[120]; Ptr32<Nd> icon; int locked; char pad244[336]; unsigned count; char pad584[12]; int done; unsigned index; };
struct ChNames { char pad[420]; W names[45]; };
extern "C" void d24l_choice_icon_802a62bc(Ptr32<Ch> self)
{
 if (self->done == 0) fn_802a671c(self);
 if (self->count <= self->index) fn_802a6878(self);
 Ptr32<Data> d = self->data;
 Ptr32<V> pos = &d->pos;
 V s;
 float k = pos->y * 1.1875f;
 s.x = k;
 Ptr32<V> q = &s;
 q->y = k;
 q->z = 1.0f;
 float px = d->pos.x;
 float f = (0.0f - px) + pos->y;
 if (self->icon) {
  self->panel->vt->detach(self->panel, self->icon);
  if (self->icon) self->icon->vt->release(self->icon);
  self->icon = 0;
 }
 if (!((Ptr32<ChNames>)self)->names[self->index].empty()) {
  int r;
  if (self->locked == 0) r = w3d_named_802b1510(self->sub, (const char *)((Ptr32<ChNames>)self)->names[self->index], &self->icon, self->base + 32);
  else r = w3d_named_802b1510(self->sub, "FE.I.Padlock", &self->icon, self->base + 32);
  if (r < 0) {
   w3d_format_8020c510((Ptr32<D24lString>)self->err, lbl_803d6030, w3d::VA((Ptr32<char>)((Ptr32<ChNames>)self)->names[self->index]));
  } else {
   self->panel->vt->attach(self->panel, self->icon, 0);
   self->icon->vt->set_scale(self->icon, &s.x, 0);
   V t;
   Ptr32<V> r2 = &t;
   t.x = f;
   r2->y = 0.0f;
   r2->z = 0.0f;
   self->icon->vt->set_pos(self->icon, &t.x, 0);
  }
 }
}


