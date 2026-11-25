/* Preserve member destruction order and reload later fields after callbacks. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_destruction.h"
extern const unsigned char w3d_concrete_actor_methods[];
extern void w3d_system_release(void *);
static inline void release_owned(ActorOwnedObject *object)
{
    if (object != 0)
        object->methods->release(object);
}
void w3d_concrete_actor_delete(ConcreteActor *base, int flags)
{
    ConcreteActorStorage *actor = (ConcreteActorStorage *)base;
    int i;
    base->methods = (void *)w3d_concrete_actor_methods;
    release_owned(actor->owned_54c[1]);
    release_owned(actor->owned_54c[0]);
    if (actor->buffer_540 != 0)
        w3d_system_release(actor->buffer_540);
    for (i = 9; i >= 0; --i)
        release_owned(actor->owned_4c0[i]);
    for (i = 2; i >= 0; --i)
        release_owned(actor->owned_4a8[i]);
    w3d_actor_member_optional_delete(actor->member_480, 2);
    w3d_actor_handle_member_destroy(&actor->member_478, 2);
    for (i = 73; i >= 0; --i)
        release_owned(actor->owned_350[i]);
    for (i = 3; i >= 0; --i)
        release_owned(actor->owned_320[i]);
    for (i = 5; i >= 0; --i)
        release_owned(actor->owned_218[i]);
    w3d_actor_method_member_destroy(&actor->member_160, 2);
    release_owned(actor->owned_f4);
    w3d_actor_method_member_destroy(&actor->member_1c, 2);
    w3d_actor_base_destroy(base, (unsigned int)flags);
}
#ifdef __cplusplus
}
#endif
