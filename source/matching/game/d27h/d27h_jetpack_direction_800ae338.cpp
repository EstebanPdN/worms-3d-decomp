// GWMP8P rev0 0x800ae338. Jetpack directional setting. Names are inferred.
// Updates the jetpack part, rotates the forward offset through pitch and yaw
// matrices, adds the reflected gravity minus scaled velocity and stores the
// result in the Jetpack_directional emitter.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { return Vec(a.x - b.x, a.y - b.y, a.z - b.z); }
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform { Axis axis[3]; Pos position; const Pos &P() const { return position; } };
struct Row { float x, y, z, w; };
struct Mat44 {
    Row row[4];
    Mat44(const Transform &t) {
        row[0].x = t.axis[0].x; row[0].y = t.axis[0].y; row[0].z = t.axis[0].z; row[0].w = 0.0f;
        row[1].x = t.axis[1].x; row[1].y = t.axis[1].y; row[1].z = t.axis[1].z; row[1].w = 0.0f;
        row[2].x = t.axis[2].x; row[2].y = t.axis[2].y; row[2].z = t.axis[2].z; row[2].w = 0.0f;
        row[3].x = t.P().x; row[3].y = t.P().y; row[3].z = t.P().z; row[3].w = 1.0f;
    }
    const Row &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" void concat_801f740c(Transform *, const Transform *, const Transform *);
extern "C" void part_800ae7d4(void *, int, int);
struct Object;
struct ObjectVt { void *u[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVt *vt; };
struct Handle {
    Object *p;
    Handle() { p = 0; }
    Handle(Object *next) : p(next) { if (p) p->vt->retain(p); }
    Handle(const Handle &);
    ~Handle() { if (p) p->vt->release(p); }
    void assign(Object *next) {
        if (next) {
            next->vt->retain(next);
            if (p) p->vt->release(p);
            p = next;
        }
    }
};
struct Descriptor_80178474 {
    void *value;
    unsigned tag;
    Descriptor_80178474() : value(0), tag(58280) {}
    ~Descriptor_80178474();
};
struct Key { const char *name; Key(const char *n) { name = n; } };
extern "C" int lookup_800fc1b0(Key *, Handle *);
extern "C" void *identity_80341584(Object *);
extern "C" Object *cast_80179598(void *, Descriptor_80178474 *);
extern Vec g_8045e788;
struct Emitter { unsigned char u[144]; Vec dir; void SetDir(const Vec &v) { dir = v; } };
extern "C" void d27h_jetpack_direction_800ae338(void *self, int a, int b, const Vec &rot, const Vec &vel) {
    if (a && b) part_800ae7d4(self, 2, 2);
    else part_800ae7d4(self, 2, 0);
    float zero = 0.0f;
    Vec fwd;
    Vec *q = &fwd;
    q->x = zero;
    q->y = -0.5f;
    q->z = -10.0f;
    Transform ty, tx, t;
    construct_801f7538(&ty, zero, 1.0f, zero, rot.y);
    construct_801f7538(&tx, 1.0f, zero, zero, rot.x);
    concat_801f740c(&t, &ty, &tx);
    Vec out;
    Mat44(t).rotate(out, fwd);
    Vec d = g_8045e788 - vel * 10.0f;
    if (d.y >= zero) d.y = zero - d.y;
    out.x += d.x;
    out.y += d.y;
    out.z += d.z;
    Descriptor_80178474 desc;
    Handle h;
    Key k("Jetpack_directional");
    lookup_800fc1b0(&k, &h);
    Handle e;
    {
        Handle c(cast_80179598(identity_80341584(h.p), &desc));
        e.assign(c.p);
    }
    ((Emitter *)e.p)->SetDir(out);
}
