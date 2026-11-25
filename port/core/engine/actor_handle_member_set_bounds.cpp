#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_handle_member_set_bounds.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
void w3d_actor_handle_member_set_bounds(Ptr32<ActorHandleMember> member, Ptr32<const ActorVector3> position, float radius)
{
    w3d_handle_set_bounds(member->handle, position, radius);
}
#ifdef __cplusplus
}
#endif

}
