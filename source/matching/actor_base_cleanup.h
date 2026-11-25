#ifndef W3D_ACTOR_BASE_CLEANUP_H
#define W3D_ACTOR_BASE_CLEANUP_H
#include "actor_member_cleanup.h"
typedef struct ActorBaseStorage ActorBaseStorage;
typedef struct ActorChildNode {
    struct ActorChildNode *next, *previous;
    ActorBaseStorage *parent;
    void *unknown_0c;
} ActorChildNode;
struct ActorBaseStorage {
    ConcreteActor base;
    unsigned char unknown_14[4];
    ActorChildNode *children;
};
extern const unsigned char w3d_actor_reference_methods[];
extern const unsigned char w3d_actor_node_methods[];
void w3d_actor_child_unlink(ActorChildNode *, ActorChildNode **);
unsigned int w3d_actor_child_remove(ActorBaseStorage *, ActorChildNode *);
void w3d_actor_child_detach(ActorChildNode *);
void w3d_actor_node_destroy(ActorOwnerNode *, unsigned int);
void w3d_actor_node_cleanup_backend(ActorOwnerNode *);
void w3d_task_array_release_backend(void *);
#endif
