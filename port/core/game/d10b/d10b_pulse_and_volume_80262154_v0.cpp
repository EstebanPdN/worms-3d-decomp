#include "w3d_ptr.h"
#line 1 "d10b_pulse_and_volume_80262154_v0.cpp"
// Partial owner/audio service views; full original classes and sizeof unknown.
struct d10b_PulseColor {
    unsigned char red,green,blue,alpha;
    inline void set(unsigned char r,unsigned char g,unsigned char b,unsigned char a) {red=r;green=g;blue=b;alpha=a;}
};
struct d10b_PulseOwner {
    unsigned char unknown00[188]; float phase;
    unsigned int unknownc0; int countdown;
    unsigned char unknownc8[16]; d10b_PulseColor color;
};
struct d10b_Mixer;
struct d10b_MixerVtable { unsigned int unknown00[32]; Ptr32<void (Ptr32<d10b_Mixer>, float, unsigned int)> set_volume; };
struct d10b_Mixer { Ptr32<d10b_MixerVtable> vtable; };
struct d10b_MixerServices { unsigned char unknown00[108]; Ptr32<d10b_Mixer> mixer; };
extern Ptr32<d10b_MixerServices> d10b_services_804b1788;
extern const float d10b_period_803caea4[],d10b_phase_zero_803caea8[],d10b_phase_step_803caeac[],d10b_peak_803caeb0[],d10b_scale_803caeb4[];
extern const char d10b_sfx_803cae70[],d10b_ambient_803cae80[],d10b_music_803cae94[];
extern "C" void d10b_countdown_expired_80262a58(Ptr32<d10b_PulseOwner>);
extern "C" int d10b_read_volume_800fc270(Ptr32<Ptr32<const char>>,Ptr32<float>);
extern "C" int d10b_pulse_and_volume_80262154(Ptr32<d10b_PulseOwner> self) {
    if (self->phase>d10b_period_803caea4[0]) self->phase=d10b_phase_zero_803caea8[0];
    self->phase+=d10b_phase_step_803caeac[0];
    unsigned char intensity;
    if (self->phase>d10b_peak_803caeb0[0]) intensity=static_cast<unsigned char>((d10b_peak_803caeb0[0]-(self->phase-d10b_peak_803caeb0[0]))*d10b_scale_803caeb4[0]);
    else intensity=static_cast<unsigned char>(self->phase*d10b_scale_803caeb4[0]);
    self->color.set(intensity,intensity,intensity,255);
    if (self->countdown && --self->countdown==0) d10b_countdown_expired_80262a58(self);
    Ptr32<const char> sfx=d10b_sfx_803cae70;
    float volume;
    d10b_read_volume_800fc270(&sfx,&volume);
    d10b_services_804b1788->mixer->vtable->set_volume(d10b_services_804b1788->mixer,volume,0);
    d10b_services_804b1788->mixer->vtable->set_volume(d10b_services_804b1788->mixer,volume,3);
    Ptr32<const char> ambient=d10b_ambient_803cae80;
    d10b_read_volume_800fc270(&ambient,&volume);
    d10b_services_804b1788->mixer->vtable->set_volume(d10b_services_804b1788->mixer,volume,1);
    Ptr32<const char> music=d10b_music_803cae94;
    d10b_read_volume_800fc270(&music,&volume);
    d10b_services_804b1788->mixer->vtable->set_volume(d10b_services_804b1788->mixer,volume,2);
    return 0;
}


