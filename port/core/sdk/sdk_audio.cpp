// Audio nativo que sustituye a MusyX y al AI del SDK: mezclador propio, ADPCM de Nintendo,
// streams del juego, efectos por proyecto MusyX (proj, pool, sdir, samp) y salida del reproductor THP.
// Macros de sonido: las 149 del juego son dos plantillas; se leen la muestra y la caída de 1 s tras soltar la tecla.
// Mezcla a 32 kHz, como la DSP de MusyX (160 cuadros cada 5 ms); SDL la lleva a la frecuencia del dispositivo.
#include "../../platform/common/arena.h"
#include "../../platform/platform.h"
#include "w3d_ptr.h"
#include <math.h>
#include <mutex>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include "audio_kernels.h"
#include "audio_metrics.h"
unsigned w3d_retrace_count(void);

using namespace w3d;
typedef w3d_u32 GA;

namespace {
const int kOutRate = 32000;
inline uint16_t be16(const uint8_t *p) { return (uint16_t)(p[0] << 8 | p[1]); }
inline uint32_t be32(const uint8_t *p) { return (uint32_t)p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]; }
inline int16_t clamp16(int v) { return v < -32768 ? -32768 : v > 32767 ? 32767 : (int16_t)v; }

using Adpcm = w3d_audio::Adpcm;

// Curva de volumen de MusyX (0x8040c728, 129 flotantes); la tabla se lee del DOL, no se copia al binario.
extern "C" char w3d_dol_image[];
float vol_curve(float v) {
    static float table[129];
    if (table[127] == 0.0f) {
        const uint8_t *p = (const uint8_t *)w3d_dol_image + (0x8040c728u - 0x8035f3e0u);
        uint32_t last; memcpy(&last, p + 127 * 4, 4);
        bool host = last == 0x3f800000u;  // 1.0 ya convertido.
        for (int i = 0; i < 129; i++) {
            uint32_t w; memcpy(&w, p + i * 4, 4);
            if (!host) w = __builtin_bswap32(w);
            memcpy(&table[i], &w, 4);
        }
    }
    float x = (v < 0 ? 0 : v > 1 ? 1 : v) * 127.0f;
    int i = (int)x;
    return table[i] + (table[i + 1] - table[i]) * (x - (float)i);
}
// Ley de panorama de salCalcVolume (0x80340b70): tramos 0, 0.7079, 1 sobre (pan - 1) / 63. En el centro, -3 dB por canal.
float pan_curve(float x) {
    x = x < 0 ? 0 : x > 2 ? 2 : x;
    return x < 1 ? 0.7079f * x : 0.7079f + (1.0f - 0.7079f) * (x - 1.0f);
}
void pan_gains(float vol, int pan, float *l, float *r) {
    float v = vol_curve(vol);
    if (pan == 0x80) pan = 0;
    float x = (float)((pan < 1 ? 1 : pan > 127 ? 127 : pan) - 1) / 63.0f;
    *l = v * pan_curve(2.0f - x);
    *r = v * pan_curve(x);
}

std::mutex g_mix;
#ifdef __3DS__
extern "C" uint64_t svcGetSystemTick(void);
static inline uint64_t audio_tick_now() { return svcGetSystemTick(); }
#else
static inline uint64_t audio_tick_now() { return 0; }
#endif
int g_profile;
W3dAudioMetricRing<128> g_audio_metrics;
W3dAudioMetrics g_game_metrics{}, g_pull_metrics{};
// All game API calls run on the game thread. pull alone uses the audio lane.
struct MixLock {
    bool audio, measured; uint64_t entered;
    explicit MixLock(bool audio_lane = false) : audio(audio_lane), measured(__atomic_load_n(&g_profile, __ATOMIC_RELAXED) != 0), entered(0) {
        const uint64_t before = measured ? audio_tick_now() : 0;
        g_mix.lock();
        if (measured) {
            entered = audio_tick_now();
            if (audio) g_pull_metrics.audio_wait_ticks += entered - before;
            else { g_game_metrics.game_wait_ticks += entered - before; ++g_game_metrics.game_locks; }
        }
    }
    ~MixLock() {
        if (measured) {
            const uint64_t held = audio_tick_now() - entered;
            if (audio) g_pull_metrics.audio_hold_ticks += held;
            else g_game_metrics.game_hold_ticks += held;
        }
        g_mix.unlock();
    }
};
static bool fixed_audio() {
    static const bool enabled = [] {
        if (const char *p = getenv("W3D_AUDIO_FIXED")) return atoi(p) != 0;
#ifdef W3D_PERF_DEFAULT_FIXED
        return true;
#else
        return false;
#endif
    }();
    return enabled;
}


