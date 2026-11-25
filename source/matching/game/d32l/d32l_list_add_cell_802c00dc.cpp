// GWMP8P rev0 0x802c00dc. Text list: adds one cell of the current row. Picks
// the cell text and colour, reads the tool-tip style text through the string
// table, fits it to the column width with an ellipsis, creates and places a
// text object and appends the 24-byte record to a real STLport vector.
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
struct Colour { unsigned char r, g, b, a; };
struct Key { const char *name; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
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
struct Row { char u0[24]; Arr<Str> *strs; int align; char u32[4]; float pct; char u40[8]; Arr<Colour> *volatile cols; };
struct Desc { char u0[20]; float size; Str font; char u28[4]; Arr<Row *> *rows; };
struct Font;
struct Face;
struct FaceVt { void *u[16]; int (*ready)(Face *); void *u68; unsigned char *(*name)(Face *); };
struct Face { FaceVt *vt; };
struct Self {
    unsigned cur; unsigned char alpha; char u5[47]; float f52; float f56; char u60[16]; float f76;
    std::vector<Rec> recs;
    Res *parent;
    char u100[39];
    unsigned char style;
};
extern "C" {
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
extern char lbl_803d83ac[], lbl_803d83c0[], lbl_803d83c4[], lbl_803d8438[], lbl_803d843c[];
extern "C" void d32l_list_add_cell_802c00dc(Self *self, int index, Desc *d) {
    float size = d->size;
    if (size == 0.0f) size = self->f76;
    Vec scale(size, size, 1.0f);
    Str text, shown, raw;
    Rec rec;
    unsigned cur = self->cur;
    Row *row = d->rows->At(index);
    if (row->strs->count <= cur) return;
    float width = self->f52 * 2.0f * (row->pct / 100.0f) - 4.0f;
    float room = self->f56;
    if (width > room) width = room - 2.0f;
    if (width < 0.0f) width = 0.0f;
    self->f56 = room - (width + 4.0f);
    rec.y = self->f52 - self->f56;
    rec.x = self->f52 - room;
    float y = self->f52 - (room + 4.0f) + 2.0f;
    raw = row->strs->At(self->cur);
    Colour col;
    if (row->cols->count <= self->cur) {
        Key k;
        k.name = lbl_803d83ac;
        fn_800fc370(k, &col);
    } else col = row->cols->At(self->cur);
    rec.c = col;
    if (raw.length() == 0) text = lbl_803d8438;
    else {
        Key k;
        k.name = raw.p;
        Ref h;
        if (fn_800fc1b0(k, &h.p) >= 0) text = fn_80179170(fn_80343744(h.p));
        else text = lbl_803d843c;
    }
    const char *t = text.p;
    unsigned len = strlen(t);
    Face *face = fn_8015ae3c(d->font);
    Font *font = fn_8034435c(face);
    if (face->vt->ready(face) == 0) fn_8015aee8(*face->vt->name(face));
    float dots = fn_8018b4cc(font, lbl_803d83c0) * size;
    unsigned fit = fn_8018b524(font, t, width, size);
    rec.sx = scale.x;
    if (fit == 0) {
        self->recs.push_back(rec);
        return;
    }
    if (fit == len) fn_8020c510(&shown, lbl_803d83c4, t);
    else {
        unsigned n = fn_8018b524(font, t, width - dots, size);
        if (n == 0) fn_8020c43c(&shown, t, fit);
        else {
            fn_8020c43c(&shown, t, n);
            shown += lbl_803d83c0;
        }
    }
    float w = fn_8018b4cc(font, shown.p) * size;
    fn_8015adf4(d->font, &rec.h, self->style + 30);
    Res *obj = fn_80343580(rec.h.p);
    obj->vt->setscale(obj, &scale, 0);
    self->recs.push_back(rec);
    self->parent->vt->add(self->parent, obj, 0);
    fn_8018c5b0(obj, shown.p);
    switch (row->align) {
    case 0: case 3: case 6:
        y += w * 0.5f;
        break;
    case 2: case 5: case 8:
        y += width - w * 0.5f;
        break;
    default:
        y += width * 0.5f;
        break;
    }
    Vec pos(y, 0.0f, 0.0f);
    obj->vt->setpos(obj, &pos, 0);
    col.a = self->alpha = fn_802bf798(self);
    fn_8018d35c(obj, &col);
    unsigned char al = self->alpha;
    col.r = 0;
    col.g = 0;
    col.b = 0;
    col.a = al;
    fn_8018d434(obj, &col);
    scale.y *= (float)self->alpha / 255.0f;
    obj->vt->setscale(obj, &scale, 0);
}
