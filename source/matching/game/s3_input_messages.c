/* Input service setup and construction of messages delivered to callbacks. */
typedef void (*Method)(void *);
typedef struct Interface {Method *vtable;} Interface;
typedef struct EntityClass {Method *vtable;unsigned char pad04[8];Method *secondary;} EntityClass;
typedef struct InputOwner {Method *vtable;unsigned char pad04[24];Interface *service;float a,b,c,d,e;} InputOwner;
typedef struct Message {unsigned short id,pad02;void *type;} Message;
typedef struct ToggleMessage {Message base;int key,enabled;} ToggleMessage;
typedef struct ButtonMessage {Message base;int key;unsigned char button,pad0d[3];int enabled;} ButtonMessage;
typedef struct AxisMessage {Message base;int key;unsigned char axis,pad0d[3];float value;} AxisMessage;
typedef struct VectorMessage {Message base;int mode,value;short first,second;unsigned char flag,pad15[3];float x,y,z;} VectorMessage;
extern Method w3d_vtable_80411608[],w3d_vtable_80411630[],w3d_vtable_804116a8[];
extern void w3d_entity_class_base_destroy_8020fc60(EntityClass *,int);
extern void w3d_ctor_801628b0(InputOwner *);
extern InputOwner *w3d_input_804b17f0;
extern const float w3d_f32_803a4650[],w3d_f32_803a4654[],w3d_f32_803a4658[],w3d_f32_803a465c[],w3d_f32_803a4660[];
extern Interface *w3d_lookup_8020b680(void *);
extern unsigned char w3d_object_80418200[],w3d_type_8040db38[];
extern int w3d_values_803fe234[];
extern int w3d_input_handler_80160b7c(void *,Message *),w3d_input_handler_80160cd8(void *,Message *),w3d_input_handler_80160da8(void *,Message *);
extern void *w3d_arena_804b1754;
extern void *w3d_message_allocate_801613f0(void *,int);
extern int w3d_callback_dispatch(void *,void *);
void w3d_entity_class_destroy(EntityClass *owner,int flags)
{
 owner->secondary=w3d_vtable_80411608;owner->vtable=w3d_vtable_80411630;
 w3d_entity_class_base_destroy_8020fc60(owner,flags);
}
static __inline__ void input_defaults(InputOwner *owner,float d,float e,float c,float zero)
{
 owner->vtable=w3d_vtable_804116a8;owner->service=0;w3d_input_804b17f0=owner;
 owner->d=d;owner->e=e;owner->c=c;owner->b=zero;owner->a=zero;
}
#if 0 /* Float-global load scheduling and final-store order differ after three attempts. */
InputOwner *w3d_input_owner_construct(InputOwner *owner)
{
 w3d_ctor_801628b0(owner);
 input_defaults(owner,*w3d_f32_803a4650,*w3d_f32_803a4654,*w3d_f32_803a4658,*w3d_f32_803a465c);
 return owner;
}
#endif

int w3d_input_owner_initialize(InputOwner *owner)
{
 Interface *service=w3d_lookup_8020b680(w3d_object_80418200);
 if(service)service->vtable[3](service);
 if(owner->service)owner->service->vtable[4](owner->service);owner->service=service;
 ((void (*)(void *,int))service->vtable[7])(service,0);
 ((void (*)(void *,void *,int))owner->service->vtable[11])(owner->service,w3d_input_handler_80160b7c,0);
 ((void (*)(void *,void *,int))owner->service->vtable[11])(owner->service,w3d_input_handler_80160cd8,2);
 ((void (*)(void *,void *,int))owner->service->vtable[11])(owner->service,w3d_input_handler_80160da8,1);
 return 0;
}
int w3d_input_owner_poll(InputOwner *owner)
{
 if(owner->service)owner->service->vtable[6](owner->service);return 0;
}
static __inline__ void toggle_initialize(ToggleMessage *message,int key,int enabled)
{message->base.type=w3d_type_8040db38;message->base.id=4096;message->key=key;message->enabled=enabled;}
static __inline__ void button_initialize(ButtonMessage *message,unsigned char button,int key,int enabled)
{message->base.type=w3d_type_8040db38;message->base.id=4098;message->key=key;message->button=button;message->enabled=enabled;}
typedef struct FloatArgument {float value;int unused;} FloatArgument;
static __inline__ FloatArgument axis_argument(float value){FloatArgument arg;arg.value=value;return arg;}
static __inline__ void axis_initialize(AxisMessage *message,unsigned char axis,int key,FloatArgument value)
{message->base.id=4099;message->base.type=w3d_type_8040db38;message->key=key;message->axis=axis;message->value=value.value;}
int w3d_input_key_press(InputOwner *owner,int key)
{
 ToggleMessage *message=w3d_message_allocate_801613f0(w3d_arena_804b1754,16);
 toggle_initialize(message,key,1);
 return w3d_callback_dispatch(owner,message);
}
int w3d_input_key_release(InputOwner *owner,int key)
{
 ToggleMessage *message=w3d_message_allocate_801613f0(w3d_arena_804b1754,16);
 toggle_initialize(message,key,0);
 return w3d_callback_dispatch(owner,message);
}
int w3d_input_button_press(InputOwner *owner,unsigned char button,int key)
{
 ButtonMessage *message=w3d_message_allocate_801613f0(w3d_arena_804b1754,20);
 button_initialize(message,button,key,1);
 return w3d_callback_dispatch(owner,message);
}
int w3d_input_button_release(InputOwner *owner,unsigned char button,int key)
{
 ButtonMessage *message=w3d_message_allocate_801613f0(w3d_arena_804b1754,20);
 button_initialize(message,button,key,0);
 return w3d_callback_dispatch(owner,message);
}
#if 0 /* Eight-byte stack gap is missing after three attempts. */
int w3d_input_axis_value(InputOwner *owner,unsigned char axis,int key,float value)
{
 AxisMessage *message=w3d_message_allocate_801613f0(w3d_arena_804b1754,20);
 axis_initialize(message,axis,key,axis_argument(value));
 return w3d_callback_dispatch(owner,message);
}
#endif
static __inline__ void direction_initialize(VectorMessage *message,int value,float x,float y,float z)
{
 message->base.id=4100;message->base.type=w3d_type_8040db38;message->mode=2;message->value=value;
 message->second=0;message->flag=0;message->x=x;message->y=y;message->z=z;message->first=0;
}
#if 0 /* Field stores and floating-register allocation differ after three attempts. */
int w3d_input_direction_event(InputOwner *owner,int unused,int index)
{
 VectorMessage *message=w3d_message_allocate_801613f0(w3d_arena_804b1754,36);
 direction_initialize(message,w3d_values_803fe234[index],owner->a,owner->b,*w3d_f32_803a4660);
 return w3d_callback_dispatch(owner,message);
}
#endif
