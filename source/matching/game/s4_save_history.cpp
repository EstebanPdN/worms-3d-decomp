extern "C" {
struct S4HistoryQueue { int *current,*end; int unknown[2]; };
struct S4SaveHistory { unsigned char pad[64]; int active,value; unsigned char first[20],second[20]; char *firstName,*secondName; S4HistoryQueue queue; };
void w3d_history_leave_8028e8ec(void *);
int w3d_name_remove_800c47f8(void *,const char *);
void w3d_history_queue_push_8035f0cc(void *,int *);
void w3d_s4_save_history_remove(S4SaveHistory *self)
{
    if(self->active==1) {
        w3d_history_leave_8028e8ec(self);
        w3d_name_remove_800c47f8(self->first,self->secondName);
        w3d_name_remove_800c47f8(self->second,self->firstName);
        S4HistoryQueue *queue=&self->queue;
        int *current=queue->current;
        int *value=&self->value;
        if(current!=queue->end) {
            if(current!=(int *)4) current[-1]=*value;
            --queue->current;
        } else w3d_history_queue_push_8035f0cc(queue,value);
    }
}
}
