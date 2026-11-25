// GWMP8P rev0 0x8014f18c. Worm ground probe. Field names are inferred from
// use.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void unit(float l) { float f = 1.0f / sqrt_802e82c0(l); x *= f; y *= f; z *= f; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Probe {
    int a, b;
    Probe();
    ~Probe();
};
extern "C" void probe_radius_8012629c(Probe *, float);
extern "C" void probe_owner_80126308(Probe *, int);
extern "C" void probe_group_8012632c(Probe *, int);
extern "C" void probe_mask_801262e4(Probe *, int);
extern "C" void probe_position_801262c0(Probe *, const Vec &);
extern "C" int probe_nearest_801263fc(Probe *, const Vec &, int, int);
struct Target { char u0[20]; unsigned flags; };
extern unsigned short kind_804aa95e;
extern "C" Target *lookup_8003f240(int);
extern "C" void slope_80149348(struct Worm *);
struct Worm {
    char u0[20]; int id; char u18[536]; Vec pos; char u23c[144]; int moving; char u2d0[40]; int state; char u2fc[60]; int flags; char u33c[376]; Vec normal;
};
extern int hits_804b1790;
extern float hitT_804b17a4;
extern "C" int d28d_worm_ground_probe_8014f18c(Worm *self, int limit, const Vec &from, const Vec &dir, int range, const Vec &slide) {
    Probe q;
    probe_radius_8012629c(&q, 10.0f);
    probe_owner_80126308(&q, self->id);
    probe_group_8012632c(&q, 1041);
    probe_mask_801262e4(&q, 1);
    Vec a = from;
    a.y += 10.0f;
    probe_position_801262c0(&q, a);
    Vec b = dir;
    if (probe_nearest_801263fc(&q, b, range, self->id) == 0xffff) return 0;
    if (hits_804b1790 > limit) return 0;
    if (hits_804b1790 == 0) {
        self->flags |= 0x80000000;
        Vec n = a - Vec(*(const Vec *)lookup_8003f240(kind_804aa95e));
        float l = n.lenSq();
        if (l > 0.0f) {
            n.unit(l);
            if (n.y < 0.7072f) {
                if (!self->moving) {
                    self->state = 9;
                    self->normal = n;
                    slope_80149348(self);
                    return 1;
                }
            } else if (!self->moving) return 1;
            if (lookup_8003f240(kind_804aa95e)->flags & 1) {
                Vec v = slide;
                float m = v.lenSq();
                if (m > 0.0f) {
                    v.unit(m);
                    if (acos_802e79e0(clamp(n.dot(v), -1.0f, 1.0f)) >= 1.5707964f) { self->state = 0; goto done; }
                    return 0;
                }
            }
        }
        return 1;
    }
    {
    Vec p = a + b * hitT_804b17a4;
    Vec n = p - Vec(*(const Vec *)lookup_8003f240(kind_804aa95e));
    n.unit(n.lenSq());
    if (self->moving && (lookup_8003f240(kind_804aa95e)->flags & 1)) {
        Vec v = slide;
        float m = v.lenSq();
        if (!(m > 0.0f)) return 1;
        v.unit(m);
        if (acos_802e79e0(clamp(n.dot(v), -1.0f, 1.0f)) >= 1.5707964f) { self->state = 0; goto done; }
        return 0;
    }
    self->pos = p;
    self->pos.y -= 10.0f;
    self->normal = n;
    self->flags |= 0x80000000;
    slope_80149348(self);
    }
    if (self->normal.y < 0.7072f && !self->moving) {
        self->state = 9;
    }
done:
    return 1;
}
