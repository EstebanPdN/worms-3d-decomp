typedef struct K2aFader { char pad0[88]; int active; float level; } K2aFader;
typedef struct K2aGameContext { char pad0[188]; unsigned int flags; } K2aGameContext;
extern const float w3d_f32_8037263c[];
extern const float w3d_f32_80372640[];
extern K2aGameContext *w3d_context_804b1788;
extern void FUN_8002bc14(void *);

void k2a_fade_step_8002c118(K2aFader *self)
{
    float floor_level = w3d_f32_80372640[0];
    float level = self->level * w3d_f32_8037263c[0];
    self->level = level;
    if (level <= floor_level) {
        self->level = floor_level;
        self->active = 0;
    }
    FUN_8002bc14((void *)self);
    w3d_context_804b1788->flags |= 4;
}
