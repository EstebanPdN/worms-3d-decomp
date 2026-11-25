// (Worms 3D GameCube PAL, 0x801dc7d8).
//
// Per-frame update of a sound object: returns 0x80004005 until ready (+176).
// Updates each listener in the array at +48 through virtual slot 10, steps
// each 16-byte gain entry in the vector at +60 with 0x801db06c, erasing
// finished ones (element copy with AddRef and Release, out-of-line
// destructor), then erases dead entries of the array at +76 (virtual slot
// 7). Names are inferred.

struct Unk { virtual void v0(); virtual void AddRef(); virtual void Release(); };
struct Gain {
  Unk *p; int a; int b; float g;
  ~Gain();
  Gain &operator=(const Gain &o) {
    if (o.p) o.p->AddRef();
    if (p) p->Release();
    p = o.p; a = o.a; b = o.b; g = o.g;
    return *this;
  }
};
extern "C" int w3d_r25b_step_gain_801db06c(Gain *, int);
static inline void copyGains(Gain *first, Gain *last, Gain *to) {
  for (int n = last - first; n > 0; --n) { *to = *first; ++first; ++to; }
}
struct GainVec {
  Gain *b, *e;
  Gain *erase(Gain *pos) {
    if (pos + 1 != e) copyGains(pos + 1, e, pos);
    --e;
    e->~Gain();
    return pos;
  }
};
struct Upd { virtual void v0(),v1(),v2(),v3(),v4(),v5(),v6(),v7(),v8(),v9(); virtual void update(int); };
struct Live { virtual void v0(),v1(),v2(),v3(),v4(),v5(),v6(); virtual int alive(); };
struct UpdArr { unsigned n; int c; Upd **d; Upd *operator[](unsigned i) { return d[i]; } };
struct LiveArr { unsigned n; int c; Live **d;
  Live **begin() { return d; }
  Live **end() { return d + n; }
};
extern "C" void f4c_erase_80210dd8(LiveArr *, Live **, Live **);
struct S { char p[48]; UpdArr ups; GainVec gains; int r[2]; LiveArr lives; char s[176 - 88]; int ready; };
extern "C" int w3d_d30e_prune_voices_801dc7d8(S *self, int t) {
  if (!self->ready) return 0x80004005;
  for (unsigned i = 0; i < self->ups.n; i++) self->ups[i]->update(t);
  GainVec &gains = self->gains;
  for (Gain *g = gains.b; g != gains.e;) {
    if (w3d_r25b_step_gain_801db06c(g, t)) g++;
    else gains.erase(g);
  }
  LiveArr &lives = self->lives;
  for (Live **p = lives.d; p != lives.d + self->lives.n;) {
    if ((*p)->alive()) p++;
    else f4c_erase_80210dd8(&lives, p, p + 1);
  }
  return 0;
}
