#ifndef W3D_ACTOR_NODE_REGISTRY_H
#define W3D_ACTOR_NODE_REGISTRY_H
#include "actor_member_cleanup.h"

/* Observed registry prefixes and virtual-slot offsets; names are inferred. */
typedef struct ActorRegistryEntry {
    Ptr32<void> value;
} ActorRegistryEntry;
typedef struct ActorRegistryObserver ActorRegistryObserver;
typedef struct ActorRegistryObserverMethods {
    Ptr32<void> unknown_00[7];
    Ptr32<Ptr32<const void> (Ptr32<ActorRegistryObserver>)> type;
    Ptr32<void> unknown_20[3];
    Ptr32<int (Ptr32<ActorRegistryObserver>, Ptr32<ActorOwnerNode>)> contains;
    Ptr32<void (Ptr32<ActorRegistryObserver>, Ptr32<ActorOwnerNode>, unsigned int)> remove;
} ActorRegistryObserverMethods;
struct ActorRegistryObserver {
    Ptr32<ActorRegistryObserverMethods> methods;
};
typedef struct ActorNodeRegistry {
    unsigned char unknown_00[0x14];
    unsigned int observer_count, unknown_18;
    Ptr32<Ptr32<ActorRegistryObserver>> observers;
    unsigned int unknown_20;
    Ptr32<unsigned int> entries;
    unsigned int unknown_28[2];
    unsigned int free_head;
} ActorNodeRegistry;

extern Ptr32<ActorNodeRegistry> w3d_actor_node_registry;
extern W3dHeap w3d_actor_registry_value_heap, w3d_actor_registry_entry_heap;
extern const unsigned char w3d_actor_registry_observer_type[];
void w3d_actor_registry_entry_clear(Ptr32<ActorRegistryEntry>);
void w3d_actor_registry_remove(Ptr32<ActorNodeRegistry>, Ptr32<ActorOwnerNode>);
void w3d_actor_node_cleanup_backend(Ptr32<ActorOwnerNode>);
#endif
