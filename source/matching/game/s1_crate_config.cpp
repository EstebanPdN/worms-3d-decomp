/* Crate configuration lookup, spawn selection, and outgoing queries. */
extern "C" {
struct W3dS1ConfigVector { float x,y,z; };
struct W3dS1ConfigText { char *text; int unused; };
struct W3dS1ConfigSpawn { int unknown; W3dS1ConfigVector position; unsigned char unknown10[0x3c-0x10]; const char *name; };
struct W3dS1ConfigGroup { unsigned char unknown[0x14]; W3dS1ConfigSpawn **begin,**end; };
struct W3dS1ConfigGroups { W3dS1ConfigGroup **begin,**end; };
struct W3dS1ConfigRef;
struct W3dS1ConfigVtable { void (*unused[4])(); void (*release)(W3dS1ConfigRef *); };
struct W3dS1ConfigRef { W3dS1ConfigVtable *vtable; };
struct W3dS1ConfigClock { unsigned char unknown[0x34]; unsigned int elapsed; };
extern W3dS1ConfigGroups w3d_groups_8043bb64[];
extern W3dS1ConfigVector w3d_default_8045e788[],w3d_hit_8043ae20[];
extern unsigned int w3d_distance_804b1764;
extern void *w3d_queue_804b1754;
extern int w3d_result_804b17a0;
extern const char *w3d_kind_804aa9b0,*w3d_kind_804aa9b4,*w3d_kind_804aa9b8,*w3d_kind_804aa9bc;
extern const float w3d_f32_80376fa4[],w3d_f32_80377260[],w3d_f32_80377264[];
void * w3d_fn_800fc1f0(const char **,int *);
void w3d_fn_800fc270(const char **,float *);
void w3d_fn_800fc2b0(const char **,const char **);
void w3d_fn_800fc330(const char **,unsigned int **);
void w3d_string_append(W3dS1ConfigText *,const char *);
void w3d_string_from_text(W3dS1ConfigText *,const char *);
void w3d_string_base_finish(W3dS1ConfigText *);
void w3d_string_release(W3dS1ConfigText *);
void *w3d_handle_storage_allocate(unsigned int);
void w3d_handle_storage_release(void *);
void *memcpy(void *,const void *,unsigned int);
int strcmp(const char *,const char *);
int w3d_sprintf_802ec254(char *,const char *,...);
void w3d_lowercase_802efa2c(char *);
void w3d_fn_8004a930(void *,const char *);
void w3d_fn_8004a988(unsigned int *);
void w3d_fn_8004aa60(unsigned int *);
void w3d_fn_8004af78(unsigned int *);
void w3d_fn_8004b3c8(unsigned int *);
void w3d_fn_8004b3f0(float,unsigned int *);
void w3d_fn_8004b448(unsigned int *);
void w3d_fn_8004b7e0(unsigned int *);
void w3d_fn_8004b8f4(unsigned int *);
void w3d_fn_8004cd08(unsigned int *);
void w3d_fn_800b0824(W3dS1ConfigVector *,W3dS1ConfigVector *,W3dS1ConfigVector *,unsigned int,int);
float w3d_auto_80178df0(unsigned int);
void *w3d_fn_801613f0(void *,unsigned int);
void *w3d_fn_8003a264(void *,unsigned int,unsigned int);
int w3d_message_post_current(void *);
W3dS1ConfigClock *w3d_engine_get_context(void);
static inline void finish_config_text(W3dS1ConfigText *text) { w3d_string_base_finish(text);w3d_string_release(text); }
static inline void release_config_ref(unsigned int value) { W3dS1ConfigRef *p=(W3dS1ConfigRef *)value;if(p)p->vtable->release(p); }
extern const char w3d_str_80376f30[];
extern const char w3d_str_80376f58[];
extern const char w3d_str_80376f5c[];
extern const char w3d_str_80376f74[];
extern const char w3d_str_80376f88[];
extern const char w3d_str_80376f90[];
extern const char w3d_str_80376f94[];
extern const char w3d_str_80376f98[];
extern const char w3d_str_8037710c[];
#if 0 /* Unmatched instruction scheduling, stack layout, or register allocation. */
void w3d_fn_8004a608(unsigned int *self,const char *location)
{
    W3dS1ConfigGroups original=w3d_groups_8043bb64[0];
    unsigned int bytes=(char *)original.end-(char *)original.begin;
    W3dS1ConfigGroup **groups=(W3dS1ConfigGroup **)w3d_handle_storage_allocate(bytes);
    memcpy(groups,original.begin,bytes);
    W3dS1ConfigGroup **end=(W3dS1ConfigGroup **)((char *)groups+bytes);
    unsigned int i=0;
    while(i<(unsigned int)(end-groups)) {
        W3dS1ConfigGroup *group=groups[i];
        unsigned int j=0;
        while(j<(unsigned int)(group->end-group->begin)) {
            W3dS1ConfigText name;
            w3d_string_from_text(&name,group->begin[j]->name);
            if(strcmp(name.text,location)==0) {
                W3dS1ConfigVector position=group->begin[j]->position;
                *(W3dS1ConfigVector *)(self+0x28/4)=position;
                finish_config_text(&name);
                if(groups)w3d_handle_storage_release(groups);
                return;
            }
            ++j;
            finish_config_text(&name);
        }
        ++i;
    }
    w3d_fn_8004a930(self,w3d_str_80376f30);
    w3d_fn_8004a930(self,location);
    *(W3dS1ConfigVector *)(self+0x28/4)=w3d_default_8045e788[0];
    if(groups)w3d_handle_storage_release(groups);
}
#endif
void w3d_fn_8004a7f4(unsigned int *self,const char *kind)
{
    struct { char buffer[64]; const char *key; int ground; } local;
    w3d_fn_8004b448(self);
    w3d_sprintf_802ec254(local.buffer,w3d_str_80376f58,kind);
    w3d_lowercase_802efa2c(local.buffer);
    if(!strcmp(local.buffer,w3d_kind_804aa9b0)) { self[0x1c/4]=1;w3d_fn_8004a988(self); }
    else if(!strcmp(local.buffer,w3d_kind_804aa9b4)) { self[0x1c/4]=0;w3d_fn_8004aa60(self); }
    else if(!strcmp(local.buffer,w3d_kind_804aa9b8)) { self[0x1c/4]=2;w3d_fn_8004af78(self); }
    else if(!strcmp(local.buffer,w3d_kind_804aa9bc)) { self[0x1c/4]=3;w3d_fn_8004b3c8(self); }
    else { w3d_fn_8004a930(self,w3d_str_80376f5c);w3d_fn_8004a930(self,kind); }
    local.ground=0;local.key=w3d_str_80376f74;
    w3d_fn_800fc1f0(&local.key,&local.ground);
    if(local.ground==1)w3d_fn_8004b7e0(self);
}
#if 0 /* Unmatched instruction scheduling, stack layout, or register allocation. */
void w3d_fn_8004a988(unsigned int *self)
{
    struct { char buffer[64];const char *pot_key;unsigned int *pot;const char *text_key,*text; } local;
    w3d_fn_8004b3f0(w3d_f32_80376fa4[0],self);
    local.pot_key=w3d_str_80376f88;
    w3d_fn_800fc330(&local.pot_key,&local.pot);
    if(local.pot[0x30/4]==1)self[0x44/4]*=2;
    W3dS1ConfigText *name=(W3dS1ConfigText *)(self+0x94/4);
    if((int)self[0x44/4]>0)w3d_string_append(name,w3d_str_80376f90);
    w3d_sprintf_802ec254(local.buffer,w3d_str_80376f94,self[0x44/4]);
    w3d_string_append(name,local.buffer);
    local.text=0;local.text_key=w3d_str_80376f98;
    w3d_fn_800fc2b0(&local.text_key,&local.text);
    w3d_string_append(name,local.text);
}
#endif
void w3d_fn_8004b3f0(float scale,unsigned int *self)
{
    struct { const char *key; int unused[3]; } local;
    local.key=w3d_str_8037710c;
    w3d_fn_800fc270(&local.key,(float *)(self+0x98/4));
    *(float *)(self+0x40/4)=scale**(float *)(self+0x98/4);
}
extern const char w3d_str_80377118[];
extern const char w3d_str_80377124[];
extern const char w3d_str_80377138[];
extern const char w3d_str_80377148[];
extern const char w3d_str_8037715c[];
extern const char w3d_str_8037716c[];
extern const char w3d_str_8037717c[];
extern const char w3d_str_80377194[];
extern const char w3d_str_803771ac[];
extern const char w3d_str_803771b8[];
extern const char w3d_str_803771c8[];
extern const char w3d_str_803771dc[];
extern const char w3d_str_803771f4[];
extern const char w3d_str_80377204[];
extern const char w3d_str_80377218[];
extern const char w3d_str_80377228[];
extern const float w3d_f32_80377244[],w3d_f32_80377248[],w3d_f32_80377258[],w3d_f32_8037725c[];
#if 0 /* Unmatched instruction scheduling, stack layout, or register allocation. */
void w3d_fn_8004b448(unsigned int *self)
{
    struct { const char *key0,*key1,*key2,*key3,*key4;int parachute;const char *key5;int gravity;const char *key6,*key7,*key8;int uxb;const char *key9;int pushable;const char *key10;int delay;const char *key11;int wait;const char *key12;int track;const char *key13;float seconds;const char *key14;float speed;const char *key15;int unused[3]; } local;
    local.seconds=w3d_f32_80377248[0];local.speed=w3d_f32_80377244[0];
    self[0xac/4]=0;local.gravity=1;local.parachute=1;local.pushable=1;local.uxb=0;local.delay=0;local.wait=0;local.track=1;
    self[0x7c/4]=0;self[0x80/4]=0;
    *(float *)(self+0x34/4)=local.speed;*(float *)(self+0x3c/4)=local.speed;*(float *)(self+0x38/4)=local.speed;
    local.key0=w3d_str_80377118;w3d_fn_800fc1f0(&local.key0,(int *)(self+0x20/4));
    local.key1=w3d_str_80377124;w3d_fn_800fc1f0(&local.key1,(int *)(self+0x44/4));
    local.key2=w3d_str_80377138;w3d_fn_800fc1f0(&local.key2,(int *)(self+0x48/4));
    local.key3=w3d_str_80377148;w3d_fn_800fc1f0(&local.key3,(int *)(self+0x4c/4));
    local.key4=w3d_str_8037715c;w3d_fn_800fc1f0(&local.key4,&local.parachute);
    local.key5=w3d_str_8037716c;w3d_fn_800fc1f0(&local.key5,&local.gravity);
    local.key6=w3d_str_8037717c;w3d_fn_800fc1f0(&local.key6,(int *)(self+0x8c/4));
    local.key7=w3d_str_80377194;w3d_fn_800fc1f0(&local.key7,(int *)(self+0x88/4));
    local.key8=w3d_str_803771ac;w3d_fn_800fc1f0(&local.key8,&local.uxb);
    local.key9=w3d_str_803771b8;w3d_fn_800fc1f0(&local.key9,&local.pushable);
    local.key10=w3d_str_803771c8;w3d_fn_800fc1f0(&local.key10,&local.delay);
    local.key11=w3d_str_803771dc;w3d_fn_800fc1f0(&local.key11,&local.wait);
    local.key12=w3d_str_803771f4;w3d_fn_800fc1f0(&local.key12,&local.track);
    local.key13=w3d_str_80377204;w3d_fn_800fc270(&local.key13,&local.seconds);
    local.key14=w3d_str_80377218;w3d_fn_800fc270(&local.key14,&local.speed);
    local.key15=w3d_str_80377228;w3d_fn_800fc270(&local.key15,(float *)(self+0xa8/4));
    float multiplier=*(float *)(self+0xa8/4);
    if(multiplier>w3d_f32_80377244[0])self[0x48/4]=(int)((float)(int)self[0x48/4]*multiplier);
    self[0x58/4]=local.delay+w3d_engine_get_context()->elapsed;
    self[0x60/4]=self[0x58/4]!=0;
    if(local.seconds<=w3d_f32_80377244[0])self[0x5c/4]=0;
    else {
        unsigned int elapsed=w3d_engine_get_context()->elapsed;
        float millis=local.seconds*w3d_f32_80377258[0];
        self[0x5c/4]=1;self[0x54/4]=elapsed+(int)millis+local.delay;
    }
    *(float *)(self+0x34/4)=w3d_f32_80377244[0];*(float *)(self+0x3c/4)=w3d_f32_80377244[0];*(float *)(self+0x38/4)=local.speed*w3d_f32_8037725c[0];
    self[0x78/4]=local.uxb==1;self[0x6c/4]=local.gravity==1;self[0x70/4]=local.parachute==1;self[0x74/4]=local.pushable==1;
    if(local.wait!=1) {release_config_ref(self[0xf4/4]);self[0xf4/4]=0;}
    if(local.track!=1)self[0x100/4]=0;
}
#endif
#if 0 /* Unmatched instruction scheduling, stack layout, or register allocation. */
void w3d_fn_8004b7e0(unsigned int *self)
{
    struct { W3dS1ConfigVector down;int unused0;W3dS1ConfigVector zero;int unused1; } local;
    local.down.x=w3d_f32_80377260[0];local.down.y=w3d_f32_80377264[0];local.down.z=w3d_f32_80377260[0];
    local.zero.x=w3d_f32_80377260[0];local.zero.z=w3d_f32_80377260[0];local.zero.y=w3d_f32_80377260[0];
    w3d_fn_800b0824((W3dS1ConfigVector *)(self+0x28/4),&local.down,&local.zero,9000000,1);
    if(w3d_distance_804b1764<9000001) {
        *(W3dS1ConfigVector *)(self+0x28/4)=w3d_hit_8043ae20[0];
        self[0x64/4]=1;
        *(float *)(self+0x2c/4)+=*(float *)(self+0x40/4);
        w3d_fn_8004b8f4(self);
    } else {
        *(float *)(self+0x2c/4)=w3d_auto_80178df0(self[0xb8/4]);self[0x80/4]=1;w3d_fn_8004cd08(self);
    }
    self[0x70/4]=0;release_config_ref(self[0xf4/4]);self[0x100/4]=0;self[0xf4/4]=0;
}
#endif
int w3d_fn_8004b908(unsigned int *self)
{
    void *message=w3d_fn_801613f0(w3d_queue_804b1754,12);
    w3d_message_post_current(w3d_fn_8003a264(message,self[0xbc/4],self[0xc0/4]));
    return w3d_result_804b17a0==0;
}
}
