// GWMP8P rev0 0x8015e0e0. Per-frame scene update and render: creates the four
// named profile records on first use (RenderScene, CullSort, Draw, OverlayDraw),
// advances the clock by the elapsed milliseconds, updates the visible items, and
// times the cull, draw and overlay stages into +152, +156 and +160. Virtual slots
// are reference-ABI table views; names are inferred.
struct Obj;
struct Item { char u0[20]; int f20; };
struct ObjVt {
    char u0[12];
    void (*retain)(Obj *);
    void (*release)(Obj *);
    char u14[4];
    Obj *(*s24)(Obj *, void *);
    char u1c[4];
    Obj *(*s32)(Obj *);
    void (*s36)(Obj *);
    void (*s40)(Obj *);
    char u2c[4];
    void (*s48)(Obj *, int);
    void (*s52)(Obj *, int, int);
    void (*s56)(Obj *);
    char u3c[4];
    void (*s64)(Obj *, Obj *);
    Obj *(*s68)(Obj *);
    void (*s72)(Obj *);
    void (*s76)(Obj *, int);
    char u50[4];
    int (*s84)(Obj *, int);
    char u58[4];
    void (*s92)(Obj *, Obj *);
    void (*s96)(Obj *, float);
    void (*s100)(Obj *, float);
    char u68[8];
    void (*s112)(Obj *, float);
    Item *(*s116)(Obj *, unsigned char *);
    char u78[64];
    unsigned char (*s184)(Obj *);
    unsigned char (*s188)(Obj *);
};
struct Obj { ObjVt *vt; };
struct Ref {
    Obj *p;
    Ref(Obj *o) { p = o; if (p) p->vt->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
};
struct CurVt { char u0[24]; Obj *(*s24)(struct Cur *); char u1c[4]; int (*s32)(struct Cur *); };
struct Cur { CurVt *vt; };
struct Current { char u0[8]; Cur **cur; };
struct Timer { long long t; Timer() {} Timer(const Timer &); void start(); int delta(); };
struct Self {
    ObjVt *vt; char u4[44]; unsigned f48; float f52; Obj *f56; Obj *f60; char u40[4]; Obj *f68; Current f72; char u54[3]; unsigned char f87; char u58[4]; Obj *f92; Obj *f96; Obj *f100; char u68[8]; int f112; char u74[36]; int f152; int f156; int f160; int f164;
};
extern "C" {
void stamp_801fc790(void *, const char *);
long long elapsed_801fe4d8();
int ticks_801fe508(int);
void *pair_80343994();
void poll_801fdbec(void *, int);
void *service_80344278();
void reset_801fe314(void *);
}
extern int rec0_804b0090, guard0_804b0098, rec1_804b009c, guard1_804b00a4, rec2_804b00a8, guard2_804b00b0, rec3_804b00b4, guard3_804b00bc;
extern char name0_803a44d0[], name1_803a44dc[], name2_803a44e8[], name3_803a44f0[];
extern Obj *global_804b1884;
inline void Timer::start() { t = elapsed_801fe4d8(); }
inline int Timer::delta() { return (int)elapsed_801fe4d8() - (int)t; }
inline const unsigned char &minimum(const unsigned char &a, const unsigned char &b) { return b < a ? b : a; }
extern "C" int d30d_game_update_8015e0e0(Self *self, int ms) {
    if (!guard0_804b0098) { stamp_801fc790(&rec0_804b0090, name0_803a44d0); guard0_804b0098 = 1; }
    if (!guard1_804b00a4) { stamp_801fc790(&rec1_804b009c, name1_803a44dc); guard1_804b00a4 = 1; }
    if (!guard2_804b00b0) { stamp_801fc790(&rec2_804b00a8, name2_803a44e8); guard2_804b00b0 = 1; }
    if (!guard3_804b00bc) { stamp_801fc790(&rec3_804b00b4, name3_803a44f0); guard3_804b00bc = 1; }
    float dt = (float)ms / 1000.0f;
    if (self->f164 < 0) self->f56->vt->s112(self->f56, dt);
    self->f52 += dt;
    self->f68->vt->s100(self->f68, self->f52);
    self->f100->vt->s96(self->f100, self->f52);
    Timer t;
    t.start();
    self->f68->vt->s72(self->f68);
    unsigned char last = minimum((unsigned char)self->f56->vt->s188(self->f56), (unsigned char)(self->f87 - 1));
    Current *cam = &self->f72;
    for (unsigned char i = self->f56->vt->s184(self->f56); i <= last; i++) {
        Item *item = self->f56->vt->s116(self->f56, &i);
        if (item && item->f20) {
            self->f60->vt->s24(self->f60, item);
            int v = ((int (*)(Self *, int))self->vt->s84)(self, i);
            self->f68->vt->s52(self->f68, v, 0);
            self->f68->vt->s24(self->f68, item);
        }
    }
    Ref r(self->f68->vt->s68(self->f68));
    self->f152 = ticks_801fe508(t.delta());
    self->f96->vt->s36(self->f96);
    self->f96->vt->s48(self->f96, self->f48 & 0x40000000 ? 3 : 2);
    ((void (*)(Obj *, int))self->f96->vt->s84)(self->f96, (*cam->cur)->vt->s32(*cam->cur));
    self->f100->vt->s64(self->f100, (*cam->cur)->vt->s24(*cam->cur));
    global_804b1884->vt->s92(global_804b1884, (*cam->cur)->vt->s24(*cam->cur));
    if (self->f112) self->f100->vt->s76(self->f100, self->f112);
    t.start();
    self->f100->vt->s24(self->f100, r.p);
    self->f156 = ticks_801fe508(t.delta());
    self->f96->vt->s40(self->f96);
    poll_801fdbec(pair_80343994(), 1);
    reset_801fe314(service_80344278());
    t.start();
    self->f92->vt->s56(self->f92);
    self->f160 = ticks_801fe508(t.delta());
    return 0;
}
