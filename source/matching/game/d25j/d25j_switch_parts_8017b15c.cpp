// Switch a node between its two parts (Worms 3D GameCube PAL, 0x8017b15c).
//
// Holds the shape found under the key at +4 in a one-word handle and calls
// 0x8017b6dc. With the flag set it looks for part +124 in the shape's list; on a
// hit it tells the shape (0x801ef380, 0x801ef174 with part +120) and clears the
// reference at +20 of part +124. With the flag clear it looks for part +120; on
// a hit it tells the shape, with part +124, and stores part +120 in that
// reference with retain and release. Returns 0, or 0x80004005 on a miss. Same
// classes as d25j_release_parts_8017b348. Real virtual calls: -fvtable-thunks.

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
    Part *ref;
    void set(Part *v) { Part *o = ref; ref = v; if (v) v->retain(); if (o) o->release(); }
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
extern "C" void fn_8017b6dc(Self *);
extern "C" void fn_801ef380(Shape *, int, int, unsigned, int);
extern "C" void fn_801ef174(Shape *, int, int, Part *);
extern "C" int d25j_switch_parts_8017b15c(Self *self, int on)
{
    Handle h(service_804ab5fc->find(self->key)->shape);
    List *list = h.p->list;
    unsigned count = list->count;
    void **items = list->items;
    fn_8017b6dc(self);
    if (on) {
        for (unsigned i = 0; i < count; i++) {
            if (items[i] == self->b) {
                fn_801ef380(h.p, 44, 3, i, 1);
                fn_801ef174(h.p, 44, 3, self->a);
                Part *b = self->b;
                Part *none = 0;
                Part *o = b->ref;
                b->ref = none;
                if (o) o->release();
                return 0;
            }
        }
    } else {
        for (unsigned i = 0; i < count; i++) {
            if (items[i] == self->a) {
                fn_801ef380(h.p, 44, 3, i, 1);
                fn_801ef174(h.p, 44, 3, self->b);
                self->b->set(self->a);
                return 0;
            }
        }
    }
    return (int)0x80004005;
}
