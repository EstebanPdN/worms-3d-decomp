// GWMP8P rev0 0x802e1b8c. Movie audio mix callback, the same algorithm as
// the SDK's THP player MixAudio: while playing, adds the movie's stereo
// samples scaled by the volume table to the source with saturation, updating
// the volume per sample and moving to the next of four buffers when one
// empties; otherwise copies the source through. memcpy is declared
// unprototyped because the original clears the floating-argument bit before
// the call.
struct Buffer {
    int u0;
    short *cur;
    unsigned valid;
};
struct Player {
    char u0[160];
    int open;
    char u164[4];
    int playing;
    int hasAudio;
    char u176[32];
    float volume;
    char u212[148];
    Buffer buffers[4];
    int u408;
    int index;
};
struct Mixer {
    int u0;
    Player *player;
};
extern const unsigned short volume_804040ec[];
extern "C" void fn_802e220c(Mixer *);
extern "C" void *memcpy(...);
extern "C" void d28l_movie_mix_audio_802e1b8c(Mixer *self, short *dst, short *src, unsigned sample) {
    Player *p = self->player;
    if (p->open && p->playing && p->hasAudio) {
        Buffer *b = &p->buffers[p->index];
        short *d = dst;
        short *s = src;
        int mix;
        for (;;) {
            if (b->valid) {
            unsigned n; if (b->valid < sample) n = b->valid; else n = sample;
            unsigned left = sample - n;
            short *cur = b->cur;
            for (unsigned i = 0; i < n; i++) {
                unsigned short *low = (unsigned short *)&mix;
                fn_802e220c(self);
                unsigned short gain = volume_804040ec[(int)self->player->volume];
                mix = *s + ((gain * *cur) >> 15);
                if (mix < -32768) mix = -32768;
                if (mix > 32767) mix = 32767;
                *d = low[1];
                d++;
                cur++;
                s++;
                mix = *s + ((gain * *cur) >> 15);
                if (mix < -32768) mix = -32768;
                if (mix > 32767) mix = 32767;
                *d = low[1];
                s++;
                cur++;
                d++;
            }
            sample = left;
            b->cur = cur;
            b->valid -= n;
            if (!b->valid) {
                self->player->index++;
                if (self->player->index > 3) {
                    self->player->index = 0;
                }
                b = &self->player->buffers[self->player->index];
            }
            if (!left) return;
            } else {
                memcpy(d, s, sample << 2);
                return;
            }
        }
    } else {
        memcpy(dst, src, sample << 2);
    }
}
