/* Original entry 0x8003fa90. Names and layout inferred from the original
 * instructions and the admitted sibling w3d_handle_set_bounds. */
typedef struct K1bVector3 {
    float x, y, z;
} K1bVector3;

typedef struct K1bHandleSlot {
    K1bVector3 position;
    float radius, radius_squared;
    unsigned int slot_word, unknown_18;
    void *resource;
} K1bHandleSlot;

typedef struct K1bHandleTable {
    K1bHandleSlot *slots;
    unsigned char unknown_04[12];
} K1bHandleTable;

extern K1bHandleTable w3d_handle_table_804273ec;
void w3d_handle_update_resource(unsigned int handle);

void w3d_handle_set_position_8003fa90(unsigned int handle, const K1bVector3 *position)
{
    K1bHandleSlot *slot;

    slot = (K1bHandleSlot *)((char *)w3d_handle_table_804273ec.slots + (handle << 5));
    slot->position = *position;
    w3d_handle_update_resource(handle);
}
