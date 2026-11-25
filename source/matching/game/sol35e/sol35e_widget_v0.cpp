#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
struct sol35e_Cc17dHeld {
    void *ptr;
    sol35e_Cc17dHeld(void *p) : ptr(p) {}
    void operator=(void *p)
    {
        if (ptr)
            VCALL(ptr, void (*)(void *), 16)(ptr);
        ptr = p;
    }
    void reset()
    {
        if (ptr)
            VCALL(ptr, void (*)(void *), 16)(ptr);
        ptr = 0;
    }
};
inline void *operator new(unsigned int, void *place) { return place; }
struct sol35e_Cc17dWidget2 {
    void *vtable;
    unsigned char opaque[204];
    void *second;
    int w212, w216, w220, w224;
    sol35e_Cc17dHeld held;
    float scale;
};
extern "C" void base_8015fef0(sol35e_Cc17dWidget2 *);
extern "C" void member_802afb20(void *);
extern "C" unsigned char table_8041c430[], table_8041c3e0[];
extern float lbl_803d2e04[];
extern "C" sol35e_Cc17dWidget2 *sol35e_w3d_cc17d_widget2_construct_802a2e24(sol35e_Cc17dWidget2 *self)
{
    base_8015fef0(self);
    member_802afb20((unsigned char *)self + 28);
    new (&self->held) sol35e_Cc17dHeld(0);
    self->second = table_8041c3e0;
    self->vtable = table_8041c430;
    self->scale = lbl_803d2e04[0];
    self->w212 = 0; self->w216 = 0; self->w220 = 0; self->w224 = 0;
    self->held = 0;
    return self;
}
