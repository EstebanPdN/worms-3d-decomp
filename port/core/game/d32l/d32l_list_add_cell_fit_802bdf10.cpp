#include "w3d_ptr.h"
#line 1 "d32l_list_add_cell_fit_802bdf10.cpp"
// GWMP8P rev0 0x802bdf10. Text list: adds one cell of the current row, like
// 0x802c00dc, with a negative column percentage meaning shrink-to-fit and a
// row flag fixing the width from the measured text. Fits the text with an
// ellipsis, creates and places a text object and appends the 24-byte record
// to a real STLport vector.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Str;
extern "C" void fn_8020c5c0(Ptr32<Str>), fn_8020c5c4(Ptr32<Str>), fn_80341588(Ptr32<Str>), fn_8020bb2c(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    Str();
    Str(const Str &);
    ~Str() { Ptr32<Str> u = this; fn_8020c5c4(u); fn_80341588(u); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((const char *)w3d_p.get()); }
 Str &operator=(const char *);
    Str &operator+=(const char *);
    Str &operator=(const Str &o) {
        ++*(Ptr32<unsigned short>)(o.p - 6);
        Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
        if (--*h == 0) fn_8020bb2c(h);
        p = o.p;
        return *this;
    }
    unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); }
};
struct Colour { unsigned char r, g, b, a; };
struct Key { Ptr32<const char> name; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Res;
struct ResVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Res>)> retain; Ptr32<void (Ptr32<Res>)> release; Ptr32<void> u20[14]; Ptr32<void (Ptr32<Res>, Ptr32<const Vec>, int)> setpos; Ptr32<void> u80; Ptr32<void (Ptr32<Res>, Ptr32<const Vec>, int)> setscale; Ptr32<void> u88; Ptr32<void (Ptr32<Res>, Ptr32<Res>, int)> add; };
struct Res { Ptr32<ResVt> vt; };
struct Ref {
    Ptr32<Res> p;
    Ref() { p = 0; }
    Ref(const Ref &o) { p = o.p; if (p) p->vt->retain(p); }
    ~Ref() { if (p) p->vt->release(p); }
    Ref &operator=(const Ref &);
};
struct Rec { Ref h; float x, y; Colour c; float sx, sy; };
template <class T> struct Arr { char u[24]; unsigned count; char u28[4]; T data[1]; T &At(unsigned i) { Ptr32<T> d = data; return *(Ptr32<T>)(i * 4 + (int)d); } };
struct Row { char u0[24]; Ptr32<Arr < Str >> strs; int align; char u32[4]; float pct; char u40[4]; int fixedw;  Ptr32<Arr < Colour >> volatile cols; };
struct Desc { char u0[20]; float size; Str font; char u28[4]; Ptr32<Arr <Ptr32<Row> >> rows; };
struct Font;
struct Face;
struct FaceVt { Ptr32<void> u[16]; Ptr32<int (Ptr32<Face>)> ready; Ptr32<void> u68; Ptr32<Ptr32<unsigned char> (Ptr32<Face>)> name; };
struct Face { Ptr32<FaceVt> vt; };
struct Self {
    unsigned cur; unsigned char alpha; char u5[47]; float f52; float f56; char u60[16]; float f76;
    std::vector<Rec> recs;
    Ptr32<Res> parent;
    char u100[36];
    unsigned char style; char w3d_tag_rest[3];  // palabra en PPC +0x88 escrita con stw; lbz +0x8b es el byte bajo
};
extern "C" {
unsigned fn_8020c5cc(Ptr32<const Str>);
float fn_802c0cf0(Ptr32<Self>, Ptr32<const char>, float, float, Ptr32<Desc>);
unsigned strlen(Ptr32<const char>);
Ptr32<Face> fn_8015ae3c(const Str &);
Ptr32<Font> fn_8034435c(Ptr32<Face>);
void fn_8015aee8(int);
float fn_8018b4cc(Ptr32<Font>, Ptr32<const char>);
unsigned fn_8018b524(Ptr32<Font>, Ptr32<const char>, float, float);
void fn_8020c43c(Ptr32<Str>, Ptr32<const char>, unsigned);
int fn_800fc1b0(const Key &, Ptr32<Ptr32<Res>>);
int fn_800fc370(const Key &, Ptr32<Colour>);
Ptr32<Res> fn_80343744(Ptr32<Res>);
const Str &fn_80179170(Ptr32<Res>);
int fn_8015adf4(const Str &, Ptr32<Ref>, unsigned char);
Ptr32<Res> fn_80343580(Ptr32<Res>);
int fn_8018c5b0(Ptr32<Res>, Ptr32<const char>);
int fn_8018d35c(Ptr32<Res>, Ptr32<const Colour>);
int fn_8018d434(Ptr32<Res>, Ptr32<const Colour>);
unsigned char fn_802bf798(Ptr32<Self>);
}
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
extern char lbl_803d83ac[], lbl_803d83c0[], lbl_803d83c4[], lbl_803d8438[];
extern "C" void d32l_list_add_cell_fit_802bdf10(Ptr32<Self> self, int index, Ptr32<Desc> d) {
    float size = d->size;
    if (size == 0.0f) size = self->f76;
    Str text, shown;
    Rec rec;
    Ptr32<Row> row = d->rows->At(index);
    if (row->strs->count <= self->cur) return;
    float pct = row->pct;
    bool shrink = false;
    int fixed = row->fixedw;
    if (pct < 0.0f) { pct = -pct; shrink = true; }
    float width = self->f52 * 2.0f * (pct / 100.0f) - 4.0f;
    float room = self->f56;
    if (width > room) width = room - 2.0f;
    if (width < 0.0f) width = 0.0f;
    float y = self->f52 - (room + 4.0f) + 2.0f;
    rec.x = self->f52 - room;
    if (!fixed) {
        self->f56 = room - (width + 4.0f);
        rec.y = self->f52 - self->f56;
    }
    text = row->strs->At(self->cur);
    Colour col;
    if (row->cols->count <= self->cur) {
        Key k;
        k.name = lbl_803d83ac;
        fn_800fc370(k, &col);
    } else col = row->cols->At(self->cur);
    rec.c = col;
    Ptr32<const char> t = text.p;
    Ptr32<Str> tp = &text;
    unsigned len = fn_8020c5cc(tp);
    if (shrink) size = fn_802c0cf0(self, text.p, width, size, d);
    Vec scale(size, size, 1.0f);
    Ptr32<Face> face = fn_8015ae3c(d->font);
    Ptr32<Font> font = fn_8034435c(face);
    if (face->vt->ready(face) == 0) fn_8015aee8(*face->vt->name(face));
    float dots = fn_8018b4cc(font, lbl_803d83c0) * size;
    unsigned fit = fn_8018b524(font, t, width, size);
    rec.sx = scale.x;
    if (fit == 0) {
        self->recs.push_back(rec);
        return;
    }
    if (fit >= len) fn_8020c510(&shown, lbl_803d83c4, w3d::VA(t));
    else {
        unsigned n = fn_8018b524(font, t, width - dots, size);
        if (n == 0) fn_8020c43c(&shown, t, fit);
        else {
            fn_8020c43c(&shown, t, n);
            shown += lbl_803d83c0;
        }
    }
    float w = fn_8018b4cc(font, shown.p) * size;
    if (fixed) {
        self->f56 = self->f56 - (w + 4.0f);
        rec.y = self->f52 - self->f56;
        width = w;
    }
    fn_8015adf4(d->font, &rec.h, self->style + 30);
    Ptr32<Res> obj = fn_80343580(rec.h.p);
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
    Colour c2;
    c2.r = 0;
    c2.g = 0;
    c2.b = 0;
    c2.a = al;
    fn_8018d434(obj, &c2);
    scale.y *= (float)self->alpha / 255.0f;
    obj->vt->setscale(obj, &scale, 0);
}


