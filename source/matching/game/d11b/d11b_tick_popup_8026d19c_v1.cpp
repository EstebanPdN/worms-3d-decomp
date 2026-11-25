inline void *operator new(unsigned int,void *p) { return p; }
// Partial popup rotation owner and callback views. Vector components are the
// three float fields actually written and passed; no full-class sizeof claim.
struct d11b_PopupVector {
    float x,y,z;
    d11b_PopupVector() {}
    d11b_PopupVector(float a,float b,float c):x(a),y(b),z(c) {}
    d11b_PopupVector &operator=(const d11b_PopupVector &v) { x=v.x;y=v.y;z=v.z;return *this; }
};
struct d11b_PopupRotator;
struct d11b_PopupRotationTable { unsigned int unknown00[20]; void (*rotate)(d11b_PopupRotator *,const d11b_PopupVector *,int); };
struct d11b_PopupRotator { d11b_PopupRotationTable *vtable; };
struct d11b_PopupClock { unsigned char unknown00[72]; d11b_PopupRotator *first,*second; unsigned int unknown50; int lastTick; };
extern float d11b_popup_phase_804abb80,d11b_popup_angle_804abb84;
extern "C" int d11b_tick_popup_8026d19c(d11b_PopupClock *self,int now) {
    int remaining=now-self->lastTick;
    if (remaining>100) remaining=100;
    while (remaining>19) {
        d11b_popup_phase_804abb80+=0.01f;
        d11b_popup_angle_804abb84+=0.01f;
        if (d11b_popup_phase_804abb80>5.0f) d11b_popup_phase_804abb80=1.0f;
        if (self->first) {
            d11b_PopupVector rotation(0.0f,d11b_popup_angle_804abb84,0.0f);
            self->first->vtable->rotate(self->first,&rotation,0);
            new (&rotation) d11b_PopupVector(0.4712389409542084f,0.0f,0.0f);
            if (self->second) self->second->vtable->rotate(self->second,&rotation,0);
        }
        remaining-=20;
    }
    self->lastTick=now-remaining;
    return 0;
}
