/* Remove an intrusive actor node without inventing membership checks. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_ownership.h"
void w3d_owner_list_remove(ActorLifetimeType *type, ActorOwnerNode *node)
{
    ActorOwnerNode **links = node->links;
    ActorOwnerNode *next = links[W3D_OWNER_NEXT];
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
