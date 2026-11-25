#include "w3d_ptr.h"
#line 1 "s1_energy_display.cpp"
/* Observed team-energy display resource and geometry updates. */
extern "C" {
struct W3dS1EnergyVec {
    float x,y,z;
    W3dS1EnergyVec() {}
    W3dS1EnergyVec(float a,float b,float c):x(a),y(b),z(c) {}
    W3dS1EnergyVec(const W3dS1EnergyVec &a) {float xx=a.x,yy=a.y,zz=a.z;x=xx;y=yy;z=zz;}
    W3dS1EnergyVec &operator=(const W3dS1EnergyVec &a) {x=a.x;y=a.y;z=a.z;return *this;}
};
struct W3dS1EnergyValue { float value;W3dS1EnergyValue(float x):value(x) {} };
struct W3dS1EnergyRef;
struct W3dS1EnergyTable { Ptr32<void (void)> unused0[4];Ptr32<void (Ptr32<W3dS1EnergyRef>)> release;Ptr32<void (void)> unused5[14];Ptr32<void (Ptr32<W3dS1EnergyRef>, Ptr32<W3dS1EnergyVec>, int)> position;Ptr32<void (void)> unused20[2];Ptr32<void (Ptr32<W3dS1EnergyRef>, int)> visible; };
struct W3dS1EnergyRef { Ptr32<W3dS1EnergyTable> vtable; };
struct W3dS1Energy { char unknown[28];Ptr32<W3dS1EnergyRef> bar; Ptr32<W3dS1EnergyRef> flag; Ptr32<W3dS1EnergyRef> text;float desired,current;unsigned int team;int alliance,count;W3dS1EnergyVec position;char unknown48[12];float scale;unsigned int blinking,visible,transition,last;Ptr32<void> text_scale; Ptr32<void> spacing; Ptr32<void> offscreen; Ptr32<void> onscreen; Ptr32<void> text_offset; Ptr32<void> bar_offset; Ptr32<void> flag_xscale; Ptr32<void> flag_yscale; Ptr32<void> scroll; Ptr32<void> decrease; Ptr32<void> bar_height; };
extern const float w3d_f32_80379d30[],w3d_f32_80379d34[],w3d_f32_80379d38[],w3d_f32_80379d3c[],w3d_f32_80379db8[],w3d_f32_80379dbc[],w3d_f32_80379dc0[];
float w3d_auto_80178df0(Ptr32<void>);
float fabs(float);
Ptr32<void> w3d_empty_8034380c(Ptr32<void>);
Ptr32<float> w3d_fn_8018963c(Ptr32<void>);
Ptr32<float> w3d_fn_80189518(Ptr32<void>);
void w3d_fn_800642ac(Ptr32<W3dS1Energy>);
static inline void energy_clear(Ptr32<W3dS1EnergyRef> &slot,Ptr32<W3dS1EnergyRef> next) { if(slot)slot->vtable->release(slot);slot=next; }
void w3d_fn_80064104(Ptr32<W3dS1Energy> self)
{
    energy_clear(self->bar,0);energy_clear(self->flag,0);energy_clear(self->text,0);
}
void w3d_fn_80064198(Ptr32<W3dS1Energy> self)
{
    W3dS1EnergyVec text(self->position),bar(self->position);
    Ptr32<W3dS1EnergyVec> position=&self->position;
    text.x+=w3d_auto_80178df0(self->text_offset);
    bar.x+=w3d_auto_80178df0(self->bar_offset);
    self->text->vtable->position(self->text,&text,0);
    self->bar->vtable->position(self->bar,&bar,0);
    self->flag->vtable->position(self->flag,position,0);
}
#if 0 /* Excluded: aggregate temporaries and floating-point allocation differ after four attempts. */
void w3d_fn_800642ac(W3dS1Energy *self)
{
    void *bar=w3d_empty_8034380c(self->bar);
    float extent=self->scale*self->current;
    float height=w3d_auto_80178df0(self->bar_height);
    float *bounds=w3d_fn_8018963c(bar);
    bounds[3]=height;
    float half=extent*w3d_f32_80379d30[0];bounds[2]=half;
    float *vertices=w3d_fn_80189518(bar);
    *(W3dS1EnergyVec *)(vertices+3)=W3dS1EnergyVec(half+w3d_f32_80379d34[0],w3d_f32_80379d38[0],w3d_f32_80379d38[0]);
    vertices=w3d_fn_80189518(bar);
    *(W3dS1EnergyVec *)(vertices+6)=W3dS1EnergyVec(extent+w3d_f32_80379d3c[0],w3d_f32_80379d38[0],w3d_f32_80379d38[0]);
}
#endif
static inline float energy_abs(const float &value) {return fabs(value);}
#if 0 /* Excluded: eight-byte stack gap remains different after four attempts. */
int w3d_fn_80064950(W3dS1Energy *self)
{
    int complete=0;
    W3dS1EnergyValue local(self->current-self->desired);
    float difference=local.value;
    float rate=w3d_auto_80178df0(self->decrease);
    if(energy_abs(difference)<w3d_f32_80379db8[0] || difference<w3d_f32_80379dbc[0] || rate>difference) {
        self->current=self->desired;complete=1;
    } else self->current-=rate;
    w3d_fn_800642ac(self);
    return complete;
}
#endif
void w3d_fn_800649e8(Ptr32<W3dS1Energy> self,int visible)
{
    if(self->desired!=w3d_f32_80379dc0[0] || self->visible) {
        self->visible=visible;
        self->text->vtable->visible(self->text,visible);self->bar->vtable->visible(self->bar,visible);self->flag->vtable->visible(self->flag,visible);
    }
}
}


