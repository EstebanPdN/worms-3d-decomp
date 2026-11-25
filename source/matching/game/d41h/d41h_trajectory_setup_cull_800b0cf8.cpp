// GWMP8P rev0 0x800b0cf8. Sets up the swept trajectory query like
// 0x800b0824, then culls the mesh tree with the caller's radius. The vector
// helpers are partial views; names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void Assign(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    void Normalize(float zero) { float n = lenSq(); if (n > zero) { float k = 1.0f / sqrt_802e82c0(n); x *= k; y *= k; z *= k; } }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Pos { float x, y, z; Pos(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; } };
inline Vec Mul(const Vec &a, float k) { return Vec(a.x * k, a.y * k, a.z * k); }
inline Vec operator+(const Vec &a, const Vec &b) { return Vec(a.x + b.x, a.y + b.y, a.z + b.z); }
inline float LenSq(const Pos &v) { return v.x * v.x + v.y * v.y + v.z * v.z; }
inline float Len(const Pos &v) { return sqrt_802e82c0(LenSq(v)); }
extern int lbl_804b1784;
extern int lbl_804b1810;
extern int lbl_804b1764;
extern unsigned lbl_804b1814;
extern float lbl_804b1818;
extern float lbl_804b181c;
extern int lbl_804b1820;
struct Mesh; extern Mesh *lbl_804b17e0;
extern Vec lbl_8043add8[];
extern Vec lbl_8043ade4[];
extern Vec lbl_8043adf0[];
extern Vec lbl_8043adfc[];
extern "C" void d32h_mesh_tree_cull_800bcdec(Mesh *, float);
extern "C" void d41h_trajectory_setup_cull_800b0cf8(const Vec &pos, const Vec &vel, const Vec &acc, unsigned steps, int extra, float f) {
    float t = (float)steps;
    lbl_804b1810 = 0;
    lbl_804b1784 = 0;
    Vec normal;
    Vec e;
    float range;
    if (acc.x == 0.0f && acc.y == 0.0f && acc.z == 0.0f) {
        range = vel.len() * t;
        normal.Set(0.0f, 0.0f, 0.0f);
    } else {
        float half = 0.5f;
        { Vec a(vel * t); Vec c(acc * (t * t * half)); e.Assign(a + c); }
        range = e.lenSq();
        float aa = acc.dot(acc);
        float b = acc.dot(vel) * 3.0f;
        float c = vel.lenSq() * 2.0f; float disc = b * b - aa * 4.0f * c;
        if (disc >= 0.0f) {
            float s = -(b + sqrt_802e82c0(disc)) / (aa + aa);
            if (s < t) {
                { Vec a(vel * s); Vec c; c.Assign(acc * (s * s * half)); e.Assign(a + c); }
                float d = e.lenSq();
                if (d > range) range = d;
            }
        }
        range = sqrt_802e82c0(range);
        const float zero = 0.0f;
        normal.Set(vel.y * acc.z - vel.z * acc.y, vel.z * acc.x - vel.x * acc.z, vel.x * acc.y - vel.y * acc.x);
        normal.Normalize(zero);
    }
    float m = vel.len();
    { Vec a(acc * t); e.Assign(vel + a); }
    float m2 = e.len();
    if (m > m2) m2 = m;
    float inv2 = 1.0f / (m2 * m2);
    Vec v(vel * (1.0f / m2));
    Vec a; a.Assign(Mul(acc, inv2));
    lbl_8043add8[0] = pos;
    lbl_8043ade4[0] = v;
    lbl_8043adf0[0] = a;
    lbl_804b1764 = steps + 1;
    lbl_804b1814 = steps;
    lbl_804b1818 = m2;
    lbl_804b181c = range;
    lbl_8043adfc[0] = normal;
    lbl_804b1820 = extra;
    if (lbl_804b17e0) d32h_mesh_tree_cull_800bcdec(lbl_804b17e0, f);
}
