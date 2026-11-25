// GWMP8P rev0 0x802b192c. Panel transform setup: binds the base node, reads
// the position from the config, binds the frame node under the Frontend node
// name when any of four config strings is set and under the null name
// otherwise, then sets position, scale, rotation and attachment. Node method
// names are inferred from the argument vectors; the string address names
// come from the original data.
extern "C" void fn_8020c5c4(void *), fn_80341588(void *);
struct Str {
    char *p;
    Str(const char *);
    Str(const Str &);
    ~Str() {
        fn_8020c5c4(this);
        fn_80341588(this);
    }
    unsigned len() const { return *(unsigned short *)(p - 4); }
};
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) {
        float a = o.x, b = o.y, c = o.z;
        x = a;
        y = b;
        z = c;
    }
};
struct Node;
struct NodeVt {
    char u0[76];
    void (*move)(Node *, const Vec &, int);
    void (*turn)(Node *, const Vec &, int);
    void (*scale)(Node *, const Vec &, int);
    void *u88;
    void (*attach)(Node *, Node *, const char *);
};
struct Node { NodeVt *vt; };
struct Cfg { char u0[32]; Vec pos; char u44[48]; Str s92, s96, s100, s104; };
struct Self {
    char u0[12];
    Cfg *cfg;
    char u16[68];
    Node *base;
    Node *frame;
};
extern const char null_803d7a6c[], front_803d7a74[], locator_803d7a84[];
extern "C" int fn_8015adf4(const Str &, Node **, unsigned char);
extern "C" void d27l_setup_frame_nodes_802b192c(Self *self) {
    fn_8015adf4(Str(null_803d7a6c), &self->base, 255);
    Cfg *c = self->cfg;
    Vec pos = c->pos;
    Vec a(0.0f, 0.0f, 0.0f);
    Vec b(1.0f, 1.0f, 1.0f);
    Vec d(0.0f, 0.0f, 0.0f);
    if (c->s104.len() || c->s100.len() || c->s96.len() || c->s92.len()) {
        fn_8015adf4(Str(front_803d7a74), &self->frame, 255);
        self->frame->vt->move(self->frame, pos, 0);
        self->frame->vt->scale(self->frame, b, 0);
        self->frame->vt->turn(self->frame, a, 0);
        self->frame->vt->attach(self->frame, self->base, locator_803d7a84);
    } else {
        fn_8015adf4(Str(null_803d7a6c), &self->frame, 255);
        self->frame->vt->move(self->frame, pos, 0);
        self->frame->vt->scale(self->frame, b, 0);
        self->frame->vt->turn(self->frame, a, 0);
        self->frame->vt->attach(self->frame, self->base, 0);
    }
    self->base->vt->move(self->base, d, 1);
    self->base->vt->turn(self->base, d, 1);
    self->base->vt->scale(self->base, b, 0);
}
