// Vídeo THP: JPEG base 4:2:0 sin relleno de 0xFF en los datos, con salida en mosaicos I8 de GX.
#include "w3d_ptr.h"
#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace w3d;
typedef w3d_u32 GA;

namespace {
struct Huff { uint16_t min_code[17]; int max_code[18]; int val_ptr[17]; uint8_t vals[256]; };
struct Decoder {
    uint8_t quant[4][64];
    Huff dc[4], ac[4];
    int qt_of[3], dc_of[3], ac_of[3];
    int width, height;
    const uint8_t *p, *end;
    uint32_t bits; int nbits;
    int pred[3];
};
const uint8_t kZigzag[64] = {0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 32, 25, 18, 11, 4, 5, 12, 19, 26, 33, 40, 48, 41, 34, 27, 20, 13, 6, 7, 14, 21, 28, 35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23, 30, 37, 44, 51, 58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 47, 55, 62, 63};

inline unsigned getbits(Decoder &d, int n) {
    while (d.nbits < n) {
        d.bits = (d.bits << 8) | (d.p < d.end ? *d.p++ : 0);
        d.nbits += 8;
    }
    d.nbits -= n;
    return (d.bits >> d.nbits) & ((1u << n) - 1);
}
inline int huff_decode(Decoder &d, const Huff &h) {
    int code = 0;
    for (int len = 1; len <= 16; len++) {
        code = (code << 1) | (int)getbits(d, 1);
        if (h.max_code[len] >= 0 && code <= h.max_code[len] && code >= h.min_code[len])
            return h.vals[h.val_ptr[len] + code - h.min_code[len]];
    }
    return 0;
}
inline int extend(int v, int t) { return t && v < (1 << (t - 1)) ? v - (1 << t) + 1 : v; }

#if defined(__3DS__)
// IDCT entera de dos pasadas (método de Loeffler con constantes de 12 bits), con atajo para bloques solo de continua.
#define F2F(x) ((int)((x) * 4096 + 0.5))
#define FSH(x) ((x) * 4096)
#define IDCT_1D(s0, s1, s2, s3, s4, s5, s6, s7) \
    int t0, t1, t2, t3, p1, p2, p3, p4, p5, x0, x1, x2, x3; \
    p2 = s2; p3 = s6; p1 = (p2 + p3) * F2F(0.5411961f); t2 = p1 + p3 * -F2F(1.847759065f); t3 = p1 + p2 * F2F(0.765366865f); \
    p2 = s0; p3 = s4; t0 = FSH(p2 + p3); t1 = FSH(p2 - p3); \
    x0 = t0 + t3; x3 = t0 - t3; x1 = t1 + t2; x2 = t1 - t2; \
    t0 = s7; t1 = s5; t2 = s3; t3 = s1; p3 = t0 + t2; p4 = t1 + t3; p1 = t0 + t3; p2 = t1 + t2; p5 = (p3 + p4) * F2F(1.175875602f); \
    t0 = t0 * F2F(0.298631336f); t1 = t1 * F2F(2.053119869f); t2 = t2 * F2F(3.072711026f); t3 = t3 * F2F(1.501321110f); \
    p1 = p5 + p1 * -F2F(0.899976223f); p2 = p5 + p2 * -F2F(2.562915447f); p3 = p3 * -F2F(1.961570560f); p4 = p4 * -F2F(0.390180644f); \
    t3 += p1 + p4; t2 += p2 + p3; t1 += p2 + p4; t0 += p1 + p3;
void idct(const int *in, uint8_t *out, int stride) {
    int val[64];
    for (int i = 0; i < 8; i++) {
        const int *d = in + i; int *v = val + i;
        if (!d[8] && !d[16] && !d[24] && !d[32] && !d[40] && !d[48] && !d[56]) {
            int dc = d[0] * 4;
            v[0] = v[8] = v[16] = v[24] = v[32] = v[40] = v[48] = v[56] = dc;
        } else {
            IDCT_1D(d[0], d[8], d[16], d[24], d[32], d[40], d[48], d[56])
            x0 += 512; x1 += 512; x2 += 512; x3 += 512;
            v[0] = (x0 + t3) >> 10; v[56] = (x0 - t3) >> 10; v[8] = (x1 + t2) >> 10; v[48] = (x1 - t2) >> 10;
            v[16] = (x2 + t1) >> 10; v[40] = (x2 - t1) >> 10; v[24] = (x3 + t0) >> 10; v[32] = (x3 - t0) >> 10;
        }
    }
    for (int i = 0; i < 8; i++) {
        const int *v = val + i * 8; uint8_t *o = out + i * stride;
        IDCT_1D(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7])
        x0 += 65536 + (128 << 17); x1 += 65536 + (128 << 17); x2 += 65536 + (128 << 17); x3 += 65536 + (128 << 17);
        #define CL(e) ({ int q_ = (e) >> 17; q_ < 0 ? 0 : q_ > 255 ? 255 : q_; })
        o[0] = CL(x0 + t3); o[7] = CL(x0 - t3); o[1] = CL(x1 + t2); o[6] = CL(x1 - t2);
        o[2] = CL(x2 + t1); o[5] = CL(x2 - t1); o[3] = CL(x3 + t0); o[4] = CL(x3 - t0);
        #undef CL
    }
}
#else
// IDCT directa con tabla de cosenos; en Mac sobra potencia y es la forma más clara.
void idct(const int *in, uint8_t *out, int stride) {
    static float table[8][8];
    static bool ready;
    if (!ready) {
        for (int x = 0; x < 8; x++) {
            for (int u = 0; u < 8; u++) {
                float c = u == 0 ? 0.70710678f : 1.0f;
                table[x][u] = c * cosf((float)((2 * x + 1) * u) * 3.14159265f / 16.0f) * 0.5f;
            }
        }
        ready = true;
    }
    float tmp[64];
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            float acc = 0;
            for (int u = 0; u < 8; u++) acc += table[x][u] * (float)in[y * 8 + u];
            tmp[y * 8 + x] = acc;
        }
    }
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            float acc = 0;
            for (int v = 0; v < 8; v++) acc += table[y][v] * tmp[v * 8 + x];
            int val = (int)floorf(acc + 128.5f);
            out[y * stride + x] = val < 0 ? 0 : val > 255 ? 255 : (uint8_t)val;
        }
    }
}
#endif

