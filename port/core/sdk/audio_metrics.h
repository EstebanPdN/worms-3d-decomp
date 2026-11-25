// Measurements, not synchronization of the mixer. No SD I/O from these paths.
#pragma once
#include <stdint.h>
struct W3dAudioMetrics {
    uint64_t mix_ticks, audio_wait_ticks, audio_hold_ticks;
    uint64_t game_wait_ticks, game_hold_ticks, mix_max_ticks;
    uint32_t buffers, samples, voices, streams, game_locks, dropped;
    uint32_t fixed_blocks, float_blocks;
};
extern "C" void w3d_audio_profile_enable(int enabled);
extern "C" void w3d_audio_metrics_take(W3dAudioMetrics *out);

// One producer (pull) and one consumer (game frame). Release publishes an entire
// record; acquire prevents torn uint64 reads on ARM32. Full means drop telemetry,
// never wait for the game. Sample memory and audio commands are not in this ring.
template<unsigned N> class W3dAudioMetricRing {
    W3dAudioMetrics records[N]{};
    uint32_t write = 0, read = 0, lost = 0;
public:
    bool push(const W3dAudioMetrics &record) {
        const uint32_t w = __atomic_load_n(&write, __ATOMIC_RELAXED);
        if (w - __atomic_load_n(&read, __ATOMIC_ACQUIRE) == N) {
            __atomic_fetch_add(&lost, 1u, __ATOMIC_RELAXED); return false;
        }
        records[w % N] = record;
        __atomic_store_n(&write, w + 1, __ATOMIC_RELEASE); return true;
    }
    bool pop(W3dAudioMetrics &record) {
        const uint32_t r = __atomic_load_n(&read, __ATOMIC_RELAXED);
        if (r == __atomic_load_n(&write, __ATOMIC_ACQUIRE)) return false;
        record = records[r % N];
        __atomic_store_n(&read, r + 1, __ATOMIC_RELEASE); return true;
    }
    uint32_t take_lost() { return __atomic_exchange_n(&lost, 0u, __ATOMIC_RELAXED); }
};
