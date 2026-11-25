/* Ballistic message scheduling and owner-slot reporting. */
extern "C" {
struct S5BallisticMessageActor { unsigned char reserved[20]; int id; unsigned char reserved24[336]; int slot,owner; unsigned time; int pending; };
extern void *w3d_message_pool_804b1754;
extern int w3d_event_state_804b17a0;
void *w3d_message_allocate_801613f0(void *,unsigned);
void *w3d_ballistic_message_init_800e7c78(void *,int,int,unsigned,void *,void *,void *);
int w3d_pool_release_800c56b8(int);
int w3d_pool_schedule_800c53a0(void *,unsigned);
void w3d_message_dispatch(void *,int,int);
void *w3d_auto_8003a264(void *,int,int);
int w3d_message_post_current(void *);
void w3d_ballistic_schedule_800d8ed8(S5BallisticMessageActor *actor,int message_id,int delay,void *first,void *second,void *third)
{
    unsigned when=actor->time+delay;
    void *message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,52);
    message=w3d_ballistic_message_init_800e7c78(message,message_id,actor->id,when,first,second,third);
    if(actor->pending!=65535) w3d_pool_release_800c56b8(actor->pending);
    if(delay>0) actor->pending=w3d_pool_schedule_800c53a0(message,when);
    else w3d_message_dispatch(message,actor->id,0);
}
int w3d_ballistic_post_owner_slot_800d8f8c(S5BallisticMessageActor *actor)
{
    void *message=w3d_message_allocate_801613f0(w3d_message_pool_804b1754,12);
    w3d_message_post_current(w3d_auto_8003a264(message,actor->slot,actor->owner));
    return !w3d_event_state_804b17a0;
}
}
