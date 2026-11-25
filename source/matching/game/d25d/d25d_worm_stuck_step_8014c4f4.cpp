// GWMP8P rev0 0x8014c4f4. Worm collision step with stuck timeout: when the
// worm moved more than 3 units (squared distance 9) remember the position
// and tick; after 500 ticks without movement zero the velocity, reset the
// normal to up and leave the state (9 becomes 25 or 10, others 0). Otherwise
// resolve the collision through 0x8014157c, store the normal, constrain a
// non-zero velocity and add 0.02 of the normal to it. Names are inferred.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    Vec &operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; return *this; }
};
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
inline float distSq(const Vec &a, const Vec &b) {
    float dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}
struct Context { unsigned char u[52]; unsigned tick; };
struct Worm {
    unsigned char u0[560]; Vec pos; Vec u572;
    unsigned char u584[76]; int moving;
    unsigned char u664[12]; Vec vel; Vec u688;
    unsigned char u700[60]; int state;
    unsigned char u764[64]; Vec last; unsigned lastTick;
    unsigned char u844[308]; char coll[52]; Vec normal;
};
extern "C" Context *context_80165254();
extern "C" Vec resolve_8014157c(void *, Vec *, Vec *, Vec *, Vec *, int);
extern "C" void constrain_8014b40c(Worm *);
extern const Vec zero_8045e788[];
extern "C" void d25d_worm_stuck_step_8014c4f4(Worm *self) {
    if (distSq(self->pos, self->last) > 9.0f) {
        self->last = self->pos;
        self->lastTick = context_80165254()->tick;
    } else if (context_80165254()->tick > self->lastTick + 500) {
        self->vel = zero_8045e788[0];
        self->normal.set(0.0f, 1.0f, 0.0f);
        if (self->state == 9) {
            if (self->moving) self->state = 25;
            else self->state = 10;
        } else self->state = 0;
        return;
    }
    Vec f = resolve_8014157c(self->coll, &self->pos, &self->vel, &self->u688, &self->u572, 20);
    self->normal = f;
    if (self->vel.lenSq() != 0.0f) constrain_8014b40c(self);
    self->vel += f * 0.02f;
}
