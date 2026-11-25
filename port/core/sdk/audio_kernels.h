// Pure audio kernels. Float remains the reference; fixed point is opt-in.
#pragma once
#include <stdint.h>
#include <string.h>
#if defined(__arm__) && !defined(__thumb__) && defined(__ARM_FEATURE_DSP) && defined(__ARM_FEATURE_SIMD32) && !defined(W3D_AUDIO_PORTABLE)
#include <arm_acle.h>
#define W3D_AUDIO_ARM_DSP 1
#else
#define W3D_AUDIO_ARM_DSP 0
#endif

namespace w3d_audio {
inline int16_t clamp16(int32_t x) { return x < -32768 ? -32768 : x > 32767 ? 32767 : (int16_t)x; }

// The scalar reference intentionally keeps 32-bit wraparound, as sdk_audio's
// -fwrapv build did. No saturation before summing both prediction products.
inline int32_t predict_scalar(int c1, int c2, int h1, int h2, int base) {
    return (int32_t)((uint32_t)base + (uint32_t)(c1 * h1) + (uint32_t)(c2 * h2));
}
struct Adpcm {
    int16_t coef[16];
    int hist1, hist2;
    void decode(const uint8_t *frame, int16_t *out) {
        const int ps = frame[0], scale = 1 << (ps & 15), c = (ps >> 4) & 7;
        const int c1 = coef[c * 2], c2 = coef[c * 2 + 1];
        // Do not read pairs from frame/out: either may be unaligned or alias.
        // Coefficients are immutable during the call. Histories are signed16
        // after every decode; use the scalar path for a malformed initial state.
#if W3D_AUDIO_ARM_DSP
        const uintptr_t src = (uintptr_t)frame, dst = (uintptr_t)out, self = (uintptr_t)this;
        const bool fast = !((src | dst) & 3u) && (dst + 28 <= src || src + 8 <= dst)
            && (src + 8 <= self || self + sizeof(*this) <= src)
            && (dst + 28 <= self || self + sizeof(*this) <= dst)
            && hist1 >= -32768 && hist1 <= 32767 && hist2 >= -32768 && hist2 <= 32767;
        if (fast) {
            uint32_t packed, history;
            memcpy(&packed, coef + c * 2, sizeof packed);
            __asm__("pkhbt %0, %1, %2, lsl #16" : "=r"(history) : "r"(hist1), "r"(hist2));
            const unsigned shift = (ps & 15) + 11;
            for (int i = 0; i < 14; ++i) {
                int nib = (i & 1) ? (int8_t)(frame[1 + i / 2] << 4) >> 4 : (int8_t)frame[1 + i / 2] >> 4;
                const int base = (int32_t)(((uint32_t)nib << shift) + 1024u);
                const int v = __ssat(__smlad((int16x2_t)packed, (int16x2_t)history, base) >> 11, 16);
                __asm__("pkhbt %0, %1, %2, lsl #16" : "=r"(history) : "r"(v), "r"(history));
                out[i] = (int16_t)v;
            }
            hist1 = (int16_t)history; hist2 = (int16_t)(history >> 16);
            return;
        }
#endif
        for (int i = 0; i < 14; ++i) {
            int nib = (i & 1) ? frame[1 + i / 2] & 15 : frame[1 + i / 2] >> 4;
            if (nib >= 8) nib -= 16;
            const int base = (int32_t)((uint32_t)(scale * nib) * 2048u + 1024u);
            const int16_t v = clamp16(predict_scalar(c1, c2, hist1, hist2, base) >> 11);
            memcpy((uint8_t *)out + i * 2, &v, 2);
            hist2 = hist1; hist1 = v;
        }
    }
};

inline uint64_t step_q32(double step) { return (uint64_t)(step * 4294967296.0 + 0.5); }
inline bool exact_phase(double step, double position, uint32_t limit, uint64_t &qstep, uint64_t &qpos) {
    // Loaded FX lengths are 24-bit. With step <= 16 and at most 28 fractional
    // bits, even the final overshoot has <= 53 significant bits. Every original
    // double addition is then exact, including long samples and ring wraps.
    // Other inputs retain the original loop, with no change to pitch or length.
    if (!(step >= 0 && step <= 16 && position >= 0 && position < 16777216.0)
        || !limit || limit > 0xffffffu) return false;
    qstep = step_q32(step); qpos = step_q32(position);
    return !((qstep | qpos) & 15u) && (double)qstep / 4294967296.0 == step
        && (double)qpos / 4294967296.0 == position;
}
// Gains retain the original float curves; quantize only their sample-loop use.
struct Gain { uint32_t value, mask; };
inline Gain gain_q16(float gain) {
    const uint32_t value = (uint32_t)(gain * 65536.0f + 0.5f);
    return {value, 0u - (uint32_t)(value >= 32768)};
}
inline int32_t interpolate_q16(int prev, int cur, uint32_t fraction) {
    return (int32_t)(((uint32_t)prev << 16) + (uint32_t)(cur - prev) * (fraction >> 16));
}
inline int scale_q16(int32_t sample, Gain gain) {
    int32_t q;
#if W3D_AUDIO_ARM_DSP
    // Signed low half + one whole sample represents unsigned Q0.16, including
    // unity (65536). Accumulation is modular; the final result fits int32.
    q = (int32_t)((uint32_t)__smlawb(sample, (int32_t)gain.value, 0) + ((uint32_t)sample & gain.mask));
#else
    q = (int32_t)(((int64_t)sample * gain.value) >> 16);
#endif
    // Match the float-to-int truncation direction, not floor for negatives.
    return (int32_t)((uint32_t)q + ((uint32_t)(q >> 31) >> 16)) >> 16;
}

template<class S> bool stream_fixed(S &s, const uint8_t *data, int *out, int frames) {
    const double reference_step = (double)(s.rate / 32000);
    uint64_t step, initial;
    // The original interpolates from the previously emitted sample (not always
    // the preceding source sample). Rounding across an integer can change that
    // history, even for sub-micro-sample phase error. Fall back before any write.
    if (!exact_phase(reference_step, s.pos, s.samples, step, initial)) return false;
    uint64_t pos = initial;
    const uint32_t limit = s.samples;
    const Gain gl = gain_q16(s.gain_l), gr = gain_q16(s.gain_r);
    for (int i = 0; i < frames; ++i) {
        const uint32_t si = (uint32_t)(pos >> 32), fi = si / 14;
        if (fi != s.frame_index) { s.frame_index = fi; s.dec.decode(data + (size_t)fi * 8, s.frame); }
        if (si != s.last_sample) { s.last_sample = si; s.prev = s.cur; s.cur = s.frame[si - fi * 14]; }
        const int32_t sample = interpolate_q16(s.prev, s.cur, (uint32_t)pos);
        out[i * 2] += scale_q16(sample, gl); out[i * 2 + 1] += scale_q16(sample, gr);
        pos += step;
        if ((uint32_t)(pos >> 32) >= limit) { pos -= (uint64_t)limit << 32; s.frame_index = -1; }
    }
    s.pos_q32 = pos;
    s.pos = (double)pos / 4294967296.0; // stream callback cursor, once per buffer
    return true;
}

template<class V, class S, class Gains> bool voice_fixed(V &v, const S &sm, int *out, int frames, Gains update_gains) {
    const double reference_step = (double)sm.rate * v.pitch / 32000;
    uint64_t step, initial;
    const uint32_t loop_end = sm.loop_start + sm.loop_len;
    if (sm.loop_len && (loop_end < sm.loop_start || loop_end > 0xffffffu)) return false;
    if (!exact_phase(reference_step, v.pos, sm.samples, step, initial)) return false;
    uint64_t pos = initial;
    const uint32_t end = sm.samples;
    Gain gl = gain_q16(v.gain_l), gr = gain_q16(v.gain_r);
    for (int i = 0; i < frames && v.active; ++i) {
        const uint32_t si = (uint32_t)(pos >> 32), fi = si / 14;
        // ADPCM only: the measured PCM path stays with the original float loop.
        int32_t sample;
        {
            if (fi != v.frame_index) {
                v.frame_index = fi;
                if ((size_t)fi * 8 + 8 > sm.adpcm.size()) { v.active = false; break; }
                v.dec.decode(sm.adpcm.data() + (size_t)fi * 8, v.frame);
            }
            if (si != v.last_sample) { v.last_sample = si; v.prev = v.cur; v.cur = v.frame[si - fi * 14]; }
            sample = interpolate_q16(v.prev, v.cur, (uint32_t)pos);
        }
        if (v.fade_len) {
            if (v.fade_left-- <= 0) { v.active = false; break; }
            if (!(i & 31)) { update_gains(v); gl = gain_q16(v.gain_l); gr = gain_q16(v.gain_r); }
        }
        out[i * 2] += scale_q16(sample, gl); out[i * 2 + 1] += scale_q16(sample, gr);
        pos += step;
        {
            if (sm.loop_len && (uint32_t)(pos >> 32) >= loop_end) {
                pos = (uint64_t)sm.loop_start << 32;
                v.dec.hist1 = sm.hist1; v.dec.hist2 = sm.hist2; v.frame_index = -1;
            } else if ((uint32_t)(pos >> 32) >= end) v.active = false;
        }
    }
    v.pos_q32 = pos;
    v.pos = (double)pos / 4294967296.0;
    return true;
}
} // namespace w3d_audio
