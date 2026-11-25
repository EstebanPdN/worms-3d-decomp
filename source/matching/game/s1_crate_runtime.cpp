/* Crate spawn notifications, periodic updates, and placement queries. */
extern "C" {
struct W3dS1RunVec { float x,y,z; };
struct W3dS1RunId { unsigned short id,pad; const char *name; };
struct W3dS1RunMessage { unsigned short id,pad; void *vtable; };
struct W3dS1RunSound;
struct W3dS1RunSoundVtable { void (*unused[24])(); void (*spawn)(W3dS1RunSound *,const char *,W3dS1RunVec *); };
struct W3dS1RunSound { W3dS1RunSoundVtable *vtable; };
struct W3dS1RunContext { unsigned char unknown[0x6c]; W3dS1RunSound *sound; };
extern W3dS1RunContext *w3d_context_804b1788;
extern void *w3d_queue_804b1754;
extern W3dS1RunId w3d_id_804ad2e0,w3d_id_804ad2f8,w3d_id_804ad300,w3d_id_804ad308,w3d_id_804ad400;
extern unsigned char w3d_vtable_8040db38[];
extern const char w3d_str_80376764[],w3d_str_80376774[];
extern const float w3d_f32_80376780[],w3d_f32_80376784[],w3d_f32_80376f24[],w3d_f32_80376f28[],w3d_f32_80376f2c[];
extern unsigned char *w3d_world_804b17e0;
extern unsigned int w3d_distance_804b1764;
extern unsigned short w3d_hit_804aa95e;
extern W3dS1RunVec w3d_hit_position_8043ae20[];
void w3d_fn_800e5ca4(float,W3dS1RunVec *,const char *,int);
unsigned int *w3d_fn_800fc6dc(int);
unsigned int *w3d_fn_80164fc8(unsigned int);
void *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(W3dS1RunId *,int);
void *w3d_message_int_init(void *,unsigned short,int);
void w3d_message_post_current(void *);
void w3d_fn_800c53a0(void *,unsigned int);
int w3d_scene_timer_is_one_8006e71c(void);
void w3d_fn_8004d1c4(unsigned int *);
void w3d_actor_handle_member_set_bounds(float,void *,W3dS1RunVec *);
void w3d_fn_8004b958(unsigned int *);
void w3d_fn_8004bdf8(unsigned int *);
void w3d_auto_8004ce38(unsigned int *);
void w3d_auto_8015fc58(unsigned int *,void *);
void w3d_fn_8004b3f0(float,unsigned int *);
float w3d_auto_801610a0(unsigned int *);
float w3d_auto_80178df0(unsigned int);
void w3d_fn_800b0824(W3dS1RunVec *,W3dS1RunVec *,W3dS1RunVec *,unsigned int,int);
void w3d_actor_handle_member_initialize(void *);
void w3d_actor_handle_member_destroy(void *,int);
void w3d_handle_member_query_8012629c(float,void *);
void w3d_actor_handle_member_set_word(void *,int);
void w3d_handle_member_query_801262c0(void *,W3dS1RunVec *);
void w3d_handle_member_call_80126384(void *,W3dS1RunVec *,int);
unsigned short w3d_handle_clock_801264fc(void *);
unsigned int *w3d_fn_8003f240(unsigned short);
void w3d_handle_member_query_80126524(void *);
static inline W3dS1RunMessage *basic_message(void *storage,unsigned int id)
{
    W3dS1RunMessage *message=(W3dS1RunMessage *)storage;
    message->id=id;message->vtable=w3d_vtable_8040db38;
    return message;
}
static inline void post_spawn(W3dS1RunId *id,int nearest)
{
    void *storage=w3d_fn_801613f0(w3d_queue_804b1754,8);
    unsigned int code=w3d_cached_message_id(id,1);
    w3d_message_post_current(basic_message(storage,code));
    storage=w3d_fn_801613f0(w3d_queue_804b1754,12);
    code=w3d_cached_message_id(&w3d_id_804ad2e0,1);
    w3d_fn_800c53a0(w3d_message_int_init(storage,(unsigned short)code,nearest),2400);
}
#if 0 /* Unmatched frame layout and register allocation. */
void w3d_fn_800492cc(unsigned int *self,W3dS1RunVec *position)
{
    w3d_fn_800e5ca4(w3d_f32_80376780[0],position,w3d_str_80376764,0);
    W3dS1RunSound *sound=w3d_context_804b1788->sound;
    if(sound)sound->vtable->spawn(sound,w3d_str_80376774,position);
    int nearest=-1;
    float best=w3d_f32_80376784[0];
    for(int i=0;i<16;++i) {
        unsigned int *actor=w3d_fn_800fc6dc(i);
        if(actor[0xdc/4]) {
            W3dS1RunVec *actor_position=(W3dS1RunVec *)(actor+0x50/4);
            float y=actor_position->y-position->y,x=actor_position->x-position->x,z=actor_position->z-position->z;
            float distance=z*z+(x*x+y*y);
            if(nearest==-1 || distance<best) {nearest=i;best=distance;}
        }
    }
    unsigned int *target=w3d_fn_80164fc8(self[0x1c/4]);
    if(target) {
        switch((int)target[0x1c/4]) {
        case 0:post_spawn(&w3d_id_804ad2f8,nearest);break;
        case 2:post_spawn(&w3d_id_804ad300,nearest);break;
        case 1:post_spawn(&w3d_id_804ad308,nearest);break;
        }
    }
}
#endif
int w3d_fn_80049c3c(unsigned int *self,unsigned int now)
{
    int delay=20;
    if(now%20)delay=20-now%20;
    if(!w3d_scene_timer_is_one_8006e71c()) {
        if(now>self[0x58/4]) {
            if(self[0x100/4]) {self[0x100/4]=0;w3d_fn_8004d1c4(self);}
            w3d_actor_handle_member_set_bounds(*(float *)(self+0x40/4),self+0xec/4,(W3dS1RunVec *)(self+0x28/4));
            self[0x60/4]=0;
            w3d_fn_8004b958(self);w3d_fn_8004bdf8(self);
        } else self[0x60/4]=1;
        if(self[0x5c/4] && now>self[0x54/4])w3d_auto_8004ce38(self);
        void *storage=w3d_fn_801613f0(w3d_queue_804b1754,8);
        unsigned int code=w3d_cached_message_id(&w3d_id_804ad400,1);
        w3d_auto_8015fc58(self,basic_message(storage,code));
    }
    return delay;
}
#if 0 /* Unmatched frame layout and register allocation. */
void w3d_fn_8004a408(unsigned int *self)
{
    struct { W3dS1RunVec candidate;int unused0;W3dS1RunVec down;int unused1;W3dS1RunVec zero;int unused2;unsigned int handle[2]; } local;
    w3d_fn_8004b3f0(w3d_f32_80376f24[0],self);
    float minx=*(float *)(w3d_world_804b17e0+0x3104),minz=*(float *)(w3d_world_804b17e0+0x310c);
    float maxx=*(float *)(w3d_world_804b17e0+0x3110),maxz=*(float *)(w3d_world_804b17e0+0x3118),height=*(float *)(w3d_world_804b17e0+0x3114);
    local.down.x=w3d_f32_80376f28[0];local.down.y=w3d_f32_80376f2c[0];local.down.z=w3d_f32_80376f28[0];
    local.zero.x=w3d_f32_80376f28[0];local.zero.z=w3d_f32_80376f28[0];local.zero.y=w3d_f32_80376f28[0];
    for(;;) {
        int valid;
        do {
            local.candidate.y=height;
            local.candidate.x=(maxx-minx)*w3d_auto_801610a0(self)+minx;
            local.candidate.z=(maxz-minz)*w3d_auto_801610a0(self)+minz;
            w3d_fn_800b0824(&local.candidate,&local.down,&local.zero,1000,1);
            valid=w3d_distance_804b1764<1001;
            if(w3d_distance_804b1764==0 || w3d_auto_80178df0(self[0xb8/4])>w3d_hit_position_8043ae20[0].y)valid=0;
        } while(!valid);
        w3d_actor_handle_member_initialize(local.handle);
        w3d_handle_member_query_8012629c(*(float *)(self+0x40/4),local.handle);
        w3d_actor_handle_member_set_word(local.handle,63);
        w3d_handle_member_query_801262c0(local.handle,&local.candidate);
        w3d_handle_member_call_80126384(local.handle,&local.down,1000);
        while(w3d_handle_clock_801264fc(local.handle)!=65535) {
            if(w3d_fn_8003f240(w3d_hit_804aa95e)[0x14/4]&1) {valid=0;break;}
        }
        w3d_handle_member_query_80126524(local.handle);
        w3d_actor_handle_member_destroy(local.handle,2);
        if(valid) {*(W3dS1RunVec *)(self+0x28/4)=local.candidate;return;}
    }
}
#endif
}
