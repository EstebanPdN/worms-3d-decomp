// d40i: 0x8011fc48. Follow camera: when the target is lost, blocked or too
// far and the patience has run out, walks up to three ring waypoints around
// the target and moves to the first with a clear view. Vectors are copied by
// plain assignment in the body; temporaries at 120 and 152 lose their stores
// to the flow pass, which leaves the reloaded z.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
    float lenSq() const { return x * x + y * y + z * z; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float s) { Vec r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
inline void cross(const Vec &a, Vec &o, const Vec &v) {
    o.x = a.y * v.z - a.z * v.y;
    o.y = a.z * v.x - a.x * v.z;
    o.z = a.x * v.y - a.y * v.x;
}
inline float dist(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
struct Ring { char u0[24]; unsigned count; char u28[4]; };
struct Config { char u0[20]; Ring *points; unsigned patience; float clearance; char u32[16]; float range; };
struct Camera {
    char u0[4]; Vec pos; Vec target; Vec off; char u40[24]; void *curve; char u68[16]; unsigned timer; void *cfg; int last; char u96[76]; int blocked; unsigned index;
};
extern Vec zero_8044f2b4[];
extern "C" void *ref_80341584(void *);
extern "C" Config *cfg_801797b4(void *);
extern "C" int sees_80121330(const Vec &);
extern "C" int ray_8015ac04(Camera *, const Vec *, const Vec *);
extern "C" float height_80178df0(void *);
extern "C" void moved_80121568(Camera *);
extern "C" void d40i_camera_ring_step_8011fc48(Camera *self, const Vec &target, const Vec &up, const Vec &anchor, const Vec &back) {
    Config *cfg = cfg_801797b4(ref_80341584(self->cfg));
    int seen = sees_80121330(target);
    int was = self->blocked || seen;
    self->blocked = was;
    int lost = 0;
    if (was) lost = seen ^ 1;
    int clear = ray_8015ac04(self, &self->pos, &target) ^ 1;
    bool far = dist(target, self->pos) >= cfg->range;
    unsigned wait = cfg->patience; bool late = self->timer >= wait;
    if ((lost || clear || far) && late) {
        Vec p, w, d, v;
        Vec right = target - self->pos;
        d = right;
        d.y = 0.0f;
        if (d.lenSq() == 0.0f) d.set(0.0f, 0.0f, 1.0f);
        { float f = 1.0f / sqrt_802e82c0(d.lenSq()); d.x *= f; d.y *= f; d.z *= f; }
        float sign = up.z * d.x - up.x * d.z;
        Vec top;
        Vec e;
        e = back;
        e.y = 0.0f;
        if (e.lenSq() == 0.0f) e.set(0.0f, 0.0f, 1.0f);
        { float f = 1.0f / sqrt_802e82c0(e.lenSq()); e.x *= f; e.y *= f; e.z *= f; }
        top = Vec(0.0f, 1.0f, 0.0f);
        cross(top, right, e);
        Ring *ring = cfg->points;
        unsigned count = ring->count;
        Vec *pts = (Vec *)(ring + 1);
        for (unsigned k = 0; k <= 2; k++) {
            p = anchor;
            w = pts[self->index];
            p += right * w.x;
            p += top * w.y;
            p += e * w.z;
            v = target - p;
            v.y = 0.0f;
            {
                float l = v.lenSq();
                if (l == 0.0f) v.set(0.0f, 0.0f, 1.0f);
                else { float f = 1.0f / sqrt_802e82c0(l); v.x *= f; v.y *= f; v.z *= f; }
            }
            bool side = sign * (up.z * v.x - up.x * v.z) > -0.00001f;
            int a = ray_8015ac04(self, &p, &target);
            bool high = p.y > height_80178df0(self->curve) + cfg->clearance;
            int b = ray_8015ac04(self, &p, &anchor);
            if (side && a && high && b) {
                if (self->index != self->last) {
                    moved_80121568(self);
                    self->pos = p;
                    self->target = target;
                    self->off = zero_8044f2b4[0];
                    self->timer = 0;
                    self->last = self->index;
                }
                return;
            }
            self->index = (self->index + 1) % count;
        }
    }
}
