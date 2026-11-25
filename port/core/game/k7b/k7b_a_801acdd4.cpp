#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k7b_a_801acdd4.c"
struct K7bTask;
struct K7bTaskVtable { Ptr32<void> slots[3]; Ptr32<void (Ptr32<struct K7bTask>)> retain; Ptr32<void (Ptr32<struct K7bTask>)> release; };
struct K7bTask { Ptr32<struct K7bTaskVtable> vtable; };
struct K7bTaskPool { int count; int granule; Ptr32<Ptr32<struct K7bTask>> items; int head; };
struct K7bTaskOwner { char pad[120]; Ptr32<Ptr32<struct K7bTask>> tasks; };
extern void w3d_k5b_task_pool_reserve_801f29d0(Ptr32<struct K7bTaskPool> self, int needed);
void w3d_k7b_task_owner_append_801acdd4(Ptr32<struct K7bTaskOwner> self, Ptr32<struct K7bTask> task)
{
    Ptr32<struct K7bTaskPool> pool = (Ptr32<struct K7bTaskPool>)self->tasks - 1;
    Ptr32<Ptr32<struct K7bTask>> slot;
    w3d_k5b_task_pool_reserve_801f29d0(pool, pool->count + 1);
    slot = (Ptr32<Ptr32<struct K7bTask>>)w3d::G(((pool->count << 2) + (int)w3d::H(pool->items)));
    if (task != 0)
        task->vtable->retain(task);
    if (*slot != 0)
        (*slot)->vtable->release(*slot);
    *slot = task;
    pool->count++;
}

}
