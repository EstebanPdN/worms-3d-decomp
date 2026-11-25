#include "w3d_ptr.h"
#line 1 "d30l_panel_load_style_802b6248.cpp"
// GWMP8P rev0 0x802b6248. Text panel style setup: subscribes two messages,
// resolves FE.BorderThickness, FE.ShadowOffset and FE.TextBoxBackground,
// then the optional game-data item and the value item named in the config,
// converts the value (int, native or string) to text and selects it. Strings
// and vtable slots come from the original; field names are inferred.
extern "C" void fn_8020c5c0(Ptr32<void>), fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
extern "C" Ptr32<void> fn_803426b8(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    Str() { fn_803426b8(this); }
    Str(struct Held &);
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
    unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); }
    Str &operator=(const Str &o) {
        ++*(Ptr32<unsigned short>)(o.p - 6);
        Ptr32<Header> h = (Ptr32<Header>)(p - 6);
        if (--h->refs == 0) fn_8020bb2c(h);
        p = o.p;
        return *this;
    }
};
inline void trace(Str) {}
struct Res;
struct ResVt { char u0[12]; Ptr32<void (Ptr32<Res>)> acquire; Ptr32<void (Ptr32<Res>)> destroy; char u20[4]; Ptr32<int (Ptr32<Res>)> type; };
struct Res { Ptr32<ResVt> vt; };
struct Ref {
    Ptr32<Res> p;
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Res *)w3d_p.get()); }
 void operator=(Res *q) {
        if (q) q->vt->acquire(q);
        if (p) p->vt->destroy(p);
        p = q;
    }
};
struct Held {
    Ptr32<Res> r;
    Held() : r(0) {}
    Held(const Held &);
    ~Held() { if (r) r->vt->destroy(r); }
};
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) : name(n) {} };
struct Msg { unsigned short id; char u[6]; };
struct Cfg { char u0[116]; float f116; char u120[20]; float f140; char u144[20]; Str s164; Str s168; };
struct Ctx { char u[52]; int a52; };
struct Panel {
    char u0[28];
    char sub[12];
    Ptr32<Cfg> cfg;
    char u44[64];
    Str err;
    char u112[64];
    int w176;
    char u180[32];
    int s212;
    int s216;
    float f220;
    char u224[12];
    int m236, m240;
    char u244[4];
    int w248;
    char u252[16];
    Ref border, shadow, back;
    Held game;
    char u284[8];
    int w292;
    char u296[16];
    float f312;
};
extern "C" Ptr32<Ctx> fn_80165254();
extern "C" void fn_802b0b84(Ptr32<char>, Ptr32<Panel>, int);
extern "C" int fn_8015f5a0(Ptr32<Msg>, int);
extern "C" int fn_80162024(Ptr32<Panel>, const unsigned short &, Ptr32<int>);
extern "C" int fn_800fc1b0(const Key &, Ptr32<Ptr32<Res>>);
extern "C" Ptr32<Res> fn_80342a74(Ptr32<Res>); Ptr32<Res> fn_80343df4(Ptr32<Res>); Ptr32<Res> fn_803426b4(Ptr32<Res>); Ptr32<Res> fn_80342a78(Ptr32<Res>); Ptr32<Res> fn_80343744(Ptr32<Res>);
extern "C" float fn_80178df0(Ptr32<Res>);
extern "C" int fn_80178c48(Ptr32<Res>), fn_80178d1c(Ptr32<Res>);
extern "C" const Str &fn_80179170(Ptr32<Res>);
extern "C" void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
extern "C" int fn_800fd62c(const Str &, Ptr32<void (void)>, Ptr32<Panel>, Ptr32<int>);
extern "C" int fn_802b6da8(Ptr32<void>, Ptr32<void>);
extern "C" int fn_802b6c44(Ptr32<void>, Ptr32<void>);
extern "C" void fn_802b9ae0(Ptr32<Panel>, Ptr32<char>), fn_802b6efc(Ptr32<Panel>), fn_802b8be0(Ptr32<Panel>), fn_802b8418(Ptr32<Panel>);
extern Msg msg_804b1058, msg_804b1060;
extern const char s_803d7f6c[], s_803d7f80[], s_803d7f90[], s_803d7fd0[], s_803d7ff4[];
extern const float zero_803d7ff8[];
inline Str::Str(Held &h) {
    Ptr32<Str> t = this;
    fn_803426b8(t);
            int n;
            switch (h.r->vt->type(h.r)) {
            case 0:
                n = fn_80178c48(fn_803426b4(h.r));
                goto show;
            case 1:
                n = fn_80178d1c(fn_80342a78(h.r));
            show:
                fn_8020c510(t, s_803d7ff4, n);
                break;
            case 4:
                *this = fn_80179170(fn_80343744(h.r));
                break;
            }
}
extern "C" void d30l_panel_load_style_802b6248(Ptr32<Panel> self) {
    fn_802b0b84(self->sub, self, fn_80165254()->a52);
    Held a;
    fn_80162024(self, fn_8015f5a0(&msg_804b1058, 1), &self->m236);
    fn_80162024(self, fn_8015f5a0(&msg_804b1060, 1), &self->m240);
    Ptr32<Cfg> c = self->cfg;
    Held h;
    fn_800fc1b0(Key(s_803d7f6c), &h.r);
    self->border = fn_80342a74(h.r);
    self->f220 = fn_80178df0(fn_80342a74(h.r));
    if (c->f116 != zero_803d7ff8[0]) self->f220 = c->f116;
    fn_800fc1b0(Key(s_803d7f80), &h.r);
    self->shadow = fn_80342a74(h.r);
    fn_800fc1b0(Key(s_803d7f90), &h.r);
    self->back = fn_80343df4(h.r);
    self->w176 = 0;
    Str &gs = c->s168;
    self->f312 = c->f140;
    if (gs.length()) {
        if (fn_800fc1b0(Key(gs.p), &self->game.r) < 0) {
            if (self->game.r) self->game.r->vt->destroy(self->game.r);
            self->game.r = 0;
            trace(c->s168);
            fn_8020c510(&self->err, s_803d7fd0, w3d::VA(c->s168.p));
        } else
            fn_800fd62c(gs, (Ptr32<void (void)>)fn_802b6c44, self, &self->s212);
    }
    Str &vs = c->s164;
    if (vs.length()) {
        if (fn_800fc1b0(Key(vs.p), &h.r) < 0) {
            trace(c->s164);
            fn_8020c510(&self->err, s_803d7fd0, w3d::VA(c->s164.p));
        } else {
            fn_800fd62c(vs, (Ptr32<void (void)>)fn_802b6da8, self, &self->s216);
            Str v(h);
            fn_802b9ae0(self, v.p);
        }
    }
    fn_802b6efc(self);
    fn_802b8be0(self);
    self->w292 = 1;
    fn_802b8418(self);
    self->w248 = fn_80165254()->a52;
}


