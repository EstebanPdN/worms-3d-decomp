#include "w3d_ptr.h"
#line 1 "d24l_page_text_802a7c54.cpp"
// GWMP8P rev0 0x802a7c54, observed partial layouts. Names describe observed use only.
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
struct W { Ptr32<char> text; };
inline D24lString::D24lString(const W &o)
{
 w3d_string_init_8020c5c0(this);
 text = o.text;
 ++*w3d_string_header_80341884(this);
}
struct PropertyKey { Ptr32<const char> name; template <class W3dU> PropertyKey(Ptr32<W3dU> w3d_p) : PropertyKey((const char *)w3d_p.get()) {}
 PropertyKey(const char *n) : name(n) {} };
struct Txt;
struct TxtVt { Ptr32<void> s0[4]; Ptr32<void (Ptr32<Txt>)> release; };
struct Txt { Ptr32<TxtVt> vt; };
struct TRef { Ptr32<Txt> value; TRef() : value(0) {} TRef(const TRef &); ~TRef() { if (value) value->vt->release(value); } };
extern "C" int w3d_lookup_800fc1b0(const PropertyKey &, Ptr32<Ptr32<Txt>>);
extern "C" Ptr32<void> w3d_as_80343744(Ptr32<void>);
extern "C" Ptr32<Ptr32<const char>> w3d_text_80179170(Ptr32<void>);
extern "C" int d24d_rename_801790bc(Ptr32<void>, Ptr32<const char>);
extern "C" void w3d_a_802b1714(Ptr32<void>);
extern "C" int w3d_string_format_8020c510(Ptr32<D24lString>, Ptr32<const char>, ...);
struct Page { unsigned w0[7]; char sub[68]; Ptr32<void> label; unsigned w100[2]; D24lString err; char pad[428]; W names[10]; unsigned n580; unsigned n584; unsigned w588; unsigned n592; unsigned w596; unsigned cur; };
extern "C" void d24l_page_text_802a7c54(Ptr32<Page> self)
{
 unsigned cur = self->cur;
 Ptr32<D24lString> err;
 if (cur >= self->n592 || cur >= self->n584 || cur >= self->n580 || (err = &self->err, !err->empty())) {
  w3d_a_802b1714(self->sub);
 } else {
  D24lString name(self->names[cur]);
  if (!name.empty()) {
   TRef ref;
   if (w3d_lookup_800fc1b0(PropertyKey(name.text), &ref.value) >= 0) {
    Ptr32<void> l = w3d_as_80343744(self->label);
    d24d_rename_801790bc(l, *w3d_text_80179170(w3d_as_80343744(ref.value)));
   } else {
    w3d_string_format_8020c510(err, "ERROR: No such Text Resource '%s'", w3d::VA(name.text));
    d24d_rename_801790bc(w3d_as_80343744(self->label), self->err.text);
   }
  }
 }
}


