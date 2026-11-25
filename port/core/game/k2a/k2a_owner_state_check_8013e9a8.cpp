#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_owner_state_check_8013e9a8.c"
typedef struct K2aSlotInfo { char pad0[128]; int kind; unsigned int state; char pad88[84]; int valid; } K2aSlotInfo;
typedef struct K2aOwner { char pad0[84]; Ptr32<void> current; } K2aOwner;
extern Ptr32<void> w3d_empty_803426b4(Ptr32<void>);
extern unsigned int w3d_auto_80178c48(Ptr32<void>);
extern Ptr32<K2aSlotInfo> s8_index_query_800fc6dc(unsigned int);

int k2a_owner_state_check_8013e9a8(Ptr32<K2aOwner> self)
{
    unsigned int index = w3d_auto_80178c48(w3d_empty_803426b4(self->current));
    Ptr32<K2aSlotInfo> info;
    if (index > 15)
        return 0;
    info = s8_index_query_800fc6dc(index);
    if (info->valid == 0)
        return 0;
    if (info->kind != 10)
        return 0;
    switch (info->state) {
    case 10: case 12: case 13:
        return 1;
    default:
        return 0;
    }
}

}
