#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k4a_slot_set_refresh_8008a2a0.c"
typedef struct K4aSlotSet { char pad0[288]; int busy; } K4aSlotSet;
extern void FUN_8008cf40(Ptr32<K4aSlotSet> self, int mode);
extern void FUN_8008a30c(Ptr32<K4aSlotSet> self, int offset, int a, int b);

void k4a_slot_set_refresh_8008a2a0(Ptr32<K4aSlotSet> self)
{
    int offset = 0;
    int i;
    self->busy = 1;
    FUN_8008cf40(self, 1);
    for (i = 6; i != 0; i--) {
        FUN_8008a30c(self, offset, 1, 1);
        offset += 1500;
    }
    FUN_8008cf40(self, 0);
}

}
