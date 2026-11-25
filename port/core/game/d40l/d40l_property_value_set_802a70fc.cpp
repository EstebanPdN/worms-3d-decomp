#include "w3d_ptr.h"
#line 1 "d40l_property_value_set_802a70fc.cpp"
// GWMP8P rev0 0x802a70fc. Sets a named integer property on a panel: looks
// the name up, checks its type chain and writes the value to the field the
// panel selects. Self, Ctl and Data are partial views. The discarded by-
// value Str copy before the error report is witnessed by its copy and
// destructor calls in the original; it is probably compiled-out trace code.
// A Ref assignment that skips a null source is witnessed by the branch
// target.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(Ptr32<unsigned short>)(p - 4); }
};
inline void use(Str) {}
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
extern "C" void fn_80178474(Ptr32<void>, int);
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
struct Ctl;
struct CtlVt { char u0[12]; Ptr32<void (Ptr32<Ctl>)> add; Ptr32<void (Ptr32<Ctl>)> release; };
struct Ctl { Ptr32<CtlVt> vt; char u4[16]; int w20, w24, w28, w32; };
struct Ref {
    Ptr32<Ctl> p;
    Ref() { p = 0; }
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Ctl *)w3d_p.get()) {}
 Ref(Ctl *c) { p = c; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    void operator=(const Ref &o) {
        Ptr32<Ctl> q = o.p;
        if (q) {
            q->vt->add(q);
            if (p) p->vt->release(p);
            p = q;
        }
    }
};
struct Type { char u0[20]; Ptr32<Type> parent; };
extern Type type_80366578[];
inline bool derived(Ptr32<Type> t) {
    while (t != type_80366578) {
        Ptr32<Type> parent = t->parent;
        if (t == parent)
            return false;
        t = parent;
    }
    return true;
}
struct Res;
struct ResVt { char u0[16]; Ptr32<void (Ptr32<Res>)> destroy; char u20[4]; Ptr32<int (Ptr32<Res>)> kind; };
struct Res { Ptr32<ResVt> vt; };
struct Handle {
    Ptr32<Res> r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Key { Ptr32<const char> text; };
struct Data;
struct DataVt { char u0[20]; Ptr32<Ptr32<Type> (Ptr32<Data>)> type; };
struct Data { Ptr32<DataVt> vt; };
struct Self {
    char u0[108];
    Str message;
    char u112[260];
    int w372;
    char u376[84];
    Str names[35];
    int index;
    char u604[8];
    unsigned field;
    int value;
};
inline Str &name(Ptr32<Self> s) { int p = (s->index << 2) + (int)w3d::H(s); p += 460; return *(Ptr32<Str>)w3d::G(p); }
extern const char s_803d6164[];
extern "C" int fn_800fc1b0(Ptr32<Key>, Ptr32<Handle>);
extern "C" Ptr32<void> fn_80341584(Ptr32<Res>);
extern "C" Ptr32<Data> fn_801797b4(Ptr32<void>);
extern "C" Ptr32<Ctl> fn_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
extern "C" void fn_802a6ce8(Ptr32<Self>);
inline bool check(Ptr32<Data> x) { return derived(x->vt->type(x)); }
extern "C" void d40l_property_value_set_802a70fc(Ptr32<Self> self, int value) {
    self->value = value;
    if (name(self).len()) {
        Descriptor_80178474 d;
        self->w372 = 1;
        Handle h;
        Key k;
        k.text = name(self).p;
        if (fn_800fc1b0(&k, &h) < 0) {
            use(name(self));
            fn_8020c510(&self->message, s_803d6164, w3d::VA(name(self).p));
            return;
        }
        if (h.r->vt->kind(h.r) == 5 && check(fn_801797b4(fn_80341584(h.r)))) {
            Ref r;
            r = Ref(fn_80179598(fn_80341584(h.r), &d));
            switch (self->field) {
            case 0:
                r.p->w32 = self->value;
                break;
            case 1:
                r.p->w24 = self->value;
                break;
            case 2:
                r.p->w20 = self->value;
                break;
            default:
                r.p->w28 = self->value;
                break;
            }
        }
    }
    self->w372 = 0;
    fn_802a6ce8(self);
}


