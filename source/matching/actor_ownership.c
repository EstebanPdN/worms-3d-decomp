/* Ownership of the concrete class whose original vtable is80410f00.
 * The deleting destructor remains an explicit dependency.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_ownership.h"

ActorLifetimeType *w3d_concrete_actor_type(ConcreteActor *actor)
{
    (void)actor;
    return &w3d_concrete_actor_descriptor;
}

void w3d_concrete_actor_unlink(ConcreteActor *actor)
{
    w3d_owner_list_remove(&w3d_concrete_actor_descriptor, &actor->ownership);
    --w3d_concrete_actor_descriptor.live_instances;
}

unsigned short w3d_concrete_actor_release(ConcreteActor *actor)
{
    unsigned short remaining = --actor->ownership.references;
    if (remaining == 0) {
        w3d_concrete_actor_unlink(actor);
        if (actor != 0)
            w3d_concrete_actor_delete(actor, 3);
    }
    return remaining;
}

unsigned short w3d_concrete_actor_acquire(ConcreteActor *actor)
{
    unsigned short previous = actor->ownership.references++;
    return previous;
}
#ifdef __cplusplus
}
#endif
