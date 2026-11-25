#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_method_member_destroy.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_member_cleanup.h"
void w3d_actor_method_member_destroy(Ptr32<ActorMethodMember> member, unsigned int flags)
{
    member->methods = w3d_actor_member_methods;
    w3d_actor_method_cleanup_backend(member, flags);
}
#ifdef __cplusplus
}
#endif

}
