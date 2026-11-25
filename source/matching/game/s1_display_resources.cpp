/* Observed resource collections, reference holders, and display state. */
extern "C" {
struct W3dS1String { char *text; };
struct W3dS1StringStorage { int unknown; W3dS1String *capacity; };
struct W3dS1StringVector { W3dS1String *begin,*end; W3dS1StringStorage storage; };
struct W3dS1IntStorage { int unknown; int *capacity; };
struct W3dS1IntVector { int *begin,*end; W3dS1IntStorage storage; };
struct W3dS1Resource;
struct W3dS1ResourceVtable { void (*slots[4])(); void (*release)(W3dS1Resource *); };
struct W3dS1Resource { W3dS1ResourceVtable *vtable; };
struct W3dS1Color { float x,y,z,w; };
struct W3dS1Display {
    void *vtable;
    unsigned char unknown04[0x1c-4];
    int mode;
    W3dS1Color color, previous;
    unsigned char unknown40[8];
    W3dS1StringVector strings;
    unsigned char unknown58[8];
    W3dS1IntVector durations;
    unsigned char unknown70[12];
    W3dS1Resource *resources[32];
    unsigned char unknownfc[8];
    int width;
};
struct W3dS1StateVec { float x,y,z; W3dS1StateVec(float a,float b,float c):x(a),y(b),z(c) {} };
extern W3dS1StateVec w3d_vec_8042745c[],w3d_vec_80427468[];
extern const float w3d_f32_80374d8c[],w3d_f32_80374d90[],w3d_f32_80374d94[],w3d_f32_80374d98[],w3d_f32_80374d9c[],w3d_f32_80374da0[],w3d_f32_80374da4[];
extern int w3d_state_804aa974,w3d_duration_804aa978,w3d_delay_804aa97c,w3d_active_804aa984;
extern float w3d_value_804aa980;
extern unsigned char w3d_vtable_8040e938[];
int w3d_ctor_8015fef0(void *);
void w3d_base_destroy_8015ff2c(void *,int);
void w3d_string_base_finish(W3dS1String *);
void w3d_string_release(W3dS1String *);
void w3d_handle_storage_release(void *);
static inline void clear_color(W3dS1Color *c,float value) { c->x=value;c->y=value;c->z=value;c->w=value; }
#if 0 /* 0x80041d28: remaining global-copy and integer register allocation differences. */
void w3d_fn_80041d28(W3dS1Display *self,int mode)
{
    self->mode=mode;
    if (mode) {
        w3d_vec_8042745c[0]=W3dS1StateVec(w3d_f32_80374d90[0],w3d_f32_80374d94[0],w3d_f32_80374d90[0]);
        w3d_vec_80427468[0]=W3dS1StateVec(w3d_f32_80374d90[0],w3d_f32_80374d94[0],w3d_f32_80374d90[0]);
        w3d_duration_804aa978=1600;w3d_delay_804aa97c=0;w3d_value_804aa980=w3d_f32_80374d8c[0];w3d_state_804aa974=0;
        clear_color(&self->color,1.0f);self->previous=self->color;self->width=62;
    } else {
        w3d_vec_8042745c[0]=W3dS1StateVec(w3d_f32_80374d90[0],w3d_f32_80374d9c[0],w3d_f32_80374d90[0]);
        w3d_vec_80427468[0]=W3dS1StateVec(w3d_f32_80374d90[0],w3d_f32_80374da0[0],w3d_f32_80374d90[0]);
        w3d_duration_804aa978=1200;w3d_delay_804aa97c=250;w3d_value_804aa980=w3d_f32_80374d8c[0];w3d_state_804aa974=250;
        clear_color(&self->color,1.0f);self->previous=self->color;self->width=36;
    }
}
#endif
static inline void init_string_storage(W3dS1StringStorage *p) { p->capacity=0; }
static inline void init_int_storage(W3dS1IntStorage *p) { p->capacity=0; }
static inline void init_int_vector(W3dS1IntVector *p) { p->begin=0;p->end=0;init_int_storage(&p->storage); }
W3dS1Display *w3d_fn_80041ef8(W3dS1Display *self)
{
    struct { short unknown[6]; } frame_slot;
    w3d_ctor_8015fef0(self);
    self->vtable=w3d_vtable_8040e938;
    self->strings.begin=0;self->strings.end=0;init_string_storage(&self->strings.storage);
    init_int_vector(&self->durations);
    self->resources[0]=0;
    self->resources[1]=0;
    self->resources[2]=0;
    self->resources[3]=0;
    self->resources[4]=0;
    self->resources[5]=0;
    self->resources[6]=0;
    self->resources[7]=0;
    self->resources[8]=0;
    self->resources[9]=0;
    self->resources[10]=0;
    self->resources[11]=0;
    self->resources[12]=0;
    self->resources[13]=0;
    self->resources[14]=0;
    self->resources[15]=0;
    self->resources[16]=0;
    self->resources[17]=0;
    self->resources[18]=0;
    self->resources[19]=0;
    self->resources[20]=0;
    self->resources[21]=0;
    self->resources[22]=0;
    self->resources[23]=0;
    self->resources[24]=0;
    self->resources[25]=0;
    self->resources[26]=0;
    self->resources[27]=0;
    self->resources[28]=0;
    self->resources[29]=0;
    self->resources[30]=0;
    self->resources[31]=0;
    w3d_active_804aa984=0;
    clear_color(&self->color,1.0f);
    self->width=36;
    return self;
}
static inline void destroy_strings(W3dS1String *first,W3dS1String *last)
{
    for (;first!=last;++first) { w3d_string_base_finish(first);w3d_string_release(first); }
}
static inline void release_resource(W3dS1Resource *resource) { if(resource) resource->vtable->release(resource); }
static inline void clear_strings(W3dS1StringVector *v)
{
    W3dS1String *first=v->begin;
    destroy_strings(first,v->end);
    v->end=first;
}
static inline void clear_durations(W3dS1IntVector *v) { v->end=v->begin; }
static inline void destroy_durations(W3dS1IntVector *v) { if(v->begin)w3d_handle_storage_release(v->begin); }
static inline void destroy_string_vector(W3dS1StringVector *v)
{
    destroy_strings(v->begin,v->end);
    if(v->begin)w3d_handle_storage_release(v->begin);
}
#if 0 /* 0x80042004: container lifetime pointer allocation and four-byte size difference remain. */
void w3d_fn_80042004(W3dS1Display *self,int flags)
{
    self->vtable=w3d_vtable_8040e938;
    clear_strings(&self->strings);
    clear_durations(&self->durations);
    w3d_active_804aa984=0;
    release_resource(self->resources[31]);
    release_resource(self->resources[30]);
    release_resource(self->resources[29]);
    release_resource(self->resources[28]);
    release_resource(self->resources[27]);
    release_resource(self->resources[26]);
    release_resource(self->resources[25]);
    release_resource(self->resources[24]);
    release_resource(self->resources[23]);
    release_resource(self->resources[22]);
    release_resource(self->resources[21]);
    release_resource(self->resources[20]);
    release_resource(self->resources[19]);
    release_resource(self->resources[18]);
    release_resource(self->resources[17]);
    release_resource(self->resources[16]);
    release_resource(self->resources[15]);
    release_resource(self->resources[14]);
    release_resource(self->resources[13]);
    release_resource(self->resources[12]);
    release_resource(self->resources[11]);
    release_resource(self->resources[10]);
    release_resource(self->resources[9]);
    release_resource(self->resources[8]);
    release_resource(self->resources[7]);
    release_resource(self->resources[6]);
    release_resource(self->resources[5]);
    release_resource(self->resources[4]);
    release_resource(self->resources[3]);
    release_resource(self->resources[2]);
    release_resource(self->resources[1]);
    release_resource(self->resources[0]);
    destroy_durations(&self->durations);
    destroy_string_vector(&self->strings);
    w3d_base_destroy_8015ff2c(self,flags);
}
#endif
}
