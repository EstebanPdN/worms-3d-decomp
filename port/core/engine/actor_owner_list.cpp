#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_owner_list.c"
/* Remove an intrusive actor node without inventing membership checks. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_ownership.h"
void w3d_owner_list_remove(Ptr32<ActorLifetimeType> type, Ptr32<ActorOwnerNode> node)
{
    Ptr32<Ptr32<ActorOwnerNode>> links = node->links;
    Ptr32<ActorOwnerNode> next = links[W3D_OWNER_NEXT];
    if (next != 0)
        next->links[W3D_OWNER_PREVIOUS] = links[W3D_OWNER_PREVIOUS];
    if (links[W3D_OWNER_PREVIOUS] != 0)
        links[W3D_OWNER_PREVIOUS]->links[W3D_OWNER_NEXT] = node->links[W3D_OWNER_NEXT];
    else
        type->first = node->links[W3D_OWNER_NEXT];
    node->links[W3D_OWNER_NEXT] = 0;
    node->links[W3D_OWNER_PREVIOUS] = 0;
}
#ifdef __cplusplus
}
#endif

}
