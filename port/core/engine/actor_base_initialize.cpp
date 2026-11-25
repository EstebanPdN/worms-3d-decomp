#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_base_initialize.c"
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_construction.h"
Ptr32<ActorBaseStorage> w3d_actor_base_initialize(Ptr32<ActorBaseStorage> actor)
{
    w3d_actor_reference_initialize(actor);
    actor->base.methods = (Ptr32<void>)w3d_actor_base_methods;
    return actor;
}
#ifdef __cplusplus
}
#endif

}
