// GWMP8P rev0 0x802663dc. Options-button layout: loads the button's textures
// by name, reporting load failures on its error string, attaches them to the
// manager, and builds the two scroll arrows with their sizes and positions
// from the layout size.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020bb2c(void *);
struct Header { unsigned short refs, length, capacity; };
struct Str_803426b8;
typedef Str_803426b8 Str;
struct Str_803426b8 {
 char *p;
 Str_803426b8();
 Str_803426b8(const char *);
 Str_803426b8(const Str_803426b8 &);
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
 unsigned short len() const { return ((Header *)(p - 6))->length; }
 Str &operator=(const Str &o) {
  ++((Header *)(o.p - 6))->refs;
  Header *h = (Header *)(p - 6);
  if (--h->refs == 0) fn_8020bb2c(h);
  p = o.p;
  return *this;
 }
};
struct Vec {
 float x, y, z;
 Vec() {}
 Vec(float a, float b, float c) { Vec *q = this; x = a; q->y = b; q->z = c; }
 Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Res;
struct ResVt { char u0[12]; void (*add)(Res *); void (*rel)(Res *); char u20[56]; void (*scale)(Res *, const Vec *, int); char u80[4]; void (*pos)(Res *, const Vec *, int); void (*show)(Res *, int); void (*attach)(Res *, Res *, int); };
struct Res { ResVt *vt; };
struct Ref { Res *p; Ref(Res *q) : p(q) { if (p) p->vt->add(p); } Ref(const Ref &o) : p(o.p) { if (p) p->vt->add(p); } ~Ref() { if (p) p->vt->rel(p); } };
struct Held { Res *r; Held() : r(0) {} Held(const Held &); ~Held() { if (r) r->vt->rel(r); } };
struct Colour { unsigned char r, g, b, a; };
struct Quad { float a, b, c, d; };
extern "C" {
void fn_8020bd38(Str *, const char *);
void fn_8020c510(Str *, const char *, ...);
int fn_802b1510(void *, const char *, Res **, unsigned char);
int fn_8015adf4(const Str &, Res **, unsigned char);
Res *fn_8034357c(Res *);
int fn_80173df0(Res *, void *);
int fn_80173f88(Res *, const unsigned char *);
void *fn_8015ae3c(const Str &);
void *fn_80343808(void *);
int fn_80171f90(void *);
int fn_80171ee0(void *, int);
Quad *fn_80171fa0(void *);
Quad *fn_80171ff8(void *);
void *memset(void *, int, unsigned);
void fn_8026857c(void *);
}
extern char lbl_803cb5cc[], lbl_803cb610[], lbl_803cb634[], lbl_803cb640[], lbl_803cb650[], lbl_803cb648[], lbl_803cb658[], lbl_803cb660[], lbl_803cb664[], lbl_803cb52c[];
struct Info { char u0[20]; Vec size; char u32[100]; int kind; Str base; char u140[8]; Str res; };
struct Arrow { Res *a; Res *b; char u8[12]; float w0, h0, x, y, w1, h1, w2, h2; char u52[8]; };
struct Button {
 char u0[28]; char f28[7]; unsigned char b35; char u36[4]; Info *info; char u44[64]; Str err; Res *mgr; char u116[24]; int f140; char u144[292]; int f436; Res *f440; Res *f444; Res *f448; Res *f452; char u456[32]; Res *f488; char u492[4]; int f496; char u500[36]; float f536; char u540[36]; Arrow a1; Arrow a2;
 void Init1(Ref mgr, Arrow *p, unsigned char k);
 void Init2(Ref mgr, Arrow *p, unsigned char k);
};
inline void Cfg(void *c) {
 if (fn_80171f90(c) != 2) {
  fn_80171ee0(c, 2);
  Quad *q = fn_80171fa0(c);
  Quad *e = fn_80171ff8(c);
  memset(q, 0, 16);
  memset(e, 0, 16);
  q->a = 0.0f; q->b = 0.0f; e->a = 1.0f; e->b = 1.0f; q->d = 0.984375f; q->c = 0.0f; e->d = -1.0f; e->c = 1.0f;
  q->b = 1.0f - q->b - e->b;
  q->d = 1.0f - q->d - e->d;
 }
}
#define INIT(F, A, V) inline void Button::F(Ref mgr, Arrow *p, unsigned char k) { \
 void *c = fn_80343808(fn_8015ae3c(Str(lbl_803cb52c))); \
  \
 Cfg(c); \
 fn_8015adf4(Str(lbl_803cb52c), &p->a, 34); \
 fn_8015adf4(Str(lbl_803cb52c), &A.b, 33); \
 unsigned char v; \
 Colour col; col.r = 0; col.g = 0; col.b = 0; col.a = 70; \
 fn_80173df0(fn_8034357c(A.b), &col); \
 if (mgr.p) { mgr.p->vt->attach(mgr.p, A.a, 0); mgr.p->vt->attach(mgr.p, A.b, 0); } \
 fn_80173f88(fn_8034357c(A.a), &(v = k)); \
 fn_80173f88(fn_8034357c(A.b), &(v = k)); \
}
INIT(Init1, a1, 0)
INIT(Init2, a2, 1)
inline void Sc(Res *r, const Vec &t) { r->vt->scale(r, &t, 0); }
inline void HoldLoad(Res *&d, const Str &n, unsigned char t) {
 Held h;
 fn_8015adf4(n, &h.r, t);
 Res *q = fn_8034357c(h.r);
 if (q) q->vt->add(q);
 if (d) d->vt->rel(d);
 d = q;
}
inline void Fit(Button *self, const Vec &size, float k) {
 Arrow *p1 = &self->a1, *p2 = &self->a2;
#define SIZE(P, A) { Vec t; float w = size.x * k, h = size.y * k; P->w0 = w; P->h0 = h; P->w1 = w; P->h1 = h; P->w2 = w; P->h2 = h; t.x = w; t.y = h; t.z = 1.0f; if (self->A.a) self->A.a->vt->pos(self->A.a, &t, 0); if (self->A.b) self->A.b->vt->pos(self->A.b, &t, 0); }
 SIZE(p1, a1)
 SIZE(p2, a2)
}
extern "C" void w3d_d42k_button_build_802663dc_802663dc(Button *self) {
 Info *info = self->info;
 Str name;
 Colour cc;
 if (info->res.len() == 0) fn_8020bd38(&name, lbl_803cb5cc);
 else name = info->res;
 if (fn_802b1510(self->f28, name.p, &self->f452, self->f436 ? self->b35 + 32 : self->b35 + 31) < 0) {
  fn_8020c510(&self->err, lbl_803cb610, info->res.p);
  fn_8015adf4(Str(lbl_803cb5cc), &self->f452, self->f436 ? self->b35 + 32 : self->b35 + 31);
 }
 if (self->f140 == 0 && self->f452) {
  signed char *b = (signed char *)&cc; b[0] = -1; b[1] = -1; b[2] = -1; b[3] = -86;
  fn_80173df0(fn_8034357c(self->f452), &cc);
 }
 self->mgr->vt->attach(self->mgr, self->f452, 0);
 self->f452->vt->pos(self->f452, &self->info->size, 0);
 if (info->base.len() != 0) {
  fn_8020c510(&name, info->base.p, lbl_803cb634);
  if (fn_802b1510(self->f28, name.p, &self->f444, !self->f436 ? self->b35 + 32 : self->b35 + 31) < 0) {
   fn_8020c510(&self->err, lbl_803cb610, name.p);
  } else {
   self->mgr->vt->attach(self->mgr, self->f444, 0);
   self->f444->vt->pos(self->f444, &self->info->size, 0);
   self->f444->vt->show(self->f444, 0);
  }
  fn_8020c510(&name, info->base.p, lbl_803cb640);
  if (fn_802b1510(self->f28, name.p, &self->f448, !self->f436 ? self->b35 + 32 : self->b35 + 31) >= 0) {
   self->mgr->vt->attach(self->mgr, self->f448, 0);
   self->f448->vt->pos(self->f448, &self->info->size, 0);
   self->f448->vt->show(self->f448, 0);
  }
  if (info->kind != 0) {
   switch (info->kind) {
   case 1: fn_8020c510(&name, info->base.p, lbl_803cb648); break;
   case 2: fn_8020c510(&name, info->base.p, lbl_803cb650); break;
   case 3: fn_8020c510(&name, info->base.p, lbl_803cb648); break;
   case 4: fn_8020c510(&name, info->base.p, lbl_803cb658); break;
   case 5: fn_8020c510(&name, info->base.p, lbl_803cb660); break;
   default: fn_8020bd38(&name, lbl_803cb664); break;
   }
   if (fn_802b1510(self->f28, name.p, &self->f440, !self->f436 ? self->b35 + 32 : self->b35 + 31) < 0) {
    fn_8020c510(&self->err, lbl_803cb610, name.p);
   } else {
    HoldLoad(self->f488, name, self->b35 + 30);
    self->mgr->vt->attach(self->mgr, self->f488, 0);
    { Colour *q = &cc; cc.r = 0; q->g = 0; q->b = 0; q->a = 70; fn_80173df0(self->f488, q); }
    self->f488->vt->pos(self->f488, &self->info->size, 0);
    { Vec t; Vec *q = &t; float z = 0.1f; t.x = self->info->size.x * z; float k = 0.0f; q->y = k; q->z = k; self->f488->vt->scale(self->f488, q, 0); }
    self->mgr->vt->attach(self->mgr, self->f440, 0);
    self->f440->vt->pos(self->f440, &self->info->size, 0);
   }
  }
 }
 Vec size(self->info->size);
 self->f536 = (size.y + size.y) * 0.7f;
 self->Init1(Ref(self->mgr), &self->a1, 0);
 self->Init2(Ref(self->mgr), &self->a2, 1);
Fit(self, size, 0.3f);
 Arrow *p1 = &self->a1;
#define POS(P, A, PX, PY) { float px = PX, py = PY; P->x = px; P->y = py; if (self->A.a && self->A.b) { float zero = 0.0f; { Vec t; t.x = px; t.y = py; t.z = zero; Sc(self->A.a, t); } if (self->A.b) { Vec t; float by = py - P->h0 * 0.15f, bx = P->w0 * 0.15f + px; t.x = bx; t.y = by; t.z = zero; Sc(self->A.b, t); } } }
 POS(p1, a1, -size.x / 1.6f, size.y * 0.5f)
 Arrow *p2 = &self->a2;
 POS(p2, a2, -size.x / 1.6f, -size.y / 1.95f)

 self->f496 = 1;
 fn_8026857c(self);
}
