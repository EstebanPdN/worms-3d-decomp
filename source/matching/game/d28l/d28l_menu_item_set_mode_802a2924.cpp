// GWMP8P rev0 0x802a2924. Sets a menu item's mode. Mode zero clears the
// active item and detaches its node. Otherwise it takes the item's text,
// becomes the active item, runs its command and, if the setting allows,
// opens the text box with the item's strings, numbers and vectors. Strings
// and vectors are by-value arguments destroyed by the callee. Field names
// are inferred.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020bb2c(void *), fn_8020c5c0(void *);
struct Header {
    unsigned short refs, length, capacity;
    void release() {
        if (!--refs)
            fn_8020bb2c(this);
    }
};
extern "C" Header *fn_80341884(void *);
struct StrBase {
    char *p;
    StrBase() { fn_8020c5c0(this); }
};
struct Str : StrBase {
    Str(const Str &o) {
        p = o.p;
        Header *h = fn_80341884(this);
        ++h->refs;
    }
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned short len() const { return *(unsigned short *)(p - 4); }
    void assign(const Str &o) {
        ++((Header *)(o.p - 6))->refs;
        ((Header *)(p - 6))->release();
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
struct NodeVt { char u0[88]; void (*attach)(Node *, int); };
struct Node { NodeVt *vt; };
struct Panel;
struct PanelVt { char u0[52]; void (*enable)(Panel *, int); char u56[8]; int (*id)(Panel *); };
struct Panel {
    char u0[12];
    Desc *desc;
    char u16[144];
    int mode;
    char u164[16];
    PanelVt *vt;
};
struct TextBox { char u0[380]; Desc *desc; };
struct Self {
    char u0[20];
    int w20;
    char u24[4];
    Panel panel;
    char u212[180];
    Node *node;
    char u396[16];
    Str w412;
    Str w416;
    char u420[4];
    int w424;
};
struct Settings { char u0[188]; unsigned flags; };
extern int active_804abc68;
extern Settings *settings_804b1788;
extern void *manager_804b178c;
extern char service_8041c8d0[];
extern "C" void fn_802a0cc0(Self *, int);
extern "C" void fn_802b1258(const char *);
extern "C" TextBox *fn_8020b680(void *);
extern "C" int fn_80164514(void *, TextBox *, int);
extern "C" void fn_802c4498(TextBox *, Str, Str);
extern "C" void fn_802c4a60(TextBox *, int);
extern "C" float fn_802b1880(Panel *);
extern "C" void fn_802c4a70(TextBox *, float, float);
extern "C" void fn_802c4d34(TextBox *, int);
extern "C" void fn_802c4eb0(TextBox *, Str);
extern "C" void fn_802c4d3c(TextBox *, Vec, Vec);
extern "C" void fn_802c4f28(TextBox *, Panel *);
extern "C" void fn_802c2aac(TextBox *);
extern "C" void d28l_menu_item_set_mode_802a2924(Self *self, int mode) {
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
                TextBox *box = fn_8020b680(service_8041c8d0);
                fn_80164514(manager_804b178c, box, self->w20);
                Desc *d = self->panel.desc;
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
