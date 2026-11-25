#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k1a_toggle_flag_800385fc.c"
struct K1aToggler { char pad0[48]; Ptr32<void> target; char pad52[28]; unsigned char flag; char pad81[11]; int mode; };
extern int w3d_s20_store_byte_value_80173f88(Ptr32<void>, Ptr32<unsigned char>);

void k1a_toggler_flip_800385fc(Ptr32<struct K1aToggler> self)
{
    if (self->mode == 0 || self->mode == 2) {
        self->flag = (self->flag + 1) & 1;
        w3d_s20_store_byte_value_80173f88(self->target, &self->flag);
    }
}

}
