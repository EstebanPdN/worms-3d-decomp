// GWMP8P rev0 0x800a9620. Camera rig copy initializer. Field names are
// inferred. The rig copies three vectors from its source, normalizes the
// third, calls the base copy, then posts input-context messages through the
// message arena.
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    float lenSq() const { return x * x + y * y + z * z; }
    float len() const { return sqrt_802e82c0(lenSq()); }
    void normalize() { float f = 1.0f / len(); x *= f; y *= f; z *= f; }
};
struct Message;
extern "C" Message *arena_alloc_801613f0(void *, int);
extern "C" unsigned message_id_8015f5a0(void *, int);
extern "C" Message *message_init_8010a8e0(Message *, unsigned short, const char *);
extern "C" int message_post_8016239c(Message *);
extern void *g_arena_804b1754;
extern int g_804ab420;
extern unsigned char id_804ae314[8], id_804ae30c[8];
struct Cam { void *vt; Vec a, b, c; };
extern "C" void base_8015a6b8(Cam *, const Cam *);
extern "C" void d26h_camera_rig_copy_800a9620(Cam *self, const Cam *o) {
    self->a = o->a;
    self->b = o->b;
    self->c = o->c;
    self->c.normalize();
    base_8015a6b8(self, o);
    if (g_804ab420 == 0) { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); message_post_8016239c(message_init_8010a8e0(m, message_id_8015f5a0(id_804ae314, 1), "Fire")); }
    { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); message_post_8016239c(message_init_8010a8e0(m, message_id_8015f5a0(id_804ae314, 1), "CameraSelect")); }
    { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); message_post_8016239c(message_init_8010a8e0(m, message_id_8015f5a0(id_804ae30c, 1), "WormFirstPersonAiming")); }
    { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); message_post_8016239c(message_init_8010a8e0(m, message_id_8015f5a0(id_804ae30c, 1), "WormAiming")); }
    { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); message_post_8016239c(message_init_8010a8e0(m, message_id_8015f5a0(id_804ae30c, 1), "WormMoving")); }
    { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); message_post_8016239c(message_init_8010a8e0(m, message_id_8015f5a0(id_804ae30c, 1), "WormRoping")); }
    { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); message_post_8016239c(message_init_8010a8e0(m, message_id_8015f5a0(id_804ae30c, 1), "UtilityGirder")); }
    { Message *m = arena_alloc_801613f0(g_arena_804b1754, 12); message_post_8016239c(message_init_8010a8e0(m, message_id_8015f5a0(id_804ae30c, 1), "Flying")); }
}
