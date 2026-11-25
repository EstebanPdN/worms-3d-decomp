/* Actor insertion, reconstructed from GWMP8P 0x80164514..0x80164aa8.
 * Parent handles and free-list heads must identify live, available records.
 * System allocation failure, final actor methods and notification are native
 * dependencies. The original does not supply safe defaults for invalid input.
 */
#ifdef __cplusplus
extern "C" {
#endif
#include "actor_registration.h"

static __inline__ RegistrationMethods *ownership(Actor *actor)
{
    return (RegistrationMethods *)actor->methods;
}
static __inline__ int registration_kind(ActorType *type, ActorType *target)
{
    for (;;) {
        ActorType *parent;
        if (type == target)
            return 1;
        parent = type->parent;
        if (parent == type)
            return 0;
        type = parent;
    }
}

ActorHandle w3d_actor_register(EngineContext *context, Actor *actor,
                              ActorHandle parent_handle)
{
    TaskTable *table = (TaskTable *)context->actors;
    RegistrationRecord *parent = 0, *record;
    ActorIndex *free_heads = (ActorIndex *)table->actor_table.unknown_08;
    unsigned int group, category, previous_phase;
    if (parent_handle != ~0u) {
        RegistrationRecord *candidate = &((RegistrationRecord *)table->actor_table.records)[parent_handle & 0xfffu];
        if (candidate->handle == parent_handle)
            parent = candidate;
    }
    w3d_engine_get_context();
    w3d_heap_actor_type_name(actor->methods->type(actor));
    category = (((RegistrationType *)actor->methods->type(actor))->attributes >> 16) & 15u;
    group = category == 10 ? 0u : category == 11 ? 1u : 2u;
    record = &((RegistrationRecord *)table->actor_table.records)[free_heads[group]];
    free_heads[group] = record->next_sibling;
    record->unknown_00 = 0;
    record->unknown_04 = 0;
    record->first_child = 0;
    record->unknown_08 = 0;
    record->next_sibling = 0;
    if (record->object != 0)
        ownership(record->object)->release(record->object);
    record->flags = 0;
    record->object = 0;
    record->parent = 0;
    record->next_sibling = parent->first_child;
    parent->first_child = record->handle & 0xfffu;
    if (actor != 0)
        ownership(actor)->acquire(actor);
    /* Acquisition may populate the destination again. Read it after the call. */
    if (record->object != 0)
        ownership(record->object)->release(record->object);
    record->object = actor;
    record->parent = parent_handle & 0xfffu;
    if (group < 2) {
        TaskEvent event;
        TaskHeap *heap = table->groups[group].pending;
        unsigned char tag;
        event.handle = record->handle;
        event.time = table->current_time;
        if (heap->end == heap->limit) {
            TaskEvent *old_end = heap->end;
            unsigned int used = old_end - heap->begin;
            unsigned int capacity = used + (used ? used : 1u);
            TaskEvent *buffer = (TaskEvent *)w3d_system_allocate(capacity * sizeof(TaskEvent));
            TaskEvent *write, *read;
            if (buffer == 0)
                buffer = (TaskEvent *)w3d_allocation_failure(capacity * sizeof(TaskEvent));
            write = buffer;
            for (read = heap->begin; read != old_end; ++read, ++write)
                if (write != 0)
                    *write = *read;
            if (write != 0)
                *write = event;
            ++write;
            if (heap->begin != 0)
                w3d_system_release(heap->begin);
            heap->begin = buffer;
            heap->end = write;
            heap->limit = buffer + capacity;
        } else {
            if (heap->end != 0)
                *heap->end = event;
            ++heap->end;
        }
        tag = heap->compare_tag;
        w3d_task_heap_push(heap->begin, heap->end, &tag);
    } else {
        ActorHandle handle = record->handle;
        TaskReady *ready = table->groups[group].ready;
        if (ready->end == ready->limit) {
            ActorHandle *old_end = ready->end;
            unsigned int used = old_end - ready->begin;
            unsigned int capacity = used + (used ? used : 1u);
            ActorHandle *buffer = (ActorHandle *)w3d_system_allocate(capacity * sizeof(ActorHandle));
            ActorHandle *write;
            if (buffer == 0)
                buffer = (ActorHandle *)w3d_allocation_failure(capacity * sizeof(ActorHandle));
            write = buffer;
            if (old_end != ready->begin) {
                unsigned int live_used = old_end - ready->begin;
                write = (ActorHandle *)w3d_task_ready_move(buffer, ready->begin, live_used * sizeof(ActorHandle)) + live_used;
            }
            *write++ = handle;
            if (ready->begin != 0)
                w3d_system_release(ready->begin);
            ready->begin = buffer;
            ready->limit = buffer + capacity;
            ready->end = write;
        } else {
            if (ready->end != 0)
                *ready->end = handle;
            ++ready->end;
        }
    }
    previous_phase = w3d_engine_get_context()->phase;
    if (registration_kind(actor->methods->type(actor), &w3d_registration_phase4))
        w3d_engine_get_context()->phase = 4;
    else if (registration_kind(actor->methods->type(actor), &w3d_registration_phase3))
        w3d_engine_get_context()->phase = 3;
    else if (registration_kind(actor->methods->type(actor), &w3d_registration_phase5))
        w3d_engine_get_context()->phase = 5;
    w3d_actor_registration_notify(table, record, 0);
    w3d_engine_get_context()->phase = previous_phase;
    return record->handle;
}
#ifdef __cplusplus
}
#endif
