#include "w3d_ptr.h"
#line 1 "d26k_countdown_cues_8025dbd0.cpp"
// Countdown cues (Worms 3D GameCube PAL, 0x8025dbd0).
// 
// Advances the time since +60 in 20-tick steps, at most 100 ticks. Each step ticks
// four countdowns at +64, +76, +88 and +100 (active word, unsigned remaining count,
// one unread word for the 12-byte stride) and posts a cached 8-byte message when a
// running countdown is at or below 4. Stores the unconsumed time back and returns 20.

struct Msg { unsigned short id; unsigned short pad02; Ptr32<const void> type; };
struct Countdown { int active; unsigned left; int pad;
    bool tick() { if (active==0) return false; return --left <= 4; } };
struct Cue { char pad0[60]; int last; Countdown a; Countdown b; Countdown c; Countdown d; };
extern const unsigned char table_8040db38[];
extern Ptr32<void> global_804b1754;
extern char cache_804b0928, cache_804b0930, cache_804b0918, cache_804b0920;
extern "C" Ptr32<void> alloc_801613f0(Ptr32<void>, int);
extern "C" int msgid_8015f5a0(Ptr32<void>, int);
extern "C" int post_8016239c(Ptr32<Msg>);
extern "C" int w3d_d26k_countdown_cues_8025dbd0(Ptr32<Cue> self, int now) {
    int delta = now - self->last;
    if (delta > 100) delta = 100;
    while (delta > 19) {
        if (self->a.tick()) {
            Ptr32<Msg> m = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
            m->id = msgid_8015f5a0(&cache_804b0928, 1);
            m->type = table_8040db38;
            post_8016239c(m);
        }
        if (self->b.tick()) {
            Ptr32<Msg> m = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
            m->id = msgid_8015f5a0(&cache_804b0930, 1);
            m->type = table_8040db38;
            post_8016239c(m);
        }
        if (self->c.tick()) {
            Ptr32<Msg> m = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
            m->id = msgid_8015f5a0(&cache_804b0918, 1);
            m->type = table_8040db38;
            post_8016239c(m);
        }
        if (self->d.tick()) {
            Ptr32<Msg> m = (Ptr32<Msg>)alloc_801613f0(global_804b1754, 8);
            m->id = msgid_8015f5a0(&cache_804b0920, 1);
            m->type = table_8040db38;
            post_8016239c(m);
        }
        delta -= 20;
    }
    self->last = now - delta;
    return 20;
}


