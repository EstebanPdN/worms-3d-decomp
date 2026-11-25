#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k1e_retreat_props_8010dce8.c"
/* Appears to reset the RetreatTime property and look up ActiveWormIndex into
   a field of the caller's state object (+64). */
extern int s8_property_write_800fc3b0(Ptr32<void> name, int value);
extern unsigned int w3d_constructor_lookup_name(Ptr32<const void> name, Ptr32<void> output);

struct K1eRetreatState {
    char pad0[64];
    int active_worm_index;
};

void w3d_k1e_retreat_reset_8010dce8(Ptr32<struct K1eRetreatState> state)
{
    Ptr32<const char> retreat = "RetreatTime";
    Ptr32<const char> active;
    s8_property_write_800fc3b0(&retreat, 0);
    active = "ActiveWormIndex";
    w3d_constructor_lookup_name(&active, &state->active_worm_index);
}

}
