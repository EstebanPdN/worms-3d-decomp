/* Original explicit actor-table delivery entry. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_delivery_impl.h"
int w3d_actor_table_deliver(ActorTable *table, void *message,
    ActorHandle recipient, int children)
{
    return dispatch_on_table(table, message, recipient, children);
}
#ifdef __cplusplus
}
#endif
