/* Due-event scheduling, reconstructed from GWMP8P 0x8034af90.
 * Native heap ordering and final allocation backends remain dependencies.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "task_scheduler.h"

void w3d_task_groups_run(TaskGroup *groups, unsigned int count, unsigned int time)
{
    w3d_engine_get_context()->phase = 1;
    while (w3d_engine_get_context()->stopped == 0) {
        unsigned int selected = 3, best_time = ~0u, index;
        TaskGroup *group;
        TaskHeap *heap;
        TaskEvent event;
        ActorRecord *record = 0;
        for (index = 0; index < count; ++index) {
            TaskHeap *candidate = groups[index].pending;
            if (candidate->begin != candidate->end &&
                candidate->begin->time <= time &&
                candidate->begin->time < best_time) {
                selected = index;
                best_time = candidate->begin->time;
            }
        }
        /* Three is the original sentinel, even if the caller supplies count. */
        if (selected == 3)
            break;
        group = &groups[selected];
        heap = group->pending;
        event = *heap->begin;
        w3d_task_heap_pop(heap->begin, heap->end, &heap->compare_tag);
        --heap->end;
        if (event.handle != ~0u) {
            ActorRecord *candidate = &group->actors->records[event.handle & 0xfffu];
            if (candidate->handle == event.handle)
                record = candidate;
        }
        if (record != 0) {
            Actor *actor = record->object;
            int result;
            w3d_task_table_set_current_time((TaskTable *)group->actors, event.time);
            result = actor->methods->run(actor, event.time);
            if (w3d_engine_get_context()->stopped != 0) {
                w3d_task_table_set_next_time((TaskTable *)group->actors, event.time);
                time = event.time;
            }
            if (result == 0) {
                TaskReady *ready = group->ready;
                if (ready->end == ready->limit) {
                    unsigned int used = ready->end - ready->begin;
                    unsigned int capacity = used + (used ? used : 1u);
                    ActorHandle *buffer = (ActorHandle *)w3d_system_allocate(capacity * sizeof(ActorHandle));
                    ActorHandle *write;
                    if (buffer == 0)
                        buffer = (ActorHandle *)w3d_allocation_failure(capacity * sizeof(ActorHandle));
                    write = buffer;
                    if (used != 0)
                        write = (ActorHandle *)w3d_task_ready_move(buffer, ready->begin, used * sizeof(ActorHandle)) + used;
                    *write++ = event.handle;
                    if (ready->begin != 0)
                        w3d_system_release(ready->begin);
                    ready->begin = buffer;
                    ready->end = write;
                    ready->limit = buffer + capacity;
                } else {
                    *ready->end++ = event.handle;
                }
            } else if (result != -1) {
                /* Keep the heap captured before the actor callback. */
                event.time += (unsigned int)result;
                if (heap->end == heap->limit) {
                    unsigned int used = heap->end - heap->begin;
                    unsigned int capacity = used + (used ? used : 1u);
                    TaskEvent *buffer = (TaskEvent *)w3d_system_allocate(capacity * sizeof(TaskEvent));
                    TaskEvent *write = buffer, *read;
                    if (buffer == 0)
                        write = buffer = (TaskEvent *)w3d_allocation_failure(capacity * sizeof(TaskEvent));
                    for (read = heap->begin; read != heap->end; ++read, ++write)
                        *write = *read;
                    *write++ = event;
                    if (heap->begin != 0)
                        w3d_system_release(heap->begin);
                    heap->begin = buffer;
                    heap->end = write;
                    heap->limit = buffer + capacity;
                } else {
                    *heap->end++ = event;
                }
                w3d_task_heap_push(heap->begin, heap->end, &heap->compare_tag);
            }
        }
        if (w3d_task_debug_enabled != 0)
            w3d_task_debug_hook(w3d_engine_context);
    }
    w3d_engine_get_context()->phase = 0;
}
#ifdef __cplusplus
}
#endif
