#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_base_destroy.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_member_cleanup.h"
void w3d_actor_base_destroy(Ptr32<ActorBasePrefix> actor, unsigned int flags)
{
    actor->methods = (Ptr32<void>)w3d_actor_base_methods;
    w3d_actor_base_cleanup_backend(actor, flags);
}
#ifdef __cplusplus
}
#endif

}
