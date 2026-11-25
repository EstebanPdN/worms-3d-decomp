// GWMP8P rev0 0x80017684. Drops a trace from above the plan's position to
// find the ground, stores the hit plus one unit, and when the probe rejects
// the spot and the plan was not re-pushed, clones it through table slot 36
// and pushes the clone. Names are inferred from the original instructions.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float s) const { Vec r; r.x = x * s; r.y = y * s; r.z = z * s; return r; }
    Vec operator/(float d) const { float f = 1.0f / d; Vec r; r.x = x * f; r.y = y * f; r.z = z * f; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct Plan {
    char unknown00[12];
    void **vtable;     /* +12 */
    char unknown10[4];
    Vec position;      /* +20 */
    char unknown20[8];
    int pushed;        /* +40 */
};
struct VecWords { int a, b, c; };
extern VecWords g_hit_8043ae20[];
extern int g_hit_time_804b1764;
extern "C" void w3d_trace_800b0824(const Vec *, const Vec *, const Vec *, int, int);
extern "C" int s19_probe_8001744c(Plan *);
extern "C" void w3d_ai_push_plan_a(Plan *);
inline Vec Twice(const Vec &v) { return v + v; }
extern "C" int w3d_d28a_plan_settle_trace_80017684(Plan *self)
{
    Vec p = self->position;
    p.y += 15.0f;
    Vec u = Twice(Vec(0.0f, -1.0f, 0.0f) * 15.0f) / 1000.0f;
    w3d_trace_800b0824(&p, &u, &Vec(0.0f, 0.0f, 0.0f), 1000, 1);
    if (g_hit_time_804b1764 == 0) return 0;
    *(VecWords *)&self->position = g_hit_8043ae20[0];
    self->position.y += 1.0f;
    int r = s19_probe_8001744c(self);
    if (!r && !self->pushed) {
        Plan *copy = ((Plan *(*)(Plan *))self->vtable[9])(self);
        copy->pushed = 1;
        w3d_ai_push_plan_a(copy);
    }
    return r;
}
