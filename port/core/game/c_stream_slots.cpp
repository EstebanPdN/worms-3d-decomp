#include "w3d_ptr.h"
#line 1 "c_stream_slots.cpp"
/* Streamed-audio slot table (0x801e3d44..0x801e47e8).
 *
 * Names are inferred from behavior; no original symbols survive. A static
 * table at 0x8045d930 holds five 128-byte stream slots followed by the next
 * stream id (+0x280), a lock handle (+0x284) and a lock depth (+0x288).
 * Observed slot layout:
 *   +0x00 state (0 free, 1 opened, 2 streaming), +0x04 stream id,
 *   +0x08 right-channel slot, +0x0c parent (left) slot, +0x10 description,
 *   +0x14/+0x15 mix bytes, +0x18 disc file info, +0x54 hardware voice,
 *   +0x58 chunk size, +0x5c data size, +0x60 buffer, +0x64/+0x68 sizes,
 *   +0x6c flag byte, +0x70 word, +0x74 started flag, +0x78 read-pending flag,
 *   +0x7c close-requested flag.
 * Description: +0x00 path, +0x04 u16 volume, +0x08 offset, +0x0c length.
 */
extern "C" {

typedef struct W3dStreamDesc {
    Ptr32<const char> path;
    unsigned short volume;
    unsigned char unknown_06[2];
    int offset;
    unsigned int length;
    unsigned char voice_setup[4];
} W3dStreamDesc;

typedef struct W3dStreamSlot W3dStreamSlot;
struct W3dStreamSlot {
    unsigned char state;
    unsigned char unknown_01[3];
    int id;
    Ptr32<W3dStreamSlot> right;
    Ptr32<W3dStreamSlot> parent;
    Ptr32<W3dStreamDesc> desc;
    unsigned char mix_a;
    unsigned char mix_b;
    unsigned char unknown_16[2];
    unsigned char file[0x54 - 0x18];
    int voice;
    int chunk_size;
    unsigned int data_size;
    Ptr32<unsigned char> buffer;
    unsigned int buffer_size;
    unsigned int stream_size;
    unsigned char flag_6c;
    unsigned char unknown_6d[3];
    int unknown_70;
    int started;
    int read_pending;
    int close_requested;
};

typedef struct W3dStreamTable {
    W3dStreamSlot slots[5];
    int next_id;
    int lock_handle;
    int lock_depth;
} W3dStreamTable;

typedef struct W3dStreamSystem W3dStreamSystem;

extern W3dStreamTable w3d_stream_table_8045d930;
extern Ptr32<W3dStreamSystem> w3d_stream_system_804ab85c;
extern const char w3d_str_803b0698[];
extern const char w3d_str_803b06c0[];

Ptr32<void> w3d_aligned_allocate(unsigned int size, unsigned int alignment);
void w3d_aligned_release(Ptr32<void> block);
void w3d_actor_member_delete_backend(Ptr32<void> block);
Ptr32<void> memset(Ptr32<void> dest, int value, unsigned int size);
int w3d_lock_create_802fdb6c(void);
int w3d_lock_destroy_802fdb94(int handle);
int w3d_disc_open_802f51e4(int path, Ptr32<void> file);
int w3d_disc_read_async_802f5568(Ptr32<void> file, Ptr32<void> buffer, int length, int offset, Ptr32<void (int, Ptr32<void>)> callback, int priority);
int w3d_disc_close_802f5320(Ptr32<void> file);
int w3d_disc_cancel_802f7a68(Ptr32<void> file);
void w3d_report_802fb7ac(Ptr32<const char> format, ...);
int w3d_voice_create_80323d88(int a, Ptr32<void> buffer, int b, int c, int d, int e, int f, int g,
                              int h, int i, int j,
                              Ptr32<unsigned int (int, unsigned int, int, unsigned int, Ptr32<W3dStreamSlot>)> callback,
                              Ptr32<void> user, int k);
void w3d_voice_free_803254e4(int voice);
void w3d_voice_start_80324920(int voice, int a, int b, int c, int d, int e);
void w3d_voice_set_volume_80324e7c(int voice, int volume);
void w3d_voice_stop_80326210(int voice);
unsigned int w3d_stream_voice_callback_801e4928(int unused0, unsigned int position, int unused2,
                                                unsigned int length, Ptr32<W3dStreamSlot> slot);
void w3d_stream_read_done_801e4a4c(int result, Ptr32<void> file);
void w3d_voice_set_loop_803238fc(int voice, unsigned int start, unsigned int end, int a, int b);
void w3d_voice_setup_80324224(int voice, Ptr32<void> setup);
unsigned char w3d_voice_prepare_80325bb8(int voice);
int w3d_disc_busy_802f7694(void);
void w3d_stream_slot_finish(Ptr32<W3dStreamSlot> slot);
void w3d_stream_slot_refill_801e47e8(Ptr32<W3dStreamSlot> slot);
int w3d_stream_slot_begin_801e4994(Ptr32<W3dStreamSlot> slot);
unsigned int w3d_stream_slot_start_801e4074(Ptr32<W3dStreamSlot> slot, Ptr32<W3dStreamDesc> desc, int mix_a, int mix_b);

int w3d_stream_slot_open(Ptr32<Ptr32<W3dStreamSlot>> out)
{
    int index;

    for (index = 0; index < 5; index++) {
        if (w3d_stream_table_8045d930.slots[index].state == 0) {
            int id;
            unsigned int i;

            do {
                id = w3d_stream_table_8045d930.next_id++;
                if (id == -1)
                    id = w3d_stream_table_8045d930.next_id++;
                for (i = 0; i <= 4; i++) {
                    if (w3d_stream_table_8045d930.slots[i].state != 0 && w3d_stream_table_8045d930.slots[i].id == id)
                        break;
                }
            } while (i != 5);
            w3d_stream_table_8045d930.slots[index].state = 1;
            w3d_stream_table_8045d930.slots[index].id = id;
            w3d_stream_table_8045d930.slots[index].right = 0;
            w3d_stream_table_8045d930.slots[index].parent = 0;
            *out = &w3d_stream_table_8045d930.slots[index];
            return id;
        }
    }
    return -1;
}

int w3d_stream_slot_find(int id)
{
    Ptr32<W3dStreamSlot> slot = w3d_stream_table_8045d930.slots;
    int i;

    for (i = 0; i < 5; slot++, i++) {
        if (slot->state != 0 && id == slot->id)
            return i;
    }
    return -1;
}

void w3d_stream_unlock(void)
{
    if (w3d_stream_table_8045d930.lock_depth != 0) {
        if (--w3d_stream_table_8045d930.lock_depth == 0)
            w3d_lock_destroy_802fdb94(w3d_stream_table_8045d930.lock_handle);
    }
}

void w3d_stream_lock(void)
{
    if (++w3d_stream_table_8045d930.lock_depth == 1)
        w3d_stream_table_8045d930.lock_handle = w3d_lock_create_802fdb6c();
}

Ptr32<W3dStreamSystem> w3d_stream_member_construct_801e3f00(Ptr32<W3dStreamSystem> system)
{
    w3d_stream_system_804ab85c = system;
    return system;
}

void w3d_stream_member_destroy_801e3f0c(Ptr32<W3dStreamSystem> system, int flags)
{
    w3d_stream_system_804ab85c = 0;
    if (flags & 1)
        w3d_actor_member_delete_backend(system);
}

void w3d_stream_member_open_801e3f3c(Ptr32<W3dStreamSystem> system)
{
    unsigned int i;

    for (i = 0; i <= 4; i++) {
        w3d_stream_table_8045d930.slots[i].state = 0;
        w3d_stream_table_8045d930.slots[i].buffer = (Ptr32<unsigned char>)w3d_aligned_allocate(54912, 32);
        w3d_stream_table_8045d930.slots[i].buffer_size = 54912;
        w3d_stream_table_8045d930.slots[i].stream_size = 96096;
        w3d_stream_table_8045d930.slots[i].voice = w3d_voice_create_80323d88(255, w3d_stream_table_8045d930.slots[i].buffer,
            96096, 32000, 0, 64, 0, 0, 0, 0, 0x30001, w3d_stream_voice_callback_801e4928, &w3d_stream_table_8045d930.slots[i], 0);
    }
    w3d_stream_table_8045d930.next_id = 0;
    w3d_stream_table_8045d930.lock_depth = 0;
}

void w3d_stream_member_close_801e4020(Ptr32<W3dStreamSystem> system)
{
    unsigned int i;

    for (i = 0; i <= 4; i++) {
        w3d_voice_free_803254e4(w3d_stream_table_8045d930.slots[i].voice);
        w3d_aligned_release(w3d_stream_table_8045d930.slots[i].buffer);
    }
}

#if 0 /* skipped 0x801e4074: store scheduling and constant register sharing differ */
unsigned int w3d_stream_slot_start(W3dStreamSlot *slot, W3dStreamDesc *desc, int mix_a, int mix_b)
{
    unsigned int length;
    unsigned int size;

    slot->mix_a = mix_a;
    slot->mix_b = mix_b;
    slot->flag_6c = 1;
    slot->buffer_size = 54912;
    slot->stream_size = 96096;
    slot->chunk_size = 27456;
    slot->desc = desc;
    slot->unknown_70 = 1;
    slot->started = 0;
    slot->read_pending = 1;
    slot->close_requested = 0;
    size = desc->length;
    slot->data_size = size;
    if (size >= 27456) {
        length = 27456;
    } else {
        length = size;
        memset(slot->buffer + length, 0, 27456 - length);
    }
    slot->state = 2;
    return length;
}
#endif

int w3d_stream_open_mono(Ptr32<W3dStreamSystem> system, Ptr32<W3dStreamDesc> desc, int mix_a, int mix_b)
{
    Ptr32<W3dStreamSlot> slot;
    int id;
    unsigned int length;

    w3d_stream_lock();
    id = w3d_stream_slot_open(&slot);
    if (id != -1) {
        length = w3d_stream_slot_start_801e4074(slot, desc, mix_a, mix_b);
        w3d_stream_unlock();
        w3d_disc_open_802f51e4((int)w3d::H(slot->desc->path), slot->file);
        w3d_disc_read_async_802f5568(slot->file, slot->buffer, length, slot->desc->offset, w3d_stream_read_done_801e4a4c, 2);
        return id;
    }
    w3d_stream_unlock();
    return -1;
}

#if 0 /* skipped 0x801e41d0: register allocation of the two id variables differs */
static inline int w3d_stream_disc_open(W3dStreamSlot *slot)
{
    return w3d_disc_open_802f51e4((int)slot->desc->path, slot->file) ? 1 : 0;
}

int w3d_stream_open_stereo(W3dStreamSystem *system, W3dStreamDesc *left, W3dStreamDesc *right, int mix_a)
{
    W3dStreamSlot *slots[2];
    int id;
    int result;
    unsigned int left_length;

    w3d_stream_lock();
    id = w3d_stream_slot_open(&slots[0]);
    result = id;
    if (result != -1) {
        left_length = w3d_stream_slot_open(&slots[1]);
        if (left_length != (unsigned int)-1) {
            unsigned int right_length;

            slots[0]->right = slots[1];
            slots[1]->parent = slots[0];
            left_length = w3d_stream_slot_start(slots[0], left, mix_a, 0);
            right_length = w3d_stream_slot_start(slots[1], right, mix_a, 127);
            w3d_stream_unlock();
            if (w3d_stream_disc_open(slots[0]) == 0)
                w3d_report_802fb7ac(w3d_str_803b0698);
            w3d_disc_read_async_802f5568(slots[0]->file, slots[0]->buffer, left_length, slots[0]->desc->offset,
                                         w3d_stream_read_done_801e4a4c, 2);
            if (w3d_stream_disc_open(slots[1]) == 0)
                w3d_report_802fb7ac(w3d_str_803b06c0);
            w3d_disc_read_async_802f5568(slots[1]->file, slots[1]->buffer, right_length, slots[1]->desc->offset,
                                         w3d_stream_read_done_801e4a4c, 2);
            return id;
        }
        slots[0]->state = 0;
        result = -1;
    }
    w3d_stream_unlock();
    return result;
}
#endif

void w3d_stream_slot_play(Ptr32<W3dStreamSlot> slot)
{
    if (slot->state != 0 && slot->started == 0) {
        w3d_voice_start_80324920(slot->voice, 0, slot->mix_b, 0, 0, 0);
        slot->started = 1;
    }
}

void w3d_stream_play(Ptr32<W3dStreamSystem> system, int id)
{
    int index;

    w3d_stream_lock();
    index = w3d_stream_slot_find(id);
    if (index != -1) {
        w3d_stream_slot_play(&w3d_stream_table_8045d930.slots[index]);
        if (w3d_stream_table_8045d930.slots[index].right != 0)
            w3d_stream_slot_play(w3d_stream_table_8045d930.slots[index].right);
        if (w3d_stream_table_8045d930.slots[index].parent != 0)
            w3d_stream_slot_play(w3d_stream_table_8045d930.slots[index].parent);
    }
    w3d_stream_unlock();
}

int w3d_stream_is_open(Ptr32<W3dStreamSystem> system, int id)
{
    int index;
    int result = 0;

    w3d_stream_lock();
    index = w3d_stream_slot_find(id);
    if (index != -1)
        result = w3d_stream_table_8045d930.slots[index].state != 0;
    w3d_stream_unlock();
    return result;
}

int w3d_stream_mute(Ptr32<W3dStreamSystem> system, int id)
{
    int index;

    w3d_stream_lock();
    index = w3d_stream_slot_find(id);
    if (index != -1) {
        Ptr32<W3dStreamSlot> slot = &w3d_stream_table_8045d930.slots[index];

        w3d_voice_set_volume_80324e7c(slot->voice, 0);
        if (slot->right != 0)
            w3d_voice_set_volume_80324e7c(slot->right->voice, 0);
        if (slot->parent != 0)
            w3d_voice_set_volume_80324e7c(slot->parent->voice, 0);
        w3d_stream_unlock();
        return 1;
    }
    w3d_stream_unlock();
    return 0;
}

int w3d_stream_unmute(Ptr32<W3dStreamSystem> system, int id)
{
    int index;

    w3d_stream_lock();
    index = w3d_stream_slot_find(id);
    if (index != -1) {
        Ptr32<W3dStreamSlot> slot = &w3d_stream_table_8045d930.slots[index];

        w3d_voice_set_volume_80324e7c(slot->voice, slot->desc->volume);
        if (slot->right != 0)
            w3d_voice_set_volume_80324e7c(slot->right->voice, slot->desc->volume);
        if (slot->parent != 0)
            w3d_voice_set_volume_80324e7c(slot->parent->voice, slot->desc->volume);
        w3d_stream_unlock();
        return 1;
    }
    w3d_stream_unlock();
    return 0;
}

static inline void w3d_stream_slot_close(Ptr32<W3dStreamSlot> slot)
{
    w3d_voice_stop_80326210(slot->voice);
    if (slot->read_pending == 0) {
        w3d_disc_close_802f5320(slot->file);
        slot->state = 0;
    } else {
        w3d_disc_cancel_802f7a68(slot->file);
        slot->state = 0;
    }
}

void w3d_stream_close(Ptr32<W3dStreamSystem> system, int id)
{
    int index;

    w3d_stream_lock();
    index = w3d_stream_slot_find(id);
    if (index != -1) {
        Ptr32<W3dStreamSlot> slot = &w3d_stream_table_8045d930.slots[index];

        w3d_stream_slot_close(slot);
        if (slot->right != 0)
            w3d_stream_slot_close(slot->right);
        if (slot->parent != 0)
            w3d_stream_slot_close(slot->parent);
    }
    w3d_stream_unlock();
}

void w3d_stream_set_mix(Ptr32<W3dStreamSystem> system, int id, int a, int b, int c)
{
    int index;

    w3d_stream_lock();
    index = w3d_stream_slot_find(id);
    if (index != -1) {
        Ptr32<W3dStreamSlot> slot = &w3d_stream_table_8045d930.slots[index];

        if (slot->right != 0)
            w3d_voice_start_80324920(slot->right->voice, a, b, c, 0, 0);
        w3d_voice_start_80324920(slot->voice, a, b, c, 0, 0);
    }
    w3d_stream_unlock();
}

void w3d_stream_slot_finish(Ptr32<W3dStreamSlot> slot)
{
    w3d_voice_stop_80326210(slot->voice);
    if (slot->read_pending == 0) {
        w3d_disc_close_802f5320(slot->file);
        slot->state = 0;
    } else {
        slot->close_requested = 1;
    }
}


#if 0 /* skipped 0x801e47e8: copy of the half-buffer size is kept in r5 in the original */
void w3d_stream_slot_refill_801e47e8(W3dStreamSlot *slot)
{
    unsigned int half = slot->buffer_size >> 1;
    unsigned int count = half;
    unsigned char *dest;

    if (slot->flag_6c != 0)
        dest = slot->buffer + half;
    else
        dest = slot->buffer;
    if (slot->chunk_size + count > slot->data_size) {
        if (slot->data_size > slot->chunk_size) {
            half = slot->data_size - slot->chunk_size;
            memset(dest + half, 0, count - half);
        } else {
            memset(dest, 0, count);
            w3d_voice_set_loop_803238fc(slot->voice, slot->flag_6c != 0 ? slot->stream_size >> 1 : 0,
                                        slot->stream_size >> 1, 0, 0);
            half = 0;
        }
    }
    if (half != 0) {
        w3d_disc_read_async_802f5568(slot->file, dest, half, slot->desc->offset + slot->chunk_size,
                                     w3d_stream_read_done_801e4a4c, 2);
        slot->read_pending = 1;
        slot->chunk_size += half;
    } else if (slot->unknown_70 != 0) {
        slot->unknown_70 = half;
    } else {
        w3d_stream_slot_finish(slot);
    }
    slot->flag_6c ^= 1;
}
#endif

unsigned int w3d_stream_voice_callback_801e4928(int unused0, unsigned int position, int unused2,
                                                unsigned int length, Ptr32<W3dStreamSlot> slot)
{
    if (slot->started != 0) {
        w3d_stream_slot_finish(slot);
        return 0;
    }
    if (position + length < slot->stream_size >> 1)
        return 0;
    w3d_stream_slot_refill_801e47e8(slot);
    return slot->stream_size >> 1;
}

#if 0 /* skipped 0x801e4994: result register (r3 vs r0) and store order differ */
int w3d_stream_slot_begin_801e4994(W3dStreamSlot *slot)
{
    w3d_voice_start_80324920(slot->voice, slot->mix_a, slot->mix_b, 0, 0, 0);
    w3d_voice_set_volume_80324e7c(slot->voice, slot->desc->volume);
    w3d_voice_setup_80324224(slot->voice, slot->desc->voice_setup);
    w3d_voice_set_loop_803238fc(slot->voice, 0, slot->stream_size >> 1, 0, 0);
    unsigned char ready = w3d_voice_prepare_80325bb8(slot->voice);
    if (ready != 0) {
        slot->state = 4;
        w3d_stream_slot_refill_801e47e8(slot);
        return 1;
    }
    slot->state = ready;
    w3d_disc_close_802f5320(slot->file);
    return 0;
}
#endif

#if 0 /* skipped 0x801e4a4c: register allocation and store addressing differ */
void w3d_stream_read_done_801e4a4c(int result, void *file)
{
    unsigned int i;
    W3dStreamSlot *slot;
    int close;

    for (i = 0; i <= 4; i++) {
        if (w3d_stream_table_8045d930.slots[i].file == file)
            break;
    }
    slot = &w3d_stream_table_8045d930.slots[i];
    slot->read_pending = 0;
    close = slot->close_requested;
    if (close != 0) {
        slot->close_requested = 0;
        w3d_disc_close_802f5320(slot->file);
        w3d_stream_table_8045d930.slots[i].state = 0;
        return;
    }
    if (w3d_disc_busy_802f7694() == 0) {
        switch (w3d_stream_table_8045d930.slots[i].state) {
        case 2:
            if (slot->right != 0) {
                if (slot->right->state != 3) {
                    w3d_stream_table_8045d930.slots[i].state = 3;
                    return;
                }
                if (w3d_stream_slot_begin_801e4994(slot->right) == 0)
                    slot->right = 0;
            }
            if (slot->parent != 0) {
                if (slot->parent->state != 3) {
                    slot->state = 3;
                    return;
                }
                if (w3d_stream_slot_begin_801e4994(slot->parent) == 0)
                    slot->parent = 0;
            }
            if (w3d_stream_slot_begin_801e4994(slot) == 0) {
                if (slot->right != 0)
                    slot->right->parent = 0;
                if (slot->parent != 0)
                    slot->parent->right = 0;
            }
            break;
        case 4:
            w3d_voice_set_loop_803238fc(slot->voice, slot->flag_6c == 0 ? slot->stream_size >> 1 : 0,
                                        slot->stream_size >> 1, 0, 0);
            break;
        }
    } else {
        if (w3d_stream_table_8045d930.slots[i].state == 4)
            w3d_voice_stop_80326210(slot->voice);
        w3d_disc_close_802f5320(slot->file);
        w3d_stream_table_8045d930.slots[i].state = 0;
        if (slot->right != 0)
            slot->right->parent = 0;
        if (slot->parent != 0)
            slot->parent->right = 0;
    }
}
#endif

}


