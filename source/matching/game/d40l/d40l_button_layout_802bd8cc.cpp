// GWMP8P rev0 0x802bd8cc. Button layout update: scales and places the left,
// right, top, bottom and centre sprites from size, origin and press state.
// Button and Node are partial views. The int return of virtual slot 76
// (place) is inferred from argument scheduling; no caller reads it here.
struct Vec {
    float x, y, z;
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Node;
struct NodeVt { char u0[76]; int (*place)(Node *, Vec *, int); char u80[4]; void (*scale)(Node *, Vec *, int); };
struct Node { NodeVt *vt; };
struct Button {
    char u0[20];
    void *visible;
    char u24[8];
    int state;
    float size;
    char u40[12];
    float origin;
    char u56[4];
    float x, y;
    void *owner;
    char u72[36];
    Node *left, *right, *top, *bottom, *centre;
};
extern "C" float fn_80178df0(void *);
extern "C" void fn_802bd354(Button *), fn_802bfc64(Button *), fn_802bf81c(Button *);
extern "C" void d40l_button_layout_802bd8cc(Button *self) {
    fn_802bd354(self);
    if (!self->visible) return;
    float size = self->size;
    float w = fn_80178df0(self->owner);
    float hx = self->x * 0.5f;
    float hy = self->y * 0.5f;
    float len = hx + hy;
    float pos = 0.0f - hx + hy;
    float off = 0.0f;
    float rest = 2.0f;
    if (self->x > off) {
        float t = self->x;
        float d = w + w;
        if (t > d) t = d;
        float q = t / d;
        rest -= q;
        off += q;
    }
    float d = w + w;
    if (self->y > 0.0f) {
        float t = self->y;
        if (t > d) t = d;
        float q = t / d;
        rest -= q;
        off -= q;
    }
    float one = 1.0f;
    Vec v;
    v.set(self->origin - d + one, w, one);
    float inner = size - len;
    self->left->vt->scale(self->left, &v, 0);
    float zero = 0.0f;
    v.set(zero, size - w, zero);
    self->left->vt->place(self->left, &v, 0);
    v.set(self->origin - d + one, w, one);
    self->right->vt->scale(self->right, &v, 0);
    v.set(zero, w - size, zero);
    self->right->vt->place(self->right, &v, 0);
    v.set(w, inner, one);
    self->top->vt->scale(self->top, &v, 0);
    v.set(zero - self->origin + w - one, pos, zero);
    self->top->vt->place(self->top, &v, 0);
    v.set(w, inner, one);
    self->bottom->vt->scale(self->bottom, &v, 0);
    v.set(self->origin - w + one, pos, zero);
    self->bottom->vt->place(self->bottom, &v, 0);
    switch (self->state) {
    case 3:
        v.set(self->origin - d + one, size - rest - len, one);
        self->centre->vt->scale(self->centre, &v, 0);
        break;
    case 0: case 1: case 2:
        v.set(self->origin + one, size - rest - len + d, one);
        self->centre->vt->scale(self->centre, &v, 0);
        break;
    }
    v.set(0.0f, pos + off, 0.0f);
    self->centre->vt->place(self->centre, &v, 0);
    fn_802bfc64(self);
    fn_802bf81c(self);
}
