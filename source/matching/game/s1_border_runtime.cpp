/* Observed border-effect construction and completion messages. */
extern "C" {
struct W3dS1BorderContext { char unknown[184];float factor; };
struct W3dS1BorderMessage { unsigned short id,reserved;void *vtable; };
struct W3dS1Border { void *vtable;char unknown4[24];unsigned int token,off,ready;void *border,*height,*on_time,*off_time;unsigned int end_tick,duration;float width,height_value,base; };
extern W3dS1BorderContext *w3d_context_804b1788;
extern void *w3d_queue_804b1754;
extern unsigned char w3d_vtable_8040ed80[],w3d_message_vtable_8040db38[];
extern unsigned int w3d_message_804ad530,w3d_message_804ad540;
extern const float w3d_f32_80379b00[],w3d_f32_80379b04[],w3d_f32_80379b08[],w3d_f32_80379b0c[],w3d_f32_80379b10[];
extern const char w3d_str_80379b78[];
void w3d_ctor_8015fef0(void *);
int w3d_fn_800fc43c(const char **,int);
W3dS1BorderMessage *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(void *,int);
int w3d_message_post_current(void *);
#if 0 /* Excluded: floating-point allocation and constant scheduling remain different after three attempts. */
W3dS1Border *w3d_fn_80062c24(W3dS1Border *self)
{
    w3d_ctor_8015fef0(self);
    self->vtable=w3d_vtable_8040ed80;
    self->token=0;self->border=0;self->height=0;self->on_time=0;self->off_time=0;
    float complement=w3d_f32_80379b00[0]-w3d_context_804b1788->factor;
    float factor=w3d_context_804b1788->factor;
    float top=factor*w3d_f32_80379b0c[0]+complement*w3d_f32_80379b10[0];
    self->height_value=top;
    float remainder=complement*w3d_f32_80379b08[0];
    self->width=factor*w3d_f32_80379b04[0]+remainder;
    self->base=top-w3d_f32_80379b10[0];
    return self;
}
#endif
static inline void post_border(unsigned int *id)
{
    W3dS1BorderMessage *message=w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(id,1);message->vtable=w3d_message_vtable_8040db38;
    w3d_message_post_current(message);
}
void w3d_fn_80063434(void *unused)
{
    struct { const char *key;unsigned int unknown; } local;
    local.key=w3d_str_80379b78;w3d_fn_800fc43c(&local.key,0);
    post_border(&w3d_message_804ad530);post_border(&w3d_message_804ad540);
}
}
