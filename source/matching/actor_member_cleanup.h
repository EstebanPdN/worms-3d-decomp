#ifndef W3D_ACTOR_MEMBER_CLEANUP_H
#define W3D_ACTOR_MEMBER_CLEANUP_H
/* Observed fields only; complete embedded object types are not yet recovered. */
#include "actor_ownership.h"
typedef struct ActorHandleMember {
    unsigned short unknown_00;
    unsigned short handle;
} ActorHandleMember;
typedef struct ActorMethodMember {
    unsigned char unknown_00[0x24];
    const void *methods;
} ActorMethodMember;
typedef ConcreteActor ActorBasePrefix;
struct W3dHeapCore;
typedef struct W3dHeap { struct W3dHeapCore *core; } W3dHeap;
extern W3dHeap w3d_actor_member_heap;
extern const unsigned char w3d_actor_member_methods[];
extern const unsigned char w3d_actor_base_methods[];
void w3d_actor_member_delete_backend(void *);
void w3d_actor_handle_cleanup_backend(unsigned int);
void w3d_actor_method_cleanup_backend(ActorMethodMember *, unsigned int);
void w3d_actor_base_cleanup_backend(ActorBasePrefix *, unsigned int);
void w3d_heap_release(W3dHeap *, void *);
void w3d_actor_member_optional_delete(void *, unsigned int);
void w3d_actor_handle_member_destroy(ActorHandleMember *, unsigned int);
void w3d_actor_method_member_destroy(ActorMethodMember *, unsigned int);
void w3d_actor_base_destroy(ActorBasePrefix *, unsigned int);
#endif
