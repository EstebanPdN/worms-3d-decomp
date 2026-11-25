/* Worm attachment resources, light values and angle helpers. */
extern "C" {
struct Object {void **vtable;};
struct Vec {float x,y,z;Vec(){}Vec(float a,float b,float c){x=a;y=b;z=c;}Vec(const Vec &v){x=v.x;y=v.y;z=v.z;} };
struct Graphic {char unknown00[28];Object *mesh;char unknown20[80];int handle;char unknown74[24];int prop140,prop144,prop148;char unknown98[320];int controlA,controlB;char unknown1e0[116];Object *wormLight,*weaponLight;char unknown25c[136];int state;};
struct Component {char unknown00[32];Object *mesh;};
struct Display {char unknown00[116];Object *service;};
struct Ref {Object *value;int reserved;Ref(Object *p){value=p;if(value) ((void (*)(Object *))value->vtable[3])(value);}~Ref(){if(value) ((void (*)(Object *))value->vtable[4])(value);}};
void *w3d_fn_80164fc8(int);
Object *w3d_empty_80343584(Object *);
struct RawRef {Object *value;int reserved;};
void * w3d_fn_800ccd04(RawRef *,void *);
int w3d_mesh_instance_set_resource_value(Object *,Object *);
void w3d_fn_80182408(Object *);
void w3d_text_format_803442b4(void *,const char *,...);
Vec w3d_fn_800cd0d0(void *);
int w3d_fn_800cd7fc(void *);
int w3d_mesh_instance_is_playing(Object *,int);
float w3d_fn_800cd13c(void *);
int w3d_worm_play_named_801359ec(Graphic *,Object *,const char *,int *,float,float,float);
float w3d_getf_800ae9ac(void *);
float w3d_getf_800ae9b4(void *);
float w3d_fn_800da4a8(void *);
int w3d_fn_80181814(Object *,const char *,float,float);
float w3d_fn_802e82c0(float);
float w3d_fn_802e83ec(float);
extern int w3d_obj_804ab338,w3d_obj_804ab334;
extern const char *w3d_obj_804ab18c,*w3d_obj_804ab190,*w3d_obj_804ab16c,*w3d_obj_804ab180,*w3d_obj_804ab17c,*w3d_obj_804ab198;
extern Display *w3d_obj_804b17ec;
extern const char w3d_str_8039f6a0[],w3d_str_8039f6b0[];
extern const float w3d_f32_8039f6e4[],w3d_f32_8039f6e8[],w3d_f32_8039f6ec[],w3d_f32_8039f6f0[],w3d_f32_8039f78c[],w3d_f32_8039f790[],w3d_f32_8039f794[],w3d_f32_8039f800[];
inline void assign(Object *&slot,Object *p) {if(p) ((void (*)(Object *))p->vtable[3])(p);if(slot) ((void (*)(Object *))slot->vtable[4])(slot);slot=p;}
void w3d_worm_attach_alternate_80139858(Graphic *self,int source) {
    Component *component=(Component *)w3d_fn_80164fc8(source);
    if(component) {
        Object *mesh;
        {Ref ref(component->mesh);mesh=w3d_empty_80343584(ref.value);}
        ((void (*)(Object *,Object *,int))self->mesh->vtable[23])(self->mesh,mesh,w3d_obj_804ab338);
        w3d_mesh_instance_set_resource_value(mesh,self->weaponLight);
    }
}
void w3d_worm_attach_component_mesh_80139900(Graphic *self,int source) {
    void *component=w3d_fn_80164fc8(source);
    if(component) {
        Object *mesh;
        {RawRef ref;w3d_fn_800ccd04(&ref,component);mesh=w3d_empty_80343584(ref.value);if(ref.value) ((void (*)(Object *))ref.value->vtable[4])(ref.value);}
        ((void (*)(Object *,Object *,int))self->mesh->vtable[23])(self->mesh,mesh,w3d_obj_804ab334);
        w3d_mesh_instance_set_resource_value(mesh,self->weaponLight);
    }
}
#if 0 // Excluded after two compilation passes: buffer pointer and saved-register allocation differ.
void w3d_worm_load_lights_80139a04(Graphic *self) {
    char text[32];char *buffer=text;
    Object *service=w3d_obj_804b17ec->service;void **vtable=service->vtable;
    w3d_text_format_803442b4(buffer,w3d_str_8039f6a0,self->handle);
    Object *worm=((Object *(*)(Object *,char *,int))vtable[50])(service,buffer,4);
    service=w3d_obj_804b17ec->service;vtable=service->vtable;
    w3d_text_format_803442b4(buffer,w3d_str_8039f6b0,self->handle);
    Object *weapon=((Object *(*)(Object *,char *,int))vtable[50])(service,buffer,4);
    assign(self->wormLight,worm);assign(self->weaponLight,weapon);
    w3d_fn_80182408(self->mesh);w3d_mesh_instance_set_resource_value(self->mesh,self->wormLight);
}
#endif
void w3d_worm_update_movement_80139f1c(Graphic *self,Object *mesh) {
    void *component=w3d_fn_80164fc8(self->prop140);
    if(!component) {self->prop140=-1;return;}
    {void **vtable=mesh->vtable;const Vec &position=w3d_fn_800cd0d0(component);
    ((void (*)(Object *,const Vec *,int))vtable[20])(mesh,&position,0); }
    self->state=w3d_fn_800cd7fc(component);
    if(w3d_mesh_instance_is_playing(mesh,self->controlA)) {
        float value=w3d_fn_800cd13c(component),zero=w3d_f32_8039f6e4[0];
        if(value>zero) w3d_worm_play_named_801359ec(self,mesh,w3d_obj_804ab18c,&self->controlA,w3d_f32_8039f6e8[0],zero,zero);
        else if(value<zero) w3d_worm_play_named_801359ec(self,mesh,w3d_obj_804ab190,&self->controlA,w3d_f32_8039f6e8[0],zero,zero);
    }
    if(w3d_mesh_instance_is_playing(mesh,self->controlB)) w3d_worm_play_named_801359ec(self,mesh,w3d_obj_804ab16c,&self->controlB,w3d_f32_8039f6e8[0],w3d_f32_8039f6e4[0],w3d_f32_8039f6e4[0]);
}
#if 0 // Excluded after two compilation passes: floating-point constant lifetime and register allocation differ.
void w3d_worm_update_blend_pair_8013a048(Graphic *self,Object *mesh) {
    if(self->prop144!=-1) {
        void *component=w3d_fn_80164fc8(self->prop144);
        if(!component) {self->prop144=-1;return;}
        {
            const char *first=w3d_obj_804ab180;
            float value=w3d_getf_800ae9ac(component);
            w3d_fn_80181814(mesh,first,value,w3d_f32_8039f6ec[0]);
            const char *second=w3d_obj_804ab17c;
            value=w3d_getf_800ae9b4(component);
            w3d_fn_80181814(mesh,second,value,w3d_f32_8039f6ec[0]);
        }
    }
}
#endif
void w3d_worm_update_blend_8013a0d4(Graphic *self,Object *mesh) {
    if(self->prop148!=-1) {
        void *component=w3d_fn_80164fc8(self->prop148);
        if(!component) {self->prop148=-1;return;}
        {
            if(w3d_mesh_instance_is_playing(mesh,self->controlA)==1) {
                const char *name=w3d_obj_804ab198;
                w3d_fn_80181814(mesh,name,w3d_fn_800da4a8(component),w3d_f32_8039f6f0[0]);
            }
        }
    }
}
float w3d_angle_delta_8013aa10(float a,float b) {
    a=a-b;
    if(a>w3d_f32_8039f78c[0]) a=-(w3d_f32_8039f790[0]-a);
    else if(a<w3d_f32_8039f794[0]) a=a+w3d_f32_8039f790[0];
    return a;
}
#if 0 // Excluded after two compilation passes: vector temporary stores and floating-point evaluation scheduling differ.
float w3d_vector_elevation_8013b898(void *self,const Vec *a,const Vec *b) {
    Vec difference(a->x-b->x,a->y-b->y,a->z-b->z);
    Vec horizontal(difference);horizontal.y=w3d_f32_8039f800[0];
    return w3d_fn_802e83ec(difference.y/w3d_fn_802e82c0(horizontal.x*horizontal.x+horizontal.y*horizontal.y+horizontal.z*horizontal.z));
}
#endif
}
