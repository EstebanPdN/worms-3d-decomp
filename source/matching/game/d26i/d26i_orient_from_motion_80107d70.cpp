// GWMP8P rev0 0x80107d70. Computes side and up vectors from the motion since
// the previous call and passes them to the target.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    Vec &operator/=(float s) { float f = 1.0f / s; x *= f; y *= f; z *= f; return *this; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r(a.x - b.x, a.y - b.y, a.z - b.z); return r; }
inline Vec operator+(const Vec &a, const Vec &b) { Vec r(a.x + b.x, a.y + b.y, a.z + b.z); return r; }
inline Vec operator*(const Vec &a, float s) { Vec r(a.x * s, a.y * s, a.z * s); return r; }
inline void *operator new(unsigned int, void *place) { return place; }
struct Thing { char u0[180]; int flags; char u184[32]; int mode; char u220[40]; void *target; char u264[40]; int dirty; char u308[76]; int state; };
extern "C" int w3d_s20_set_vectors_8018993c(void *, const Vec &, const Vec &);
extern int have_last_804af1f0;
extern Vec last_8044beb4[];
inline void cross(const Vec &a, Vec &o, const Vec &v) {
    o.x = a.y * v.z - a.z * v.y;
    o.y = a.z * v.x - a.x * v.z;
    o.z = a.x * v.y - a.y * v.x;
}
extern "C" void d26i_orient_from_motion_80107d70(Thing *self, const Vec &pos, const Vec &v, const Vec &scale) {
    if (!have_last_804af1f0) {
        new (last_8044beb4) Vec(pos);
        have_last_804af1f0 = 1;
    }
    Vec up(0.0f, 1.0f, 0.0f);
    Vec side;
    Vec d = pos - last_8044beb4[0];
    cross(up, side, v);
    if (self->state == 6 || self->state == 9) {
        float s = scale.y;
        if (s != 0.0f) {
            up.x -= (d.x / s) + (d.x / s);
            up.y -= (d.y / s) + (d.y / s);
            up.z -= (d.z / s) + (d.z / s);
        }
        if (self->flags & 256 && self->mode == 0) {
            self->mode = 1;
            self->dirty |= 1;
        }
    } else {
        if (self->flags & 256 && self->mode == 1) {
            self->mode = 0;
            self->dirty |= 3;
        }
    }
    w3d_s20_set_vectors_8018993c(self->target, side, up);
    last_8044beb4[0] = pos;
}
