#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "s3_runtime_metrics.c"
/* Runtime pause controls and a rolling history of elapsed ticks. */
typedef Ptr32<void (Ptr32<void>)> Method;
typedef struct Interface {Ptr32<Method> vtable;} Interface;
typedef struct Owner {unsigned char pad00[68];Ptr32<Interface> service;unsigned char pad48[92-72];int locks;Ptr32<Interface> core; Ptr32<Interface> context; Ptr32<Interface> input; Ptr32<Interface> renderer; Ptr32<Interface> output;int value,total;} Owner;
typedef struct Context {unsigned char pad00[56];int paused;} Context;
typedef struct Name {int id;Ptr32<const char> name;} Name;
typedef struct Sample {int count;float duration;} Sample;
typedef struct History {Ptr32<Sample> samples;int size,count;float duration;int cursor,previous;unsigned int tick;int frame;} History;
typedef struct Text {Ptr32<char> data;} Text;
typedef struct TextOwner {Ptr32<Text> begin; Ptr32<Text> end; Ptr32<Text> capacity;int capacity_pad;Ptr32<Interface> first; Ptr32<Interface> second; Ptr32<Interface> third;float a,b,c,d,e,f;unsigned short limit;} TextOwner;
typedef struct Handle {Ptr32<Interface> service;struct {unsigned int rest:11; unsigned int mode:5; unsigned int byte:8; unsigned int enabled:1; unsigned int kind:7;} flags;} Handle;
extern Ptr32<Context> w3d_engine_get_context(void);
extern Name w3d_name_804b0060,w3d_name_804b006c,w3d_name_804b0078;
extern int w3d_init_804b0068,w3d_init_804b0074,w3d_init_804b0080;
extern const char w3d_str_803a43d4[],w3d_str_803a43e4[],w3d_str_803a43f0[];
extern const float w3d_f32_803a4418[],w3d_f32_803a441c[],w3d_f32_803a4430[],w3d_f32_803a4434[],w3d_f32_803a4438[];
extern void w3d_name_construct_801fc790(Ptr32<Name>,Ptr32<const char>);
extern unsigned int w3d_clock_801fe45c(void);
extern Ptr32<void> w3d_heap_allocate_entry_b(unsigned int);
extern void w3d_task_array_release(Ptr32<void>);
extern void w3d_string_base_finish(Ptr32<Text>),w3d_string_release(Ptr32<Text>);
extern void w3d_handle_storage_release(Ptr32<void>),w3d_actor_member_delete_backend(Ptr32<void>);
extern Ptr32<Interface> w3d_service_80208aac(int);
void w3d_history_reset(Ptr32<History>);
void w3d_history_record(Ptr32<History>,int,float);
#if 0 /* Elapsed-time temporary register allocation differs after three attempts. */
void w3d_runtime_update_services(Owner *owner,int delta)
{
 int elapsed;Context *context;
 if(!w3d_init_804b0068){w3d_name_construct_801fc790(&w3d_name_804b0060,w3d_str_803a43d4);w3d_init_804b0068=1;}
 if(!w3d_init_804b0074){w3d_name_construct_801fc790(&w3d_name_804b006c,w3d_str_803a43e4);w3d_init_804b0074=1;}
 if(!w3d_init_804b0080){w3d_name_construct_801fc790(&w3d_name_804b0078,w3d_str_803a43f0);w3d_init_804b0080=1;}
 context=w3d_engine_get_context();elapsed=delta;if(context->paused)elapsed=0;
 owner->total+=elapsed;
 if(owner->renderer)((void (*)(void *,int))owner->renderer->vtable[7])(owner->renderer,delta);
 ((void (*)(void *,int *))owner->core->vtable[8])(owner->core,&owner->total);
}
#endif
void w3d_runtime_reset_time(Ptr32<Owner> owner,int time)
{
 ((Ptr32<void (Ptr32<void>, int)>)owner->core->vtable[9])(owner->core,time);owner->total=time;
}
void w3d_runtime_pause_retain(Ptr32<Owner> owner)
{
 owner->locks++;owner->core->vtable[10](owner->core);
}
void w3d_runtime_pause_release(Ptr32<Owner> owner)
{
 if(--owner->locks<=0){owner->core->vtable[11](owner->core);owner->locks=0;}
}
int w3d_runtime_is_paused(Ptr32<Owner> owner)
{
 if(owner->locks>0)return 1;return w3d_engine_get_context()->paused;
}
void w3d_runtime_service_request(Ptr32<Owner> owner,int value)
{
 ((Ptr32<void (Ptr32<void>, int)>)owner->service->vtable[21])(owner->service,value);
}
void w3d_runtime_service_bind_view(Ptr32<Owner> owner,int value,Ptr32<void> view)
{
 ((Ptr32<void (Ptr32<void>, int, Ptr32<void>)>)owner->service->vtable[20])(owner->service,value,view);
}
void w3d_history_tick(Ptr32<History> history)
{
 unsigned int now;
 history->frame++;
 now=w3d_clock_801fe45c();
 w3d_history_record(history,history->frame,(float)(now-history->tick));
 history->tick=now;
}
Ptr32<History> w3d_history_construct(Ptr32<History> history)
{
 history->samples=0;history->size=0;history->cursor=0;w3d_history_reset(history);return history;
}
#if 0 /* Count comparison and loop-counter setup scheduling differ after three attempts. */
void w3d_history_resize(History *history,int count)
{
 Sample *samples,*item;int left;float zero;
 if(history->samples)w3d_task_array_release(history->samples);
 samples=w3d_heap_allocate_entry_b(count*8);item=samples;
 if(count){left=count-1;zero=*w3d_f32_803a4418;do{item->count=0;item->duration=zero;item++;}while(left--!=0);}
 history->size=count;history->samples=samples;w3d_history_reset(history);
}
#endif
#if 0 /* Float-load placement and final-store scheduling differ after three attempts. */
void w3d_history_reset(History *history)
{
 int index;
 if(history->samples){float zero=*w3d_f32_803a441c;for(index=0;index<history->size;index++){history->samples[index].duration=zero;history->samples[index].count=0;}}
 history->cursor=0;history->duration=*w3d_f32_803a441c;history->previous=-1;history->count=0;
}
#endif
#if 0 /* Two adjacent count-delta setup instructions differ after three attempts. */
void w3d_history_record(History *history,int count,float duration)
{
 Sample *samples=history->samples;int delta,index;unsigned int previous;
 Sample *slot;
 if(samples){
 previous=history->previous;delta=count-previous;if(previous==-1)delta=0;
 index=history->cursor;slot=(Sample *)(index*8+(unsigned int)samples);
 history->duration=history->duration-slot->duration+duration;
 history->count=history->count-((Sample *)(index*8+(unsigned int)samples))->count+delta;
 slot->duration=duration;history->samples[history->cursor].count=delta;
 if(++history->cursor>=history->size)history->cursor=0;
 history->previous=count;
 }
}
#endif
#if 0 /* Frame and vector initialization layout differ after three attempts. */
TextOwner *w3d_text_owner_construct(TextOwner *owner)
{
 float zero;Interface *service;
 owner->begin=0;owner->end=0;owner->capacity_pad=0;zero=*w3d_f32_803a4434;
 owner->third=0;owner->c=*w3d_f32_803a4430;owner->first=0;owner->second=0;
 owner->f=*w3d_f32_803a4438;owner->d=zero;owner->e=*w3d_f32_803a4438;
 service=w3d_service_80208aac(0);if(service)service->vtable[3](service);
 if(owner->third)owner->third->vtable[4](owner->third);owner->third=service;
 ((void (*)(void *,int))service->vtable[8])(service,2048);
 ((void (*)(void *,int))owner->third->vtable[8])(owner->third,0);
 owner->b=zero;owner->limit=12;owner->a=zero;return owner;
}
#endif
void w3d_text_owner_destroy(Ptr32<TextOwner> owner,int flags)
{
 Ptr32<Text> item; Ptr32<Text> end;
 if(owner->third)owner->third->vtable[4](owner->third);
 if(owner->second)owner->second->vtable[4](owner->second);
 if(owner->first)owner->first->vtable[4](owner->first);
 end=owner->end;for(item=owner->begin;item!=end;item++){w3d_string_base_finish(item);w3d_string_release(item);}
 if(owner->begin)w3d_handle_storage_release(owner->begin);
 if(flags&1)w3d_actor_member_delete_backend(owner);
}
Ptr32<Handle> w3d_text_owner_make_handle(Ptr32<Handle> handle,Ptr32<TextOwner> owner)
{
 Ptr32<Interface> service=owner->third;handle->service=service;if(service)service->vtable[3](service);
 handle->flags.kind=10;handle->flags.enabled=0;handle->flags.byte=0;handle->flags.mode=6;
 return handle;
}

}