float g_master = 1.0f;
bool g_started;

// --- Streams ADPCM del juego: un anillo en memoria que el juego rellena a medias ---
struct Stream {
    bool used, active;
    GA buffer, callback, user;
    uint32_t samples, write_pos;
    double pos;              // Reference cursor and callback cursor.
    uint64_t pos_q32;        // Opt-in experiment; never used by the float path.
    float rate;
    float gain_l, gain_r;
    Adpcm dec;
    int16_t frame[14], prev, cur;
    int frame_index, last_sample;
};
const int kStreams = 8;
Stream g_streams[kStreams];

void stream_mix(Stream &s, int *out, int frames) {
    if (fixed_audio() && w3d_audio::stream_fixed(s, (const uint8_t *)g2h(s.buffer), out, frames)) { ++g_pull_metrics.fixed_blocks; return; }
    ++g_pull_metrics.float_blocks;
    const double step = s.rate / kOutRate;
    const uint8_t *data = (const uint8_t *)g2h(s.buffer);
    for (int i = 0; i < frames; i++) {
        // El bloque ADPCM contiene 14 muestras. La fracción solo se usa al interpolar.
        const int si = (int)s.pos;
        const int fi = si / 14;
        if (fi != s.frame_index) {
            s.frame_index = fi;
            s.dec.decode(data + (size_t)fi * 8, s.frame);
        }
        if (si != s.last_sample) { s.last_sample = si; s.prev = s.cur; s.cur = s.frame[si % 14]; }
        float sample = s.prev + (s.cur - s.prev) * (float)(s.pos - si);
        out[i * 2] += (int)(sample * s.gain_l);
        out[i * 2 + 1] += (int)(sample * s.gain_r);
        s.pos += step;
        // Al dar la vuelta al anillo el descodificador sigue: el bloque 0 continúa al último.
        if (s.pos >= s.samples) { s.pos -= s.samples; s.frame_index = -1; }
    }
}

// --- Efectos: proyecto MusyX ---
// pcm: muestra de 16 bits ya decodificada (sonidos propios del port: francotirador de UM); si no, ADPCM de MusyX.
struct Sample { std::vector<uint8_t> adpcm; int16_t coef[16]; uint32_t samples, loop_start, loop_len; uint32_t rate; int hist1, hist2; const int16_t *pcm = nullptr; };
struct FxDef { uint16_t macro; uint8_t prio, vel, pan; };
struct MacroInfo { int sample; int fade_ms; };  // fade_ms: caída al soltar la tecla; 0 si la macro no reacciona a ella.
std::vector<Sample> g_samples;
int g_sample_of_id[0x10000];
FxDef g_fx[0x10000];
bool g_fx_used[0x10000];
MacroInfo g_macro[0x10000];
// Sonidos propios del port (francotirador de UM): ids de FX desde 0x0F00, fuera de los 0x00..0x94 de NGCSFX.proj. Los da
// de alta core/native/francotirador.cpp; sndPushGroup no los borra.
const unsigned kNativeFx = 0x0F00, kNativeFxCount = 2;
Sample g_native[kNativeFxCount];

struct Voice {
    bool active;
    uint32_t id;
    const Sample *sample;
    Adpcm dec;
    int16_t frame[14], prev, cur;
    int frame_index, last_sample;
    double pos;
    uint64_t pos_q32;
    float pitch;
    int vel, ctrl_vol, pan_base, ctrl_pan;
    int fade_ms;             // De la macro.
    int fade_left, fade_len; // Cuadros de salida restantes de la caída tras soltar la tecla.
    float gain_l, gain_r;
};
const int kVoices = 64;
Voice g_voices[kVoices];
uint32_t g_next_voice = 1;
// Último hueco de cada identificador, por sus 8 bits bajos: voice_of no recorre las 64 voces en cada sndFXCtrl.
uint8_t g_slot_of_id[256];

