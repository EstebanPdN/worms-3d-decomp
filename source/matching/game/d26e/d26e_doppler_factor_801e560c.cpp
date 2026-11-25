// (Worms 3D GameCube PAL, 0x801e560c).
//
// Doppler factor of a 3D sound: listener velocity and position (listener
// virtual slot 17, kinds 4 and 3), emitter position and velocity, direction
// normalized, speeds along it scaled by emitter slot 11, emitter slot 13
// scales (1 - v_e) / (1 + v_l), minus 1, clamped to [-1, 1]. Reading of the
// physics is inferred from the arithmetic; virtual slot names are unknown.

extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r(a.x - b.x, a.y - b.y, a.z - b.z); return r; }
inline const float &fmin(const float &a, const float &b) { return b < a ? b : a; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
struct Listener3D { void **vt; };
struct Emitter {
    void **vt;
};
struct Player { char u[12]; Listener3D *listener; float Doppler(Emitter *e); };
typedef int (*GetFn)(Listener3D *, int, Vec *);
typedef float (*FloatFn)(Emitter *);
typedef void (*VecFn)(Emitter *, Vec *);
extern "C" float w3d_d26e_doppler_factor_801e560c(Player *self, Emitter *e) {
    Vec vel, pos, epos;
    ((GetFn)self->listener->vt[17])(self->listener, 4, &vel);
    ((GetFn)self->listener->vt[17])(self->listener, 3, &pos);
    ((VecFn)e->vt[14])(e, &epos);
    Vec n = epos - pos;
    n.normalize();
    float vl = vel.dot(n);
    Vec ev;
    ((VecFn)e->vt[16])(e, &ev);
    float sl = ev.dot(n);
    sl *= ((FloatFn)e->vt[11])(e);
    vl *= ((FloatFn)e->vt[11])(e);
    float r = ((FloatFn)e->vt[13])(e) * (1.0f - sl) / (1.0f + vl) - 1.0f;
    r = fmin(r, 1.0f);
    r = fmax(r, -1.0f);
    return r;
}
