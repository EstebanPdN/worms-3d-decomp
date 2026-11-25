#include "w3d_ptr.h"
#line 1 "s2_transition_dispatch_r3.cpp"
/* Transition service messages and resource setup. */
extern "C" {
struct Object { Ptr32<Ptr32<void>> vtable; };
struct Transition { Ptr32<Ptr32<void>> vtable; char unknown04[24]; Ptr32<Object> resource; Ptr32<Object> other; Ptr32<Object> mesh; };
struct String { Ptr32<char> text; int reserved; };
struct Ref { Ptr32<Object> value; int reserved; Ref() {value=0;} Ref(Ptr32<Object> w3d_p) : Ref((Object *)w3d_p.get()) {}
 Ref(Object *p) {value=p;if(value) ((Ptr32<void (Ptr32<Object>)>)value->vtable[3])(value);} ~Ref() {if(value) ((Ptr32<void (Ptr32<Object>)>)value->vtable[4])(value);} };
struct Vector { float x,y,z; };
struct Context { char unknown00[184]; float fraction; };
struct Dirty { char unknown[4]; unsigned char flags; char w3d_tag_rest[3]; void mark() {flags|=2;} };
struct Options { Ptr32<Ptr32<void>> vtable; Dirty dirty; char unknown0c[20]; int mode,enabled; };
void w3d_transition_service_attach_801242e0(Ptr32<Transition>);
void w3d_transition_service_detach_801243b0(Ptr32<Transition>);
void w3d_transition_service_circle_in_80124424(Ptr32<Transition>);
void w3d_transition_service_circle_out_801244d8(Ptr32<Transition>);
int w3d_auto_8016293c(Ptr32<Transition>,Ptr32<unsigned short>);
void w3d_auto_8015fd1c(Ptr32<Transition>);
int w3d_fn_8015f620(Ptr32<void>,unsigned short);
void w3d_string_from_text(Ptr32<String>,Ptr32<const char>);
void w3d_string_base_finish(Ptr32<String>);
void w3d_string_release(Ptr32<String>);
void w3d_handle_set_name(Ptr32<String>,Ptr32<Ptr32<Object>>,int);
Ptr32<Object> w3d_empty_80343584(Ptr32<Object>);
Ptr32<Object> w3d_fn_8020b680(Ptr32<void>);
extern unsigned int w3d_obj_804af4f0,w3d_obj_804af4f8,w3d_obj_804af500;
extern Ptr32<Context> w3d_obj_804b1788;
extern const char w3d_str_8039b868[];
extern const float w3d_f32_8039b878[],w3d_f32_8039b87c[];
extern char w3d_obj_80415c10[],w3d_obj_80416560[],w3d_obj_8040e078[];
inline void retain(Ptr32<Object> value) { if(value) ((Ptr32<void (Ptr32<Object>)>)value->vtable[3])(value); }
inline void release(Ptr32<Object> value) { if(value) ((Ptr32<void (Ptr32<Object>)>)value->vtable[4])(value); }
inline void assign(Ptr32<Object> &slot,Ptr32<Object> value) { retain(value); release(slot); slot=value; }
inline void setEnabled(Ptr32<Options> self,int value) { self->enabled=value; self->dirty.mark(); }
inline void setMode(Ptr32<Options> self,int value) { self->mode=value; self->dirty.mark(); }
#if 0 // Excluded after two attempts: switch copy and saved-register allocation differ.
int w3d_transition_dispatch_801241d0(Transition *self,unsigned short *message) {
    unsigned short id=*message;
    switch(*message) {
    case 64:
        if(w3d_auto_8016293c(self,message)>=0) { w3d_transition_service_attach_801242e0(self); return 0; }
        return 0x80004005;
    case 66: w3d_transition_service_detach_801243b0(self); break;
    default:
        if(w3d_fn_8015f620(&w3d_obj_804af4f8,id)) w3d_transition_service_circle_in_80124424(self);
        else if(w3d_fn_8015f620(&w3d_obj_804af4f0,id)) w3d_transition_service_circle_out_801244d8(self);
        else if(w3d_fn_8015f620(&w3d_obj_804af500,id)) w3d_auto_8015fd1c(self);
    }
    return w3d_auto_8016293c(self,message);
}
#endif
int w3d_transition_setup_options_80124668(Ptr32<Transition> self) {
    Ref options(w3d_fn_8020b680(w3d_obj_80415c10));
    setEnabled((Ptr32<Options>)options.value,1); setMode((Ptr32<Options>)options.value,7);
    Ref output;
    ((Ptr32<void (Ptr32<Transition>, Ptr32<void>, int, Ptr32<Ptr32<Object>>)>)self->vtable[14])(self,w3d_obj_8040e078,0,&output.value);
    Ptr32<Object> target=output.value;
    Ref service(w3d_fn_8020b680(w3d_obj_80416560));
    ((Ptr32<void (Ptr32<Object>, Ptr32<Object>)>)service.value->vtable[12])(service.value,options.value);
    ((Ptr32<void (Ptr32<Object>, Ptr32<Object>)>)service.value->vtable[6])(service.value,target);
    return 0;
}
#if 0 // Excluded after two attempts: string/vector temporary layout and registers differ.
void w3d_transition_load_mesh_801247d0(Transition *self) {
    struct { int a,b; } scratch;
    Object **slot=&self->resource;
    if(!self->resource) {
        struct {String name;Vector scale;} local;
        w3d_string_from_text(&local.name,w3d_str_8039b868);
        w3d_handle_set_name(&local.name,slot,34);
        w3d_string_base_finish(&local.name); w3d_string_release(&local.name);
        Object *mesh=w3d_empty_80343584(self->resource);
        assign(self->mesh,mesh);
        float value=w3d_obj_804b1788->fraction;
        float one=w3d_f32_8039b878[0];
        value=value*w3d_f32_8039b87c[0]+(one-value);
        local.scale.y=value; local.scale.x=value; local.scale.z=one;
        ((void (*)(Object *,Vector *,int))mesh->vtable[21])(mesh,&local.scale,0);
    }
}
#endif
}


