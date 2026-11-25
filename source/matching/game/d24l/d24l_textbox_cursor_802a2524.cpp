// GWMP8P rev0 0x802a2524, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors, so both are BLKmode and their
// freed block-scoped slots can be reused.
struct D24lString {
 char *text;
 D24lString();
 D24lString(const char *);
 D24lString(const struct W &);
 D24lString(const D24lString &o);
 int empty() const { return ((unsigned short *)text)[-2] == 0; }
 ~D24lString();
};
extern "C" void w3d_string_finish_8020c5c4(D24lString *);
extern "C" void w3d_string_release_80341588(D24lString *);
extern "C" void w3d_string_init_8020c5c0(D24lString *);
extern "C" unsigned short *w3d_string_header_80341884(D24lString *);
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
struct W { char *text; operator char *() const { return text; } int empty() const { return ((unsigned short *)text)[-2] == 0; } };
inline D24lString::D24lString(const W &o)
{
 w3d_string_init_8020c5c0(this);
 text = o.text;
 struct H { unsigned short refs, length, capacity; } *h = (H *)w3d_string_header_80341884(this);
 ++h->refs;
}
struct PropertyKey { const char *name; PropertyKey(const char *n) : name(n) {} };
struct Klass { char pad[20]; Klass *parent; };
inline int d24l_is_a(Klass *t, Klass *key)
{
 while (t != key) {
  Klass *n = t->parent;
  if (t == n) return 0;
  t = n;
 }
 return 1;
}
struct V { float x, y, z; };
extern "C" int w3d_read_800fc270(const PropertyKey &, float *);
struct NodeVt { void *s0[3]; void (*retain)(struct Nd *); void (*release)(struct Nd *); void *s20[16]; int (*set_scale)(struct Nd *, const V *, int); int (*show)(struct Nd *, int); int (*attach)(struct Nd *, struct Nd *, int); };
struct Nd { NodeVt *vt; };
struct NRef { Nd *value; NRef() : value(0) {} NRef(const NRef &); ~NRef() { if (value) value->vt->release(value); } };
extern "C" int w3d_set_name_8015adf4(const D24lString &, Nd **, unsigned char);
extern "C" Nd *w3d_as_8034357c(Nd *);
struct Tb { char pad0[35]; unsigned char base; char pad36[272]; Nd *panel; char pad312[80]; Nd *cursor; };
extern "C" void d24l_textbox_cursor_802a2524(Tb *self)
{
 if (self->cursor != 0) return;
 V v; V *p = &v;
 p->x = 0.0f; p->y = 0.0f; p->z = 0.0f;
 w3d_read_800fc270(PropertyKey("FE.TextBoxTextSize"), &v.y);
 p->x = v.y * 0.5f;
 p->y = p->y * 0.5f;
 p->z = p->z * 0.5f;
 if (self->cursor != 0) return;
 NRef ref;
 w3d_set_name_8015adf4(D24lString("FE.Textbox.Cursor"), &ref.value, self->base + 30);
 Nd *n = w3d_as_8034357c(ref.value);
 if (n) n->vt->retain(n);
 if (self->cursor) self->cursor->vt->release(self->cursor);
 self->cursor = n;
 self->cursor->vt->show(self->cursor, 0);
 self->cursor->vt->set_scale(self->cursor, p, 0);
 self->panel->vt->attach(self->panel, self->cursor, 0);
}
