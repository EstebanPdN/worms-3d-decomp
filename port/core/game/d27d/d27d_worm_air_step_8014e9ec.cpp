#include "w3d_ptr.h"
#line 1 "d27d_worm_air_step_8014e9ec.cpp"
// GWMP8P rev0 0x8014e9ec. Advance a falling worm one step: trace its scaled
// velocity from a raised position and stop when the landing test 0x8014f18c
// accepts. Bump along the segment after a clear drop; with no steps taken
// reflect the velocity off the flattened ground direction; otherwise test
// the slope and either land on the trace point, storing the normal and
// setting the moving flag, or re-trace from the surface and slide or
// reflect. Update the velocity in state 1 and recompute the slope. Names are
// inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void unit() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec &operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Tracer { int t; };
struct Worm {
    char u0[560]; Vec pos; Vec rot; char u248[20]; int f604, f608; char u264[64]; Vec vel; char u2b0[28]; int moving; char u2d0[40]; int state; char u2fc[388]; Tracer tracer; char u484[48]; Vec normal; Ptr32<void> height;
};
extern "C" float level_80178df0(Ptr32<void>);
extern "C" void trace_801412a4(Ptr32<Tracer>, const Vec &, const Vec &, const Vec &, const Vec &, int, int);
extern "C" int steps_80141554(Ptr32<Tracer>);
extern "C" Ptr32<const Vec> point_8014155c(Ptr32<Tracer>);
extern "C" int collided_801418c4(Ptr32<Tracer>);
extern "C" int fieldA_8014156c(Ptr32<Tracer>);
extern "C" int fieldB_80141574(Ptr32<Tracer>);
extern "C" int hit_8014f18c(Ptr32<Worm>, int, const Vec &, const Vec &, int, const Vec &);
extern "C" void bump_80153cf0(Ptr32<Worm>, const Vec &);
extern "C" void step_80146e30(Ptr32<Worm>);
extern "C" Vec direction_80146f10(Ptr32<Worm>);
extern "C" int limit_8014c7fc(Ptr32<const Vec>);
extern "C" int check_801531b0(Ptr32<Worm>, const Vec &);
extern "C" void apply_80153f80(Ptr32<Worm>, const Vec &, const Vec &);
extern "C" void slope_80149348(Ptr32<Worm>);
extern "C" void d27d_worm_air_step_8014e9ec(Ptr32<Worm> self) {
    Vec a, b, c, w;
    Vec v = self->vel * 20.0f;
    float h = level_80178df0(self->height);
    a = self->pos + v;
    a.y += h;
    b.set(0.0f, -h * 2.0f * 0.02f, 0.0f);
    c.set(0.0f, 0.0f, 0.0f);
    trace_801412a4(&self->tracer, a, b, c, self->rot, 100, 1);
    int n = steps_80141554(&self->tracer);
    if (hit_8014f18c(self, n, a, b, 100, v)) return;
    if (!collided_801418c4(&self->tracer) && point_8014155c(&self->tracer)->y < self->pos.y) {
        bump_80153cf0(self, v);
        return;
    }
    if (n == 0) {
        a = self->pos;
        a.y += h;
        b = v * 0.02f;
        trace_801412a4(&self->tracer, a, b, c, self->rot, 100, 1);
        step_80146e30(self);
        w = direction_80146f10(self);
        w.y = 0.0f;
        float l = w.lenSq();
        if (l > 0.0f) {
            float f = 1.0f / sqrt_802e82c0(l);
            w.x *= f; w.y *= f; w.z *= f;
        } else {
            w.set(0.0f, 1.0f, 0.0f);
        }
        v -= w * (2.0f * w.dot(v));
    } else if (n <= 100) {
        step_80146e30(self);
        w = direction_80146f10(self);
        w.unit();
        Vec o(0.0f, 0.0f, 0.0f);
        if (!limit_8014c7fc(&w) && !check_801531b0(self, o)) {
            if (w.dot(v) > 0.0f) {
                bump_80153cf0(self, v);
            } else {
            Vec d = self->vel;
            d.unit();
            d.x *= h; d.y *= h; d.z *= h;
            a = self->pos + d;
            a.y += h;
            trace_801412a4(&self->tracer, a, b, c, self->rot, 100, 1);
            n = steps_80141554(&self->tracer);
            if (n == 0) {
                w.y = 0.0f;
                w.unit();
                v -= w * (2.0f * w.dot(v));
            } else {
                Vec q = self->pos + v * 0.05f;
                if (n <= 100) q.y += (point_8014155c(&self->tracer)->y - q.y) * 0.5f;
                apply_80153f80(self, self->pos, q);
            }
            }
        } else if (point_8014155c(&self->tracer)->y >= self->pos.y - h) {
            apply_80153f80(self, self->pos, *point_8014155c(&self->tracer));
            self->f608 = fieldA_8014156c(&self->tracer);
            self->f604 = fieldB_80141574(&self->tracer);
            self->normal = w;
            self->moving = 1;
        } else {
            bump_80153cf0(self, v);
        }
    } else {
        bump_80153cf0(self, v);
    }
    if (self->state == 1) self->vel = v * 0.05f;
    slope_80149348(self);
}


