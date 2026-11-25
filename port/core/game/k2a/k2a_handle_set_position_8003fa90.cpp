#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_handle_set_position_8003fa90.c"
typedef struct K2aVec3 { float x, y, z; } K2aVec3;
typedef struct K2aHandleSlot {
    K2aVec3 position;
    float radius, radius_squared;
    unsigned int slot_word, unknown_18;
    Ptr32<void> resource;
} K2aHandleSlot;
typedef struct K2aHandleTable { Ptr32<K2aHandleSlot> slots; unsigned char unknown_04[12]; } K2aHandleTable;
extern K2aHandleTable w3d_handle_table_804273ec;
void w3d_handle_update_resource(unsigned int handle);

void k2a_handle_set_position_8003fa90(unsigned int handle, Ptr32<const K2aVec3> position)
{
    Ptr32<K2aHandleSlot> slot = (Ptr32<K2aHandleSlot>)((Ptr32<char>)w3d_handle_table_804273ec.slots + (handle << 5));
    slot->position = *position;
    w3d_handle_update_resource(handle);
}

}
