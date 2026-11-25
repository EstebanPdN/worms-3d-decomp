#include "w3d_ptr.h"
#line 1 "s1_popup.cpp"
/* Observed popup resource ownership and animation dispatch. */
extern "C" {
struct W3dS1Interface;
struct W3dS1InterfaceVtable { Ptr32<void (void)> unused[4]; Ptr32<void (Ptr32<W3dS1Interface>)> release; };
struct W3dS1Interface { Ptr32<W3dS1InterfaceVtable> vtable; };
struct W3dS1PopupVec { float x,y,z; };
struct W3dS1PopupColor { signed char r,g,b,a; };
static inline void set_color(Ptr32<W3dS1PopupColor> c) { c->r=-56;c->g=-56;c->b=-56;c->a=-1; }
static inline void shift_position(Ptr32<W3dS1PopupVec> out,Ptr32<W3dS1PopupVec> in) { extern const float w3d_f32_8037673c[]; float y=in->y+w3d_f32_8037673c[0];float x=in->x,z=in->z;out->x=x;out->z=z;out->y=y; }
struct W3dS1PopupUi;
struct W3dS1PopupUiVtable { Ptr32<void (void)> unused[10]; Ptr32<void (Ptr32<W3dS1PopupUi>, Ptr32<W3dS1PopupVec>)> position; Ptr32<void (Ptr32<W3dS1PopupUi>, Ptr32<const char>)> text; };
struct W3dS1PopupUi { Ptr32<W3dS1PopupUiVtable> vtable; };
struct W3dS1Mesh;
struct W3dS1MeshVtable { Ptr32<void (void)> unused[22]; Ptr32<void (Ptr32<W3dS1Mesh>, int)> mode; };
struct W3dS1Mesh { Ptr32<W3dS1MeshVtable> vtable; };
extern unsigned char w3d_vtable_8040e978[],w3d_type_80410a10[];
extern Ptr32<void> w3d_context_804b178c;
extern const char w3d_str_803766d4[],w3d_str_80376740[],w3d_str_80376750[];
extern unsigned int w3d_color_804af3b4;
extern const float w3d_f32_8037673c[],w3d_f32_80376748[],w3d_f32_8037674c[],w3d_f32_80376758[],w3d_f32_8037675c[],w3d_f32_80376760[];
extern Ptr32<const char> w3d_clip_804aa994; extern Ptr32<const char> w3d_clip_804aa998; extern Ptr32<const char> w3d_clip_804aa99c; extern Ptr32<const char> w3d_clip_804aa9a0;
void w3d_ctor_8015fef0(Ptr32<void>);
void w3d_base_destroy_8015ff2c(Ptr32<void>,int);
void w3d_handle_member_destroy_801265a4(Ptr32<void>,int);
Ptr32<void> w3d_fn_80164fc8(unsigned int);
Ptr32<void> w3d_fn_8020b680(Ptr32<void>);
unsigned int w3d_fn_80164514(Ptr32<void>,Ptr32<void>,unsigned int);
Ptr32<void> w3d_fn_800fc1f0(Ptr32<Ptr32<const char>>,Ptr32<unsigned int>);
Ptr32<void> w3d_fn_800fc6dc(unsigned int);
Ptr32<void> w3d_fn_800fc7f8(unsigned int);
void w3d_fn_8011adf8(Ptr32<W3dS1PopupUi>,Ptr32<unsigned char>,Ptr32<unsigned int>);
Ptr32<void> w3d_empty_80343584(unsigned int);
int w3d_fn_80181640(float,float,float,Ptr32<void>,Ptr32<const char>,Ptr32<int>,int);
Ptr32<void> w3d_registry_instance_80343810(void);
unsigned int w3d_buffer_storage_available(Ptr32<void>);
int w3d_mesh_instance_check_control(Ptr32<void>,int,int);
static inline void release_interface(unsigned int address)
{
    Ptr32<W3dS1Interface> object=(Ptr32<W3dS1Interface>)w3d::G(address);
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
void w3d_fn_8004862c(Ptr32<unsigned int> self,int flags)
{
    self[0]=(unsigned int)w3d::H(w3d_vtable_8040e978);
    release_interface(self[20]);
    release_interface(self[16]);
    release_interface(self[15]);
    release_interface(self[14]);
    release_interface(self[13]);
    release_interface(self[9]);
    release_interface(self[8]);
    w3d_base_destroy_8015ff2c(self,flags);
}
void w3d_fn_80048ec4(Ptr32<unsigned int> self)
{
    if(self[0x28/4])w3d_handle_member_destroy_801265a4((Ptr32<void>)w3d::G(self[0x28/4]),3);
    if(self[0x2c/4])w3d_handle_member_destroy_801265a4((Ptr32<void>)w3d::G(self[0x2c/4]),3);
    self[0x2c/4]=0;
}
void w3d_fn_80048fcc(Ptr32<unsigned int> self);
void w3d_fn_80048f1c(Ptr32<unsigned int> self)
{
    Ptr32<const char> key;
    unsigned int index;
    Ptr32<unsigned int> target=(Ptr32<unsigned int>)w3d_fn_80164fc8(self[0x1c/4]);
    if(target && target[0x1c/4]!=1 && target[0x1c/4]!=3) {
        key=w3d_str_803766d4;
        w3d_fn_800fc1f0(&key,&index);
        if(index<16) {
            Ptr32<unsigned char> actor=(Ptr32<unsigned char>)w3d_fn_800fc6dc(index);
            Ptr32<unsigned int> team=(Ptr32<unsigned int>)w3d_fn_800fc7f8(actor[0xd5]);
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
void w3d_fn_80049108(Ptr32<unsigned int> self)
{
    Ptr32<W3dS1Mesh> mesh=(Ptr32<W3dS1Mesh>)w3d::G(self[0x24/4]);
    if(mesh) {
        mesh->vtable->mode(mesh,1);
        Ptr32<void> instance=w3d_empty_80343584(self[0x24/4]);
        w3d_fn_80181640(w3d_f32_80376748[0],w3d_f32_8037674c[0],w3d_f32_8037674c[0],instance,w3d_str_80376740,(Ptr32<int>)(self+0x48/4),0);
    }
}
void w3d_fn_80049180(Ptr32<unsigned int> self)
{
    struct { int clip; int unused; } local;
    if(w3d_buffer_storage_available(w3d_registry_instance_80343810())>102399) {
        Ptr32<unsigned int> target=(Ptr32<unsigned int>)w3d_fn_80164fc8(self[0x1c/4]);
        if(target) {
            Ptr32<void> instance=w3d_empty_80343584(self[0x20/4]);
            if(target[0x1c/4]!=3)w3d_fn_80181640(1.0f,0.0f,0.0f,instance,w3d_str_80376750,&local.clip,0);
            Ptr32<const char> clip=0;
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


