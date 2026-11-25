/* Observed popup resource ownership and animation dispatch. */
extern "C" {
struct W3dS1Interface;
struct W3dS1InterfaceVtable { void (*unused[4])(); void (*release)(W3dS1Interface *); };
struct W3dS1Interface { W3dS1InterfaceVtable *vtable; };
struct W3dS1PopupVec { float x,y,z; };
struct W3dS1PopupColor { signed char r,g,b,a; };
static inline void set_color(W3dS1PopupColor *c) { c->r=-56;c->g=-56;c->b=-56;c->a=-1; }
static inline void shift_position(W3dS1PopupVec *out,W3dS1PopupVec *in) { extern const float w3d_f32_8037673c[]; float y=in->y+w3d_f32_8037673c[0];float x=in->x,z=in->z;out->x=x;out->z=z;out->y=y; }
struct W3dS1PopupUi;
struct W3dS1PopupUiVtable { void (*unused[10])(); void (*position)(W3dS1PopupUi *,W3dS1PopupVec *); void (*text)(W3dS1PopupUi *,const char *); };
struct W3dS1PopupUi { W3dS1PopupUiVtable *vtable; };
struct W3dS1Mesh;
struct W3dS1MeshVtable { void (*unused[22])(); void (*mode)(W3dS1Mesh *,int); };
struct W3dS1Mesh { W3dS1MeshVtable *vtable; };
extern unsigned char w3d_vtable_8040e978[],w3d_type_80410a10[];
extern void *w3d_context_804b178c;
extern const char w3d_str_803766d4[],w3d_str_80376740[],w3d_str_80376750[];
extern unsigned int w3d_color_804af3b4;
extern const float w3d_f32_8037673c[],w3d_f32_80376748[],w3d_f32_8037674c[],w3d_f32_80376758[],w3d_f32_8037675c[],w3d_f32_80376760[];
extern const char *w3d_clip_804aa994,*w3d_clip_804aa998,*w3d_clip_804aa99c,*w3d_clip_804aa9a0;
void w3d_ctor_8015fef0(void *);
void w3d_base_destroy_8015ff2c(void *,int);
void w3d_handle_member_destroy_801265a4(void *,int);
void *w3d_fn_80164fc8(unsigned int);
void *w3d_fn_8020b680(void *);
unsigned int w3d_fn_80164514(void *,void *,unsigned int);
void * w3d_fn_800fc1f0(const char **,unsigned int *);
void *w3d_fn_800fc6dc(unsigned int);
void *w3d_fn_800fc7f8(unsigned int);
void w3d_fn_8011adf8(W3dS1PopupUi *,unsigned char *,unsigned int *);
void *w3d_empty_80343584(unsigned int);
int w3d_fn_80181640(float,float,float,void *,const char *,int *,int);
void *w3d_registry_instance_80343810(void);
unsigned int w3d_buffer_storage_available(void *);
int w3d_mesh_instance_check_control(void *,int,int);
static inline void release_interface(unsigned int address)
{
    W3dS1Interface *object=(W3dS1Interface *)address;
    if(object)object->vtable->release(object);
}
#if 0 /* Remaining register allocation or scheduling differences. */
unsigned int *w3d_fn_800485b0(unsigned int *self)
{
    w3d_ctor_8015fef0(self);
    self[0]=(unsigned int)w3d_vtable_8040e978;
    self[18]=0xffffffffu;
    self[11]=0;
    self[8]=0;
    self[9]=0;
    self[13]=0;
    self[14]=0;
    self[15]=0;
    self[16]=0;
    self[20]=0;
    self[7]=0xffffffffu;
    self[12]=0;
    self[17]=0;
    self[19]=0;
    self[10]=0;
    return self;
}
#endif
void w3d_fn_8004862c(unsigned int *self,int flags)
{
    self[0]=(unsigned int)w3d_vtable_8040e978;
    release_interface(self[20]);
    release_interface(self[16]);
    release_interface(self[15]);
    release_interface(self[14]);
    release_interface(self[13]);
    release_interface(self[9]);
    release_interface(self[8]);
    w3d_base_destroy_8015ff2c(self,flags);
}
void w3d_fn_80048ec4(unsigned int *self)
{
    if(self[0x28/4])w3d_handle_member_destroy_801265a4((void *)self[0x28/4],3);
    if(self[0x2c/4])w3d_handle_member_destroy_801265a4((void *)self[0x2c/4],3);
    self[0x2c/4]=0;
}
void w3d_fn_80048fcc(unsigned int *self);
void w3d_fn_80048f1c(unsigned int *self)
{
    const char *key;
    unsigned int index;
    unsigned int *target=(unsigned int *)w3d_fn_80164fc8(self[0x1c/4]);
    if(target && target[0x1c/4]!=1 && target[0x1c/4]!=3) {
        key=w3d_str_803766d4;
        w3d_fn_800fc1f0(&key,&index);
        if(index<16) {
            unsigned char *actor=(unsigned char *)w3d_fn_800fc6dc(index);
            unsigned int *team=(unsigned int *)w3d_fn_800fc7f8(actor[0xd5]);
            if(team[0x28/4])w3d_fn_80048fcc(self);
        }
    }
}
#if 0 /* Remaining register allocation or scheduling differences. */
void w3d_fn_80048fcc(unsigned int *self)
{
    struct { W3dS1PopupVec position; unsigned int padding; W3dS1PopupColor color; } local;
    if(!self[0x44/4]) {
        void *type=w3d_fn_8020b680(w3d_type_80410a10);
        self[0x44/4]=w3d_fn_80164514(w3d_context_804b178c,type,self[0x14/4]);
    }
    W3dS1PopupUi *ui=(W3dS1PopupUi *)w3d_fn_80164fc8(self[0x44/4]);
    unsigned int *target=(unsigned int *)w3d_fn_80164fc8(self[0x1c/4]);
    set_color(&local.color);
    w3d_fn_8011adf8(ui,(unsigned char *)&local.color,&w3d_color_804af3b4);
    ui->vtable->text(ui,(const char *)target[0x94/4]);
    shift_position(&local.position,(W3dS1PopupVec *)(target+0x28/4));
    ui->vtable->position(ui,&local.position);
}
#endif
void w3d_fn_80049108(unsigned int *self)
{
    W3dS1Mesh *mesh=(W3dS1Mesh *)self[0x24/4];
    if(mesh) {
        mesh->vtable->mode(mesh,1);
        void *instance=w3d_empty_80343584(self[0x24/4]);
        w3d_fn_80181640(w3d_f32_80376748[0],w3d_f32_8037674c[0],w3d_f32_8037674c[0],instance,w3d_str_80376740,(int *)(self+0x48/4),0);
    }
}
void w3d_fn_80049180(unsigned int *self)
{
    struct { int clip; int unused; } local;
    if(w3d_buffer_storage_available(w3d_registry_instance_80343810())>102399) {
        unsigned int *target=(unsigned int *)w3d_fn_80164fc8(self[0x1c/4]);
        if(target) {
            void *instance=w3d_empty_80343584(self[0x20/4]);
            if(target[0x1c/4]!=3)w3d_fn_80181640(1.0f,0.0f,0.0f,instance,w3d_str_80376750,&local.clip,0);
            const char *clip=0;
            switch((int)target[0x1c/4]) {
            case 1:clip=w3d_clip_804aa994;break;
            case 0:clip=w3d_clip_804aa998;break;
            case 2:clip=w3d_clip_804aa99c;break;
            case 3:clip=w3d_clip_804aa9a0;break;
            }
            w3d_fn_80181640(1.0f,-1.0f,1.0f,instance,clip,&local.clip,0);
            w3d_mesh_instance_check_control(instance,local.clip,1);
        }
    }
}
}
