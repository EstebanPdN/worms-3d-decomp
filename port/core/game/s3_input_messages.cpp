#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_input_messages.c"
/* Input service setup and construction of messages delivered to callbacks. */
typedef Ptr32<void (Ptr32<void>)> Method;
typedef struct Interface {Ptr32<Method> vtable;} Interface;
typedef struct EntityClass {Ptr32<Method> vtable;unsigned char pad04[8];Ptr32<Method> secondary;} EntityClass;
typedef struct InputOwner {Ptr32<Method> vtable;unsigned char pad04[24];Ptr32<Interface> service;float a,b,c,d,e;} InputOwner;
typedef struct Message {unsigned short id,pad02;Ptr32<void> type;} Message;
typedef struct ToggleMessage {Message base;int key,enabled;} ToggleMessage;
typedef struct ButtonMessage {Message base;int key;unsigned char button,pad0d[3];int enabled;} ButtonMessage;
typedef struct AxisMessage {Message base;int key;unsigned char axis,pad0d[3];float value;} AxisMessage;
typedef struct VectorMessage {Message base;int mode,value;short first,second;unsigned char flag,pad15[3];float x,y,z;} VectorMessage;
extern Method w3d_vtable_80411608[],w3d_vtable_80411630[],w3d_vtable_804116a8[];
extern void w3d_entity_class_base_destroy_8020fc60(Ptr32<EntityClass>,int);
extern void w3d_ctor_801628b0(Ptr32<InputOwner>);
extern Ptr32<InputOwner> w3d_input_804b17f0;
extern const float w3d_f32_803a4650[],w3d_f32_803a4654[],w3d_f32_803a4658[],w3d_f32_803a465c[],w3d_f32_803a4660[];
extern Ptr32<Interface> w3d_lookup_8020b680(Ptr32<void>);
extern unsigned char w3d_object_80418200[],w3d_type_8040db38[];
extern int w3d_values_803fe234[];
extern int w3d_input_handler_80160b7c(Ptr32<void>,Ptr32<Message>),w3d_input_handler_80160cd8(Ptr32<void>,Ptr32<Message>),w3d_input_handler_80160da8(Ptr32<void>,Ptr32<Message>);
extern Ptr32<void> w3d_arena_804b1754;
extern Ptr32<void> w3d_message_allocate_801613f0(Ptr32<void>,int);
extern int w3d_callback_dispatch(Ptr32<void>,Ptr32<void>);
void w3d_entity_class_destroy(Ptr32<EntityClass> owner,int flags)
{
 owner->secondary=w3d_vtable_80411608;owner->vtable=w3d_vtable_80411630;
 w3d_entity_class_base_destroy_8020fc60(owner,flags);
}
static __inline__ void input_defaults(Ptr32<InputOwner> owner,float d,float e,float c,float zero)
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

int w3d_input_owner_initialize(Ptr32<InputOwner> owner)
{
 Ptr32<Interface> service=w3d_lookup_8020b680(w3d_object_80418200);
 if(service)service->vtable[3](service);
 if(owner->service)owner->service->vtable[4](owner->service);owner->service=service;
 ((Ptr32<void (Ptr32<void>, int)>)service->vtable[7])(service,0);
 ((Ptr32<void (Ptr32<void>, Ptr32<void>, int)>)owner->service->vtable[11])(owner->service,w3d_input_handler_80160b7c,0);
 ((Ptr32<void (Ptr32<void>, Ptr32<void>, int)>)owner->service->vtable[11])(owner->service,w3d_input_handler_80160cd8,2);
 ((Ptr32<void (Ptr32<void>, Ptr32<void>, int)>)owner->service->vtable[11])(owner->service,w3d_input_handler_80160da8,1);
 return 0;
}
int w3d_input_owner_poll(Ptr32<InputOwner> owner)
{
 if(owner->service)owner->service->vtable[6](owner->service);return 0;
}
static __inline__ void toggle_initialize(Ptr32<ToggleMessage> message,int key,int enabled)
{message->base.type=w3d_type_8040db38;message->base.id=4096;message->key=key;message->enabled=enabled;}
static __inline__ void button_initialize(Ptr32<ButtonMessage> message,unsigned char button,int key,int enabled)
{message->base.type=w3d_type_8040db38;message->base.id=4098;message->key=key;message->button=button;message->enabled=enabled;}
typedef struct FloatArgument {float value;int unused;} FloatArgument;
static __inline__ FloatArgument axis_argument(float value){FloatArgument arg;arg.value=value;return arg;}
static __inline__ void axis_initialize(Ptr32<AxisMessage> message,unsigned char axis,int key,FloatArgument value)
{message->base.id=4099;message->base.type=w3d_type_8040db38;message->key=key;message->axis=axis;message->value=value.value;}
int w3d_input_key_press(Ptr32<InputOwner> owner,int key)
{
 Ptr32<ToggleMessage> message=w3d_message_allocate_801613f0(w3d_arena_804b1754,16);
 toggle_initialize(message,key,1);
 return w3d_callback_dispatch(owner,message);
}
int w3d_input_key_release(Ptr32<InputOwner> owner,int key)
{
 Ptr32<ToggleMessage> message=w3d_message_allocate_801613f0(w3d_arena_804b1754,16);
 toggle_initialize(message,key,0);
 return w3d_callback_dispatch(owner,message);
}
int w3d_input_button_press(Ptr32<InputOwner> owner,unsigned char button,int key)
{
 Ptr32<ButtonMessage> message=w3d_message_allocate_801613f0(w3d_arena_804b1754,20);
 button_initialize(message,button,key,1);
 return w3d_callback_dispatch(owner,message);
}
int w3d_input_button_release(Ptr32<InputOwner> owner,unsigned char button,int key)
{
 Ptr32<ButtonMessage> message=w3d_message_allocate_801613f0(w3d_arena_804b1754,20);
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
static __inline__ void direction_initialize(Ptr32<VectorMessage> message,int value,float x,float y,float z)
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

}
