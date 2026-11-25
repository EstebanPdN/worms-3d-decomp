/* Inferred names/types reconstructed from original GameCube instructions.
 * Original entries: 8003fbb8 (slot word), 8003fa2c (position/radius).
 * The unsigned 32-bit handle is not narrowed to the wrappers' u16 storage.
 */
extern "C" {
#include "actor_construction.h"
}
struct RecoveredHandleSlot {
    ActorVector3 position;
    float radius, radius_squared;
    unsigned int slot_word, unknown_18;
    void *resource;
};
struct RecoveredHandleTable { RecoveredHandleSlot *slots; unsigned char unknown_04[12]; };
inline RecoveredHandleSlot &handle_slot(RecoveredHandleSlot *base, unsigned int i) { return *(base + i); }
extern "C" {
extern RecoveredHandleTable w3d_handle_table;
void w3d_handle_update_resource(unsigned int handle);
void w3d_handle_set_slot_word(unsigned int handle, unsigned int word)
{
    handle_slot(w3d_handle_table.slots, handle).slot_word = word;
}
void w3d_handle_set_bounds(unsigned int handle, const ActorVector3 *position, float radius)
{
    handle_slot(w3d_handle_table.slots, handle).position = *position;
    handle_slot(w3d_handle_table.slots, handle).radius = radius;
    handle_slot(w3d_handle_table.slots, handle).radius_squared = radius * radius;
    w3d_handle_update_resource(handle);
}
}
