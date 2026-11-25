/* Sound emitters and the voice manager that owns them (0x801e00c0..0x801e1958).
 *
 * Names are inferred from behavior; no original symbols survive. The code
 * returns COM-style result codes (0x80004001 not implemented, 0x80004005
 * failure) and keeps reference-counted interfaces whose vtable slot 12 is
 * AddRef and slot 16 is Release. Observed layouts:
 *   emitter +0x04 id, +0x0c position, +0x18 volume, +0x1c mode word,
 *           +0x20 play cursor, +0x24 playing flag, +0x54 pause depth,
 *           +0x58 attached sound interface
 *   manager +0x24/+0x28/+0x2c emitter vector, +0x30 32 voice slots
 *   voice   +0x00 owner id, +0x04 owner emitter, +0x1c vtable pointer
 */
extern "C" {

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dSound W3dSound;
typedef struct W3dSoundEmitter W3dSoundEmitter;
typedef struct W3dSoundManager W3dSoundManager;
typedef struct W3dSoundListener W3dSoundListener;
typedef struct W3dSoundVoice W3dSoundVoice;

/* Reference-counted sound sample interface. */
typedef struct W3dSoundVtbl {
    unsigned char unknown_00[0x0c];
    void (*add_ref)(W3dSound *sound);                       /* +0x0c */
    void (*release)(W3dSound *sound);                       /* +0x10 */
    unsigned char unknown_14[0x20 - 0x14];
    int (*kind)(W3dSound *sound);                           /* +0x20 */
    unsigned char unknown_24[0x28 - 0x24];
    const char *(*name)(W3dSound *sound);                   /* +0x28 */
    unsigned char unknown_2c[0x30 - 0x2c];
    unsigned int (*length)(W3dSound *sound);                /* +0x30 */
} W3dSoundVtbl;
struct W3dSound {
    W3dSoundVtbl *vtbl;
};

/* Native reference-counted node prefix shared with actors (see actor_reference_initialize). */
typedef union W3dNodeFlagWord {
    unsigned int word;
    unsigned char bytes[4];
} W3dNodeFlagWord;
typedef struct W3dNodeCounts {
    unsigned short first, second;
    W3dNodeFlagWord flags;
} W3dNodeCounts;
typedef struct W3dNodeLinks {
    void *next, *previous;
} W3dNodeLinks;

typedef struct W3dSoundEmitterVtbl {
    unsigned char unknown_00[0x0c];
    void (*add_ref)(W3dSoundEmitter *emitter);              /* +0x0c */
    void (*release)(W3dSoundEmitter *emitter);              /* +0x10 */
    unsigned char unknown_14[0x18 - 0x14];
    void (*stop)(W3dSoundEmitter *emitter);                 /* +0x18 */
    unsigned char unknown_1c[0x20 - 0x1c];
    void (*prepare)(W3dSoundEmitter *emitter);              /* +0x20 */
    int (*is_active)(W3dSoundEmitter *emitter);             /* +0x24 */
    int (*is_finished)(W3dSoundEmitter *emitter);           /* +0x28 */
    unsigned char unknown_2c[0x48 - 0x2c];
    int (*get_id)(W3dSoundEmitter *emitter);                /* +0x48 */
    float (*priority)(W3dSoundEmitter *emitter);            /* +0x4c */
} W3dSoundEmitterVtbl;

struct W3dSoundEmitter {
    W3dSoundEmitterVtbl *vtbl;
    int id;
    float attenuation;
    W3dVec3 position;
    float volume;
    int mode;
    int cursor;
    int playing;
    W3dNodeCounts counts;
    W3dNodeLinks links;
    int channel;
    W3dVec3 velocity;
    W3dVec3 direction;
    int pause_depth;
    W3dSound *sound;
};

typedef struct W3dSoundListenerVtbl {
    unsigned char unknown_00[0x38];
    void (*get_position)(W3dSoundListener *listener, W3dVec3 *out); /* +0x38 */
    unsigned char unknown_3c[0x44 - 0x3c];
    void (*update)(W3dSoundListener *listener, int elapsed);        /* +0x44 */
} W3dSoundListenerVtbl;
struct W3dSoundListener {
    W3dSoundListenerVtbl *vtbl;
};

typedef struct W3dSoundVoiceVtbl {
    unsigned char unknown_00[0x0c];
    void (*halt)(W3dSoundVoice *voice);                     /* +0x0c */
    unsigned char unknown_10[0x1c - 0x10];
    void (*set_position)(W3dSoundVoice *voice, W3dVec3 *position); /* +0x1c */
    void (*update)(W3dSoundVoice *voice, W3dSoundListener *listener, int elapsed); /* +0x20 */
    void (*set_mode)(W3dSoundVoice *voice, int mode);       /* +0x24 */
    void (*reset)(W3dSoundVoice *voice);                    /* +0x28 */
} W3dSoundVoiceVtbl;
struct W3dSoundVoice {
    int id;
    W3dSound *sound;
    unsigned char unknown_08[0x1c - 0x08];
    W3dSoundVoiceVtbl *vtbl;
    int unknown_20;
};

typedef struct W3dEmitterVector {
    W3dSoundEmitter **begin;
    W3dSoundEmitter **end;
    W3dSoundEmitter **capacity;
} W3dEmitterVector;

typedef struct W3dSoundManagerVtbl {
    unsigned char unknown_00[0x38];
    float (*master_volume)(W3dSoundManager *manager);       /* +0x38 */
} W3dSoundManagerVtbl;
struct W3dSoundManager {
    W3dSoundManagerVtbl *vtbl;
    unsigned char unknown_04[0x14 - 0x04];
    W3dSoundListener *listener;
    unsigned char unknown_18[0x20 - 0x18];
    int next_id;
    W3dEmitterVector emitters;
    W3dSoundVoice *voices[32];
};

/* Inlined std::vector<Emitter *> members. */
static inline unsigned int w3d_emitter_vector_size(W3dEmitterVector *vector)
{
    return vector->end - vector->begin;
}

static inline W3dSoundEmitter *&w3d_emitter_vector_at(W3dEmitterVector *vector, unsigned int index)
{
    return *(vector->begin + index);
}

static inline W3dSoundEmitter **w3d_emitter_vector_begin(W3dEmitterVector *vector)
{
    return vector->begin;
}

static inline W3dSoundEmitter **w3d_emitter_vector_end(W3dEmitterVector *vector)
{
    return vector->end;
}

void w3d_memmove_802eee50(void *dest, const void *source, unsigned int size, ...);

static inline void w3d_emitter_vector_erase(W3dEmitterVector *vector, W3dSoundEmitter **item)
{
    if (item + 1 != vector->end)
        w3d_memmove_802eee50(item, item + 1, (char *)vector->end - (char *)(item + 1));
    vector->end--;
}

/* Fixed-size priority list of emitters used while assigning voices. */
typedef struct W3dSoundEmitterList {
    W3dSoundEmitter *items[32];
    unsigned int count;
    unsigned int capacity;
} W3dSoundEmitterList;

extern W3dSoundManager *w3d_sound_system_804ab834;
extern const float w3d_f32_803b0484[];
extern const float w3d_f32_803b0488[];
extern const float w3d_f32_803b048c[];
extern const float w3d_f32_803b0490[];
extern const float w3d_f32_803b0494[];
extern W3dSoundEmitterVtbl w3d_sound_emitter_base_vtable_80416a90;
extern W3dSoundEmitterVtbl w3d_sound_emitter_vtable_80416d20;
extern const float w3d_f32_803b04b8[];
extern const float w3d_f32_803b04cc[];
extern const float w3d_f32_803b04d0[];
extern const double w3d_f64_803b04d8[];
extern const double w3d_f64_803b04e0[];
extern const float w3d_f32_803b04e8[];
extern const float w3d_f32_803b04ec[];
extern const float w3d_f32_803b04f0[];
extern const char w3d_str_803b04bc[];

int w3d_sound_get_base_rate_801df104(W3dSound *sound);
float w3d_sound_get_rate_spread_801df1cc(W3dSound *sound);
float w3d_sound_get_base_volume_801df1b4(W3dSound *sound);
float w3d_sound_get_volume_spread_801df1d4(W3dSound *sound);
int w3d_sound_is_looping_801df1ac(W3dSound *sound);
float w3d_sound_get_position_at_801df23c(W3dSound *sound, int cursor);
int w3d_channel_status_803229bc(int channel);
int w3d_rand_802ee7dc(void);
int w3d_strcmp_802ef234(const char *a, const char *b);
void w3d_sound_manager_remove_801e0794(W3dSoundManager *manager, int id);
int w3d_sound_manager_set_voice_position_801e0888(W3dSoundManager *manager, int id, W3dVec3 *position);
int w3d_sound_manager_set_voice_mode_801e08f4(W3dSoundManager *manager, int id, int mode);
void w3d_sound_emitter_detach_801e1120(W3dSoundEmitter *emitter);
int w3d_sound_emitter_vary_rate_801e1274(W3dSoundEmitter *emitter, unsigned int base, float spread);
float w3d_sound_emitter_vary_volume_801e1308(W3dSoundEmitter *emitter, float base, float spread);
void w3d_actor_member_delete_backend(void *block);
void *w3d_heap_allocate_entry_a(unsigned int size);
void w3d_actor_node_destroy(void *node, unsigned int flags);
void *w3d_handle_storage_allocate(unsigned int size);
void w3d_handle_storage_release(void *storage);
float w3d_sound_get_range_801df1bc(W3dSound *sound);
int w3d_sound_get_category_801df288(W3dSound *sound);
int w3d_sound_voice_release_801e4f38(W3dSoundVoice *voice);
int w3d_sound_voice_is_busy_801e4fcc(W3dSoundVoice *voice);
int w3d_sound_voice_is_free_801e5024(W3dSoundVoice *voice);
void w3d_sound_voice_assign_801e4ce0(W3dSoundVoice *voice, W3dSoundEmitter *emitter);
W3dSoundEmitter *w3d_sound_manager_create_emitter_801e0680(W3dSoundManager *manager);
void w3d_sound_emitter_attach_801e117c(W3dSoundEmitter *emitter, W3dSound *sound, int unused);
void w3d_sound_emitter_detach_801e1120(W3dSoundEmitter *emitter);
int w3d_sound_emitter_update_attenuation_801e1424(W3dSoundEmitter *emitter, W3dSoundListener *listener);
void w3d_sound_emitter_advance(W3dSoundEmitter *emitter, int elapsed);
void w3d_sound_emitter_list_init(W3dSoundEmitterList *list);
void w3d_sound_emitter_list_destroy(W3dSoundEmitterList *list, int flags);
void w3d_sound_emitter_list_insert_801e16b0(W3dSoundEmitterList *list, W3dSoundEmitter *emitter);
void w3d_sound_emitter_list_remove_801e183c(W3dSoundEmitterList *list, unsigned int index);
unsigned int w3d_sound_emitter_list_count(W3dSoundEmitterList *list);
W3dSoundEmitter *w3d_sound_emitter_list_get(W3dSoundEmitterList *list, unsigned int index);

int w3d_sound_emitter_always_true(void)
{
    return 1;
}

int w3d_sound_emitter_not_implemented_801e0290(void)
{
    return (int)0x80004001;
}

int w3d_sound_emitter_set_volume(W3dSoundEmitter *emitter, float volume)
{
    if (volume < w3d_f32_803b0484[0])
        volume = w3d_f32_803b0484[0];
    if (volume > w3d_f32_803b0488[0])
        volume = w3d_f32_803b0488[0];
    emitter->volume = volume;
    return 0;
}

float w3d_sound_emitter_get_volume(W3dSoundEmitter *emitter)
{
    return emitter->volume;
}

int w3d_sound_manager_stub_801e0960(W3dSoundManager *system, int id, int value)
{
    return 0;
}

int w3d_sound_manager_stub_801e0968(W3dSoundManager *system, int id, int *value)
{
    return 0;
}

int w3d_sound_manager_stub_801e0970(W3dSoundManager *system, int id, int value)
{
    return 0;
}

int w3d_sound_manager_stub_801e0978(W3dSoundManager *system, int id, W3dVec3 *value)
{
    return 0;
}

int w3d_sound_manager_stub_801e0980(W3dSoundManager *system, int id, W3dVec3 *value)
{
    return 0;
}

int w3d_sound_manager_stub_801e0988(W3dSoundManager *system, int id, W3dVec3 *value)
{
    return 0;
}

int w3d_sound_emitter_not_implemented_801e0990(void)
{
    return (int)0x80004001;
}

int w3d_sound_emitter_start(W3dSoundEmitter *emitter)
{
    if (emitter->sound == 0)
        return 1;
    emitter->cursor = 0;
    emitter->playing = 1;
    return 0;
}

int w3d_sound_emitter_pause(W3dSoundEmitter *emitter)
{
    emitter->pause_depth++;
    return 0;
}

int w3d_sound_emitter_resume(W3dSoundEmitter *emitter)
{
    if (emitter->pause_depth > 0)
        emitter->pause_depth--;
    return 0;
}

int w3d_sound_emitter_is_audible(W3dSoundEmitter *emitter)
{
    if (emitter->sound == 0)
        return 0;
    if (emitter->playing != 0 && emitter->pause_depth == 0)
        return 1;
    return 0;
}

int w3d_sound_emitter_is_vector_property(W3dSoundEmitter *emitter, int property)
{
    switch (property) {
    case 1: case 2: case 3: case 4:
    case 8: case 9: case 10: case 11: case 12:
        return 1;
    }
    return 0;
}

W3dSoundManager *w3d_sound_system_get(W3dSoundEmitter *emitter)
{
    return w3d_sound_system_804ab834;
}

float w3d_sound_emitter_get_attenuation(W3dSoundEmitter *emitter)
{
    return emitter->attenuation;
}


int w3d_sound_manager_set_voice_position_801e0888(W3dSoundManager *manager, int id, W3dVec3 *position)
{
    unsigned int i;

    for (i = 0; i <= 31; i++) {
        W3dSoundVoice *voice = manager->voices[i];
        if (voice != 0 && voice->id == id) {
            voice->vtbl->set_position(voice, position);
            return 1;
        }
    }
    return 0;
}

int w3d_sound_manager_set_voice_mode_801e08f4(W3dSoundManager *manager, int id, int mode)
{
    unsigned int i;

    for (i = 0; i <= 31; i++) {
        W3dSoundVoice *voice = manager->voices[i];
        if (voice != 0 && voice->id == id) {
            voice->vtbl->set_mode(voice, mode);
            return 1;
        }
    }
    return 0;
}

#if 0 /* helper for the skipped volume setters below */
static inline void w3d_sound_master_scale(W3dSoundEmitter *emitter, float *scale)
{
    if (w3d_sound_system_get(emitter) != 0) {
        W3dSoundManager *manager = w3d_sound_system_get(emitter);
        *scale = manager->vtbl->master_volume(manager);
    }
}

#endif

int w3d_sound_emitter_deactivate(W3dSoundEmitter *emitter)
{
    if (w3d_sound_system_get(emitter) != 0 && emitter->vtbl->is_active(emitter) != 0) {
        emitter->playing = 0;
        return 0;
    }
    return (int)0x80004005;
}

int w3d_sound_emitter_set_int(W3dSoundEmitter *emitter, int property, int value)
{
    W3dSoundManager *manager = w3d_sound_system_get(emitter);

    if (manager != 0) {
        switch (property) {
        case 2:
            emitter->mode = value;
            if (w3d_sound_manager_set_voice_mode_801e08f4(manager, emitter->id, value))
                return 0;
            break;
        case 9:
            if (w3d_sound_manager_stub_801e0960(manager, emitter->id, value))
                return 0;
            break;
        case 10:
            if (w3d_sound_manager_stub_801e0970(manager, emitter->id, value))
                return 0;
            break;
        }
    }
    return (int)0x80004005;
}

#if 0 /* skipped 0x801e0cbc: code matches but original frame is 8 bytes larger */
int w3d_sound_emitter_set_float(W3dSoundEmitter *emitter, int property, float value)
{
    if (w3d_sound_system_get(emitter) != 0 && (property == 1 || property == 11)) {
        float scale;

        emitter->volume = value;
        scale = w3d_f32_803b04b8[0];
        w3d_sound_master_scale(emitter, &scale);
        emitter->volume = emitter->volume * scale;
        return 0;
    }
    return (int)0x80004005;
}

#endif

int w3d_sound_emitter_set_vector(W3dSoundEmitter *emitter, int property, W3dVec3 *value)
{
    W3dSoundManager *manager = w3d_sound_system_get(emitter);

    if (manager != 0) {
        switch (property) {
        case 3:
            emitter->position = *value;
            if (w3d_sound_manager_set_voice_position_801e0888(manager, emitter->id, &emitter->position))
                return 0;
            break;
        case 4:
            emitter->velocity = *value;
            if (w3d_sound_manager_stub_801e0978(manager, emitter->id, &emitter->velocity))
                return 0;
            break;
        case 8:
            emitter->direction = *value;
            if (w3d_sound_manager_stub_801e0980(manager, emitter->id, &emitter->direction))
                return 0;
            break;
        }
    }
    return (int)0x80004005;
}

int w3d_sound_emitter_get_int(W3dSoundEmitter *emitter, int property, int *out)
{
    int value;
    W3dSoundManager *manager = w3d_sound_system_get(emitter);

    value = 360;
    if (manager != 0) {
        switch (property) {
        case 2:
            *out = emitter->mode;
            return 0;
        case 9:
            if (w3d_sound_manager_stub_801e0968(manager, emitter->id, &value)) {
                *out = value;
                return 0;
            }
            break;
        case 10:
            if (w3d_sound_manager_stub_801e0970(manager, emitter->id, 360)) {
                *out = value;
                return 0;
            }
            break;
        case 12:
            if (emitter->sound != 0) {
                *out = w3d_sound_get_base_rate_801df104(emitter->sound);
                return 0;
            }
            break;
        }
    }
    return (int)0x80004005;
}

int w3d_sound_emitter_get_float(W3dSoundEmitter *emitter, int property, float *out)
{
    if (w3d_sound_system_get(emitter) != 0) {
        switch (property) {
        case 1:
        case 11:
            *out = emitter->volume;
            return 0;
        case 24:
            if (emitter->sound != 0) {
                *out = w3d_sound_get_position_at_801df23c(emitter->sound, emitter->cursor);
                return 0;
            }
            break;
        }
    }
    return (int)0x80004005;
}

int w3d_sound_emitter_get_vector(W3dSoundEmitter *emitter, int property, W3dVec3 *out)
{
    W3dSoundManager *manager = w3d_sound_system_get(emitter);

    if (manager != 0) {
        switch (property) {
        case 3:
            *out = emitter->position;
            return 0;
        case 4:
            *out = emitter->velocity;
            return 0;
        case 8:
            if (w3d_sound_manager_stub_801e0988(manager, emitter->id, out))
                return 0;
            break;
        }
    }
    return (int)0x80004005;
}

void w3d_sound_emitter_shutdown(W3dSoundEmitter *emitter)
{
    W3dSoundManager *manager = w3d_sound_system_get(emitter);

    if (emitter->sound != 0)
        w3d_strcmp_802ef234(emitter->sound->vtbl->name(emitter->sound), w3d_str_803b04bc);
    if (emitter->vtbl->is_active(emitter) != 0)
        emitter->vtbl->stop(emitter);
    if (manager != 0)
        w3d_sound_manager_remove_801e0794(manager, emitter->id);
}

void w3d_sound_emitter_detach_801e1120(W3dSoundEmitter *emitter)
{
    emitter->vtbl->stop(emitter);
    if (emitter->sound != 0)
        emitter->sound->vtbl->release(emitter->sound);
    emitter->sound = 0;
}

#if 0 /* skipped 0x801e117c: code matches but original frame is 8 bytes larger */
void w3d_sound_emitter_attach_801e117c(W3dSoundEmitter *emitter, W3dSound *sound, int unused)
{
    int rate;
    float base;
    float scale;

    if (sound != 0)
        sound->vtbl->add_ref(sound);
    if (emitter->sound != 0)
        emitter->sound->vtbl->release(emitter->sound);
    emitter->sound = sound;
    rate = w3d_sound_get_base_rate_801df104(sound);
    emitter->mode = w3d_sound_emitter_vary_rate_801e1274(emitter, rate, w3d_sound_get_rate_spread_801df1cc(sound));
    base = w3d_sound_get_base_volume_801df1b4(sound);
    emitter->volume = w3d_sound_emitter_vary_volume_801e1308(emitter, base, w3d_sound_get_volume_spread_801df1d4(sound));
    scale = w3d_f32_803b04cc[0];
    w3d_sound_master_scale(emitter, &scale);
    emitter->volume = emitter->volume * scale;
}

#endif

int w3d_sound_emitter_vary_rate_801e1274(W3dSoundEmitter *emitter, unsigned int base, float spread)
{
    int range;

    if (spread == w3d_f32_803b04d0[0])
        return base;
    range = (int)((float)base * spread);
    return base - range + w3d_rand_802ee7dc() % (range + range);
}

#if 0 /* skipped 0x801e1308: code matches but original frame is 16 bytes larger */
static inline float w3d_sound_rand_unit(void)
{
    return (float)w3d_rand_802ee7dc() * w3d_f32_803b04e8[0];
}

float w3d_sound_emitter_vary_volume_801e1308(W3dSoundEmitter *emitter, float base, float spread)
{
    float range = base * spread;
    float low = base - range;
    float value = low + w3d_sound_rand_unit() * range * 2.0f;

    if (value > w3d_f32_803b04ec[0])
        value = w3d_f32_803b04ec[0];
    else if (value < w3d_f32_803b04f0[0])
        value = w3d_f32_803b04f0[0];
    return value;
}

#endif

void w3d_sound_emitter_advance(W3dSoundEmitter *emitter, int elapsed)
{
    if (emitter->playing != 0 && emitter->pause_depth == 0) {
        emitter->cursor += elapsed;
        if (emitter->sound != 0) {
            int looping = w3d_sound_is_looping_801df1ac(emitter->sound);
            if (looping == 0 && w3d_channel_status_803229bc(emitter->channel) == -1)
                emitter->playing = looping;
        }
    }
}

int w3d_sound_emitter_is_looping(W3dSoundEmitter *emitter)
{
    if (emitter->sound == 0)
        return 0;
    return w3d_sound_is_looping_801df1ac(emitter->sound);
}

void w3d_sound_emitter_list_init(W3dSoundEmitterList *list)
{
    W3dSoundEmitter **item = list->items;
    int i;

    for (i = 32; i != 0; i--)
        *item++ = 0;
    list->count = 0;
    list->capacity = 0;
}

void w3d_sound_emitter_list_destroy(W3dSoundEmitterList *list, int flags)
{
    unsigned int i;

    for (i = 0; i < list->capacity; i++) {
        if (list->items[i] != 0)
            list->items[i]->vtbl->release(list->items[i]);
        list->items[i] = 0;
    }
    if (list != 0) {
        W3dSoundEmitter **item = list->items + 32;
        while (list->items != item) {
            --item;
            if (*item != 0)
                (*item)->vtbl->release(*item);
        }
    }
    if (flags & 1)
        w3d_actor_member_delete_backend(list);
}

unsigned int w3d_sound_emitter_list_count(W3dSoundEmitterList *list)
{
    return list->count;
}

W3dSoundEmitter *w3d_sound_emitter_list_get(W3dSoundEmitterList *list, unsigned int index)
{
    return *(index + list->items);
}


int w3d_sound_manager_stop_category(W3dSoundManager *manager, int category)
{
    unsigned int i;
    unsigned int j;

    for (i = 0; i < w3d_emitter_vector_size(&manager->emitters); i++) {
        if (w3d_sound_get_category_801df288(w3d_emitter_vector_at(&manager->emitters, i)->sound) == category) {
            w3d_emitter_vector_at(&manager->emitters, i)->vtbl->prepare(w3d_emitter_vector_at(&manager->emitters, i));
            for (j = 0; j <= 31; j++) {
                int voice_id = manager->voices[j]->id;
                if (voice_id == w3d_emitter_vector_at(&manager->emitters, i)->vtbl->get_id(w3d_emitter_vector_at(&manager->emitters, i))) {
                    w3d_sound_voice_release_801e4f38(manager->voices[j]);
                    break;
                }
            }
        }
    }
    return 0;
}

W3dSoundEmitter *w3d_sound_manager_create_with_sound(W3dSoundManager *manager, W3dSound *sound)
{
    W3dSoundEmitter *emitter = w3d_sound_manager_create_emitter_801e0680(manager);
    w3d_sound_emitter_attach_801e117c(emitter, sound, 0);
    return emitter;
}

int w3d_sound_manager_create_emitter_ref(W3dSoundManager *manager, W3dSound *sound, W3dSoundEmitter **out)
{
    W3dSoundEmitter *emitter = w3d_sound_manager_create_emitter_801e0680(manager);

    emitter->id = ++manager->next_id;
    w3d_sound_emitter_attach_801e117c(emitter, sound, 0);
    if (emitter != 0)
        emitter->vtbl->add_ref(emitter);
    if (*out != 0)
        (*out)->vtbl->release(*out);
    *out = emitter;
    return 0;
}

int w3d_sound_manager_forget_sound(W3dSoundManager *manager, W3dSound *sound)
{
    unsigned int i;

    if (sound->vtbl->kind(sound) == 1) {
        unsigned int count = w3d_emitter_vector_size(&manager->emitters);
        for (i = 0; i < count; i++) {
            if (w3d_emitter_vector_at(&manager->emitters, i)->sound == sound)
                w3d_sound_emitter_detach_801e1120(w3d_emitter_vector_at(&manager->emitters, i));
        }
        for (i = 0; i <= 31; i++) {
            if (manager->voices[i]->sound == sound) {
                manager->voices[i]->vtbl->halt(manager->voices[i]);
                manager->voices[i]->vtbl->reset(manager->voices[i]);
            }
        }
    }
    return 0;
}

void w3d_sound_manager_remove_801e0794(W3dSoundManager *manager, int id)
{
    unsigned int i;
    W3dSoundEmitter **item;

    for (i = 0; i <= 31; i++) {
        if (manager->voices[i]->id == id) {
            manager->voices[i]->vtbl->halt(manager->voices[i]);
            manager->voices[i]->vtbl->reset(manager->voices[i]);
            break;
        }
    }
    for (item = w3d_emitter_vector_begin(&manager->emitters); item != w3d_emitter_vector_end(&manager->emitters); item++) {
        if ((*item)->vtbl->get_id(*item) == id) {
            w3d_emitter_vector_erase(&manager->emitters, item);
            break;
        }
    }
}

#if 0 /* skipped 0x801e183c: one add operand order differs */
void w3d_sound_emitter_list_remove_801e183c(W3dSoundEmitterList *list, unsigned int index)
{
    if (*(index + list->items) != 0) {
        W3dSoundEmitter **item;
        unsigned int i;
        for (i = index; i < list->capacity - 1; i++) {
            item = &list->items[i];
            if (*item != 0)
                (*item)->vtbl->release(*item);
            *item = 0;
            if (item[1] != 0)
                item[1]->vtbl->add_ref(item[1]);
            if (*item != 0)
                (*item)->vtbl->release(*item);
            *item = item[1];
        }
        item = list->capacity + list->items;
        --item;
        if (*item != 0)
            (*item)->vtbl->release(*item);
        *item = 0;
        list->count--;
    }
}
#endif

#if 0 /* skipped 0x801e099c: store scheduling and register choice differ */
static inline void w3d_vec3_fill(W3dVec3 *vector, float value)
{
    vector->x = value;
    vector->z = value;
    vector->y = value;
}

W3dSoundEmitter *w3d_sound_emitter_construct(W3dSoundEmitter *emitter)
{
    emitter->vtbl = &w3d_sound_emitter_base_vtable_80416a90;
    W3dNodeCounts *counts = &emitter->counts;
    counts->flags.bytes[3] = 2;
    W3dNodeFlagWord &flags = counts->flags;
    flags.word = flags.bytes[3];
    emitter->links.next = 0;
    W3dNodeLinks &links = emitter->links;
    links.previous = 0;
    counts->first = 0;
    counts->second = 0;
    emitter->vtbl = &w3d_sound_emitter_vtable_80416d20;
    emitter->pause_depth = 0;
    emitter->attenuation = w3d_f32_803b048c[0];
    emitter->volume = w3d_f32_803b0490[0];
    emitter->mode = 10101;
    emitter->sound = 0;
    emitter->id = 0;
    emitter->cursor = 0;
    emitter->playing = 0;
    w3d_vec3_fill(&emitter->position, w3d_f32_803b0494[0]);
    w3d_vec3_fill(&emitter->velocity, w3d_f32_803b0494[0]);
    w3d_vec3_fill(&emitter->direction, w3d_f32_803b0494[0]);
    emitter->channel = -1;
    return emitter;
}

#endif

void w3d_sound_emitter_destroy(W3dSoundEmitter *emitter, int flags)
{
    emitter->vtbl = &w3d_sound_emitter_vtable_80416d20;
    if (emitter->sound != 0)
        emitter->sound->vtbl->release(emitter->sound);
    emitter->vtbl = &w3d_sound_emitter_base_vtable_80416a90;
    w3d_actor_node_destroy(&emitter->counts, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(emitter);
}

}
