struct K7bTask;
struct K7bTaskVtable { void *slots[3]; void (*retain)(struct K7bTask *self); void (*release)(struct K7bTask *self); };
struct K7bTask { struct K7bTaskVtable *vtable; };
struct K7bTaskPool { int count; int granule; struct K7bTask **items; int head; };
struct K7bTaskOwner { char pad[120]; struct K7bTask **tasks; };
extern void w3d_k5b_task_pool_reserve_801f29d0(struct K7bTaskPool *self, int needed);
void w3d_k7b_task_owner_append_801acdd4(struct K7bTaskOwner *self, struct K7bTask *task)
{
    struct K7bTaskPool *pool = (struct K7bTaskPool *)self->tasks - 1;
    struct K7bTask **slot;
    w3d_k5b_task_pool_reserve_801f29d0(pool, pool->count + 1);
    slot = (struct K7bTask **)((pool->count << 2) + (int)pool->items);
    if (task != 0)
        task->vtable->retain(task);
    if (*slot != 0)
        (*slot)->vtable->release(*slot);
    *slot = task;
    pool->count++;
}
