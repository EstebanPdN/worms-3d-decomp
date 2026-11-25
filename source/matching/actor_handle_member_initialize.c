#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
ActorHandleMember *w3d_actor_handle_member_initialize(ActorHandleMember *member)
{
    member->handle = (unsigned short)w3d_handle_create(0);
    return member;
}
#ifdef __cplusplus
}
#endif
