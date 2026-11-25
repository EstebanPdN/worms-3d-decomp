// GWMP8P rev0 0x802a047c. Creates or removes the scroll box of a text list
// and updates its scroll position. One-word String with a user copy
// constructor. The slot reference is the store form that reproduces the
// original's register choice for the new box.
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
extern int w3d_resource_base_804abb60;
extern "C" D24lObject *w3d_as_mesh_8034357c(D24lObject *);
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) : x(o.x), y(o.y), z(o.z) {} };
struct Obj;
struct ObjVt { void *s0[3]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct ObjRef { Obj *value; ObjRef(const ObjRef &o) : value(o.value) { if (value) value->vt->retain(value); } };
struct Box { char pad[216]; int a216; };
struct Data { char pad[20]; float a20; float a24; char pad28[100]; int a128; };
struct TL { char pad0[20]; int a20; char pad24[4]; int a28; int a32; char pad36[4]; Data *data; char pad44[68]; ObjRef a112; char pad116[24]; int a140; char pad144[32]; int a176; char pad180[88]; float a268; char pad272[44]; float a316; char pad320[56]; Box *box; float a380; float a384; };
extern "C" void w3d_remove_box_802a0664(TL *);
extern "C" Box *w3d_new_box_8020b680(void *);
extern unsigned char lbl_8041c220[];
extern Box *lbl_804b178c;
extern "C" int fn_80164514(Box *, Box *, int);
extern "C" void fn_80296774(Box *, int);
extern "C" void fn_8029550c(Box *, float);
extern "C" void fn_80295468(Box *, Vec);
extern "C" void fn_8029623c(Box *, int), fn_80296518(Box *, int), fn_8029677c(Box *, int);
extern "C" void fn_80295268(Box *, ObjRef);
extern "C" void fn_8029fc78(TL *);
extern "C" float fn_802b1880(void *);
extern "C" float fn_802e87d4(float);
extern "C" void fn_80296378(Box *, float, float, float);
extern "C" void d25l_text_list_scroll_box_b_802a047c(TL *self)
{
 D24lString s;
 Data *d = self->data;
 if (d->a128 == 0) {
  w3d_remove_box_802a0664(self);
  return;
 }
 if (self->box == 0) {
  float zero = 0.0f;
  float h = self->a316;
  self->a380 = zero;
  self->a384 = zero;
  Box *b = w3d_new_box_8020b680(lbl_8041c220);
  Box *&slot = self->box; slot = b; fn_80164514(lbl_804b178c, b, self->a20);
  fn_80296774(self->box, self->a32);
  self->box->a216 = self->a28;
  fn_8029550c(self->box, (d->a24 - h) + (d->a24 - h));
  Vec v;
  Vec *p = &v;
  p->x = d->a20 - h * 0.5f;
  p->y = zero; p->z = zero;
  fn_80295468(self->box, v);
  fn_8029623c(self->box, d->a128);
  fn_80296518(self->box, self->a176);
  fn_8029677c(self->box, self->a140);
  fn_80295268(self->box, self->a112);
  fn_8029fc78(self);
 }
 float t = (self->data->a24 - self->a316) + (self->data->a24 - self->a316);
 float size = fn_802b1880((char *)self + 28);
 t = t / size;
 float fl = fn_802e87d4(t);
 t = t - fl;
 fn_80296378(self->box, 0.0f, self->a268 / size - t, fl);
}
