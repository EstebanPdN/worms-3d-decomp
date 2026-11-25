#include "w3d_ptr.h"
#line 1 "native_slot_lifecycle.cpp"
/* Reference ABI observations only; shared state and lifetime ownership external. */
typedef unsigned int u32;
struct Slot { u32 key; Ptr32<void> object; u32 count; u32 flags; };
extern "C" {
extern Slot w3d_shared_slots[80];
extern u32 w3d_slots_initialized;
extern Ptr32<Slot> w3d_slots_clear(Ptr32<Slot>);
extern void w3d_slots_destroy(Ptr32<Slot>,u32);
extern void w3d_slot_shutdown_callback();
extern int w3d_register_shutdown(Ptr32<void (void)>);
extern void w3d_actor_member_delete_backend(Ptr32<void>);
Ptr32<Slot> w3d_slots_shared()
{
    if (!w3d_slots_initialized) {
        w3d_slots_clear(w3d_shared_slots);
        w3d_slots_initialized=1;
        w3d_register_shutdown(w3d_slot_shutdown_callback);
    }
    return w3d_shared_slots;
}
void w3d_slot_shutdown_callback()
{
    w3d_slots_destroy(w3d_shared_slots,2);
}
void w3d_slots_destroy(Ptr32<Slot> slots,u32 flags)
{
    if (flags&1) w3d_actor_member_delete_backend(slots);
}
}


