/* Worms 3D GameCube PAL 0x8004bdf8. Crate step: hands over once exploded; while enabled and not grounded it sweeps down from the position less the height at +64 with gravity from two rates, and on contact posts a message, runs the indexed dispatch when idle and bounces along the normalized global vector; below the water height it marks exploded; otherwise it integrates position and velocity with step 20, easing fall speed toward -0.055 while the parachute flag at +112 is set. Disabled or grounded crates release the object at +244. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec scaled(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    void add(const Vec &o) { x += o.x; y += o.y; z += o.z; }
    float len() const { return sqrt_802e82c0(x * x + y * y + z * z); }
    void normalize() { float s = 1.0f / len(); x *= s; y *= s; z *= s; }
};
struct Handle;
struct Owned { struct Vt { char u[16]; void (*release)(Owned *); } *vt; };
struct Crate {
    char u0[40]; Vec pos; Vec vel; float height; char u68[100 - 68];
    int grounded; int a104; int a108; int moving; char u116[128 - 116]; int exploded; char u132[176 - 132];
    Handle *a176; Handle *a180; Handle *a184; char u188[244 - 188]; Owned *a244;
};
struct Msg { unsigned short id; void *data; };
extern "C" {
void f6b_crate_step_8004c138(Crate *);
float w3d_auto_80178df0(Handle *);
void sweep_800b0824(Vec *, Vec *, const Vec *, int, int);
void *tsonnet_b33_arena_801613f0(void *, int);
int w3d_cached_message_id(void *, int);
int w3d_message_post_current(Msg *);
void s19_dispatch_indexed_800bd920();
void w3d_d25g_body_bounce_8004ce58(Crate *, Vec *);
void w3d_fn_8004cd08(Crate *);
}
extern unsigned hits_804b1764;
extern void *arena_804b1754;
struct MessageSlot { int a, b; };
extern MessageSlot msg_slot_804ad3b8;
extern char msg_data_8040db38[];
extern int flag_804b1784;
extern Vec bounce_8043ae38;
extern "C" void w3d_d28g_crate_fall_step_8004bdf8(Crate *self)
{
    if (self->exploded) { f6b_crate_step_8004c138(self); return; }
    if (!self->a108 || self->grounded) goto release;
    {
    int z = self->a104;
    if (z) goto release;
    float y = w3d_auto_80178df0(self->a176);
    y *= w3d_auto_80178df0(self->a180);
    Vec g(0.0f, y, 0.0f);
    Vec start = self->pos;
    start.y -= self->height;
    sweep_800b0824(&start, &self->vel, &g, 20, 1);
    self->grounded = hits_804b1764 <= 20;
    if (self->grounded) {
        self->moving = z;
        Msg *m = (Msg *)tsonnet_b33_arena_801613f0(arena_804b1754, 8);
        m->id = w3d_cached_message_id(&msg_slot_804ad3b8, 1);
        m->data = msg_data_8040db38;
        w3d_message_post_current(m);
        if (flag_804b1784 == 0) s19_dispatch_indexed_800bd920();
        Vec u = bounce_8043ae38;
        u.normalize();
        w3d_d25g_body_bounce_8004ce58(self, &u);
        return;
    }
    if (self->pos.y <= w3d_auto_80178df0(self->a184)) {
        self->moving = z;
        self->exploded = 1;
        w3d_fn_8004cd08(self);
        return;
    }
    self->pos.add(self->vel.scaled(20.0f));
    if (self->moving) {
        if (self->vel.y < -0.055f) {
            self->vel.y += (-0.055f - self->vel.y) * 0.25f;
            return;
        }
        self->vel.add(g.scaled(20.0f));
    } else {
        self->vel.add(g.scaled(20.0f));
    }
    return;
    }
release:
    if (self->a244) self->a244->vt->release(self->a244);
    self->a244 = 0;
}
