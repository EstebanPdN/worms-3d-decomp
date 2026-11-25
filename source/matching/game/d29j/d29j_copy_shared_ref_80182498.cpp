// Copy a shared reference from another node, GWMP8P rev0 0x80182498. Checks flag
// 8 of the object's type; without it the type's name string is copied and
// released and the call returns E_FAIL (0x80004005). Otherwise item 11's data
// takes the other object's counted reference, retaining the new value and
// releasing the old one. Virtual slot meanings and field names are inferred.
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
struct TypeBase {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60(); virtual void s64();
    virtual const Str *name();
};
struct Type : TypeBase { char u[32]; unsigned short flags; };
struct Info;
extern "C" Type *fn_80341348(Info *);
struct Counted { virtual void s8(); virtual void retain(); virtual void release(); };
struct Ref { Counted *p;
    Ref &operator=(const Ref &o) { Counted *old = p; p = o.p; if (p) p->retain(); if (old) old->release(); return *this; }
};
struct Data { char u[48]; Ref ref; };
struct Item { char u[32]; Data *data; };
struct Node { Item *slot[12]; };
struct ObjBase {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60();
    virtual Info *info();
};
struct Obj : ObjBase {
    char u[116];
    Node *items;
};
extern "C" int d29j_copy_shared_ref_80182498(Obj *self, Obj *o)
{
    if (!(fn_80341348(self->info())->flags & 8)) {
        Str s(*fn_80341348(self->info())->name());
        return 0x80004005;
    }
    int k = 11; Node &x = *o->items; Node &y = *self->items; Item &b = *x.slot[k]; Item &a = *y.slot[k];
    a.data->ref = b.data->ref;
    return 0;
}
