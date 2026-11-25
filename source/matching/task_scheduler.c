/* Native task scheduler step, reconstructed from GWMP8P 0x8016393c.
 * Target layouts are 32-bit and big-endian. Heap ordering, due-event dispatch
 * and deferred reference release remain original native dependencies in the
 * isolated verification harness; this file does not recover those bodies.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "task_scheduler.h"
#include "message_arena.h"

int w3d_task_scheduler_step(EngineContext *manager, unsigned int *time)
{
    TaskTable *table = (TaskTable *)manager->actors;
    TaskMessageEntry *entry, *end;
    unsigned int rounded, group_index;

    *time -= table->actor_table.time_bias;
    entry = (TaskMessageEntry *)table->actor_table.queue_primary->begin;
    end = (TaskMessageEntry *)table->actor_table.queue_primary->end;
    w3d_actor_queue_exchange(&table->actor_table);
    while (entry != end) {
        unsigned int packed = entry->packed_message;
        void *message = (void *)(packed & ~3u);
        int descendants = (packed & 3u) >> 1;
        if (packed & 1u)
            w3d_message_broadcast_type(&table->actor_table, message,
                                      (ActorType *)entry->recipient, descendants);
        else
            w3d_actor_table_deliver(&table->actor_table, message,
                                   entry->recipient, descendants);
        ++entry;
    }
    /* Message payloads stay live through delivery of the captured queue. */
    w3d_message_arena_checkpoint(w3d_message_storage);
    w3d_task_groups_run(table->groups, 3, *time);
    if (table->groups[1].pending->begin == table->groups[1].pending->end &&
        table->groups[0].pending->begin == table->groups[0].pending->end) {
        table->current_time = *time;
        w3d_engine_context->current_time = *time;
    }
    rounded = ((*time + 19u) / 20u) * 20u;
    table->next_time = rounded;
    w3d_engine_context->next_time = rounded;

    /* The original runs ready groups 0 and 2, in this order. */
    for (group_index = 0; group_index < 3; group_index += 2) {
        TaskGroup *group = &table->groups[group_index];
        TaskReady *ready;
        unsigned int index = 0;
        w3d_engine_get_context()->phase = 2;
        ready = group->ready;
        if (ready != 0) {
            while (ready->begin + index != ready->end) {
                ActorHandle handle = ready->begin[index];
                ActorRecord *record = 0;
                if (handle != ~0u) {
                    ActorRecord *candidate = &group->actors->records[handle & 0xfffu];
                    if (candidate->handle == handle)
                        record = candidate;
                }
                if (record == 0) {
                    ready->begin[index] = ready->end[-1];
                    --ready->end;
                } else {
                    Actor *actor = record->object;
                    int result = actor->methods->run(actor, rounded);
                    if (result == 0) {
                        ++index;
                    } else {
                        TaskHeap *heap;
                        TaskEvent event;
                        ready->begin[index] = ready->end[-1];
                        --ready->end;
                        if (result == -1)
                            continue;
                        heap = group->pending;
                        event.handle = handle;
                        event.time = rounded + (unsigned int)result;
                        if (heap->end == heap->limit) {
                            unsigned int count = heap->end - heap->begin;
                            unsigned int capacity = count + (count ? count : 1u);
                            TaskEvent *buffer = (TaskEvent *)w3d_system_allocate(capacity * sizeof(TaskEvent));
                            TaskEvent *write = buffer;
                            TaskEvent *read;
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
            }
        }
        w3d_engine_get_context()->phase = 0;
    }
    /* Callbacks may have replaced the manager's actor table. */
    w3d_task_deferred_clear(&((TaskTable *)manager->actors)->deferred_count);
    return 0;
}
#ifdef __cplusplus
}
#endif
