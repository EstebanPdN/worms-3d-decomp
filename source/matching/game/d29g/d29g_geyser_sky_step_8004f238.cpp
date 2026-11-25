/* Worms 3D GameCube PAL 0x8004f238. Geyser sky step: lazily initialises three static vectors, passes two of them to the camera service, moves the 3 by 3 sprite grid at +28 by the scroll vector, advances the two scroll angles with wrap-around, and at random intervals of 500 to 2500 ms starts the Part_Geyser particle at a random position. Returns 20. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Sprite { struct Vt { char u[80]; void (*place)(Sprite *, const Vec &, int); } *vt; };
struct Camera { struct Vt { char u[44]; void (*set_a)(Camera *, Vec *); void (*set_b)(Camera *, Vec *); } *vt; };
struct Engine { char u[48]; Camera *camera; };
struct Ctx { char u[52]; unsigned now; };
struct Sky { char u[28]; Sprite *grid[9]; };
extern "C" {
Ctx *w3d_engine_get_context();
float fn_80162C40();
int w3d_s20_forward_global_800e5ca4(Vec *, const char *, int, float);
}
extern int guard_804ad46c, guard_804ad470, guard_804ad474;
extern Vec step_804299d0, dir_804299dc, col_804299e8;
extern Engine *engine_804b1788;
extern unsigned last_804aa9ec, wait_804aa9f0;
extern char effect_803778fc[];
extern "C" int w3d_d29g_geyser_sky_step_8004f238(Sky *self)
{
    if (!guard_804ad46c) { guard_804ad46c = 1; step_804299d0.set(0.0f, 0.0f, 0.0f); }
    if (!guard_804ad470) { dir_804299dc.set(0.0f, 0.0f, -450.0f); guard_804ad470 = 1; }
    if (!guard_804ad474) { guard_804ad474 = 1; col_804299e8.set(0.0f, 0.0f, 0.0f); }
    engine_804b1788->camera->vt->set_a(engine_804b1788->camera, &dir_804299dc);
    engine_804b1788->camera->vt->set_b(engine_804b1788->camera, &col_804299e8);
    for (int i = 0; i <= 2; i++) {
        float fi = (float)i;
        for (int j = 0; j <= 2; j++) {
            Sprite *o = self->grid[i + j * 3];
            o->vt->place(o, Vec(step_804299d0.x / fi, step_804299d0.y * (float)j, step_804299d0.z), 0);
        }
    }
    step_804299d0.y += 0.00087266468f;
    if (step_804299d0.y > 6.2831855f) step_804299d0.y -= 6.2831855f;
    step_804299d0.z += 0.017453292f;
    if (step_804299d0.z > 25.132742f) step_804299d0.z -= 25.132742f;
    unsigned now = w3d_engine_get_context()->now;
    if (now >= last_804aa9ec + wait_804aa9f0) {
        last_804aa9ec = now;
        wait_804aa9f0 = (unsigned)(fn_80162C40() * 2000.0f) + 500;
        float x = (fn_80162C40() - 0.5f) * 16.0f;
        float y = fn_80162C40() * 16.0f + -15.0f;
        float z = (fn_80162C40() - 0.5f) * 3.0f;
        Vec p(x, y, z);
        Vec c = p;
        w3d_s20_forward_global_800e5ca4(&p, effect_803778fc, 0, 0.0f);
    }
    return 20;
}
