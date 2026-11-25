// d40i: 0x801182ec. Solves the launch for a ballistic shot of the given
// speed: discriminant, both flight times from the quadratic formula, rotates
// the two launch vectors by the frame.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
struct Axis { float x, y, z; };
struct Frame {
    Axis axis[3];
    const Axis &A(int i) const { return axis[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * A(0).x + v.y * A(1).x + v.z * A(2).x;
        o.y = v.x * A(0).y + v.y * A(1).y + v.z * A(2).y;
        o.z = v.x * A(0).z + v.y * A(1).z + v.z * A(2).z;
    }
};
struct Ball {
    char u0[92]; Frame frame; char u128[4]; float gravity; char u136[4];
    float dx, dy, dz; Vec launch; float height; float divisor; float disc; float t0, t1;
};
extern const Vec zero_8045e788[];
extern "C" int w3d_prepare_8011855c(Ball *);
extern "C" void w3d_copy12_800d7788(Ball *, const Vec &);
extern "C" int d40i_ballistic_solve_801182ec(Ball *self, float speed) {
    w3d_prepare_8011855c(self);
    w3d_copy12_800d7788(self, zero_8045e788[0]);
    Vec &launch = self->launch;
    launch.x = 0.0f; launch.y = 0.0f; launch.z = 0.0f;
    float disc = self->disc;
    if (disc == 0.0f) {
        launch.x = speed;
        launch.y = 0.0f; launch.z = 0.0f;
        w3d_copy12_800d7788(self, launch);
        return 1;
    }
    float e = speed * speed + self->height;
    disc = e * e - disc;
    if (disc < 0.0f) return 0;
    disc = sqrt_802e82c0(disc);
    float a = (e + disc) * 2.0f / self->divisor;
    float b = (e - disc) * 2.0f / self->divisor;
    if (a < 0.0f) a = b;
    else if (b < 0.0f) b = a;
    self->t0 = sqrt_802e82c0(a);
    self->t1 = sqrt_802e82c0(b);
    Vec va(self->dx / self->t0, self->dy / self->t0 - self->gravity * self->t0 * 0.5f, self->dz / self->t0);
    Vec vb(self->dx / self->t1, self->dy / self->t1 - self->gravity * self->t1 * 0.5f, self->dz / self->t1);
    Vec out;
    self->frame.rotate(out, va);
    w3d_copy12_800d7788(self, out);
    self->frame.rotate(self->launch, vb);
    return 1;
}
