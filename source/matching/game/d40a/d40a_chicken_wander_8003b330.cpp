// GWMP8P rev0 0x8003b330. Random walk step of a chicken: with some chance
// stops, otherwise turns the heading by a random amount, makes a horizontal
// step vector, and traces downward from the stepped position. No ground:
// traces along the step and reflects the step off the wall. Ground within
// range: reflects off steep surfaces or stops if moving into them, and moves
// to the hit point on shallow ones. Out of range: stops. In state 2 the
// scaled step becomes the velocity. Names are inferred.
extern "C" float sqrt_802e82c0(float);
extern "C" float cosf_802e86d4(float);
extern "C" float sinf_802e88ac(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void Set(float a, float b, float c) { x = a; y = b; z = c; }
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    float dot(const Vec &o) const { return x * o.x + y * o.y + z * o.z; }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
    Vec operator*(float f) const { Vec r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
    Vec &operator-=(const Vec &o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
};
struct Chicken {
    char unknown00[28];
    Vec pos;
    float heading_pad;
    float heading;
    char unknown30[4];
    Vec vel;
    char unknown40[16];
    int state;
};
extern "C" float random_801610a0(Chicken *);
extern "C" void w3d_trace_800b0824(Vec *, Vec *, Vec *, int, int);
extern "C" void compute_800bd920();
extern int g_hit_804b1764;
extern int traceReady_804b1784;
extern Vec g_point_8043ae20[];
extern Vec g_normal_8043ae38[];
extern "C" void w3d_d40a_chicken_wander_8003b330(Chicken *self)
{
    if (random_801610a0(self) < 0.2f) {
        self->state = 1;
        return;
    }
    self->heading += random_801610a0(self) * 0.015707964f;
    Vec from;
    Vec to;
    Vec box;
    Vec n;
    Vec dir;
    float c = cosf_802e86d4(self->heading) * 0.1f;
    dir.Set(c, 0.0f, sinf_802e88ac(self->heading) * 0.1f);
    float len = dir.len();
    from = self->pos + dir;
    from.y += len;
    float down = -len;
    to.Set(0.0f, (down + down) * 0.01f, 0.0f);
    box.Set(0.0f, 0.0f, 0.0f);
    w3d_trace_800b0824(&from, &to, &box, 100, 1);
    if (g_hit_804b1764 == 0) {
        from = self->pos;
        from.y += len;
        to = dir * 0.01f;
        w3d_trace_800b0824(&from, &to, &box, 100, 1);
        if (!traceReady_804b1784) compute_800bd920();
        n = g_normal_8043ae38[0];
        n.y = 0.0f;
        n.normalize();
        float d = n.dot(dir);
        dir -= n * (d + d);
    } else if (g_hit_804b1764 <= 100) {
        if (!traceReady_804b1784) compute_800bd920();
        n = g_normal_8043ae38[0];
        n.normalize();
        if (n.y < 0.7072f) {
            if (n.dot(dir) > 0.0f) {
                self->state = 1;
                return;
            }
            n.y = 0.0f;
            n.normalize();
            float d = n.dot(dir);
            dir -= n * (d + d);
        } else {
            self->pos = g_point_8043ae20[0];
        }
    } else {
        self->state = 1;
    }
    if (self->state == 2) self->vel = dir * 0.1f;
}
