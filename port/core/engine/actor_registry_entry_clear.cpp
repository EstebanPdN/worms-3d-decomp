#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_registry_entry_clear.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_node_registry.h"
/* Original entry 802074c4; backend callbacks can observe the live entry. */
void w3d_actor_registry_entry_clear(Ptr32<ActorRegistryEntry> entry)
{
    if (entry->value)
        w3d_heap_release(&w3d_actor_registry_value_heap, entry->value);
    entry->value = 0;
    w3d_heap_release(&w3d_actor_registry_entry_heap, entry);
}
#ifdef __cplusplus
}
#endif

}
