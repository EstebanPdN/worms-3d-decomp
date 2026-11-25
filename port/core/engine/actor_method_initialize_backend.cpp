#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_method_initialize_backend.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
Ptr32<ActorMethodStorage> w3d_actor_method_initialize_backend(Ptr32<ActorMethodStorage> member)
{
    member->base.methods = w3d_actor_method_lower_methods;
    return member;
}
#ifdef __cplusplus
}
#endif

}
