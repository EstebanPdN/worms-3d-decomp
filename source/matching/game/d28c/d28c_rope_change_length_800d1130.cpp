// d28c: 0x800d1130. Rope length change: extends or retracts the last segment toward a point within limits, then probes the new end and rescales. Names are inferred; classes are partial views.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    void normalize();
};
extern "C" float sqrt_802e82c0(float);
inline void Vec3::normalize() { float f = 1.0f / sqrt_802e82c0(lenSq()); x *= f; y *= f; z *= f; }
inline Vec3 operator-(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct W { int a, b, c; };
struct Seg { Vec3 p; float len; char u16[12]; };
struct SegList { Seg *first, *last; int size() const { return last - first; } Seg &operator[](int i) { return first[i]; } };
struct Rope { char u0[28]; SegList segs; char u36[52]; int extend, retract; char u96[112]; void *h208, *h212, *h216; char u220[8]; void *h228; };
extern "C" float value_80178df0(void *);
extern "C" float sum_800cfe18(Rope *);
extern "C" int probe_800d066c(Rope *, Vec3 *);
extern "C" int drain_800d0058(Rope *, Vec3 *);
extern "C" void rescale_800d1628(Rope *, float, float);
extern "C" void d28c_rope_change_length_800d1130(Rope *self, Vec3 *at) {
    if (self->extend != 0 || self->retract != 0) {
        int last = self->segs.size() - 1;
        float rate = value_80178df0(self->h228) * 20.0f;
        float len = self->segs[last].len;
        float old = len;
        Vec3 d = *at - self->segs[last].p;
        d.normalize();
        float sum = sum_800cfe18(self);
        if (self->extend != 0) {
            if (sum + rate > value_80178df0(self->h208)) rate = value_80178df0(self->h208) - sum;
            len += rate;
        } else if (self->retract != 0) {
            if (len < rate) return;
            if (sum - rate < value_80178df0(self->h212)) return;
            float next = len - rate;
            if (next < value_80178df0(self->h216)) return;
            len = next;
        }
        Vec3 np = self->segs[last].p + d * len;
        int blocked = 0;
        if (probe_800d066c(self, &np) || drain_800d0058(self, &np)) blocked = 1;
        if (blocked == 0) {
            self->segs[last].len = len;
            *(W *)at = *(W *)&np;
            rescale_800d1628(self, old, len);
        }
    }
}
