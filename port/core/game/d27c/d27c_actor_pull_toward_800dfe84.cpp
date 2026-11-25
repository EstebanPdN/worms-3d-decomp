#include "w3d_ptr.h"
#line 1 "d27c_actor_pull_toward_800dfe84.cpp"
// d27c: 0x800dfe84. Adds to an accumulated vector the offset from the actor to a target, weighted by a falling time factor. Names are inferred.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec3 &operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Actor { Vec3 pos; char u12[88]; unsigned start; };
extern "C" void d27c_actor_pull_toward_800dfe84(Ptr32<Actor> self, Ptr32<Vec3> out, unsigned now, Ptr32<Vec3> target, unsigned dur) {
    unsigned end = self->start + dur;
    now -= self->start;
    if (now < end) {
        float t = (float)now / (float)end;
        Vec3 d = *target - self->pos;
        *out += d * (1.0f - t);
    }
}


