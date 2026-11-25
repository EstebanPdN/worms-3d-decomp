#ifdef __cplusplus
extern "C" {
#endif
#include "actor_member_cleanup.h"
void w3d_actor_base_destroy(ActorBasePrefix *actor, unsigned int flags)
{
    actor->methods = (void *)w3d_actor_base_methods;
    w3d_actor_base_cleanup_backend(actor, flags);
}
#ifdef __cplusplus
}
#endif
