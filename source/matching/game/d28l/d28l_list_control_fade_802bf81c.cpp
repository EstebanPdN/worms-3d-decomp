// GWMP8P rev0 0x802bf81c. List control element update: stores the current
// ratio, recomputes the alpha and, if it changed, applies it to each element
// by type, then rescales each sprite (type 0) and text element (type 5) from
// the element size and ratio. Vectors and colours are function-level locals,
// as their shared stack slots show. Names are inferred; the always-true
// resize flag reproduces the kept compare.
struct Vec {
    float x, y, z;
    Vec() {}
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Color {
    unsigned char r, g, b, a;
    Color() {}
    void set(int x, int y, int z, int w) { r = x; g = y; b = z; a = w; }
};
struct Node;
struct NodeVt { char u0[84]; void (*scale)(Node *, Vec *, int); };
struct Node { NodeVt *vt; };
struct Res;
struct ResVt { char u0[32]; int (*type)(Res *); };
struct Res { ResVt *vt; };
struct Elem {
    Res *r;
    char u4[8];
    Color colour;
    float width;
    float height;
};
struct ElemList { Elem *first, *last; Elem *end() { return last; } };
struct Control {
    char u0[4];
    unsigned char alpha;
    char u5[3];
    float ratio;
    char u12[68];
    ElemList list;
};
extern "C" float fn_802bfa40(Control *);
extern "C" int fn_802bf798(Control *);
extern "C" Node *fn_8034357c(Res *);
extern "C" Node *fn_80343580(Res *);
extern "C" int fn_80173df0(Node *, Color *);
extern "C" int fn_8018d35c(Node *, Color *);
extern "C" int fn_8018d434(Node *, Color *);
extern "C" void d28l_list_control_fade_802bf81c(Control *self) {
    int changed = 0;
    int resize = 1;
    self->ratio = fn_802bfa40(self);
    int alpha = fn_802bf798(self);
    if (alpha != self->alpha) {
        self->alpha = alpha;
        changed = 1;
    }
    Vec o, v;
    Color c, fill;
    for (Elem *e = self->list.first; e != self->list.end(); e++) {
        if (e->r) {
            switch (e->r->vt->type(e->r)) {
            case 0: {
                Node *n = fn_8034357c(e->r);
                if (changed) {
                    c.set(255, 255, 255, alpha);
                    fn_80173df0(n, &c);
                }
                v.set(e->height * 0.5f, e->width * 0.5f, 1.0f);
                float ax = v.x;
                o.set(ax, ax - ax * self->ratio, 1.0f);
                n->vt->scale(n, &o, 0);
                break;
            }
            case 5:
                if (changed) {
                    Node *n = fn_80343580(e->r);
                    fill = e->colour;
                    fill.a = alpha;
                    fn_8018d35c(n, &fill);
                    c.set(0, 0, 0, alpha);
                    fn_8018d434(n, &c);
                }
                if (resize) {
                    Node *n = fn_80343580(e->r);
                    v.set(e->width, e->width, 1.0f);
                    float ax = v.x;
                    o.set(ax, ax - ax * self->ratio, 1.0f);
                    n->vt->scale(n, &o, 0);
                }
                break;
            case 3:
                break;
            }
        }
    }
}
