// GWMP8P rev0 0x802c6434, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors, so both are BLKmode and their
// freed block-scoped slots can be reused.
struct D24lString {
 char *text;
 D24lString();
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
struct Btn { unsigned w0[7]; D24lObject *panel; unsigned w32; int ready; unsigned w40[2]; D24lHeld border; D24lHeld hilite; unsigned w56[4]; float w; float h; };
extern "C" void d24l_key_button_borders_802c6434(Btn *self)
{
 int base = w3d_resource_base_804abb60;
 unsigned char type;
 { D24lString name("FE.K.BtnBdr"); type = base + 31;  D24lRef ref(name, type); self->border = w3d_as_mesh_8034357c(ref.value);  }
 { D24lString name("FE.K.BtnBdrH");  D24lRef ref(name, type); self->hilite = w3d_as_mesh_8034357c(ref.value);  }
 {
  D24lVec3 scale(self->w * 0.5f, self->h * 0.5f, 0.0f);
  self->border.value->vtable->set_scale(self->border.value, scale, 0);
  self->hilite.value->vtable->set_scale(self->hilite.value, scale, 0);
 }
 self->panel->vtable->attach(self->panel, self->border.value, 0);
 self->panel->vtable->attach(self->panel, self->hilite.value, 0);
 self->ready = 1;
}
