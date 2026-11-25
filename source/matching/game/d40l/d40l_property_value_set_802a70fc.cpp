// GWMP8P rev0 0x802a70fc. Sets a named integer property on a panel: looks
// the name up, checks its type chain and writes the value to the field the
// panel selects. Self, Ctl and Data are partial views. The discarded by-
// value Str copy before the error report is witnessed by its copy and
// destructor calls in the original; it is probably compiled-out trace code.
// A Ref assignment that skips a null source is witnessed by the branch
// target.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020c5c0(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
struct Str {
    char *p;
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Header *h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(unsigned short *)(p - 4); }
};
inline void use(Str) {}
extern "C" void fn_8020c510(Str *, const char *, ...);
extern "C" void fn_80178474(void *, int);
struct Descriptor_80178474 { int zero; unsigned type; Descriptor_80178474() : zero(0), type(58280) {} ~Descriptor_80178474(); };
struct Ctl;
struct CtlVt { char u0[12]; void (*add)(Ctl *); void (*release)(Ctl *); };
struct Ctl { CtlVt *vt; char u4[16]; int w20, w24, w28, w32; };
struct Ref {
    Ctl *p;
    Ref() { p = 0; }
    Ref(Ctl *c) { p = c; if (p) p->vt->add(p); }
    Ref(const Ref &);
    ~Ref() { if (p) p->vt->release(p); }
    void operator=(const Ref &o) {
        Ctl *q = o.p;
        if (q) {
            q->vt->add(q);
            if (p) p->vt->release(p);
            p = q;
        }
    }
};
struct Type { char u0[20]; Type *parent; };
extern Type type_80366578[];
inline bool derived(Type *t) {
    while (t != type_80366578) {
        Type *parent = t->parent;
        if (t == parent)
            return false;
        t = parent;
    }
    return true;
}
struct Res;
struct ResVt { char u0[16]; void (*destroy)(Res *); char u20[4]; int (*kind)(Res *); };
struct Res { ResVt *vt; };
struct Handle {
    Res *r;
    Handle() { r = 0; }
    Handle(const Handle &);
    ~Handle() { if (r) r->vt->destroy(r); }
};
struct Key { const char *text; };
struct Data;
struct DataVt { char u0[20]; Type *(*type)(Data *); };
struct Data { DataVt *vt; };
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
inline Str &name(Self *s) { int p = (s->index << 2) + (int)s; p += 460; return *(Str *)p; }
extern const char s_803d6164[];
extern "C" int fn_800fc1b0(Key *, Handle *);
extern "C" void *fn_80341584(Res *);
extern "C" Data *fn_801797b4(void *);
extern "C" Ctl *fn_80179598(void *, Descriptor_80178474 *);
extern "C" void fn_802a6ce8(Self *);
inline bool check(Data *x) { return derived(x->vt->type(x)); }
extern "C" void d40l_property_value_set_802a70fc(Self *self, int value) {
    self->value = value;
    if (name(self).len()) {
        Descriptor_80178474 d;
        self->w372 = 1;
        Handle h;
        Key k;
        k.text = name(self).p;
        if (fn_800fc1b0(&k, &h) < 0) {
            use(name(self));
            fn_8020c510(&self->message, s_803d6164, name(self).p);
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