// Velocidad, control 7 y caída se multiplican antes de la curva; el panorama es el de inicio más el control 10.
void voice_gains(Voice &v) {
    float vol = (float)v.vel / 127.0f * (float)v.ctrl_vol / 127.0f;
    if (v.fade_len) vol *= (float)(v.fade_left < 0 ? 0 : v.fade_left) / (float)v.fade_len;
    pan_gains(vol, v.pan_base + v.ctrl_pan - 0x40, &v.gain_l, &v.gain_r);
}

void voice_mix(Voice &v, int *out, int frames) {
    const Sample &sm = *v.sample;
    if (!sm.pcm && fixed_audio() && w3d_audio::voice_fixed(v, sm, out, frames, voice_gains)) { ++g_pull_metrics.fixed_blocks; return; }
    ++g_pull_metrics.float_blocks;
    const double step = (double)sm.rate * v.pitch / kOutRate;
    if (sm.pcm) {   // PCM propio: interpolación lineal, misma caída y ganancias que el ADPCM
        for (int i = 0; i < frames && v.active; i++) {
            int si = (int)v.pos;
            if ((uint32_t)si + 1 >= sm.samples) { v.active = false; break; }
            float sample = sm.pcm[si] + (sm.pcm[si + 1] - sm.pcm[si]) * (float)(v.pos - si);
            if (v.fade_len) {
                if (v.fade_left-- <= 0) { v.active = false; break; }
                if (!(i & 31)) voice_gains(v);
            }
            out[i * 2] += (int)(sample * v.gain_l);
            out[i * 2 + 1] += (int)(sample * v.gain_r);
            v.pos += step;
        }
        return;
    }
    for (int i = 0; i < frames && v.active; i++) {
        const int si = (int)v.pos;
        const int fi = si / 14;
        if (fi != v.frame_index) {
            v.frame_index = fi;
            if ((size_t)fi * 8 + 8 > sm.adpcm.size()) { v.active = false; break; }
            v.dec.decode(sm.adpcm.data() + (size_t)fi * 8, v.frame);
        }
        if (si != v.last_sample) { v.last_sample = si; v.prev = v.cur; v.cur = v.frame[si % 14]; }
        float sample = v.prev + (v.cur - v.prev) * (float)(v.pos - si);
        if (v.fade_len) {
            if (v.fade_left-- <= 0) { v.active = false; break; }
            if (!(i & 31)) voice_gains(v);
        }
        out[i * 2] += (int)(sample * v.gain_l);
        out[i * 2 + 1] += (int)(sample * v.gain_r);
        v.pos += step;
        if (sm.loop_len && v.pos >= sm.loop_start + sm.loop_len) {
            v.pos = sm.loop_start;
            v.dec.hist1 = sm.hist1; v.dec.hist2 = sm.hist2;
            v.frame_index = -1;
        } else if (v.pos >= sm.samples) {
            v.active = false;
        }
    }
}

// --- AI: bloques PCM del reproductor de vídeo ---
GA g_ai_callback, g_ai_start;
uint32_t g_ai_len;
bool g_ai_on;
const uint32_t kAiRing = 1 << 16;  // Cuadros estéreo.
int16_t g_ai_ring[kAiRing * 2];
uint32_t g_ai_read, g_ai_write;

