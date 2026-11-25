#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4b_a_801a7274.c"
struct K4bQuad { int a; int b; int c; int d; };
struct K4bLink { Ptr32<void> node; int count; };
struct K4bChannel {
    struct K4bQuad state;
    struct K4bQuad target;
    struct K4bLink link_a;
    struct K4bLink link_b;
};
struct K4bChannelPair {
    Ptr32<Ptr32<void>> vtable;
    char base[36];
    int field_28;
    int field_2c;
    struct K4bChannel first;
    struct K4bChannel second;
};
extern Ptr32<void> lbl_80413c38[];
extern Ptr32<void> lbl_80413bf8[];
extern Ptr32<void> fn_801e81c8(Ptr32<void> member);
extern void fn_803534b0(Ptr32<struct K4bChannel> channel, int mode);
static inline void k4b_quad_init(Ptr32<struct K4bQuad> q)
{
    q->a = 0;
    q->b = 0;
    q->c = 0;
    q->d = 0;
}
static inline void k4b_link_init(Ptr32<struct K4bLink> l)
{
    l->count = 0;
}
static inline void k4b_channel_init(Ptr32<struct K4bChannel> c)
{
    k4b_quad_init(&c->state);
    k4b_quad_init(&c->target);
    k4b_link_init(&c->link_a);
    k4b_link_init(&c->link_b);
    fn_803534b0(c, 0);
}
Ptr32<struct K4bChannelPair> w3d_k4b_channel_pair_construct_801a7274(Ptr32<struct K4bChannelPair> self)
{
    volatile char pad[32];
    self->vtable = lbl_80413c38;
    fn_801e81c8(self->base);
    self->vtable = lbl_80413bf8;
    self->field_28 = 0;
    k4b_channel_init(&self->first);
    k4b_channel_init(&self->second);
    self->field_2c = 0;
    return self;
}
// desc: w3d_k4b_channel_pair_construct_801a7274: Appears to construct an object holding two channel members, each zeroed and reset through 0x803534b0 with mode zero, after the base and vtable setup.

}
