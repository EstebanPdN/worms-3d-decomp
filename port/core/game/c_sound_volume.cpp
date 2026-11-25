#include "w3d_ptr.h"
#line 1 "c_sound_volume.cpp"
/* Sound emitter and voice-manager functions whose frames keep unused local
 * slots (0x801e0380..0x801e1a0c), retried after c_sound_emitter was frozen.
 *
 * Names are inferred from behavior; no original symbols survive. These
 * functions belong to the emitter/sample sources (see c_sound_emitter.cpp and
 * c_sound_sample.cpp for the layouts). The originals route float values
 * have 8 or 16 bytes of locals that no surviving instruction uses. An
 * unused BLKmode struct local (W3dFrameSlot: 6 bytes, W3dVec3: 12 bytes)
 * reproduces that reservation; the original object is unknown.
 */
extern "C" {

typedef struct W3dFrameSlot {
    short unknown[3];
} W3dFrameSlot;

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dSound W3dSound;
typedef struct W3dSoundEmitter W3dSoundEmitter;
typedef struct W3dSoundManager W3dSoundManager;

typedef struct W3dSoundEmitterVtbl {
    unsigned char unknown_00[0x0c];
    Ptr32<void (Ptr32<W3dSoundEmitter>)> add_ref;              /* +0x0c */
    Ptr32<void (Ptr32<W3dSoundEmitter>)> release;              /* +0x10 */
    unsigned char unknown_14[0x24 - 0x14];
    Ptr32<int (Ptr32<W3dSoundEmitter>)> is_active;             /* +0x24 */
    Ptr32<int (Ptr32<W3dSoundEmitter>)> is_finished;           /* +0x28 */
    unsigned char unknown_2c[0x48 - 0x2c];
    Ptr32<int (Ptr32<W3dSoundEmitter>)> get_id;                /* +0x48 */
    Ptr32<float (Ptr32<W3dSoundEmitter>)> priority;            /* +0x4c */
} W3dSoundEmitterVtbl;

/* Fixed-size priority list of emitters used while assigning voices. */
typedef struct W3dSoundEmitterList {
    Ptr32<W3dSoundEmitter> items[32];
    unsigned int count;
    unsigned int capacity;
} W3dSoundEmitterList;
typedef struct W3dSoundVoice W3dSoundVoice;
typedef struct W3dSoundListener W3dSoundListener;

typedef struct W3dSoundVtbl {
    unsigned char unknown_00[0x0c];
    Ptr32<void (Ptr32<W3dSound>)> add_ref;                       /* +0x0c */
    Ptr32<void (Ptr32<W3dSound>)> release;                       /* +0x10 */
    unsigned char unknown_14[0x30 - 0x14];
    Ptr32<unsigned int (Ptr32<W3dSound>)> length;                /* +0x30 */
} W3dSoundVtbl;

typedef struct W3dSoundListenerVtbl {
    unsigned char unknown_00[0x38];
    Ptr32<void (Ptr32<W3dSoundListener>, Ptr32<W3dVec3>)> get_position; /* +0x38 */
    unsigned char unknown_3c[0x44 - 0x3c];
    Ptr32<void (Ptr32<W3dSoundListener>, int)> update;        /* +0x44 */
} W3dSoundListenerVtbl;
struct W3dSoundListener {
    Ptr32<W3dSoundListenerVtbl> vtbl;
};

typedef struct W3dSoundConfig W3dSoundConfig;
typedef struct W3dSoundConfigVtbl {
    unsigned char unknown_00[0x84];
    Ptr32<float (Ptr32<W3dSoundConfig>, int)> category_volume; /* +0x84 */
} W3dSoundConfigVtbl;
struct W3dSoundConfig {
    Ptr32<W3dSoundConfigVtbl> vtbl;
};
struct W3dSound {
    Ptr32<W3dSoundVtbl> vtbl;
};

struct W3dSoundEmitter {
    Ptr32<W3dSoundEmitterVtbl> vtbl;
    int id;
    float attenuation;
    W3dVec3 position;
    float volume;
    int mode;
    int cursor;
    int playing;
    unsigned char unknown_28[0x58 - 0x28];
    Ptr32<W3dSound> sound;
};

typedef struct W3dSoundVoiceVtbl {
    unsigned char unknown_00[0x20];
    Ptr32<void (Ptr32<W3dSoundVoice>, Ptr32<W3dSoundListener>, int)> update; /* +0x20 */
    unsigned char unknown_24[0x28 - 0x24];
    Ptr32<void (Ptr32<W3dSoundVoice>)> reset;                    /* +0x28 */
    unsigned char unknown_2c[0x30 - 0x2c];
    Ptr32<void (Ptr32<W3dSoundVoice>, int, float)> set_parameter;   /* +0x30 */
} W3dSoundVoiceVtbl;
struct W3dSoundVoice {
    int id;
    unsigned char unknown_04[0x1c - 0x04];
    Ptr32<W3dSoundVoiceVtbl> vtbl;
};

typedef struct W3dSoundManagerVtbl {
    unsigned char unknown_00[0x38];
    Ptr32<float (Ptr32<W3dSoundManager>)> master_volume;       /* +0x38 */
} W3dSoundManagerVtbl;
typedef struct W3dEmitterVector {
    Ptr32<Ptr32<W3dSoundEmitter>> begin;
    Ptr32<Ptr32<W3dSoundEmitter>> end;
    Ptr32<Ptr32<W3dSoundEmitter>> capacity;
} W3dEmitterVector;

struct W3dSoundManager {
    Ptr32<W3dSoundManagerVtbl> vtbl;
    unsigned char unknown_04[0x14 - 0x04];
    Ptr32<W3dSoundListener> listener;
    unsigned char unknown_18[0x24 - 0x18];
    W3dEmitterVector emitters;
    Ptr32<W3dSoundVoice> voices[32];
};

/* Inlined std::vector<Emitter *> members. */
static inline unsigned int w3d_emitter_vector_size(Ptr32<W3dEmitterVector> vector)
{
    return vector->end - vector->begin;
}

static inline Ptr32<W3dSoundEmitter> & w3d_emitter_vector_at(Ptr32<W3dEmitterVector> vector, unsigned int index)
{
    return *(vector->begin + index);
}

extern const float w3d_f32_803b04b8[];
extern const float w3d_f32_803b04cc[];
extern const float w3d_f32_803b04e8[];
extern const float w3d_f32_803b04ec[];
extern const float w3d_f32_803b04f0[];
extern const float w3d_f32_803b04f4[];
extern const float w3d_f32_803b04f8[];
extern Ptr32<W3dSoundConfig> w3d_sound_config_804ab80c;
int w3d_sound_get_category_801df288(Ptr32<W3dSound> sound);
float w3d_sound_get_range_801df1bc(Ptr32<W3dSound> sound);
void w3d_sound_emitter_list_init(Ptr32<W3dSoundEmitterList> list);
void w3d_sound_emitter_list_destroy(Ptr32<W3dSoundEmitterList> list, int flags);
void w3d_sound_emitter_list_remove_801e183c(Ptr32<W3dSoundEmitterList> list, unsigned int index);
unsigned int w3d_sound_emitter_list_count(Ptr32<W3dSoundEmitterList> list);
Ptr32<W3dSoundEmitter> w3d_sound_emitter_list_get(Ptr32<W3dSoundEmitterList> list, unsigned int index);
void w3d_sound_emitter_advance(Ptr32<W3dSoundEmitter> emitter, int elapsed);
int w3d_sound_voice_is_busy_801e4fcc(Ptr32<W3dSoundVoice> voice);
int w3d_sound_voice_is_free_801e5024(Ptr32<W3dSoundVoice> voice);
int w3d_sound_voice_assign_801e4ce0(Ptr32<W3dSoundVoice> voice, Ptr32<W3dSoundEmitter> emitter);
int w3d_sound_emitter_update_attenuation(Ptr32<W3dSoundEmitter> emitter, Ptr32<W3dSoundListener> listener);
void w3d_sound_emitter_list_insert(Ptr32<W3dSoundEmitterList> list, Ptr32<W3dSoundEmitter> emitter);
Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
Ptr32<void> w3d_handle_storage_allocate(unsigned int size);
void w3d_handle_storage_release(Ptr32<void> storage);
void w3d_memcpy_802eee50(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);
Ptr32<W3dSoundEmitter> w3d_sound_emitter_construct_801e099c(Ptr32<void> storage);

Ptr32<W3dSoundManager> w3d_sound_system_get(Ptr32<W3dSoundEmitter> emitter);
int w3d_sound_get_base_rate_801df104(Ptr32<W3dSound> sound);
float w3d_sound_get_rate_spread_801df1cc(Ptr32<W3dSound> sound);
float w3d_sound_get_base_volume_801df1b4(Ptr32<W3dSound> sound);
float w3d_sound_get_volume_spread_801df1d4(Ptr32<W3dSound> sound);
int w3d_rand_802ee7dc(void);
int w3d_sound_emitter_vary_rate_801e1274(Ptr32<W3dSoundEmitter> emitter, unsigned int base, float spread);
float w3d_sound_emitter_vary_volume_801e1308(Ptr32<W3dSoundEmitter> emitter, float base, float spread);

static inline void w3d_sound_master_scale(Ptr32<W3dSoundEmitter> emitter, Ptr32<float> scale)
{
    if (w3d_sound_system_get(emitter) != 0) {
        Ptr32<W3dSoundManager> manager = w3d_sound_system_get(emitter);
        *scale = manager->vtbl->master_volume(manager);
    }
}

int w3d_sound_emitter_set_float(Ptr32<W3dSoundEmitter> emitter, int property, float value)
{
    W3dFrameSlot unused;

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

void w3d_sound_emitter_attach_801e117c(Ptr32<W3dSoundEmitter> emitter, Ptr32<W3dSound> sound, int unused_flags)
{
    W3dFrameSlot unused;
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

int w3d_sound_manager_set_voice_parameter(Ptr32<W3dSoundManager> manager, int which, float value)
{
    W3dFrameSlot unused;
    unsigned int i;

    for (i = 0; i <= 31; i++) {
        Ptr32<W3dSoundVoice> voice = manager->voices[i];
        if (voice != 0)
            voice->vtbl->set_parameter(voice, which, value);
    }
    return 0;
}


static inline float w3d_vec3_distance_squared(const W3dVec3 &a, const W3dVec3 &b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    float dz = a.z - b.z;

    return dx * dx + dy * dy + dz * dz;
}

int w3d_sound_emitter_update_attenuation(Ptr32<W3dSoundEmitter> emitter, Ptr32<W3dSoundListener> listener)
{
    W3dVec3 listener_position;
    W3dVec3 unused_a;
    W3dVec3 unused_b;
    float zero;

    listener->vtbl->get_position(listener, &listener_position);
    if (emitter->sound != 0 && emitter->playing != 0) {
        zero = w3d_f32_803b04f4[0];
        if (emitter->volume > zero) {
            float distance = w3d_vec3_distance_squared(emitter->position, listener_position);
            Ptr32<W3dSoundConfig> config = w3d_sound_config_804ab80c;
            float level = emitter->volume * config->vtbl->category_volume(config, w3d_sound_get_category_801df288(emitter->sound));
            float range = w3d_sound_get_range_801df1bc(emitter->sound);
            range = range * w3d_sound_get_range_801df1bc(emitter->sound);
            if (distance < range && level != zero) {
                emitter->attenuation = (float)emitter->sound->vtbl->length(emitter->sound) * distance / level;
                return 0;
            }
        }
    }
    emitter->attenuation = w3d_f32_803b04f8[0];
    return 1;
}


void w3d_sound_emitter_list_insert(Ptr32<W3dSoundEmitterList> list, Ptr32<W3dSoundEmitter> emitter)
{
    W3dFrameSlot unused;
    unsigned int i;

    for (i = 0; i < list->capacity; i++) {
        if (list->items[i] == 0 || list->items[i]->vtbl->priority(list->items[i]) > emitter->vtbl->priority(emitter)) {
            unsigned int j;

            for (j = list->capacity - 1; j > i; j--) {
                Ptr32<Ptr32<W3dSoundEmitter>> item = &list->items[j];
                if (*item != 0)
                    (*item)->vtbl->release(*item);
                *item = 0;
                if (item[-1] != 0)
                    item[-1]->vtbl->add_ref(item[-1]);
                if (*item != 0)
                    (*item)->vtbl->release(*item);
                *item = item[-1];
            }
            if (emitter != 0)
                emitter->vtbl->add_ref(emitter);
            if (list->items[i] != 0)
                list->items[i]->vtbl->release(list->items[i]);
            list->items[i] = emitter;
            if (list->count < list->capacity)
                list->count++;
            return;
        }
    }
}


int w3d_sound_manager_update(Ptr32<W3dSoundManager> manager, int elapsed)
{
    W3dSoundEmitterList list;
    unsigned int i;

    w3d_sound_emitter_list_init(&list);
    list.capacity = 32;
    for (i = 0; i < w3d_emitter_vector_size(&manager->emitters); i++) {
        if (w3d_sound_emitter_update_attenuation(w3d_emitter_vector_at(&manager->emitters, i), manager->listener) == 0
            && w3d_emitter_vector_at(&manager->emitters, i)->vtbl->is_active(w3d_emitter_vector_at(&manager->emitters, i)) != 0)
            w3d_sound_emitter_list_insert(&list, w3d_emitter_vector_at(&manager->emitters, i));
    }
    for (i = 0; i <= 31; i++) {
        if (manager->voices[i] != 0) {
            if (w3d_sound_voice_is_busy_801e4fcc(manager->voices[i]) == 0) {
                manager->voices[i]->vtbl->reset(manager->voices[i]);
            } else {
                int found = 0;
                unsigned int k;

                for (k = 0; k < w3d_sound_emitter_list_count(&list); k++) {
                    if (w3d_sound_emitter_list_get(&list, k) != 0) {
                        int id = manager->voices[i]->id;
                        Ptr32<W3dSoundEmitter> emitter = w3d_sound_emitter_list_get(&list, k);
                        if (id == emitter->vtbl->get_id(emitter)) {
                            w3d_sound_emitter_list_remove_801e183c(&list, k);
                            found = 1;
                            goto searched;
                        }
                    }
                }
            searched:
                if (found != 1)
                    manager->voices[i]->vtbl->reset(manager->voices[i]);
            }
        }
    }
    for (i = 0; i <= 31; i++) {
        if (manager->voices[i] != 0) {
            if (w3d_sound_voice_is_free_801e5024(manager->voices[i]) != 0 && w3d_sound_emitter_list_count(&list) != 0) {
                Ptr32<W3dSoundEmitter> emitter = w3d_sound_emitter_list_get(&list, 0);
                if (emitter->vtbl->is_finished(emitter) != 0 || emitter->cursor == 0)
                    w3d_sound_voice_assign_801e4ce0(manager->voices[i], emitter);
                w3d_sound_emitter_list_remove_801e183c(&list, 0);
            }
            manager->voices[i]->vtbl->update(manager->voices[i], manager->listener, elapsed);
        }
    }
    for (i = 0; i < w3d_emitter_vector_size(&manager->emitters); i++)
        w3d_sound_emitter_advance(w3d_emitter_vector_at(&manager->emitters, i), elapsed);
    manager->listener->vtbl->update(manager->listener, elapsed);
    w3d_sound_emitter_list_destroy(&list, 2);
    return 0;
}


static inline const int &w3d_max_int(const int &a, const int &b)
{
    return a < b ? b : a;
}

static inline const unsigned int &w3d_min_uint(const unsigned int &a, const unsigned int &b)
{
    return b < a ? b : a;
}

/* Inlined vector push_back; sizes are kept in bytes. */
static inline void w3d_emitter_vector_push_back(Ptr32<W3dEmitterVector> vector, Ptr32<W3dSoundManager> manager, Ptr32<W3dSoundEmitter> const &value)
{
    if (vector->end == vector->capacity) {
        unsigned int used = (Ptr32<char>)vector->end - (Ptr32<char>)manager->emitters.begin;
        int grown = used + 1;
        int scaled = used + (used >> 1);
        unsigned int bytes = w3d_max_int(grown, scaled) * 4;
        Ptr32<Ptr32<W3dSoundEmitter>> storage = (Ptr32<Ptr32<W3dSoundEmitter>>)w3d_handle_storage_allocate(bytes);

        if (manager->emitters.begin != 0) {
            w3d_memcpy_802eee50(storage, manager->emitters.begin, w3d_min_uint(bytes, used));
            w3d_handle_storage_release(manager->emitters.begin);
        }
        vector->begin = storage;
        vector->end = (Ptr32<Ptr32<W3dSoundEmitter>>)((Ptr32<char>)storage + used);
        vector->capacity = (Ptr32<Ptr32<W3dSoundEmitter>>)((Ptr32<char>)storage + bytes);
    }
    *vector->end = value;
    vector->end++;
}

Ptr32<W3dSoundEmitter> w3d_sound_manager_create_emitter(Ptr32<W3dSoundManager> manager)
{
    Ptr32<W3dSoundEmitter> emitter = w3d_sound_emitter_construct_801e099c(w3d_heap_allocate_entry_a(92));

    w3d_emitter_vector_push_back(&manager->emitters, manager, emitter);
    return emitter;
}

}


