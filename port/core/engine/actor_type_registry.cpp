#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_type_registry.c"
/* Intrusive instance links are stored four bytes into each actor prefix. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_dispatch.h"

Ptr32<Actor> w3d_actor_type_first(Ptr32<ActorType> type)
{
    Ptr32<void> link = type->first_link;
    return link == 0 ? 0 : w3d::R((Ptr32<Actor>)((Ptr32<unsigned char>)link - 4));
}

Ptr32<Actor> w3d_actor_type_next(Ptr32<ActorType> type, Ptr32<Actor> actor)
{
    Ptr32<void> link = actor->next_link;
    (void)type;
    return link == 0 ? 0 : w3d::R((Ptr32<Actor>)((Ptr32<unsigned char>)link - 4));
}

Ptr32<ActorType> w3d_actor_types_first(void)
{
    return w3d_actor_type_registry;
}
#ifdef __cplusplus
}
#endif

}
