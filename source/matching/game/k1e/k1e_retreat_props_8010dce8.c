/* Appears to reset the RetreatTime property and look up ActiveWormIndex into
   a field of the caller's state object (+64). */
extern int s8_property_write_800fc3b0(void *name, int value);
extern unsigned int w3d_constructor_lookup_name(const void *name, void *output);

struct K1eRetreatState {
    char pad0[64];
    int active_worm_index;
};

void w3d_k1e_retreat_reset_8010dce8(struct K1eRetreatState *state)
{
    const char *retreat = "RetreatTime";
    const char *active;
    s8_property_write_800fc3b0(&retreat, 0);
    active = "ActiveWormIndex";
    w3d_constructor_lookup_name(&active, &state->active_worm_index);
}
