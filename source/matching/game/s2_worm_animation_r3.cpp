/* Worm graphic animation and attached effect helpers. */
extern "C" {
struct Object {void **vtable;};
struct Vec {float x,y,z;Vec(){}Vec(const Vec &v){x=v.x;y=v.y;z=v.z;}};
void w3d_empty_80343740(Vec *);
struct Matrix {Vec x,y,z,translation;Matrix(){w3d_empty_80343740(&translation);}};
struct Graphic {void **vtable;char unknown04[24];Object *mesh;char unknown20[20];Vec position;char unknown40[20];Object *current;char unknown58[20];Object *hidden,*worm;char unknown74[20];Object *pot;char unknown8c[24];Object *attachment;char unknowna8[4];Object *transform;char unknownb0[296];int control;char unknown1dc[16];int returnControl,state;char unknown1f4[36];Object *sound;char unknown21c[8];int effectId;Object *effect,*secondEffect;char unknown230[20];float elapsed;char unknown248[16];int resourceValue;char unknown25c[80];int mode;char unknown2b0[20];Object *optionA,*optionB,*blocked;};
struct Worm {char unknown00[132];int type;char unknown88[4];int label;char unknown90[26];unsigned short number;};
struct Context {char unknown00[56];int paused;};
struct Application {char unknown00[188];unsigned int flags;};
struct Resource {char unknown00[76];const char *animation;};
struct Component {char unknown00[32];Object *mesh;};
struct MeshState {char unknown00[56];Vec position;};
struct Ref {Object *value;int reserved;Ref(Object *p){value=p;if(value) ((void (*)(Object *))value->vtable[3])(value);}~Ref(){if(value) ((void (*)(Object *))value->vtable[4])(value);}};
Worm *w3d_fn_800fc6dc(int);
void *w3d_fn_80164fc8(Object *);
void w3d_fn_80140b24(void *,Vec *);
void w3d_worm_pot_set_second_text(void *,int);
void w3d_set_80140d78(void *,unsigned short);
void w3d_worm_pot_apply_pair(void *,int,int);
Object *w3d_empty_803426b4(Object *);
Object *w3d_auto_80178c48(Object *);
int w3d_auto_80178d1c(Object *);
Context *w3d_engine_get_context();
int w3d_auto_801359c8(Graphic *);
int w3d_fn_80181640(Object *,const char *,int *,int,float,float,float);
int w3d_mesh_instance_play_index(Object *,int,int *,int,float,float,float);
Object *w3d_empty_80343584(Object *);
int w3d_fn_80181e3c(Object *,int,Matrix *);
MeshState *w3d_mesh_instance_unbind(Object *);
void * w3d_fn_800fc330(const char **,Resource **);
int w3d_worm_play_named_801359ec(Graphic *,Object *,const char *,int *,float,float,float);
int w3d_mesh_instance_control_3c(Object *,int);
void w3d_fn_800e5bb8(Object *);
void *w3d_fn_801613f0(void *,int);
int w3d_cached_message_id(void *,int);
void *w3d_int_message_init_80125fdc(void *,unsigned short,int);
int w3d_message_post_current(void *);
void w3d_worm_graphic_release_effect(Graphic *);
int w3d_mesh_instance_set_resource_value(Object *,int);
extern Application *w3d_obj_804b1788;
extern int w3d_obj_804abab4,w3d_obj_804ab324,w3d_obj_804ab328,w3d_obj_804ab338,w3d_obj_804af840;
extern void *w3d_obj_804b1754;
extern const char *w3d_obj_804ab100;
extern const char *w3d_obj_803eb63c[];
extern const float w3d_f32_8039f634[],w3d_f32_8039f638[],w3d_f32_8039f63c[],w3d_f32_8039f654[],w3d_f32_8039f658[],w3d_f32_8039f65c[];
#if 0 // Excluded after two attempts: matrix and vector temporaries change saved-register allocation.
void w3d_worm_update_pot_8013586c(Graphic *self) {
    void *pot=w3d_fn_80164fc8(self->pot);
    struct {Matrix transform;Vec copy;} local;
    ((void (*)(Object *,Matrix *))self->transform->vtable[31])(self->transform,&local.transform);
    local.copy.x=local.transform.translation.x;local.copy.y=local.transform.translation.y;local.copy.z=local.transform.translation.z;
    w3d_fn_80140b24(pot,&self->position);
    w3d_worm_pot_set_second_text(pot,w3d_fn_800fc6dc((int)self->worm)->label);
    w3d_set_80140d78(pot,w3d_fn_800fc6dc((int)self->worm)->number);
    if(self->worm==w3d_auto_80178c48(w3d_empty_803426b4(self->current)) || w3d_auto_80178d1c(self->blocked) || w3d_auto_80178d1c(self->hidden) || w3d_engine_get_context()->paused || ((w3d_obj_804b1788->flags&4) && !w3d_obj_804abab4)) w3d_worm_pot_apply_pair(pot,0,0);
    else {int first=1;if(!w3d_auto_80178d1c(self->optionB)) first=0;int second=1;if(!w3d_auto_80178d1c(self->optionA)) second=0;w3d_worm_pot_apply_pair(pot,first,second);}
}
#endif
int w3d_worm_play_named_801359ec(Graphic *self,Object *mesh,const char *name,int *control,float speed,float start,float end) {
    struct Gap {float values[6];~Gap(){}} scratch;
    if(!w3d_auto_801359c8(self)) return w3d_fn_80181640(mesh,name,control,0,speed,start,end);
    return 0;
}
int w3d_worm_play_index_80135a70(Graphic *self,Object *mesh,int index,int *control,float speed,float start,float end) {
    struct Gap {float values[6];~Gap(){}} scratch;
    if(!w3d_auto_801359c8(self)) return w3d_mesh_instance_play_index(mesh,index,control,0,speed,start,end);
    return 0;
}
#if 0 // Excluded after two attempts: matrix and returned vector temporary layout and branch tails differ.
Vec w3d_worm_attachment_position_80135af4(Graphic *self) {
    if(self->mode==47) return self->position;
    Vec result;
    if(self->attachment) {
        Matrix transform;
        Object *mesh=w3d_empty_80343584(self->attachment);
        if(w3d_fn_80181e3c(mesh,w3d_obj_804ab324,&transform)>=0) result=transform.translation;
        else result=w3d_mesh_instance_unbind(mesh)->position;
    } else {
        Matrix transform;
        w3d_fn_80181e3c(w3d_empty_80343584(self->mesh),w3d_obj_804ab328,&transform);
        result=transform.translation;
    }
    return result;
}
#endif
void w3d_worm_play_type_animation_80138d24(Graphic *self) {
    Resource *resource;
    w3d_fn_800fc330(&w3d_obj_803eb63c[w3d_fn_800fc6dc((int)self->worm)->type],&resource);
    const char *name=resource->animation;
    if(*name) w3d_worm_play_named_801359ec(self,self->mesh,name,&self->control,w3d_f32_8039f634[0],w3d_f32_8039f638[0],w3d_f32_8039f63c[0]);
}
void w3d_worm_restore_animation_80139084(Graphic *self,int clear) {
    if(self->sound) ((void (*)(Object *))self->sound->vtable[6])(self->sound);
    if(self->state==10) {
        if(clear) {
            w3d_mesh_instance_control_3c(self->mesh,-1);
            w3d_worm_play_named_801359ec(self,self->mesh,w3d_obj_804ab100,&self->returnControl,w3d_f32_8039f654[0],w3d_f32_8039f658[0],w3d_f32_8039f65c[0]);
        } else w3d_worm_play_named_801359ec(self,self->mesh,w3d_obj_804ab100,&self->returnControl,w3d_f32_8039f654[0],w3d_f32_8039f658[0],w3d_f32_8039f65c[0]);
        self->state=0;
    }
    self->elapsed=w3d_f32_8039f65c[0];
}
int w3d_worm_is_current_80139158(Graphic *self) {
    return self->worm==w3d_auto_80178c48(w3d_empty_803426b4(self->current));
}
void w3d_worm_release_effects_8013919c(Graphic *self) {
    if(self->effect) w3d_fn_800e5bb8(self->effect);
    void *message=w3d_fn_801613f0(w3d_obj_804b1754,12);
    w3d_message_post_current(w3d_int_message_init_80125fdc(message,(unsigned short)w3d_cached_message_id(&w3d_obj_804af840,1),self->effectId));
    if(self->secondEffect) w3d_fn_800e5bb8(self->secondEffect);
    if(self->effect) {w3d_fn_800e5bb8(self->effect);self->effect=0;}
    w3d_worm_graphic_release_effect(self);
}
void w3d_worm_attach_resource_801397b0(Graphic *self,Object *source) {
    Component *component=(Component *)w3d_fn_80164fc8(source);
    if(component) {
        Object *mesh;
        {Ref ref(component->mesh);mesh=w3d_empty_80343584(ref.value);}
        ((void (*)(Object *,Object *,int))self->mesh->vtable[23])(self->mesh,mesh,w3d_obj_804ab338);
        w3d_mesh_instance_set_resource_value(mesh,self->resourceValue);
    }
}
}