uint64_t g_mixed_frames;
// v33: pico de la salida y efectos lanzados desde el último informe (w3d_audio_tick los escribe en el registro de
// 3DS cada 10 s): en la consola no se oía nada y no había forma de saber si la mezcla llevaba sonido.
volatile int g_peak_out;
volatile unsigned g_fx_started;
void pull(int16_t *stereo, int frames) {
    static int mix[4096 * 2] __attribute__((aligned(32)));
    const bool measured = __atomic_load_n(&g_profile, __ATOMIC_RELAXED) != 0;
    const uint64_t start = measured ? audio_tick_now() : 0;
    g_pull_metrics = {};
    g_mixed_frames += frames;
    { MixLock lock(true);
    if (frames > 4096) frames = 4096;
    memset(mix, 0, (size_t)frames * 2 * sizeof(int));
    for (auto &s : g_streams) if (s.used && s.active) { ++g_pull_metrics.streams; stream_mix(s, mix, frames); }
    for (auto &v : g_voices) if (v.active) { ++g_pull_metrics.voices; voice_mix(v, mix, frames); }
    for (int i = 0; i < frames; i++) {
        if (g_ai_read != g_ai_write) {
            mix[i * 2] += g_ai_ring[g_ai_read * 2];
            mix[i * 2 + 1] += g_ai_ring[g_ai_read * 2 + 1];
            g_ai_read = (g_ai_read + 1) % kAiRing;
        }
    }
    int peak = g_peak_out;
    for (int i = 0; i < frames * 2; i++) {
        stereo[i] = clamp16((int)(mix[i] * g_master));
        const int a = stereo[i] < 0 ? -stereo[i] : stereo[i];
        if (a > peak) peak = a;
    }
    g_peak_out = peak;
    } // Complete the mix before publishing metrics; optional disk output is outside g_mix.
    if (measured) {
        const uint64_t elapsed = audio_tick_now() - start;
        g_pull_metrics.mix_ticks = elapsed - g_pull_metrics.audio_wait_ticks;
        g_pull_metrics.mix_max_ticks = g_pull_metrics.mix_ticks;
        g_pull_metrics.buffers = 1; g_pull_metrics.samples = frames;
        g_audio_metrics.push(g_pull_metrics);
    }
    // W3D_WAV=<archivo>: guarda la salida en PCM crudo para medir chasquidos sin depender del oído.
    static const char *wav = getenv("W3D_WAV");
    static FILE *wav_file = wav ? fopen(wav, "wb") : nullptr;
    if (wav_file) fwrite(stereo, 4, (size_t)frames, wav_file);
}

void ensure_started() {
    if (!g_started) {
        g_started = true;
        fprintf(stderr, "[audio-perf] fixed=%d DSP_ARM=%d rate=32000 voices=64 streams=8\n", fixed_audio(), W3D_AUDIO_ARM_DSP);
        plat::audio_start(pull);
    }
}

void parse_sdir(const uint8_t *sdir, const uint8_t *samp) {
    g_samples.clear();
    memset(g_sample_of_id, -1, sizeof g_sample_of_id);
    g_samples.reserve(4096);
    for (const uint8_t *e = sdir; be16(e) != 0xffff; e += 32) {
        uint16_t id = be16(e);
        uint32_t off = be32(e + 4), info = be32(e + 12), len = be32(e + 16);
        Sample s;
        s.rate = info & 0xffff;
        s.samples = len & 0xffffff;
        s.loop_start = be32(e + 20);
        s.loop_len = be32(e + 24);
        const uint8_t *adp = sdir + be32(e + 28);
        // Parámetros: u16 bytes por bloque, u8 ps, u8 lps, s16 hist2, s16 hist1, s16 coef[16].
        s.hist2 = (int16_t)be16(adp + 4);
        s.hist1 = (int16_t)be16(adp + 6);
        for (int i = 0; i < 16; i++) s.coef[i] = (int16_t)be16(adp + 8 + i * 2);
        uint32_t bytes = (s.samples + 13) / 14 * 8;
        s.adpcm.assign(samp + off, samp + off + bytes);
        g_sample_of_id[id] = (int)g_samples.size();
        g_samples.push_back(std::move(s));
    }
}

// Comandos de 8 B (dos palabras): 0x10 arranca la muestra, 0x07 espera y 0x0f es la envolvente. La espera con el bit 8 acaba al soltar la tecla.
void parse_pool(const uint8_t *pool) {
    for (auto &m : g_macro) { m.sample = -1; m.fade_ms = 0; }
    const uint8_t *m = pool + be32(pool);
    for (;;) {
        uint32_t size = be32(m);
        if (size == 0xffffffffu || size == 0) break;
        MacroInfo &info = g_macro[be16(m + 4)];
        bool key_wait = false;
        for (const uint8_t *c = m + 8; c + 8 <= m + size; c += 8) {
            uint32_t w = be32(c), w2 = be32(c + 4);
            if ((w & 0xff) == 0x10 && info.sample < 0) info.sample = (int)((w >> 8) & 0xffff);
            if ((w & 0xff) == 0x07 && (w & 0x100)) key_wait = true;
            if ((w & 0xff) == 0x0f && key_wait) info.fade_ms = (int)(w2 >> 16);
        }
        m += size;
    }
}

