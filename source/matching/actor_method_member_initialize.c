#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
ActorMethodStorage *w3d_actor_method_member_initialize(ActorMethodStorage *member)
{
    w3d_actor_method_initialize_backend(member);
    member->base.methods = w3d_actor_member_methods;
    member->state = 15;
    return member;
}
#ifdef __cplusplus
}
#endif
