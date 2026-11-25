// d27c: 0x800dbda8. Computes a steering value from the angle between an actor's horizontal velocity and its facing, weighted by speed and limited to a quarter turn. Names are inferred. Mat4 widens the transform to four rows and is written before use, as in the original.
extern "C" float sqrt_802e82c0(float);
extern "C" float acos_802e79e0(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    float dot(const Vec3 &o) const { return x * o.x + y * o.y + z * o.z; }
};
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform { Axis a[3]; Pos p; const Pos &P() const { return p; } };
struct Row { float x, y, z, w; };
struct Mat4 {
    Row r[4];
    Mat4(const Transform &t) {
        r[0].x = t.a[0].x; r[0].y = t.a[0].y; r[0].z = t.a[0].z; r[0].w = 0.0f;
        r[1].x = t.a[1].x; r[1].y = t.a[1].y; r[1].z = t.a[1].z; r[1].w = 0.0f;
        r[2].x = t.a[2].x; r[2].y = t.a[2].y; r[2].z = t.a[2].z; r[2].w = 0.0f;
        const Pos &p = t.P(); r[3].x = p.x; r[3].y = p.y; r[3].z = p.z; r[3].w = 1.0f;
    }
    const Row &R(int i) const { return r[i]; }
};
struct Self { char u0[88]; float yaw; char u92[16]; float vx; float vy; float vz; };
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" float d27c_actor_steer_angle_800dbda8(Self *self) {
    Vec3 h(self->vx, 0.0f, self->vz);
    float s = h.len();
    if (s == 0.0f) return 0.0f;
    Vec3 z(0.0f, 0.0f, 1.0f);
    Transform t;
    construct_801f7538(&t, 0.0f, 1.0f, 0.0f, self->yaw);
    Vec3 d;
    Mat4 m(t);
    d.x = z.x * m.R(0).x + z.y * m.R(1).x + z.z * m.R(2).x;
    d.y = z.x * m.R(0).y + z.y * m.R(1).y + z.z * m.R(2).y;
    d.z = z.x * m.R(0).z + z.y * m.R(1).z + z.z * m.R(2).z;
    d.normalize();
    h.normalize();
    float c = h.dot(d);
    c = fmin(c, 1.0f);
    c = fmax(c, 0.0f);
    float a = acos_802e79e0(c) / 3.1415927f;
    float e = a + a - 1.0f;
    s *= 3.0f;
    s = fmin(s, 0.7853982f);
    s = fmax(s, -0.7853982f);
    return -s * e;
}
