#ifndef W3D_REFERENCE_ACTOR_OWNERSHIP_H
#define W3D_REFERENCE_ACTOR_OWNERSHIP_H
/* Observed native prefixes. Unknown fields remain unnamed storage. */
enum { W3D_OWNER_NEXT, W3D_OWNER_PREVIOUS };
typedef struct ActorOwnerNode {
    unsigned short references, unknown_02;
    unsigned int unknown_04;
    Ptr32<struct ActorOwnerNode> links[2];
} ActorOwnerNode;
typedef struct ConcreteActor {
    Ptr32<void> methods;
    ActorOwnerNode ownership;
} ConcreteActor;
typedef struct ActorLifetimeType {
    unsigned char unknown_00[0x20];
    unsigned short live_instances; unsigned short w3d_flags_high;
    unsigned char unknown_24[8];
    Ptr32<ActorOwnerNode> first;
} ActorLifetimeType;
extern ActorLifetimeType w3d_concrete_actor_descriptor;
Ptr32<ActorLifetimeType> w3d_concrete_actor_type(Ptr32<ConcreteActor>);
unsigned short w3d_concrete_actor_acquire(Ptr32<ConcreteActor>);
unsigned short w3d_concrete_actor_release(Ptr32<ConcreteActor>);
void w3d_concrete_actor_unlink(Ptr32<ConcreteActor>);
void w3d_concrete_actor_delete(Ptr32<ConcreteActor>, int);
void w3d_owner_list_remove(Ptr32<ActorLifetimeType>, Ptr32<ActorOwnerNode>);
#endif
