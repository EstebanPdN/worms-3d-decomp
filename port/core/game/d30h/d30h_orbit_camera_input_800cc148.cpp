#include "w3d_ptr.h"
#line 1 "d30h_orbit_camera_input_800cc148.cpp"
// GWMP8P rev0 0x800cc148. Orbit camera input step. Names are inferred. Turns
// the position at +76 around the target at +100 by the left and right flags
// plus the analog value at +8, raises it by the up and down flags plus the
// analog value at +12 clamped above the floor value of the object at +136
// and limits the distance to 400, then snaps it to the global view position
// 0x8043ae20 when the range test 0x800cc070 passes and that position is at
// least 300 from the target. Returns whether anything moved. Class layouts
// are partial views. Pos has an out of line constructor, witnessed by the
// call to 0x80343740. The pool starts at the double-aligned 0x80387d38; the
// zero before it at 0x80387d34 stays an external object.
extern "C" float sqrt_802e82c0(float);
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void operator*=(float f) { x *= f; y *= f; z *= f; }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct Transform { Axis axis[3]; Pos position; const Pos &P() const { return position; } };
extern const float lbl_80387d34[];
struct Row { float x, y, z, w; };
struct Mat44 {
    Row row[4];
    Mat44(const Transform &t) {
        row[0].x = t.axis[0].x; row[0].y = t.axis[0].y; row[0].z = t.axis[0].z; row[0].w = lbl_80387d34[0];
        row[1].x = t.axis[1].x; row[1].y = t.axis[1].y; row[1].z = t.axis[1].z; row[1].w = lbl_80387d34[0];
        row[2].x = t.axis[2].x; row[2].y = t.axis[2].y; row[2].z = t.axis[2].z; row[2].w = lbl_80387d34[0];
        row[3].x = t.P().x; row[3].y = t.P().y; row[3].z = t.P().z; row[3].w = 1.0f;
    }
    const Row &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
extern "C" void construct_801f7538(Ptr32<Transform>, float, float, float, float);
extern "C" float read_80178df0(Ptr32<void>);
struct Input { unsigned flags; int unknown4; int yaw; int pitch; };
struct Cam { char unknown00[76]; Vec pos; char unknown88[12]; Vec target; char unknown112[24]; Ptr32<void> floor; };
extern "C" int in_range_800cc070(Ptr32<Cam>, Ptr32<const Vec>, Ptr32<const Vec>);
extern Vec lbl_8043ae20[];
extern const float lbl_80387d34[];
inline float Dist(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
extern "C" int d30h_orbit_camera_input_800cc148(Ptr32<Cam> self, Ptr32<Input> in, float dt) {
    int changed = 0;
    unsigned flags = in->flags;
    float turn = lbl_80387d34[0];
    if (flags & 0x08000000) turn -= 1.5f;
    if (flags & 0x04000000) turn += 1.5f;
    turn += (float)in->yaw * 0.3f;
    float zero = lbl_80387d34[0];
    if (turn != zero) {
        changed = 1;
        Vec d = self->pos - self->target;
        Transform m;
        construct_801f7538(&m, zero, 1.0f, zero, turn * 1.5f * dt);
        Vec o;
        Mat44(m).rotate(o, d);
        o += self->target;
        self->pos = o;
    }
    float lift = zero;
    if (in->flags & 0x02000000) lift -= 100.0f;
    if (in->flags & 0x01000000) lift += 100.0f;
    lift += (float)in->pitch * 20.0f;
    if (lift != zero) {
        float h = self->pos.y + lift * dt;
        if (h < read_80178df0(self->floor)) h = read_80178df0(self->floor);
        self->pos.y = h;
        float dist = Dist(self->pos, self->target);
        float maxd = 400.0f;
        if (dist > maxd) {
            Vec d = self->pos - self->target;
            d *= 1.0f / d.len();
            d *= maxd;
            self->pos = self->target + d;
        }
        changed = 1;
    }
    if (in_range_800cc070(self, &self->pos, &self->target)) {
        Vec v = lbl_8043ae20[0];
        if (Dist(v, self->target) >= 300.0f) self->pos = v;
    }
    return changed;
}


