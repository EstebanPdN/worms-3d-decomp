// GWMP8P rev0 0x80126e4c. Game scene start: loads the font, creates the three
// light groups and their settings, binds the render layers to them and starts
// the top-level game objects.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Row { float x, y, z; };
struct Mat3 {
    Row r[3];
    const Row &R(int i) const { return r[i]; }
    void transpose() {
        float t;
        t = r[0].y; r[0].y = r[1].x; r[1].x = t;
        t = r[1].z; float v = r[2].y; r[1].z = v; r[2].y = t;
        t = r[2].x; r[2].x = r[0].z; r[0].z = t;
    }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Settings { float a, b, c, d, e, f; int k; };
struct Light;
struct LightVt {
    char u0[12]; void (*add)(Light *); void (*release)(Light *); char u20[20];
    void (*settings)(Light *, const Settings *); void (*colour)(Light *, const Vec *); void (*dir)(Light *, const Vec *); void (*spec)(Light *, const Vec *);
};
struct Light { LightVt *vt; };
struct Ref {
    Light *p;
    void operator=(Light *q) {
        if (q) q->vt->add(q);
        if (p) p->vt->release(p);
        p = q;
    }
    Light *operator->() const { return p; }
    operator Light *() const { return p; }
};
struct Layers { struct LayersVt *vt; };
struct LayersVt { char u0[160]; void (*setup)(Layers *, int, int); };
struct Scene {
    struct SceneVt *vt; char u4[44]; Ref l48; char u52[44]; void *owner; char u100[16]; Layers *layers;
    char u120[12]; Ref a; Ref b; Ref c; char u144[40]; float blend; unsigned flags;
};
struct SceneVt { char u0[72]; void (*enable)(Scene *, int); };
struct Type { char u0[20]; unsigned id; };
struct Commands { char u0[28]; int count; };
extern char lightType_804138c0[], type_8040e238[], type_80411018[], type_8040ead0[], type_8040f300[], type_8040f918[];
extern Vec spec_8045e7a0[], colour_8045e788[], ambient_80450a54[];
extern int ambient_ready_804af5b8;
inline void *operator new(unsigned int, void *place) { return place; }
extern Type *type_804aa828;
extern void *service_804b178c;
extern Commands *commands_804aabd4;
extern void *endpoint_804aaf88;
extern "C" void font_8015c8dc(Scene *, const char *);
extern "C" Light *make_8020b680(char *);
extern "C" void euler_801a3eb0(const Vec *, int, Mat3 *);
extern "C" void pre_8015cabc(Scene *, int);
extern "C" void bind_8015cd34(Scene *, int, Light *);
extern "C" void reset_800fbd48();
extern "C" int create_80164514(void *, Light *, unsigned);
extern "C" int endpoint_802cc4f0(const char *);
extern "C" void post_80128f68(Scene *);
inline void start(Type *t, char *type) {
    Light *o = make_8020b680(type);
    create_80164514(service_804b178c, o, t->id);
}
extern "C" void d28i_scene_start_80126e4c(Scene *self) {
    font_8015c8dc(self, "font.tga");
    self->vt->enable(self, (self->flags >> 21) & 1);
    char *type = lightType_804138c0;
    self->a = make_8020b680(type);
    self->b = make_8020b680(type);
    self->c = make_8020b680(type);
    Settings s;
    s.e = 5.0f;
    s.f = 15000.0f;
    s.a = -0.64f;
    s.b = 0.64f;
    s.c = -0.48f;
    s.d = 0.48f;
    s.k = 0;
    self->l48->vt->settings(self->l48, &s);
    self->c->vt->settings(self->c, &s);
    self->b->vt->settings(self->b, &s);
    float t = self->blend;
    float u = 1.0f - t;
    s.b = t * 0.7f + u * 0.64f;
    s.d = t * 0.525f + u * 0.48f;
    s.a = -s.b;
    s.c = -s.d;
    self->a->vt->settings(self->a, &s);
    Vec col(-46.944f, 20.195f, -2.163f);
    Vec ang(-92.978f, -109.447f, -71.975f);
    Vec dir(0.0f, 0.0f, 100.0f);
    Vec fwd(0.0f, 0.0f, 100.0f);
    Mat3 m;
    euler_801a3eb0(&ang, 0, &m);
    m.transpose();
    m.rotate(dir, fwd);
    self->l48->vt->colour(self->l48, &col);
    self->l48->vt->dir(self->l48, &dir);
    self->l48->vt->spec(self->l48, spec_8045e7a0);
    self->c->vt->colour(self->c, colour_8045e788);
    self->c->vt->dir(self->c, &dir);
    self->c->vt->spec(self->c, spec_8045e7a0);
    self->b->vt->colour(self->b, colour_8045e788);
    self->b->vt->dir(self->b, &dir);
    self->b->vt->spec(self->b, spec_8045e7a0);
    if (!ambient_ready_804af5b8) {
        new (ambient_80450a54) Vec(0.0f, 0.0f, 500.0f);
        ambient_ready_804af5b8 = 1;
    }
    self->a->vt->colour(self->a, ambient_80450a54);
    self->a->vt->dir(self->a, colour_8045e788);
    self->a->vt->spec(self->a, spec_8045e7a0);
    pre_8015cabc(self, 62);
    self->layers->vt->setup(self->layers, 0, 58);
    unsigned i;
    for (i = 0; i <= 61; i++) bind_8015cd34(self, i, self->l48);
    bind_8015cd34(self, 59, self->a);
    bind_8015cd34(self, 60, self->a);
    bind_8015cd34(self, 61, self->a);
    bind_8015cd34(self, 24, self->a);
    bind_8015cd34(self, 26, self->a);
    for (i = 28; i <= 55; i++) bind_8015cd34(self, i, self->a);
    bind_8015cd34(self, 56, self->a);
    bind_8015cd34(self, 9, self->b);
    bind_8015cd34(self, 11, self->b);
    bind_8015cd34(self, 6, self->c);
    bind_8015cd34(self, 7, self->c);
    bind_8015cd34(self, 8, self->c);
    bind_8015cd34(self, 27, self->a);
    bind_8015cd34(self, 57, self->a);
    bind_8015cd34(self, 58, self->a);
    bind_8015cd34(self, 18, self->a);
    bind_8015cd34(self, 17, self->a);
    reset_800fbd48();
    void *owner = self->owner;
    create_80164514(owner, make_8020b680(type_8040e238), 0xbabe000);
    if (self->flags & 0x40000000) {
        start(type_804aa828, type_80411018);
        start(type_804aa828, type_8040ead0);
        start(type_804aa828, type_8040f300);
        commands_804aabd4->count = 89;
        endpoint_804aaf88 = (void *)endpoint_802cc4f0("Script commands");
    }
    start(type_804aa828, type_8040f918);
    post_80128f68(self);
}
