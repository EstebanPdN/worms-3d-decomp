/* Observed cached-message subscription setup and deferred posting. */
extern "C" {
struct W3dS1Subscription { unsigned int unknown;const char *name;unsigned int result,token;unsigned int message[2];unsigned int unknown18,enabled; };
struct W3dS1SubscriptionContext { char unknown[52];unsigned int tick; };
struct W3dS1SubscriptionMessage { unsigned short id,reserved;void *vtable; };
extern void *w3d_queue_804b1754;
extern unsigned char w3d_vtable_8040db38[];
void * w3d_string_default(const char **);
void w3d_string_assign(const char **,const char *);
void * w3d_fn_8015f704(void *,void *);
unsigned int w3d_cached_message_id(void *,int);
int w3d_fn_80162024(void *,unsigned short *,unsigned int *);
W3dS1SubscriptionContext *w3d_engine_get_context(void);
W3dS1SubscriptionMessage *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_fn_800c53a0(void *,unsigned int);
W3dS1Subscription *w3d_fn_8005ff48(W3dS1Subscription *self,void *name,void *owner)
{
    struct { unsigned short id; } local;
    w3d_string_default(&self->name);
    self->token=0;
    unsigned int *message=self->message;
    w3d_fn_8015f704(message,name);
    unsigned int *token=&self->token;
    local.id=w3d_cached_message_id(message,1);
    w3d_fn_80162024(owner,&local.id,token);
    self->enabled=1;
    return self;
}
unsigned int w3d_fn_8005ffc8(W3dS1Subscription *self,const char *name,unsigned int delay)
{
    w3d_string_assign(&self->name,name);
    unsigned int time=w3d_engine_get_context()->tick+delay;
    W3dS1SubscriptionMessage *message=w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(self->message,1);
    message->vtable=w3d_vtable_8040db38;
    unsigned int result=w3d_fn_800c53a0(message,time);
    self->enabled=0;
    self->result=result;
    return result;
}
}
