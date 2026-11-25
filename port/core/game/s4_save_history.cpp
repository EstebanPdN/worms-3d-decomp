#include "w3d_ptr.h"
#line 1 "s4_save_history.cpp"
extern "C" {
struct S4HistoryQueue { Ptr32<int> current; Ptr32<int> end; int unknown[2]; };
struct S4SaveHistory { unsigned char pad[64]; int active,value; unsigned char first[20],second[20]; Ptr32<char> firstName; Ptr32<char> secondName; S4HistoryQueue queue; };
void w3d_history_leave_8028e8ec(Ptr32<void>);
int w3d_name_remove_800c47f8(Ptr32<void>,Ptr32<const char>);
void w3d_history_queue_push_8035f0cc(Ptr32<void>,Ptr32<int>);
void w3d_s4_save_history_remove(Ptr32<S4SaveHistory> self)
{
    if(self->active==1) {
        w3d_history_leave_8028e8ec(self);
        w3d_name_remove_800c47f8(self->first,self->secondName);
        w3d_name_remove_800c47f8(self->second,self->firstName);
        Ptr32<S4HistoryQueue> queue=&self->queue;
        Ptr32<int> current=queue->current;
        Ptr32<int> value=&self->value;
        if(current!=queue->end) {
            if(current!=(Ptr32<int>)w3d::G(4)) current[-1]=*value;
            --queue->current;
        } else w3d_history_queue_push_8035f0cc(queue,value);
    }
}
}


