#include "w3d_ptr.h"
#line 1 "d27l_panel_load_resources_802b1f98.cpp"
// GWMP8P rev0 0x802b1f98. Panel control first-time setup: resets the mesh
// and active resource once, then resolves the two named resources in the
// config through 0x802b2664 (string parameter by value, destroyed by the
// callee), applies them and notifies through the table at +180. Twin of
// d27l_panel_show_resources_802b1d98. Partial views; field names are
// inferred.
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
struct Cfg { char u0[52]; Str s52; char u56[44]; Str s100; char u104[4]; unsigned w108; };
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
    char u140[24];
    int w164;
    char u168[12];
    Ptr32<PanelVt> vt;
    Str fn_802b2664(Str, int);
};
extern int id_804abb58;
extern "C" void fn_802b1cec(Ptr32<Panel>);
extern "C" void fn_802b24bc(Ptr32<Panel>);
extern "C" void d27l_panel_load_resources_802b1f98(Ptr32<Panel> self) {
    if (!self->w164) {
        int one = 1;
        self->w164 = one;
        fn_802b1cec(self);
        fn_802b24bc(self);
        if (id_804abb58 != -1) {
            {
            Ptr32<Cfg> c = self->cfg;
            if (c->s100.length()) {
                Str r = self->fn_802b2664(c->s100, id_804abb58);
                if (r.length()) {
                    self->w100 = one;
                    self->w136 = (float)self->cfg->w108 / 1000.0f;
                    self->vt->a(self, r.p);
                }
            }
            }
            Ptr32<Cfg> c = self->cfg;
            if (c->s52.length()) {
                Str r = self->fn_802b2664(c->s52, id_804abb58);
                if (r.length()) {
                    fn_802b24bc(self);
                    self->w104 = 1;
                    self->vt->b(self, r.p);
                }
            }
            self->vt->c(self, 3);
        }
    }
}


