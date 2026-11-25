/* Restores camera settings and releases title-screen handles. */
extern "C" {
struct Object { void **vtable; };
struct Title { char unknown00[28]; Object *first[4]; char unknown2c[12]; Object *camera,*other[3]; char unknown48[8]; Object *last[4]; };
struct Context { char unknown00[48]; Object *camera; };
struct Display { char unknown00[116]; Object *screen; };
struct Vec { float x,y,z; };
extern const float w3d_f32_8039b54c[],w3d_f32_8039b550[];
extern const char w3d_str_8039b40c[];
extern Context *w3d_obj_804b1788;
extern Display *w3d_obj_804b17ec;
void w3d_text_format_803442b4(void *,const char *,...);
inline void clear(Object *&slot,Object *replacement) {
    if(slot) ((void (*)(Object *))slot->vtable[4])(slot);
    slot=replacement;
}
void w3d_title_default_vector_8011f2c8(void *self,Vec *out) {
    float a=w3d_f32_8039b54c[0],b=w3d_f32_8039b550[0];
    out->x=a; out->y=b; out->z=a;
}
inline void release(Object *value) { if(value) ((void (*)(Object *))value->vtable[4])(value); }
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
