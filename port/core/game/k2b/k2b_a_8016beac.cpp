#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8016beac.c"
struct K2bVec3 { float x, y, z; };
struct K2bLight { unsigned char pad0[156]; struct K2bVec3 position; struct K2bVec3 target; unsigned char pad1[4]; struct K2bVec3 direction; };
struct K2bLightOwner { unsigned char pad0[196]; unsigned short next_slot; };
struct K2bGxState { unsigned char pad0[264]; unsigned char slots[1][64]; };
extern Ptr32<struct K2bGxState> w3d_global_804b1884;
extern void w3d_light_reset_8016a0a4(Ptr32<struct K2bLightOwner> self);
extern void w3d_light_load_8016b9ec(Ptr32<void> slot, Ptr32<struct K2bLight> light);
extern void w3d_gx_set_position_80309594(Ptr32<void> slot, float x, float y, float z);
extern void w3d_gx_set_direction_803095a4(Ptr32<void> slot, float x, float y, float z);
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
static inline void k2b_set_direction(Ptr32<void> slot, Ptr32<const struct K2bVec3> v)
{
    w3d_gx_set_direction_803095a4(slot, -v->x, -v->y, -v->z);
}
Ptr32<void> w3d_k2b_allocate_light_slot_8016beac(Ptr32<struct K2bLightOwner> self, Ptr32<struct K2bLight> light)
{
    Ptr32<struct K2bGxState> state = w3d_global_804b1884;
    unsigned int index = k2b_take_slot(self);
    Ptr32<void> slot = state->slots[index];
    w3d_light_reset_8016a0a4(self);
    w3d_light_load_8016b9ec(slot, light);
    k2b_set_position(slot, &light->position);
    k2b_set_direction(slot, &light->direction);
    w3d_gx_set_attenuation_803093f4(slot, light->target.z, light->target.y, light->target.x);
    w3d_s20_enable_slot_8016857c(w3d_global_804b1884, index & 255);
    return slot;
}
// desc: Appears to claim the next light slot, load a light into it, set its position, direction and attenuation and enable it.

}
