/* Hardware sound voices driven by the sound manager (0x801e4c14..0x801e51c8).
 *
 * Names are inferred from behavior; no original symbols survive. Observed
 * voice layout: +0x00 owner emitter id, +0x04 sample interface, +0x08 pause
 * depth, +0x0c owner emitter, +0x10 hardware channel (-1 when idle),
 * +0x14 second handle (-1), +0x1c vtable. The emitter keeps its channel at
 * +0x38 and its sample at +0x58 (see c_sound_emitter.cpp).
 */
extern "C" {

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dSound W3dSound;
typedef struct W3dSoundVtbl {
    unsigned char unknown_00[0x40];
    int (*sample_rate)(W3dSound *sound);                    /* +0x40 */
} W3dSoundVtbl;
struct W3dSound {
    W3dSoundVtbl *vtbl;
};

typedef struct W3dSoundEmitter W3dSoundEmitter;
typedef struct W3dSoundEmitterVtbl {
    unsigned char unknown_00[0x48];
    int (*get_id)(W3dSoundEmitter *emitter);                /* +0x48 */
} W3dSoundEmitterVtbl;
struct W3dSoundEmitter {
    W3dSoundEmitterVtbl *vtbl;
    unsigned char unknown_04[0x38 - 0x04];
    int channel;
    unsigned char unknown_3c[0x58 - 0x3c];
    W3dSound *sound;
};

typedef struct W3dSoundListener W3dSoundListener;
typedef struct W3dSoundVoice W3dSoundVoice;
typedef struct W3dSoundVoiceVtbl {
    unsigned char unknown_00[0x0c];
    void (*halt)(W3dSoundVoice *voice);                     /* +0x0c */
    void (*set_volume)(W3dSoundVoice *voice, float value);  /* +0x10 */
    void (*set_pitch)(W3dSoundVoice *voice, float value);   /* +0x14 */
} W3dSoundVoiceVtbl;
struct W3dSoundVoice {
    int id;
    W3dSound *sound;
    int pause_depth;
    W3dSoundEmitter *emitter;
    int channel;
    int handle;
    int unknown_18;
    W3dSoundVoiceVtbl *vtbl;
};

extern W3dSoundVoiceVtbl w3d_sound_voice_vtable_80416f38;
extern const float w3d_f32_803b06ec[];

void w3d_actor_member_delete_backend(void *block);
int w3d_sound_is_looping_801df1ac(W3dSound *sound);
int w3d_channel_play_80322938(unsigned short rate, int volume, int pan, int flags);
void w3d_channel_stop_803228f8(int channel);
void w3d_channel_control_80322838(int channel, int control, int value);
int w3d_channel_status_803229bc(int channel);
float w3d_sound_voice_calc_pitch_801e5460(W3dSoundVoice *voice, W3dSoundListener *listener);
float w3d_sound_voice_calc_volume_801e51c8(W3dSoundVoice *voice, W3dSoundListener *listener);
float w3d_sound_voice_calc_pan_801e5314(W3dSoundVoice *voice, W3dSoundListener *listener);
float w3d_sound_voice_calc_depth_801e560c(W3dSoundVoice *voice, W3dSoundListener *listener);
void w3d_sound_voice_apply_pan_801e5908(W3dSoundVoice *voice, float value);
void w3d_sound_voice_apply_depth_801e5960(W3dSoundVoice *voice, float value);
int w3d_sound_voice_stop_801e4de8(W3dSoundVoice *voice);
int w3d_sound_voice_is_busy_801e4fcc(W3dSoundVoice *voice);
int w3d_sound_voice_is_looping_801e507c(W3dSoundVoice *voice);
void w3d_sound_voice_commit_801e50b8(W3dSoundVoice *voice);

void w3d_sound_voice_destroy(W3dSoundVoice *voice, int flags)
{
    voice->vtbl = &w3d_sound_voice_vtable_80416f38;
    w3d_sound_voice_stop_801e4de8(voice);
    if (flags & 1)
        w3d_actor_member_delete_backend(voice);
}

void w3d_sound_voice_clear(W3dSoundVoice *voice)
{
    voice->vtbl->halt(voice);
    voice->id = 0;
    voice->emitter = 0;
    voice->sound = 0;
    voice->pause_depth = 0;
}

int w3d_sound_voice_assign_801e4ce0(W3dSoundVoice *voice, W3dSoundEmitter *emitter)
{
    W3dSound *sound = emitter->sound;

    if (sound == 0)
        return 0;
    if (sound->vtbl->sample_rate(sound) >= 0) {
        voice->id = emitter->vtbl->get_id(emitter);
        voice->channel = w3d_channel_play_80322938(sound->vtbl->sample_rate(sound), 127, 64, 0);
        voice->emitter = emitter;
        voice->sound = emitter->sound;
        emitter->channel = voice->channel;
    }
    return 1;
}

int w3d_sound_voice_set_sound(W3dSoundVoice *voice, W3dSound *sound)
{
    if (w3d_sound_voice_is_busy_801e4fcc(voice) != 0)
        voice->vtbl->halt(voice);
    voice->sound = sound;
    return 1;
}

int w3d_sound_voice_stop_801e4de8(W3dSoundVoice *voice)
{
    if (w3d_sound_voice_is_busy_801e4fcc(voice) == 0 && voice->pause_depth == 0)
        return 0;
    if (voice->channel == -1)
        return 0;
    w3d_channel_stop_803228f8(voice->channel);
    voice->channel = -1;
    if (voice->emitter != 0)
        voice->emitter->channel = -1;
    voice->sound = 0;
    return 1;
}

int w3d_sound_voice_pause(W3dSoundVoice *voice)
{
    if (voice->pause_depth > 0) {
        voice->pause_depth++;
        return 1;
    }
    if (w3d_sound_voice_is_busy_801e4fcc(voice) != 0 && w3d_sound_voice_is_looping_801e507c(voice) == 0) {
        voice->pause_depth = 1;
        voice->vtbl->halt(voice);
        return 1;
    }
    if (w3d_sound_voice_is_busy_801e4fcc(voice) != 0 && w3d_sound_voice_is_looping_801e507c(voice) != 0) {
        voice->pause_depth = 1;
        w3d_channel_control_80322838(voice->channel, 7, 0);
        return 1;
    }
    return 0;
}

int w3d_sound_voice_is_busy_801e4fcc(W3dSoundVoice *voice)
{
    int status;

    if (voice->pause_depth > 0)
        return 1;
    status = w3d_channel_status_803229bc(voice->channel);
    if (status != -1)
        return 1;
    voice->channel = status;
    return 0;
}

int w3d_sound_voice_is_free(W3dSoundVoice *voice)
{
    if (w3d_sound_voice_is_busy_801e4fcc(voice) != 0 || voice->pause_depth > 0)
        return 0;
    return voice->channel == -1;
}

int w3d_sound_voice_is_looping_801e507c(W3dSoundVoice *voice)
{
    if (voice->sound == 0)
        return 0;
    return w3d_sound_is_looping_801df1ac(voice->sound);
}

int w3d_sound_voice_always_true(W3dSoundVoice *voice)
{
    return 1;
}

void w3d_sound_voice_commit_801e50b8(W3dSoundVoice *voice)
{
}

float w3d_sound_voice_default_level(W3dSoundVoice *voice)
{
    return w3d_f32_803b06ec[0];
}

void w3d_sound_voice_update(W3dSoundVoice *voice, W3dSoundListener *listener)
{
    W3dVec3 unused_a;
    W3dVec3 unused_b;

    if (voice->pause_depth == 0 && w3d_sound_voice_is_busy_801e4fcc(voice) != 0 && voice->emitter != 0) {
        float pitch = w3d_sound_voice_calc_pitch_801e5460(voice, listener);
        float volume = w3d_sound_voice_calc_volume_801e51c8(voice, listener);
        float pan = w3d_sound_voice_calc_pan_801e5314(voice, listener);
        float depth = w3d_sound_voice_calc_depth_801e560c(voice, listener);

        voice->vtbl->set_pitch(voice, pitch);
        voice->vtbl->set_volume(voice, volume);
        w3d_sound_voice_apply_pan_801e5908(voice, pan);
        w3d_sound_voice_apply_depth_801e5960(voice, depth);
        w3d_sound_voice_commit_801e50b8(voice);
    }
}

}
