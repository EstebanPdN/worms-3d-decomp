#ifdef __cplusplus
extern "C" {
#endif
#include "actor_member_cleanup.h"
void w3d_actor_handle_member_destroy(ActorHandleMember *member, unsigned int flags)
{
    w3d_actor_handle_cleanup_backend(member->handle);
    if (flags & 1)
        w3d_heap_release(&w3d_actor_member_heap, member);
}
#ifdef __cplusplus
}
#endif
