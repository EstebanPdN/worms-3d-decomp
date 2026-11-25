#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_method_member_initialize.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
Ptr32<ActorMethodStorage> w3d_actor_method_member_initialize(Ptr32<ActorMethodStorage> member)
{
    w3d_actor_method_initialize_backend(member);
    member->base.methods = w3d_actor_member_methods;
    member->state = 15;
    return member;
}
#ifdef __cplusplus
}
#endif

}
