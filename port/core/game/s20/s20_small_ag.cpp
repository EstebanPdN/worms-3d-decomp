#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s20_small_ag.c"
/* Loop over a pointer vector with no per-item work. */
int w3d_s20_touch_items_800f6760(Ptr32<char> self, Ptr32<char> vector) {
    unsigned int count = (*(Ptr32<int>)(vector + 20) - *(Ptr32<int>)(vector + 16)) >> 2;
    unsigned int i;
    volatile char pad[32];
    for (i = 0; i < count; i++) {
    }
    return 1;
}

}
