#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s21_g_801dff4c.c"
extern int fn_801e507c(Ptr32<void>);
extern int fn_801e4e6c(Ptr32<void>);
struct S21Slots { char pad[48]; int slots[32]; };
int w3d_s21_flush_slots_801dff4c(Ptr32<struct S21Slots> self)
{
    Ptr32<int> slot = self->slots;
    unsigned i;
    for (i = 0; i < 32; i++, slot++) {
        if (*slot && fn_801e507c(w3d::G(*slot)))
            fn_801e4e6c(w3d::G(*slot));
    }
    return 0;
}

}
