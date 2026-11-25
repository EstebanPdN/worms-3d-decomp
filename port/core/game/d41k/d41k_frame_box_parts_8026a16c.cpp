#include "w3d_ptr.h"
#line 1 "d41k_frame_box_parts_8026a16c.cpp"
// GWMP8P rev0 0x8026a16c. Framed list box: with style 0 it releases the
// sixteen corner and edge parts and hides the box; otherwise it loads the
// two part sets once for the style's FE.Box texture, sets their anchors,
// positions and scales from the layout size, then shows the highlighted set.
struct Str_803426b8;
typedef Str_803426b8 Str;
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str_803426b8 {
 Ptr32<char> p;
 Str_803426b8();
 template <class W3dU> Str_803426b8(Ptr32<W3dU> w3d_p) : Str_803426b8((const char *)w3d_p.get()) {}
 Str_803426b8(const char *);
 Str_803426b8(const Str_803426b8 &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
};
struct Vec {
 float x, y, z;
 Vec() {}
 Vec(float a, float b, float c) { x = a; y = b; Ptr32<Vec> q = this; q->z = c; }
 Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Res;
struct ResVt { char u0[12]; Ptr32<void (Ptr32<Res>)> add; Ptr32<void (Ptr32<Res>)> rel; char u20[56]; Ptr32<void (Ptr32<Res>, Ptr32<const Vec>, int)> pos; char u80[4]; Ptr32<void (Ptr32<Res>, Ptr32<const Vec>, int)> scale; Ptr32<void (Ptr32<Res>, int)> show; Ptr32<void (Ptr32<Res>, Ptr32<Res>, int)> attach; };
struct Res { Ptr32<ResVt> vt; };
struct Held { Ptr32<Res> r; Held() : r(0) {} Held(const Held &); ~Held() { if (r) r->vt->rel(r); } };
struct Key { Ptr32<const char> n; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *s) : n(s) {} };
struct Colour { unsigned char r, g, b, a; };
struct Info { char u0[20]; Vec size; char u32[108]; int style; };
struct Self {
 char u0[32]; unsigned char b35; char w3d_tag_rest[3]; char u36[4]; Ptr32<Info> info; char u44[68]; Ptr32<Res> mgr; char u116[60]; int f176; char u180[40];
 Ptr32<Res> part[8][2]; Ptr32<Res> box; char u288[12]; Ptr32<void> colours; char u304[140]; int built;
};
extern "C" {
Ptr32<const char> fn_80263bb8(int);
void fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
void fn_80263608(Str, int);
int fn_8015adf4(const Str &, Ptr32<Ptr32<Res>>, unsigned char);
Ptr32<Res> fn_8034357c(Ptr32<Res>);
int fn_80173f88(Ptr32<Res>, Ptr32<const unsigned char>);
int fn_800fc1b0(const Key &, Ptr32<Ptr32<Res>>);
Ptr32<void> fn_80342a74(Ptr32<Res>);
float fn_80178df0(Ptr32<void>);
Ptr32<const Colour> fn_80178f54(Ptr32<void>);
int fn_80173df0(Ptr32<Res>, Ptr32<const Colour>);
}
extern char lbl_803cb9ec[], lbl_803cba00[];
extern Vec lbl_8045e788;
struct Bias { unsigned char v; };
inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
inline void Load(Ptr32<Res> &d, const Str &n, unsigned char t) {
 Held h;
 fn_8015adf4(n, &h.r, t);
 Ptr32<Res> q = fn_8034357c(h.r);
 if (q) q->vt->add(q);
 if (d) d->vt->rel(d);
 d = q;
}
inline void SetBias(Ptr32<Res> r, Bias k) { fn_80173f88(r, &k.v); }
extern "C" void w3d_d41k_frame_box_parts_8026a16c(Ptr32<Self> self) {
 Str name;
 int style = self->info->style;
 if (style == 0) {
  Ptr32<Res> none = 0;
  Ptr32<Ptr32<Res>> q = (Ptr32<Ptr32<Res>>)self;
  Ptr32<Ptr32<Res>> p = &self->part[6][0];
#define CL(x) if (x) (x)->vt->rel(x); x = none;
  do { for (int i = 0; i < 2; i++) {
   CL(p[-12]) CL(p[0]) CL(q[57]) CL(q[65]) CL(q[61]) CL(q[69]) CL(q[59]) CL(q[63])
   p++; q++;
  } } while (0);
  self->box->vt->show(self->box, 0);
  return;
 }
 if (self->built == 0) {
  fn_8020bd38(&name, fn_80263bb8(style));
  Str high(lbl_803cb9ec);
  fn_80263608(Str(name), 0);
  fn_80263608(Str(high), 0);
#define LD(k, i, n) Load(self->part[k][i], n, self->b35 + 32);
  LD(0,0,name) LD(1,0,name) LD(2,0,name) LD(3,0,name) LD(4,0,name) LD(5,0,name) LD(6,0,name) LD(7,0,name)
  LD(0,1,high) LD(1,1,high) LD(2,1,high) LD(3,1,high) LD(4,1,high) LD(5,1,high) LD(6,1,high) LD(7,1,high)
  for (unsigned i = 0; i < 2; i++) {
   Ptr32<Ptr32<Res>> p = &self->part[7][i];
   { Bias b; b.v = 0; SetBias(p[-14], b); }
   { Bias b; b.v = 1; SetBias(p[-12], b); }
   { Bias b; b.v = 2; SetBias(p[-10], b); }
   { Bias b; b.v = 3; SetBias(p[-8], b); }
   { Bias b; b.v = 6; SetBias(p[-6], b); }
   { Bias b; b.v = 7; SetBias(p[-4], b); }
   { Bias b; b.v = 4; SetBias(p[-2], b); }
   { Bias b; b.v = 5; SetBias(p[-0], b); }
   self->mgr->vt->attach(self->mgr, p[-14], 0);
   self->mgr->vt->attach(self->mgr, p[-12], 0);
   self->mgr->vt->attach(self->mgr, p[-10], 0);
   self->mgr->vt->attach(self->mgr, p[-8], 0);
   self->mgr->vt->attach(self->mgr, p[-6], 0);
   self->mgr->vt->attach(self->mgr, p[-4], 0);
   self->mgr->vt->attach(self->mgr, p[-2], 0);
   self->mgr->vt->attach(self->mgr, p[-0], 0);
  }
  Held h;
  fn_800fc1b0(Key(lbl_803cba00), &h.r);
  float t = fn_80178df0(fn_80342a74(h.r));
  Vec c(lbl_8045e788);
  Ptr32<Info> info = self->info;
  Ptr32<Vec> sp = &info->size;
  float m = t * 0.5f;
  float one = 1.0f;
  Vec size(info->size.x, sp->y, one);
  size.x = Max(t, size.x);
  size.y = Max(t, size.y);
  Vec v72; v72.x = m; v72.y = m; { Ptr32<Vec> q = &v72; q->z = one; }
  Vec v88; v88.x = info->size.x - t; v88.y = m; { Ptr32<Vec> q = &v88; q->z = one; }
  Vec v104(v88);
  Vec v120; v120.y = sp->y - t; v120.x = m; { Ptr32<Vec> q = &v120; q->z = one; }
  float left = c.x - size.x + m, top = c.y + size.y - m, right = c.x + size.x - m, bottom = c.y - size.y + m;
  Vec a(left, top, c.z), b(right, top, c.z), e(left, bottom, c.z), d(right, bottom, c.z), f(c.x, top, c.z), g(c.x, bottom, c.z), j(left, c.y, c.z), k(right, c.y, c.z);
  for (int i = 0; i < 2; i++) {
   Ptr32<Ptr32<Res>> p = &self->part[7][i];
   p[-14]->vt->pos(p[-14], &a, 0);
   p[-12]->vt->pos(p[-12], &b, 0);
   p[-10]->vt->pos(p[-10], &e, 0);
   p[-8]->vt->pos(p[-8], &d, 0);
   p[-2]->vt->pos(p[-2], &f, 0);
   p[-0]->vt->pos(p[-0], &g, 0);
   p[-6]->vt->pos(p[-6], &j, 0);
   p[-4]->vt->pos(p[-4], &k, 0);
   p[-14]->vt->scale(p[-14], &v72, 0);
   p[-12]->vt->scale(p[-12], &v72, 0);
   p[-10]->vt->scale(p[-10], &v72, 0);
   p[-8]->vt->scale(p[-8], &v72, 0);
   p[-4]->vt->scale(p[-4], &v120, 0);
   p[-6]->vt->scale(p[-6], &v120, 0);
   p[-2]->vt->scale(p[-2], &v88, 0);
   p[-0]->vt->scale(p[-0], &v104, 0);
  }
  Colour col = *fn_80178f54(self->colours);
  size.x -= m;
  size.y -= m;
  self->box->vt->scale(self->box, &size, 0);
  fn_80173df0(self->box, &col);
  self->box->vt->show(self->box, 1);
  }
 int sel = 0;
 if (self->f176) sel = 1;
 for (unsigned i = 0; i < 2; i++) {
  int on = (sel ^ i) == 0;
  Ptr32<Ptr32<Res>> p = &self->part[5][i];
  p[-10]->vt->show(p[-10], on);
  p[-8]->vt->show(p[-8], on);
  p[-6]->vt->show(p[-6], on);
  p[-4]->vt->show(p[-4], on);
  p[2]->vt->show(p[2], on);
  p[4]->vt->show(p[4], on);
  p[-2]->vt->show(p[-2], on);
  p[0]->vt->show(p[0], on);
 }
 self->built = 1;
}


