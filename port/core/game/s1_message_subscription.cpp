#include "w3d_ptr.h"
#line 1 "s1_message_subscription.cpp"
/* Observed cached-message subscription setup and deferred posting. */
extern "C" {
struct W3dS1Subscription { unsigned int unknown;Ptr32<const char> name;unsigned int result,token;unsigned int message[2];unsigned int unknown18,enabled; };
struct W3dS1SubscriptionContext { char unknown[52];unsigned int tick; };
struct W3dS1SubscriptionMessage { unsigned short id,reserved;Ptr32<void> vtable; };
extern Ptr32<void> w3d_queue_804b1754;
extern unsigned char w3d_vtable_8040db38[];
Ptr32<void> w3d_string_default(Ptr32<Ptr32<const char>>);
void w3d_string_assign(Ptr32<Ptr32<const char>>,Ptr32<const char>);
Ptr32<void> w3d_fn_8015f704(Ptr32<void>,Ptr32<void>);
unsigned int w3d_cached_message_id(Ptr32<void>,int);
int w3d_fn_80162024(Ptr32<void>,Ptr32<unsigned short>,Ptr32<unsigned int>);
Ptr32<W3dS1SubscriptionContext> w3d_engine_get_context(void);
Ptr32<W3dS1SubscriptionMessage> w3d_fn_801613f0(Ptr32<void>,unsigned int);
unsigned int w3d_fn_800c53a0(Ptr32<void>,unsigned int);
Ptr32<W3dS1Subscription> w3d_fn_8005ff48(Ptr32<W3dS1Subscription> self,Ptr32<void> name,Ptr32<void> owner)
{
    struct { unsigned short id; } local;
    w3d_string_default(&self->name);
    self->token=0;
    Ptr32<unsigned int> message=self->message;
    w3d_fn_8015f704(message,name);
    Ptr32<unsigned int> token=&self->token;
    local.id=w3d_cached_message_id(message,1);
    w3d_fn_80162024(owner,&local.id,token);
    self->enabled=1;
    return self;
}
unsigned int w3d_fn_8005ffc8(Ptr32<W3dS1Subscription> self,Ptr32<const char> name,unsigned int delay)
{
    w3d_string_assign(&self->name,name);
    unsigned int time=w3d_engine_get_context()->tick+delay;
    Ptr32<W3dS1SubscriptionMessage> message=w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(self->message,1);
    message->vtable=w3d_vtable_8040db38;
    unsigned int result=w3d_fn_800c53a0(message,time);
    self->enabled=0;
    self->result=result;
    return result;
}
}