void parse_proj(const uint8_t *proj, unsigned gid) {
    for (const uint8_t *g = proj;;) {
        uint32_t next = be32(g);
        if (be16(g + 4) == gid && be16(g + 6) == 1) {
            const uint8_t *fx = proj + be32(g + 0x1c);
            if (fx < proj) break;
            unsigned n = be16(fx);
            const uint8_t *e = fx + 4;
            for (unsigned i = 0; i < n; i++, e += 10) {
                uint16_t id = be16(e);
                g_fx[id].macro = be16(e + 2);
                g_fx[id].prio = e[4];
                g_fx[id].vel = e[6];
                g_fx[id].pan = e[7];
                g_fx_used[id] = true;
            }
        }
        if (next == 0xffffffffu || next == 0) break;
        g = proj + next;
        if (be32(g) == 0xffffffffu) break;
    }
}
}  // namespace

#ifdef __3DS__
extern "C" unsigned w3d_audio_out_buffers(void);   // platform_3ds.cpp: búferes entregados a NDSP
#endif
extern "C" {
// Lo llama VIWaitForRetrace desde el hilo del juego: los callbacks tocan datos del juego.
void w3d_audio_tick(void) {
#ifdef __3DS__
    {   // Cada 10 s (300 retrazos): ¿la mezcla lleva sonido y llega a la DSP?
        static unsigned ticks, last_bufs; static uint64_t last_frames;
        if (++ticks % 300 == 0) {
            const unsigned bufs = w3d_audio_out_buffers();
            int streams = 0; for (int i = 0; i < kStreams; i++) streams += g_streams[i].used && g_streams[i].active;
            fprintf(stderr, "[audio] 10 s: pico %d, efectos %u, streams %d, mezcla %llu cuadros, %u búferes a la DSP, volumen %.2f\n",
                    g_peak_out, g_fx_started, streams, (unsigned long long)(g_mixed_frames - last_frames), bufs - last_bufs, g_master);
            g_peak_out = 0; g_fx_started = 0; last_bufs = bufs; last_frames = g_mixed_frames;
        }
    }
#endif
    for (int i = 0; i < kStreams; i++) {
        Stream &s = g_streams[i];
        if (!s.used || !s.active || !s.callback) continue;
        uint32_t read;
        { MixLock lock; read = (uint32_t)s.pos; }
        uint32_t free_samples = (read + s.samples - s.write_pos) % s.samples;
        if (!free_samples) continue;
        uint32_t len1 = s.write_pos + free_samples <= s.samples ? free_samples : s.samples - s.write_pos;
        uint32_t len2 = free_samples - len1;
        typedef unsigned (*Update)(GA, unsigned, GA, unsigned, GA);
        unsigned used = ((Update)g2h(s.callback))(s.write_pos, len1, 0, len2, s.user);
        s.write_pos = (s.write_pos + used) % s.samples;
    }
    // Vídeo: un bloque de 160 cuadros cada vez hasta llenar el margen del anillo.
    while (g_ai_on && g_ai_callback && g_ai_start) {
        uint32_t queued;
        { MixLock lock; queued = (g_ai_write + kAiRing - g_ai_read) % kAiRing; }
        if (queued > kOutRate / 20) break;
        const int16_t *src = (const int16_t *)g2h(g_ai_start);
        uint32_t frames = g_ai_len / 4;
        {
            MixLock lock;
            for (uint32_t i = 0; i < frames; i++) {
                g_ai_ring[g_ai_write * 2] = src[i * 2];
                g_ai_ring[g_ai_write * 2 + 1] = src[i * 2 + 1];
                g_ai_write = (g_ai_write + 1) % kAiRing;
            }
        }
        ((void (*)(void))g2h(g_ai_callback))();
    }
}

// --- AI ---
// Sin AX: el vídeo THP en modo mezcla llama al callback anterior y toma de AIGetDMAStartAddr lo que AX habría generado.
// Este sustituto entrega silencio; los efectos y la música siguen por el mezclador del port.
static GA g_ai_silence;
static void ai_silent_callback(void) { g_ai_start = g_ai_silence; g_ai_len = 0x280; }
GA A80311210(GA cb) {                                                        // AIRegisterDMACallback
    GA o = g_ai_callback;
    if (!o && cb) {
        if (!g_ai_silence) { void *b = w3d::arena_alloc(0x280); memset(b, 0, 0x280); g_ai_silence = h2g(b); }
        o = h2g((void *)ai_silent_callback);
        ai_silent_callback();
        ensure_started();
        g_ai_on = true;
    }
    g_ai_callback = cb;
    return o;
}
void A80311254(GA start, unsigned len) { g_ai_start = start; g_ai_len = len; }  // AIInitDMA
void A803112dc(void) { ensure_started(); g_ai_on = true; }                   // AIStartDMA
// AIGetDMAStartAddr: dirección física; el juego le suma 0x80000000 y debe volver a la real.
unsigned A8031130c(void) { return g_ai_start - 0x80000000u; }
unsigned A803114f0(void) { return 0; }                                       // AIGetDSPSampleRate: 32 kHz, medido en Dolphin
void A80311640(GA) {}                                                        // AIInit

// --- MusyX: sistema ---
int A80331928(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned) { ensure_started(); return 0; }  // sndInit
void A80331a40(void) {}                                                      // sndQuit
void A8033499c(GA) {}                                                        // sndSetHooks
void A80322a5c(unsigned) {}                                                  // sndOutputMode: salida estéreo siempre; en estéreo MusyX ignora el canal envolvente (span).
void A803229fc(unsigned vol, unsigned, unsigned) { g_master = (float)vol / 127.0f; }  // sndVolume
int A8032f828(GA proj, unsigned gid, GA samples, GA sdir, GA pool) {         // sndPushGroup
    MixLock lock;
    for (auto &v : g_voices) v.active = false;
    parse_sdir((const uint8_t *)g2h(sdir), (const uint8_t *)g2h(samples));
    parse_pool((const uint8_t *)g2h(pool));
    parse_proj((const uint8_t *)g2h(proj), gid);
    return 1;
}
int A8032fb54(void) {                                                        // sndPopGroup
    MixLock lock;
    for (auto &v : g_voices) v.active = false;
    g_samples.clear();
    return 1;
}

// --- MusyX: efectos ---
extern "C" int w3d_fx_muted(unsigned fid);   // core/native/fe_layout.cpp: sonidos de controles que la UI oculta
unsigned A80322938(unsigned fid, unsigned vol, unsigned pan, unsigned) {     // sndFXStartEx
    fid &= 0xffff;
    if (w3d_fx_muted(fid)) return 0xffffffffu;
    const Sample *native = fid >= kNativeFx && fid < kNativeFx + kNativeFxCount && g_native[fid - kNativeFx].pcm ? &g_native[fid - kNativeFx] : nullptr;
    if (!native && !g_fx_used[fid]) return 0xffffffffu;
    const MacroInfo &macro = g_macro[g_fx[fid].macro];
    int sid = native ? -2 : macro.sample;
    if (!native && (sid < 0 || g_sample_of_id[sid] < 0)) return 0xffffffffu;
    if ((vol & 0xff) == 0xff) vol = native ? 127 : g_fx[fid].vel;
    if ((pan & 0xff) == 0xff) pan = native ? 64 : g_fx[fid].pan;
    MixLock lock;
    static FILE *log = getenv("W3D_SND_LOG") ? fopen(getenv("W3D_SND_LOG"), "w") : nullptr;
    if (log) { fprintf(log, "%.3f fx %u vol %u pan %u muestra %d\n", w3d::plat::now_seconds(), fid, vol & 0xff, pan & 0xff, sid); fflush(log); }
    for (auto &v : g_voices) {
        if (v.active) continue;
        const Sample &s = native ? *native : g_samples[g_sample_of_id[sid]];
        v.active = true;
        v.id = g_next_voice++;
        g_slot_of_id[v.id & 255] = (uint8_t)(&v - g_voices);
        v.sample = &s;
        memcpy(v.dec.coef, s.coef, sizeof s.coef);
        v.dec.hist1 = s.hist1; v.dec.hist2 = s.hist2;
        v.frame_index = -1; v.last_sample = -1; v.prev = v.cur = 0; v.pos = 0; v.pos_q32 = 0; v.pitch = 1.0f;
        v.vel = (int)(vol & 0xff); v.ctrl_vol = 127; v.pan_base = (int)(pan & 0xff); v.ctrl_pan = 0x40;
        v.fade_ms = native ? 0 : macro.fade_ms; v.fade_left = v.fade_len = 0;
        voice_gains(v);
        g_fx_started++;
        return v.id;
    }
    return 0xffffffffu;
}
static Voice *voice_of(unsigned vid) {
    Voice &q = g_voices[g_slot_of_id[vid & 255]];
    if (q.active && q.id == vid) return &q;
    for (auto &v : g_voices) if (v.active && v.id == vid) return &v;
    return nullptr;
}
int A80322838(unsigned vid, unsigned ctrl, unsigned value) {                 // sndFXCtrl
    MixLock lock;
    Voice *v = voice_of(vid);
    if (!v) return 0;
    if ((ctrl & 0xff) == 7) v->ctrl_vol = (int)(value & 0xff);
    else if ((ctrl & 0xff) == 10) v->ctrl_pan = (int)(value & 0xff);
    voice_gains(*v);
    return 1;
}
int A80322898(unsigned vid, unsigned ctrl, unsigned value) {                 // sndFXCtrl14: rueda de tono (0x80) y Doppler (0x84), centro 0x2000.
    MixLock lock;
    Voice *v = voice_of(vid);
    if (!v) return 0;
    if ((ctrl & 0xff) == 0x80 || (ctrl & 0xff) == 0x84) v->pitch = powf(2.0f, ((float)(value & 0xffff) - 8192.0f) / 8192.0f * 2.0f / 12.0f);
    return 1;
}
int A803228f8(unsigned vid) {                                                // sndFXKeyOff
    MixLock lock;
    Voice *v = voice_of(vid);
    if (!v) return 0;
    // Plantilla sin espera de tecla: la muestra sigue hasta su final. Con ella: caída y fin.
    if (v->fade_ms && !v->fade_len) { v->fade_len = v->fade_left = v->fade_ms * kOutRate / 1000; }
    return 1;
}
unsigned A803229bc(unsigned vid) {                                           // sndFXCheck
    MixLock lock;
    return voice_of(vid) ? vid : 0xffffffffu;
}

// --- MusyX: streams ---
// W3D_SND_LOG=<archivo>: también <archivo>.str con las llamadas de streams.
static FILE *stream_log() {
    static FILE *log = getenv("W3D_SND_LOG") ? fopen((std::string(getenv("W3D_SND_LOG")) + ".str").c_str(), "w") : nullptr;
    return log;
}
#define STRLOG(...) do { if (FILE *l_ = stream_log()) { fprintf(l_, __VA_ARGS__); fflush(l_); } } while (0)
// En 3DS los sucesos de streams van también al registro (log.txt), para leerlos tras jugar en la consola.
#ifdef __3DS__
#define STRCON(...) do { fprintf(stderr, "[stream] retrazo %u ", ::w3d_retrace_count()); fprintf(stderr, __VA_ARGS__); } while (0)
#else
#define STRCON(...) do {} while (0)
#endif
unsigned A80323d88(int, Ptr32<void> buffer, int samples, int frq, int vol, int pan, int, int, int, int, int, Ptr32<void> cb, Ptr32<void> user, int) {  // sndStreamAllocEx
    ensure_started();
    MixLock lock;
    for (int i = 0; i < kStreams; i++) {
        Stream &s = g_streams[i];
        if (s.used) continue;
        memset(&s, 0, sizeof s);
        s.used = true;
        s.buffer = buffer.v; s.samples = (uint32_t)samples; s.rate = (float)frq;
        s.callback = cb.v; s.user = user.v;
        s.frame_index = -1;
        pan_gains((float)vol / 127.0f, pan, &s.gain_l, &s.gain_r);
        STRCON("reserva %d muestras %d\n", i, samples);
        STRLOG("alloc %d buf %08x muestras %d frq %d vol %d pan %d cb %08x user %08x gan %.3f %.3f\n", i, buffer.v, samples, frq, vol, pan, cb.v, user.v, s.gain_l, s.gain_r);
        return (unsigned)i;
    }
    return 0xffffffffu;
}
void A803254e4(unsigned id) { STRLOG("free %u\n", id); STRCON("libera %u\n", id); MixLock lock; if (id < kStreams) g_streams[id].used = g_streams[id].active = false; }  // sndStreamFree
void A80324920(unsigned id, unsigned vol, unsigned pan, unsigned, unsigned, unsigned) {  // sndStreamMixParameterEx
    MixLock lock;
    if (id < kStreams) pan_gains((float)(vol & 0xff) / 127.0f, (int)(pan & 0xff), &g_streams[id].gain_l, &g_streams[id].gain_r);
    STRLOG("mix %u vol %08x pan %08x\n", id, vol, pan);
    static unsigned last_vol[kStreams];
    if (id < kStreams && (vol & 0xff) != last_vol[id]) { last_vol[id] = vol & 0xff; STRCON("volumen %u = %u pan %u\n", id, vol & 0xff, pan & 0xff); }
}
void A80324e7c(unsigned id, unsigned frq) { MixLock lock; if (id < kStreams) g_streams[id].rate = (float)frq; STRLOG("frq %u %u\n", id, frq); }  // sndStreamFrq
void A80324224(unsigned id, GA info) {                                       // sndStreamADPCMParameter
    MixLock lock;
    if (id >= kStreams) return;
    // El juego pasa directamente los 16 coeficientes de la cabecera DSP, ya convertidos al leerla.
    const uint8_t *p = (const uint8_t *)g2h(info);
    memcpy(g_streams[id].dec.coef, p, sizeof g_streams[id].dec.coef);
    g_streams[id].dec.hist1 = g_streams[id].dec.hist2 = 0;
    g_streams[id].frame_index = -1;
}
void A803238fc(unsigned, unsigned, unsigned, unsigned, unsigned) {}          // sndStreamARAMUpdate: los datos ya están en memoria.
int A80325bb8(unsigned id) {                                                 // sndStreamActivate
    MixLock lock;
    if (id >= kStreams) return 0;
    Stream &s = g_streams[id];
    STRCON("activa %u gan %.3f %.3f\n", id, g_streams[id].gain_l, g_streams[id].gain_r);
    STRLOG("activate %u cuadro %llu gan %.3f %.3f\n", id, (unsigned long long)g_mixed_frames, g_streams[id].gain_l, g_streams[id].gain_r);
    s.active = true; s.pos = 0; s.pos_q32 = 0; s.write_pos = 0; s.frame_index = -1; s.last_sample = -1; s.prev = s.cur = 0;
    return 1;
}
// v32: streams que suenan ahora mismo (core/native/fe_bridge.cpp, music_watchdog: la música del título y del menú).
extern "C" int w3d_stream_active_count(void) {
    MixLock lock;
    int n = 0;
    for (int i = 0; i < kStreams; i++) if (g_streams[i].used && g_streams[i].active) n++;
    return n;
}
void A80326210(unsigned id) { STRCON("para %u\n", id); MixLock lock; if (id < kStreams) g_streams[id].active = false; }  // sndStreamDeactivate
}

