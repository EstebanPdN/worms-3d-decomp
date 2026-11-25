/* Crate pickup dispatch and observed collection messages. */
extern "C" {
struct W3dS1PickupVec { float x,y,z; };
struct W3dS1PickupRef;
struct W3dS1PickupRefVtable { void (*unused[4])(); void (*release)(W3dS1PickupRef *); };
struct W3dS1PickupRef { W3dS1PickupRefVtable *vtable; };
struct W3dS1PickupSound;
struct W3dS1PickupSoundVtable { void (*unused[24])(); void (*play)(W3dS1PickupSound *,const char *,W3dS1PickupVec *); };
struct W3dS1PickupSound { W3dS1PickupSoundVtable *vtable; };
struct W3dS1PickupContext { unsigned char unknown[0x6c];W3dS1PickupSound *sound; };
struct W3dS1PickupActor { unsigned char unknown[0xd5];unsigned char team; };
struct W3dS1PickupTeam { unsigned char unknown[0x3c];unsigned char alliance; };
struct W3dS1PickupMessage { unsigned short id;unsigned short unused;void *vtable; };
struct W3dS1PickupHandle { unsigned int id,kind; };
extern void *w3d_queue_804b1754;
extern W3dS1PickupContext *w3d_context_804b1788;
extern unsigned char w3d_message_vtable_8040db38[];
extern unsigned int w3d_message_804ad3b0,w3d_message_804ad358,w3d_message_804ad380,w3d_message_804ad378,w3d_message_804ad3f0,w3d_message_804ad3c8,w3d_message_804ad3a0,w3d_message_804ad398,w3d_message_804ad350;
extern const char w3d_str_80377118[],w3d_str_80376ed4[],w3d_str_803772cc[],w3d_str_803772dc[],w3d_str_803772f0[],w3d_str_80377308[],w3d_str_80377318[],w3d_str_80377330[],w3d_str_8037734c[];
extern const float w3d_f32_803772ec[];
void *w3d_fn_801613f0(void *,unsigned int);
unsigned int w3d_cached_message_id(void *,int);
int w3d_message_post_current(void *);
void *w3d_message_int_init(void *,unsigned int,unsigned int);
W3dS1PickupActor *w3d_fn_800fc6dc(unsigned int);
W3dS1PickupTeam *w3d_fn_800fc7f8(unsigned int);
int w3d_fn_800fc3b0(const char **,unsigned int);
int w3d_fn_800fc550(const char **,unsigned int);
void w3d_fn_800fc230(const char **,int *);
void w3d_fn_800fc43c(const char **,int);
unsigned int *w3d_fn_800fc710(unsigned int,W3dS1PickupHandle *);
void w3d_fn_80178474(W3dS1PickupHandle *,int);
void w3d_auto_8015fd1c(void *);
void w3d_auto_8004c814(unsigned int *,unsigned int);
void w3d_fn_8004c598(unsigned int *,unsigned int);
void w3d_fn_8004c670(unsigned int *,unsigned int);
void w3d_fn_8004c51c(unsigned int *);
void w3d_fn_8004c7a0(unsigned int *,unsigned int);
void w3d_fn_8004cda4(unsigned int *,unsigned int);
void w3d_fn_8004d10c(unsigned int *);
void w3d_fn_800e5ca4(float,W3dS1PickupVec *,const char *,int);
static inline void post_pickup_message(unsigned int *id)
{
    W3dS1PickupMessage *message=(W3dS1PickupMessage *)w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(id,1);
    message->vtable=w3d_message_vtable_8040db38;
    w3d_message_post_current(message);
}
static inline void release_pickup_ref(unsigned int value)
{
    W3dS1PickupRef *ref=(W3dS1PickupRef *)value;
    if(ref)ref->vtable->release(ref);
}
#if 0 /* Two instruction-scheduling differences remain. */
void w3d_fn_8004c378(unsigned int *self)
{
    const char *index,*showered;
    if(!self[0x84/4]) {
        self[0x84/4]=1;
        W3dS1PickupActor *actor=w3d_fn_800fc6dc(self[0x50/4]);
        switch((int)self[0x1c/4]) {
        case 1:w3d_fn_8004c598(self,self[0x50/4]);break;
        case 0:w3d_auto_8004c814(self,actor->team);break;
        case 2:w3d_fn_8004c670(self,actor->team);break;
        }
        void *message=w3d_fn_801613f0(w3d_queue_804b1754,12);
        unsigned int id=(unsigned short)w3d_cached_message_id(&w3d_message_804ad3b0,1);
        w3d_message_post_current(w3d_message_int_init(message,id,self[0x50/4]));
        index=w3d_str_80377118;w3d_fn_800fc3b0(&index,self[0x20/4]);
        showered=w3d_str_80376ed4;w3d_fn_800fc3b0(&showered,self[0x90/4]);
        post_pickup_message(&w3d_message_804ad358);
        release_pickup_ref(self[0xf4/4]);*(W3dS1PickupRef **)(self+0xf4/4)=0;
        W3dS1PickupSound *sound=w3d_context_804b1788->sound;
        W3dS1PickupVec *position=(W3dS1PickupVec *)(self+0x28/4);
        if(sound)sound->vtable->play(sound,w3d_str_803772cc,position);
        w3d_fn_800e5ca4(w3d_f32_803772ec[0],position,w3d_str_803772dc,0);
        w3d_auto_8015fd1c(self);
    }
}
#endif
void w3d_fn_8004c51c(unsigned int *self)
{
    const char *key;
    if(!self[0x118/4]) {
        key=w3d_str_803772f0;w3d_fn_800fc550(&key,self[0x94/4]);
        post_pickup_message(&w3d_message_804ad380);
    }
}
void w3d_fn_8004c598(unsigned int *self,unsigned int actor)
{
    W3dS1PickupHandle handle;
    w3d_fn_8004c51c(self);
    handle.id=0;handle.kind=0xe3a8;
    unsigned int *target=w3d_fn_800fc710(actor,&handle);
    target[0xa4/4]-=self[0x44/4];
    w3d_fn_80178474(&handle,2);
    post_pickup_message(&w3d_message_804ad378);
    void *message=w3d_fn_801613f0(w3d_queue_804b1754,12);
    unsigned int id=(unsigned short)w3d_cached_message_id(&w3d_message_804ad3f0,1);
    w3d_message_post_current(w3d_message_int_init(message,id,actor));
}
void w3d_fn_8004c670(unsigned int *self,unsigned int team)
{
    const char *key;
    w3d_fn_8004c51c(self);
    switch(self[0x24/4]) {
    case 39:case 40:case 41:case 42:case 43:case 44:case 45:case 46:case 47:case 48:
    case 51:case 52:case 53:w3d_fn_8004cda4(self,team);break;
    case 54:key=w3d_str_80377308;w3d_fn_800fc3b0(&key,1);post_pickup_message(&w3d_message_804ad3c8);break;
    case 55:post_pickup_message(&w3d_message_804ad3a0);break;
    case 56:post_pickup_message(&w3d_message_804ad398);break;
    case 57:w3d_fn_8004d10c(self);break;
    case 58:w3d_fn_8004c7a0(self,team);break;
    }
}
#if 0 /* Two instruction-scheduling differences remain. */
void w3d_fn_8004c7a0(unsigned int *self,unsigned int team)
{
    struct { const char *alliance,*defaults;unsigned int rounds;const char *active; } local;
    unsigned int value=w3d_fn_800fc7f8(team)->alliance;
    local.alliance=w3d_str_80377318;w3d_fn_800fc3b0(&local.alliance,value);
    local.defaults=w3d_str_80377330;local.rounds=0;w3d_fn_800fc230(&local.defaults,(int *)&local.rounds);
    local.active=w3d_str_8037734c;w3d_fn_800fc43c(&local.active,local.rounds);
}
#endif
}
