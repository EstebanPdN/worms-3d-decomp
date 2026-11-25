/* Parachute actor defaults, smoothing and visual interface lifecycle. */
extern "C" {
struct S5ChuteVisual;
struct S5ChuteVisualVtable { void (*reserved[4])(); void (*release)(S5ChuteVisual *); void (*show)(S5ChuteVisual *); void (*hide)(S5ChuteVisual *); void (*reserved28[6])(); void (*start)(S5ChuteVisual *,float,int); };
struct S5ChuteVisual { S5ChuteVisualVtable *vtable; };
struct S5ChuteActor { void *vtable; unsigned char reserved04[24]; S5ChuteVisual *held[10]; int active,state72,state76,state80; unsigned char reserved84[48]; float x,y,z,value; int state148,state152; S5ChuteVisual *visual; int state160,sentinel; };
struct S5ChuteManager;
struct S5ChuteManagerVtable { void (*reserved[23])(); void (*lookup)(S5ChuteManager *,const char *,S5ChuteVisual **); };
struct S5ChuteManager { S5ChuteManagerVtable *vtable; };
struct S5ChuteContext { unsigned char reserved[108]; S5ChuteManager *manager; };
extern S5ChuteContext *w3d_chute_context_804b1788;
extern unsigned char w3d_chute_vtable_8040fe40[];
extern const char w3d_str_803898d4[];
extern const float w3d_f32_803898bc[],w3d_f32_803898c0[],w3d_f32_803898c4[],w3d_f32_803898c8[],w3d_f32_803898cc[],w3d_f32_803898d0[],w3d_f32_803898e0[];
void w3d_actor_base_initialize(void *);
void w3d_actor_base_destroy(void *,int);
/* 0x800daa2c: independent default-store scheduling differs after two attempts. */
#if 0
S5ChuteActor *w3d_chute_actor_init_800daa2c(S5ChuteActor *actor)
{
    w3d_actor_base_initialize(actor);
    actor->vtable=w3d_chute_vtable_8040fe40;
    actor->active=1;actor->sentinel=-1;actor->state80=0;
    actor->held[0]=0;actor->held[1]=0;actor->held[2]=0;actor->held[3]=0;actor->held[4]=0;
    actor->held[5]=0;actor->held[6]=0;actor->held[7]=0;actor->held[8]=0;actor->held[9]=0;
    actor->visual=0;actor->state72=0;
    actor->x=0.0f;actor->y=0.0f;actor->z=0.0f;
    actor->state152=0;actor->state148=0;actor->state160=0;actor->state76=0;
    actor->value=0.0f;
    return actor;
}
#endif
static inline void s5_chute_release(S5ChuteVisual *value) { if(value) value->vtable->release(value); }
void w3d_chute_actor_destroy_800daad8(S5ChuteActor *actor,int flags)
{
    actor->vtable=w3d_chute_vtable_8040fe40;
    s5_chute_release(actor->visual);
    s5_chute_release(actor->held[9]);s5_chute_release(actor->held[8]);
    s5_chute_release(actor->held[7]);s5_chute_release(actor->held[6]);
    s5_chute_release(actor->held[5]);s5_chute_release(actor->held[4]);
    s5_chute_release(actor->held[3]);s5_chute_release(actor->held[2]);
    s5_chute_release(actor->held[1]);s5_chute_release(actor->held[0]);
    w3d_actor_base_destroy(actor,flags);
}
static inline const float &s5_chute_max(const float &left,const float &right) { return left<right?right:left; }
static inline const float &s5_chute_min(const float &left,const float &right) { return left<right?left:right; }
void w3d_chute_smooth_value_800dc0b4(S5ChuteActor *actor,float input)
{
    float minimum=-0.02f;
    float working=input;
    working=s5_chute_max(minimum,working);
    working=s5_chute_min(working,0.02f);
    actor->value+=((working/0.02f+1.0f)*0.5f-actor->value)*0.04f;
    actor->value=s5_chute_max(0.0f,actor->value);
    actor->value=s5_chute_min(actor->value,1.0f);
}
void w3d_chute_visual_create_800dc184(S5ChuteActor *actor)
{
    S5ChuteManager *manager=w3d_chute_context_804b1788->manager;
    if(manager) {
        manager->vtable->lookup(manager,w3d_str_803898d4,&actor->visual);
        actor->visual->vtable->start(actor->visual,*w3d_f32_803898e0,1);
        actor->visual->vtable->show(actor->visual);
    }
}
void w3d_chute_visual_hide_800dc20c(S5ChuteActor *actor)
{
    if(actor->visual) actor->visual->vtable->hide(actor->visual);
}
}
