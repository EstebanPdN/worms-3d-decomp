#ifndef W3D_ACTOR_BASE_CLEANUP_H
#define W3D_ACTOR_BASE_CLEANUP_H
#include "actor_member_cleanup.h"
typedef struct ActorBaseStorage ActorBaseStorage;
typedef struct ActorChildNode {
    Ptr32<struct ActorChildNode> next; Ptr32<struct ActorChildNode> previous;
    Ptr32<ActorBaseStorage> parent;
    Ptr32<void> unknown_0c;
} ActorChildNode;
struct ActorBaseStorage {
    ConcreteActor base;
    unsigned char unknown_14[4];
    Ptr32<ActorChildNode> children;
};
extern const unsigned char w3d_actor_reference_methods[];
extern const unsigned char w3d_actor_node_methods[];
void w3d_actor_child_unlink(Ptr32<ActorChildNode>, Ptr32<Ptr32<ActorChildNode>>);
unsigned int w3d_actor_child_remove(Ptr32<ActorBaseStorage>, Ptr32<ActorChildNode>);
void w3d_actor_child_detach(Ptr32<ActorChildNode>);
void w3d_actor_node_destroy(Ptr32<ActorOwnerNode>, unsigned int);
void w3d_actor_node_cleanup_backend(Ptr32<ActorOwnerNode>);
void w3d_task_array_release_backend(Ptr32<void>);
#endif
