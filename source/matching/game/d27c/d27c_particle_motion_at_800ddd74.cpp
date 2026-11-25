// d27c: 0x800ddd74. Evaluates a particle's position at time t from start, velocity and acceleration, with optional wind (0x800e5a70), linear drag and a spiral whose radius shrinks over time. Names are inferred.
extern "C" float sin_802e88ac(float);
extern "C" float cos_802e86d4(float);
struct W { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec3 &operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec3 operator*(const Vec3 &a, float s) { Vec3 r; r.x = a.x * s; r.y = a.y * s; r.z = a.z * s; return r; }
struct Motion { W pos; Vec3 vel; Vec3 acc; char u36[48]; float radius; float spin; };
struct Desc { char u0[280]; float drag0; char u284[40]; float drag1; char u328[24]; float shrink; char u356[20]; float gravity; char u380[56]; int spiral; int orbit; int damped; };
extern "C" void orbit_800e5a70(Vec3 *);
extern "C" void d27c_particle_motion_at_800ddd74(Motion *self, float t, Vec3 *out, Desc *d, Vec3 *out2) {
    Vec3 a(self->acc);
    *(W *)out = self->pos;
    if (d->orbit) {
        Vec3 o;
        orbit_800e5a70(&o);
        a += o * 0.2f;
    }
    if (d->damped) {
        float drag = d->drag0;
        float k = drag - 1.0f / (t * d->drag1 + 1.0f / drag);
        out->x += self->vel.x * k;
        out->y += self->vel.y * k;
        out->y += self->vel.y * t;
        out->z += self->vel.z * k;
    } else {
        float h = t * t * 0.5f;
        out->x += self->vel.x * t + h * (a.x * d->gravity);
        out->y += self->vel.y * t + h * (a.y * d->gravity);
        out->z += self->vel.z * t + h * (a.z * d->gravity);
    }
    if (out2) *(W *)out2 = *(W *)out;
    if (d->spiral) {
        float r = self->radius - d->shrink * t * 0.01f;
        if (r > 0.0f) {
            float ang = self->spin * t;
            out->x += r * sin_802e88ac(ang);
            out->z += r * cos_802e86d4(ang);
        }
    }
}
