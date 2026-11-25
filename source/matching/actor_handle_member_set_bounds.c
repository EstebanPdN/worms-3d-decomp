#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
void w3d_actor_handle_member_set_bounds(ActorHandleMember *member, const ActorVector3 *position, float radius)
{
    w3d_handle_set_bounds(member->handle, position, radius);
}
#ifdef __cplusplus
}
#endif
