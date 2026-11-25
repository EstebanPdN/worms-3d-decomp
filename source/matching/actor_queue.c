/* Swap queue cursors, then reset only the new primary queue's end. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_dispatch.h"
void w3d_actor_queue_exchange(ActorTable *table)
{
    ActorQueueCursor *next = table->queue_secondary;
    ActorQueueCursor *previous = table->queue_primary;
    table->queue_primary = next;
    table->queue_secondary = previous;
    next->end = next->begin;
}
#ifdef __cplusplus
}
#endif
