#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "actor_queue.c"
/* Swap queue cursors, then reset only the new primary queue's end. */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_dispatch.h"
void w3d_actor_queue_exchange(Ptr32<ActorTable> table)
{
    Ptr32<ActorQueueCursor> next = table->queue_secondary;
    Ptr32<ActorQueueCursor> previous = table->queue_primary;
    table->queue_primary = next;
    table->queue_secondary = previous;
    next->end = next->begin;
}
#ifdef __cplusplus
}
#endif

}
