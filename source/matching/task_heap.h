#ifndef W3D_REFERENCE_TASK_HEAP_H
#define W3D_REFERENCE_TASK_HEAP_H
#include "task_scheduler.h"
Actor *w3d_heap_actor_from_handle(ActorHandle);
const char *w3d_heap_actor_type_name(ActorType *);
int w3d_heap_name_compare(const char *, const char *);
void w3d_task_heap_adjust(TaskEvent *, int, int, const TaskEvent *, const unsigned char *);

/* Match the native comparator's ordering and callback order. The global actor
 * table is deliberately looked up again for each comparison. */
static __inline__ int w3d_task_event_later(TaskEvent left, TaskEvent right)
{
    Actor *a, *b;
    const char *a_name, *b_name;
    if (left.time != right.time)
        return right.time < left.time;
    a = w3d_heap_actor_from_handle(left.handle);
    b = w3d_heap_actor_from_handle(right.handle);
    if (a == 0 || b == 0)
        return a != 0;
    a_name = w3d_heap_actor_type_name(a->methods->type(a));
    b_name = w3d_heap_actor_type_name(b->methods->type(b));
    return w3d_heap_name_compare(a_name, b_name) == 1;
}
#endif
