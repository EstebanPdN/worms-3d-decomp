#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
ActorMethodStorage *w3d_actor_method_initialize_backend(ActorMethodStorage *member)
{
    member->base.methods = w3d_actor_method_lower_methods;
    return member;
}
#ifdef __cplusplus
}
#endif
