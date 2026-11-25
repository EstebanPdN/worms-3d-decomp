// d26c: 0x800d99e0. Probe downward from a point: returns 0 when the frame is past the point's next time, otherwise
// posts the tick message and returns the ground normal, fall direction and stamp, returning 1. Names are inferred.
struct Words { int a, b, c; };
struct Actor {
    struct V { void *u[12]; void (*refresh)(Actor *, int, void *); } *vtable;
    char u4[32];
    char pos[12];
    char vel[12];
    char acc[12];
    char u72[288];
    int stamp_a, stamp_b;
    int base;
};
struct Vec3 {
    float x, y, z;
    float lenSq() const { return x * x + y * y + z * z; }
    void normalize();
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
};
extern "C" float sqrt_802e82c0(float);
inline void Vec3::normalize() {
    float f = 1.0f / sqrt_802e82c0(lenSq());
    x *= f; y *= f; z *= f;
}
struct Message { unsigned short id; const void *data; };
extern "C" void step_800b0824(Vec3 *, Vec3 *, Vec3 *, int, int);
extern Vec3 zero_8045e788[];
extern int now_804b1764, table_ready_804b1784;
extern int stamp_a_804b17a8, stamp_b_804b17ac;
extern int arrive_id_804aeb08, tick_id_804aeb30;
extern "C" int cached_id_8015f5a0(int *, int);
extern "C" void *arena_alloc_801613f0(void *, unsigned);
extern void *arena_804b1754;
extern char data_8040db38[];
extern "C" int post_8016239c(void *);
extern "C" void init_800bd920(void);
extern Words dir_8043ae38[], up_8043ae20[];
extern "C" int d26c_actor_ground_probe_800d99e0(Actor *self, Vec3 *p, Vec3 *dir, Words *up) {
    int when = (int)p->y + 1;
    Vec3 a(0.0f, -1.0f, 0.0f);
    Vec3 b(zero_8045e788[0]);
    step_800b0824(p, &a, &b, when, 1);
    if (now_804b1764 > when) return 0;
    Message *m = (Message *)arena_alloc_801613f0(arena_804b1754, 8);
    m->id = cached_id_8015f5a0(&tick_id_804aeb30, 1);
    m->data = data_8040db38;
    post_8016239c(m);
    if (table_ready_804b1784 == 0) init_800bd920();
    *(Words *)dir = dir_8043ae38[0];
    dir->normalize();
    *up = up_8043ae20[0];
    self->stamp_b = stamp_b_804b17ac;
    self->stamp_a = stamp_a_804b17a8;
    return 1;
}
