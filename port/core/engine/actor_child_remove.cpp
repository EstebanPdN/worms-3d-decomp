#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_child_remove.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_base_cleanup.h"
unsigned int w3d_actor_child_remove(Ptr32<ActorBaseStorage> parent, Ptr32<ActorChildNode> node)
{
    w3d_actor_child_unlink(node, &parent->children);
    return 0;
}
#ifdef __cplusplus
}
#endif

}
