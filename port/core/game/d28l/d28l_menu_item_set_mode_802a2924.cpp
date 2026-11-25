#include "w3d_ptr.h"
#line 1 "d28l_menu_item_set_mode_802a2924.cpp"
// GWMP8P rev0 0x802a2924. Sets a menu item's mode. Mode zero clears the
// active item and detaches its node. Otherwise it takes the item's text,
// becomes the active item, runs its command and, if the setting allows,
// opens the text box with the item's strings, numbers and vectors. Strings
// and vectors are by-value arguments destroyed by the callee. Field names
// are inferred.
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020bb2c(Ptr32<void>), fn_8020c5c0(Ptr32<void>);
struct Header {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs)
            fn_8020bb2c(this);
    }
};
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct StrBase {
    Ptr32<char> p;
    StrBase() { fn_8020c5c0(this); }
};
struct Str : StrBase {
    Str(const Str &o) {
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned short len() const { return *(Ptr32<unsigned short>)(p - 4); }
    void assign(const Str &o) {
        ++((Ptr32<Header>)(o.p - 6))->refs;
        ((Ptr32<Header>)(p - 6))->release();
        p = o.p;
    }
};
struct Vec {
    float x, y, z;
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Desc {
    char u0[20];
    Vec v20;
    Vec v32;
    char u44[92];
    Str w136;
    Str w140;
    char u144[16];
    unsigned w160;
    int w164;
    char u168[4];
    Str w172;
    Str w176;
    char u180[4];
    int w184;
};
struct Node;
struct NodeVt { char u0[88]; Ptr32<void (Ptr32<Node>, int)> attach; };
struct Node { Ptr32<NodeVt> vt; };
struct Panel;
struct PanelVt { char u0[52]; Ptr32<void (Ptr32<Panel>, int)> enable; char u56[8]; Ptr32<int (Ptr32<Panel>)> id; };
struct Panel {
    char u0[12];
    Ptr32<Desc> desc;
    char u16[144];
    int mode;
    char u164[16];
    Ptr32<PanelVt> vt;
};
struct TextBox { char u0[380]; Ptr32<Desc> desc; };
struct Self {
    char u0[20];
    int w20;
    char u24[4];
    Panel panel;
    char u212[180];
    Ptr32<Node> node;
    char u396[16];
    Str w412;
    Str w416;
    char u420[4];
    int w424;
};
struct Settings { char u0[188]; unsigned flags; };
extern int active_804abc68;
extern Ptr32<Settings> settings_804b1788;
extern Ptr32<void> manager_804b178c;
extern char service_8041c8d0[];
extern "C" void fn_802a0cc0(Ptr32<Self>, int);
extern "C" void fn_802b1258(Ptr32<const char>);
extern "C" Ptr32<TextBox> fn_8020b680(Ptr32<void>);
extern "C" int fn_80164514(Ptr32<void>, Ptr32<TextBox>, int);
extern "C" void fn_802c4498(Ptr32<TextBox>, Str, Str);
extern "C" void fn_802c4a60(Ptr32<TextBox>, int);
extern "C" float fn_802b1880(Ptr32<Panel>);
extern "C" void fn_802c4a70(Ptr32<TextBox>, float, float);
extern "C" void fn_802c4d34(Ptr32<TextBox>, int);
// El llamado destruye el argumento (GCC 2.95): esta copia no lleva destructor.
struct StrArg : StrBase {
    StrArg(const Str &o) {
        p = o.p;
        Ptr32<Header> h = fn_80341884(this);
        ++h->refs;
    }
    StrArg(const StrArg &);
};
extern "C" void fn_802c4eb0(Ptr32<TextBox>, StrArg);
extern "C" void fn_802c4d3c(Ptr32<TextBox>, Vec, Vec);
extern "C" void fn_802c4f28(Ptr32<TextBox>, Ptr32<Panel>);
extern "C" void fn_802c2aac(Ptr32<TextBox>);
extern "C" void d28l_menu_item_set_mode_802a2924(Ptr32<Self> self, int mode) {
    if (mode != self->panel.mode) {
        fn_802a0cc0(self, mode);
        if (!self->panel.mode) {
            if (active_804abc68 != -1 && active_804abc68 == self->panel.vt->id(&self->panel)) {
                active_804abc68 = -1;
            }
            self->node->vt->attach(self->node, 0);
            self->w424 = 0;
        } else {
            self->w416.assign(self->w412);
            active_804abc68 = self->panel.vt->id(&self->panel);
            if (self->panel.desc->w176.len()) {
                fn_802b1258(self->panel.desc->w176.p);
            }
            if (settings_804b1788->flags & 0x2000) {
                Ptr32<TextBox> box = fn_8020b680(service_8041c8d0);
                fn_80164514(manager_804b178c, box, self->w20);
                Ptr32<Desc> d = self->panel.desc;
                fn_802c4498(box, d->w140, d->w136);
                fn_802c4a60(box, d->w164);
                float a = d->w160;
                fn_802c4a70(box, a, fn_802b1880(&self->panel));
                fn_802c4d34(box, d->w184);
                fn_802c4eb0(box, d->w172);
                fn_802c4d3c(box, d->v32, d->v20);
                fn_802c4f28(box, &self->panel);
                box->desc = d;
                fn_802c2aac(box);
                self->panel.vt->enable(&self->panel, 0);
            }
        }
    }
}


