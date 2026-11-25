// d24c: 0x800df570 (276 bytes). Step a sweep: trace from the entity position with
// (a, b, a) and a zero vector, 60 ticks, mode 1. While the global tick count is at most
// 59: reset the position (+68) from the trace result 0x8043ae20 and add the settings'
// offset (+128), copy two globals to +120 and +124, and return whether the position's
// y is at least the limit setting (+208). Otherwise returns 0. Names are inferred.
struct Words { int a, b, c; };
struct Vec3 {
    float x, y, z;
    Vec3() {}
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Settings { unsigned char u[128]; Vec3 offset; };
struct Sweep {
    unsigned char u0[68];
    Vec3 pos;           // +68
    unsigned char u80[40];
    int w120, w124;     // +120
    void *resource;     // +128
    unsigned char u132[76];
    void *limit;        // +208
};
extern "C" void trace_800b0824(Vec3 *, Vec3 *, Vec3 *, int, int);
extern "C" void *identity_80341584(void *);
extern "C" Settings *settings_801797b4(void *);
extern "C" void *as_80342a74(void *);
extern "C" float value_80178df0(void *);
extern const float a_80389cb0[], b_80389cb4[];
extern const Words result_8043ae20[];
extern unsigned ticks_804b1764;
extern int w_804b17a8, w_804b17ac;
extern "C" int d24c_sweep_step_800df570(Sweep *self) {
    float a = a_80389cb0[0];
    Vec3 from, to;
    Vec3 *pf = &from, *pt = &to;
    from.x = a;
    pf->y = b_80389cb4[0];
    pf->z = a;
    to.x = a;
    pt->y = a;
    pt->z = a;
    Vec3 *pos = &self->pos;
    trace_800b0824(pos, pf, pt, 60, 1);
    if (ticks_804b1764 > 59) return 0;
    Settings *s = settings_801797b4(identity_80341584(self->resource));
    *(Words *)&self->pos = result_8043ae20[0];
    Vec3 *o = &s->offset;
    self->pos.x += o->x;
    pos->y += o->y;
    pos->z += o->z;
    self->w120 = w_804b17a8;
    self->w124 = w_804b17ac;
    float v = value_80178df0(as_80342a74(self->limit));
    if (self->pos.y < v) return 0;
    return 1;
}
