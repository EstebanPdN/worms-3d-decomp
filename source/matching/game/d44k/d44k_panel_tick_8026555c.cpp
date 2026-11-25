// GWMP8P rev0 0x8026555c. Per-frame update of a menu panel: a fixed 20 ms
// simulation loop animating an equaliser-style bar grid, two arrow widgets
// and two transform tweens. Inferred class layout; only fields the code
// reads are named.
struct Vec {
 float x, y, z;
 Vec() {}
 Vec(float a, float b, float c) { Vec *q = this; x = a; q->y = b; q->z = c; }
};
struct Res;
struct ResVt { char u0[80]; void (*rot)(Res *, const Vec *, int); void (*pos)(Res *, const Vec *, int); };
struct Res { ResVt *vt; };
struct Ref { Res *p; Ref(const Ref &); Res *get() const { return p; } };
struct Colour { signed char r, g, b; unsigned char a; };
inline float Diff(const float &x, const float &y) { return x - y; }
inline float LerpK(const float &k, float a, float b) { return a * (1.0f - k) + b * k; }
struct Arrow {
 Res *a; Res *b; char u8[12]; float w0, h0, x, y, w1, h1, w2, h2; float alpha, alpha2;
 inline void Step();
 inline void Fade(float rate, float target, const float &floor);
 void TrackI(float k, float a, float b) { float d = Diff(b, a); if (d < 0.01f && d > -0.01f) h1 = b; else h1 = LerpK(k, a, b); }
};
struct Panel {
 char u0[28]; char inner[184]; Res *f212; Ref bars[6][7]; char u384[0]; int want[6]; int have[6]; char u432[60]; int f492; int f496; int f500; Colour on[7]; Colour off; float f536; char u540[28]; float f568; char u572[4]; Arrow a1; Arrow a2; char u696[8]; float f704; float f708; int f712; float f716; float f720; int f724;
};
extern "C" {
void fn_802b0668(void *);
int fn_8015ff5c(Panel *);
Res *fn_8034357c(Res *);
int fn_80173df0(Res *, Colour *);
void fn_8026807c(Panel *);
}
inline void Paint(Res *r, Colour *q) { if (r) fn_80173df0(fn_8034357c(r), q); }
inline void Arrow::Fade(float rate, float target, const float &) {
 float d = Diff(target, alpha);
 if (d < 0.01f && d > -0.01f) alpha = target;
 else alpha = LerpK(rate, alpha, target);
  { Colour c; Colour *q = &c; int av = (unsigned char)alpha; c.r = -1; q->g = -1; q->b = -1; q->a = av; Paint(a, q); }
  { Colour c; Colour *q = &c; int av = (unsigned char)(alpha / 255.0f * 70.0f); c.r = 0; q->g = 0; q->b = 0; q->a = av; Paint(b, q); }
}
inline void Arrow::Step() {
 int changed = 0;
 float k = 0.9f;
 if (w1 != w2) {
  float d = w2 - w1;
  w1 = (d < 0.01f && d > -0.01f) ? w2 : w1 * (1.0f - k) + w2 * k;
  changed = 1;
 }
 if (h1 != h2) { TrackI(k, h1, h2); changed = 1; }
 if (w1 == w2 && h1 == h2) {
  if (w0 != w1) w2 = w0;
  if (h0 != h1) h2 = h0;
 }
 if (changed == 1) {
  Vec v(w1, h1, 1.0f);
  if (a) a->vt->pos(a, &v, 0);
  if (b) b->vt->pos(b, &v, 0);
 }
 if (alpha != alpha2) Fade(0.5f, alpha2, 0.0f);
}
extern "C" int w3d_d44k_panel_tick_8026555c(Panel *self, int ms) {
 fn_802b0668(self->inner);
 int n = ms - self->f492;
 if (n > 100) n = 100;
 while (n > 29) {
  int rest = n - 20;
  float cell = self->f536 / 7.0f;
  Vec t(cell * 2.3334f * 0.5f, cell * 0.5f, 1.0f);
  int level = (int)(self->f568 * 7.0f) - 1;
  Vec u(t.x * 0.66f, t.y * 0.66f, 1.0f);
  for (unsigned row = 0; row < 6; row++) {
   if (self->want[row] == self->have[row]) {
    self->want[row] = level - (fn_8015ff5c(self) & 3);
   } else if (self->want[row] > self->have[row]) {
    self->have[row] = self->have[row] + 1;
   } else {
    self->have[row] = self->have[row] - 1;
   }
   for (int col = 0; col < 7; col++) {
    if (col <= self->have[row]) {
     if (self->bars[row][col].get()) {
      fn_80173df0(fn_8034357c(self->bars[row][col].get()), &self->on[col]);
      Res *o = self->bars[row][col].get(); o->vt->pos(o, &t, 0);
     }
    } else {
     if (self->bars[row][col].get()) {
      fn_80173df0(fn_8034357c(self->bars[row][col].get()), &self->off);
      Res *o = self->bars[row][col].get(); o->vt->pos(o, &u, 0);
     }
    }
   }
  }
  fn_8026807c(self);
  self->a1.Step();
  self->a2.Step();
  if (self->f712 == 0 && self->f724 != 0 && self->f212) {
   float s = (self->f704 - self->f708) * 0.125f;
   float d = self->f708 - self->f704;
   if (d < 0.01f && d > -0.01f) { self->f704 = self->f708; self->f712 = 1; }
   else self->f704 = self->f704 - s;
   Vec v(self->f704, 0.0f, 0.0f);
   self->f212->vt->rot(self->f212, &v, 0);
  }
  if (self->f724 != 1 && self->f212) {
   float st = 0.1f;
   float d = self->f720 - self->f716;
   if (d < st && d > -st) { self->f716 = self->f720; self->f724 = 1; }
   else self->f716 = self->f716 + st;
   Vec v(self->f716, 1.0f, 1.0f);
   self->f212->vt->pos(self->f212, &v, 0);
  }
  n = rest;
 }
 self->f492 = ms - n;
 return 0;
}
