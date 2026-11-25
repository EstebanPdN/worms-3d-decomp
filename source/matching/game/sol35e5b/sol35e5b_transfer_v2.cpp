#include <stddef.h>
// Inferred audio DMA callback state; offsets and dataflow observed in originals.
// The first sixteen bytes belong to the containing object and are not accessed here.
struct Sol35e5bAudioState {
    unsigned char unknown_prefix[16];
    void* buffers[2];
    unsigned int selected;
    void (*callback)();
    void* current;
    void* previous;
    int mode;
};
typedef char Sol35e5bAudioOffsets[
    offsetof(Sol35e5bAudioState, buffers) == 16 &&
    offsetof(Sol35e5bAudioState, callback) == 28 &&
    offsetof(Sol35e5bAudioState, mode) == 40 ? 1 : -1];
extern "C" Sol35e5bAudioState* sol35e5b_state_804b190c;
extern "C" void sol35e5b_dma_init_80311254(void*, unsigned int);
extern "C" unsigned int sol35e5b_dma_address_8031130c();
extern "C" int sol35e5b_enable_802fdb80();
extern "C" int sol35e5b_restore_802fdb94(int);
extern "C" void sol35e5b_invalidate_802fa95c(void*, unsigned int);
extern "C" void sol35e5b_flush_802fa988(void*, unsigned int);
extern "C" void sol35e5b_mix_802e1f54(Sol35e5bAudioState*, void*, void*, unsigned int);

extern "C" void sol35e5b_transfer_802e1f88()
{
    Sol35e5bAudioState* self = sol35e5b_state_804b190c;
    if (self->mode == 0) {
        self->selected ^= 1;
        void** buffers = self->buffers;
        sol35e5b_dma_init_80311254(buffers[self->selected], 640);
        int enabled = sol35e5b_enable_802fdb80();
        sol35e5b_mix_802e1f54(self, buffers[self->selected], 0, 160);
        sol35e5b_flush_802fa988(buffers[self->selected], 640);
        sol35e5b_restore_802fdb94(enabled);
    } else {
        if (self->mode == 1) {
            if (self->current)
                self->previous = self->current;
            self->callback();
            self->current = reinterpret_cast<void*>(sol35e5b_dma_address_8031130c() + 0x80000000u);
        } else {
            self->callback();
            self->previous = reinterpret_cast<void*>(sol35e5b_dma_address_8031130c() + 0x80000000u);
        }
        self->selected ^= 1;
        void** buffers = self->buffers;
        sol35e5b_dma_init_80311254(buffers[self->selected], 640);
        int enabled = sol35e5b_enable_802fdb80();
        if (self->previous)
            sol35e5b_invalidate_802fa95c(self->previous, 640);
        sol35e5b_mix_802e1f54(self, buffers[self->selected], self->previous, 160);
        sol35e5b_flush_802fa988(buffers[self->selected], 640);
        sol35e5b_restore_802fdb94(enabled);
    }
}
