#include "w3d_ptr.h"
#line 1 "c_stream_cue.cpp"
/* Stream player update and stream cue methods (0x801e3010..0x801e3990).
 *
 * Names are inferred from behavior; no original symbols survive. A stream cue
 * mirrors the sound emitter interface for streamed audio. Observed cue layout
 * (size 0x44):
 *   +0x00 vtable, +0x04 id, +0x08 attenuation, +0x0c position,
 *   +0x18 volume, +0x20 play cursor, +0x24 playing flag,
 *   +0x28 native node counts (u16 references), +0x30 node links,
 *   +0x38 position-set flag, +0x3c pause depth, +0x40 sample interface.
 * The player layout is described in c_sound_stream.cpp.
 */
extern "C" {

typedef struct W3dVec3 {
    float x, y, z;
} W3dVec3;

typedef struct W3dFrameSlot {
    short unknown[3];
} W3dFrameSlot;

typedef union W3dNodeFlagWord {
    unsigned int word;
    w3d::be_array<unsigned char, 4> bytes;
} W3dNodeFlagWord;
typedef struct W3dNodeCounts {
    unsigned short references, second;
    W3dNodeFlagWord flags;
} W3dNodeCounts;
typedef struct W3dNodeLinks {
    Ptr32<void> next; Ptr32<void> previous;
} W3dNodeLinks;

typedef struct W3dComObject W3dComObject;
typedef struct W3dComVtbl {
    unsigned char unknown_00[0x0c];
    Ptr32<void (Ptr32<W3dComObject>)> add_ref;                  /* +0x0c */
    Ptr32<void (Ptr32<W3dComObject>)> release;                  /* +0x10 */
    unsigned char unknown_14[0x60 - 0x14];
    Ptr32<int (Ptr32<W3dComObject>)> query_60;                  /* +0x60 */
    unsigned char unknown_64[0x7c - 0x64];
    Ptr32<float (Ptr32<W3dComObject>, int)> position_at; /* +0x7c */
} W3dComVtbl;
struct W3dComObject {
    Ptr32<W3dComVtbl> vtbl;
};

typedef struct W3dStreamCue W3dStreamCue;
typedef struct W3dStreamCueVtbl {
    unsigned char unknown_00[0x0c];
    Ptr32<void (Ptr32<W3dStreamCue>)> add_ref;                     /* +0x0c */
    Ptr32<void (Ptr32<W3dStreamCue>)> release;                     /* +0x10 */
    unsigned char unknown_14[0x18 - 0x14];
    Ptr32<void (Ptr32<W3dStreamCue>)> stop;                        /* +0x18 */
    unsigned char unknown_1c[0x24 - 0x1c];
    Ptr32<int (Ptr32<W3dStreamCue>)> is_active;                    /* +0x24 */
    unsigned char unknown_28[0x48 - 0x28];
    Ptr32<int (Ptr32<W3dStreamCue>)> get_id;                       /* +0x48 */
} W3dStreamCueVtbl;

struct W3dStreamCue {
    Ptr32<W3dStreamCueVtbl> vtbl;
    int id;
    float attenuation;
    W3dVec3 position;
    float volume;
    int unknown_1c;
    int cursor;
    int playing;
    W3dNodeCounts counts;
    W3dNodeLinks links;
    int position_set;
    int pause_depth;
    Ptr32<W3dComObject> sample;
};

typedef struct W3dStreamChannel W3dStreamChannel;
typedef struct W3dStreamChannelVtbl {
    unsigned char unknown_00[0x0c];
    Ptr32<void (Ptr32<W3dStreamChannel>, int, float)> set_parameter; /* +0x0c */
} W3dStreamChannelVtbl;
struct W3dStreamChannel {
    int index;
    unsigned char unknown_04[0xa8 - 0x04];
    Ptr32<W3dStreamChannelVtbl> vtbl;
};

typedef struct W3dCueVector {
    Ptr32<Ptr32<W3dStreamCue>> begin;
    Ptr32<Ptr32<W3dStreamCue>> end;
    Ptr32<Ptr32<W3dStreamCue>> capacity;
} W3dCueVector;

typedef struct W3dStreamPlayer {
    Ptr32<void> vtbl;
    W3dNodeCounts counts;
    W3dNodeLinks links;
    int member;
    W3dCueVector queue;
    float volume;
    int next_id;
    Ptr32<W3dStreamChannel> channels[6];
    Ptr32<W3dComObject> output;
} W3dStreamPlayer;

/* Same 32-slot priority list as the emitter manager uses, holding cues. */
typedef struct W3dCueList {
    Ptr32<W3dStreamCue> items[32];
    unsigned int count;
    unsigned int capacity;
} W3dCueList;

static inline unsigned int w3d_cue_vector_size(Ptr32<W3dCueVector> vector)
{
    return vector->end - vector->begin;
}

static inline Ptr32<W3dStreamCue> & w3d_cue_vector_at(Ptr32<W3dCueVector> vector, unsigned int index)
{
    return *(vector->begin + index);
}

static inline Ptr32<Ptr32<W3dStreamCue>> w3d_cue_vector_begin(Ptr32<W3dCueVector> vector)
{
    return vector->begin;
}

static inline Ptr32<Ptr32<W3dStreamCue>> w3d_cue_vector_end(Ptr32<W3dCueVector> vector)
{
    return vector->end;
}

Ptr32<void> memcpy(Ptr32<void> dest, Ptr32<const void> source, unsigned int size, ...);

static inline void w3d_cue_vector_erase(Ptr32<W3dCueVector> vector, Ptr32<Ptr32<W3dStreamCue>> item)
{
    if (item + 1 != vector->end)
        memcpy(item, item + 1, (Ptr32<char>)vector->end - (Ptr32<char>)(item + 1));
    vector->end--;
}

extern Ptr32<W3dStreamPlayer> w3d_stream_player_current_804ab84c;
extern unsigned char w3d_stream_cue_base_vtable_80416a90[];
extern unsigned char w3d_stream_cue_vtable_80416ee0[];
extern const float w3d_f32_803b0658[];
extern const float w3d_f32_803b065c[];
extern const float w3d_f32_803b0660[];

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
Ptr32<void> w3d_handle_storage_allocate(unsigned int size);
void w3d_handle_storage_release(Ptr32<void> storage);
void w3d_sound_emitter_list_init(Ptr32<W3dCueList> list);
void w3d_sound_emitter_list_destroy(Ptr32<W3dCueList> list, int flags);
void w3d_sound_emitter_list_insert(Ptr32<W3dCueList> list, Ptr32<W3dStreamCue> cue);
void w3d_sound_emitter_list_remove_801e183c(Ptr32<W3dCueList> list, unsigned int index);
unsigned int w3d_sound_emitter_list_count(Ptr32<W3dCueList> list);
Ptr32<W3dStreamCue> w3d_sound_emitter_list_get(Ptr32<W3dCueList> list, unsigned int index);
Ptr32<W3dStreamCue> w3d_stream_cue_construct_801e34b0(Ptr32<void> storage);
void w3d_stream_channel_update_801e6054(Ptr32<W3dStreamChannel> channel, int elapsed, Ptr32<W3dComObject> output);
int w3d_stream_channel_is_busy_801e5fd4(Ptr32<W3dStreamChannel> channel);
void w3d_stream_channel_assign_801e5b80(Ptr32<W3dStreamChannel> channel, Ptr32<W3dStreamCue> cue);
void w3d_stream_channel_stop_801e5dfc(Ptr32<W3dStreamChannel> channel);
void w3d_stream_cue_advance_801e3888(Ptr32<W3dStreamCue> cue, int elapsed);
int w3d_stream_cue_update_attenuation_801e38a4(Ptr32<W3dStreamCue> cue, Ptr32<W3dComObject> output);
void w3d_stream_player_remove_cue_801e337c(Ptr32<W3dStreamPlayer> player, int id);
void w3d_actor_node_destroy(Ptr32<void> node, unsigned int flags);
void w3d_actor_member_delete_backend(Ptr32<void> block);
Ptr32<W3dStreamPlayer> w3d_stream_player_current_801e3880(Ptr32<W3dStreamCue> cue);

#if 0 /* skipped 0x801e3010: channel loop is a bare pointer walk in the original; loop form and register allocation differ */
int w3d_stream_player_update(W3dStreamPlayer *player, int elapsed)
{
    W3dCueList list;
    unsigned int i;
    W3dStreamChannel **channels = player->channels;
    W3dStreamChannel **channel;

    w3d_sound_emitter_list_init(&list);
    list.capacity = 6;
    for (i = 0; i <= 5; i++) {
        if (channels[i] != 0)
            w3d_stream_channel_update_801e6054(channels[i], elapsed, player->output);
    }
    for (i = 0; i < w3d_cue_vector_size(&player->queue); i++) {
        w3d_stream_cue_advance_801e3888(w3d_cue_vector_at(&player->queue, i), elapsed);
        if (w3d_cue_vector_at(&player->queue, i)->vtbl->is_active(w3d_cue_vector_at(&player->queue, i)) != 0
            && w3d_stream_cue_update_attenuation_801e38a4(w3d_cue_vector_at(&player->queue, i), player->output) == 0)
            w3d_sound_emitter_list_insert(&list, w3d_cue_vector_at(&player->queue, i));
    }
    for (channel = channels; channel <= channels + 5; channel++) {
        if (w3d_stream_channel_is_busy_801e5fd4(*channel) != 0) {
            int found = 0;
            unsigned int k;

            for (k = 0; k < w3d_sound_emitter_list_count(&list); k++) {
                if (w3d_sound_emitter_list_get(&list, k) != 0) {
                    int index = (*channel)->index;
                    W3dStreamCue *cue = w3d_sound_emitter_list_get(&list, k);
                    if (index == cue->vtbl->get_id(cue)) {
                        w3d_sound_emitter_list_remove_801e183c(&list, k);
                        found = 1;
                        goto searched;
                    }
                }
            }
        searched:
            if (found == 0)
                w3d_stream_channel_stop_801e5dfc(*channel);
        }
    }
    for (i = 0; i <= 5; i++) {
        if (channels[i] != 0 && w3d_stream_channel_is_busy_801e5fd4(channels[i]) == 0
            && w3d_sound_emitter_list_count(&list) != 0) {
            W3dStreamCue *cue = w3d_sound_emitter_list_get(&list, 0);
            w3d_stream_channel_assign_801e5b80(channels[i], cue);
            w3d_stream_channel_update_801e6054(channels[i], 0, player->output);
            w3d_sound_emitter_list_remove_801e183c(&list, 0);
        }
    }
    w3d_sound_emitter_list_destroy(&list, 2);
    return 0;
}
#endif

static inline const int &w3d_max_int(const int &a, const int &b)
{
    return a < b ? b : a;
}

static inline const unsigned int &w3d_min_uint(const unsigned int &a, const unsigned int &b)
{
    return b < a ? b : a;
}

/* Inlined vector push_back; sizes are kept in bytes. */
static inline void w3d_cue_vector_push_back(Ptr32<W3dCueVector> vector, Ptr32<W3dStreamPlayer> player, Ptr32<W3dStreamCue> const &value)
{
    if (vector->end == vector->capacity) {
        unsigned int used = (Ptr32<char>)vector->end - (Ptr32<char>)player->queue.begin;
        int grown = used + 1;
        int scaled = used + (used >> 1);
        unsigned int bytes = w3d_max_int(grown, scaled) * 4;
        Ptr32<Ptr32<W3dStreamCue>> storage = (Ptr32<Ptr32<W3dStreamCue>>)w3d_handle_storage_allocate(bytes);

        if (player->queue.begin != 0) {
            memcpy(storage, player->queue.begin, w3d_min_uint(bytes, used));
            w3d_handle_storage_release(player->queue.begin);
        }
        vector->begin = storage;
        vector->end = (Ptr32<Ptr32<W3dStreamCue>>)((Ptr32<char>)storage + used);
        vector->capacity = (Ptr32<Ptr32<W3dStreamCue>>)((Ptr32<char>)storage + bytes);
    }
    *vector->end = value;
    vector->end++;
}

Ptr32<W3dStreamCue> w3d_stream_player_new_cue(Ptr32<W3dStreamPlayer> player)
{
    Ptr32<W3dStreamCue> cue = w3d_stream_cue_construct_801e34b0(w3d_heap_allocate_entry_a(68));

    w3d_cue_vector_push_back(&player->queue, player, cue);
    return cue;
}

void w3d_stream_player_remove_cue_801e337c(Ptr32<W3dStreamPlayer> player, int id)
{
    unsigned int i;
    Ptr32<Ptr32<W3dStreamCue>> item;

    for (i = 0; i <= 5; i++) {
        if (player->channels[i]->index == id)
            w3d_stream_channel_stop_801e5dfc(player->channels[i]);
    }
    for (item = w3d_cue_vector_begin(&player->queue); item != w3d_cue_vector_end(&player->queue); item++) {
        if ((*item)->vtbl->get_id(*item) == id) {
            w3d_cue_vector_erase(&player->queue, item);
            break;
        }
    }
}

void w3d_stream_player_set_output(Ptr32<W3dStreamPlayer> player, Ptr32<W3dComObject> output)
{
    if (output != 0)
        output->vtbl->add_ref(output);
    if (player->output != 0)
        player->output->vtbl->release(player->output);
    player->output = output;
}

#if 0 /* skipped 0x801e34b0: leaf constructor register choice and node-field addressing differ */
W3dStreamCue *w3d_stream_cue_construct_801e34b0(void *storage)
{
    W3dStreamCue *cue = (W3dStreamCue *)storage;

    cue->vtbl = (W3dStreamCueVtbl *)w3d_stream_cue_base_vtable_80416a90;
    W3dNodeCounts *counts = &cue->counts;
    counts->flags.bytes[3] = 2;
    W3dNodeFlagWord &flags = counts->flags;
    flags.word = flags.bytes[3];
    cue->links.next = 0;
    W3dNodeLinks &links = cue->links;
    links.previous = 0;
    counts->references = 0;
    counts->second = 0;
    cue->vtbl = (W3dStreamCueVtbl *)w3d_stream_cue_vtable_80416ee0;
    cue->cursor = 0;
    cue->attenuation = w3d_f32_803b0658[0];
    cue->volume = w3d_f32_803b065c[0];
    cue->sample = 0;
    cue->playing = 0;
    cue->position_set = 0;
    cue->pause_depth = 0;
    return cue;
}
#endif

void w3d_stream_cue_destroy(Ptr32<W3dStreamCue> cue, int flags)
{
    cue->vtbl = (Ptr32<W3dStreamCueVtbl>)w3d_stream_cue_vtable_80416ee0;
    if (cue->sample != 0)
        cue->sample->vtbl->release(cue->sample);
    cue->vtbl = (Ptr32<W3dStreamCueVtbl>)w3d_stream_cue_base_vtable_80416a90;
    w3d_actor_node_destroy(&cue->counts, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(cue);
}

int w3d_stream_cue_start(Ptr32<W3dStreamCue> cue)
{
    cue->playing = 1;
    return 0;
}

int w3d_stream_cue_stop(Ptr32<W3dStreamCue> cue)
{
    cue->playing = 0;
    return 0;
}

int w3d_stream_cue_pause(Ptr32<W3dStreamCue> cue)
{
    cue->pause_depth++;
    return 0;
}

int w3d_stream_cue_resume(Ptr32<W3dStreamCue> cue)
{
    if (cue->pause_depth > 0)
        cue->pause_depth--;
    return 0;
}

int w3d_stream_cue_is_audible(Ptr32<W3dStreamCue> cue)
{
    if (cue->playing != 0 && cue->pause_depth == 0)
        return 1;
    return 0;
}

int w3d_stream_cue_query_sample(Ptr32<W3dStreamCue> cue)
{
    if (cue->sample == 0)
        return 0;
    return cue->sample->vtbl->query_60(cue->sample);
}

int w3d_stream_cue_has_property(Ptr32<W3dStreamCue> cue, int property)
{
    switch (property) {
    case 1:
    case 3:
        return 1;
    }
    return 0;
}

int w3d_stream_cue_not_implemented_801e367c(void)
{
    return (int)0x80004001;
}

int w3d_stream_cue_set_float(Ptr32<W3dStreamCue> cue, int property, float value)
{
    switch (property) {
    case 1:
        cue->volume = value;
        return 0;
    }
    return (int)0x80004005;
}

int w3d_stream_cue_set_vector(Ptr32<W3dStreamCue> cue, int property, Ptr32<W3dVec3> value)
{
    switch (property) {
    case 3:
        cue->position = *value;
        cue->position_set = 1;
        return 0;
    }
    return (int)0x80004005;
}

int w3d_stream_cue_not_implemented_801e36ec(void)
{
    return (int)0x80004001;
}

int w3d_stream_cue_get_float(Ptr32<W3dStreamCue> cue, int property, Ptr32<float> out)
{
    if (property == 24) {
        if (cue->sample != 0) {
            *out = cue->sample->vtbl->position_at(cue->sample, cue->cursor);
            return 0;
        }
    } else if (property == 1) {
        *out = cue->volume;
        return 0;
    }
    return (int)0x80004001;
}

int w3d_stream_cue_get_vector(Ptr32<W3dStreamCue> cue, int property, Ptr32<W3dVec3> out)
{
    switch (property) {
    case 3:
        *out = cue->position;
        return 0;
    }
    return (int)0x80004001;
}

void w3d_stream_cue_shutdown(Ptr32<W3dStreamCue> cue)
{
    Ptr32<W3dStreamPlayer> player = w3d_stream_player_current_801e3880(cue);

    if (cue->vtbl->is_active(cue) != 0)
        cue->vtbl->stop(cue);
    if (player != 0)
        w3d_stream_player_remove_cue_801e337c(player, cue->id);
}

void w3d_stream_cue_detach(Ptr32<W3dStreamCue> cue)
{
    cue->vtbl->stop(cue);
    if (cue->sample != 0)
        cue->sample->vtbl->release(cue->sample);
    cue->sample = 0;
}

Ptr32<W3dStreamPlayer> w3d_stream_player_current_801e3880(Ptr32<W3dStreamCue> cue)
{
    return w3d_stream_player_current_804ab84c;
}

void w3d_stream_cue_advance_801e3888(Ptr32<W3dStreamCue> cue, int elapsed)
{
    if (cue->playing != 0)
        cue->cursor += elapsed;
}

int w3d_stream_cue_update_attenuation_801e38a4(Ptr32<W3dStreamCue> cue, Ptr32<W3dComObject> output)
{
    cue->attenuation = w3d_f32_803b0660[0];
    return 0;
}

int w3d_stream_player_set_channel_parameter(Ptr32<W3dStreamPlayer> player, int which, float value)
{
    W3dFrameSlot unused;
    unsigned int i;

    for (i = 0; i <= 5; i++) {
        Ptr32<W3dStreamChannel> channel = player->channels[i];
        if (channel != 0)
            channel->vtbl->set_parameter(channel, which, value);
    }
    return 0;
}

int w3d_stream_cue_get_position_set(Ptr32<W3dStreamCue> cue)
{
    return cue->position_set;
}

}


