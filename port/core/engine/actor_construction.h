#ifndef W3D_ACTOR_CONSTRUCTION_H
#define W3D_ACTOR_CONSTRUCTION_H
#include "actor_base_cleanup.h"

/* Observed initialization prefixes; sizes are not complete allocation claims. */
typedef struct ActorMethodStorage {
    ActorMethodMember base;
    unsigned char state;
} ActorMethodStorage;
typedef struct ActorHandleStorage {
    ActorHandleMember base;
    unsigned int unknown_04;
} ActorHandleStorage;
typedef struct ActorVector3 { float x, y, z; } ActorVector3;
typedef struct ActorConstructionPrefix {
    unsigned char unknown_00[0x130];
    unsigned int unknown_130, unknown_134;
} ActorConstructionPrefix;
extern const unsigned char w3d_actor_method_lower_methods[];
Ptr32<ActorBaseStorage> w3d_actor_reference_initialize(Ptr32<ActorBaseStorage>);
Ptr32<ActorBaseStorage> w3d_actor_base_initialize(Ptr32<ActorBaseStorage>);
Ptr32<ActorMethodStorage> w3d_actor_method_initialize_backend(Ptr32<ActorMethodStorage>);
Ptr32<ActorMethodStorage> w3d_actor_method_member_initialize(Ptr32<ActorMethodStorage>);
unsigned int w3d_handle_create(unsigned int);
Ptr32<ActorHandleMember> w3d_actor_handle_member_initialize(Ptr32<ActorHandleMember>);
void w3d_handle_set_slot_word(unsigned int, unsigned int);
void w3d_handle_set_bounds(unsigned int, Ptr32<const ActorVector3>, float);
void w3d_actor_handle_member_set_word(Ptr32<ActorHandleStorage>, unsigned int);
void w3d_actor_handle_member_set_slot_word(Ptr32<ActorHandleMember>, unsigned int);
void w3d_actor_handle_member_set_bounds(Ptr32<ActorHandleMember>, Ptr32<const ActorVector3>, float);
void w3d_actor_reset_construction_words(Ptr32<ActorConstructionPrefix>);
#endif
