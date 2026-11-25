#include "w3d_ptr.h"
#line 1 "d25l_text_list_scroll_box_b_802a047c.cpp"
// GWMP8P rev0 0x802a047c. Creates or removes the scroll box of a text list
// and updates its scroll position. One-word String with a user copy
// constructor. The slot reference is the store form that reproduces the
// original's register choice for the new box.
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
extern int w3d_resource_base_804abb60;
extern "C" Ptr32<D24lObject> w3d_as_mesh_8034357c(Ptr32<D24lObject>);
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) : x(o.x), y(o.y), z(o.z) {} };
struct Obj;
struct ObjVt { Ptr32<void> s0[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct ObjRef { Ptr32<Obj> value; ObjRef(const ObjRef &o) : value(o.value) { if (value) value->vt->retain(value); } };
struct Box { char pad[216]; int a216; };
struct Data { char pad[20]; float a20; float a24; char pad28[100]; int a128; };
struct TL { char pad0[20]; int a20; char pad24[4]; int a28; int a32; char pad36[4]; Ptr32<Data> data; char pad44[68]; ObjRef a112; char pad116[24]; int a140; char pad144[32]; int a176; char pad180[88]; float a268; char pad272[44]; float a316; char pad320[56]; Ptr32<Box> box; float a380; float a384; };
extern "C" void w3d_remove_box_802a0664(Ptr32<TL>);
extern "C" Ptr32<Box> w3d_new_box_8020b680(Ptr32<void>);
extern unsigned char lbl_8041c220[];
extern Ptr32<Box> lbl_804b178c;
extern "C" int fn_80164514(Ptr32<Box>, Ptr32<Box>, int);
extern "C" void fn_80296774(Ptr32<Box>, int);
extern "C" void fn_8029550c(Ptr32<Box>, float);
extern "C" void fn_80295468(Ptr32<Box>, Vec);
extern "C" void fn_8029623c(Ptr32<Box>, int), fn_80296518(Ptr32<Box>, int), fn_8029677c(Ptr32<Box>, int);
extern "C" void fn_80295268(Ptr32<Box>, ObjRef);
extern "C" void fn_8029fc78(Ptr32<TL>);
extern "C" float fn_802b1880(Ptr32<void>);
extern "C" float fn_802e87d4(float);
extern "C" void fn_80296378(Ptr32<Box>, float, float, float);
extern "C" void d25l_text_list_scroll_box_b_802a047c(Ptr32<TL> self)
{
 D24lString s;
 Ptr32<Data> d = self->data;
 if (d->a128 == 0) {
  w3d_remove_box_802a0664(self);
  return;
 }
 if (self->box == 0) {
  float zero = 0.0f;
  float h = self->a316;
  self->a380 = zero;
  self->a384 = zero;
  Ptr32<Box> b = w3d_new_box_8020b680(lbl_8041c220);
  Ptr32<Box> &slot = self->box; slot = b; fn_80164514(lbl_804b178c, b, self->a20);
  fn_80296774(self->box, self->a32);
  self->box->a216 = self->a28;
  fn_8029550c(self->box, (d->a24 - h) + (d->a24 - h));
  Vec v;
  Ptr32<Vec> p = &v;
  p->x = d->a20 - h * 0.5f;
  p->y = zero; p->z = zero;
  fn_80295468(self->box, v);
  fn_8029623c(self->box, d->a128);
  fn_80296518(self->box, self->a176);
  fn_8029677c(self->box, self->a140);
  fn_80295268(self->box, self->a112);
  fn_8029fc78(self);
 }
 float t = (self->data->a24 - self->a316) + (self->data->a24 - self->a316);
 float size = fn_802b1880((Ptr32<char>)self + 28);
 t = t / size;
 float fl = fn_802e87d4(t);
 t = t - fl;
 fn_80296378(self->box, 0.0f, self->a268 / size - t, fl);
}