void decode_block(Decoder &d, int comp, uint8_t *out, int stride) {
    int coef[64];
    memset(coef, 0, sizeof coef);
    const Huff &dc = d.dc[d.dc_of[comp]], &ac = d.ac[d.ac_of[comp]];
    const uint8_t *q = d.quant[d.qt_of[comp]];
    int t = huff_decode(d, dc);
    int diff = t ? extend((int)getbits(d, t), t) : 0;
    d.pred[comp] += diff;
    coef[0] = d.pred[comp] * q[0];
    for (int i = 1; i < 64; i++) {
        int rs = huff_decode(d, ac);
        int r = rs >> 4, s = rs & 15;
        if (!s) {
            if (r != 15) break;
            i += 15;
            continue;
        }
        i += r;
        if (i > 63) break;
        coef[kZigzag[i]] = extend((int)getbits(d, s), s) * q[i];
    }
    idct(coef, out, stride);
}

// Plano GX I8: mosaicos de 8×4.
inline void put_tile(uint8_t *plane, int width, int x, int y, uint8_t v) {
    plane[((y / 4) * (width / 8) + x / 8) * 32 + (y % 4) * 8 + (x % 8)] = v;
}
void store(uint8_t *plane, int plane_w, int plane_h, int bx, int by, const uint8_t *block) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            int px = bx + x, py = by + y;
            if (px < plane_w && py < plane_h) put_tile(plane, plane_w, px, py, block[y * 8 + x]);
        }
    }
}

