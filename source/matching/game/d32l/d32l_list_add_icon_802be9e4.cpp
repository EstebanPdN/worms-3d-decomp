// GWMP8P rev0 0x802be9e4. Text list: adds one icon cell of the current row.
// Sizes it from the row's aspect and percentage against the list width,
// parses a 'name:frame' string, creates the sprite, stores the frame byte,
// places it by alignment and appends the 24-byte record to a real STLport
// vector.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Str;
extern "C" void fn_8020c5c0(Str *), fn_8020c5c4(Str *), fn_80341588(Str *), fn_8020bb2c(void *);
struct Str {
    char *p;
    Str();
    Str(const Str &);
    ~Str() { Str *u = this; fn_8020c5c4(u); fn_80341588(u); }
    Str &operator=(const char *);
    Str &operator+=(const char *);
    Str &operator=(const Str &o) {
        ++*(unsigned short *)(o.p - 6);
        unsigned short *h = (unsigned short *)(p - 6);
        if (--*h == 0) fn_8020bb2c(h);
        p = o.p;
        return *this;
    }
    unsigned length() const { return *(unsigned short *)(p - 4); }
};
struct Colour { signed char r, g, b; unsigned char a; };
struct Key { const char *name; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Res;
struct ResVt { void *u[3]; void (*retain)(Res *); void (*release)(Res *); void *u20[14]; void (*setpos)(Res *, const Vec *, int); void *u80; void (*setscale)(Res *, const Vec *, int); void *u88; void (*add)(Res *, Res *, int); };
struct Res { ResVt *vt; };
struct Ref {
    Res *p;
    Ref() { p = 0; }
    Ref(const Ref &o) { p = o.p; if (p) p->vt->retain(p); }
    ~Ref() { if (p) p->vt->release(p); }
    Ref &operator=(const Ref &);
};
struct Rec { Ref h; float x, y; Colour c; float sx, sy; };
template <class T> struct Arr { char u[24]; unsigned count; char u28[4]; T data[1]; T &At(unsigned i) { T *d = data; return *(T *)(i * 4 + (int)d); } };
struct Row { char u0[24]; Arr<Str> *strs; int align; float aspect; float pct; char u40[4]; int fixedw;  Arr<Colour> *cols; };
struct Desc { char u0[20]; float size; Str font; char u28[4]; Arr<Row *> *rows; };
struct Font;
struct Face;
struct FaceVt { void *u[16]; int (*ready)(Face *); void *u68; unsigned char *(*name)(Face *); };
struct Face { FaceVt *vt; };
struct Self {
    unsigned cur; unsigned char alpha; char u5[31]; float f36; char u40[12]; float f52; float f56; float f60; float f64; void *w68; char u72[4]; float f76;
    std::vector<Rec> recs;
    Res *parent;
    char u100[39];
    unsigned char style;
};
extern "C" {
float fn_80178df0(void *);
char *strstr(const char *, const char *);
long atol(const char *);
void fn_8020c3a0(Str *, int);
Str *fn_8020c0fc(Str *, Str *, int);
Res *fn_8034357c(Res *);
int fn_80173f88(Res *, const unsigned char &);
int fn_80173df0(Res *, const Colour *);
unsigned fn_8020c5cc(const Str *);
float fn_802c0cf0(Self *, const char *, float, float, Desc *);
unsigned strlen(const char *);
Face *fn_8015ae3c(const Str &);
Font *fn_8034435c(Face *);
void fn_8015aee8(int);
float fn_8018b4cc(Font *, const char *);
unsigned fn_8018b524(Font *, const char *, float, float);
void fn_8020c43c(Str *, const char *, unsigned);
int fn_800fc1b0(const Key &, Res **);
int fn_800fc370(const Key &, Colour *);
Res *fn_80343744(Res *);
const Str &fn_80179170(Res *);
int fn_8015adf4(const Str &, Ref *, unsigned char);
Res *fn_80343580(Res *);
int fn_8018c5b0(Res *, const char *);
int fn_8018d35c(Res *, const Colour *);
int fn_8018d434(Res *, const Colour *);
unsigned char fn_802bf798(Self *);
}
extern "C" void fn_8020c510(Str *, const char *, ...);
extern char lbl_803d83ac[], lbl_803d83c0[], lbl_803d83c4[], lbl_803d83e4[], lbl_803d8438[];
extern "C" void d32l_list_add_icon_802be9e4(Self *self, int index, Desc *d) {
    Str a, b, c;
    Rec rec;
    Row *row = d->rows->At(index);
    if (row->strs->count <= self->cur) return;
    float h = row->aspect;
    float w = row->pct;
    if (h == 0.0f) h = w;
    h /= w;
    float border = fn_80178df0(self->w68);
    float limit = (self->f36 - (border + border)) * 2.0f;
    limit = self->f36 - (border + border);
    limit = limit + limit;
    if (w > limit) w = limit;
    h *= w;
    float x = self->f52 - self->f56;
    rec.sx = w;
    float full = w + 1.0f;
    rec.sy = h;
    rec.x = x;
    float room = self->f56 - full;
    rec.y = self->f52 - room;
    self->f56 = room;
    if (room < 0.0f) {
        self->f56 = 0.0f;
        self->recs.push_back(rec);
        return;
    }
    a = row->strs->At(self->cur);
    b = a;
    const char *s = a.p;
    long n = 0;
    if (strlen(s) <= 2) {
        self->recs.push_back(rec);
        return;
    }
    const char *p = strstr(s, lbl_803d83e4);
    if (p) {
        int off = p - s;
        fn_8020c3a0(&b, off);
        int rest = a.length() - 1;
        if (rest != off) {
            fn_8020c0fc(&c, &a, rest - off);
            n = atol(c.p);
        }
    }
    Vec v;
    Vec *pv = &v;
    fn_8015adf4(b, &rec.h, self->style + 30);
    Res *obj = fn_8034357c(rec.h.p);
    v.x = h * 0.5f;
    v.y = w * 0.5f;
    pv->z = 1.0f;
    obj->vt->setscale(obj, pv, 0);
    self->recs.push_back(rec);
    self->parent->vt->add(self->parent, obj, 0);
    fn_80173f88(obj, n);
    float px;
    switch (row->align) {
    case 0: case 3: case 6:
        px = x + w * 0.5f;
        break;
    case 2: case 5: case 8:
        px = x + (full - w * 0.5f + 2.0f);
        break;
    default:
        px = x + full * 0.5f;
        break;
    }
    v.Set(px, 0.0f, 0.0f);
    obj->vt->setpos(obj, &v, 0);
    unsigned char al = self->alpha = fn_802bf798(self);
    Colour col;
    col.r = -1;
    col.g = -1;
    col.b = -1;
    col.a = al;
    fn_80173df0(obj, &col);
    float t = (self->f64 + self->f60) / (self->f36 + self->f36);
    if (t > 1.0f) t = 1.0f;
    v.Set(h * 0.5f, (w - w * t) * 0.5f, 1.0f);
    obj->vt->setscale(obj, &v, 0);
}
