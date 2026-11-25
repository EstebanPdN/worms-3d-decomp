#ifndef W3D_REFERENCE_ACTOR_OWNERSHIP_H
#define W3D_REFERENCE_ACTOR_OWNERSHIP_H
/* Observed native prefixes. Unknown fields remain unnamed storage. */
enum { W3D_OWNER_NEXT, W3D_OWNER_PREVIOUS };
typedef struct ActorOwnerNode {
    unsigned short references, unknown_02;
    unsigned int unknown_04;
    struct ActorOwnerNode *links[2];
} ActorOwnerNode;
typedef struct ConcreteActor {
    void *methods;
    ActorOwnerNode ownership;
} ConcreteActor;
typedef struct ActorLifetimeType {
    unsigned char unknown_00[0x22];
    unsigned short live_instances;
    unsigned char unknown_24[8];
    ActorOwnerNode *first;
} ActorLifetimeType;
extern ActorLifetimeType w3d_concrete_actor_descriptor;
ActorLifetimeType *w3d_concrete_actor_type(ConcreteActor *);
unsigned short w3d_concrete_actor_acquire(ConcreteActor *);
unsigned short w3d_concrete_actor_release(ConcreteActor *);
void w3d_concrete_actor_unlink(ConcreteActor *);
void w3d_concrete_actor_delete(ConcreteActor *, int);
void w3d_owner_list_remove(ActorLifetimeType *, ActorOwnerNode *);
#endif
