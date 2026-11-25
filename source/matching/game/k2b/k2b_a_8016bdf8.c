struct K2bVec3 { float x, y, z; };
struct K2bLight { unsigned char pad0[156]; struct K2bVec3 position; struct K2bVec3 target; unsigned char pad1[4]; struct K2bVec3 direction; };
struct K2bLightOwner { unsigned char pad0[196]; unsigned short next_slot; int enabled; };
struct K2bGxState { unsigned char pad0[264]; unsigned char slots[1][64]; };
extern struct K2bGxState *w3d_global_804b1884;
extern void w3d_light_reset_8016a0a4(struct K2bLightOwner *self);
extern void w3d_light_load_8016b9ec(void *slot, struct K2bLight *light);
extern void w3d_gx_set_position_80309594(void *slot, float x, float y, float z);
extern void w3d_gx_set_attenuation_803093f4(void *slot, float a, float b, float c);
extern void w3d_s20_enable_slot_8016857c(struct K2bGxState *state, unsigned int slot);
static inline unsigned short k2b_take_slot(struct K2bLightOwner *owner)
{
    return owner->next_slot++;
}
static inline void k2b_set_position(void *slot, const struct K2bVec3 *v)
{
    w3d_gx_set_position_80309594(slot, v->x, v->y, v->z);
}
int w3d_k2b_enable_light_slot_8016bdf8(char *base, struct K2bLight *light)
{
    struct K2bLightOwner *self = base ? (struct K2bLightOwner *)(base - 4) : 0;
    if (self->enabled != 0) {
        struct K2bGxState *state = w3d_global_804b1884;
        unsigned int index = k2b_take_slot(self);
        void *slot = state->slots[index];
        w3d_light_reset_8016a0a4(self);
        w3d_light_load_8016b9ec(slot, light);
        k2b_set_position(slot, &light->position);
        w3d_gx_set_attenuation_803093f4(slot, light->target.z, light->target.y, light->target.x);
        w3d_s20_enable_slot_8016857c(w3d_global_804b1884, index & 255);
    }
    return 0;
}
// desc: Appears to claim the next light slot when lighting is enabled, load a light into it, set position and attenuation and enable it.
