// GWMP8P rev0 0x80152a80. Find the most upward ground normal around a worm:
// trace from two yaw-rotated side offsets of the position, then from the
// position toward each of those points in 20 steps, and keep the unit trace
// normal with the largest y. The last two traces reuse the earlier step
// count, as the original does. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    void unit(float l) { float f = 1.0f / sqrt_802e82c0(l); x *= f; y *= f; z *= f; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator/(const Vec &a, float k) { float f = 1.0f / k; Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
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
struct Worm { char u0[560]; Vec pos; float u23c; float yaw; char u244[96]; Vec vel; Vec acc; };
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" void test_800b0824(const Vec &, const Vec &, const Vec &, int, int);
extern "C" void compute_800bd920();
extern unsigned traceFrac_804b1764;
extern int traceReady_804b1784;
extern Vec traceNormal_8043ae38;
extern const Vec zero_8045e788;
extern "C" Vec d27d_worm_probe_ground_normal_80152a80(Worm *self) {
    Vec a(3.0f, 0.0f, 3.0f);
    Vec b(-3.0f, 0.0f, 3.0f);
    Vec best(0.0f, 0.0f, 0.0f);
    Vec n(0.0f, 0.0f, 0.0f);
    Transform m;
    construct_801f7538(&m, 0.0f, 1.0f, 0.0f, self->yaw);
    Vec p;
    Matrix(m).rotate(p, a);
    p += self->pos;
    test_800b0824(p, self->vel, self->acc, 20, 1);
    unsigned frac = traceFrac_804b1764;
    if (frac <= 20) {
        if (!traceReady_804b1784) compute_800bd920();
        n = traceNormal_8043ae38;
        float l = n.lenSq();
        if (l > 0.0f) {
            n.unit(l);
            if (n.y > best.y) best = n;
        }
    }
    Vec q;
    Matrix(m).rotate(q, b);
    q += self->pos;
    test_800b0824(q, self->vel, self->acc, 20, 1);
    frac = traceFrac_804b1764;
    if (frac <= 20) {
        if (!traceReady_804b1784) compute_800bd920();
        n = traceNormal_8043ae38;
        float l = n.lenSq();
        if (l > 0.0f) {
            n.unit(l);
            if (n.y > best.y) best = n;
        }
    }
    Vec d = (p - self->pos) / 20.0f;
    Vec zero = zero_8045e788;
    test_800b0824(self->pos, d, zero, 20, 1);
    if (frac <= 20) {
        if (!traceReady_804b1784) compute_800bd920();
        n = traceNormal_8043ae38;
        float l = n.lenSq();
        if (l > 0.0f) {
            n.unit(l);
            if (n.y > best.y) best = n;
        }
    }
    d = (q - self->pos) / 20.0f;
    test_800b0824(self->pos, d, zero, 20, 1);
    if (frac <= 20) {
        if (!traceReady_804b1784) compute_800bd920();
        n = traceNormal_8043ae38;
        float l = n.lenSq();
        if (l > 0.0f) {
            n.unit(l);
            if (n.y > best.y) best = n;
        }
    }
    return best;
}
