#include "w3d_ptr.h"
#line 1 "k4a_rain_loop_start_800f18bc.cpp"
struct K4aVoice;
struct K4aVoiceVtable { Ptr32<void (void)> unknown_00[5]; Ptr32<int (Ptr32<K4aVoice>)> start; Ptr32<void (void)> unknown_06[7]; Ptr32<int (Ptr32<K4aVoice>, int, float)> set_gain; };
struct K4aVoice { Ptr32<const K4aVoiceVtable> vtable; };
struct K4aAudio;
struct K4aAudioVtable { Ptr32<void (void)> unknown_00[23]; Ptr32<int (Ptr32<K4aAudio>, Ptr32<const char>, Ptr32<Ptr32<K4aVoice>>)> create_voice; };
struct K4aAudio { Ptr32<const K4aAudioVtable> vtable; };
struct K4aGameContext { char pad0[108]; Ptr32<K4aAudio> audio; };
struct K4aMessageId { unsigned short value; K4aMessageId() {} };
struct K4aRainLoop { char pad0[28]; Ptr32<K4aVoice> left; Ptr32<K4aVoice> right; float gain; int unused; unsigned int subscription; int ambient; };
struct K4aEngineContext { char pad0[52]; int value; };
extern "C" Ptr32<K4aGameContext> w3d_context_804b1788;
extern "C" char w3d_str_8038c3d4[];
extern "C" const float w3d_f32_8038c3e0[];
extern "C" unsigned int w3d_message_804af098;
extern "C" int w3d_auto_8015fd1c(Ptr32<K4aRainLoop> self);
extern "C" unsigned short w3d_cached_message_id(Ptr32<void> cache, int create);
extern "C" int w3d_subscribe_80162024(Ptr32<void> self, Ptr32<K4aMessageId> id, Ptr32<void> slot);
extern "C" Ptr32<K4aEngineContext> w3d_engine_get_context();

extern "C" void k4a_rain_loop_start_800f18bc(Ptr32<K4aRainLoop> self)
{
    K4aMessageId id;
    if (w3d_context_804b1788->audio == 0) {
        w3d_auto_8015fd1c(self);
        return;
    }
    w3d_context_804b1788->audio->vtable->create_voice(w3d_context_804b1788->audio, w3d_str_8038c3d4, &self->left);
    w3d_context_804b1788->audio->vtable->create_voice(w3d_context_804b1788->audio, w3d_str_8038c3d4, &self->right);
    self->unused = 0;
    self->gain = w3d_f32_8038c3e0[0];
    self->left->vtable->set_gain(self->left, 1, w3d_f32_8038c3e0[0]);
    self->right->vtable->set_gain(self->right, 1, self->gain);
    self->left->vtable->start(self->left);
    self->right->vtable->start(self->right);
    id.value = w3d_cached_message_id(&w3d_message_804af098, 1);
    w3d_subscribe_80162024(self, &id, &self->subscription);
    self->ambient = w3d_engine_get_context()->value;
}


