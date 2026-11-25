// GWMP8P rev0 0x802b0990. Panel enable switch: stores the new state; when
// enabling, writes the value from the panel's table to the bound property,
// marks the seven parts, enters the panel and reports its name to the
// optional service; when disabling, clears the property if it holds the
// panel's value, clears the parts, notifies, and plays the optional mesh
// clip. Partial views; roles are inferred from calls.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020c5c0(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
struct Base { Base() { fn_8020c5c0(this); } char *p; };
struct Str : Base {
    Str(const Str &o) {
        p = o.p;
        Header *h = fn_80341884(this);
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
struct SelfVt { char u0[52]; void (*m52)(Self *, int); void (*m56)(Self *); char u60[4]; int (*m64)(Self *); };
struct Self {
    char u0[12];
    Cfg *cfg;
    Part *parts[7];
    char u44[28];
    void *w72;
    char u76[12];
    void *w88;
    int w92, w96, w100;
    char u104[44];
    int w148;
    char u152[28];
    SelfVt *vt;
};
extern void *rename_804abb44;
extern "C" void *fn_80342a78(void *);
extern "C" int fn_80178d28(void *, int *);
extern "C" int fn_80178d1c(void *);
extern "C" void fn_802b2164(Self *), fn_802b21ec(Self *), fn_802b1cec(Self *);
extern "C" void fn_80264698(void *, const char *);
extern "C" void *fn_80343584(void *);
extern "C" int fn_8018179c(void *, int, int);
extern "C" void d27l_panel_set_enabled_802b0990(Self *self, int on) {
    if (self->w148 != on) {
        self->w148 = on;
        if (on) {
            void *t = fn_80342a78(self->w72);
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
            void *t = fn_80342a78(self->w72);
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
