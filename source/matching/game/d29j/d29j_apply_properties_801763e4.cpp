// Apply a set's properties. For each property calls its prepare slot, then by
// its type passes the value view to the matching applier: types 0, 1, 2 and 5
// directly, type 3 copies the returned vector, type 4 copies and releases the
// returned string. An unknown type sets the result to E_FAIL and the loop goes
// on. Slot and helper meanings are inferred. GWMP8P rev0 0x801763e4.
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
struct Vec { float x, y, z;
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Prop {
    virtual void s8(); virtual void s12(); virtual void s16(); virtual void s20();
    virtual int type();
    virtual void s28();
    virtual void prepare();
};
struct P0; struct P1; struct P2; struct P3; struct P4; struct P5;
extern "C" P0 *fn_803426b4(Prop *);
extern "C" P1 *fn_80342a78(Prop *);
extern "C" P2 *fn_80342a74(Prop *);
extern "C" P3 *fn_80342fa4(Prop *);
extern "C" P4 *fn_80343744(Prop *);
extern "C" P5 *fn_80341584(Prop *);
extern "C" int fn_80178c48(P0 *);
extern "C" int fn_80178d1c(P1 *);
extern "C" float fn_80178df0(P2 *);
extern "C" const Vec *fn_80178ec4(P3 *);
extern "C" const Str *fn_80179170(P4 *);
extern "C" int fn_801797b4(P5 *);
struct Set { char u[24]; Prop **props; char u1c[2088]; unsigned count; };
extern "C" int d29j_apply_properties_801763e4(Set *self)
{
    int hr = 0;
    for (unsigned i = 0; i < self->count; ++i) {
        if (self->props[i]) {
            self->props[i]->prepare();
            switch (self->props[i]->type()) {
            case 0: fn_80178c48(fn_803426b4(self->props[i])); break;
            case 1: fn_80178d1c(fn_80342a78(self->props[i])); break;
            case 2: fn_80178df0(fn_80342a74(self->props[i])); break;
            case 3: { Vec v(*fn_80178ec4(fn_80342fa4(self->props[i]))); break; }
            case 4: { Str s(*fn_80179170(fn_80343744(self->props[i]))); break; }
            case 5: fn_801797b4(fn_80341584(self->props[i])); break;
            default: hr = 0x80004005; break;
            }
        }
    }
    return hr;
}
