// d29c: 0x800de988. Constructor of a particle-like part: clears the word vector, sets the table pointer at +228, builds the name string and three handles, then resets all state (zero vectors, empty name, flags). Names are inferred; classes are partial views; base and member constructors are written as explicit stores.
inline void *operator new(unsigned, void *p) { return p; }
struct Header { unsigned short refs; };
struct String {
    char *text; String(); String(const String &);
    void operator=(const String &o);
};
extern "C" void * string_default_803426b8(String *);
inline String::String() { string_default_803426b8(this); }
extern "C" void release_8020bb2c(void *);
inline void String::operator=(const String &o) {
    Header *n = (Header *)(o.text - 6);
    n->refs++;
    Header *h = (Header *)(text - 6);
    if (--h->refs == 0) release_8020bb2c(h);
    text = o.text;
}
extern String empty_804b06a0[];
struct W { int a, b, c; };
struct Vec { float x, y, z; void zero(float f) { x = f; y = f; z = f; } };
struct Obj { struct V { void *u[4]; void (*release)(Obj *); } *vt; };
extern W zero_8045e788[];
struct Ref {
    Obj *p;
    Ref() { p = 0; }
    void clear(int z) { if (p) p->vt->release(p); p = (Obj *)z; }
};
struct Data {
    int w[10]; char b40; char u41[3]; W vec; Ref a, b, c; int w68; char b72;
};
struct Part {
    int on; int flag; char u8[24]; int w32; float f36; char u40[4]; Vec v44, v56, v68; char u80[24]; int w104; char u108[4]; int w112; char u116[12];
    int *b, *e, *c; String s; int w144, w148; Data d; void **vt;
};
extern void *vt_8040ff68[];
extern "C" Part *d29c_part_construct_800de988(Part *self) {
    int z = 0;
    self->b = (int *)z; self->e = (int *)z; self->c = (int *)z;
    self->vt = vt_8040ff68;
    Data *d = &self->d;
    new (&self->s) String;
    new (&d->a) Ref; new (&d->b) Ref; new (&d->c) Ref;
    d->w[0] = z; d->w[1] = z; d->w[2] = z; d->w[3] = z; d->w[4] = z; d->w[5] = z; d->w[6] = z; d->w[7] = z; d->w[8] = z; d->w[9] = z;
    d->b40 = z;
    d->vec = zero_8045e788[0];
    d->a.clear(z);
    d->b.clear(z);
    d->c.clear(z);
    d->w68 = z;
    d->b72 = z;
    self->s = empty_804b06a0[0];
    float f = 0.0f;
    self->v68.zero(f);
    self->v44.zero(f);
    self->v56.zero(f);
    self->flag = z;
    self->w104 = z;
    self->w32 = z;
    self->d.w[0] = z;
    self->w144 = 1;
    self->w112 = z;
    self->d.w[9] = z;
    self->on = 1;
    self->f36 = f;
    self->w148 = z;
    return self;
}
