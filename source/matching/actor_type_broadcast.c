/* Actual list/ancestry traversal; only negative callbacks stop broadcast. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_delivery_impl.h"

int w3d_message_broadcast_type(ActorTable *table, void *message,
    ActorType *type, int descendants)
{
    Actor *actor;
    ActorType *candidate;
    int result;
    (void)table;
    for (actor = w3d_actor_type_first(type); actor != 0;
         actor = w3d_actor_type_next(type, actor)) {
        result = actor->methods->message(actor, message);
        if (result < 0) return result;
    }
    if (descendants != 0) {
        for (candidate = w3d_actor_types_first(); candidate != 0;
             candidate = candidate->next) {
            if (candidate != type && actor_type_derives(candidate, type)) {
                for (actor = w3d_actor_type_first(candidate); actor != 0;
                     actor = w3d_actor_type_next(candidate, actor)) {
                    result = actor->methods->message(actor, message);
                    if (result < 0) return result;
                }
            }
        }
    }
    return 0;
}
#ifdef __cplusplus
}
#endif
