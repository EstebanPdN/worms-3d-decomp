// d25c: 0x800ed440. Point the rotation at +124 along a direction read through virtual +52: the axis is
// up x direction and the angle the arc cosine of their dot product. Names are inferred.
extern "C" float sqrtf_802e82c0(float);
extern "C" float acosf_802e79e0(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    void normalize() { float n = 1.0f / sqrtf_802e82c0(x * x + y * y + z * z); x *= n; y *= n; z *= n; }
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Quat;
extern "C" void set_axis_angle_801f656c(Quat *, const Vec3 *, float);
struct Self {
    struct V { void *u[13]; void (*direction)(Self *, int, Vec3 *); } *vtable;
    char u4[120];
    char rotation[1];
};
inline float dot(const Vec3 &a, const Vec3 &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline Vec3 cross(const Vec3 &a, const Vec3 &b) { return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x); }
extern "C" Quat *d25c_actor_align_rotation_800ed440(Self *self, int a) {
    Quat *q = (Quat *)self->rotation;
    Vec3 d;
    self->vtable->direction(self, a, &d);
    d.normalize();
    Vec3 up(0.0f, 0.0f, 1.0f);
    Vec3 axis = cross(up, d);
    float angle = acosf_802e79e0(dot(up, d));
    set_axis_angle_801f656c(q, &axis, angle);
    return q;
}
