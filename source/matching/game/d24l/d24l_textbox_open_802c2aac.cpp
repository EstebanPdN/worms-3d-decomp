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
 char *text;
 D24lString_8020bb54(const char *);
 D24lString_8020bb54(const D24lString_8020bb54 &);
 ~D24lString_8020bb54();
};
extern "C" void w3d_string_finish_8020c5c4(D24lString_8020bb54 *);
extern "C" void w3d_string_release_80341588(D24lString_8020bb54 *);
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
 void *slots0[3];
 void (*retain)(D24lObject *);                    // +12
 void (*release)(D24lObject *);                   // +16
 void *slots20[16];
 void (*set_scale)(D24lObject *, const D24lVec3 &, int); // +84
};
struct D24lObject { D24lObjectVtable *vtable; };
extern "C" int w3d_handle_set_name_8015adf4(const D24lString_8020bb54 &, D24lObject **, unsigned char);
// Retaining reference; released when it goes out of scope.
struct D24lRef {
 D24lObject *value;
 D24lRef() : value(0) {}
 D24lRef(const D24lRef &);
 ~D24lRef() { if (value) value->vtable->release(value); }
};
inline int d24l_load_resource(const D24lString_8020bb54 &n, D24lObject **o, unsigned char t) { return w3d_handle_set_name_8015adf4(n, o, t); }
// Owning pointer: assignment retains the new object, then releases the old.
struct D24lHeld {
 D24lObject *value;
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
extern "C" void w3d_textbox_reset_802c2c10(D24lTextbox *self);
extern "C" D24lObject *w3d_as_mesh_8034357c(D24lObject *);
extern "C" int w3d_mesh_set_colour_80173df0(D24lObject *mesh, D24lColour *colour);
extern "C" void w3d_textbox_layout_802c2dc4(D24lTextbox *self);
extern "C" void w3d_textbox_caption_802c459c(D24lTextbox *self);
extern "C" void w3d_cx12b_focus_dispatch_802c3ff0(D24lTextbox *self, int state, unsigned index);
extern "C" void w3d_setup_cursor_802c4840(D24lTextbox *self);

inline void load_back(D24lTextbox *self, const D24lString_8020bb54 &name, unsigned char type)
{
 D24lRef ref;
 d24l_load_resource(name, &ref.value, type);
 self->back = w3d_as_mesh_8034357c(ref.value);
}
extern "C" void d24l_textbox_open_802c2aac(D24lTextbox *self)
{
 w3d_textbox_reset_802c2c10(self);
 {
  int base = w3d_resource_base_804abb60;
  D24lString_8020bb54 name("FE.Textbox.Back");
  load_back(self, name, base + 28);
 }
 {
  D24lVec3 scale(500.0f, 500.0f, 1.0f);
  self->back.value->vtable->set_scale(self->back.value, scale, 0);
 }
 D24lColour colour;
 D24lColour *c = &colour;
 c->r = -2; c->g = -22; c->b = -43; c->a = 0;
 w3d_mesh_set_colour_80173df0(self->back.value, c);
 w3d_textbox_layout_802c2dc4(self);
 w3d_textbox_caption_802c459c(self);
 w3d_cx12b_focus_dispatch_802c3ff0(self, 1, self->focus);
 w3d_setup_cursor_802c4840(self);
 self->ready = 1;
}
