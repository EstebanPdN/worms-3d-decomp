// GWMP8P rev0 0x8014157c. Average the ground normal under a worm: test ten
// collision corners, add the unit vector from a point 10 units above each
// contact to the sum, then return the normalised direction from the mean to
// the reference point, or straight up when there is no contact or the result
// has zero length. The rotation matrix is built and never read in the
// original. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    void unit() { float f = 1.0f / sqrt_802e82c0(lenSq()); x *= f; y *= f; z *= f; }
    Vec safeUnit() {
        float l = lenSq();
        if (l > 0.0f) { float f = 1.0f / sqrt_802e82c0(l); x *= f; y *= f; z *= f; return *this; }
        x = 0.0f; y = 1.0f; z = 0.0f;
        return *this;
    }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Matrix { float m[16]; };
extern "C" void rotation_801f725c(Matrix *, float, float, float, float);
extern "C" void test_800b0824(const Vec &, const Vec &, void *, int, int);
extern Vec corners_80453030[];
extern Vec reference_8045e788;
extern unsigned traceFrac_804b1764;
extern int traceDone_804b1810;
extern "C" Vec d26d_worm_ground_normal_8014157c(void *self, const Vec &pos, const Vec &dir, void *user, const Vec &rot, int id) {
    Vec n(0.0f, 0.0f, 0.0f);
    Matrix m;
    rotation_801f725c(&m, 0.0f, 1.0f, 0.0f, rot.y);
    int count = 0;
    Vec o, start;
    Vec sum(0.0f, 0.0f, 0.0f);
    for (int i = 0; i <= 9; i++) {
        o = corners_80453030[i];
        start = pos + o;
        test_800b0824(start, dir, user, id, 1);
        if (traceFrac_804b1764 == 0 && traceDone_804b1810) {
            count++;
            Vec d = o;
            d.y -= 10.0f;
            d.unit();
            sum.x += d.x; sum.y += d.y; sum.z += d.z;
        }
    }
    if (count) {
        float f = 1.0f / count;
        n = (reference_8045e788 - sum) * f;
        return n.safeUnit();
    }
    n.set(0.0f, 1.0f, 0.0f);
    return n;
}
