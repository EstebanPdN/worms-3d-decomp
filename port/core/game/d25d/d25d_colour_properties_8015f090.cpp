#include "w3d_ptr.h"
#line 1 "d25d_colour_properties_8015f090.cpp"
// GWMP8P rev0 0x8015f090. Start of a property-owning object: set its colour
// to opaque black through virtual +52, create four properties from the
// descriptors at 0x80415c30, 0x80415c20, 0x80415c40 and 0x80415bd0 with
// values 2, 2, 3 and 0, mark them and add them to the target through +80.
// Then clone every existing property of the target (list from +88) through
// the service object for 0x804143e0, keep the retained clones in a local
// array and add them all. Names are inferred.
struct Object;
struct ObjectVt { Ptr32<void> u0[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVt> vt; };
struct Flags { int u0; unsigned char bits; unsigned char u4[3]; void set(unsigned char b) { bits |= b; } };
struct Prop : Object { Flags flags __attribute__((aligned(__alignof__(Object)))); unsigned char u12[12]; int value; void init(int v) { value = v; flags.set(2); } };
struct Maker;
struct MakerVt { Ptr32<void> u[11]; Ptr32<Ptr32<Prop> (Ptr32<Maker>, Ptr32<Prop>)> make; };
struct PropRef {
    Ptr32<Prop> p;
    template <class W3dU> PropRef(Ptr32<W3dU> w3d_p) : PropRef((Prop *)w3d_p.get()) {}
 PropRef(Prop *o) { p = o; if (p) ((Ptr32<Object>)p)->vt->retain(p); }
    PropRef(const PropRef &);
    ~PropRef() { if (p) ((Ptr32<Object>)p)->vt->release(p); }
    Ptr32<Prop> operator->() const { return p; }
};
struct Maker { Ptr32<MakerVt> vt; };
struct Factory;
struct FactoryVt { Ptr32<void> u[23]; Ptr32<Ptr32<Prop> (Ptr32<Factory>, Ptr32<const void>)> create; };
struct Factory { Ptr32<FactoryVt> vt; };
struct Target;
struct TargetVt { Ptr32<void> u0[20]; Ptr32<void (Ptr32<Target>, Ptr32<Prop>)> add; Ptr32<void> u84; Ptr32<Ptr32<Ptr32<Prop>> (Ptr32<Target>, Ptr32<unsigned int>)> list; };
struct Target { Ptr32<TargetVt> vt; };
struct Color { float r, g, b, a; Color(float x, float y, float z, float w) { r=x; g=y; b=z; a=w; } };
struct Self;
struct SelfVt { Ptr32<void> u[13]; Ptr32<int (Ptr32<Self>, Ptr32<Color>)> set; };
struct Self { Ptr32<SelfVt> vt; };
struct Slot {
    Ptr32<Prop> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Prop *)w3d_p.get()); }
 Slot &operator=(Prop *n) { if (n) ((Ptr32<Object>)n)->vt->retain(n); if (p) ((Ptr32<Object>)p)->vt->release(p); p = n; return *this; }
};
struct Array {
    unsigned count; short a, b; Ptr32<Slot> data;
    Array(); ~Array(); void resize(unsigned);
};
struct Arr2 : Array { Arr2() {} ~Arr2() {}
};
extern "C" Ptr32<Prop> forward_8020b680(Ptr32<const void>);
extern "C" Ptr32<Factory> service_8020b648();
inline Ptr32<Prop> lookup(Ptr32<const void> key) { Ptr32<Factory> fa = service_8020b648(); return fa->vt->create(fa, key); }
extern const unsigned char t0_80415c30[], t1_80415c20[], t2_80415c40[], t3_80415bd0[], t4_804143e0[];
extern "C" void d25d_colour_properties_8015f090(Ptr32<Self> self, Ptr32<Target> t) {
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
    Ptr32<Ptr32<Prop>> list = t->vt->list(t, &n);
    PropRef f(lookup(t4_804143e0));
    unsigned i = 0;
    Arr2 arr;
    arr.resize(n);
    for (; i < n; i++) {
        list[i]->flags.set(1);
        Ptr32<Slot> data = arr.data;
        data[i] = ((Ptr32<Maker>)f.p)->vt->make((Ptr32<Maker>)f.p, list[i]);
    }
    for (i = 0; i < n; i++) t->vt->add(t, arr.data[i].p);
}


