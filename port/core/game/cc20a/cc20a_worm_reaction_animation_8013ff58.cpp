#include "w3d_ptr.h"
#line 1 "cc20a_worm_reaction_animation_8013ff58.cpp"
extern "C" {
/* Observed worm graphic fields; names are inferred from local behavior. */
typedef struct Cc20aWormGraphic {
    unsigned char pad00[0x1c];
    Ptr32<void> mesh;
    unsigned char pad20[0x70-0x20];
    int entity;
    unsigned char pad74[0x1d8-0x74];
    int animation;
    unsigned char pad1dc[0x240-0x1dc];
    Ptr32<void> effect;
    unsigned char pad244[0x2e0-0x244];
    int blink;
} Cc20aWormGraphic;
typedef struct Cc20aEntity {
    unsigned char pad00[0xd5];
    unsigned char player;
} Cc20aEntity;
extern int w3d_auto_8013fecc(Ptr32<Cc20aWormGraphic>, Ptr32<void>);
extern int w3d_get_800a830c(Ptr32<void>);
extern Ptr32<Cc20aEntity> w3d_fn_800fc6dc(int);
extern int w3d_fn_80139158(Ptr32<Cc20aWormGraphic>);
extern Ptr32<void> w3d_empty_80343584(Ptr32<void>);
extern int w3d_mesh_instance_is_playing(Ptr32<void>, int);
extern int fn_80162C20(void);
extern int w3d_fn_801359ec(Ptr32<Cc20aWormGraphic>, Ptr32<void>, int, Ptr32<int>, float, float, float);
extern const float w3d_f32_8039fe38[];
extern const float w3d_f32_8039fe3c[];
extern int w3d_global_804ab2dc;
extern int w3d_global_804ab2e0;
extern int w3d_global_804ab304;
extern int w3d_global_804ab310;
extern const char w3d_str_8039fe48[];
extern void w3d_fn_800fc1f0(Ptr32<Ptr32<const char>>, Ptr32<int>);
extern void w3d_fn_800e5bb8(Ptr32<void>);

void w3d_cc20a_worm_reaction_animation_8013ff58(Ptr32<Cc20aWormGraphic> self, Ptr32<void> message)
{
    int player;
    Ptr32<void> mesh;
    if (!w3d_auto_8013fecc(self, message)) return;
    if (w3d_fn_80139158(self)) return;
    player = w3d_get_800a830c(message);
    if (w3d_fn_800fc6dc(self->entity)->player != player) return;
    mesh = w3d_empty_80343584(self->mesh);
    if (!w3d_mesh_instance_is_playing(mesh, self->animation)) return;
    switch ((unsigned int)fn_80162C20() & 3) {
    case 0: w3d_fn_801359ec(self, mesh, w3d_global_804ab2dc, &self->animation, w3d_f32_8039fe38[0], w3d_f32_8039fe3c[0], w3d_f32_8039fe3c[0]); break;
    case 1: w3d_fn_801359ec(self, mesh, w3d_global_804ab2e0, &self->animation, w3d_f32_8039fe38[0], w3d_f32_8039fe3c[0], w3d_f32_8039fe3c[0]); break;
    case 2: w3d_fn_801359ec(self, mesh, w3d_global_804ab304, &self->animation, w3d_f32_8039fe38[0], w3d_f32_8039fe3c[0], w3d_f32_8039fe3c[0]); break;
    case 3: w3d_fn_801359ec(self, mesh, w3d_global_804ab310, &self->animation, w3d_f32_8039fe38[0], w3d_f32_8039fe3c[0], w3d_f32_8039fe3c[0]); break;
    }
}

}


