#include "w3d_ptr.h"
#line 1 "d31l_panel_init_802b0b84.cpp"
// GWMP8P rev0 0x802b0b84. Panel base setup: stores the owner and font,
// subscribes thirteen cached messages, resolves the tooltip and highlight
// colours, sets up frame nodes and resources, then evaluates the optional
// enable switch named by the config (a leading ! inverts it; literal false
// disables; otherwise a game-data value of type int, native or string).
// Field names are inferred.
extern "C" void fn_8020c5c0(Ptr32<void>), fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str {
    Ptr32<char> p;
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
struct Key { Ptr32<const char> name; template <class W3dU> Key(Ptr32<W3dU> w3d_p) : Key((const char *)w3d_p.get()) {}
 Key(const char *n) : name(n) {} };
struct Msg { char u[8]; };
struct Res;
struct ResVt { char u0[24]; Ptr32<int (Ptr32<Res>)> type; };
struct Res { Ptr32<ResVt> vt; };
struct Ent { char u[16]; int w16; };
struct Panel;
struct PanelVt { char u[68]; Ptr32<void (Ptr32<Panel>, int)> enable; };
struct Cfg { char u0[60]; Str s60; };
struct Panel {
    char u0[4];
    int font;
    int w8;
    Ptr32<Cfg> cfg;
    Ptr32<Ent> e[7];
    Ptr32<Ent> e44; Ptr32<Ent> e48; Ptr32<Ent> e52; Ptr32<Ent> e56; Ptr32<Ent> e60; Ptr32<Ent> e64;
    Ptr32<Res> tip; Ptr32<Res> hi; Ptr32<Res> val;
    Str err;
    char u84[40];
    int w124;
    char u128[40];
    int w168;
    char u172[8];
    Ptr32<PanelVt> vt;
};
extern int font_804abb60;
extern Msg msg_804b0f80, msg_804b0f88, msg_804b0f90, msg_804b0f98, msg_804b0fa0, msg_804b0fa8, msg_804b0fb0, msg_804b0fc8, msg_804b0fd8, msg_804b0fe0, msg_804b0fe8, msg_804b0fd0, msg_804b0ff0;
extern char str_803d79c8[], str_803d79d4[], str_803d79e8[], str_803d79f0[];
extern "C" {
int fn_8015f5a0(Ptr32<Msg>, int);
int fn_80162024(Ptr32<void>, const unsigned short &, Ptr32<Ptr32<Ent>>);
int fn_800fc1b0(const Key &, Ptr32<Ptr32<Res>>);
int fn_800fd62c(Ptr32<Str>, Ptr32<void (Ptr32<void>, Ptr32<void>)>, Ptr32<Panel>, Ptr32<int>);
int fn_802b2374(Ptr32<void>, Ptr32<void>);
void fn_802b192c(Ptr32<Panel>);
void fn_802b1d98(Ptr32<Panel>);
Ptr32<Str> fn_8020bd38(Ptr32<Str>, Ptr32<const char>);
int strcmp(Ptr32<const char>, Ptr32<const char>);
void fn_8020c510(Ptr32<void>, Ptr32<const char>, ...);
Ptr32<void> fn_803426b4(Ptr32<Res>);
int fn_80178c48(Ptr32<void>);
Ptr32<void> fn_80342a78(Ptr32<Res>);
int fn_80178d1c(Ptr32<void>);
Ptr32<void> fn_80343744(Ptr32<Res>);
Ptr32<Str> fn_80179170(Ptr32<void>);
}
extern "C" void d31l_panel_init_802b0b84(Ptr32<Panel> self, Ptr32<void> o, int d) {
    self->w168 = d;
    self->font = font_804abb60;
    fn_80162024(o, fn_8015f5a0(&msg_804b0f80, 1), &self->e[0]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0f88, 1), &self->e[1]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0f90, 1), &self->e[2]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0f98, 1), &self->e[3]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fa0, 1), &self->e[4]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fa8, 1), &self->e[5]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fb0, 1), &self->e[6]);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fc8, 1), &self->e44);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fd8, 1), &self->e56);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fe0, 1), &self->e60);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fe8, 1), &self->e52);
    fn_80162024(o, fn_8015f5a0(&msg_804b0fd0, 1), &self->e48);
    fn_80162024(o, fn_8015f5a0(&msg_804b0ff0, 1), &self->e64);
    self->e[0]->w16 = 0;
    self->e[1]->w16 = 0;
    self->e[2]->w16 = 0;
    self->e[3]->w16 = 0;
    self->e[4]->w16 = 0;
    self->e[5]->w16 = 0;
    self->e[6]->w16 = 0;
    fn_800fc1b0(Key(str_803d79c8), &self->tip);
    fn_800fc1b0(Key(str_803d79d4), &self->hi);
    fn_802b192c(self);
    fn_802b1d98(self);
    Ptr32<Cfg> c = self->cfg;
    if (c->s60.length()) {
        Str s(c->s60);
        Ptr32<Str> ps = &s;
        if (*s.p == '!') {
            self->w124 = 1;
            fn_8020bd38(ps, s.p + 1);
        }
        if (s.length()) {
            if (strcmp(s.p, str_803d79e8) == 0)
                self->vt->enable(self, 0);
            else if (fn_800fc1b0(Key(s.p), &self->val) >= 0) {
                fn_800fd62c(ps, (Ptr32<void (Ptr32<void>, Ptr32<void>)>)fn_802b2374, self, &self->w8);
                switch (self->val->vt->type(self->val)) {
                case 0:
                    self->vt->enable(self, fn_80178c48(fn_803426b4(self->val)) != 0);
                    break;
                case 1:
                    self->vt->enable(self, fn_80178d1c(fn_80342a78(self->val)) != 0);
                    break;
                case 4: {
                    Str t(*fn_80179170(fn_80343744(self->val)));
                    if (t.length() == 0 || *t.p == ' ')
                        self->vt->enable(self, 0);
                    else
                        self->vt->enable(self, 1);
                    break;
                }
                }
            } else
                fn_8020c510(&self->err, str_803d79f0, w3d::VA(self->cfg->s60.p));
        }
    }
}


