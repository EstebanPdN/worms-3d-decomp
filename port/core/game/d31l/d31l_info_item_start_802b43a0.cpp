#include "w3d_ptr.h"
#line 1 "d31l_info_item_start_802b43a0.cpp"
// GWMP8P rev0 0x802b43a0. Info menu item start: panel setup, loads the info
// and FE.Cross sprites with fallback to FE.Info.E, tints the first when not
// interactive, subscribes two messages, adds the sprites to the node and
// resolves the game-data value named by the config. Strings and vtable slots
// come from the original; field names are inferred.
extern "C" void fn_8020c5c0(Ptr32<void>), fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    template <class W3dU> Str(Ptr32<W3dU> w3d_p) : Str((const char *)w3d_p.get()) {}
 Str(const char *);
    Str(const Str &o) {
        Ptr32<Str> t = this;
        fn_8020c5c0(t);
        p = o.p;
        Ptr32<Header> h = fn_80341884(t);
        ++h->refs;
    }
    ~Str() { Ptr32<Str> t = this; fn_8020c5c4(t); fn_80341588(t); }
    unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); }
};
inline void trace(Str) {}
struct Vec { float x, y, z; };
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) : name(n) {} };
struct Msg { char u[8]; };
struct Colour {
    signed char r, g, b, a;
    Colour(signed char x, signed char y, signed char z, signed char w) { r = x; g = y; b = z; a = w; }
};
struct Res;
struct ResVt { char u0[16]; Ptr32<void (Ptr32<Res>)> destroy; char u20[64]; Ptr32<int (Ptr32<Res>, const Vec &, int)> scale; char u88[4]; Ptr32<void (Ptr32<Res>, Ptr32<Res>, int)> add; };
struct Res { Ptr32<ResVt> vt; };
struct Ent { char u[16]; int w16; };
struct Cfg { char u0[20]; Vec size; char u32[104]; Str s136; char u140[4]; int w144; int w148; Str s152; };
struct Sub;
struct SubVt { char u[20]; Ptr32<void (Ptr32<Sub>, int)> show; };
struct Sub { char u0[180]; Ptr32<SubVt> vt; };
struct Item {
    char u0[28];
    Sub sub;
    int w212, w216;
    char u220[16];
    Ptr32<Res> w236; Ptr32<Res> w240;
    char u244[4];
    int w248;
    Ptr32<Res> w252;
    Ptr32<Ent> e256; Ptr32<Ent> e260;
};
inline unsigned char &font_of(Ptr32<Item> s) { return *((Ptr32<unsigned char>)s + 32); }
inline Ptr32<Cfg> & cfg_of(Ptr32<Item> s) { return *(Ptr32<Ptr32<Cfg>>)((Ptr32<char>)s + 40); }
inline Str &err_of(Ptr32<Item> s) { return *(Ptr32<Str>)((Ptr32<char>)s + 108); }
inline Ptr32<Res> & node_of(Ptr32<Item> s) { return *(Ptr32<Ptr32<Res>>)((Ptr32<char>)s + 112); }
inline int &w140_of(Ptr32<Item> s) { return *(Ptr32<int>)((Ptr32<char>)s + 140); }
inline int &w176_of(Ptr32<Item> s) { return *(Ptr32<int>)((Ptr32<char>)s + 176); }
extern Msg msg_804b1008, msg_804b1010;
extern char str_803d7d60[], str_803d7d84[], str_803d7d90[], str_803d7d9c[], str_803d7df0[];
struct Ctx { char u[52]; int w52; };
extern "C" {
Ptr32<Ctx> fn_80165254();
void fn_802b0b84(Ptr32<Sub>, Ptr32<Item>, int);
int fn_802b1510(Ptr32<Sub>, Ptr32<const char>, Ptr32<Ptr32<Res>>, unsigned char);
void fn_8020c510(Ptr32<void>, Ptr32<const char>, ...);
Ptr32<Str> fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
int fn_8015adf4(const Str &, Ptr32<Ptr32<Res>>, unsigned char);
Ptr32<Res> fn_8034357c(Ptr32<Res>);
int fn_80173df0(Ptr32<Res>, Ptr32<const Colour>);
void fn_802b49b0(Ptr32<Item>);
int fn_8015f5a0(Ptr32<Msg>, int);
int fn_80162024(Ptr32<void>, const unsigned short &, Ptr32<Ptr32<Ent>>);
int fn_800fc1b0(const Key &, Ptr32<Ptr32<Res>>);
int fn_800fd62c(Ptr32<Str>, Ptr32<void (Ptr32<void>, Ptr32<void>)>, Ptr32<Item>, Ptr32<int>);
int fn_802b5050(Ptr32<void>, Ptr32<void>);
int fn_802b4ef4(Ptr32<Item>);
void fn_802b4e8c(Ptr32<Item>);
}
extern "C" void d31l_info_item_start_802b43a0(Ptr32<Item> self) {
    Ptr32<Sub> sub = &self->sub;
    fn_802b0b84(sub, self, fn_80165254()->w52);
    Ptr32<Cfg> c = cfg_of(self);
    int sel = c->w144;
    self->w216 = sel;
    if (c->s136.length()) {
        if (fn_802b1510(sub, c->s136.p, &self->w236, sel ? font_of(self) + 30 : font_of(self) + 29) < 0) {
            fn_8020c510(&err_of(self), str_803d7d60, w3d::VA(c->s136.p));
            fn_8015adf4(Str(str_803d7d84), &self->w236, self->w216 ? font_of(self) + 30 : font_of(self) + 29);
        }
    }
    if (fn_802b1510(&self->sub, str_803d7d90, &self->w240, font_of(self) + 31) < 0)
        fn_8020bd38(&err_of(self), str_803d7d9c);
    if (!w140_of(self)) {
        Colour col(-1, -1, -1, -86);
        if (self->w236) fn_80173df0(fn_8034357c(self->w236), &col);
    }
    fn_802b49b0(self);
    fn_80162024(self, fn_8015f5a0(&msg_804b1008, 1), &self->e256);
    fn_80162024(self, fn_8015f5a0(&msg_804b1010, 1), &self->e260);
    self->e256->w16 = 0;
    self->e260->w16 = 0;
    w176_of(self) = 1;
    self->sub.vt->show(&self->sub, 0);
    self->w212 = c->w148;
    if (self->w236) {
        node_of(self)->vt->add(node_of(self), self->w236, 0);
        self->w236->vt->scale(self->w236, cfg_of(self)->size, 0);
    }
    if (self->w240) {
        node_of(self)->vt->add(node_of(self), self->w240, 0);
        self->w240->vt->scale(self->w240, cfg_of(self)->size, 0);
    }
    Str &s = c->s152;
    if (s.length()) {
        Key k(c->s152.p);
        if (fn_800fc1b0(k, &self->w252) < 0) {
            Ptr32<Res> z = 0;
            if (self->w252) self->w252->vt->destroy(self->w252);
            self->w252 = z;
            trace(c->s152);
            fn_8020c510(&err_of(self), str_803d7df0, w3d::VA(c->s152.p));
        } else {
            fn_800fd62c(&s, (Ptr32<void (Ptr32<void>, Ptr32<void>)>)fn_802b5050, self, &self->w248);
            fn_802b4ef4(self);
        }
    }
    fn_802b4e8c(self);
}


