// GWMP8P rev0 0x802a62bc, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors (the handle copy with retain is
// witnessed by value at 0x802a047c), which makes them BLKmode.
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
struct Nd;
struct NdVt { void *s0[4]; void (*release)(Nd *); void *s20[14]; int (*set_pos)(Nd *, const float *, int); void *s80; int (*set_scale)(Nd *, const float *, int); void *s88; int (*attach)(Nd *, Nd *, int); int (*detach)(Nd *, Nd *); };
struct Nd { NdVt *vt; };
struct V { float x, y, z; };
struct Data { char pad[20]; V pos; };
extern "C" void fn_802a671c(struct Ch *), fn_802a6878(struct Ch *);
extern "C" int w3d_named_802b1510(char *, const char *, Nd **, unsigned char);
extern "C" int w3d_format_8020c510(D24lString *, const char *, ...);
extern const char lbl_803d6030[];
struct Ch { char pad0[28]; char sub[7]; unsigned char base; char pad36[4]; Data *data; char pad44[64]; char err[4]; Nd *panel; char pad116[120]; Nd *icon; int locked; char pad244[336]; unsigned count; char pad584[12]; int done; unsigned index; };
struct ChNames { char pad[420]; W names[45]; };
extern "C" void d24l_choice_icon_802a62bc(Ch *self)
{
 if (self->done == 0) fn_802a671c(self);
 if (self->count <= self->index) fn_802a6878(self);
 Data *d = self->data;
 V *pos = &d->pos;
 V s;
 float k = pos->y * 1.1875f;
 s.x = k;
 V *q = &s;
 q->y = k;
 q->z = 1.0f;
 float px = d->pos.x;
 float f = (0.0f - px) + pos->y;
 if (self->icon) {
  self->panel->vt->detach(self->panel, self->icon);
  if (self->icon) self->icon->vt->release(self->icon);
  self->icon = 0;
 }
 if (!((ChNames *)self)->names[self->index].empty()) {
  int r;
  if (self->locked == 0) r = w3d_named_802b1510(self->sub, ((ChNames *)self)->names[self->index], &self->icon, self->base + 32);
  else r = w3d_named_802b1510(self->sub, "FE.I.Padlock", &self->icon, self->base + 32);
  if (r < 0) {
   w3d_format_8020c510((D24lString *)self->err, lbl_803d6030, (char *)((ChNames *)self)->names[self->index]);
  } else {
   self->panel->vt->attach(self->panel, self->icon, 0);
   self->icon->vt->set_scale(self->icon, &s.x, 0);
   V t;
   V *r2 = &t;
   t.x = f;
   r2->y = 0.0f;
   r2->z = 0.0f;
   self->icon->vt->set_pos(self->icon, &t.x, 0);
  }
 }
}
