// GWMP8P rev0 0x8015f090. Start of a property-owning object: set its colour
// to opaque black through virtual +52, create four properties from the
// descriptors at 0x80415c30, 0x80415c20, 0x80415c40 and 0x80415bd0 with
// values 2, 2, 3 and 0, mark them and add them to the target through +80.
// Then clone every existing property of the target (list from +88) through
// the service object for 0x804143e0, keep the retained clones in a local
// array and add them all. Names are inferred.
struct Object;
struct ObjectVt { void *u0[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVt *vt; };
struct Flags { int u0; unsigned char u4[3]; unsigned char bits; void set(unsigned char b) { bits |= b; } };
struct Prop : Object { Flags flags; unsigned char u12[12]; int value; void init(int v) { value = v; flags.set(2); } };
struct Maker;
struct MakerVt { void *u[11]; Prop *(*make)(Maker *, Prop *); };
struct PropRef {
    Prop *p;
    PropRef(Prop *o) { p = o; if (p) ((Object *)p)->vt->retain(p); }
    PropRef(const PropRef &);
    ~PropRef() { if (p) ((Object *)p)->vt->release(p); }
    Prop *operator->() const { return p; }
};
struct Maker { MakerVt *vt; };
struct Factory;
struct FactoryVt { void *u[23]; Prop *(*create)(Factory *, const void *); };
struct Factory { FactoryVt *vt; };
struct Target;
struct TargetVt { void *u0[20]; void (*add)(Target *, Prop *); void *u84; Prop **(*list)(Target *, unsigned *); };
struct Target { TargetVt *vt; };
struct Color { float r, g, b, a; Color(float x, float y, float z, float w) { r=x; g=y; b=z; a=w; } };
struct Self;
struct SelfVt { void *u[13]; int (*set)(Self *, Color *); };
struct Self { SelfVt *vt; };
struct Slot {
    Prop *p;
    Slot &operator=(Prop *n) { if (n) ((Object *)n)->vt->retain(n); if (p) ((Object *)p)->vt->release(p); p = n; return *this; }
};
struct Array {
    unsigned count; short a, b; Slot *data;
    Array(); ~Array(); void resize(unsigned);
};
struct Arr2 : Array { Arr2() {} ~Arr2() {}
};
extern "C" Prop *forward_8020b680(const void *);
extern "C" Factory *service_8020b648();
inline Prop *lookup(const void *key) { Factory *fa = service_8020b648(); return fa->vt->create(fa, key); }
extern const unsigned char t0_80415c30[], t1_80415c20[], t2_80415c40[], t3_80415bd0[], t4_804143e0[];
extern "C" void d25d_colour_properties_8015f090(Self *self, Target *t) {
    Color c(0.0f, 0.0f, 0.0f, 1.0f);
    self->vt->set(self, &c);
    PropRef a(forward_8020b680(t0_80415c30));
    a.p->init(2);
    t->vt->add(t, a.p);
    PropRef b(forward_8020b680(t1_80415c20));
    b.p->init(2);
    t->vt->add(t, b.p);
    PropRef d(forward_8020b680(t2_80415c40));
    d.p->init(3);
    t->vt->add(t, d.p);
    PropRef e(forward_8020b680(t3_80415bd0));
    e.p->init(0);
    t->vt->add(t, e.p);
    unsigned n;
    Prop **list = t->vt->list(t, &n);
    PropRef f(lookup(t4_804143e0));
    unsigned i = 0;
    Arr2 arr;
    arr.resize(n);
    for (; i < n; i++) {
        list[i]->flags.set(1);
        Slot *data = arr.data;
        data[i] = ((Maker *)f.p)->vt->make((Maker *)f.p, list[i]);
    }
    for (i = 0; i < n; i++) t->vt->add(t, arr.data[i].p);
}
