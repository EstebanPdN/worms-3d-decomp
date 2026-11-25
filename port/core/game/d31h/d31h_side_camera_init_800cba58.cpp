#include "w3d_ptr.h"
#line 1 "d31h_side_camera_init_800cba58.cpp"
// GWMP8P rev0 0x800cba58. Side camera setup from another camera. Names are
// inferred. Calls the virtual base step 0x8015a6b8, copies the three view
// vectors from the other camera, moves the target to the tracked object at
// index st, and picks the eye: two candidates at (-100,40,-100) and
// (100,40,-100) turned by the tracked object's heading around the target,
// nearer one first, taking the first that passes the range test 0x800cc070;
// otherwise (0,40,-100), halving the offset while blocked and longer than
// 10. Sets the up vector and posts message 0x804ae838. Class layouts are
// partial views. The first candidate goes through the 4x4 form of the
// transform and the others through the transform itself, as in the original,
// where the position is read in the second form only.
extern "C" float sqrt_802e82c0(float);
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
    void operator/=(float k) { float i = 1.0f / k; x *= i; y *= i; z *= i; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct Transform {
    Axis axis[3]; Pos position;
    const Axis &R(int i) const { return axis[i]; }
    const Pos &P() const { return position; }
    void apply(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + P().x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + P().y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + P().z;
    }
};
struct Row { float x, y, z, w; };
struct Mat44 {
    Row row[4];
    Mat44(const Transform &t) {
        row[0].x = t.axis[0].x; row[0].y = t.axis[0].y; row[0].z = t.axis[0].z; row[0].w = 0.0f;
        row[1].x = t.axis[1].x; row[1].y = t.axis[1].y; row[1].z = t.axis[1].z; row[1].w = 0.0f;
        row[2].x = t.axis[2].x; row[2].y = t.axis[2].y; row[2].z = t.axis[2].z; row[2].w = 0.0f;
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
extern "C" unsigned read_80178c48(Ptr32<void>);
struct Tracked { char unknown00[72]; float heading; int unknown76; Vec pos; };
extern "C" Ptr32<Tracked> query_800fc6dc(unsigned);
struct Cam { int unknown0; Vec eye; Vec look; Vec c; char unknown40[16]; Ptr32<void> state; char unknown60[16]; Vec pos; char unknown88[12]; Vec target; };
extern "C" int in_range_800cc070(Ptr32<Cam>, Ptr32<const Vec>, Ptr32<const Vec>);
extern "C" int base_8015a6b8(Ptr32<Cam>, Ptr32<Cam>);
struct Msg { unsigned short id; Ptr32<const void> vtable; };
extern "C" Ptr32<Msg> alloc_801613f0(Ptr32<void>, int);
extern "C" int message_id_8015f5a0(Ptr32<int>, int);
extern "C" int post_8016239c(Ptr32<Msg>);
extern Ptr32<void> lbl_804b1754;
extern int lbl_804ae838;
extern const char lbl_8040db38[];
inline float DistSq(const Vec &a, const Vec &b) {
    float x = a.x - b.x; x *= x; float y = a.y - b.y; y *= y; float z = a.z - b.z; z *= z; return x + y + z;
}
extern "C" void d31h_side_camera_init_800cba58(Ptr32<Cam> self, Ptr32<Cam> other) {
    base_8015a6b8(self, other);
    self->eye = other->eye;
    self->look = other->look;
    self->c = other->c;
    unsigned st = read_80178c48(self->state);
    if (st > 16) return;
    self->target = query_800fc6dc(st)->pos;
    {
        Vec off(-100.0f, 40.0f, -100.0f);
        Vec o;
        Transform m;
        construct_801f7538(&m, 0.0f, 1.0f, 0.0f, query_800fc6dc(st)->heading);
        Mat44(m).rotate(o, off);
        Vec a = self->target + o;
        off.Set(100.0f, 40.0f, -100.0f);
        m.apply(o, off);
        Vec b = self->target + o;
        if (DistSq(a, self->eye) > DistSq(b, self->eye)) {
            Vec t = a;
            a = b;
            b = t;
        }
        if (!in_range_800cc070(self, &a, &self->target)) self->pos = a;
        else if (!in_range_800cc070(self, &b, &self->target)) self->pos = b;
        else {
            off.Set(0.0f, 40.0f, -100.0f);
            m.apply(o, off);
            a = self->target + o;
            while (in_range_800cc070(self, &a, &self->target) && sqrt_802e82c0(o.x * o.x + o.y * o.y + o.z * o.z) > 10.0f) {
                o /= 2.0f;
                a = self->target + o;
            }
            self->pos = a;
        }
    }
    self->c.Set(0.0f, 1.0f, 0.0f);
    Ptr32<Msg> m = alloc_801613f0(lbl_804b1754, 8);
    m->id = message_id_8015f5a0(&lbl_804ae838, 1);
    m->vtable = lbl_8040db38;
    post_8016239c(m);
}


