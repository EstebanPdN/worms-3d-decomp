// GWMP8P rev0 0x8029f598, observed partial layouts. Names describe observed use only.
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
extern "C" char *strchr(const char *, int);
extern "C" void fn_8029f48c(struct Tl *);
extern "C" int fn_8020c0fc(D24lString *, const D24lString &, int);
extern "C" void w3d_truncate_8020c3a0(D24lString *, int);
extern "C" void fn_8029f714(struct Tl *, char *, float, float);
extern D24lString lbl_804b06a0[];
extern "C" void w3d_release_header_8020bb2c(void *);
struct Tl { char pad[268]; float a268; };
extern "C" void d24l_text_list_lines_8029f598(Tl *self, const char *text, float a, float b)
{
 fn_8029f48c(self);
 D24lString rest(text);
 self->a268 = 0.0f;
 while (!rest.empty()) {
  char *nl = strchr(rest.text, 10);
  if (nl) {
   D24lString line(rest);
   int len = nl - rest.text;
   fn_8020c0fc(&rest, line, ((unsigned short *)rest.text)[-2] - len - 1);
   w3d_truncate_8020c3a0(&line, len);
   fn_8029f714(self, line.text, a, b);
  } else {
   fn_8029f714(self, rest.text, a, b);
   ++((unsigned short *)lbl_804b06a0[0].text)[-3];
   unsigned short *h = (unsigned short *)(rest.text - 6);
   if (--*h == 0) w3d_release_header_8020bb2c(h);
   rest.text = lbl_804b06a0[0].text;
  }
 }
}
