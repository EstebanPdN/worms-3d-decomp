#include "w3d_ptr.h"
#line 1 "d27d_worm_spot_clear_8014a9f8.cpp"
// GWMP8P rev0 0x8014a9f8. Test whether a worm can stand at a spot: scan the
// handle list of nearby worms, returning 1 if one lies more than 90 degrees
// from the facing direction within a low vertical band; otherwise trace
// downward from the spot, 10 units ahead along the yaw and 20 up, and return
// 1 if the trace starts clear or lands above the worm's height plus the
// water level. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
    void unit() { float l = lenSq(); if (l > 0.0f) { float f = 1.0f / sqrt_802e82c0(l); x *= f; y *= f; z *= f; } }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Axis { float x, y, z, w; };
struct Pos { float x, y, z, w; };
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &A(int i) const { return axis[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z;
    }
};
struct Handle {
    void start(const Vec &v, int n);
    int clock();
    void finish();
 char w3d_empty; };
extern "C" void start_80126384(Ptr32<Handle>, const Vec &, int);
extern "C" int clock_801264fc(Ptr32<Handle>);
extern "C" void finish_80126524(Ptr32<Handle>);
inline void Handle::start(const Vec &v, int n) { start_80126384(this, v, n); }
inline int Handle::clock() { return clock_801264fc(this); }
inline void Handle::finish() { finish_80126524(this); }
struct Worm { char u0[560]; Vec pos; float u23c; float yaw; char u244[564]; Handle handle; char u47c[71]; Ptr32<void> water; };
extern unsigned short kind_804aa95e;
extern "C" Ptr32<const Vec> lookup_8003f240(int);
inline Vec lookup() { return *lookup_8003f240(kind_804aa95e); }
extern "C" float level_80178df0(Ptr32<void>);
extern "C" void construct_801f725c(Ptr32<Transform>, float, float, float, float);
extern "C" void test_800b0824(const Vec &, const Vec &, const Vec &, int, int);
extern unsigned traceFrac_804b1764;
extern Vec tracePoint_8043ae20;
extern "C" int d27d_worm_spot_clear_8014a9f8(Ptr32<Worm> self, const Vec &dir) {
    Vec p = self->pos;
    Vec v;
    p.y += 10.0f;
    Vec d = dir;
    d.unit();
    Vec t = dir;
    self->handle.start(t, 20);
    bool found = false;
    if (self->handle.clock() != 0xffff) do {
        v = p - lookup();
        if (v.lenSq() > 0.0f && d.lenSq() > 0.0f) {
            v.unit();
            float a = acos_802e79e0(clamp(v.dot(d), -1.0f, 1.0f));
            if (a > 1.5707964f && v.y < 0.7072f) { found = true; break; }
        }
    } while (self->handle.clock() != 0xffff);
    self->handle.finish();
    if (found) return 1;
    float water = level_80178df0(self->water);
    Vec b = self->pos + dir;
    b.y += 20.0f;
    Transform m;
    construct_801f725c(&m, 0.0f, 1.0f, 0.0f, self->yaw);
    Vec fw(0.0f, 0.0f, 10.0f);
    Vec o;
    m.rotate(o, fw);
    b += o;
    Vec down(0.0f, -0.79999995f, 0.0f);
    Vec zero(0.0f, 0.0f, 0.0f);
    test_800b0824(b, down, zero, 100, 1);
    unsigned frac = traceFrac_804b1764;
    if (frac == 0) return 1;
    if (frac <= 100) {
        Vec hit = tracePoint_8043ae20;
        if (hit.y > self->pos.y + water) return 1;
    }
    return 0;
}


