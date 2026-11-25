/* Intrusive instance links are stored four bytes into each actor prefix. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_dispatch.h"

Actor *w3d_actor_type_first(ActorType *type)
{
    void *link = type->first_link;
    return link == 0 ? 0 : (Actor *)((unsigned char *)link - 4);
}

Actor *w3d_actor_type_next(ActorType *type, Actor *actor)
{
    void *link = actor->next_link;
    (void)type;
    return link == 0 ? 0 : (Actor *)((unsigned char *)link - 4);
}

ActorType *w3d_actor_types_first(void)
{
    return w3d_actor_type_registry;
}
#ifdef __cplusplus
}
#endif
