// GWMP8P rev0 0x802aa5f0, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors, so both are BLKmode and their
// freed block-scoped slots can be reused.
struct D24lString {
 char *text;
 D24lString();
 D24lString(const char *);
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
struct PropertyKey { const char *name; PropertyKey(const char *n) : name(n) {} };
struct Item;
struct ItemVt { void *s0[4]; void (*release)(Item *); void *s20; int (*kind)(Item *); };
struct Item { ItemVt *vt; unsigned w4;
 Item() {} };
struct IRef { Item *value; IRef() : value(0) {} IRef(const IRef &); ~IRef() { if (value) value->vt->release(value); } };
extern "C" int w3d_lookup_800fc1b0(const PropertyKey &, Item **);
extern "C" void *w3d_as_a_803426b4(Item *);
extern "C" void *w3d_as_b_80342a78(Item *);
extern "C" int w3d_value_a_80178c48(void *);
extern "C" int w3d_value_b_80178d1c(void *);
extern "C" int d24l_property_value_802aa5f0(void *self, D24lString name)
{
 IRef ref;
 if (name.empty()) return 0;
 if (w3d_lookup_800fc1b0(PropertyKey(name.text), &ref.value) >= 0) {
  switch (ref.value->vt->kind(ref.value)) {
  case 0: return w3d_value_a_80178c48(w3d_as_a_803426b4(ref.value));
  case 1: return w3d_value_b_80178d1c(w3d_as_b_80342a78(ref.value));
  }
 }
 D24lString copy(name);
 return 0;
}
