// d24c: 0x800d98a4 (316 bytes). Launch a ballistic object: solve direction and aim for
// the target at +36; on success compute the basis, store the aim in +36, reset +48 and
// +60 to the shared origin, store the basis in +72, set the pending velocity to the
// direction times the settings' speed (+220), run 0x800d8938 and return 1. Otherwise
// return 0. Names are inferred. The original writes the scaled vector to two stack
// slots (an inline's temporary and its copy); t is that temporary.
struct Words { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
inline Vec3 scaled(const Vec3 *v, float f) { Vec3 t(v->x * f, v->y * f, v->z * f); return t; }
struct Settings { unsigned char u[220]; float speed; };
struct Jump {
    unsigned char u0[36];
    Words target;       // +36
    Words w48, w60, w72;
    unsigned char u84[108];
    void *resource;     // +192
};
extern "C" void *identity_80341584(void *);
extern "C" Settings *settings_801797b4(void *);
extern "C" int solve_800d99e0(Jump *, Words *, Vec3 *, Words *);
extern "C" void basis_800d9b70(Jump *, Vec3 *, Words *);
extern "C" void set_pending_800ecec0(Jump *, Vec3 *);
extern "C" void fn_800d8938(Jump *);
extern const Words origin_8045e788[];
extern "C" int d24c_ballistic_launch_800d98a4(Jump *self) {
    Vec3 dir;
    Words aim, basis;
    Words *paim = &aim;
    Words *target = &self->target;
    Settings *s = settings_801797b4(identity_80341584(self->resource));
    int result;
    if (solve_800d99e0(self, target, &dir, paim)) {
        Words *pb = &basis;
        basis_800d9b70(self, &dir, pb);
        *target = *paim;
        Vec3 *pd = &dir;
        self->w48 = origin_8045e788[0];
        self->w72 = *pb;
        self->w60 = origin_8045e788[0];
        float f = s->speed;
        float vx = pd->x * f, vy = pd->y * f, vz = pd->z * f;
        Vec3 v, t;
        t.x = vx; t.y = vy; t.z = vz;
        v.x = vx; v.y = vy; v.z = vz;
        set_pending_800ecec0(self, &v);
        fn_800d8938(self);
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
