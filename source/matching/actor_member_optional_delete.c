#ifdef __cplusplus
extern "C" {
#endif
#include "actor_member_cleanup.h"
void w3d_actor_member_optional_delete(void *member, unsigned int flags)
{
    if (flags & 1)
        w3d_actor_member_delete_backend(member);
}
#ifdef __cplusplus
}
#endif
