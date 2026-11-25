#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_base_cleanup.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
void w3d_actor_base_cleanup_backend(Ptr32<ActorBasePrefix> prefix, unsigned int flags)
{
    Ptr32<ActorBaseStorage> actor = (Ptr32<ActorBaseStorage>)prefix;
    actor->base.methods = (Ptr32<void>)w3d_actor_reference_methods;
    while (actor->children != 0)
        w3d_actor_child_detach(actor->children);
    actor->base.methods = (Ptr32<void>)w3d_actor_node_methods;
    w3d_actor_node_destroy(&actor->base.ownership, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(actor);
}
#ifdef __cplusplus
}
#endif

}
