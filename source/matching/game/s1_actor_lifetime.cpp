/* Actor component construction, owned interfaces, and outgoing notifications. */
extern "C" {
struct W3dS1ActorRef;
struct W3dS1ActorVtable { void (*unused[4])(); void (*release)(W3dS1ActorRef *); };
struct W3dS1ActorRef { W3dS1ActorVtable *vtable; };
struct W3dS1ActorString { char *text; };
struct W3dS1ActorId { unsigned short id,padding; const char *name; };
extern unsigned char w3d_vtable_8040e9b8[];
extern const float w3d_f32_80376e30[],w3d_f32_80376e34[],w3d_f32_80376e38[];
extern void *w3d_queue_804b1754;
extern W3dS1ActorId w3d_id_804ad368,w3d_id_804ad348;
void w3d_actor_base_initialize(void *);
void w3d_actor_base_destroy(void *,int);
void w3d_actor_handle_member_initialize(void *);
void w3d_actor_handle_member_destroy(void *,int);
void w3d_string_default(W3dS1ActorString *);
void w3d_string_base_finish(W3dS1ActorString *);
void w3d_string_release(W3dS1ActorString *);
void *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(W3dS1ActorId *,int);
void *w3d_fn_801190b4(void *,unsigned short,unsigned int);
void *w3d_message_string_init(void *,unsigned short,void *);
int w3d_message_post_current(void *);
static inline void release_actor_ref(unsigned int value)
{
    W3dS1ActorRef *ref=(W3dS1ActorRef *)value;
    if(ref)ref->vtable->release(ref);
}
#if 0 /* Unmatched constructor instruction scheduling and register allocation. */
unsigned int *w3d_fn_8004971c(unsigned int *self)
{
    w3d_actor_base_initialize(self);
    self[0]=(unsigned int)w3d_vtable_8040e9b8;
    w3d_string_default((W3dS1ActorString *)(self+0x25));
    self[44]=0;
    self[45]=0;
    self[46]=0;
    self[49]=0;
    self[50]=0;
    self[51]=0;
    self[52]=0;
    self[53]=0;
    self[54]=0;
    self[55]=0;
    self[56]=0;
    self[57]=0;
    self[58]=0;
    w3d_actor_handle_member_initialize(self+0x3b);
    *(float *)(self+0x26)=w3d_f32_80376e30[0];
    self[0x40]=1;
    *(float *)(self+0x45)=w3d_f32_80376e34[0];
    *(float *)(self+0x2a)=w3d_f32_80376e38[0];
    self[43]=0;
    self[25]=0;
    self[26]=0;
    self[47]=0;
    self[48]=0;
    self[36]=0;
    self[62]=0;
    self[61]=0;
    self[33]=0;
    self[40]=0;
    self[39]=0;
    self[0x29]=1;self[0x3f]=1;
    *(float *)(self+0x44)=w3d_f32_80376e34[0];
    return self;
}
#endif
void w3d_fn_80049804(unsigned int *self,int flags)
{
    self[0]=(unsigned int)w3d_vtable_8040e9b8;
    release_actor_ref(self[0x3d]);
    w3d_actor_handle_member_destroy(self+0x3b,2);
    release_actor_ref(self[58]);
    release_actor_ref(self[57]);
    release_actor_ref(self[56]);
    release_actor_ref(self[55]);
    release_actor_ref(self[54]);
    release_actor_ref(self[53]);
    release_actor_ref(self[52]);
    release_actor_ref(self[51]);
    release_actor_ref(self[50]);
    release_actor_ref(self[49]);
    release_actor_ref(self[46]);
    release_actor_ref(self[45]);
    release_actor_ref(self[44]);
    W3dS1ActorString *name=(W3dS1ActorString *)(self+0x25);
    w3d_string_base_finish(name);
    w3d_string_release(name);
    w3d_actor_base_destroy(self,flags);
}
void w3d_fn_8004a38c(unsigned int *self)
{
    release_actor_ref(self[0x3d]);
    self[0x3d]=0;
    void *message=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id=w3d_cached_message_id(&w3d_id_804ad368,1);
    w3d_message_post_current(w3d_fn_801190b4(message,id,self[0x14/4]));
}
void w3d_fn_8004a930(void *self,void *text)
{
    void *message=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id=w3d_cached_message_id(&w3d_id_804ad348,1);
    w3d_message_post_current(w3d_message_string_init(message,id,text));
}
}
