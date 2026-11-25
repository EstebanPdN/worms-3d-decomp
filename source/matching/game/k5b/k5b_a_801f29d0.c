struct K5bTaskPool {
    void *head;
    unsigned short capacity;
    unsigned short granule;
};
extern int fn_801f282c(struct K5bTaskPool *pool, int capacity);
void w3d_k5b_task_pool_reserve_801f29d0(struct K5bTaskPool *self, int needed)
{
    if (self->capacity < needed) {
        int granule = self->granule;
        void *head = self->head;
        fn_801f282c(self, (needed + granule) & -granule);
        self->head = head;
        self->granule <<= 1;
    }
}
// desc: w3d_k5b_task_pool_reserve_801f29d0: Appears to grow a task pool to the needed size rounded up by its granule through 0x801f282c, keeping the head pointer and doubling the granule.
