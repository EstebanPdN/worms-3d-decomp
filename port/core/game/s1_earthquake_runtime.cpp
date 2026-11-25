#include "w3d_ptr.h"
#line 1 "s1_earthquake_runtime.cpp"
/* Observed earthquake impulse timing, startup, and cleanup messages. */
extern "C" {
struct W3dS1QuakeRef;
struct W3dS1QuakeTable { Ptr32<void (void)> unused[4];Ptr32<void (Ptr32<W3dS1QuakeRef>)> release; };
struct W3dS1QuakeRef { Ptr32<W3dS1QuakeTable> vtable; };
struct W3dS1QuakeMessage { unsigned short id,reserved;Ptr32<void> vtable; };
struct W3dS1QuakeContext { char unknown[52];unsigned int tick; };
struct W3dS1QuakeConfig { char unknown[56];unsigned int delay; };
extern Ptr32<void> w3d_queue_804b1754;
extern unsigned int w3d_message_804ad4ec,w3d_message_804ad504,w3d_message_804ad518,w3d_message_804ad520;
extern unsigned char w3d_vtable_8040db38[];
extern const char w3d_str_80379394[],w3d_str_803795c0[];
int w3d_scene_timer_is_one_8006e71c(void);
unsigned int w3d_auto_80161080(Ptr32<void>);
Ptr32<W3dS1QuakeMessage> w3d_fn_801613f0(Ptr32<void>,unsigned int);
unsigned int w3d_cached_message_id(Ptr32<void>,int);
int w3d_message_post_current(Ptr32<void>);
void w3d_fn_800fde64(int);
Ptr32<void> w3d_int_message_init_80125fdc(Ptr32<void>,unsigned short,unsigned int);
int w3d_fn_800fc43c(Ptr32<Ptr32<const char>>,int);
void w3d_auto_8015fd1c(Ptr32<void>);
int w3d_fn_800c56b8(unsigned int);
Ptr32<void> w3d_constructor_lookup_name(Ptr32<Ptr32<const char>>,Ptr32<Ptr32<W3dS1QuakeRef>>);
Ptr32<void> w3d_empty_80341584(Ptr32<void>);
Ptr32<W3dS1QuakeConfig> w3d_auto_801797b4(Ptr32<void>);
Ptr32<W3dS1QuakeContext> w3d_engine_get_context(void);
void w3d_fn_8002ad9c(Ptr32<void>);
static inline void post_quake_message(Ptr32<unsigned int> id)
{
    Ptr32<W3dS1QuakeMessage> message=w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(id,1);message->vtable=w3d_vtable_8040db38;
    w3d_message_post_current(message);
}
unsigned int w3d_fn_800619e4(Ptr32<unsigned int> self)
{
    unsigned int result;
    if(!w3d_scene_timer_is_one_8006e71c()) {
        post_quake_message(&w3d_message_804ad4ec);
        result=w3d_auto_80161080(self)%180+20;
        self[7]=result;
    } else result=self[7];
    return result;
}
void w3d_fn_80061cd4(Ptr32<unsigned int> self)
{
    Ptr32<const char> key;
    w3d_fn_800fde64(500);
    Ptr32<void> message=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned short id=w3d_cached_message_id(&w3d_message_804ad504,1);
    w3d_message_post_current(w3d_int_message_init_80125fdc(message,id,self[10]));
    key=w3d_str_80379394;w3d_fn_800fc43c(&key,0);
    Ptr32<W3dS1QuakeRef> held=(Ptr32<W3dS1QuakeRef>)w3d::G(self[9]);
    if(held)held->vtable->release(held);
    self[9]=0;
    w3d_auto_8015fd1c(self);
}
static inline void replace_quake_ref(Ptr32<unsigned int> slot,unsigned int next)
{
    Ptr32<W3dS1QuakeRef> held=(Ptr32<W3dS1QuakeRef>)w3d::G(*slot);
    if(held)held->vtable->release(held);
    *slot=next;
}
void w3d_fn_80062228(Ptr32<unsigned int> self)
{
    replace_quake_ref(self+19,0);
    if(self[17]) {
        w3d_fn_800c56b8(self[17]);self[17]=0;
        post_quake_message(&w3d_message_804ad518);
    }
}
void w3d_fn_800622bc(Ptr32<unsigned int> self)
{
    struct { Ptr32<W3dS1QuakeRef> handle;unsigned int unknown;Ptr32<const char> key; } local;
    if(!self[15]) {
        local.handle=0;local.key=w3d_str_803795c0;
        w3d_constructor_lookup_name(&local.key,&local.handle);
        Ptr32<W3dS1QuakeConfig> config=w3d_auto_801797b4(w3d_empty_80341584(local.handle));
        self[18]=w3d_engine_get_context()->tick+config->delay;
        post_quake_message(&w3d_message_804ad520);
        w3d_fn_8002ad9c(self);self[15]=1;
        if(local.handle)local.handle->vtable->release(local.handle);
    }
}
}


