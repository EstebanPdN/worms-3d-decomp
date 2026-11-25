#include "w3d_ptr.h"
#line 1 "d40l_item_default_name_802ab3e8.cpp"
// GWMP8P rev0 0x802ab3e8. Menu item name refresh: when the current item's
// string is empty, picks a default from one of three order tables by item
// kind. Item, Str and Res are partial views; the offset local shared across
// the switch arms is inferred from register allocation.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header {
    unsigned short refs, length, capacity;
    void release() { if (!--refs) fn_8020bb2c(this); }
};
struct Str {
    Ptr32<char> p;
    Str();
    Str(const Str &);
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
    unsigned short len() const { return *(Ptr32<unsigned short>)(p - 4); }
    void assign(const Str &o) {
        ++((Ptr32<Header>)(o.p - 6))->refs;
        ((Ptr32<Header>)(p - 6))->release();
        p = o.p;
    }
};
struct Res;
struct ResVt { char u0[16]; Ptr32<void (Ptr32<Res>)> destroy; };
struct Res { Ptr32<ResVt> vt; };
struct Held {
    Ptr32<Res> r;
    Held() : r(0) {}
    Held(const Held &);
    ~Held() { if (r) r->vt->destroy(r); }
};
struct Key { Ptr32<const char> p; };
struct Slot { char u0[60]; Str text; char u64[8]; };
struct Item {
    char u0[96];
    Ptr32<Res> label;
    char u100[8];
    Str error;
    char u112[156];
    int kinds[1];
    char u272[800];
    int current;
    char u1076[240];
    int a, b, c;
};
extern "C" Ptr32<Res> fn_80343744(Ptr32<Res>);
extern "C" int fn_801790bc(Ptr32<Res>, Ptr32<const char>);
extern "C" Ptr32<Ptr32<const char>> fn_80179170(Ptr32<Res>);
extern "C" int fn_800fc1b0(Ptr32<const Key>, Ptr32<Held>);
extern "C" void fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
extern int t1_803d6b7c[], t4_803d6bd0[], t7_803d6c24[];
extern Ptr32<const char> names_80403b9c[];
extern const char empty_803d6ab8[], error_803d6abc[];
extern "C" void d40l_item_default_name_802ab3e8(Ptr32<Item> self) {
    Str s;
    int i = self->current;
    if (!((Ptr32<Str>)((Ptr32<char>)self + i * 72 + 328))->len()) {
        int n; Ptr32<char> kinds = (Ptr32<char>)self->kinds;
        switch (*(Ptr32<int>)(kinds + i * 72)) {
        case 1: { Ptr32<int> tb = t1_803d6b7c; n = self->a << 2; fn_8020bd38(&s, names_80403b9c[*(Ptr32<int>)((Ptr32<char>)tb + n)]); } break;
        case 4: { Ptr32<int> tb = t4_803d6bd0; n = self->b << 2; fn_8020bd38(&s, names_80403b9c[*(Ptr32<int>)((Ptr32<char>)tb + n)]); } break;
        case 7: { Ptr32<int> tb = t7_803d6c24; n = self->c << 2; fn_8020bd38(&s, names_80403b9c[*(Ptr32<int>)((Ptr32<char>)tb + n)]); } break;
        }
    } else {
        s.assign(*(Ptr32<Str>)((Ptr32<char>)self + i * 72 + 328));
    }
    if (!s.len()) {
        fn_801790bc(fn_80343744(self->label), empty_803d6ab8);
    } else {
        Held h;
        Key k;
        k.p = s.p;
        if (fn_800fc1b0(&k, &h) >= 0) {
            Ptr32<Res> l = fn_80343744(self->label);
            fn_801790bc(l, *fn_80179170(fn_80343744(h.r)));
        } else {
            fn_8020c510(&self->error, error_803d6abc, w3d::VA(s.p));
            fn_801790bc(fn_80343744(self->label), self->error.p);
        }
    }
}


