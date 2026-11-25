// GWMP8P rev0 0x8015a6f0. Build a camera's orthonormal basis: forward from
// at to eye, up as the stored up vector with its forward part removed,
// falling back to world Y and then world Z when that is too short, and right
// as the cross product of up and forward. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void unit() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec &operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
struct Camera { char u0[4]; Vec eye; Vec at; Vec up; };
extern "C" void d26d_camera_basis_8015a6f0(Camera *self, Vec &right, Vec &up, Vec &forward) {
    forward = self->eye - self->at;
    forward.unit();
    up = self->up - forward * self->up.dot(forward);
    if (up.len() < 1e-06f) {
        up.y = 1.0f; up.x = 0.0f; up.z = 0.0f;
        up -= forward * forward.y;
        if (up.len() < 1e-06f) {
            up.x = 0.0f; up.y = 0.0f; up.z = 1.0f;
            up -= forward * forward.z;
        }
    }
    up.unit();
    right.x = up.y * forward.z - up.z * forward.y;
    right.y = up.z * forward.x - up.x * forward.z;
    right.z = up.x * forward.y - up.y * forward.x;
}
