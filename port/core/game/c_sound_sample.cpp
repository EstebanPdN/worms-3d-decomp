#include "w3d_ptr.h"
#line 1 "c_sound_sample.cpp"
/* Sound sample descriptors kept in a global owner list (0x801e1958..0x801e25dc).
 *
 * Names are inferred from behavior; no original symbols survive. Samples are
 * reference-counted native nodes registered in the list record at 0x803656dc
 * (u16 element count at +0x22). Observed sample layout (size 0x68):
 *   +0x00 vtable, +0x04 node counts (u16 references), +0x0c node links,
 *   +0x14 name string, +0x18 word, +0x1c word, +0x20 file path string,
 *   +0x24 float, +0x28 word, +0x2c/+0x30 float pair, +0x34 float,
 *   +0x38/+0x3c float pair, +0x40 word, +0x44 word, +0x48 channel count,
 *   +0x4c/+0x50/+0x54 words, +0x58 two stream handles (-1 when closed),
 *   +0x60 lip-sync byte table, +0x64 lip-sync table length.
 */
extern "C" {

typedef struct EngineString {
    Ptr32<char> data;
} EngineString;

typedef struct W3dHeap {
    Ptr32<void> core;
} W3dHeap;

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

typedef struct W3dSampleList {
    unsigned char unknown_00[0x20];
    unsigned short count; unsigned short w3d_flags_high;
} W3dSampleList;

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

/* Static description used to initialise a sample. */
typedef struct W3dSoundSampleDesc {
    Ptr32<const char> name;
    unsigned char unknown_04[0x0c - 0x04];
    Ptr32<const char> path;
    float unknown_10;
    int unknown_14;
    int unknown_18;
    int unknown_1c;
    float unknown_20;
    float unknown_24;
    float unknown_28;
    float unknown_2c;
    float unknown_30;
    unsigned char unknown_34[0x3c - 0x34];
    int unknown_3c;
} W3dSoundSampleDesc;

typedef struct W3dArchiveWriter W3dArchiveWriter;
typedef struct W3dArchiveWriterVtbl {
    unsigned char unknown_00[0x28];
    Ptr32<void (Ptr32<W3dArchiveWriter>, int, int, int)> write_bool;          /* +0x28 */
    unsigned char unknown_2c[0x50 - 0x2c];
    Ptr32<void (Ptr32<W3dArchiveWriter>, int, int, int)> write_int;           /* +0x50 */
    Ptr32<void (Ptr32<W3dArchiveWriter>, unsigned int, int, int)> write_uint; /* +0x54 */
    unsigned char unknown_58[0x70 - 0x58];
    Ptr32<void (Ptr32<W3dArchiveWriter>, float, int, int)> write_float;       /* +0x70 */
    unsigned char unknown_74[0x80 - 0x74];
    Ptr32<void (Ptr32<W3dArchiveWriter>, Ptr32<EngineString>, int, int)> write_string; /* +0x80 */
    unsigned char unknown_84[0x98 - 0x84];
    Ptr32<void (Ptr32<W3dArchiveWriter>, Ptr32<void>, unsigned int, int)> write_bytes; /* +0x98 */
} W3dArchiveWriterVtbl;
struct W3dArchiveWriter {
    Ptr32<W3dArchiveWriterVtbl> vtbl;
};

typedef struct W3dArchiveReader W3dArchiveReader;
typedef struct W3dArchiveReaderVtbl {
    unsigned char unknown_00[0x30];
    Ptr32<void (Ptr32<W3dArchiveReader>, Ptr32<int>, int)> read_bool;                 /* +0x30 */
    unsigned char unknown_34[0x7c - 0x34];
    Ptr32<void (Ptr32<W3dArchiveReader>, Ptr32<int>, int)> read_int;                  /* +0x7c */
    Ptr32<void (Ptr32<W3dArchiveReader>, Ptr32<unsigned int>, int)> read_uint;        /* +0x80 */
    unsigned char unknown_84[0x8c - 0x84];
    Ptr32<void (Ptr32<W3dArchiveReader>, Ptr32<float>, int)> read_float;              /* +0x8c */
    unsigned char unknown_90[0x94 - 0x90];
    Ptr32<void (Ptr32<W3dArchiveReader>, Ptr32<EngineString>, int)> read_string;      /* +0x94 */
    unsigned char unknown_98[0xa0 - 0x98];
    Ptr32<void (Ptr32<W3dArchiveReader>, Ptr32<void>, unsigned int, int)> read_bytes; /* +0xa0 */
} W3dArchiveReaderVtbl;
struct W3dArchiveReader {
    Ptr32<W3dArchiveReaderVtbl> vtbl;
};

typedef struct W3dSoundVoice W3dSoundVoice;
typedef struct W3dSoundVoiceVtbl {
    unsigned char unknown_00[0x30];
    Ptr32<void (Ptr32<W3dSoundVoice>, int, float)> set_parameter;   /* +0x30 */
} W3dSoundVoiceVtbl;
struct W3dSoundVoice {
    unsigned char unknown_00[0x1c];
    Ptr32<W3dSoundVoiceVtbl> vtbl;
};
typedef struct W3dSoundManager {
    unsigned char unknown_00[0x30];
    Ptr32<W3dSoundVoice> voices[32];
} W3dSoundManager;

typedef struct W3dPair {
    int first, second;
} W3dPair;

extern W3dSampleList w3d_sound_sample_list_803656dc;
extern unsigned char w3d_sound_sample_type_803b05b8[];
extern unsigned char w3d_sound_sample_base_vtable_80416bf8[];
extern unsigned char w3d_sound_sample_vtable_80416de0[];
extern const char w3d_str_unused_803b05d0[];
extern const char w3d_str_notset_803b05d8[];
extern const char w3d_str_left_dsp_803b05e0[];
extern const char w3d_str_right_dsp_803b05e8[];
extern const W3dPair w3d_audio_config_803b059c[];
extern const float w3d_f32_803b05f0[];
extern const double w3d_f64_803b05f8[];
extern const float w3d_f32_803b0600[];
extern W3dHeap w3d_lipsync_heap_804b0564;

Ptr32<void> w3d_aligned_allocate(unsigned int size, unsigned int alignment);
void w3d_aligned_release(Ptr32<void> block);
Ptr32<void> w3d_heap_allocate_entry_a(unsigned int size);
void w3d_actor_member_delete_backend(Ptr32<void> block);
void w3d_actor_node_destroy(Ptr32<void> node, unsigned int flags);
void w3d_owner_list_remove(Ptr32<W3dSampleList> list, Ptr32<void> node);
void w3d_state_register(Ptr32<W3dSampleList> list, Ptr32<void> node);
Ptr32<EngineString> w3d_string_default(Ptr32<EngineString> string);
Ptr32<EngineString> w3d_string_assign(Ptr32<EngineString> string, Ptr32<const char> text);
Ptr32<EngineString> w3d_string_append(Ptr32<EngineString> string, Ptr32<const char> text);
void w3d_string_base_finish(Ptr32<EngineString> string);
void w3d_string_release(Ptr32<EngineString> string);
void w3d_heap_release(Ptr32<W3dHeap> heap, Ptr32<void> block);
Ptr32<void> w3d_heap_allocate(Ptr32<W3dHeap> heap, unsigned int size);
void w3d_heap_compact_80209968(Ptr32<W3dHeap> heap);
Ptr32<EngineString> w3d_string_assign_prefix_8020c048(Ptr32<EngineString> string, Ptr32<EngineString> source, int length);
int w3d_stream_open_802f4ef0(Ptr32<const char> path);
int w3d_type_cast_8020b460(Ptr32<void> object, Ptr32<void> type, int a, Ptr32<void> b);
int w3d_audio_set_mode_80311c44(Ptr32<void> state, int mode);
void w3d_audio_start_80313754(void);
void w3d_audio_select_80311640(int which);
void w3d_audio_configure_8033499c(Ptr32<W3dPair> config);
int w3d_audio_open_80331928(int a, int b, int c, int d, int e, int f);
Ptr32<W3dSoundSample> w3d_sound_sample_construct_801e1c80(Ptr32<W3dSoundSample> sample);
void w3d_sound_sample_destroy_801e1d68(Ptr32<W3dSoundSample> sample, int flags);

Ptr32<void> w3d_sound_allocate_aligned(unsigned int size)
{
    return w3d_aligned_allocate(size, 32);
}

void w3d_sound_release_aligned(Ptr32<void> block)
{
    w3d_aligned_release(block);
}

void w3d_audio_hardware_init(Ptr32<unsigned char> system)
{
    W3dPair config;

    w3d_audio_set_mode_80311c44(system + 188, 2);
    w3d_audio_start_80313754();
    w3d_audio_select_80311640(0);
    config = w3d_audio_config_803b059c[0];
    w3d_audio_configure_8033499c(&config);
    w3d_audio_open_80331928(32, 0, 16, 1, 0, 0x400000);
}

#if 0 /* skipped 0x801e1a0c: code matches but original frame has one extra 8-byte slot per saved FPR */
int w3d_sound_manager_set_voice_parameter(W3dSoundManager *manager, int which, float value)
{
    unsigned int i;

    for (i = 0; i <= 31; i++) {
        W3dSoundVoice *voice = manager->voices[i];
        if (voice != 0)
            voice->vtbl->set_parameter(voice, which, value);
    }
    return 0;
}
#endif

Ptr32<W3dSampleList> w3d_sound_sample_list_get(void)
{
    return &w3d_sound_sample_list_803656dc;
}

void w3d_sound_sample_unlink(Ptr32<W3dSoundSample> sample)
{
    w3d_owner_list_remove(&w3d_sound_sample_list_803656dc, &sample->counts);
    w3d_sound_sample_list_803656dc.count--;
}

Ptr32<W3dSoundSample> w3d_sound_sample_create(void)
{
    Ptr32<W3dSoundSample> sample = w3d_sound_sample_construct_801e1c80((Ptr32<W3dSoundSample>)w3d_heap_allocate_entry_a(104));
    w3d_state_register(&w3d_sound_sample_list_803656dc, sample ? w3d::R(&sample->counts) : 0);
    w3d_sound_sample_list_803656dc.count++;
    return sample;
}

Ptr32<void> w3d_sound_sample_type_get(void)
{
    return w3d_sound_sample_type_803b05b8;
}

unsigned short w3d_sound_sample_release(Ptr32<W3dSoundSample> sample)
{
    unsigned short remaining = --sample->counts.references;
    if (remaining == 0) {
        w3d_sound_sample_unlink(sample);
        if (sample)
            w3d_sound_sample_destroy_801e1d68(sample, 3);
    }
    return remaining;
}

unsigned short w3d_sound_sample_retain(Ptr32<W3dSoundSample> sample)
{
    return sample->counts.references++;
}

int w3d_sound_sample_cast(Ptr32<void> object, int a, int b)
{
    return w3d_type_cast_8020b460(object, w3d_sound_sample_type_get(), a, (Ptr32<void>)w3d::G(b));
}

Ptr32<W3dSoundSample> w3d_sound_sample_construct_801e1c80(Ptr32<W3dSoundSample> sample)
{
    unsigned int i;

    sample->vtbl = w3d_sound_sample_base_vtable_80416bf8;
    Ptr32<W3dNodeCounts> counts = &sample->counts;
    counts->flags.bytes[3] = 2;
    W3dNodeFlagWord &flags = counts->flags;
    flags.word = flags.bytes[3];
    sample->links.next = 0;
    W3dNodeLinks &links = sample->links;
    links.previous = 0;
    counts->references = 0;
    counts->second = 0;
    sample->vtbl = w3d_sound_sample_vtable_80416de0;
    w3d_string_default(&sample->name);
    w3d_string_default(&sample->path);
    w3d_string_assign(&sample->name, w3d_str_unused_803b05d0);
    w3d_string_assign(&sample->path, w3d_str_notset_803b05d8);
    sample->unknown_4c = 0;
    sample->channels = 0;
    sample->lipsync = 0;
    sample->lipsync_length = 0;
    sample->unknown_54 = 0;
    sample->unknown_50 = 0;
    for (i = 0; i <= 1; i++)
        sample->streams[i] = -1;
    sample->unknown_44 = 0;
    return sample;
}

void w3d_sound_sample_destroy_801e1d68(Ptr32<W3dSoundSample> sample, int flags)
{
    sample->vtbl = w3d_sound_sample_vtable_80416de0;
    if (sample->lipsync != 0) {
        w3d_heap_release(&w3d_lipsync_heap_804b0564, sample->lipsync);
        w3d_heap_compact_80209968(&w3d_lipsync_heap_804b0564);
    }
    w3d_string_base_finish(&sample->path);
    w3d_string_release(&sample->path);
    w3d_string_base_finish(&sample->name);
    w3d_string_release(&sample->name);
    sample->vtbl = w3d_sound_sample_base_vtable_80416bf8;
    w3d_actor_node_destroy(&sample->counts, 0);
    if (flags & 1)
        w3d_actor_member_delete_backend(sample);
}

int w3d_sound_sample_kind(Ptr32<W3dSoundSample> sample)
{
    return 2;
}

int w3d_sound_sample_set_name(Ptr32<W3dSoundSample> sample, Ptr32<const char> name)
{
    w3d_string_assign(&sample->name, name);
    return 0;
}

Ptr32<const char> w3d_sound_sample_get_name(Ptr32<W3dSoundSample> sample)
{
    return sample->name.data;
}

int w3d_sound_sample_set_18(Ptr32<W3dSoundSample> sample, int value)
{
    sample->unknown_18 = value;
    return 0;
}

int w3d_sound_sample_get_18(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_18;
}

int w3d_sound_sample_set_40(Ptr32<W3dSoundSample> sample, int value)
{
    sample->unknown_40 = value;
    return 0;
}

int w3d_sound_sample_get_40(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_40;
}

#if 0 /* skipped 0x801e1e70 and 0x801e20e0: virtual-call argument moves scheduled differently (this pointer moved last in original) */
int w3d_sound_sample_save(W3dSoundSample *sample, W3dArchiveWriter *writer)
{
    writer->vtbl->write_string(writer, &sample->name, 0, 0);
    writer->vtbl->write_string(writer, &sample->path, 0, 0);
    writer->vtbl->write_int(writer, sample->unknown_1c, 0, 0);
    writer->vtbl->write_float(writer, sample->unknown_24, 0, 0);
    writer->vtbl->write_uint(writer, sample->unknown_18, 0, 0);
    writer->vtbl->write_bool(writer, sample->unknown_28, 0, 0);
    writer->vtbl->write_float(writer, sample->unknown_2c, 0, 0);
    writer->vtbl->write_float(writer, sample->unknown_30, 0, 0);
    writer->vtbl->write_float(writer, sample->unknown_38, 0, 0);
    writer->vtbl->write_float(writer, sample->unknown_3c, 0, 0);
    writer->vtbl->write_float(writer, sample->unknown_34, 0, 0);
    writer->vtbl->write_int(writer, sample->channels, 0, 0);
    writer->vtbl->write_int(writer, sample->unknown_4c, 0, 0);
    writer->vtbl->write_int(writer, sample->unknown_44, 0, 0);
    writer->vtbl->write_uint(writer, sample->lipsync_length, 0, 0);
    writer->vtbl->write_bytes(writer, sample->lipsync, sample->lipsync_length, 0);
    writer->vtbl->write_int(writer, sample->unknown_50, 0, 0);
    writer->vtbl->write_int(writer, sample->unknown_54, 0, 0);
    return 0;
}

int w3d_sound_sample_load(W3dSoundSample *sample, W3dArchiveReader *reader)
{
    int value;

    reader->vtbl->read_string(reader, &sample->name, 0);
    reader->vtbl->read_string(reader, &sample->path, 0);
    reader->vtbl->read_int(reader, &sample->unknown_1c, 0);
    reader->vtbl->read_float(reader, &sample->unknown_24, 0);
    reader->vtbl->read_uint(reader, (unsigned int *)&sample->unknown_18, 0);
    reader->vtbl->read_bool(reader, &sample->unknown_28, 0);
    reader->vtbl->read_float(reader, &sample->unknown_2c, 0);
    reader->vtbl->read_float(reader, &sample->unknown_30, 0);
    reader->vtbl->read_float(reader, &sample->unknown_38, 0);
    reader->vtbl->read_float(reader, &sample->unknown_3c, 0);
    reader->vtbl->read_float(reader, &sample->unknown_34, 0);
    reader->vtbl->read_int(reader, &sample->channels, 0);
    reader->vtbl->read_int(reader, &sample->unknown_4c, 0);
    reader->vtbl->read_int(reader, &value, 0);
    sample->unknown_44 = value;
    reader->vtbl->read_uint(reader, &sample->lipsync_length, 0);
    if (sample->lipsync != 0) {
        w3d_heap_release(&w3d_lipsync_heap_804b0564, sample->lipsync);
        w3d_heap_compact_80209968(&w3d_lipsync_heap_804b0564);
    }
    sample->lipsync = (unsigned char *)w3d_heap_allocate(&w3d_lipsync_heap_804b0564, sample->lipsync_length);
    reader->vtbl->read_bytes(reader, sample->lipsync, sample->lipsync_length, 0);
    reader->vtbl->read_int(reader, &sample->unknown_50, 0);
    reader->vtbl->read_int(reader, &sample->unknown_54, 0);
    return 0;
}
#endif

int w3d_sound_sample_set_path(Ptr32<W3dSoundSample> sample, Ptr32<const char> path)
{
    w3d_string_assign(&sample->path, path);
    return 0;
}

int w3d_sound_sample_set_1c(Ptr32<W3dSoundSample> sample, int value)
{
    sample->unknown_1c = value;
    return 0;
}

int w3d_sound_sample_set_24(Ptr32<W3dSoundSample> sample, float value)
{
    sample->unknown_24 = value;
    return 0;
}

int w3d_sound_sample_set_28(Ptr32<W3dSoundSample> sample, int value)
{
    sample->unknown_28 = value;
    return 0;
}

int w3d_sound_sample_set_2c_pair(Ptr32<W3dSoundSample> sample, float first, float second)
{
    sample->unknown_2c = first;
    sample->unknown_30 = second;
    return 0;
}

int w3d_sound_sample_set_38_pair(Ptr32<W3dSoundSample> sample, float first, float second)
{
    sample->unknown_38 = first;
    sample->unknown_3c = second;
    return 0;
}

int w3d_sound_sample_set_34(Ptr32<W3dSoundSample> sample, float value)
{
    sample->unknown_34 = value;
    return 0;
}

#if 0 /* skipped 0x801e23c0: register allocation and store scheduling differ */
int w3d_sound_sample_init_from_desc(W3dSoundSample *sample, W3dSoundSampleDesc *desc)
{
    EngineString file;
    int *stream;

    if (desc == 0)
        return (int)0x80004005;
    w3d_string_assign(&sample->name, desc->name);
    w3d_string_assign(&sample->path, desc->path);
    sample->unknown_28 = desc->unknown_1c;
    sample->unknown_2c = desc->unknown_20;
    sample->unknown_30 = desc->unknown_24;
    sample->unknown_3c = desc->unknown_2c;
    sample->unknown_38 = desc->unknown_30;
    sample->unknown_34 = desc->unknown_28;
    sample->unknown_1c = desc->unknown_14;
    sample->unknown_18 = desc->unknown_18;
    sample->unknown_24 = desc->unknown_10;
    sample->channels = 0;
    sample->unknown_44 = desc->unknown_3c;
    w3d_string_default(&file);
    w3d_string_assign_prefix_8020c048(&file, &sample->path, ((unsigned short *)sample->path.data)[-2] - 4);
    w3d_string_append(&file, w3d_str_left_dsp_803b05e0);
    for (stream = &sample->streams[0]; stream <= &sample->streams[1]; stream++)
        *stream = -1;
    sample->streams[0] = w3d_stream_open_802f4ef0(file.data);
    if (sample->streams[0] != -1) {
        sample->channels = 1;
        w3d_string_assign_prefix_8020c048(&file, &sample->path, ((unsigned short *)sample->path.data)[-2] - 4);
        w3d_string_append(&file, w3d_str_right_dsp_803b05e8);
        sample->streams[1] = w3d_stream_open_802f4ef0(file.data);
        if (sample->streams[1] != -1)
            sample->channels = 2;
    } else {
        sample->streams[0] = w3d_stream_open_802f4ef0(sample->path.data);
        if (sample->streams[0] != -1)
            sample->channels = 1;
    }
    w3d_string_base_finish(&file);
    w3d_string_release(&file);
    return 0;
}
#endif

float w3d_sound_sample_lipsync_level(Ptr32<W3dSoundSample> sample, unsigned int time)
{
    unsigned int frame = time * 60 / 1000;
    int level;

    if (sample->lipsync == 0 || frame >= sample->lipsync_length)
        return w3d_f32_803b05f0[0];
    level = sample->lipsync[frame];
    return (float)level / w3d_f32_803b0600[0];
}

void w3d_sound_sample_set_44(Ptr32<W3dSoundSample> sample, int value)
{
    sample->unknown_44 = value;
}

int w3d_sound_sample_get_44(Ptr32<W3dSoundSample> sample)
{
    return sample->unknown_44;
}

}


