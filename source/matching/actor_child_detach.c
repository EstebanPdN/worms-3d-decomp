#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_child_detach(ActorChildNode *node)
{
    if (node->parent != 0)
        w3d_actor_child_remove(node->parent, node);
    node->parent = 0;
}
#ifdef __cplusplus
}
#endif
