#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_node_cleanup_backend.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_node_registry.h"
/* Original entry 802075a0. The absent-registry path has no side effects. */
void w3d_actor_node_cleanup_backend(Ptr32<ActorOwnerNode> node)
{
    if (w3d_actor_node_registry)
        w3d_actor_registry_remove(w3d_actor_node_registry, node);
}
#ifdef __cplusplus
}
#endif

}
