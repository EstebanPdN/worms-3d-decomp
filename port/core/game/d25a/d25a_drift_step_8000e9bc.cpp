#include "w3d_ptr.h"
#line 1 "d25a_drift_step_8000e9bc.cpp"
/* Random drift step (0x8000e9bc): fills a vector through 0x80015910 with scale
 * 1, subtracts a vector of ones, scales it by the frame step (+156 of 0x804aa6d8),
 * adds it to the position at +24, copies the vector 0x8045e788 to +36 and continues
 * with 0x8000affc(self, 1, 0.0). Field and type names are inferred from the original
 * instructions. Globals and literals are external views of original data; the unit
 * owns no data. */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float v) { x = v; y = v; z = v; }
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
    void operator-=(const Vec3 &o) { x -= o.x; y -= o.y; z -= o.z; }
    void operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; }
    Vec3 operator*(float s) const { Vec3 r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
};
struct Plain3 { int a, b, c; };
struct Drift {
    char unknown00[24];
    Vec3 position;             /* +24 */
    Plain3 velocity;           /* +36 */
};
struct Clock { char unknown00[156]; float step; };
extern Ptr32<Clock> w3d_clock_804aa6d8;
extern Plain3 w3d_vector_8045e788[];
extern const float w3d_float_80369fcc[], w3d_float_80369fd0[];
extern "C" void w3d_random_vector_80015910(Ptr32<Vec3>, float);
extern "C" void w3d_continue_8000affc(Ptr32<Drift>, int, float);

extern "C" void w3d_d25a_drift_step_8000e9bc(Ptr32<Drift> self)
{
    float one = w3d_float_80369fcc[0];
    Vec3 v(one);
    w3d_random_vector_80015910(&v, one);
    {
        Vec3 u;
        Ptr32<Vec3> q = &u;
        q->x = one;
        q->y = one;
        q->z = one;
        v -= u;
    }
    Vec3 delta = v * w3d_clock_804aa6d8->step;
    self->position += delta;
    self->velocity = w3d_vector_8045e788[0];
    w3d_continue_8000affc(self, 1, w3d_float_80369fd0[0]);
}


