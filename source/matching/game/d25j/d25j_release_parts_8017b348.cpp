// Release a node's two part references (Worms 3D GameCube PAL, 0x8017b348).
//
// Calls 0x801859f8 and keeps its result. Finds the shape registered under the
// key at +4 through the service object 0x804ab5fc and holds it in a one-word
// handle. Looks for part +124 (when set and its +20 is nonzero) or else part
// +120 in the shape's list. On a hit, tells the shape (0x801ef380), releases
// both parts, clears them and returns the kept result. On a miss, copies and
// destroys the node's name string and returns 0x80004005. Real virtual calls:
// -fvtable-thunks.

extern "C" void fn_8020c5c0(void *);
extern "C" unsigned short *fn_80341884(void *);
struct Str {
    char *text;
    Str(const Str &o) { fn_8020c5c0(this); text = o.text; ++*fn_80341884(this); }
    ~Str();
};
extern "C" void fn_8020c5c4(Str *);
extern "C" void fn_80341588(Str *);
inline Str::~Str() { fn_8020c5c4(this); fn_80341588(this); }
struct List { char u[24]; unsigned count; char u28[4]; void *items[1]; };
struct Counted { virtual void s8(); virtual void retain(); virtual void release(); };
struct Shape : Counted {
    char u4[40];
    List *list;
};
struct Part : Counted {
    char u4[16];
    int active;
};
struct Handle {
    Shape *p;
    Handle(Shape *v) { p = v; if (p) p->retain(); }
    Handle(const Handle &);
    ~Handle() { if (p) p->release(); }
};
struct Found { char u[20]; Shape *shape; };
struct Service {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60(); virtual void s64(); virtual void s68(); virtual void s72(); virtual void s76(); virtual void s80(); virtual void s84(); virtual void s88(); virtual void s92(); virtual void s96(); virtual void s100(); virtual void s104(); virtual void s108(); virtual void s112();
    virtual Found *find(void *key);
};
extern Service *service_804ab5fc;
struct Named { virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60(); virtual void s64(); virtual const Str *name(); };
struct SelfBase {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60();
    virtual Named *named();
};
struct Self : SelfBase {
    char key[116];
    Part *a;
    Part *b;
};
extern "C" int fn_801859f8(Self *);
extern "C" void fn_801ef380(Shape *, int, int, unsigned, int);
extern "C" int d25j_release_parts_8017b348(Self *self)
{
    int result = fn_801859f8(self);
    Handle h(service_804ab5fc->find(self->key)->shape);
    List *list = h.p->list;
    unsigned count = list->count;
    void **items = list->items;
    void *key = self->a;
    if (self->b && self->b->active) key = self->b;
    for (unsigned i = 0; i < count; i++) {
        if (items[i] == key) {
            Part *none = 0;
            fn_801ef380(h.p, 44, 3, i, 1);
            if (self->a) self->a->release();
            self->a = none;
            if (self->b) self->b->release();
            self->b = none;
            return result;
        }
    }
    Str s(*self->named()->name());
    return (int)0x80004005;
}
