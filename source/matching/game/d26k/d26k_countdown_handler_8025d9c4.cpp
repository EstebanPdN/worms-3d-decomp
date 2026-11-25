// Countdown message handler (Worms 3D GameCube PAL, 0x8025d9c4).
// 
// Message 64 forwards to the base handler and starts the cues (0x8025ddb8),
// returning 0 or 0x80004005; message 66 stops them (0x8025deec). Other messages
// test eight cached ids: four trigger a countdown (start at 23, or restart from
// its period, which shrinks by one down to 8) and four clear its active word.
// All other ids go to the base handler. Same 12-byte countdown as 0x8025dbd0.

struct Message { unsigned short id; };
struct Countdown {
    int active;
    unsigned left;
    unsigned period;
    void trigger() {
        if (active) {
            unsigned next = period;
            left = next;
            if (next <= 7) period = 8;
            else period = next - 1;
        } else {
            active = 1;
            period = left = 23;
        }
    }
};
struct Cue { char pad0[64]; Countdown a; Countdown b; Countdown c; Countdown d; };
extern "C" int base_8016293c(Cue *, Message *);
extern "C" void started_8025ddb8(Cue *);
extern "C" void stopped_8025deec(Cue *);
extern "C" int same_8015f65c(unsigned short, void *);
extern char cache_804b0918, cache_804b0920, cache_804b0928, cache_804b0930, cache_804b0938, cache_804b0940, cache_804b0948, cache_804b0950;
extern "C" int w3d_d26k_countdown_handler_8025d9c4(Cue *self, Message *m) {
    switch (m->id) {
    case 64:
        if (base_8016293c(self, m) >= 0) { started_8025ddb8(self); return 0; }
        return 0x80004005;
    case 66:
        stopped_8025deec(self);
        break;
    default:
        if (same_8015f65c(m->id, &cache_804b0918)) self->c.trigger();
        else if (same_8015f65c(m->id, &cache_804b0920)) self->d.trigger();
        else if (same_8015f65c(m->id, &cache_804b0928)) self->a.trigger();
        else if (same_8015f65c(m->id, &cache_804b0930)) self->b.trigger();
        else if (same_8015f65c(m->id, &cache_804b0938)) self->c.active = 0;
        else if (same_8015f65c(m->id, &cache_804b0940)) self->d.active = 0;
        else if (same_8015f65c(m->id, &cache_804b0948)) self->a.active = 0;
        else if (same_8015f65c(m->id, &cache_804b0950)) self->b.active = 0;
    }
    return base_8016293c(self, m);
}
