#include "w3d_ptr.h"
#line 1 "d10b_replace_audio_802643d0_v3.cpp"
// Partial service and owner views; original class names/full object sizes unknown.
struct d10b_Audio;
struct d10b_AudioVtable {
    unsigned int unknown00[4];
    Ptr32<void (Ptr32<d10b_Audio>)> release;
    Ptr32<void (Ptr32<d10b_Audio>)> start;
    Ptr32<void (Ptr32<d10b_Audio>)> stop;
    unsigned int unknown1c[6];
    Ptr32<void (Ptr32<d10b_Audio>, float, int)> set_volume;
};
struct d10b_Audio { Ptr32<d10b_AudioVtable> vtable; };
struct d10b_AudioFactory;
struct d10b_AudioFactoryVtable {
    unsigned int unknown00[23];
    Ptr32<void (Ptr32<d10b_AudioFactory>, unsigned int, Ptr32<Ptr32<d10b_Audio>>)> create;
};
struct d10b_AudioFactory { Ptr32<d10b_AudioFactoryVtable> vtable; };
struct d10b_AudioServices { unsigned char unknown00[108]; Ptr32<d10b_AudioFactory> factory; };
struct d10b_AudioHandle {
    Ptr32<d10b_Audio> value;
    inline void clear(Ptr32<d10b_Audio> next) { if (value) value->vtable->release(value); value=next; }
    inline void stop() { if (value) value->vtable->stop(value); }
};
struct d10b_AudioOwner { unsigned char unknown00[204]; d10b_AudioHandle audio; };
extern Ptr32<d10b_AudioServices> d10b_services_804b1788;
extern char d10b_volume_key_803cae70[];
extern "C" int d10b_read_float_800fc270(Ptr32<Ptr32<const char>>, Ptr32<float>);
extern "C" void d10b_replace_audio_802643d0(Ptr32<d10b_AudioOwner> self, unsigned int id) {
    self->audio.stop();
    self->audio.clear(0);
    d10b_services_804b1788->factory->vtable->create(d10b_services_804b1788->factory,id,&self->audio.value);
    self->audio.value->vtable->start(self->audio.value);
    Ptr32<const char> key=d10b_volume_key_803cae70;
    float volume;
    d10b_read_float_800fc270(&key,&volume);
    self->audio.value->vtable->set_volume(self->audio.value,volume,1);
}


