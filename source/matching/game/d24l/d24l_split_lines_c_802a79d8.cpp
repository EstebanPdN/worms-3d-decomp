// GWMP8P rev0 0x802a79d8, observed partial layouts. Names describe observed use only.
// 0x8015adf4 forwards the resource manager's load status, so it returns int.
// String and handle have user copy constructors, so both are BLKmode and their
// freed block-scoped slots can be reused.
struct D24lString {
 char *text;
 D24lString();
 D24lString(const char *);
 D24lString(const D24lString &o);
 D24lString(const struct W &o);
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
extern const char lbl_803d611c[];
extern "C" unsigned strcspn(const char *, const char *);
extern "C" int w3d_string_assign_8020bd38(D24lString *, const char *);
struct Hdr { unsigned short refs, length, capacity; };
extern "C" void w3d_release_header_8020bb2c(Hdr *);
struct W {
 char *text;
 int empty() const { return ((unsigned short *)text)[-2] == 0; }
 operator char *() const { return text; }
 W &operator=(const D24lString &o)
 {
  Hdr *a = (Hdr *)(o.text - 6);
  ++a->refs;
  Hdr *b = (Hdr *)(text - 6);
  if (--b->refs == 0) w3d_release_header_8020bb2c(b);
  text = o.text;
  return *this;
 }
};
inline D24lString::D24lString(const W &o)
{
 w3d_string_init_8020c5c0(this);
 text = o.text;
 ++*w3d_string_header_80341884(this);
}
extern "C" void w3d_truncate_8020c3a0(W *, unsigned);
struct Data { char pad[132]; W text132; char pad136[8]; W text144; };
struct P { char pad0[40]; Data *data; char pad44[452]; W lines_a[10]; W lines_b[11]; int pad584[2]; int count_a; int count_b; };
extern "C" void d24l_split_lines_c_802a79d8(P *self)
{
 self->count_a = 0;
 Data *d = self->data;
 if (!d->text144.empty()) {
  D24lString rest(d->text144);
  while (!rest.empty()) {
   self->lines_a[self->count_a + 1] = rest;
   if (self->count_a == 10) break;
   self->count_a++;
   char *t = self->lines_a[self->count_a];
   unsigned n = strcspn(t, lbl_803d611c);
   if (t[n] == 92) {
    w3d_truncate_8020c3a0(&self->lines_a[self->count_a], n);
    n++;
   }
   t = rest.text;
   w3d_string_assign_8020bd38(&rest, t + n);
  }
 }
 self->count_b = 0;
 if (!d->text132.empty()) {
  D24lString rest(d->text132);
  while (!rest.empty()) {
   self->lines_b[self->count_b + 1] = rest;
   if (self->count_b == 10) break;
   self->count_b++;
   char *t = self->lines_b[self->count_b];
   unsigned n = strcspn(t, lbl_803d611c);
   if (t[n] == 92) {
    w3d_truncate_8020c3a0(&self->lines_b[self->count_b], n);
    n++;
   }
   t = rest.text;
   w3d_string_assign_8020bd38(&rest, t + n);
  }
 }
}
