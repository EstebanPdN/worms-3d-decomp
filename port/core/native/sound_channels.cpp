// 0x801e3010: actualiza las voces de un emisor. Hay seis canales físicos y una lista de sonidos que quieren sonar: los que ya tienen
// canal siguen, los que no pueden pasan a un canal libre, y lo demás se apaga.
#include "native_common.h"

namespace {
struct VoiceList {
    char storage[0x84];
    w3d_u32 capacity;   // +0x84
};
struct Channel { Ptr32<void> sound; };
struct SoundEmitter {
    char pad[0x18];
    Ptr32<Ptr32<void>> sounds;      // +0x18
    Ptr32<Ptr32<void>> sounds_end;  // +0x1c
    char pad2[0x2c - 0x20];
    Ptr32<Channel> channels[6];     // +0x2c
    w3d_u32 volume;                 // +0x44
};
const int kChannels = 6;
}
extern "C" {
void A801e15c8(VoiceList *);
void A801e15f4(VoiceList *, w3d_u32);
void A801e16b0(VoiceList *, void *);
void A801e183c(VoiceList *, w3d_u32);
w3d_u32 A801e1944(VoiceList *);
w3d_u32 A801e194c(VoiceList *, w3d_u32);
void A801e3888(void *, w3d_u32);
w3d_u32 A801e38a4(void *, void *);
w3d_u32 A801e5fd4(void *);
void A801e5dfc(void *);
void A801e5b80(void *, void *);
void A801e6054(void *, w3d_u32, void *);

w3d_u32 A801e3010(Ptr32<SoundEmitter> self, w3d_u32 elapsed) {
    VoiceList wanted;
    A801e15c8(&wanted);
    wanted.capacity = kChannels;
    for (int i = 0; i < kChannels; i++)
        if (self->channels[i]) A801e6054(self->channels[i].get(), elapsed, arg(self->volume));

    for (w3d_u32 i = 0; i < ((self->sounds_end.v - self->sounds.v) >> 2); i++) {
        void *sound = self->sounds[i].get();
        A801e3888(sound, elapsed);
        if (call_virtual(self->sounds[i].get(), 0x24) != 0 && A801e38a4(self->sounds[i].get(), arg(self->volume)) == 0) A801e16b0(&wanted, self->sounds[i].get());
    }
    for (int i = 0; i < kChannels; i++) {
        Channel *channel = self->channels[i];
        if (!A801e5fd4(channel)) continue;
        bool still_wanted = false;
        for (w3d_u32 j = 0; j < A801e1944(&wanted); j++) {
            if (!A801e194c(&wanted, j)) continue;
            const w3d_u32 playing = channel->sound.v;
            if (playing == call_virtual(g2h(A801e194c(&wanted, j)), 0x48)) {
                A801e183c(&wanted, j);
                still_wanted = true;
                break;
            }
        }
        if (!still_wanted) A801e5dfc(channel);
    }
    for (int i = 0; i < kChannels; i++) {
        Channel *channel = self->channels[i];
        if (channel && !A801e5fd4(channel) && A801e1944(&wanted) != 0) {
            A801e5b80(channel, g2h(A801e194c(&wanted, 0)));
            A801e6054(channel, 0, arg(self->volume));
            A801e183c(&wanted, 0);
        }
    }
    A801e15f4(&wanted, 2);
    return 0;
}
}
