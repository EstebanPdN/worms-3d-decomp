#ifndef W3D_REFERENCE_TASK_SCHEDULER_H
#define W3D_REFERENCE_TASK_SCHEDULER_H
#include "actor_dispatch.h"
typedef struct TaskEvent {
    ActorHandle handle;
    unsigned int time;
} TaskEvent;
typedef struct TaskMessageEntry {
    unsigned int packed_message, recipient;
} TaskMessageEntry;
typedef struct TaskHeap {
    Ptr32<TaskEvent> begin; Ptr32<TaskEvent> end;
    Ptr32<void> unknown_08;
    Ptr32<TaskEvent> limit;
    unsigned char compare_tag;
    unsigned char unknown_11[3];
} TaskHeap;
typedef struct TaskReady {
    Ptr32<ActorHandle> begin; Ptr32<ActorHandle> end;
    Ptr32<void> unknown_08;
    Ptr32<ActorHandle> limit;
} TaskReady;
typedef struct TaskGroup {
    Ptr32<TaskHeap> pending;
    Ptr32<TaskReady> ready;
    Ptr32<ActorTable> actors;
} TaskGroup;
typedef struct TaskTable {
    ActorTable actor_table;
    unsigned int next_time, current_time;
    TaskGroup groups[3];
    unsigned int deferred_count, deferred_capacity;
    Ptr32<Ptr32<Actor>> deferred_objects;
} TaskTable;
void w3d_task_groups_run(Ptr32<TaskGroup>, unsigned int, unsigned int);
void w3d_task_table_set_current_time(Ptr32<TaskTable>, unsigned int);
void w3d_task_table_set_next_time(Ptr32<TaskTable>, unsigned int);
void w3d_task_heap_push(Ptr32<TaskEvent>, Ptr32<TaskEvent>, Ptr32<const unsigned char>);
void w3d_task_heap_pop(Ptr32<TaskEvent>, Ptr32<TaskEvent>, Ptr32<const unsigned char>);
Ptr32<void> w3d_task_ready_move(Ptr32<void>, Ptr32<const void>, unsigned int);
extern unsigned int w3d_task_debug_enabled;
void w3d_task_debug_hook(Ptr32<EngineContext>);
void w3d_task_deferred_clear(Ptr32<void>);
Ptr32<void> w3d_system_allocate(unsigned int);
Ptr32<void> w3d_allocation_failure(unsigned int);
void w3d_system_release(Ptr32<void>);
int w3d_task_scheduler_step(Ptr32<EngineContext>, Ptr32<unsigned int>);
#endif
