// GWMP8P rev0 0x801418dc. Walk a worm from its position toward a target in
// two half steps and test the corner edge from the table at each point. If
// the edge is blocked at the start or nothing blocks, the position moves to
// the target; if it blocks later the position is left unchanged. The 0.01
// scale is one over the 100-unit test length. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Edge { int a, b; };
extern Edge edges_804ab3d0[1];
extern Vec corners_80453030[];
extern Vec reference_8045e788;
extern unsigned traceFrac_804b1764;
extern "C" void test_800b0824(const Vec &, const Vec &, const Vec &, int, int);
inline float inv(float a) { return 1.0f / a; }
inline Vec operator/(const Vec &a, float k) { return a * (1.0f / k); }
extern "C" void d26d_worm_step_clear_801418dc(void *self, Vec &pos, const Vec &target) {
    float steps = 2.0f;
    Vec step = (target - pos) * (1.0f / steps);
    Vec p = pos;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j < 1; j++) {
            Vec s = p + corners_80453030[edges_804ab3d0[j].a];
            Vec e = p + corners_80453030[edges_804ab3d0[j].b];
            Vec v = e - s;
            float r = 100.0f;
            Vec d = v * (1.0f / r);
            test_800b0824(s, d, reference_8045e788, 100, 1);
            if ((float)traceFrac_804b1764 <= 90.0f) {
                if (i == 0) goto done;
                return;
            }
        }
        p += step;
    }
done:
    pos = target;
}
