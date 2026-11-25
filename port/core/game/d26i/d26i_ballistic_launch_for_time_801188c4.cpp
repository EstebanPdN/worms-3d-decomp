#include "w3d_ptr.h"
#line 1 "d26i_ballistic_launch_for_time_801188c4.cpp"
// GWMP8P rev0 0x801188c4. Sets a ballistic solver's launch velocity for a
// given flight time.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    Vec &operator/=(float s) { float f = 1.0f / s; x *= f; y *= f; z *= f; return *this; }
    Vec &operator*=(float f) { x *= f; y *= f; z *= f; return *this; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float s) { Vec r(a.x * s, a.y * s, a.z * s); return r; }
struct Ball { Vec pos; Vec v12; Vec accel; float u36, u40; Vec target; char u56[96]; Vec v152; char u164[12]; float t176, t180; };
extern "C" void w3d_copy12_800d7788(Ptr32<Ball>, const Vec &);
extern "C" int d26i_ballistic_launch_for_time_801188c4(Ptr32<Ball> self, float t) {
    self->t176 = t;
    self->t180 = t;
    if (t == 0.0f) {
        Vec up(0.0f, 1.0f, 0.0f);
        w3d_copy12_800d7788(self, up); self->v152 = up;
    } else {
        Vec d = self->target - self->pos;
        Vec &ac = self->accel; Vec g = ac * (t * 0.5f);
        d /= t;
        Vec e = d - g;
        w3d_copy12_800d7788(self, e);
        self->v152 = self->v12;
        return 1;
    }

    return 1;
}


