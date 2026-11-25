// GWMP8P rev0 0x800a8d00. Free camera input step. Names are inferred. Turns
// yaw and pitch from digital flags or, when the analog flag 0x00200000 is
// clear, from analog values, clamps pitch between 0 and pi/2, builds the
// forward vector from the yaw and the side vector as its cross product with
// the global up at 0x80439590, moves the position by the digital flags
// scaled by speed and dt or by the analog values when the flag is set, keeps
// it within 6000 of the centre vector read from the object at +180, then
// calls 0x800a9b60 and 0x800a93fc. Class layouts are partial views.
extern "C" float sqrt_802e82c0(float);
extern "C" float sinf_802e88ac(float);
extern "C" float cosf_802e86d4(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
    void operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r; r.x = a.x + b.x; r.y = a.y + b.y; r.z = a.z + b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline void Cross(Vec &o, const Vec &a, const Vec &b) {
    o.x = a.y * b.z - a.z * b.y;
    o.y = a.z * b.x - a.x * b.z;
    o.z = a.x * b.y - a.y * b.x;
}
inline const float &Min(const float &a, const float &b) { return a < b ? a : b; }
inline const float &Clamp(const float &v, const float &lo, const float &hi) { const float &m = Min(v, hi); return m < lo ? lo : m; }
inline float Dist(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return sqrt_802e82c0(dx * dx + dy * dy + dz * dz);
}
extern "C" float value_80178df0(void *);
extern "C" const Vec *vector_80178ec4(void *);
extern Vec lbl_80439590[];
struct Input { unsigned flags; int unknown4; int strafe; int forward; };
struct Fly {
    char unknown0[76]; float pitch; float yaw; char unknown84[12]; Vec pos; char unknown108[24];
    void *moveSpeed; void *strafeRate; void *forwardRate; int unknown144[3]; void *turnSpeed; int unknown160; void *lookSpeed; int unknown168; void *aimY; void *aimX; void *center;
};
extern "C" void limit_800a9b60(Fly *);
extern "C" void blend_800a93fc(Fly *);
extern "C" void d31h_free_camera_input_800a8d00(Fly *self, Input *in, float dt) {
    Vec dir, side;
    if (in->flags & 0x08000000) self->yaw -= value_80178df0(self->turnSpeed) * dt;
    else if (in->flags & 0x04000000) self->yaw += value_80178df0(self->turnSpeed) * dt;
    if (!(in->flags & 0x00200000)) self->yaw -= (float)in->strafe * value_80178df0(self->aimX);
    if (in->flags & 0x01000000) self->pitch += value_80178df0(self->lookSpeed) * dt;
    else if (in->flags & 0x02000000) self->pitch -= value_80178df0(self->lookSpeed) * dt;
    if (!(in->flags & 0x00200000)) self->pitch -= (float)in->forward * value_80178df0(self->aimY);
    self->pitch = Clamp(self->pitch, 0.0f, 1.5707964f);
    float s = sinf_802e88ac(self->yaw);
    float c = cosf_802e86d4(self->yaw);
    unsigned flags = in->flags;
    dir = Vec(s, 0.0f, c);
    Cross(side, dir, lbl_80439590[0]);
    if (flags & 0x10000000) self->pos += dir * value_80178df0(self->moveSpeed) * dt;
    else if (flags & 0x20000000) self->pos -= dir * value_80178df0(self->moveSpeed) * dt;
    if (in->flags & 0x00200000) self->pos -= dir * ((float)in->forward * value_80178df0(self->forwardRate));
    if (in->flags & 0x80000000) self->pos -= side * value_80178df0(self->moveSpeed) * dt;
    else if (in->flags & 0x40000000) self->pos += side * value_80178df0(self->moveSpeed) * dt;
    if (in->flags & 0x00200000) self->pos += side * ((float)in->strafe * value_80178df0(self->strafeRate));
    const float maxd = 6000.0f;
    Vec center = *vector_80178ec4(self->center);
    if (Dist(self->pos, center) > maxd) {
        Vec d = self->pos - center;
        if (d.lenSq() > 0.0f) {
            float i = 1.0f / sqrt_802e82c0(d.lenSq());
            d.x *= i; d.y *= i; d.z *= i;
        }
        self->pos = center + d * maxd;
    }
    limit_800a9b60(self);
    blend_800a93fc(self);
}
