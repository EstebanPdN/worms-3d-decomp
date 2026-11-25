#include "w3d_ptr.h"
#line 1 "d28d_worm_air_move_80146190.cpp"
// GWMP8P rev0 0x80146190. Worm airborne movement step. Field names are
// inferred from use; the pool words 0x803a0f90..0x803a0f9b are original data
// owned to place the literals.
// The unit's .rodata starts with the last three words of the preceding pool
// (0x803a0f90..0x803a0f9b). They have no reader here. They place this function's
// literals 4 bytes past the 8-byte boundary that the double requires. One word
// alone would go to small data under -G 8, so the view holds three.
extern const float lbl_803a0f90[3] = { -0.25f, 0.01f, 100.0f };
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void unit() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline Vec operator/(const Vec &a, float k) { float f = 1.0f / k; Vec r; r.x = a.x * f; r.y = a.y * f; r.z = a.z * f; return r; }
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline const float &clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Handle { int h; char u4[4]; };
struct Tracer { int t; };
struct Worm {
    char u0[560]; Vec pos; Vec rot; char u248[20]; int f604, f608; char u264[64]; Vec vel; Vec acc; char u2bc[16]; int moving; char u2d0[40]; int state; char u2fc[60]; unsigned flags;
    char u33c[316]; Handle handle; Tracer tracer; char u484[48]; Vec normal;
};
extern "C" void air_80146aa4(Ptr32<Worm>);
extern "C" int blocked_80146b84(Ptr32<Worm>);
extern "C" int landA_8014dc60(Ptr32<Worm>);
extern "C" int landB_8014dc04(Ptr32<Worm>);
extern "C" void sweep_801263bc(Ptr32<Handle>, const Vec &, const Vec &, int);
extern "C" int clock_801264fc(Ptr32<Handle>);
extern "C" void finish_80126524(Ptr32<Handle>);
extern unsigned short kind_804aa95e;
extern "C" Ptr32<const Vec> lookup_8003f240(int);
inline Vec lookup() { return *lookup_8003f240(kind_804aa95e); }
extern "C" void trace_801412a4(Ptr32<Tracer>, const Vec &, const Vec &, const Vec &, const Vec &, int, int);
extern "C" unsigned steps_80141554(Ptr32<Tracer>);
extern "C" Ptr32<const Vec> point_8014155c(Ptr32<Tracer>);
extern "C" Ptr32<const Vec> normal_80141564(Ptr32<Tracer>);
extern "C" int fieldA_8014156c(Ptr32<Tracer>);
extern "C" int fieldB_80141574(Ptr32<Tracer>);
extern "C" void apply_80153f80(Ptr32<Worm>, const Vec &, const Vec &);
extern "C" void slope_80149348(Ptr32<Worm>);
inline void land(Ptr32<Worm> self) {
    self->f608 = fieldA_8014156c(&self->tracer);
    self->f604 = fieldB_80141574(&self->tracer);
}
extern "C" void d28d_worm_air_move_80146190(Ptr32<Worm> self) {
    if (self->state == 19) { air_80146aa4(self); return; }
    if (self->vel.lenSq() == 0.0f) {
        if (self->moving) return;
        if ((int)self->flags < 0 && blocked_80146b84(self)) return;
    }
    if (landA_8014dc60(self)) return;
    if (landB_8014dc04(self)) return;
    if (self->state == 1) return;
    self->flags &= 0x7fffffff;
    Vec p = self->pos;
    p.y += 10.0f;
    Vec sum(0.0f, 0.0f, 0.0f);
    int n = 0;
    Vec v;
    Vec d = self->vel;
    float l = d.lenSq();
    if (l > 0.0f) {
        float f = 1.0f / sqrt_802e82c0(l);
        d.x *= f; d.y *= f; d.z *= f;
    }
    sweep_801263bc(&self->handle, self->vel, self->acc, 20);
    if (clock_801264fc(&self->handle) != 0xffff) do {
        v = p - lookup();
        float m = v.lenSq();
        if (m > 0.0f) {
            float g = 1.0f / sqrt_802e82c0(m);
            v.x *= g; v.y *= g; v.z *= g;
            if (d.lenSq() > 0.0f) {
                if (acos_802e79e0(clamp(d.dot(v), -1.0f, 1.0f)) > 1.5707964f) {
                    if (!(self->state == 21 && v.y < 0.0f)) {
                        self->flags |= 0x80000000; n++; sum += v;
                    }
                }
            } else {
                self->flags |= 0x80000000; n++; sum += v;
            }
        }
    } while (clock_801264fc(&self->handle) != 0xffff);
    finish_80126524(&self->handle);
    trace_801412a4(&self->tracer, self->pos, self->vel, self->acc, self->rot, 20, 1);
    if (!(self->moving = steps_80141554(&self->tracer) <= 20)) {
        if ((int)self->flags < 0) goto average;
        {
            float t = 20.0f;
            const Vec &q = self->pos;
            Vec out = q + self->vel * t + self->acc * (t * 0.5f * t);
            apply_80153f80(self, q, out);
        }
        if ((self->state == 6 || self->state == 1) && self->vel.y < 0.0f) self->state = 7;
        self->vel += self->acc * 20.0f;
        goto done;
    }
    if ((int)self->flags < 0) {
        Vec nn = *normal_80141564(&self->tracer);
        float e = nn.lenSq();
        if (e > 0.0f) {
            float g = 1.0f / sqrt_802e82c0(e);
            float avg = sum.y / (float)n;
            nn.x *= g; nn.y *= g; nn.z *= g;
            if (nn.y > avg) {
                self->normal = nn;
            } else {
                Vec a = (sum + nn) / (float)(n + 1);
                a.unit();
                self->normal = a;
            }
        } else {
            Vec a = sum / (float)n;
            a.unit();
            self->normal = a;
        }
        land(self);
    } else {
        v = *normal_80141564(&self->tracer);
        v.unit();
        self->normal = v;
        apply_80153f80(self, self->pos, *point_8014155c(&self->tracer));
        land(self);
    }
    goto done;
average:
    {
        Vec a = sum / (float)n;
        a.unit();
        self->normal = a;
    }
done:
    slope_80149348(self);
}


