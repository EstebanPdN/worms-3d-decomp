// GWMP8P rev0 0x8025f54c. Sets up a menu button's text object. Names are
// inferred from use; Panel, Info and Res are partial views.
struct Str_803426b8;
typedef Str_803426b8 Str;
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020c5c0(void *), fn_8020bb2c(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
struct Str_803426b8 {
 char *p;
 Str_803426b8();
 Str_803426b8(const char *);
 Str_803426b8(const Str_803426b8 &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
 unsigned short len() const { return ((Header *)(p - 6))->length; }
 Str_803426b8 &operator=(const Str_803426b8 &o) {
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
 Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Res;
struct ResVt { char u0[12]; void (*add)(Res *); void (*rel)(Res *); char u20[56]; void (*scale)(Res *, const Vec *, int); char u80[4]; void (*pos)(Res *, const Vec *, int); char u88[4]; void (*attach)(Res *, Res *, int); void (*detach)(Res *, Res *); };
struct Res { ResVt *vt; };
struct Colour { signed char r, g, b, a; };
struct Key { const char *name; };
struct Info { char u0[20]; Vec size; char u32[104]; Str text; int f140; int f144; int f148; };
struct InnerVt { char u0[20]; void (*refresh)(void *, int); };
struct Panel {
 char u0[28]; char inner[7]; unsigned char b35; char u36[4]; Info *info; char u44[68]; Res *mgr; char u116[60]; int f176; char u180[28]; InnerVt *ivt; int f212; int f216; int f220; char u224[20]; Res *font; char u248[4]; int f252;
};
struct Ctx { char u0[52]; int f52; };
extern "C" {
Ctx *fn_80165254();
void fn_802b0b84(void *, Panel *, int);
int fn_802b1510(void *, const char *, Res **, unsigned char);
int fn_800fc2b0(Key *, const char **);
Str *fn_8020bd38(Str *, const char *);
void * fn_8020bf2c(Str *, const char *);
int fn_8015adf4(const Str &, Res **, unsigned char);
Res *fn_80343580(Res *);
float fn_802b1880(void *);
int fn_8018d324(Res *, int);
int fn_8018c5b0(Res *, const char *);
int fn_8018d35c(Res *, Colour *);
void fn_802602fc(Panel *);
}
extern char lbl_803caae8[], lbl_803caaec[], lbl_803caaf0[];
inline Str operator+(const Str &a, const Str &b) { Str r = a; fn_8020bf2c(&r, b.p); return r; }
inline Str operator+(const Str &a, const char *b) { Str r = a; fn_8020bf2c(&r, b); return r; }
inline void Attach(Panel *self, Res *o) { if (o) self->mgr->vt->attach(self->mgr, o, 0); }
extern "C" void w3d_d32k_button_text_setup_8025f54c(Panel *self) {
 fn_802b0b84(self->inner, self, fn_80165254()->f52);
 Info *info = self->info;
 self->f216 = info->f144;
 self->f220 = info->f140;
 if (info->text.len() != 0) {
  if (fn_802b1510(self->inner, info->text.p, &self->font, self->f216 ? self->b35 + 31 : self->b35 + 30) < 0) {
   Str s;
   if (self->font) {
    self->mgr->vt->detach(self->mgr, self->font);
    if (self->font) self->font->vt->rel(self->font);
    self->font = 0;
   }
   s = info->text;
   Key key; const char *out;
   key.name = s.p;
   if (fn_800fc2b0(&key, &out) >= 0) {
    fn_8020bd38(&s, out);
   } else {
    Str t;
    t = Str(lbl_803caae8) + s + lbl_803caaec;
    s = t;
   }
   fn_8015adf4(Str(lbl_803caaf0), &self->font, self->f216 ? self->b35 + 31 : self->b35 + 30);
   self->mgr->vt->attach(self->mgr, self->font, 0);
   Res *text = fn_80343580(self->font);
   float h = fn_802b1880(self->inner);
   Vec v; Vec *pv = &v;
   v.x = h; v.y = h; pv->z = 1.0f;
   text->vt->pos(text, pv, 0);
   float k = 0.0f;
   Vec size(self->info->size);
   fn_8018d324(text, 0);
   Vec u; Vec *pu = &u;
   u.x = k; u.y = k; pu->z = k;
   text->vt->scale(text, pu, 0);
   fn_8018c5b0(text, s.p);
   Colour c; Colour *pc = &c;
   c.r = -1; pc->g = -1; pc->b = -1; pc->a = -1;
   fn_8018d35c(text, pc);
   self->f252 = 1;
  } else {
   Attach(self, self->font);
   if (self->font) self->font->vt->pos(self->font, &self->info->size, 0);
  }
 }
 fn_802602fc(self);
 self->f176 = 1;
 self->ivt->refresh(self->inner, 0);
 self->f212 = info->f148;
}
