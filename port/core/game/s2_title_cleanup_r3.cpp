#include "w3d_ptr.h"
#line 1 "s2_title_cleanup_r3.cpp"
/* Restores camera settings and releases title-screen handles. */
extern "C" {
struct Object { Ptr32<Ptr32<void>> vtable; };
struct Title { char unknown00[28]; Ptr32<Object> first[4]; char unknown2c[12]; Ptr32<Object> camera; Ptr32<Object> other[3]; char unknown48[8]; Ptr32<Object> last[4]; };
struct Context { char unknown00[48]; Ptr32<Object> camera; };
struct Display { char unknown00[116]; Ptr32<Object> screen; };
struct Vec { float x,y,z; };
extern const float w3d_f32_8039b54c[],w3d_f32_8039b550[];
extern const char w3d_str_8039b40c[];
extern Ptr32<Context> w3d_obj_804b1788;
extern Ptr32<Display> w3d_obj_804b17ec;
void w3d_text_format_803442b4(Ptr32<void>,Ptr32<const char>,...);
inline void clear(Ptr32<Object> &slot,Ptr32<Object> replacement) {
    if(slot) ((Ptr32<void (Ptr32<Object>)>)slot->vtable[4])(slot);
    slot=replacement;
}
void w3d_title_default_vector_8011f2c8(Ptr32<void> self,Ptr32<Vec> out) {
    float a=w3d_f32_8039b54c[0],b=w3d_f32_8039b550[0];
    out->x=a; out->y=b; out->z=a;
}
inline void release(Ptr32<Object> value) { if(value) ((Ptr32<void (Ptr32<Object>)>)value->vtable[4])(value); }
// Excluded after two attempts: null-store scheduling and call setup differ.
#if 0
void w3d_title_cleanup_8011f2e8(Title *self) {
    if(self->camera) {
        ((void (*)(Object *,void *))w3d_obj_804b1788->camera->vtable[10])(w3d_obj_804b1788->camera,((void *(*)(Object *))self->camera->vtable[9])(self->camera));
        ((void (*)(Object *,void *))w3d_obj_804b1788->camera->vtable[11])(w3d_obj_804b1788->camera,((void *(*)(Object *))self->camera->vtable[14])(self->camera));
        ((void (*)(Object *,void *))w3d_obj_804b1788->camera->vtable[12])(w3d_obj_804b1788->camera,((void *(*)(Object *))self->camera->vtable[15])(self->camera));
        ((void (*)(Object *,void *))w3d_obj_804b1788->camera->vtable[13])(w3d_obj_804b1788->camera,((void *(*)(Object *))self->camera->vtable[16])(self->camera));
    }
    release(self->camera);
    self->camera=0;
    if(self->other[0]) ((void (*)(Object *))self->other[0]->vtable[4])(self->other[0]);
    self->other[0]=0;
    if(self->other[1]) ((void (*)(Object *))self->other[1]->vtable[4])(self->other[1]);
    self->other[1]=0;
    if(self->other[2]) ((void (*)(Object *))self->other[2]->vtable[4])(self->other[2]);
    self->other[2]=0;
    clear(self->first[0],0); clear(self->first[1],0); clear(self->first[2],0); clear(self->first[3],0);
    char text[32];
    Object *screen=w3d_obj_804b17ec->screen;
    void **vtable=screen->vtable;
    w3d_text_format_803442b4(text,w3d_str_8039b40c);
    ((void (*)(Object *,char *,int))vtable[49])(screen,text,4);
    clear(self->last[0],0); clear(self->last[1],0); clear(self->last[2],0); clear(self->last[3],0);
}
#endif
}


