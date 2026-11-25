#include "w3d_ptr.h"
#line 1 "d41h_chase_camera_orbit_800a9b60.cpp"
// GWMP8P rev0 0x800a9b60. Chase camera placement: builds a rotation from yaw
// and pitch, offsets the camera from its centre by the target range along
// the rotated view axis, and rotates the fixed axis into the camera
// direction. Partial Cam view; names inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
struct Row { float x, y, z; };
struct Mat {
    Row rows[3];
    const Row &R(int i) const { return rows[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Target;
extern "C" void euler_matrix_801a3eb0(Ptr32<const Vec>, int, Ptr32<Mat>);
extern "C" float target_range_80178df0(Ptr32<Target>);
extern Vec lbl_80439590[];
struct Cam { char u0[76]; float yaw, pitch; Vec pos; Vec centre; Vec dir; char u78[40]; Ptr32<Target> target; };
extern "C" void d41h_chase_camera_orbit_800a9b60(Ptr32<Cam> self) {
    Mat m;
    Vec a; Ptr32<Vec> pa = &a; a.x = self->yaw; a.y = self->pitch;
    float k = 0.0f;
    pa->z = k;
    euler_matrix_801a3eb0(&a, 0, &m);
    float d = -target_range_80178df0(self->target);
    Vec v; Ptr32<Vec> pv = &v; v.x = k; pv->y = k; v.z = d;
    Vec o;
    m.rotate(o, v);
    self->pos = self->centre + o;
    m.rotate(self->dir, lbl_80439590[0]);
}


