#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_handle_member_initialize.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
Ptr32<ActorHandleMember> w3d_actor_handle_member_initialize(Ptr32<ActorHandleMember> member)
{
    member->handle = (unsigned short)w3d_handle_create(0);
    return member;
}
#ifdef __cplusplus
}
#endif

}
