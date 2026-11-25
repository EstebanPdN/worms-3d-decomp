#ifdef __cplusplus
extern "C" {
#endif
#include "actor_member_cleanup.h"
void w3d_actor_method_member_destroy(ActorMethodMember *member, unsigned int flags)
{
    member->methods = w3d_actor_member_methods;
    w3d_actor_method_cleanup_backend(member, flags);
}
#ifdef __cplusplus
}
#endif
