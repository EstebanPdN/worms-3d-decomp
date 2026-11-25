#include "w3d_ptr.h"
#line 1 "cx8a_audio_fade_update_800f19d8.cpp"
// Shared lifetime interface, stop +0x18 and set-volume +0x34.
struct Cx8aAudio;
struct Cx8aAudioVtable {Ptr32<void> unknown00[6];Ptr32<int (Ptr32<Cx8aAudio>)> stop;Ptr32<void> unknown1c[6];Ptr32<int (Ptr32<Cx8aAudio>, int, float)> volume;};
struct Cx8aAudio {Ptr32<Cx8aAudioVtable> vtable;};
struct Cx8aFade {unsigned char unknown00[0x1c];Ptr32<Cx8aAudio> first; Ptr32<Cx8aAudio> second;float volume;int fading;unsigned char unknown2c[4];unsigned int tick;};
extern const float stop_volume_8038c3e4[];
extern "C" void fade_prepare_800f1a70(Ptr32<Cx8aFade>);extern "C" void fade_step_800f1b58(Ptr32<Cx8aFade>,unsigned int);extern "C" int expire_8015fd1c(Ptr32<Cx8aFade>);
extern "C" int w3d_cx8a_audio_fade_update_800f19d8(Ptr32<Cx8aFade> self,unsigned int tick){
 fade_prepare_800f1a70(self);fade_step_800f1b58(self,tick);
 if(self->fading && self->volume<=stop_volume_8038c3e4[0]){self->first->vtable->stop(self->first);self->second->vtable->stop(self->second);expire_8015fd1c(self);}return 0;
}


