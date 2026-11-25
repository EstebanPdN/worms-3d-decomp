// GWMP8P rev0 0x800601a0. Sets up a level object from its description:
// copies name strings, places it through the context transform, scales it,
// stores orientation and packed colour; a name prefix selects a model with
// light or an attached effect. Views inferred from the original
// instructions.
struct Object;
struct ObjectVtable { void *u0[3]; void (*retain)(Object *); void (*release)(Object *); void *u20; void (*use24)(Object *, void *); char u28[36]; struct Bound *(*bound64)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Vec { float x, y, z; Vec() {} Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
inline void Put(Vec &d, const Vec &o) { d = o; }
struct Vec2 { float x, y, z; Vec2(); };
struct Row { float x, y, z; };
struct Mat {
    Row r[3]; Vec2 t;
    const Row &R(int i) const { return r[i]; }
    const Vec2 &P() const { return t; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
inline unsigned Pack(const Vec &c) {
    int r = (int)c.x, g = (int)c.y, b = (int)c.z;
    return (r & 255) | ((g & 255) << 8) | ((b & 255) << 16);
}
struct Bound { Vec c; float r; };
struct Ref {
    Object *value;
    Ref() {}
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" void string_header_release_8020bb2c(void *);
extern "C" void string_finish_8020c5c4(void *);
extern "C" void string_release_80341588(void *);
struct String {
    char *text;
    String();
    unsigned short length() const { return ((unsigned short *)text)[-2]; }
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
    String &operator=(const String &o) {
        *(unsigned short *)(o.text - 6) += 1;
        unsigned short *h = (unsigned short *)(text - 6);
        if (--*h == 0) string_header_release_8020bb2c(h);
        text = o.text;
        return *this;
    }
};
struct Model;
struct ModelVt { char u0[60]; void *(*get60)(Model *); char u64[12]; void (*set76)(Model *, Vec *, int); void (*set80)(Model *, Vec *, int); void (*set84)(Model *, Vec *, int); };
struct Model { ModelVt *vt; char u4[116]; void *a120; };
struct Info { char u0[44]; Vec v44; Vec v56; Vec v68; Vec v80; String s92; String s96; };
struct Ctx { char u0[4]; char *scale; char u8[4]; int a12; };
struct Self { char u0[4]; Vec v4; Vec v16; Vec v28; Vec v40; int a52; unsigned colour; String s60; String s64; void *a68; void *a72; Model *model; };
extern "C" int strcmp_802ef234(const char *, const char *);
inline bool operator==(const String &a, const char *b) { return strcmp_802ef234(a.text, b) == 0; }
extern "C" void string_upper_8020c2e8(String *);
extern "C" void *string_prefix_8020c048(String *, const String *, int);
extern "C" void *string_suffix_8020c0fc(String *, const String *, int);
extern "C" Vec pos_800b43f8(Ctx *, Vec);
extern "C" void pair_800b8c50(Ctx *, Mat *);
extern "C" void rot_801f6120(Mat *, float);
extern "C" void rot_801f61a0(Mat *, float);
extern "C" void rot_801f621c(Mat *, float);
extern "C" void place_8009ed90(Mat *, Vec *);
extern "C" void theme_800606e4(Self *);
extern "C" int set_name_8015adf4(String *, Model **, int);
extern "C" void *as_mesh_80343584(Model *);
extern "C" int mesh_status_80182408(void *);
extern "C" Object *create_8020b680(const void *);
extern "C" void *heap_802098d8(void *, int);
extern "C" void *init_8012656c(void *, void *);
extern "C" void set_801265ec(void *, Vec *);
struct Plain { Object *value; Plain() {} Plain(const Plain &); };
extern "C" void set_80126610(void *, Plain *);
extern "C" void set_80126688(void *, float);
extern "C" void *make_800e5ca4(Vec *, const char *, int, float);
extern const char s_80379168[], s_80379170[], type_80413a68[];
extern float k_80379178[];
extern int heap_804af5bc;
extern "C" void w3d_d31g_landmark_setup_800601a0(Self *self, Info *info, Ctx *ctx) {
    Vec p, o;
    Mat m;
    self->s60 = info->s96;
    self->s64 = info->s92;
    string_upper_8020c2e8(&self->s64);
    { p = pos_800b43f8(ctx, info->v80); }
    pair_800b8c50(ctx, &m);
    m.apply(o, p);
    self->v4 = o;
    self->v16.x = p.x * *(float *)(ctx->scale + 372);
    self->v16.y = p.y * *(float *)(ctx->scale + 376);
    self->v16.z = p.z * *(float *)(ctx->scale + 380);
    Put(self->v28, info->v68);
    rot_801f6120(&m, self->v28.x);
    rot_801f61a0(&m, self->v28.y);
    rot_801f621c(&m, self->v28.z);
    place_8009ed90(&m, &self->v28);
    Put(self->v40, info->v44);
    self->colour = Pack(info->v56);
    self->a52 = ctx->a12;
    String tag;
    string_prefix_8020c048(&tag, &self->s60, 7);
    string_upper_8020c2e8(&tag);
    if (tag == s_80379168) {
        theme_800606e4(self);
        set_name_8015adf4(&self->s64, &self->model, 255);
        self->model->vt->set80(self->model, &self->v28, 0);
        self->model->vt->set76(self->model, &self->v4, 0);
        self->model->vt->set84(self->model, &self->v40, 0);
        mesh_status_80182408(as_mesh_80343584(self->model));
        Vec c = self->v4;
        float radius = k_80379178[0];
        void *a = self->model->a120;
        Ref t;
        t.value = create_8020b680(type_80413a68);
        if (t.value) t.value->vtable->retain(t.value);
        t.value->vtable->use24(t.value, a);
        Bound *b = t.value->vtable->bound64(t.value);
        if (b) { c = b->c; radius = b->r; }
        void *h = heap_802098d8(&heap_804af5bc, 4);
        self->a72 = init_8012656c(h, self->model->vt->get60(self->model));
        set_801265ec(self->a72, &c);
        Plain q;
        q.value = (Object *)self->model;
        if (q.value) q.value->vtable->retain(q.value);
        set_80126610(self->a72, &q);
        set_80126688(self->a72, radius);
    }
    if (tag == s_80379170) {
        String n;
        string_suffix_8020c0fc(&n, &self->s60, self->s60.length() - 8);
        self->a68 = make_800e5ca4(&self->v4, n.text, 0, k_80379178[0]);
    }
}
