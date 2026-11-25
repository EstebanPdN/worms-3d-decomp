#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_state_release_8013f1c0.c"
typedef struct K2aRef { Ptr32<Ptr32<void>> vtable; } K2aRef;
typedef struct K2aStateOwner { char pad0[164]; Ptr32<K2aRef> held; char pad_a8[516]; unsigned int state; } K2aStateOwner;

void k2a_state_release_8013f1c0(Ptr32<K2aStateOwner> self)
{
    switch (self->state) {
    case 1: case 2: case 5: case 6:
    case 0x14: case 0x15: case 0x22: case 0x24:
        if (self->held != 0)
            ((Ptr32<void (Ptr32<K2aRef>)>)self->held->vtable[4])(self->held);
        self->held = 0;
        break;
    default:
        break;
    }
}

}
