#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_base_cleanup_backend(ActorBasePrefix *prefix, unsigned int flags)
{
    ActorBaseStorage *actor = (ActorBaseStorage *)prefix;
    actor->base.methods = (void *)w3d_actor_reference_methods;
    while (actor->children != 0)
        w3d_actor_child_detach(actor->children);
    actor->base.methods = (void *)w3d_actor_node_methods;
    w3d_actor_node_destroy(&actor->base.ownership, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(actor);
}
#ifdef __cplusplus
}
#endif
