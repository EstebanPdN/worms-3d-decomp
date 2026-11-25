// GWMP8P rev0 0x8011855c. Rebuilds a ballistic solver's frame and local
// target when its dirty flags are set.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void cross(Vec &o, const Vec &v) const {
        o.x = y * v.z - z * v.y;
        o.y = z * v.x - x * v.z;
        o.z = x * v.y - y * v.x;
    }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
struct Axis { float x, y, z; };
struct Frame {
    Axis axis[3];
    void set(const Vec &a, const Vec &b, const Vec &c) {
        float *p = &axis[0].x;
        p[0] = a.x; p[1] = a.y; p[2] = a.z;
        p[3] = b.x; p[4] = b.y; p[5] = b.z;
        p[6] = c.x; p[7] = c.y; p[8] = c.z;
    }
    const Axis &A(int i) const { return axis[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z;
    }
};
struct Ball {
    Vec pos; Vec v12; Vec accel; char u36[4]; unsigned char flags; char u41[3]; Vec target;
    Frame frame; Frame inverse; Vec local_accel; Vec local_target; Vec launch;
    float along; float gravity_sq; float reach;
};
extern "C" void w3d_invert_801f60dc(Frame *, Frame *);
extern "C" void d26i_ballistic_prepare_8011855c(Ball *self) {
    if (self->flags & 4) {
        Vec u;
        Vec n(self->accel);
        float f = 1.0f / n.len();
        n.x = -(n.x * f); n.y = -(n.y * f); n.z = -(n.z * f);
        if (n.x != 0.0f) u.set(n.y, -n.x, 0.0f);
        else if (n.y != 0.0f) u.set(-n.y, 0.0f, 0.0f);
        else u.set(0.0f, -n.z, 0.0f);
        u.normalize();
        Vec w;
        u.cross(w, n);
        self->inverse.set(u, n, w);
        w3d_invert_801f60dc(&self->frame, &self->inverse);
        self->frame.rotate(self->local_accel, self->accel);
        self->gravity_sq = self->local_accel.y * self->local_accel.y;
    }
    if (self->flags & 13) {
        Vec d = self->target - self->pos;
        self->frame.rotate(self->local_target, d);
        self->along = self->local_accel.y * self->local_target.y;
        self->reach = self->local_target.lenSq() * self->gravity_sq;
    }
    self->flags = 0;
}
