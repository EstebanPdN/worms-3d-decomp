typedef struct K2aVec3 { float x, y, z; } K2aVec3;
typedef struct K2aHandleSlot {
    K2aVec3 position;
    float radius, radius_squared;
    unsigned int slot_word, unknown_18;
    void *resource;
} K2aHandleSlot;
typedef struct K2aHandleTable { K2aHandleSlot *slots; unsigned char unknown_04[12]; } K2aHandleTable;
extern K2aHandleTable w3d_handle_table_804273ec;
void w3d_handle_update_resource(unsigned int handle);

void k2a_handle_set_position_8003fa90(unsigned int handle, const K2aVec3 *position)
{
    K2aHandleSlot *slot = (K2aHandleSlot *)((char *)w3d_handle_table_804273ec.slots + (handle << 5));
    slot->position = *position;
    w3d_handle_update_resource(handle);
}
