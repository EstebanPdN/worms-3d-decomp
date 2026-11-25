#include "w3d_ptr.h"
#line 1 "d43l_label_text_refresh_802a32e0.cpp"
// GWMP8P rev0 0x802a32e0. Rebuilds a text label from its style: drops the
// old sprite text, resolves the key through the language table or falls back
// to a marked-up key, creates text in the style's font, scales it to fit,
// sets its string, justification, position and colour.
extern "C" void fn_8020c5c0(Ptr32<void>), fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header {
    unsigned short refs, length, capacity;
    void release() { if (!--refs) fn_8020bb2c(this); }
};
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str;
extern "C" void fn_8020bf2c(Ptr32<Str>, Ptr32<const char>);
struct Str {
    Ptr32<char> p;
    Str();
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
    void operator+=(const Str &o) { fn_8020bf2c(this, o.p); }
    unsigned short len() const { return *(Ptr32<unsigned short>)(p - 4); }
    void operator=(const Str &o) {
        ++((Ptr32<Header>)(o.p - 6))->refs;
        ((Ptr32<Header>)(p - 6))->release();
        p = o.p;
    }
};
inline Str operator+(const Str &a, const Str &b) { Str r = a; r += b; return r; }
inline Str operator+(const Str &a, const char *b) { Str r(a); fn_8020bf2c(&r, b); return r; }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Res;
struct ResVt { char u0[16]; Ptr32<void (Ptr32<Res>)> destroy; };
struct Res { Ptr32<ResVt> vt; };
struct Held {
    Ptr32<Res> r;
    void clear() { if (r) r->vt->destroy(r); r = 0; }
};
struct Node;
struct NodeVt { char u0[76]; Ptr32<void (Ptr32<Node>, Ptr32<Vec>, int)> place; char u80[4]; Ptr32<void (Ptr32<Node>, Ptr32<Vec>, int)> scale; };
struct Node { Ptr32<NodeVt> vt; };
struct Group;
struct GroupVt { char u0[92]; Ptr32<void (Ptr32<Group>, Ptr32<Res>, int)> add; Ptr32<void (Ptr32<Group>, Ptr32<Res>)> remove; };
struct Group { Ptr32<GroupVt> vt; };
struct Style {
    char u0[20];
    Vec margin;
    char u32[88];
    char colour[4];
    Str key;
    Str font;
};
struct Key { Ptr32<const char> p; };
struct Label {
    char u0[28];
    char id[4];
    unsigned char size; char w3d_tag_rest[3];
    char u36[4];
    Ptr32<Style> style;
    char u44[68];
    Ptr32<Group> group;
    char u116[96];
    Held text;
};
extern "C" int fn_800fc2b0(Ptr32<const Key>, Ptr32<Ptr32<const char>>);
extern "C" void fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
extern "C" int fn_8015adf4(Ptr32<Str>, Ptr32<Held>, int);
extern "C" Ptr32<Node> fn_80343580(Ptr32<Res>);
extern "C" float fn_802b1880(Ptr32<void>);
extern "C" float fn_802a36cc(Ptr32<Label>, Ptr32<const char>, float, float, float);
extern "C" int fn_8018c5b0(Ptr32<Node>, Ptr32<const char>);
extern "C" int fn_8018d324(Ptr32<Node>, int);
extern "C" int fn_8018d35c(Ptr32<Node>, Ptr32<char>);
extern const char lt_803d2e28[], gt_803d2e2c[];
extern "C" void d43l_label_text_refresh_802a32e0(Ptr32<Label> self) {
    Ptr32<Style> st = self->style;
    if (st->font.len() && st->key.len()) {
        if (self->text.r) {
            self->group->vt->remove(self->group, self->text.r);
            self->text.clear();
        }
        Str name(st->key);
        Key k;
        k.p = name.p;
        Ptr32<const char> v;
        if (fn_800fc2b0(&k, &v) >= 0) {
            fn_8020bd38(&name, v);
        } else {
            Str tmp;
            tmp = Str(lt_803d2e28) + name + gt_803d2e2c;
            name = tmp;
        }
        fn_8015adf4(&st->font, &self->text, (unsigned char)(self->size + 30));
        self->group->vt->add(self->group, self->text.r, 0);
        Ptr32<Node> t = fn_80343580(self->text.r);
        float limit = fn_802b1880(self->id);
        Vec m(self->style->margin);
        float r = fn_802a36cc(self, name.p, m.x + m.x, m.y + m.y, limit);
        if (r > limit) r = limit;
        Vec s(r, r, 1.0f);
        t->vt->scale(t, &s, 0);
        fn_8018c5b0(t, name.p);
        fn_8018d324(t, 6);
        Vec p(0.0f - m.x, 0.0f - m.y, 0.0f);
        t->vt->place(t, &p, 0);
        fn_8018d35c(t, st->colour);
    }
}