// Francotirador de UM: muestra PCM de 16 bits mono para el id de FX 0x0F00 + i (core/native/francotirador.cpp).
extern "C" void w3d_audio_native(unsigned i, const int16_t *pcm, unsigned frames, unsigned rate) {
    if (i >= kNativeFxCount) return;
    MixLock lock;
    g_native[i].pcm = pcm; g_native[i].samples = frames; g_native[i].rate = rate; g_native[i].loop_len = 0;
}

extern "C" void w3d_audio_profile_enable(int enabled) { __atomic_store_n(&g_profile, enabled != 0, __ATOMIC_RELAXED); }
extern "C" void w3d_audio_metrics_take(W3dAudioMetrics *out) {
    *out = g_game_metrics; g_game_metrics = {};
    W3dAudioMetrics m;
    while (g_audio_metrics.pop(m)) {
        out->mix_ticks += m.mix_ticks;
        out->audio_wait_ticks += m.audio_wait_ticks;
        out->audio_hold_ticks += m.audio_hold_ticks;
        if (m.mix_max_ticks > out->mix_max_ticks) out->mix_max_ticks = m.mix_max_ticks;
        out->buffers += m.buffers; out->samples += m.samples;
        out->voices += m.voices; out->streams += m.streams;
        out->fixed_blocks += m.fixed_blocks; out->float_blocks += m.float_blocks;
    }
    out->dropped = g_audio_metrics.take_lost();
}
