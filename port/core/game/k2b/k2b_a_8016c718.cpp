#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8016c718.c"
struct K2bCommand { unsigned char pad0[60]; int enabled; unsigned char pad1[16]; int mode; };
struct K2bGxState { unsigned char pad0[5268]; unsigned int flags; };
extern Ptr32<struct K2bGxState> w3d_global_804b1884;
extern int w3d_gx_prepare_8016c338(Ptr32<char> base, Ptr32<struct K2bCommand> command);
extern void w3d_gx_set_cull_mode_8016a1e8(Ptr32<void> self, int mode);
int w3d_k2b_apply_cull_mode_8016c718(Ptr32<char> base, Ptr32<struct K2bCommand> command)
{
    int result = w3d_gx_prepare_8016c338(base, command);
    Ptr32<void> self = base ? w3d::R(base - 4) : 0;
    if (command->enabled != 0) {
        int cull;
        switch (command->mode) {
        case 0: cull = 3; break;
        case 2: cull = 1; break;
        case 3: cull = 2; break;
        case 1: cull = 0; break;
        }
        w3d_gx_set_cull_mode_8016a1e8(self, cull);
        w3d_global_804b1884->flags |= 0x20000000;
    }
    return result;
}
// desc: Appears to apply a command's cull mode through a four-way mapping and mark the global GX state dirty.

}
