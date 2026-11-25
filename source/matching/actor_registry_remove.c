#ifdef __cplusplus
extern "C" {
#endif
#include "actor_node_registry.h"
/* Original entry 802075d4. Capture the range, index and slot before callbacks;
   re-read the current observer after its type callback, as the native body does. */
void w3d_actor_registry_remove(ActorNodeRegistry *registry, ActorOwnerNode *node)
{
    unsigned short index = (unsigned short)(node->unknown_04 >> 8);
    ActorRegistryObserver **cursor = registry->observers;
    ActorRegistryObserver **end = cursor + registry->observer_count;
    unsigned int *slot = index + registry->entries;
    while (cursor != end) {
        if ((*cursor)->methods->type(*cursor) == w3d_actor_registry_observer_type) {
            ActorRegistryObserver *observer = *cursor;
            if (observer->methods->contains(observer, node) == 0)
                observer->methods->remove(observer, node, 0);
        }
        ++cursor;
    }
    w3d_actor_registry_entry_clear((ActorRegistryEntry *)*slot);
    *slot = registry->free_head;
    registry->free_head = index;
}
#ifdef __cplusplus
}
#endif
