#include "w3d_ptr.h"
#line 1 "d24l_choice_setup_802a4cbc.cpp"
// GWMP8P rev0 0x802a4cbc, observed partial layouts. Names describe observed use only.
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
 struct H { unsigned short refs, length, capacity; }; Ptr32<struct H> h = (Ptr32<H>)w3d_string_header_80341884(this);
 ++h->refs;
}
struct PropertyKey { Ptr32<const char> name; template <class W3dU> PropertyKey(Ptr32<W3dU> w3d_p) : PropertyKey((const char *)w3d_p.get()) {}
 PropertyKey(const char *n) : name(n) {} };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct Sub { unsigned w0[4]; int value; };
struct Node;
struct NodeVt { Ptr32<void> s0[19]; Ptr32<int (Ptr32<Node>, Ptr32<const float>, int)> set_position; Ptr32<void> s80; Ptr32<int (Ptr32<Node>, Ptr32<const float>, int)> set_scale; Ptr32<void> s88; Ptr32<int (Ptr32<Node>, Ptr32<Node>, int)> attach; };
struct Node { Ptr32<NodeVt> vt; };
struct V { float x, y, z; V() {} V(const V &o) : x(o.x), y(o.y), z(o.z) {} };
extern V lbl_8045e788[];
struct Data { char pad[136]; D24lString name136; };
struct Data2 { char pad[140]; D24lString name140; };
struct Ctx { char pad[52]; int a52; };
struct Choice {
 char pad0[28]; char sub[12]; Ptr32<Data> data; char pad44[68]; Ptr32<Node> panel; char pad116[108];
 Ptr32<Node> anchor; char pad228[12]; int result; char pad244[136]; char watch380[4]; char watch384[4];
 Ptr32<D24lObject> p388; Ptr32<D24lObject> p392; Ptr32<Sub> msg396; Ptr32<Sub> msg400; char pad404[96]; W names[25]; int index; int next; int a608; unsigned a612; int pad616; int count;
};
extern "C" Ptr32<Ctx> w3d_engine_get_context_80165254();
extern "C" void w3d_sub_init_802b0b84(Ptr32<char>, Ptr32<Choice>, int);
extern "C" int w3d_lookup_800fc1b0(const PropertyKey &, Ptr32<Ptr32<D24lObject>>);
extern "C" int w3d_forward_800fd62c(const D24lString &, Ptr32<void (void)>, Ptr32<Choice>, Ptr32<char>);
extern "C" int fn_802a7550(Ptr32<void>, Ptr32<void>);
extern "C" int fn_802a7500(Ptr32<void>, Ptr32<void>);
extern "C" void fn_802a79d8(Ptr32<Choice>), fn_802a671c(Ptr32<Choice>), fn_802a6fa8(Ptr32<Choice>), fn_802a73d4(Ptr32<Choice>), fn_802a6878(Ptr32<Choice>), fn_802a7490(Ptr32<Choice>), fn_802a75ec(Ptr32<Choice>), fn_802a77a4(Ptr32<Choice>), fn_802a520c(Ptr32<Choice>), fn_802a62bc(Ptr32<Choice>), fn_802a6b30(Ptr32<Choice>);
extern Ptr32<void> lbl_804abbac;
extern "C" int fn_8028496c(Ptr32<void>, D24lString);
extern "C" int w3d_cached_message_id_8015f5a0(Ptr32<MessageCache>, int);
extern "C" int w3d_subscribe_80162024(Ptr32<Choice>, const unsigned short &, Ptr32<Ptr32<Sub>>);
extern MessageCache lbl_804b0ed8, lbl_804b0ee0;
extern "C" void d24l_choice_setup_802a4cbc(Ptr32<Choice> self)
{
 w3d_sub_init_802b0b84(self->sub, self, w3d_engine_get_context_80165254()->a52);
 Ptr32<Data> d = self->data;
 D24lString &second = ((Ptr32<Data2>)d)->name140;
 w3d_handle_set_name_8015adf4(D24lString("NULL"), (Ptr32<Ptr32<D24lObject>>)&self->anchor, 255);
 self->panel->vt->attach(self->panel, self->anchor, 0);
  V s; Ptr32<V> p = &s;
  p->x = 1.0f; p->y = 1.0f; p->z = 1.0f;
  self->anchor->vt->set_scale(self->anchor, &p->x, 0);
  V pos(lbl_8045e788[0]);
  self->anchor->vt->set_position(self->anchor, &pos.x, 0);
 fn_802a79d8(self);
 fn_802a671c(self);
 fn_802a6fa8(self);
 if (!second.empty() && w3d_lookup_800fc1b0(PropertyKey(second.text), &self->p388) >= 0) {
  w3d_forward_800fd62c(second, (Ptr32<void (void)>)fn_802a7500, self, self->watch380);
  fn_802a73d4(self);
  self->index = self->next;
  fn_802a6878(self);
 }
 {
  D24lString &first = d->name136;
  if (!first.empty() && w3d_lookup_800fc1b0(PropertyKey(first.text), &self->p392) >= 0) {
   w3d_forward_800fd62c(first, (Ptr32<void (void)>)fn_802a7550, self, self->watch384);
   fn_802a7490(self);
   self->a612 = self->a608;
  }
 }
 self->result = fn_8028496c(lbl_804abbac, D24lString(self->names[self->index]));
 fn_802a75ec(self);
 fn_802a77a4(self);
 switch (self->a612) {
 case 0: case 2: self->count = 8; break;
 case 1: case 3: self->count = 4; break;
 }
 fn_802a520c(self);
 fn_802a62bc(self);
 fn_802a6b30(self);
 fn_802a6878(self);
 w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&lbl_804b0ed8, 1), &self->msg396);
 w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&lbl_804b0ee0, 1), &self->msg400);
 self->msg396->value = 0;
 self->msg400->value = 0;
}


