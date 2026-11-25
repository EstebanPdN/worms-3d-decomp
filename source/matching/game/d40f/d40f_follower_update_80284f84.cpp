// GWMP8P rev0 0x80284f84. Rope-like follower update: keeps the target at the
// fixed distance from the position and orients the part.
extern "C" float fn_802e82c0(float);
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec3 operator-(const Vec3 &o) const { Vec3 r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    Vec3(float a, float b, float c) { Vec3 *q = this; x = a; q->y = b; q->z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    void Scale(float s) { x *= s; y *= s; z *= s; }
    void Diff(const Vec3 &a, const Vec3 &b) { float p = a.x - b.x, q = a.y - b.y, r = a.z - b.z; x = p; y = q; z = r; }
    float Length() const { return fn_802e82c0(x * x + y * y + z * z); }
};
struct Part { void **table; };
struct Follower {
    char pad0[28];
    Part *part;
    Vec3 position;
    Vec3 target;
    float distance;
};
extern "C" float fn_802e79e0(float);
inline void SetRot(Part *part, const Vec3 &v) { ((void (*)(Part *, const Vec3 *, int))part->table[20])(part, &v, 0); }
inline void SetPos(Part *part, const Vec3 &v) { ((void (*)(Part *, const Vec3 *, int))part->table[19])(part, &v, 0); }
extern "C" int w3d_d40f_follower_update_80284f84(Follower *self) {
    Vec3 d(self->position - self->target);
    float length = d.Length();
    if (length == 0.0f) {
        d.Set(0.0f, self->distance, 0.0f);
    } else {
        d.Scale(self->distance / length);
    }
    self->target = self->position - d;
    float angle = fn_802e79e0(d.x / self->distance);
    if (d.y > 0.0f)
        angle = -angle;
    Vec3 rot(0.0f, 0.0f, angle + 3.1415927f);
    Vec3 next;
    next.Diff(self->position, d);
    SetRot(self->part, rot);
    SetPos(self->part, next);
    return 0;
}
