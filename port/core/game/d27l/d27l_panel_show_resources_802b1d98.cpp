#include "w3d_ptr.h"
#line 1 "d27l_panel_show_resources_802b1d98.cpp"
// GWMP8P rev0 0x802b1d98. Panel control enter: when the selected id is
// valid, resolves the two named resources in the config through 0x802b2664
// (string parameter by value, destroyed by the callee, result returned
// through hidden pointer), applies them and notifies through the table at
// +180. Panel, Cfg, Node are partial views; the table at +180 is written as
// function pointers. Field names are inferred.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str {
    Ptr32<char> p;
    Str(const Str &o) {
        fn_8020c5c0(this);
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned length() const { return *(Ptr32<unsigned short>)(p - 4); }
};
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Node;
struct NodeVt { char u[76]; Ptr32<void (Ptr32<Node>, const Vec &, int)> set; };
struct Node { Ptr32<NodeVt> vt; };
struct Cfg { char u0[56]; Str s56; char u60[44]; Str s104; char u108[4]; unsigned w112; };
struct Panel;
struct PanelVt { char u[24]; Ptr32<void (Ptr32<Panel>, Ptr32<const char>)> a; Ptr32<void (Ptr32<Panel>, Ptr32<const char>)> b; char u32[12]; Ptr32<void (Ptr32<Panel>, int)> c; };
struct Panel {
    char u0[12];
    Ptr32<Cfg> cfg;
    char u16[68];
    Ptr32<Node> node;
    char u88[12];
    int w100, w104;
    char u108[12];
    int w120;
    char u124[12];
    float w136;
    char u140[40];
    Ptr32<PanelVt> vt;
    Str fn_802b2664(Str, int);
};
extern int id_804abb50;
extern "C" void fn_802b1cec(Ptr32<Panel>);
extern "C" void fn_802b24bc(Ptr32<Panel>);
extern "C" void d27l_panel_show_resources_802b1d98(Ptr32<Panel> self) {
    if (id_804abb50 != -1) {
        {
        Ptr32<Cfg> c = self->cfg;
        if (c->s104.length()) {
            Str r = self->fn_802b2664(c->s104, id_804abb50);
            if (r.length()) {
                fn_802b1cec(self);
                self->w136 = (float)self->cfg->w112 / 1000.0f;
                self->w100 = 1;
                self->w120 = 1;
                Vec v(5000.0f, 5000.0f, 0.0f);
                self->node->vt->set(self->node, v, 0);
                self->vt->a(self, r.p);
            }
        }
        }
        Ptr32<Cfg> c = self->cfg;
        if (c->s56.length()) {
            Str r = self->fn_802b2664(c->s56, id_804abb50);
            if (r.length()) {
                fn_802b24bc(self);
                self->w104 = 1;
                self->vt->b(self, r.p);
            }
        }
        self->vt->c(self, 1);
    }
}


