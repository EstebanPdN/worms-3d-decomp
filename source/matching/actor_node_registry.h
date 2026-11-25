#ifndef W3D_ACTOR_NODE_REGISTRY_H
#define W3D_ACTOR_NODE_REGISTRY_H
#include "actor_member_cleanup.h"

/* Observed registry prefixes and virtual-slot offsets; names are inferred. */
typedef struct ActorRegistryEntry {
    void *value;
} ActorRegistryEntry;
typedef struct ActorRegistryObserver ActorRegistryObserver;
typedef struct ActorRegistryObserverMethods {
    void *unknown_00[7];
    const void *(*type)(ActorRegistryObserver *);
    void *unknown_20[3];
    int (*contains)(ActorRegistryObserver *, ActorOwnerNode *);
    void (*remove)(ActorRegistryObserver *, ActorOwnerNode *, unsigned int);
} ActorRegistryObserverMethods;
struct ActorRegistryObserver {
    ActorRegistryObserverMethods *methods;
};
typedef struct ActorNodeRegistry {
    unsigned char unknown_00[0x14];
    unsigned int observer_count, unknown_18;
    ActorRegistryObserver **observers;
    unsigned int unknown_20;
    unsigned int *entries;
    unsigned int unknown_28[2];
    unsigned int free_head;
} ActorNodeRegistry;

extern ActorNodeRegistry *w3d_actor_node_registry;
extern W3dHeap w3d_actor_registry_value_heap, w3d_actor_registry_entry_heap;
extern const unsigned char w3d_actor_registry_observer_type[];
void w3d_actor_registry_entry_clear(ActorRegistryEntry *);
void w3d_actor_registry_remove(ActorNodeRegistry *, ActorOwnerNode *);
void w3d_actor_node_cleanup_backend(ActorOwnerNode *);
#endif
