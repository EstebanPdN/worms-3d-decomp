// GWMP8P rev0 0x802a6b30, observed partial layouts. Names describe observed use only.
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
extern "C" D24lObject *w3d_runtime_service_lookup_8015ae3c(const D24lString &);
extern "C" struct Mesh *w3d_cast_mesh_80343808(D24lObject *);
struct Mesh;
extern "C" int w3d_count_80171f90(Mesh *);
extern "C" int w3d_acquire_80171ee0(Mesh *, int);
extern "C" float *w3d_a_80171fa0(Mesh *);
extern "C" float *w3d_b_80171ff8(Mesh *);
extern "C" void *memset(void *, int, unsigned);
extern "C" int w3d_s20_store_byte_value_80173f88(D24lObject *, const unsigned char &);
extern "C" void fn_802a64a8(struct Bar *);
struct S8 { D24lObject *value; operator D24lObject *() const { return value; } };
struct Bar { char pad0[35]; unsigned char base; char pad36[188]; D24lObject *panel; char pad228[48]; S8 bars[8]; };
extern "C" void d24l_audio_bars_802a6b30(Bar *self)
{
 Mesh *m = w3d_cast_mesh_80343808(w3d_runtime_service_lookup_8015ae3c(D24lString("FE.AudioBar")));
 if (w3d_count_80171f90(m) != 2) {
  w3d_acquire_80171ee0(m, 2);
  float *a = w3d_a_80171fa0(m);
  float *b = w3d_b_80171ff8(m);
  memset(a, 0, 16);
  memset(b, 0, 16);
  a[0] = 0.0625f; a[1] = 0.125f; a[2] = 0.0625f; a[3] = 0.125f;
  b[0] = 0.0625f; b[1] = 0.375f; b[2] = 0.875f; b[3] = 0.375f;
  a[1] = 1.0f - a[1] - b[1];
  a[3] = 1.0f - a[3] - b[3];
 }
 for (unsigned char i = 0; i < 8; i++) {
  w3d_handle_set_name_8015adf4(D24lString("FE.AudioBar"), &self->bars[i].value, self->base + 29);
  w3d_s20_store_byte_value_80173f88(w3d_as_mesh_8034357c(self->bars[i]), 1);
  self->panel->vtable->attach(self->panel, self->bars[i], 0);
 }
 fn_802a64a8(self);
}
