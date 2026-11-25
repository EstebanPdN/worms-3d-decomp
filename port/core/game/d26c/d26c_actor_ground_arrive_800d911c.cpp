#include "w3d_ptr.h"
#line 1 "d26c_actor_ground_arrive_800d911c.cpp"
// d26c: 0x800d911c. Step the actor to the ground and, when it arrives at or before the planned time, take that time,
// post the tick message, return the ground normal and fall direction and refresh through virtual +48. Names are
// inferred. The bool local keeps the original's separate condition register (mcrf).
struct Words { int a, b, c; };
struct Actor {
    struct V { Ptr32<void> u[12]; Ptr32<void (Ptr32<Actor>, int, Ptr32<void>)> refresh; }; Ptr32<struct V> vtable;
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
};
extern "C" float sqrt_802e82c0(float);
inline void Vec3::normalize() {
    float f = 1.0f / sqrt_802e82c0(lenSq());
    x *= f; y *= f; z *= f;
}
struct Message { unsigned short id; Ptr32<const void> data; };
extern "C" void step_800b0824(Ptr32<void>, Ptr32<void>, Ptr32<void>, int, int);
extern int now_804b1764, table_ready_804b1784;
extern int stamp_a_804b17a8, stamp_b_804b17ac;
extern int arrive_id_804aeb08, tick_id_804aeb30;
extern "C" int cached_id_8015f5a0(Ptr32<int>, int);
extern "C" Ptr32<void> arena_alloc_801613f0(Ptr32<void>, unsigned);
extern Ptr32<void> arena_804b1754;
extern char data_8040db38[];
extern "C" int post_8016239c(Ptr32<void>);
extern "C" void init_800bd920(void);
extern Words dir_8043ae38[], up_8043ae20[];
extern "C" void d26c_actor_ground_arrive_800d911c(Ptr32<Actor> self, Ptr32<unsigned short> id, Ptr32<int> when, Ptr32<Words> out2, Ptr32<void> arg, Ptr32<Vec3> dir) {
    step_800b0824(self->pos, self->vel, self->acc, *when, 1);
    int now = now_804b1764;
    bool late = now > *when;
    if (late) return;
    if (*when != -1 && now >= *when) return;
    *id = cached_id_8015f5a0(&arrive_id_804aeb08, 1);
    *when = now;
    {
        Ptr32<Message> m = (Ptr32<Message>)arena_alloc_801613f0(arena_804b1754, 8);
        m->id = cached_id_8015f5a0(&tick_id_804aeb30, 1);
        m->data = data_8040db38;
        post_8016239c(m);
    }
    if (table_ready_804b1784 == 0) init_800bd920();
    *(Ptr32<Words>)dir = dir_8043ae38[0];
    dir->normalize();
    *out2 = up_8043ae20[0];
    self->vtable->refresh(self, *when + self->base, arg);
    self->stamp_b = stamp_b_804b17ac;
    self->stamp_a = stamp_a_804b17a8;
}


