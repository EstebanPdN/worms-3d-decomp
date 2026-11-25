/* Airstrike cursor resources, camera state, and targeting messages. */
extern "C" {
struct W3dS1AirText { char *text; };
struct W3dS1AirRef;
struct W3dS1AirVtable { void (*unused[3])();void (*retain)(W3dS1AirRef *);void (*release)(W3dS1AirRef *); };
struct W3dS1AirRef { W3dS1AirVtable *vtable; };
struct W3dS1AirColor { unsigned char r,g,b,a; };
struct W3dS1AirMsg { unsigned short id,pad;void *vtable; };
extern unsigned char w3d_vtable_8040e9f8[],w3d_message_vtable_8040db38[],w3d_zero_8045e788[];
extern unsigned int w3d_message_804ad43c,w3d_message_804ad424,w3d_message_804ad444,w3d_message_804ad434,w3d_message_804ad44c,w3d_message_804ad42c;
extern W3dS1AirColor w3d_color_804ad458,w3d_color_804ad45c,w3d_color_804ad454;
extern const char w3d_str_80377770[],w3d_str_80377788[],w3d_str_8037779c[],w3d_str_803777b8[];
extern float w3d_f32_803777b0[],w3d_f32_803777b4[],w3d_f32_803777c8[],w3d_f32_803777cc[];
extern unsigned int *w3d_context_804b1788;
extern int w3d_disabled_804abab4;
extern void *w3d_queue_804b1754;
void w3d_ctor_8015fef0(void *);
void w3d_base_destroy_8015ff2c(void *,int);
void w3d_string_default(W3dS1AirText *);
void * w3d_string_from_text(W3dS1AirText *,const char *);
void w3d_string_assign(W3dS1AirText *,const char *);
void w3d_string_base_finish(W3dS1AirText *);
void w3d_string_release(W3dS1AirText *);
void w3d_constructor_lookup_name(const char **,unsigned int *);
unsigned int w3d_constructor_native_cast(unsigned int);
unsigned int w3d_empty_80343584(unsigned int);
unsigned int w3d_empty_8034357c(unsigned int);
unsigned int w3d_empty_80341348(unsigned int);
unsigned int w3d_auto_80178d1c(void *);
int w3d_auto_8015fb34(unsigned int *,unsigned short *);
void w3d_auto_8015fd1c(unsigned int *);
void w3d_empty_8004e0d8(unsigned int *);
unsigned int w3d_cached_message_id(void *,int);
int w3d_fn_8015f65c(unsigned int,void *);
void w3d_fn_80162024(void *,unsigned short *,unsigned int *);
unsigned int *w3d_engine_get_context(void);
void *w3d_fn_801613f0(void *,unsigned int);
int w3d_message_post_current(void *);
void w3d_handle_set_name(W3dS1AirText *,unsigned int *,unsigned int);
int w3d_fn_80173df0(void *,W3dS1AirColor *);
void w3d_fn_80181640(unsigned int,const char *,float,float,float,int *,int);
void w3d_mesh_instance_check_control(unsigned int,int,int);
void w3d_mesh_instance_control_3c(unsigned int,int);
unsigned int w3d_fn_8015ae3c(W3dS1AirText *);
int w3d_fn_8017fc90(void *,const char *,float *);
void w3d_fn_8004def0(unsigned int *);
int w3d_fn_8004e324(unsigned int *);
void w3d_fn_8004e5ac(unsigned int *);
float w3d_fn_8004e544(unsigned int *,const char *,const char *);
static inline void release_air(unsigned int value) { W3dS1AirRef *ref=(W3dS1AirRef *)value;if(ref)ref->vtable->release(ref); }
static inline void retain_air(unsigned int value) { W3dS1AirRef *ref=(W3dS1AirRef *)value;if(ref)ref->vtable->retain(ref); }
static inline void finish_air_text(W3dS1AirText *text) { w3d_string_base_finish(text);w3d_string_release(text); }
static inline void air_dispatch(unsigned int *self,int slot) { ((void (*)(unsigned int *))(*(void ***)self)[slot])(self); }
static inline void air_message(unsigned int *id) {
    W3dS1AirMsg *message=(W3dS1AirMsg *)w3d_fn_801613f0(w3d_queue_804b1754,8);
    message->id=w3d_cached_message_id(id,1);message->vtable=w3d_message_vtable_8040db38;w3d_message_post_current(message);
}
#if 0 /* Unmatched register copy or argument scheduling. */
unsigned int *w3d_fn_8004db14(unsigned int *self)
{
    struct { unsigned int target;int gap;const char *key;int gap2; } local;
    w3d_ctor_8015fef0(self);
    self[7]=0;self[8]=0;self[9]=0;self[10]=0;self[11]=0;self[12]=0;self[13]=0;self[14]=0;
    self[0]=(unsigned int)w3d_vtable_8040e9f8;
    w3d_string_default((W3dS1AirText *)(self+15));w3d_string_default((W3dS1AirText *)(self+16));w3d_string_default((W3dS1AirText *)(self+17));w3d_string_default((W3dS1AirText *)(self+18));
    self[22]=0;release_air(self[8]);self[8]=0;self[20]=0;
    local.target=0;local.key=w3d_str_80377770;w3d_constructor_lookup_name(&local.key,&local.target);
    unsigned int target=w3d_constructor_native_cast(local.target);retain_air(target);release_air(self[22]);self[22]=target;
    release_air(local.target);return self;
}
#endif
void w3d_fn_8004dc38(unsigned int *self,int flags)
{
    self[0]=(unsigned int)w3d_vtable_8040e9f8;
    release_air(self[22]);finish_air_text((W3dS1AirText *)(self+18));finish_air_text((W3dS1AirText *)(self+17));finish_air_text((W3dS1AirText *)(self+16));finish_air_text((W3dS1AirText *)(self+15));
    release_air(self[14]);release_air(self[13]);release_air(self[12]);release_air(self[11]);release_air(self[10]);release_air(self[9]);release_air(self[8]);release_air(self[7]);
    w3d_base_destroy_8015ff2c(self,flags);
}
#if 0 /* Unmatched register copy or argument scheduling. */
int w3d_fn_8004ddc8(unsigned int *self,unsigned short *message)
{
    unsigned int id=*message;
    switch((unsigned short)id) {
    case 64:if(w3d_auto_8015fb34(self,message)>=0) {w3d_fn_8004def0(self);return 0;} else return 0x80004005;
    case 66:w3d_empty_8004e0d8(self);return w3d_auto_8015fb34(self,message);
    }
    if(w3d_fn_8015f65c(id,&w3d_message_804ad43c))w3d_fn_8004e5ac(self);
    else if(w3d_fn_8015f65c(id,&w3d_message_804ad424)) {
        int enabled=w3d_fn_8004e324(self);
        if(enabled) { self[20]=1;air_dispatch(self,11); }
        else { self[20]=enabled;air_dispatch(self,12); }
    } else if(w3d_fn_8015f65c(id,&w3d_message_804ad444))w3d_auto_8015fd1c(self);
    else return w3d_auto_8015fb34(self,message);
    return 0;
}
#endif
#if 0 /* Unmatched register copy or argument scheduling. */
void w3d_fn_8004def0(unsigned int *self)
{
    unsigned short fire,camera,remove;const char *mode,*target;
    fire=w3d_cached_message_id(&w3d_message_804ad43c,1);w3d_fn_80162024(self,&fire,self+9);
    camera=w3d_cached_message_id(&w3d_message_804ad424,1);w3d_fn_80162024(self,&camera,self+10);
    remove=w3d_cached_message_id(&w3d_message_804ad444,1);w3d_fn_80162024(self,&remove,self+11);
    mode=w3d_str_80377788;w3d_constructor_lookup_name(&mode,self+13);
    target=w3d_str_8037779c;w3d_constructor_lookup_name(&target,self+12);
    air_dispatch(self,10);
    int enabled=w3d_fn_8004e324(self);
    if(enabled) { self[20]=1;air_dispatch(self,11); }
    else { self[20]=enabled;air_dispatch(self,12); }
}
#endif
int w3d_fn_8004e004(unsigned int *self)
{
    if((w3d_engine_get_context()[14] || (w3d_context_804b1788[47]&4)) && self[20] && !w3d_disabled_804abab4)air_dispatch(self,12);
    else if(!w3d_engine_get_context()[14] && self[20] && self[8] && !((int (*)(unsigned int))(*(void ***)self[8])[28])(self[8]))air_dispatch(self,11);
    return 0;
}
#if 0 /* Unmatched register copy or argument scheduling. */
void w3d_fn_8004e0dc(unsigned int *self,const char *resource,const char *second,int mode,const char *third,const char *fourth,const char *fifth)
{
    struct { unsigned int handle;int gap;W3dS1AirText text;int gap2; } local;
    local.handle=0;
    w3d_string_from_text(&local.text,resource);unsigned int *handle=&local.handle;w3d_handle_set_name(&local.text,handle,255);finish_air_text(&local.text);
    unsigned int mesh=w3d_empty_80343584(local.handle);retain_air(mesh);release_air(self[7]);self[7]=mesh;
    const char *second_name=second;w3d_string_from_text(&local.text,second_name);w3d_handle_set_name(&local.text,handle,255);finish_air_text(&local.text);
    unsigned int instance=w3d_empty_8034357c(local.handle);retain_air(instance);release_air(self[8]);self[8]=instance;
    ((void (*)(unsigned int,unsigned int,int))(*(void ***)self[7])[23])(self[7],instance,mode);
    ((void (*)(unsigned int,void *,int))(*(void ***)self[7])[19])(self[7],w3d_zero_8045e788,0);
    w3d_string_assign((W3dS1AirText *)(self+15),resource);w3d_string_assign((W3dS1AirText *)(self+16),third);w3d_string_assign((W3dS1AirText *)(self+17),fourth);w3d_string_assign((W3dS1AirText *)(self+18),fifth);
    *(float *)(self+19)=w3d_fn_8004e544(self,resource,third);
    release_air(local.handle);
}
#endif
void w3d_fn_8004e2a4(unsigned int *self,unsigned int *target,int active)
{
    if(active) {
        unsigned int object=*target;
        unsigned int water=w3d_auto_80178d1c((void *)self[22]);
        W3dS1AirColor *color=water?&w3d_color_804ad45c:&w3d_color_804ad458;
        w3d_fn_80173df0((void *)object,color);
    } else w3d_fn_80173df0((void *)(*target),&w3d_color_804ad454);
    release_air(*target);
}
int w3d_fn_8004e324(unsigned int *self)
{
    switch(w3d_auto_80178d1c((void *)(w3d_constructor_native_cast(self[13])))) {
    case 2:case 9:case 17:case 18:case 19:return 0;
    default:return 1;
    }
}
int w3d_fn_8004e384(unsigned int *self,int rope,int teleport)
{
    if(rope)air_message(&w3d_message_804ad434);
    else if(teleport)air_message(&w3d_message_804ad44c);
    else air_message(&w3d_message_804ad42c);
    return w3d_auto_80178d1c((void *)(w3d_constructor_native_cast(self[12])))!=0;
}
#if 0 /* Unmatched register copy or argument scheduling. */
void w3d_fn_8004e460(unsigned int *self)
{
    struct { int control;int gap; } local;
    ((void (*)(unsigned int,int))(*(void ***)self[8])[22])(self[8],1);
    w3d_fn_80181640(self[7],(const char *)self[16],w3d_f32_803777b0[0],w3d_f32_803777b4[0],w3d_f32_803777b4[0],&local.control,0);
    w3d_fn_80181640(self[7],(const char *)self[17],w3d_f32_803777b0[0],*(float *)(self+19),w3d_f32_803777b4[0],(int *)(self+21),1);
    w3d_mesh_instance_check_control(self[7],self[21],1);
}
#endif
float w3d_fn_8004e544(unsigned int *self,const char *resource,const char *animation)
{
    struct { W3dS1AirText text;int gap;float duration;int gap2; } local;
    w3d_string_from_text(&local.text,resource);
    unsigned int handle=w3d_fn_8015ae3c(&local.text);finish_air_text(&local.text);
    w3d_fn_8017fc90((void *)(w3d_empty_80341348(handle)),animation,&local.duration);
    return local.duration;
}
#if 0 /* Unmatched register copy or argument scheduling. */
void w3d_fn_8004e5ac(unsigned int *self)
{
    struct { int control;int gap; } local;
    unsigned int sound=w3d_context_804b1788[27];
    ((void (*)(unsigned int,const char *,unsigned int *))(*(void ***)sound)[23])(sound,w3d_str_803777b8,self+14);
    air_dispatch((unsigned int *)self[14],5);
    if(w3d_fn_8004e324(self)) {
        w3d_mesh_instance_control_3c(self[7],self[21]);
        w3d_fn_80181640(self[7],(const char *)self[18],w3d_f32_803777c8[0],w3d_f32_803777cc[0],w3d_f32_803777cc[0],&local.control,0);
        float duration=w3d_fn_8004e544(self,(const char *)self[15],(const char *)self[18]);
        w3d_fn_80181640(self[7],(const char *)self[17],w3d_f32_803777c8[0],duration,w3d_f32_803777cc[0],(int *)(self+21),1);
        w3d_mesh_instance_check_control(self[7],self[21],1);
    }
}
#endif
}
