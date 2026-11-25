#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_node_destroy.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_node_destroy(Ptr32<ActorOwnerNode> node, unsigned int flags)
{
    if (node->unknown_04 & 0xffffff00u)
        w3d_actor_node_cleanup_backend(node);
    if (flags & 1)
        w3d_actor_member_delete_backend(node);
}
#ifdef __cplusplus
}
#endif

}
