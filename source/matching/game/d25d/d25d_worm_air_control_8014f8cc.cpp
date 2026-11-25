// GWMP8P rev0 0x8014f8cc. Worm air control: clear the aim vector (+724);
// when enabled, rising or falling slowly, airborne and alive, add the wished
// direction 0x8014b8ec to the horizontal velocity, scaled by 0x80178df0. A
// non-zero wish is rotated by the matrix built from the negated yaw,
// normalized and stored as the aim. Names are inferred.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
struct Pos { float x, y, z; Pos(); };
struct Axis { float x, y, z; };
struct Transform { Axis axis[3]; Pos position; };
struct Row { float x, y, z, w; };
struct Matrix {
    Row row[4];
    const Row &R(int i) const { return row[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
    Matrix(const Axis *axis, const Pos &p) {
        row[0].x = axis[0].x; row[0].y = axis[0].y; row[0].z = axis[0].z; row[0].w = 0.0f;
        row[1].x = axis[1].x; row[1].y = axis[1].y; row[1].z = axis[1].z; row[1].w = 0.0f;
        row[2].x = axis[2].x; row[2].y = axis[2].y; row[2].z = axis[2].z; row[2].w = 0.0f;
        row[3].x = p.x; row[3].y = p.y; row[3].z = p.z; row[3].w = 1.0f;
    }
};
struct Worm {
    unsigned char u0[576]; float yaw;
    unsigned char u580[96]; Vec vel;
    unsigned char u688[28]; int grounded; int moved; Vec aim;
    unsigned char u736[64]; int enabled;
    unsigned char u804[20]; int health;
    unsigned char u828[396]; void *res;
};
extern "C" void construct_801f7538(Transform *, float, float, float, float);
extern "C" Vec wish_8014b8ec(Worm *);
extern "C" float scale_80178df0(void *);
extern const Vec zero_8045e788[];
extern "C" void d25d_worm_air_control_8014f8cc(Worm *self) {
    self->aim = zero_8045e788[0];
    if (self->enabled && self->vel.y > -0.25f && !self->grounded && self->health >= 0) {
        Vec d = wish_8014b8ec(self);
        self->vel.x += d.x * scale_80178df0(self->res);
        self->vel.z += d.z * scale_80178df0(self->res);
        if (d.lenSq() > 0.0f) {
            self->moved = 1;
            Transform t;
            construct_801f7538(&t, 0.0f, 1.0f, 0.0f, -self->yaw);
            const Pos &pos = t.position;
            Vec c = d;
            Vec o;
            Matrix m(t.axis, pos);
            m.rotate(o, c);
            o.normalize();
            self->aim = o;
        }
    }
}
