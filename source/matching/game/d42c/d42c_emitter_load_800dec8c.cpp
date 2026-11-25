// d42c: 0x800dec8c. Particle emitter load: reads the settings, sizes the
// pool from the descriptor, seeds motion and builds the items.
struct Vec3 {
    float x, y, z;
    void operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; }
};
struct Rng { unsigned seed; };
extern Rng rng_804aecb4;
inline float lrand() { rng_804aecb4.seed = rng_804aecb4.seed * 0x41c64e6d + 12345; return (float)rng_804aecb4.seed * 2.3283064e-10f; }
inline float spread(float r, float half) { float h = r - half; return h + h; }
extern "C" float random_80162bc8();
struct Key { const char *name; };
extern "C" int read_setting_800fc1b0(Key *, void *);
extern "C" void *empty_80341584(void *);
struct Desc {
    char u0[20]; Vec3 v20; char u32[24]; Vec3 v56; Vec3 v68; char u80[36]; Vec3 v116; Vec3 v128;
    char u140[164]; int mode304; char u308[72]; int kind380; char u384[4];
    unsigned short n388; char u390[8]; unsigned short id398; unsigned short max400; unsigned short batch402;
    unsigned short a404, a406, n408; char u410[4]; unsigned short external414; unsigned short n416, n418, n420;
    char u422[38]; int sweep460; char u464[4]; int f468; char u472[8]; int f480;
};
extern "C" Desc *desc_801797b4(void *);
struct Item;
struct List { struct V { void *u[5]; Item *(*at)(List *, unsigned); } *vt; };
struct Self;
struct Ops { void *u[2]; void (*add)(Self *, Item *, int, int); };
struct Self {
    char u0[4]; List *list; int f8; char u12[4]; int f16; int f20; int f24; int f28; char u32[36];
    Vec3 pos; char u80[12]; int f92; char u96[4]; int f100; char u104[4]; int f108; int count;
    char u116[12]; void *handle; int f132; int f136; const char *key; char u144[4]; int state; unsigned flags;
    char u156[52]; int f208; int f212; int f216; char u220[8]; Ops *ops;
};
extern "C" int sweep_800df570(Self *);
extern "C" void motion_800df6c8(Self *, Vec3 *, Vec3 *, Vec3 *);
extern "C" void build_800e0198(Self *, unsigned, int, bool);
inline void Build(Self *self, int mode, const bool &ext) { build_800e0198(self, self->count, mode, ext); }
struct Context { char u0[52]; int v52; };
extern "C" Context *context_80165254();
extern char n1_80389c18[], n2_80389c38[], n3_80389c58[], n4_80389c64[], n5_80389c74[];
extern "C" int d42c_emitter_load_800dec8c(Self *self) {
    Vec3 a, b;
    if (self->state == 3) return 0x80004005;
    Key k0, k1, k2, k3, k4, k5;
    k0.name = self->key;
    int hr = read_setting_800fc1b0(&k0, &self->handle);
    if (hr < 0) { self->count = 0; self->state = 3; return hr; }
    Desc *d = desc_801797b4(empty_80341584(self->handle));
    k1.name = n1_80389c18; read_setting_800fc1b0(&k1, &self->f216);
    k2.name = n2_80389c38; read_setting_800fc1b0(&k2, &self->f212);
    k3.name = n3_80389c58; read_setting_800fc1b0(&k3, &self->f208);
    k4.name = n4_80389c64; read_setting_800fc1b0(&k4, &self->f132);
    k5.name = n5_80389c74; read_setting_800fc1b0(&k5, &self->f136);
    if (d->f480 == 1) self->flags |= 0x200;
    if (d->id398 == 65535) self->flags |= 1;
    if (d->f468 == 1) self->flags |= 8;
    int span = d->n416 - d->n388;
    if (d->n420 != 0 && span > 0) {
        int total = d->n420 + d->n418;
        int rate = d->a404 + d->a406;
        if (rate == 0) rate = 1;
        unsigned n = total / span * rate + 1;
        self->count = n;
        if (n > d->max400) self->count = d->max400;
    } else {
        self->count = d->max400;
    }
    if (self->count != 0) {
        if (d->sweep460 != 0 && sweep_800df570(self) == 0) { self->state = 3; return 0x80004005; }
        unsigned short e0 = d->external414; bool ext = false; if (e0) ext = d->external414 != 0; int e = e0;
        if (e) {
            float r = random_80162bc8();
            const Vec3 &base = d->v20, &range = d->v116, &base2 = d->v68, &range2 = d->v56;
            const float half = 0.5f;
            {
            const float k = 0.009999999776482582f;
            a.x = (spread(r, half) * range.x + base.x) * k;
            a.y = (spread(random_80162bc8(), half) * range.y + base.y) * k;
            a.z = (spread(random_80162bc8(), half) * range.z + base.z) * k;
            }
            {
            float q = random_80162bc8();
            const float k = 9.999999747378752e-05f;
            b.x = (spread(q, half) * range2.x + base2.x) * k;
            b.y = (spread(random_80162bc8(), half) * range2.y + base2.y) * k;
            b.z = (spread(random_80162bc8(), half) * range2.z + base2.z) * k;
            }
        } else {
            const Vec3 &base = d->v20, &range = d->v116, &base2 = d->v68, &range2 = d->v56;
            a.x = (spread(lrand(), 0.5f) * range.x + base.x) * 0.009999999776482582f;
            a.y = (spread(lrand(), 0.5f) * range.y + base.y) * 0.009999999776482582f;
            a.z = (spread(lrand(), 0.5f) * range.z + base.z) * 0.009999999776482582f;
            b.x = (spread(lrand(), 0.5f) * range2.x + base2.x) * 9.999999747378752e-05f;
            b.y = (spread(lrand(), 0.5f) * range2.y + base2.y) * 9.999999747378752e-05f;
            b.z = (spread(lrand(), 0.5f) * range2.z + base2.z) * 9.999999747378752e-05f;
        }
        motion_800df6c8(self, &self->pos, &a, &b);
        if (d->batch402 != 0) {
            if (d->kind380 == 3) Build(self, 2, ext);
            else Build(self, 1, ext);
            unsigned b2 = d->batch402, n = self->count;
            if (b2 > n) b2 = n;
            self->flags |= 4;
            self->f108 = n / b2;
        } else {
            Build(self, 0, ext);
            self->flags &= ~4;
        }
        if (self->list == 0 || self->list->vt->at(self->list, 0) == 0) {
            self->count = 0; self->state = 3; return 0x8007000e;
        }
        if (d->external414) {
            const float half = 0.5f;
            self->f24 = (int)(spread(random_80162bc8(), half) * (float)(int)d->n408);
            self->f28 = (int)(spread(random_80162bc8(), half) * (float)(int)d->n388);
            self->f92 = (int)(spread(random_80162bc8(), half) * (float)(int)d->a406);
        } else {
            self->f24 = (int)(spread(lrand(), 0.5f) * (float)(int)d->n408);
            self->f28 = (int)(spread(lrand(), 0.5f) * (float)(int)d->n388);
            self->f92 = (int)(spread(lrand(), 0.5f) * (float)(int)d->a406);
        }
    }
    self->f8 = 0; self->f16 = 0; self->state = 0; self->f20 = 0; self->f100 = 0;
    { int m = d->mode304; if (m == 2) goto set; if (m == 1) { set: self->flags |= 0x80; } else self->flags &= ~0x80; }
    int ctx = context_80165254()->v52;
    for (unsigned i = 0; i < self->count; ) {
        Item *it = self->list->vt->at(self->list, i);
        if (it == 0) { self->count = 0; self->state = 3; return 0x80004005; }
        i++;
        self->ops->add(self, it, ctx, 0);
    }
    const Vec3 &step = d->v128;
    self->pos.x += step.x;
    self->pos.y += step.y;
    self->pos.z += step.z;
    return 0;
}
