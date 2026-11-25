#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_child_detach.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_child_detach(Ptr32<ActorChildNode> node)
{
    if (node->parent != 0)
        w3d_actor_child_remove(node->parent, node);
    node->parent = 0;
}
#ifdef __cplusplus
}
#endif

}