bool parse(Decoder &d, const uint8_t *data, const uint8_t *end) {
    const uint8_t *p = data;
    if (p[0] != 0xff || p[1] != 0xd8) return false;
    p += 2;
    while (p + 4 <= end) {
        if (p[0] != 0xff) return false;
        int marker = p[1];
        int len = p[2] << 8 | p[3];
        const uint8_t *s = p + 4, *e = p + 2 + len;
        if (marker == 0xdb) {
            while (s < e) {
                int id = *s & 3; s++;
                memcpy(d.quant[id], s, 64); s += 64;
            }
        } else if (marker == 0xc0) {
            d.height = s[1] << 8 | s[2];
            d.width = s[3] << 8 | s[4];
            int n = s[5];
            for (int i = 0; i < n && i < 3; i++) d.qt_of[i] = s[6 + i * 3 + 2] & 3;
        } else if (marker == 0xc4) {
            while (s < e) {
                int tc = *s >> 4, id = *s & 3; s++;
                Huff &h = tc ? d.ac[id] : d.dc[id];
                const uint8_t *counts = s; s += 16;
                int code = 0, k = 0;
                for (int l = 1; l <= 16; l++) {
                    h.val_ptr[l] = k;
                    h.min_code[l] = (uint16_t)code;
                    code += counts[l - 1];
                    k += counts[l - 1];
                    h.max_code[l] = counts[l - 1] ? code - 1 : -1;
                    code <<= 1;
                }
                memcpy(h.vals, s, k); s += k;
            }
        } else if (marker == 0xda) {
            int n = s[0];
            for (int i = 0; i < n && i < 3; i++) {
                d.dc_of[i] = s[2 + i * 2] >> 4;
                d.ac_of[i] = s[2 + i * 2] & 15;
            }
            d.p = e;
            d.end = end;
            return true;
        }
        p = e;
    }
    return false;
}
}  // namespace

extern "C" {
int A80322268(void) { return 1; }  // THPInit

// THPVideoDecode(archivo, planoY, planoU, planoV, trabajo). Devuelve 0 si va bien.
int A8031ada0(GA file, GA y, GA u, GA v, GA) {
    static Decoder d;
    // El tamaño real del cuadro no llega: se decodifica hasta completar la imagen.
    const uint8_t *data = (const uint8_t *)g2h(file);
    if (!parse(d, data, data + (1 << 24))) return 1;
    d.bits = 0; d.nbits = 0;
    d.pred[0] = d.pred[1] = d.pred[2] = 0;
    uint8_t *py = (uint8_t *)g2h(y), *pu = (uint8_t *)g2h(u), *pv = (uint8_t *)g2h(v);
    const int cw = d.width / 2, ch = d.height / 2;
    uint8_t block[64];
    for (int my = 0; my < d.height; my += 16) {
        for (int mx = 0; mx < d.width; mx += 16) {
            for (int j = 0; j < 2; j++) {
                for (int i = 0; i < 2; i++) {
                    decode_block(d, 0, block, 8);
                    store(py, d.width, d.height, mx + i * 8, my + j * 8, block);
                }
            }
            decode_block(d, 1, block, 8);
            store(pu, cw, ch, mx / 2, my / 2, block);
            decode_block(d, 2, block, 8);
            store(pv, cw, ch, mx / 2, my / 2, block);
        }
    }
    return 0;
}

// THPAudioDecode(salida, bloque, modo). Bloque big-endian: tamaño de canal, muestras, coeficientes y estado.
unsigned A80322308(GA out, GA frame, int mode) {
    const uint8_t *f = (const uint8_t *)g2h(frame);
    auto be32 = [](const uint8_t *p) { return (uint32_t)p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]; };
    auto be16 = [](const uint8_t *p) { return (int16_t)(p[0] << 8 | p[1]); };
    uint32_t channel_size = be32(f), samples = be32(f + 4);
    int16_t *o = (int16_t *)g2h(out);
    const uint8_t *data = f + 80;
    for (int c = 0; c < 2; c++) {
        const uint8_t *coefs = f + 8 + c * 32;
        int y1 = be16(f + 72 + c * 4), y2 = be16(f + 74 + c * 4);
        const uint8_t *src = data + c * channel_size;
        int step = mode ? 1 : 2;
        int16_t *dst = mode ? o + c * samples : o + c;
        uint32_t written = 0;
        while (written < samples) {
            int ps = *src++, scale = 1 << (ps & 15), idx = (ps >> 4) & 7;
            int c1 = be16(coefs + idx * 4), c2 = be16(coefs + idx * 4 + 2);
            for (int i = 0; i < 14 && written < samples; i++, written++) {
                int nib = (i & 1) ? src[i / 2] & 15 : src[i / 2] >> 4;
                if (nib >= 8) nib -= 16;
                int v = (scale * nib * 2048 + 1024 + c1 * y1 + c2 * y2) >> 11;
                v = v < -32768 ? -32768 : v > 32767 ? 32767 : v;
                *dst = (int16_t)v;
                dst += step;
                y2 = y1; y1 = v;
            }
            src += 7;
        }
    }
    return samples;
}
}
