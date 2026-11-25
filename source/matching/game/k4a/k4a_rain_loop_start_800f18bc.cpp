struct K4aVoice;
struct K4aVoiceVtable { void (*unknown_00[5])(void); int (*start)(K4aVoice *self); void (*unknown_06[7])(void); int (*set_gain)(K4aVoice *self, int mode, float gain); };
struct K4aVoice { const K4aVoiceVtable *vtable; };
struct K4aAudio;
struct K4aAudioVtable { void (*unknown_00[23])(void); int (*create_voice)(K4aAudio *self, const char *name, K4aVoice **out); };
struct K4aAudio { const K4aAudioVtable *vtable; };
struct K4aGameContext { char pad0[108]; K4aAudio *audio; };
struct K4aMessageId { unsigned short value; K4aMessageId() {} };
struct K4aRainLoop { char pad0[28]; K4aVoice *left; K4aVoice *right; float gain; int unused; unsigned int subscription; int ambient; };
struct K4aEngineContext { char pad0[52]; int value; };
extern "C" K4aGameContext *w3d_context_804b1788;
extern "C" char w3d_str_8038c3d4[];
extern "C" const float w3d_f32_8038c3e0[];
extern "C" unsigned int w3d_message_804af098;
extern "C" int w3d_auto_8015fd1c(K4aRainLoop *self);
extern "C" unsigned short w3d_cached_message_id(void *cache, int create);
extern "C" int w3d_subscribe_80162024(void *self, K4aMessageId *id, void *slot);
extern "C" K4aEngineContext *w3d_engine_get_context();

extern "C" void k4a_rain_loop_start_800f18bc(K4aRainLoop *self)
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
