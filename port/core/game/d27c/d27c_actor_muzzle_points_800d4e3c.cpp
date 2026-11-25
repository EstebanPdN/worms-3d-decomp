#include "w3d_ptr.h"
#line 1 "d27c_actor_muzzle_points_800d4e3c.cpp"
// d27c: 0x800d4e3c. Rotates two descriptor offsets by the actor's euler matrix and adds its position. Names are inferred; the sin/0/cos vector is written in the original but never read.
extern "C" float cos_802e86d4(float);
extern "C" float sin_802e88ac(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec3 operator+(const Vec3 &a, const Vec3 &b) { Vec3 r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct Row { float x, y, z; };
struct Mat {
    Row r[3];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec3 &o, const Vec3 &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Desc { char u0[20]; Vec3 a; Vec3 b; };
struct Actor { char u0[136]; Ptr32<void> h136; Vec3 pos; Vec3 rot; };
extern "C" Ptr32<void> empty_80341584(Ptr32<void>);
extern "C" Ptr32<Desc> desc_801797b4(Ptr32<void>);
extern "C" void euler_801a3eb0(Ptr32<float>, int, Ptr32<Mat>);
extern "C" void d27c_actor_muzzle_points_800d4e3c(Ptr32<Actor> self, Ptr32<Vec3> o1, Ptr32<Vec3> o2) {
    Ptr32<Desc> d = desc_801797b4(empty_80341584(self->h136));
    Vec3 fwd;
    fwd.x = sin_802e88ac(self->rot.y);
    fwd.y = 0.0f;
    fwd.z = cos_802e86d4(self->rot.y);
    Mat m;
    euler_801a3eb0(&self->rot.x, 0, &m);
    Vec3 rb, ra;
    Vec3 b(d->b), a(d->a);
    m.rotate(rb, b);
    m.rotate(ra, a);
    *o1 = self->pos + rb;
    *o2 = self->pos + ra;
}


