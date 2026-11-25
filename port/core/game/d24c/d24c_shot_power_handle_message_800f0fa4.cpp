#include "w3d_ptr.h"
#line 1 "d24c_shot_power_handle_message_800f0fa4.cpp"
// d24c: 0x800f0fa4 (424 bytes). Message handler of the shot power meter. Message 64:
// forward to the base and initialise on success, or return 0x80004005. Message 66: post
// a closing message. First cached id, when not armed and the actor may act: arm (+48),
// store the tick (+44) and post two messages. Second cached id, when armed: disarm and
// post a message. Everything else forwards to the base. Names are inferred.
struct Message { unsigned short id; };
struct Shot {
    unsigned char u0[44];
    int tick;      // +44
    int armed;     // +48
};
struct Context { unsigned char u[52]; int tick; };
struct Simple { short id; Ptr32<const void> vtable; };
extern "C" int base_8015fb34(Ptr32<Shot>, Ptr32<Message>);
extern "C" void init_800f1200(Ptr32<Shot>);
extern "C" int id_equals_8015f65c(unsigned short, Ptr32<int>);
extern "C" int restricted_800ef788(Ptr32<void>);
extern "C" Ptr32<Context> context_80165254(void);
extern "C" Ptr32<void> arena_801613f0(Ptr32<void>, int);
extern "C" short message_id_8015f5a0(Ptr32<int>, int);
extern "C" int post_8016239c(Ptr32<void>);
extern Ptr32<void> arena_804b1754;
extern Ptr32<void> actor_804aaf04;
extern const unsigned char message_vtable_8040db38[];
extern int a_804af088, b_804af060, m0_804af078, m1_804af068, m2_804af090, m3_804af080;
inline void post_simple(Ptr32<int> cache) {
    Ptr32<Simple> m = (Ptr32<Simple>)arena_801613f0(arena_804b1754, 8);
    m->id = message_id_8015f5a0(cache, 1);
    m->vtable = message_vtable_8040db38;
    post_8016239c(m);
}
extern "C" int d24c_shot_power_handle_message_800f0fa4(Ptr32<Shot> self, Ptr32<Message> m) {
    unsigned short id = m->id;
    switch (id) {
    case 64:
        if (base_8015fb34(self, m) >= 0) {
            init_800f1200(self);
            goto handled;
        }
        return 0x80004005;
    case 66:
        post_simple(&m0_804af078);
        goto handled;
    default:
        if (id_equals_8015f65c(id, &a_804af088) && self->armed == 0 && restricted_800ef788(actor_804aaf04)) {
            self->armed = 1;
            self->tick = context_80165254()->tick;
            post_simple(&m1_804af068);
            post_simple(&m2_804af090);
            goto handled;
        }
        if (id_equals_8015f65c(id, &b_804af060) && self->armed) {
            self->armed = 0;
            post_simple(&m3_804af080);
            goto handled;
        }
        break;
    }
    return base_8015fb34(self, m);
handled:
    return 0;
}


