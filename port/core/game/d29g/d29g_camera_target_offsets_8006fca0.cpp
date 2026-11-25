#include "w3d_ptr.h"
#line 1 "d29g_camera_target_offsets_8006fca0.cpp"
/* Worms 3D GameCube PAL 0x8006fca0. Camera target offsets: reads the target object's position and orientation at the current time, writes its up direction, and writes the points ahead (+92) and behind (+96) along its local z axis, each rotated by the orientation and added to the position. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct Row { float x, y, z; };
struct Mat {
    Row r[3];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
    void apply(Vec &o, const Vec &v, const Vec &p) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x + p.x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y + p.y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z + p.z;
    }
};
struct Ctx { char u[52]; int now; };
struct Target;
struct TargetVt { char u[44]; Ptr32<void (Ptr32<Target>, int, Ptr32<Vec>)> position; char u48[56 - 48]; Ptr32<Ptr32<const Mat> (Ptr32<Target>, int)> orientation; };
struct Target { Ptr32<TargetVt> vt; };
struct Camera { char u0[76]; int target; char u80[92 - 80]; float ahead; float behind; };
extern "C" {
Ptr32<Ctx> w3d_engine_get_context();
Ptr32<Target> w3d_s20_lookup_handle_object_80164fc8(int);
}
extern "C" void w3d_d29g_camera_target_offsets_8006fca0(Ptr32<Camera> self, Ptr32<Vec> back, Ptr32<Vec> front, Ptr32<Vec> up)
{
    int now = w3d_engine_get_context()->now;
    Ptr32<Target> t = w3d_s20_lookup_handle_object_80164fc8(self->target);
    Vec pos;
    t->vt->position(t, now, &pos);
    Mat m = *t->vt->orientation(t, now);
    Vec u(0.0f, 1.0f, 0.0f);
    m.rotate(*up, u);
    Vec z(0.0f, 0.0f, 1.0f);
    Vec a = z * self->ahead;
    Vec b = z * -self->behind;
    m.apply(*front, a, pos);
    m.apply(*back, b, pos);
}


