#ifdef __cplusplus
extern "C" {
#endif
#include "actor_node_registry.h"
/* Original entry 802074c4; backend callbacks can observe the live entry. */
void w3d_actor_registry_entry_clear(ActorRegistryEntry *entry)
{
    if (entry->value)
        w3d_heap_release(&w3d_actor_registry_value_heap, entry->value);
    entry->value = 0;
    w3d_heap_release(&w3d_actor_registry_entry_heap, entry);
}
#ifdef __cplusplus
}
#endif
