#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_node_destroy(ActorOwnerNode *node, unsigned int flags)
{
    if (node->unknown_04 & 0xffffff00u)
        w3d_actor_node_cleanup_backend(node);
    if (flags & 1)
        w3d_actor_member_delete_backend(node);
}
#ifdef __cplusplus
}
#endif
