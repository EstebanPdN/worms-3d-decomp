#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
unsigned int w3d_actor_child_remove(ActorBaseStorage *parent, ActorChildNode *node)
{
    w3d_actor_child_unlink(node, &parent->children);
    return 0;
}
#ifdef __cplusplus
}
#endif
