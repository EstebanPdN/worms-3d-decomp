// GWMP8P rev0 0x80287f64. Constructor of the memory card screen: base
// constructor, vtable, two arrays of held references, cleared fields, then
// the float setup from the literal pool.
// Observed object views; roles inferred.
struct Obj { void **vtable; };
struct Ref {
    Obj *p;
    Ref() : p(0) {}
    void Set(Obj *n) { if (p) ((void (*)(Obj *))p->vtable[4])(p); p = n; }
};
extern "C" void *w3d_ctor_801628b0(void *);
extern "C" float w3d_cx9c_ceilf_802e85fc(float);
extern char lbl_8041c050[];
extern float lbl_803cf8a8[], lbl_803cf8ac[], lbl_803cf8b0[], lbl_803cf8b4[];
struct Self {
    void *vtable; char pad4[684];
    int f688, f692, f696; char pad700[4]; int f704; char pad708[164];
    Ref a[8]; Ref b[5];
    int f924, f928, f932, f936, f940, f944, f948, f952, f956, f960, f964, f968, f972, f976, f980, f984, f988, f992;
    float f996, f1000, f1004, f1008; char pad1012[4];
    unsigned flags;
};
inline void *operator new[](unsigned int, void *p) { return p; }
extern "C" Self *d33f_card_screen_ctor_80287f64(Self *self) {
    w3d_ctor_801628b0(self);
    self->vtable = lbl_8041c050;
    new (self->a) Ref[8];
    new (self->b) Ref[5];
    self->flags &= 0x0bffffff;
    self->f932 = 0;
    self->f936 = 0;
    self->f940 = 0;
    self->f944 = 0;
    self->f948 = 0;
    self->f952 = 0;
    self->f988 = 0;
    self->f972 = 0;
    self->f976 = 0;
    self->f980 = 0;
    self->f704 = 0;
    self->f984 = 0;
    self->f968 = 0;
    self->f688 = 0;
    self->f692 = 0;
    self->f956 = 0;
    self->f964 = 0;
    self->f924 = 0;
    self->f928 = -1;
    for (int i = 0; i < 8; i++) self->a[i].Set(0);
    self->f960 = 0;
    for (int i = 0; i < 5; i++) self->b[i].Set(0);
    int cells = (int)w3d_cx9c_ceilf_802e85fc(lbl_803cf8a8[0]);
    float a = lbl_803cf8ac[0], b = lbl_803cf8b0[0], c = lbl_803cf8b4[0];
    unsigned f = self->flags;
    f &= ~0x08000000;
    f &= ~0x02000000;
    self->f696 = cells << 13;
    self->f992 = 0;
    self->f996 = a;
    self->f1000 = a;
    self->f1004 = b;
    self->f1008 = c;
    self->flags = f;
    return self;
}
