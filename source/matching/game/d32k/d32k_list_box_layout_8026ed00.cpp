// GWMP8P rev0 0x8026ed00. Lays out a list menu's box parts and its scroll
// controls. Names are inferred from use; Panel, Info and Res are partial
// views.
struct Str_803426b8;
typedef Str_803426b8 Str;
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020c5c0(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
extern "C" Str *fn_8020bd38(Str *, const char *);
struct Str_803426b8 {
 char *p;
 Str_803426b8();
 Str_803426b8(const char *);
 Str_803426b8(const Str_803426b8 &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
 void Set(const char *t) { fn_8020bd38(this, t); }
 unsigned short len() const { return ((Header *)(p - 6))->length; }
};
struct Vec {
 float x, y, z;
 Vec() {}
 Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Res;
struct ResVt { char u0[12]; void (*add)(Res *); void (*rel)(Res *); char u20[56]; void (*scale)(Res *, const Vec *, int); char u80[4]; void (*pos)(Res *, const Vec *, int); void (*show)(Res *, int); void (*attach)(Res *, Res *, int); };
struct Res { ResVt *vt; };
struct Ref { Res *p; Ref(const Ref &); Res *get() const { return p; } };
struct Held { Res *r; Held() : r(0) {} Held(const Held &); ~Held() { if (r) r->vt->rel(r); } };
struct Bias { unsigned char v; };
struct Obj;
struct Info { char u0[20]; Vec size; char u32[28]; Str f60; char u64[64]; int kind; void SetSize(const Vec &o) { size = o; } };
struct Panel {
 char u0[35]; unsigned char b35; char u36[4]; Info *info; char u44[68]; Res *mgr; char u116[60]; int f176; char u180[36]; Ref box[2]; Obj *bars[3]; Obj *scrolls[3]; int f248; float border; char u256[8]; int f264; char u268[8]; Res *f276; char u280[12]; int f292;
};
extern "C" {
const char *fn_80263bb8(int);
const char *fn_80263c24(int);
const char *fn_80263c90(int);
int fn_8015adf4(const Str &, Res **, unsigned char);
Res *fn_8034357c(Res *);
int fn_80173f88(Res *, const Bias *);
float fn_80178df0(Res *);
void fn_8027035c(Panel *, int, int);
void *fn_801fe1d8(unsigned);
Obj *fn_8025dffc(void *, const char *, unsigned char);
Obj *fn_80293460(void *, const char *, unsigned char);
void fn_8025e128(Obj *, float, float, float);
void fn_8025ee60(Obj *, const Vec *);
void fn_8025ee94(Obj *, Res *);
void fn_8029358c(Obj *, float, float, float, float);
void fn_80294398(Obj *, const Vec *);
void fn_802943cc(Obj *, Res *);
void fn_8025f064(Obj *, int);
void fn_8029459c(Obj *, int);
void fn_8027014c(Panel *);
}
void fn_80263608(Str, int);
extern char lbl_803cbe94[], lbl_803cbea8[], lbl_803cbebc[], lbl_803cbecc[], lbl_803cbee4[];
extern Vec lbl_8045e788[];
inline void HoldLoad(Res *&d, const Str &n, unsigned char t) {
 Held h;
 fn_8015adf4(n, &h.r, t);
 Res *q = fn_8034357c(h.r);
 if (q) q->vt->add(q);
 if (d) d->vt->rel(d);
 d = q;
}
inline const float &Max(const float &a, const float &b) { return a < b ? b : a; }
extern "C" void w3d_d32k_list_box_layout_8026ed00(Panel *self) {
 Str name;
 Info *info = self->info;
 if (info->kind == 0) {
  if (self->box[0].p) self->box[0].p->vt->rel(self->box[0].p);
  self->box[0].p = 0;
  if (self->box[1].p) self->box[1].p->vt->rel(self->box[1].p);
  self->box[1].p = 0;
  fn_8027035c(self, 1, 1);
  return;
 }
 float border = self->border;
 Obj **bars = self->bars, **scrolls = self->scrolls;
 float a = border * fn_80178df0(self->f276);
 float b = border * 0.5f;
 if (self->f264 == 0) {
  name.Set(fn_80263bb8(info->kind));
  Str hl(lbl_803cbe94);
  fn_80263608(name, 0);
  fn_80263608(hl, 0);
  HoldLoad(self->box[0].p, name, self->b35 + 31);
  HoldLoad(self->box[1].p, hl, self->b35 + 31);
  Bias k;
  for (unsigned i = 0; i < 2; i++) {
   Res *o0 = self->box[i].get(); k.v = 65; fn_80173f88(o0, &k);
   self->mgr->vt->attach(self->mgr, self->box[i].get(), 0);
  }
  Vec c(lbl_8045e788[0]);
  Vec sz(self->info->size);
  sz.x = Max(border, sz.x);
  sz.y = Max(border, sz.y);
  self->info->SetSize(sz);
  Vec t, u; Vec *pt = &t;
  float one = 1.0f;
  t.x = self->info->size.x - b; t.y = b; pt->z = one;
  u.x = c.x; u.z = c.z; u.y = c.y + sz.y - border - b + a;
  for (int i = 0; i < 2; i++) {
   Res *o = self->box[i].get(); o->vt->scale(o, &u, 0);
   Res *o2 = self->box[i].get(); o2->vt->pos(o2, pt, 0);
  }
 }
 if (self->f292 == 0) {
  if (self->scrolls[0]) fn_8027035c(self, 0, 1);
  if (self->bars[0] == 0) {
   self->bars[0] = fn_8025dffc(fn_801fe1d8(4), fn_80263c24(info->kind), self->b35 + 32);
   self->bars[1] = fn_8025dffc(fn_801fe1d8(4), lbl_803cbea8, self->b35 + 32);
   if (info->f60.len() != 0) self->bars[2] = fn_8025dffc(fn_801fe1d8(4), lbl_803cbebc, self->b35 + 32);
   unsigned i = 0;
   Vec c(lbl_8045e788[0]);
   const Vec &s = info->size;
   for (; i < 3; i++) {
    if (bars[i]) {
     fn_8025e128(bars[i], border, info->size.x, s.y);
     fn_8025ee60(bars[i], &c);
     fn_8025ee94(bars[i], self->mgr);
    }
   }
  }
 } else {
  if (self->bars[0]) fn_8027035c(self, 1, 0);
  if (self->scrolls[0] == 0) {
   self->scrolls[0] = fn_80293460(fn_801fe1d8(4), fn_80263c90(info->kind), self->b35 + 32);
   self->scrolls[1] = fn_80293460(fn_801fe1d8(4), lbl_803cbecc, self->b35 + 32);
   if (info->f60.len() != 0) self->scrolls[2] = fn_80293460(fn_801fe1d8(4), lbl_803cbee4, self->b35 + 32);
   unsigned i = 0;
   Vec c(lbl_8045e788[0]);
   const Vec &s = info->size;
   for (; i < 3; i++) {
    if (scrolls[i]) {
     fn_8029358c(scrolls[i], border, info->size.x, s.y, border * 0.25f);
     fn_80294398(scrolls[i], &c);
     fn_802943cc(scrolls[i], self->mgr);
    }
   }
  }
 }
 int active = 0;
 if (self->f176) active = 1;
 for (unsigned i = 0; i < 2; i++) {
  Ref *p = &self->box[i];
  int on = active == i;
  if (bars[i]) fn_8025f064(bars[i], on);
  if (scrolls[i]) fn_8029459c(scrolls[i], on);
  p->p->vt->show(p->p, on);
 }
 int done = 1;
 fn_8027014c(self);
 self->f264 = done;
}
