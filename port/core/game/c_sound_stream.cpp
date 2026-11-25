#include "w3d_ptr.h"
#line 1 "c_sound_stream.cpp"
/* Sound sample accessors and the streamed-sound player (0x801e2650..0x801e3268).
 *
 * Names are inferred from behavior; no original symbols survive. The first
 * functions are the remaining field getters of the sound sample object (see
 * c_sound_sample.cpp for its layout). The player is a reference-counted
 * native node registered in the list record at 0x8036570c and also published
 * as the current instance in small data. Observed player layout (size 0x48):
 *   +0x00 vtable, +0x04 node counts (u16 references), +0x0c node links,
 *   +0x14 embedded member with its own construct/destroy, +0x18 pointer
 *   vector (begin/end/capacity), +0x24 float, +0x28 word,
 *   +0x2c six channel objects (vtable at +0xa8), +0x44 interface pointer.
 * A second object type (references at +0x28) has its type, retain/release
 * and cast helpers here; its other methods follow later in the binary.
 */
extern "C" {

typedef struct EngineString {
    Ptr32<char> data;
} EngineString;

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

typedef struct W3dObjectList {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;
} W3dObjectList;

typedef struct W3dSoundSample {
    Ptr32<void> vtbl;
    W3dNodeCounts counts;
    W3dNodeLinks links;
    EngineString name;
    int unknown_18;
    int unknown_1c;
    EngineString path;
    float unknown_24;
    int unknown_28;
    float unknown_2c;
    float unknown_30;
    float unknown_34;
    float unknown_38;
    float unknown_3c;
    int unknown_40;
    int unknown_44;
    int channels;
    int unknown_4c;
    int unknown_50;
    int unknown_54;
    int streams[2];
    Ptr32<unsigned char> lipsync;
    unsigned int lipsync_length;
} W3dSoundSample;

typedef struct W3dComObject W3dComObject;
typedef struct W3dComVtbl {
    unsigned char unknown_00[0x0c];
    Ptr32<void (Ptr32<W3dComObject>)> add_ref;                  /* +0x0c */
    Ptr32<void (Ptr32<W3dComObject>)> release;                  /* +0x10 */
    unsigned char unknown_14[0x20 - 0x14];
    Ptr32<int (Ptr32<W3dComObject>)> kind;                      /* +0x20 */
} W3dComVtbl;
struct W3dComObject {
    Ptr32<W3dComVtbl> vtbl;
};

typedef struct W3dStreamChannel W3dStreamChannel;
typedef struct W3dStreamChannelVtbl {
    unsigned char unknown_00[0x08];
    Ptr32<void (Ptr32<W3dStreamChannel>, int)> destroy;  /* +0x08 */
} W3dStreamChannelVtbl;
struct W3dStreamChannel {
    int index;
    unsigned char unknown_04[0xa8 - 0x04];
    Ptr32<W3dStreamChannelVtbl> vtbl;
};

typedef struct W3dStreamCue W3dStreamCue;
typedef struct W3dStreamCueVtbl {
    unsigned char unknown_00[0x0c];
    Ptr32<void (Ptr32<W3dStreamCue>)> add_ref;                     /* +0x0c */
    Ptr32<void (Ptr32<W3dStreamCue>)> release;                     /* +0x10 */
    unsigned char unknown_14[0x1c - 0x14];
    Ptr32<void (Ptr32<W3dStreamCue>)> pause;                       /* +0x1c */
    Ptr32<void (Ptr32<W3dStreamCue>)> resume;                      /* +0x20 */
    Ptr32<int (Ptr32<W3dStreamCue>)> is_active;                    /* +0x24 */
    unsigned char unknown_28[0x48 - 0x28];
    Ptr32<int (Ptr32<W3dStreamCue>)> get_id;                       /* +0x48 */
} W3dStreamCueVtbl;

/* Second object type: queued stream cue; reference count at +0x28. */
struct W3dStreamCue {
    Ptr32<W3dStreamCueVtbl> vtbl;
    int id;
    unsigned char unknown_08[0x28 - 0x08];
    unsigned short references;
    unsigned char unknown_2a[0x40 - 0x2a];
    Ptr32<W3dComObject> sample;
};

typedef struct W3dPointerVector {
    Ptr32<Ptr32<W3dStreamCue>> begin;
    Ptr32<Ptr32<W3dStreamCue>> end;
    Ptr32<Ptr32<W3dStreamCue>> capacity;
} W3dPointerVector;

static inline unsigned int w3d_cue_vector_size(Ptr32<W3dPointerVector> vector)
{
    return vector->end - vector->begin;
}

static inline Ptr32<W3dStreamCue> & w3d_cue_vector_at(Ptr32<W3dPointerVector> vector, unsigned int index)
{
    return *(vector->begin + index);
}

typedef struct W3dStreamPlayer {
    Ptr32<void> vtbl;
    W3dNodeCounts counts;
    W3dNodeLinks links;
    int member;
    W3dPointerVector queue;
    float volume;
    int unknown_28;
    Ptr32<W3dStreamChannel> channels[6];
    Ptr32<W3dComObject> output;
} W3dStreamPlayer;

/* W3dStreamPlayer.unknown_28 doubles as the last issued cue id. */


extern W3dObjectList w3d_stream_player_list_8036570c;
extern unsigned char w3d_stream_cue_type_803b0624[];
extern unsigned char w3d_stream_player_type_803b063c[];
extern unsigned char w3d_stream_player_base_vtable_80416d78[];
extern unsigned char w3d_stream_player_vtable_80416e88[];
extern const float w3d_f32_803b0654[];
extern Ptr32<W3dStreamPlayer> w3d_stream_player_current_804ab84c;

Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_actor_member_delete_backend(Ptr32<void> block);
void w3d_actor_node_destroy(Ptr32<void> node, unsigned int flags);
void w3d_owner_list_remove(Ptr32<W3dObjectList> list, Ptr32<void> node);
void w3d_state_register(Ptr32<W3dObjectList> list, Ptr32<void> node);
void w3d_handle_storage_release(Ptr32<void> storage);
int w3d_type_cast_8020b460(Ptr32<void> object, Ptr32<void> type, int a, Ptr32<void> b);
void w3d_stream_cue_unlink_801e37b0(Ptr32<W3dStreamCue> cue);
void w3d_stream_cue_destroy_801e3528(Ptr32<W3dStreamCue> cue, int flags);
Ptr32<W3dStreamPlayer> w3d_stream_player_construct_801e292c(Ptr32<W3dStreamPlayer> player);
void w3d_stream_player_destroy_801e29e8(Ptr32<W3dStreamPlayer> player, int flags);
void w3d_stream_member_construct_801e3f00(Ptr32<int> member);
void w3d_stream_member_destroy_801e3f0c(Ptr32<int> member, int flags);
void w3d_stream_member_open_801e3f3c(Ptr32<int> member);
void w3d_stream_member_close_801e4020(Ptr32<int> member);
Ptr32<W3dStreamChannel> w3d_stream_channel_construct_801e5a60(Ptr32<void> storage);
void w3d_stream_channel_setup_801e5b7c(Ptr32<W3dStreamChannel> channel, int a, int b);
void w3d_stream_channel_stop_801e5dfc(Ptr32<W3dStreamChannel> channel);
void w3d_stream_channel_pause_801e5f24(Ptr32<W3dStreamChannel> channel);
void w3d_stream_channel_resume_801e5f84(Ptr32<W3dStreamChannel> channel);
int w3d_sound_sample_get_44(Ptr32<W3dComObject> sample);
Ptr32<W3dStreamCue> w3d_stream_player_new_cue_801e3268(Ptr32<W3dStreamPlayer> player);
void w3d_stream_cue_detach_801e3824(Ptr32<W3dStreamCue> cue);

Ptr32<const char> w3d_sound_sample_get_path(Ptr32<W3dSoundSample> sample)
{
    return sample->path.data;
}

int w3d_sound_sample_get_28(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_28;
}

float w3d_sound_sample_get_2c(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_2c;
}

float w3d_sound_sample_get_30(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_30;
}

int w3d_sound_sample_get_4c(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_4c;
}

float w3d_sound_sample_get_24(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_24;
}

int w3d_sound_sample_get_channels(Ptr32<W3dSoundSample> sample)
{
    return sample->channels;
}

int w3d_sound_sample_get_1c(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_1c;
}

float w3d_sound_sample_get_3c(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_3c;
}

float w3d_sound_sample_get_38(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_38;
}

int w3d_sound_sample_get_50(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_50;
}

int w3d_sound_sample_get_54(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_54;
}

int w3d_sound_sample_get_stream(Ptr32<W3dSoundSample> sample, unsigned int index)
{
    return sample->streams[index];
}

Ptr32<W3dObjectList> w3d_stream_player_list_get(void)
{
    return &w3d_stream_player_list_8036570c;
}

void w3d_stream_player_unlink(Ptr32<W3dStreamPlayer> player)
{
    w3d_owner_list_remove(&w3d_stream_player_list_8036570c, &player->counts);
    w3d_stream_player_list_8036570c.count--;
}

Ptr32<W3dStreamPlayer> w3d_stream_player_create(void)
{
    Ptr32<W3dStreamPlayer> player = w3d_stream_player_construct_801e292c((Ptr32<W3dStreamPlayer>)w3d_heap_allocate_entry_a(72));
    w3d_state_register(&w3d_stream_player_list_8036570c, player ? w3d::R(&player->counts) : 0);
    w3d_stream_player_list_8036570c.count++;
    return player;
}

Ptr32<void> w3d_stream_cue_type_get(void)
{
    return w3d_stream_cue_type_803b0624;
}

unsigned short w3d_stream_cue_release(Ptr32<W3dStreamCue> cue)
{
    unsigned short remaining = --cue->references;
    if (remaining == 0) {
        w3d_stream_cue_unlink_801e37b0(cue);
        if (cue)
            w3d_stream_cue_destroy_801e3528(cue, 3);
    }
    return remaining;
}

unsigned short w3d_stream_cue_retain(Ptr32<W3dStreamCue> cue)
{
    return cue->references++;
}

int w3d_stream_cue_cast(Ptr32<void> object, int a, int b)
{
    return w3d_type_cast_8020b460(object, w3d_stream_cue_type_get(), a, (Ptr32<void>)w3d::G(b));
}

Ptr32<void> w3d_stream_player_type_get(void)
{
    return w3d_stream_player_type_803b063c;
}

unsigned short w3d_stream_player_release(Ptr32<W3dStreamPlayer> player)
{
    unsigned short remaining = --player->counts.references;
    if (remaining == 0) {
        w3d_stream_player_unlink(player);
        if (player)
            w3d_stream_player_destroy_801e29e8(player, 3);
    }
    return remaining;
}

unsigned short w3d_stream_player_retain(Ptr32<W3dStreamPlayer> player)
{
    return player->counts.references++;
}

int w3d_stream_player_cast(Ptr32<void> object, int a, int b)
{
    return w3d_type_cast_8020b460(object, w3d_stream_player_type_get(), a, (Ptr32<void>)w3d::G(b));
}

Ptr32<W3dStreamPlayer> w3d_stream_player_construct_801e292c(Ptr32<W3dStreamPlayer> player)
{
    Ptr32<Ptr32<W3dStreamChannel>> channel;
    int i;

    player->vtbl = w3d_stream_player_base_vtable_80416d78;
    Ptr32<W3dNodeCounts> counts = &player->counts;
    counts->flags.bytes[3] = 2;
    W3dNodeFlagWord &flags = counts->flags;
    flags.word = flags.bytes[3];
    player->links.next = 0;
    W3dNodeLinks &links = player->links;
    links.previous = 0;
    counts->references = 0;
    counts->second = 0;
    player->vtbl = w3d_stream_player_vtable_80416e88;
    w3d_stream_member_construct_801e3f00(&player->member);
    W3dPointerVector &queue = player->queue;
    queue.capacity = 0;
    queue.end = 0;
    queue.begin = 0;
    player->output = 0;
    w3d_stream_player_current_804ab84c = player;
    player->volume = w3d_f32_803b0654[0];
    player->unknown_28 = 0;
    channel = player->channels;
    for (i = 6; i != 0; i--)
        *channel++ = 0;
    return player;
}

void w3d_stream_player_destroy_801e29e8(Ptr32<W3dStreamPlayer> player, int flags)
{
    unsigned int i;

    player->vtbl = w3d_stream_player_vtable_80416e88;
    for (i = 0; i <= 5; i++) {
        Ptr32<W3dStreamChannel> channel = player->channels[i];
        if (channel != 0)
            channel->vtbl->destroy(channel, 3);
    }
    w3d_stream_player_current_804ab84c = 0;
    if (player->output != 0)
        player->output->vtbl->release(player->output);
    if (player->queue.begin != 0)
        w3d_handle_storage_release(player->queue.begin);
    w3d_stream_member_destroy_801e3f0c(&player->member, 2);
    player->vtbl = w3d_stream_player_base_vtable_80416d78;
    w3d_actor_node_destroy(&player->counts, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(player);
}

int w3d_stream_player_open(Ptr32<W3dStreamPlayer> player)
{
    unsigned int i;

    w3d_stream_member_open_801e3f3c(&player->member);
    for (i = 0; i <= 5; i++) {
        player->channels[i] = w3d_stream_channel_construct_801e5a60(w3d_heap_allocate_entry_a(172));
        w3d_stream_channel_setup_801e5b7c(player->channels[i], 0, 1000);
        player->channels[i]->index = i;
    }
    return 0;
}

int w3d_stream_player_close(Ptr32<W3dStreamPlayer> player)
{
    unsigned int i;

    for (i = 0; i <= 5; i++) {
        if (player->channels[i] != 0) {
            w3d_stream_channel_stop_801e5dfc(player->channels[i]);
            if (player->channels[i] != 0)
                player->channels[i]->vtbl->destroy(player->channels[i], 3);
            player->channels[i] = 0;
        }
    }
    w3d_stream_member_close_801e4020(&player->member);
    return 0;
}

int w3d_stream_player_stop_all(Ptr32<W3dStreamPlayer> player)
{
    unsigned int i;

    for (i = 0; i <= 5; i++) {
        Ptr32<W3dStreamChannel> channel = player->channels[i];
        if (channel != 0)
            w3d_stream_channel_stop_801e5dfc(channel);
    }
    return 0;
}

int w3d_stream_player_kind(Ptr32<W3dStreamPlayer> player)
{
    return 2;
}

int w3d_stream_player_stub_801e2e38(Ptr32<W3dStreamPlayer> player)
{
    return 0;
}

int w3d_stream_player_not_implemented_801e2f04(void)
{
    return (int)0x80004001;
}

int w3d_stream_player_set_volume(Ptr32<W3dStreamPlayer> player, float volume)
{
    player->volume = volume;
    return 0;
}

float w3d_stream_player_get_volume(Ptr32<W3dStreamPlayer> player)
{
    return player->volume;
}

int w3d_stream_player_not_implemented_801e325c(void)
{
    return (int)0x80004001;
}


int w3d_stream_player_pause_category(Ptr32<W3dStreamPlayer> player, int category)
{
    unsigned int i;
    unsigned int j;

    for (i = 0; i < w3d_cue_vector_size(&player->queue); i++) {
        if (w3d_cue_vector_at(&player->queue, i)->sample == 0
            || w3d_sound_sample_get_44(w3d_cue_vector_at(&player->queue, i)->sample) == category) {
            if (w3d_cue_vector_at(&player->queue, i)->vtbl->is_active(w3d_cue_vector_at(&player->queue, i))) {
                w3d_cue_vector_at(&player->queue, i)->vtbl->pause(w3d_cue_vector_at(&player->queue, i));
                for (j = 0; j <= 5; j++) {
                    int index = player->channels[j]->index;
                    if (index == w3d_cue_vector_at(&player->queue, i)->vtbl->get_id(w3d_cue_vector_at(&player->queue, i))) {
                        w3d_stream_channel_pause_801e5f24(player->channels[j]);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}

int w3d_stream_player_resume_category(Ptr32<W3dStreamPlayer> player, int category)
{
    unsigned int i;
    unsigned int j;

    for (i = 0; i < w3d_cue_vector_size(&player->queue); i++) {
        if (w3d_cue_vector_at(&player->queue, i)->sample == 0
            || w3d_sound_sample_get_44(w3d_cue_vector_at(&player->queue, i)->sample) == category) {
            w3d_cue_vector_at(&player->queue, i)->vtbl->resume(w3d_cue_vector_at(&player->queue, i));
            for (j = 0; j <= 5; j++) {
                int index = player->channels[j]->index;
                if (index == w3d_cue_vector_at(&player->queue, i)->vtbl->get_id(w3d_cue_vector_at(&player->queue, i))) {
                    w3d_stream_channel_resume_801e5f84(player->channels[j]);
                    break;
                }
            }
        }
    }
    return 0;
}

int w3d_stream_player_create_cue(Ptr32<W3dStreamPlayer> player, Ptr32<W3dComObject> sample, Ptr32<Ptr32<W3dStreamCue>> out)
{
    Ptr32<W3dStreamCue> cue = w3d_stream_player_new_cue_801e3268(player);

    cue->id = ++player->unknown_28;
    if (sample != 0)
        sample->vtbl->add_ref(sample);
    if (cue->sample != 0)
        cue->sample->vtbl->release(cue->sample);
    cue->sample = sample;
    if (cue != 0)
        cue->vtbl->add_ref(cue);
    if (*out != 0)
        (*out)->vtbl->release(*out);
    *out = cue;
    return 0;
}


int w3d_stream_player_forget_sample(Ptr32<W3dStreamPlayer> player, Ptr32<W3dComObject> sample)
{
    unsigned int i;
    unsigned int j;

    if (sample->vtbl->kind(sample) != 2)
        return 1;
    for (i = 0; i < w3d_cue_vector_size(&player->queue); i++) {
        if (w3d_cue_vector_at(&player->queue, i)->sample == sample) {
            w3d_stream_cue_detach_801e3824(w3d_cue_vector_at(&player->queue, i));
            for (j = 0; j <= 5; j++) {
                if (w3d_cue_vector_at(&player->queue, i)->vtbl->get_id(w3d_cue_vector_at(&player->queue, i))
                    == player->channels[j]->index) {
                    w3d_stream_channel_stop_801e5dfc(player->channels[j]);
                    break;
                }
            }
        }
    }
    return 0;
}

}


