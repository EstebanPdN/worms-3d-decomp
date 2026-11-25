#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_registry_remove.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_node_registry.h"
/* Original entry 802075d4. Capture the range, index and slot before callbacks;
   re-read the current observer after its type callback, as the native body does. */
void w3d_actor_registry_remove(Ptr32<ActorNodeRegistry> registry, Ptr32<ActorOwnerNode> node)
{
    unsigned short index = (unsigned short)(node->unknown_04 >> 8);
    if (index == 0) return;
    Ptr32<Ptr32<ActorRegistryObserver>> cursor = registry->observers;
    Ptr32<Ptr32<ActorRegistryObserver>> end = cursor + registry->observer_count;
    Ptr32<unsigned int> slot = index + registry->entries;
    while (cursor != end) {
        if ((*cursor)->methods->type(*cursor) == w3d_actor_registry_observer_type) {
            Ptr32<ActorRegistryObserver> observer = *cursor;
            if (observer->methods->contains(observer, node) == 0)
                observer->methods->remove(observer, node, 0);
        }
        ++cursor;
    }
    w3d_actor_registry_entry_clear((Ptr32<ActorRegistryEntry>)w3d::G(*slot));
    *slot = registry->free_head;
    registry->free_head = index;
}
#ifdef __cplusplus
}
#endif

}
