#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2b_a_8016a484.c"
struct K2bModeCommand { unsigned char pad0[32]; int index; int custom; };
extern int w3d_global_804ab51c;
extern unsigned char w3d_global_804ab520;
extern int w3d_table_803a552c[];
extern void w3d_gx_set_mode_8030ba64(int custom, int value, int extra);
int w3d_k2b_set_blend_mode_8016a484(Ptr32<void> unused, Ptr32<struct K2bModeCommand> command)
{
    if (command->custom == 0) {
        w3d_global_804ab51c = 7;
        w3d_gx_set_mode_8030ba64(0, 7, w3d_global_804ab520);
    } else {
        int value = w3d_table_803a552c[command->index];
        w3d_global_804ab51c = value;
        w3d_gx_set_mode_8030ba64(1, value, w3d_global_804ab520);
    }
    return 0;
}
// desc: Appears to select a blend or mode value from a table (or the default 7), store it in a global and apply it.

}
