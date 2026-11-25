// GWMP8P rev0 0x8014ae84. Test whether a worm can jump from a spot: scan the
// nearby object list and refuse if any object has flag bit 0; trace from the
// offset head position downward, then along the rotated jump speed plus the
// scaled motion for up to 1000 steps. Accept only when the trace ends above
// the worm, reports a collision and the unit normal passes the slope limit
// at 0x8014c89c. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void unit() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
    Vec &operator*=(float k) { x *= k; y *= k; z *= k; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform { Axis a[3]; Pos p; const Pos &P() const { return p; } };
struct Row { float x, y, z, w; };
struct Matrix {
    Row r[4];
    Matrix(const Transform &t) {
        r[0].x = t.a[0].x; r[0].y = t.a[0].y; r[0].z = t.a[0].z; r[0].w = 0.0f;
        r[1].x = t.a[1].x; r[1].y = t.a[1].y; r[1].z = t.a[1].z; r[1].w = 0.0f;
        r[2].x = t.a[2].x; r[2].y = t.a[2].y; r[2].z = t.a[2].z; r[2].w = 0.0f;
        r[3].x = t.P().x; r[3].y = t.P().y; r[3].z = t.P().z; r[3].w = 1.0f;
    }
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Handle { int h; };
struct Tracer { int t; };
struct Worm {
    char u0[560]; Vec pos; Vec rot; char u248[104]; Vec vel; char u2bc[444]; Handle handle; char u47c[4]; Tracer tracer; char u484[68]; void *scale; char u4cc[12]; void *a; void *b;
};
extern "C" void start_80126384(Handle *, const Vec &, int);
extern "C" int clock_801264fc(Handle *);
extern "C" void finish_80126524(Handle *);
struct Item { char u0[20]; unsigned flags; };
extern unsigned short kind_804aa95e;
extern "C" Item *lookup_8003f240(int);
extern "C" float level_80178df0(void *);
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" void trace_801412a4(Tracer *, const Vec &, const Vec &, const Vec &, const Vec &, int, int);
extern "C" int steps_80141554(Tracer *);
extern "C" const Vec *point_8014155c(Tracer *);
extern "C" int collided_801418c4(Tracer *);
extern "C" const Vec *normal_80141564(Tracer *);
extern "C" const Vec *speed_80178ec4(void *);
extern "C" Vec motion_8014b8ec(Worm *);
extern "C" int limit_8014c89c(const Vec *);
extern void *speedE_804afde8;
extern "C" int d27d_worm_jump_clear_8014ae84(Worm *self, const Vec &at) {
    Vec t = at;
    bool found = false;
    start_80126384(&self->handle, t, 20);
    if (clock_801264fc(&self->handle) != 0xffff) {
        int id;
        do {
            Item *it = lookup_8003f240(kind_804aa95e);
            if (it->flags & 1) found = true;
            id = clock_801264fc(&self->handle);
        } while (!found && id != 0xffff);
    }
    finish_80126524(&self->handle);
    if (found) return 0;
    float l1 = level_80178df0(self->a);
    Vec o(0.0f, l1, level_80178df0(self->b));
    Transform m;
    construct_801f7538(&m, 0.0f, 1.0f, 0.0f, self->rot.y);
    Vec w;
    Matrix(m).rotate(w, o);
    Vec start = w + self->pos;
    t.set(0.0f, -0.1f, 0.0f);
    trace_801412a4(&self->tracer, start, t, self->vel, self->rot, 1000, 1);
    if (!steps_80141554(&self->tracer)) return 0;
    const Vec &sp = *speed_80178ec4(speedE_804afde8);
    Matrix(m).rotate(t, sp);
    Vec p = self->pos;
    Vec v = self->vel;
    Vec g = motion_8014b8ec(self);
    g.x *= level_80178df0(self->scale);
    g.y = 0.0f;
    g.z *= level_80178df0(self->scale);
    g *= 0.05f;
    v += g;
    trace_801412a4(&self->tracer, self->pos, t, v, self->rot, 1000, 1);
    int n = steps_80141554(&self->tracer);
    if (!n || n > 1000) return 0;
    Vec hit = *point_8014155c(&self->tracer);
    if (hit.y <= self->pos.y) return 0;
    if (!collided_801418c4(&self->tracer)) return 0;
    Vec nn = *normal_80141564(&self->tracer);
    nn.unit();
    int r;
    if (limit_8014c89c(&nn)) r = 1;
    else r = 0;
    return r;
}
