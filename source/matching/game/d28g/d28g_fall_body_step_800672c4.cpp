/* Worms 3D GameCube PAL 0x800672c4. Falling-body step: eases and grows once settled; otherwise sweeps from the position with the velocity and a gravity vector built from two rates; on a registered contact it reflects, and below speed 0.01 it snaps to the rest velocity and position and stops, else clears the flag; with no contact it settles when at or below the ground height, or integrates position and velocity with step 20. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec scaled(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    void zero() { x = 0.0f; y = 0.0f; z = 0.0f; }
    void set(const Vec &o) { x = o.x; y = o.y; z = o.z; }
    void add(const Vec &o) { x += o.x; y += o.y; z += o.z; }
    float len() const { return sqrt_802e82c0(x * x + y * y + z * z); }
};
struct Handle;
struct Body {
    char u0[28]; Vec vel; Vec pos; char u52[64 - 52];
    int rest; int done; Handle *a72; Handle *a76; Handle *a80;
};
extern "C" {
float w3d_auto_80178df0(Handle *);
Handle *w3d_empty_80342a74(Handle *);
void k5a_body_ease_and_grow_80067524(Body *);
void w3d_stamp_pair_capture_80067510(Body *);
void f7b_reflect_800675fc(Body *);
void sweep_800b0824(Vec *, Vec *, const Vec *, int, int);
}
extern unsigned hits_804b1764;
extern Vec rest_vel_8045e788;
extern Vec rest_pos_8043ae20;
extern "C" void w3d_d28g_fall_body_step_800672c4(Body *self)
{
    if (self->done) { k5a_body_ease_and_grow_80067524(self); return; }
    int rest = self->rest;
    if (rest) return;
    float y = w3d_auto_80178df0(self->a72);
    y *= w3d_auto_80178df0(self->a76);
    Vec g(0.0f, y, 0.0f);
    Vec start = self->pos; sweep_800b0824(&start, &self->vel, &g, 20, 1);
    self->rest = hits_804b1764 <= 20;
    if (self->rest) {
        f7b_reflect_800675fc(self);
        if (self->vel.len() < 0.01f) {
            self->vel = rest_vel_8045e788;
            w3d_stamp_pair_capture_80067510(self);
            self->pos = rest_pos_8043ae20;
            self->vel.zero();
        } else {
            self->rest = rest;
        }
        return;
    }
    if (self->pos.y <= w3d_auto_80178df0(w3d_empty_80342a74(self->a80))) {
        self->done = 1;
        return;
    }
    self->pos.add(self->vel.scaled(20.0f));
    self->vel.add(g.scaled(20.0f));
}
