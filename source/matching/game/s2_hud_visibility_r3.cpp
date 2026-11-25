/* Observed HUD resource and visibility fields; names are inferred. */
extern "C" {
struct HudResource { void (**vtable)(); };
struct HudVector { int x,y,z; };
struct HudState {
    void (**vtable)();
    char unknown04[24];
    HudResource *first, *second;
    char unknown24[16];
    HudVector position;
    int visible;
    int property68, property72;
};
extern int w3d_global_804abab4;
void *w3d_engine_get_context();
HudResource *w3d_empty_80343580(HudResource *);
void w3d_auto_8018c5b0(HudResource *,int);
int w3d_fn_8018d35c(HudResource *,int *);
int w3d_fn_8018d434(HudResource *,int *);
void w3d_hud_refresh_8011bc28(HudState *);
int w3d_hud_visibility_8011ac1c(HudState *self) {
    if (self->visible) {
        if (*(int *)((char *)w3d_engine_get_context()+56) && !w3d_global_804abab4) {
            if(self->first) ((void (*)(HudResource *,int))self->first->vtable[22])(self->first,0);
            if(self->second) ((void (*)(HudResource *,int))self->second->vtable[22])(self->second,0);
        } else {
            if(self->first) ((void (*)(HudResource *,int))self->first->vtable[22])(self->first,1);
            if(self->second) ((void (*)(HudResource *,int))self->second->vtable[22])(self->second,1);
        }
    }
    return 0;
}
void w3d_hud_position_8011acf4(HudState *self,HudVector *pos) {
    if(self->second) {
        int same=0;
        HudVector *old=&self->position;
        int x=pos->x;
        if(x==old->x && pos->y==old->y) same=pos->z==old->z;
        if(!same) { self->position=*pos;
            ((void (*)(HudState *))self->vtable[14])(self);
        }
    }
}
// Excluded: argument-address setup order differs after three attempts.
#if 0
void w3d_hud_resource_update_8011ad90(HudState *self,int value) {
    if(self->first) {
        HudResource *resource=w3d_empty_80343580(self->first);
        w3d_auto_8018c5b0(resource,value);
        int *property=&self->property68;
        w3d_fn_8018d35c(resource,property);
        w3d_fn_8018d434(resource,&self->property72);
        w3d_hud_refresh_8011bc28(self);
    }
}
#endif
void w3d_hud_properties_8011adf8(HudState *self,int *a,int *b) {
    HudResource *resource=w3d_empty_80343580(self->first);
    self->property68=*a; self->property72=*b;
    w3d_fn_8018d35c(resource,a);
    w3d_fn_8018d434(resource,b);
}
inline void releaseResource(HudResource *&slot,HudResource *value) {
    if(slot) ((void (*)(HudResource *))slot->vtable[4])(slot);
    slot=value;
}
#if 0
void unused_release(HudState *self) {
    if(self->first) ((void (*)(HudResource *))self->first->vtable[4])(self->first);
    HudResource *second=self->second;
    self->first=0;
    if(second) ((void (*)(HudResource *))second->vtable[4])(second);
    self->second=0;
}
#endif
void w3d_hud_release_resources_8011af40(HudState *self) {
    releaseResource(self->first,0);
    releaseResource(self->second,0);
}
void w3d_hud_set_visible_8011afac(HudState *self,int visible) {
    HudResource *first=self->first;
    self->visible=visible;
    if(first) {
        ((void (*)(HudResource *,int))first->vtable[22])(first,visible);
        ((void (*)(HudResource *,int))self->second->vtable[22])(self->second,visible);
    }
}
}
