// GWMP8P rev0 0x802c1248, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors, so both are BLKmode and their
// freed block-scoped slots can be reused.
struct D24lString {
 char *text;
 D24lString(const char *);
 D24lString(const D24lString &);
 ~D24lString();
};
extern "C" void w3d_string_finish_8020c5c4(D24lString *);
extern "C" void w3d_string_release_80341588(D24lString *);
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
 void *slots0[3];
 void (*retain)(D24lObject *);                     // +12
 void (*release)(D24lObject *);                    // +16
 void *slots20[16];
 void (*set_scale)(D24lObject *, const D24lVec3 &, int); // +84
 void *slot88;
 void (*attach)(D24lObject *, D24lObject *, int);  // +92
 void (*detach)(D24lObject *, D24lObject *);       // +96
};
struct D24lObject { D24lObjectVtable *vtable; };
extern "C" int w3d_handle_set_name_8015adf4(const D24lString &, D24lObject **, unsigned char);
struct D24lRef {
 D24lObject *value;
 D24lRef() : value(0) {}
 D24lRef(const D24lString &n, unsigned char t) : value(0) { w3d_handle_set_name_8015adf4(n, &value, t); }
 D24lRef(const D24lRef &);
 ~D24lRef() { if (value) value->vtable->release(value); }
};
inline int d24l_load_resource(const D24lString &n, D24lObject **o, unsigned char t) { return w3d_handle_set_name_8015adf4(n, o, t); }
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
extern int w3d_resource_base_804abb60;
extern "C" D24lObject *w3d_as_mesh_8034357c(D24lObject *);
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
extern "C" int w3d_cached_message_id_8015f5a0(MessageCache *, int);
extern "C" int w3d_subscribe_80162024(struct Box *, const unsigned short &, void *);
extern "C" int w3d_mesh_set_colour_80173df0(D24lObject *mesh, D24lColour *colour);
extern MessageCache w3d_message_804b1068;
struct Box { unsigned w0[9]; D24lHeld back; float alpha; unsigned w44[6]; char slot68[4]; };
inline void load_back(Box *self, const D24lString &name, unsigned char type)
{
 D24lRef ref(name, type);
 self->back = w3d_as_mesh_8034357c(ref.value);
}
extern "C" void d24l_textbox_back_panel_802c1248(Box *self)
{
 {
  int base = w3d_resource_base_804abb60;
  D24lString name("FE.Textbox.Back");
  load_back(self, name, base + 28);
 }
 {
  D24lVec3 scale(500.0f, 500.0f, 1.0f);
  self->back.value->vtable->set_scale(self->back.value, scale, 0);
 }
 {
  D24lColour colour;
  D24lColour *c = &colour;
  c->r = 0; c->g = 0; c->b = 0; c->a = 0;
  w3d_mesh_set_colour_80173df0(self->back.value, c);
 }
 self->alpha = 10.0f;
 w3d_subscribe_80162024(self, w3d_cached_message_id_8015f5a0(&w3d_message_804b1068, 1), self->slot68);
}
