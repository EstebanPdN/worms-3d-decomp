// Appears to play a forty-step fade-out on an object's two linked visuals: it
// steps a gray level down from 255 by 6.375 per step, applies it to both
// visuals, runs a per-step virtual update, then marks the object finished,
// releases the visuals and notifies the runtime service.
// Quantized byte conversion requires the original -mfast-cast option.
struct K10aColor
{
    char r, g, b, a;
    K10aColor() { r = -1; g = -1; b = -1; a = -1; }
};

// Partial view of the stack block the original fills: only the leading color
// is written; the rest of the 24-byte block is not touched in this function.
struct K10aColorBlock
{
    K10aColor color;
    int untouched[4];
};

static inline void k10a_fill(K10aColor *color, unsigned char gray)
{
    color->r = gray;
    color->g = gray;
    color->b = gray;
    color->a = -1;
}

struct K10aHeld
{
    void **vtable;
};

struct K10aFader;
struct K10aFaderTable
{
    void (*slots0[16])();
    void (*step)(K10aFader *self, int phase);     // +64
};

struct K10aFader
{
    K10aFaderTable *vtable;      // +0
    char pad4[72];
    unsigned int flags;          // +76
    char pad80[44];
    K10aHeld *first;             // +124
    K10aHeld *second;            // +128
};

extern const float w3d_f32_8039bc6c[];   // 255.0f
extern const float w3d_f32_8039bc70[];   // 6.375f
extern "C" K10aHeld *w3d_empty_8034357c(K10aHeld *held);
extern "C" int fn_80173df0(K10aHeld *held, const K10aColor *color);
extern "C" void w3d_runtime_service_set_byte_b(int value);

extern "C" void w3d_k10a_fade_out_80126ac0(K10aFader *self)
{
    K10aColorBlock block;
    self->flags = (self->flags | 0x20000000) & ~0x10000000u;
    float level = w3d_f32_8039bc6c[0];
    for (unsigned int step = 0; step < 40; step++)
    {
        level = level - w3d_f32_8039bc70[0];
        unsigned char gray = (unsigned char)level;
        k10a_fill(&block.color, gray);
        fn_80173df0(w3d_empty_8034357c(self->first), &block.color);
        fn_80173df0(w3d_empty_8034357c(self->second), &block.color);
        self->vtable->step(self, 0);
    }
    self->flags = (self->flags | 0x10000000) & ~0x20000000u;
    int zero = 0;
    if (self->first)
        ((void (*)(K10aHeld *))self->first->vtable[4])(self->first);
    self->first = (K10aHeld *)zero;
    if (self->second)
        ((void (*)(K10aHeld *))self->second->vtable[4])(self->second);
    self->second = (K10aHeld *)zero;
    w3d_runtime_service_set_byte_b(3);
}
