#include "w3d_ptr.h"
#line 1 "d27c_rope_unwind_segment_800d13d0.cpp"
// d27c: 0x800d13d0. Removes the last rope segment when the line back to the previous anchor is clear and the swing has passed it: traces from the player to the anchor, tests the side against the segment direction, pops it and rescales to the new length. Names are inferred; the copy of the hit point at sp+72 is written but not read.
extern "C" float sqrt_802e82c0(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Seg { Vec3 pos; float len; Vec3 dir; };
struct Segs {
    Ptr32<Seg> start; Ptr32<Seg> finish;
    unsigned size() const { return finish - start; }
    Seg &operator[](int i) { return start[i]; }
    void pop() { --finish; }
};
struct Rope { char u0[28]; Segs segs; };
extern Vec3 zero_8045e788[], hit_8043ae20[];
extern int frac_804b1764;
extern "C" int trace_800b0824(const Vec3 &, const Vec3 &, const Vec3 &, int, int);
extern "C" void rescale_800d1628(Ptr32<Rope>, float, float);
extern "C" void d27c_rope_unwind_segment_800d13d0(Ptr32<Rope> self, const Vec3 &at) {
    Segs &v = self->segs;
    unsigned n = v.size();
    if (n > 1) {
        float one = 1000.0f;
        int i = n - 1;
        float k = 1.0f / one;
        Vec3 z(zero_8045e788[0]);
        Vec3 a(v[i - 1].pos);
        Vec3 b(at);
        Vec3 d = (a - b) * k;
        trace_800b0824(b, d, z, 1000, 1);
        Vec3 h(hit_8043ae20[0]);
        if (frac_804b1764 > 1000) {
            Vec3 dir(v[i - 1].dir);
            Vec3 e = b - a;
            if (dir.x * e.x + dir.y * e.y + dir.z * e.z > 0.0f) {
                float old = v[i].len;
                v.pop();
                i = v.size() - 1;
                float dx = at.x - v[i].pos.x, dy = at.y - v[i].pos.y, dz = at.z - v[i].pos.z;
                float l = sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
                v[i].len = l;
                rescale_800d1628(self, old, l);
            }
        }
    }
}


