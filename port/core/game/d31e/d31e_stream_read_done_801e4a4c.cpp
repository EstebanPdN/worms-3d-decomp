#include "w3d_ptr.h"
#line 1 "d31e_stream_read_done_801e4a4c.cpp"
// (Worms 3D GameCube PAL, 0x801e4a4c).
//
// Disc read completion callback for a stream slot, found in the 128-byte
// table 0x8045d930 by its file handle at +24. Clears +120; if the slot was
// closing, closes the file and resets state. If the read failed, stops the
// stream if playing, closes the file, resets state and unlinks the
// neighbours. Otherwise, in state 2 starts linked slots at +8 and +12 once
// ready and then itself, unlinking on success; in state 4 refills the stream
// at offset 0 or half according to +108. Names are inferred.

struct Voice;
struct Slot {
    unsigned char state;
    char u1[7];
    Ptr32<Slot> prev;
    Ptr32<Slot> next;
    char pad16[8];
    char info[60];
    Ptr32<void> stream;
    char pad88[16];
    unsigned size;
    unsigned char half;
    char pad109[11];
    volatile int x120;
    volatile int closing;
};
extern Slot g_slots[];
extern "C" int fn_802f7694(Ptr32<void>);
extern "C" int fn_802f5320(Ptr32<void>);
extern "C" void fn_80326210(Ptr32<void>);
extern "C" void fn_803238fc(Ptr32<void>, unsigned, unsigned, int, int);
extern "C" int w3d_cx14b_sound_voice_start_801e4994(Ptr32<Slot>);
static inline unsigned FindSlot(Ptr32<void> info)
{
    Ptr32<char> p = g_slots[0].info;
    unsigned i = 0;
    while (i <= 4 && p != info) {
        i++;
        p += 128;
    }
    return i;
}
extern "C" void w3d_d31e_stream_read_done_801e4a4c(int result, Ptr32<void> info)
{
    unsigned i = FindSlot(info);
    Ptr32<Slot> e = &g_slots[i];
    e->x120 = 0;
    int closing = e->closing;
    if (closing) {
        e->closing = 0;
        fn_802f5320(e->info);
        e->state = 0;
        return;
    }
    if (fn_802f7694(info) == 0) {
        switch (e->state) {
        case 2: {
            Ptr32<Slot> a = e->prev;
            if (a) {
                if (a->state != 3) { e->state = 3; return; }
                if (w3d_cx14b_sound_voice_start_801e4994(a) == 0) e->prev = 0;
            }
            a = e->next;
            if (a) {
                if (a->state != 3) { e->state = 3; return; }
                if (w3d_cx14b_sound_voice_start_801e4994(a) == 0) e->next = 0;
            }
            if (w3d_cx14b_sound_voice_start_801e4994(e) == 0) {
                if (e->prev) e->prev->next = 0;
                if (e->next) e->next->prev = 0;
            }
            break;
        }
        case 4: {
            unsigned from, len;
            Ptr32<void> s = e->stream;
            if (!e->half) {
                from = e->size >> 1;
                len = e->size;
            } else {
                from = 0;
                len = e->size;
            }
            len >>= 1;
            fn_803238fc(s, from, len, 0, 0);
            break;
        }
        }
    } else {
        if (e->state == 4) fn_80326210(e->stream);
        fn_802f5320(e->info);
        e->state = 0;
        if (e->prev) e->prev->next = 0;
        if (e->next) e->next->prev = 0;
    }
}


