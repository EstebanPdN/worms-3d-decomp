#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct Cc17dHeld { void *ptr; };
struct Cc17dWidget2 {
    void *vtable;
    unsigned char opaque[204];
    void *second;
    int w212, w216, w220, w224;
    struct Cc17dHeld held;
    float scale;
};
extern void base_8015fef0(struct Cc17dWidget2 *);
extern void member_802afb20(void *);
extern unsigned char table_8041c430[], table_8041c3e0[];
extern float lbl_803d2e04[];
static inline void cc17d_held_reset(struct Cc17dHeld *h)
{
    if (h->ptr)
        VCALL(h->ptr, void (*)(void *), 16)(h->ptr);
    h->ptr = 0;
}
static inline void cc17d_held_init(struct Cc17dHeld *h, void *p) { h->ptr = p; }
struct Cc17dWidget2 *w3d_cc17d_widget2_construct_802a2e24(struct Cc17dWidget2 *self)
{
    base_8015fef0(self);
    member_802afb20((unsigned char *)self + 28);
    cc17d_held_init(&self->held, 0);
    self->second = table_8041c3e0;
    self->vtable = table_8041c430;
    self->scale = lbl_803d2e04[0];
    self->w212 = 0; self->w216 = 0; self->w220 = 0; self->w224 = 0;
    cc17d_held_reset(&self->held);
    return self;
}
