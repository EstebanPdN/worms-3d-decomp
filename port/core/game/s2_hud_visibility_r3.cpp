#include "w3d_ptr.h"
#line 1 "s2_hud_visibility_r3.cpp"
/* Observed HUD resource and visibility fields; names are inferred. */
extern "C" {
struct HudResource { Ptr32<Ptr32<void (void)>> vtable; };
struct HudVector { int x,y,z; };
struct HudState {
    Ptr32<Ptr32<void (void)>> vtable;
    char unknown04[24];
    Ptr32<HudResource> first; Ptr32<HudResource> second;
    char unknown24[16];
    HudVector position;
    int visible;
    int property68, property72;
};
extern int w3d_global_804abab4;
Ptr32<void> w3d_engine_get_context();
Ptr32<HudResource> w3d_empty_80343580(Ptr32<HudResource>);
void w3d_auto_8018c5b0(Ptr32<HudResource>,int);
int w3d_fn_8018d35c(Ptr32<HudResource>,Ptr32<int>);
int w3d_fn_8018d434(Ptr32<HudResource>,Ptr32<int>);
void w3d_hud_refresh_8011bc28(Ptr32<HudState>);
int w3d_hud_visibility_8011ac1c(Ptr32<HudState> self) {
    if (self->visible) {
        if (*(Ptr32<int>)((Ptr32<char>)w3d_engine_get_context()+56) && !w3d_global_804abab4) {
            if(self->first) ((Ptr32<void (Ptr32<HudResource>, int)>)self->first->vtable[22])(self->first,0);
            if(self->second) ((Ptr32<void (Ptr32<HudResource>, int)>)self->second->vtable[22])(self->second,0);
        } else {
            if(self->first) ((Ptr32<void (Ptr32<HudResource>, int)>)self->first->vtable[22])(self->first,1);
            if(self->second) ((Ptr32<void (Ptr32<HudResource>, int)>)self->second->vtable[22])(self->second,1);
        }
    }
    return 0;
}
void w3d_hud_position_8011acf4(Ptr32<HudState> self,Ptr32<HudVector> pos) {
    if(self->second) {
        int same=0;
        Ptr32<HudVector> old=&self->position;
        int x=pos->x;
        if(x==old->x && pos->y==old->y) same=pos->z==old->z;
        if(!same) { self->position=*pos;
            ((Ptr32<void (Ptr32<HudState>)>)self->vtable[14])(self);
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
void w3d_hud_properties_8011adf8(Ptr32<HudState> self,Ptr32<int> a,Ptr32<int> b) {
    Ptr32<HudResource> resource=w3d_empty_80343580(self->first);
    self->property68=*a; self->property72=*b;
    w3d_fn_8018d35c(resource,a);
    w3d_fn_8018d434(resource,b);
}
inline void releaseResource(Ptr32<HudResource> &slot,Ptr32<HudResource> value) {
    if(slot) ((Ptr32<void (Ptr32<HudResource>)>)slot->vtable[4])(slot);
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
void w3d_hud_release_resources_8011af40(Ptr32<HudState> self) {
    releaseResource(self->first,0);
    releaseResource(self->second,0);
}
void w3d_hud_set_visible_8011afac(Ptr32<HudState> self,int visible) {
    Ptr32<HudResource> first=self->first;
    self->visible=visible;
    if(first) {
        ((Ptr32<void (Ptr32<HudResource>, int)>)first->vtable[22])(first,visible);
        ((Ptr32<void (Ptr32<HudResource>, int)>)self->second->vtable[22])(self->second,visible);
    }
}
}


