#include "w3d_ptr.h"
#line 1 "d27l_panel_set_enabled_802b0990.cpp"
// GWMP8P rev0 0x802b0990. Panel enable switch: stores the new state; when
// enabling, writes the value from the panel's table to the bound property,
// marks the seven parts, enters the panel and reports its name to the
// optional service; when disabling, clears the property if it holds the
// panel's value, clears the parts, notifies, and plays the optional mesh
// clip. Partial views; roles are inferred from calls.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Base { Base() { fn_8020c5c0(this); } Ptr32<char> p; };
struct Str : Base {
    Str(const Str &o) {
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
};
struct Part { char u0[16]; int w16; };
struct Cfg { char u0[88]; Str s88; };
struct Self;
struct SelfVt { char u0[52]; Ptr32<void (Ptr32<Self>, int)> m52; Ptr32<void (Ptr32<Self>)> m56; char u60[4]; Ptr32<int (Ptr32<Self>)> m64; };
struct Self {
    char u0[12];
    Ptr32<Cfg> cfg;
    Ptr32<Part> parts[7];
    char u44[28];
    Ptr32<void> w72;
    char u76[12];
    Ptr32<void> w88;
    int w92, w96, w100;
    char u104[44];
    int w148;
    char u152[28];
    Ptr32<SelfVt> vt;
};
extern Ptr32<void> rename_804abb44;
extern "C" Ptr32<void> fn_80342a78(Ptr32<void>);
extern "C" int fn_80178d28(Ptr32<void>, Ptr32<int>);
extern "C" int fn_80178d1c(Ptr32<void>);
extern "C" void fn_802b2164(Ptr32<Self>), fn_802b21ec(Ptr32<Self>), fn_802b1cec(Ptr32<Self>);
extern "C" void fn_80264698(Ptr32<void>, Ptr32<const char>);
extern "C" Ptr32<void> fn_80343584(Ptr32<void>);
extern "C" int fn_8018179c(Ptr32<void>, int, int);
extern "C" void d27l_panel_set_enabled_802b0990(Ptr32<Self> self, int on) {
    if (self->w148 != on) {
        self->w148 = on;
        if (on) {
            Ptr32<void> t = fn_80342a78(self->w72);
            int v = self->vt->m64(self);
            fn_80178d28(t, &v);
            self->parts[0]->w16 = 1;
            self->parts[1]->w16 = 1;
            self->parts[2]->w16 = 1;
            self->parts[3]->w16 = 1;
            self->parts[4]->w16 = 1;
            self->parts[5]->w16 = 1;
            self->parts[6]->w16 = 1;
            fn_802b2164(self);
            fn_802b21ec(self);
            if (rename_804abb44) {
                Str s(self->cfg->s88);
                fn_80264698(rename_804abb44, s.p);
            }
            self->vt->m56(self);
        } else {
            Ptr32<void> t = fn_80342a78(self->w72);
            int cur = fn_80178d1c(t);
            if (cur == self->vt->m64(self)) {
                int v = 0;
                fn_80178d28(t, &v);
            }
            self->parts[0]->w16 = 0;
            self->parts[1]->w16 = 0;
            self->parts[2]->w16 = 0;
            self->parts[3]->w16 = 0;
            self->parts[4]->w16 = 0;
            self->parts[5]->w16 = 0;
            self->parts[6]->w16 = 0;
            self->vt->m52(self, 0);
            if (self->w96 == 1) {
                fn_8018179c(fn_80343584(self->w88), self->w92, 0);
                if (!self->w100)
                    fn_802b1cec(self);
            }
        }
    }
}


