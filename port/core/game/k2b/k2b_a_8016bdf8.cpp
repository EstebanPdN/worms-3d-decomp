#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8016bdf8.c"
struct K2bVec3 { float x, y, z; };
struct K2bLight { unsigned char pad0[156]; struct K2bVec3 position; struct K2bVec3 target; unsigned char pad1[4]; struct K2bVec3 direction; };
struct K2bLightOwner { unsigned char pad0[196]; unsigned short next_slot; int enabled; };
struct K2bGxState { unsigned char pad0[264]; unsigned char slots[1][64]; };
extern Ptr32<struct K2bGxState> w3d_global_804b1884;
extern void w3d_light_reset_8016a0a4(Ptr32<struct K2bLightOwner> self);
extern void w3d_light_load_8016b9ec(Ptr32<void> slot, Ptr32<struct K2bLight> light);
extern void w3d_gx_set_position_80309594(Ptr32<void> slot, float x, float y, float z);
extern void w3d_gx_set_attenuation_803093f4(Ptr32<void> slot, float a, float b, float c);
extern void w3d_s20_enable_slot_8016857c(Ptr32<struct K2bGxState> state, unsigned int slot);
static inline unsigned short k2b_take_slot(Ptr32<struct K2bLightOwner> owner)
{
    return owner->next_slot++;
}
static inline void k2b_set_position(Ptr32<void> slot, Ptr32<const struct K2bVec3> v)
{
    w3d_gx_set_position_80309594(slot, v->x, v->y, v->z);
}
int w3d_k2b_enable_light_slot_8016bdf8(Ptr32<char> base, Ptr32<struct K2bLight> light)
{
    Ptr32<struct K2bLightOwner> self = base ? w3d::R((Ptr32<struct K2bLightOwner>)(base - 4)) : 0;
    if (self->enabled != 0) {
        Ptr32<struct K2bGxState> state = w3d_global_804b1884;
        unsigned int index = k2b_take_slot(self);
        Ptr32<void> slot = state->slots[index];
        w3d_light_reset_8016a0a4(self);
        w3d_light_load_8016b9ec(slot, light);
        k2b_set_position(slot, &light->position);
        w3d_gx_set_attenuation_803093f4(slot, light->target.z, light->target.y, light->target.x);
        w3d_s20_enable_slot_8016857c(w3d_global_804b1884, index & 255);
    }
    return 0;
}
// desc: Appears to claim the next light slot when lighting is enabled, load a light into it, set position and attenuation and enable it.

}
