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
    Ptr32<const void> methods;
} ActorMethodMember;
typedef ConcreteActor ActorBasePrefix;
struct W3dHeapCore;
typedef struct W3dHeap { Ptr32<struct W3dHeapCore> core; } W3dHeap;
extern W3dHeap w3d_actor_member_heap;
extern const unsigned char w3d_actor_member_methods[];
extern const unsigned char w3d_actor_base_methods[];
void w3d_actor_member_delete_backend(Ptr32<void>);
void w3d_actor_handle_cleanup_backend(unsigned int);
void w3d_actor_method_cleanup_backend(Ptr32<ActorMethodMember>, unsigned int);
void w3d_actor_base_cleanup_backend(Ptr32<ActorBasePrefix>, unsigned int);
void w3d_heap_release(Ptr32<W3dHeap>, Ptr32<void>);
void w3d_actor_member_optional_delete(Ptr32<void>, unsigned int);
void w3d_actor_handle_member_destroy(Ptr32<ActorHandleMember>, unsigned int);
void w3d_actor_method_member_destroy(Ptr32<ActorMethodMember>, unsigned int);
void w3d_actor_base_destroy(Ptr32<ActorBasePrefix>, unsigned int);
#endif
