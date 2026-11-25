#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
ActorBaseStorage *w3d_actor_base_initialize(ActorBaseStorage *actor)
{
    w3d_actor_reference_initialize(actor);
    actor->base.methods = (void *)w3d_actor_base_methods;
    return actor;
}
#ifdef __cplusplus
}
#endif
