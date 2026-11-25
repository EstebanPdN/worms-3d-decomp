#include "w3d_ptr.h"
#line 1 "d24l_textbox_open_802c2aac.cpp"
// GWMP8P rev0, observed partial layouts. Field and slot names describe
// observed use only; they do not establish the original class identities.
// 0x8015adf4 forwards the resource manager virtual load result, so it is
// declared with a status return; the string constructor 0x8020bb54 is out of
// line. The 12-byte scale
// vector at sp+8 reuses the freed string (8) and handle (16) slots and the
// colour sits at sp+24. The back panel's handle is a local of an inline helper.
// The string and handle
// have user copy constructors, so both are BLKmode and their slots can be reused.
struct D24lString_8020bb54 {
 Ptr32<char> text;
 template <class W3dU> D24lString_8020bb54(Ptr32<W3dU> w3d_p) : D24lString_8020bb54((const char *)w3d_p.get()) {}
 D24lString_8020bb54(const char *);
 D24lString_8020bb54(const D24lString_8020bb54 &);
 ~D24lString_8020bb54();
};
extern "C" void w3d_string_finish_8020c5c4(Ptr32<D24lString_8020bb54>);
extern "C" void w3d_string_release_80341588(Ptr32<D24lString_8020bb54>);
inline D24lString_8020bb54::~D24lString_8020bb54()
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
 Ptr32<void (Ptr32<D24lObject>)> retain;                    // +12
 Ptr32<void (Ptr32<D24lObject>)> release;                   // +16
 Ptr32<void> slots20[16];
 Ptr32<void (Ptr32<D24lObject>, const D24lVec3 &, int)> set_scale; // +84
};
struct D24lObject { Ptr32<D24lObjectVtable> vtable; };
extern "C" int w3d_handle_set_name_8015adf4(const D24lString_8020bb54 &, Ptr32<Ptr32<D24lObject>>, unsigned char);
// Retaining reference; released when it goes out of scope.
struct D24lRef {
 Ptr32<D24lObject> value;
 D24lRef() : value(0) {}
 D24lRef(const D24lRef &);
 ~D24lRef() { if (value) value->vtable->release(value); }
};
inline int d24l_load_resource(const D24lString_8020bb54 &n, Ptr32<Ptr32<D24lObject>> o, unsigned char t) { return w3d_handle_set_name_8015adf4(n, o, t); }
// Owning pointer: assignment retains the new object, then releases the old.
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
struct D24lTextbox {
 unsigned words0[12];
 D24lHeld back;             // +48
 unsigned words52[3];
 int focus;                 // +64
 unsigned words68[3];
 int ready;                 // +80
};
extern int w3d_resource_base_804abb60;
extern "C" void w3d_textbox_reset_802c2c10(Ptr32<D24lTextbox> self);
extern "C" Ptr32<D24lObject> w3d_as_mesh_8034357c(Ptr32<D24lObject>);
extern "C" int w3d_mesh_set_colour_80173df0(Ptr32<D24lObject> mesh, Ptr32<D24lColour> colour);
extern "C" void w3d_textbox_layout_802c2dc4(Ptr32<D24lTextbox> self);
extern "C" void w3d_textbox_caption_802c459c(Ptr32<D24lTextbox> self);
extern "C" void w3d_cx12b_focus_dispatch_802c3ff0(Ptr32<D24lTextbox> self, int state, unsigned index);
extern "C" void w3d_setup_cursor_802c4840(Ptr32<D24lTextbox> self);

inline void load_back(Ptr32<D24lTextbox> self, const D24lString_8020bb54 &name, unsigned char type)
{
 D24lRef ref;
 d24l_load_resource(name, &ref.value, type);
 self->back = w3d_as_mesh_8034357c(ref.value);
}
extern "C" void d24l_textbox_open_802c2aac(Ptr32<D24lTextbox> self)
{
 w3d_textbox_reset_802c2c10(self);
 {
  int base = w3d_resource_base_804abb60;
  D24lString_8020bb54 name("FE.Textbox.Back");
  load_back(self, name, base + 28);
 }
 {
  D24lVec3 scale(500.0f, 1600.0f, 1.0f);   // port de dos pantallas: alto de sobra para cubrir también la de abajo (original 500)
  self->back.value->vtable->set_scale(self->back.value, scale, 0);
  // Port de dos pantallas: además del alto, se baja media pantalla (252,6 unidades del FE) para que llegue al final de la
  // de abajo; solo con el alto se quedaba a mitad (+76 es la posición, como en core/native/fe_layout.cpp).
  {
   D24lVec3 pos(0.0f, -252.63158f, 0.0f);
   (*(Ptr32<void (Ptr32<D24lObject>, const D24lVec3 &, int)> *)&self->back.value->vtable->slots20[14])(self->back.value, pos, 0);
  }
 }
 D24lColour colour;
 Ptr32<D24lColour> c = &colour;
 c->r = -2; c->g = -22; c->b = -43; c->a = 0;
 w3d_mesh_set_colour_80173df0(self->back.value, c);
 w3d_textbox_layout_802c2dc4(self);
 w3d_textbox_caption_802c459c(self);
 w3d_cx12b_focus_dispatch_802c3ff0(self, 1, self->focus);
 w3d_setup_cursor_802c4840(self);
 self->ready = 1;
}


