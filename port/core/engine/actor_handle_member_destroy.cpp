#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_handle_member_destroy.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_member_cleanup.h"
void w3d_actor_handle_member_destroy(Ptr32<ActorHandleMember> member, unsigned int flags)
{
    w3d_actor_handle_cleanup_backend(member->handle);
    if (flags & 1)
        w3d_heap_release(&w3d_actor_member_heap, member);
}
#ifdef __cplusplus
}
#endif

}
