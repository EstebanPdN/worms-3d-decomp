#include "w3d_ptr.h"
#line 1 "s5_ballistic_messages.cpp"
/* Ballistic message scheduling and owner-slot reporting. */
extern "C" {
struct S5BallisticMessageActor { unsigned char reserved[20]; int id; unsigned char reserved24[336]; int slot,owner; unsigned time; int pending; };
extern Ptr32<void> w3d_message_pool_804b1754;
extern int w3d_event_state_804b17a0;
Ptr32<void> w3d_message_allocate_801613f0(Ptr32<void>,unsigned);
Ptr32<void> w3d_ballistic_message_init_800e7c78(Ptr32<void>,int,int,unsigned,Ptr32<void>,Ptr32<void>,Ptr32<void>);
int w3d_pool_release_800c56b8(int);
int w3d_pool_schedule_800c53a0(Ptr32<void>,unsigned);
void w3d_message_dispatch(Ptr32<void>,int,int);
Ptr32<void> w3d_auto_8003a264(Ptr32<void>,int,int);
int w3d_message_post_current(Ptr32<void>);
void w3d_ballistic_schedule_800d8ed8(Ptr32<S5BallisticMessageActor> actor,int message_id,int delay,Ptr32<void> first,Ptr32<void> second,Ptr32<void> third)
{
    unsigned when=actor->time+delay;
    Ptr32<void> message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,52);
    message=w3d_ballistic_message_init_800e7c78(message,message_id,actor->id,when,first,second,third);
    if(actor->pending!=65535) w3d_pool_release_800c56b8(actor->pending);
    if(delay>0) actor->pending=w3d_pool_schedule_800c53a0(message,when);
    else w3d_message_dispatch(message,actor->id,0);
}
int w3d_ballistic_post_owner_slot_800d8f8c(Ptr32<S5BallisticMessageActor> actor)
{
    Ptr32<void> message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_auto_8003a264(message,actor->slot,actor->owner));
    return !w3d_event_state_804b17a0;
}
}


