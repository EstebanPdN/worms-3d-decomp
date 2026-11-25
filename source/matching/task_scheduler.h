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
    TaskEvent *begin, *end;
    void *unknown_08;
    TaskEvent *limit;
    unsigned char compare_tag;
    unsigned char unknown_11[3];
} TaskHeap;
typedef struct TaskReady {
    ActorHandle *begin, *end;
    void *unknown_08;
    ActorHandle *limit;
} TaskReady;
typedef struct TaskGroup {
    TaskHeap *pending;
    TaskReady *ready;
    ActorTable *actors;
} TaskGroup;
typedef struct TaskTable {
    ActorTable actor_table;
    unsigned int next_time, current_time;
    TaskGroup groups[3];
    unsigned int deferred_count, deferred_capacity;
    Actor **deferred_objects;
} TaskTable;
void w3d_task_groups_run(TaskGroup *, unsigned int, unsigned int);
void w3d_task_table_set_current_time(TaskTable *, unsigned int);
void w3d_task_table_set_next_time(TaskTable *, unsigned int);
void w3d_task_heap_push(TaskEvent *, TaskEvent *, const unsigned char *);
void w3d_task_heap_pop(TaskEvent *, TaskEvent *, const unsigned char *);
void *w3d_task_ready_move(void *, const void *, unsigned long);
extern unsigned int w3d_task_debug_enabled;
void w3d_task_debug_hook(EngineContext *);
void w3d_task_deferred_clear(void *);
void *w3d_system_allocate(unsigned long);
void *w3d_allocation_failure(unsigned long);
void w3d_system_release(void *);
int w3d_task_scheduler_step(EngineContext *, unsigned int *);
#endif
