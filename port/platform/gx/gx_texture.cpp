// Decodificación de texturas GX a RGBA8. Los teselos llegan en big-endian, byte a byte, como en la consola.
// La TLUT llega en el orden del anfitrión: ver la nota de gx_internal.h.
#ifdef __3DS__
#include "../3ds/zones_3ds.h"
#endif
#include "gx_internal.h"
#ifdef __3DS__
extern int g_detail;   // zones_3ds.cpp (v34)
#endif
#include "w3d_ptr.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace w3d {
namespace gx {

namespace {

inline u16 be16(const u8 *p) { return (u16)(p[0] << 8 | p[1]); }

// Tamaño de bloque en texeles y bytes por bloque.
void block_of(u32 fmt, u32 &bw, u32 &bh, u32 &bytes) {
    switch (fmt) {
        case TEX_I4: case TEX_CI4: case TEX_CMPR: bw = 8; bh = 8; bytes = 32; break;
        case TEX_I8: case TEX_IA4: case TEX_CI8: bw = 8; bh = 4; bytes = 32; break;
        case TEX_RGBA8: bw = 4; bh = 4; bytes = 64; break;
        default: bw = 4; bh = 4; bytes = 32; break;
    }
}

inline void put(u8 *rgba, u32 w, u32 h, u32 x, u32 y, u8 r, u8 g_, u8 b, u8 a) {
    if (x >= w || y >= h) return;
    u8 *o = rgba + (size_t)(y * w + x) * 4;
    o[0] = r; o[1] = g_; o[2] = b; o[3] = a;
}

inline void from_tlut(const u16 *tlut, u32 fmt, u32 i, u8 *c) {
    u16 v = tlut ? tlut[i] : 0;
    switch (fmt) {
        case TL_IA8: c[0] = c[1] = c[2] = (u8)v; c[3] = (u8)(v >> 8); break;
        case TL_RGB565:
            c[0] = (u8)(((v >> 11) << 3) | (v >> 13));
            c[1] = (u8)((((v >> 5) & 63) << 2) | (((v >> 5) & 63) >> 4));
            c[2] = (u8)(((v & 31) << 3) | ((v & 31) >> 2));
            c[3] = 255;
            break;
        default:
            if (v & 0x8000) {
                c[0] = (u8)((((v >> 10) & 31) << 3) | (((v >> 10) & 31) >> 2));
                c[1] = (u8)((((v >> 5) & 31) << 3) | (((v >> 5) & 31) >> 2));
                c[2] = (u8)(((v & 31) << 3) | ((v & 31) >> 2));
                c[3] = 255;
            } else {
                c[0] = (u8)(((v >> 8) & 15) * 17);
                c[1] = (u8)(((v >> 4) & 15) * 17);
                c[2] = (u8)((v & 15) * 17);
                u32 a = (v >> 12) & 7;
                c[3] = (u8)((a << 5) | (a << 2) | (a >> 1));
            }
    }
}

}  // namespace

u32 tex_level_bytes(u32 w, u32 h, u32 fmt) {
    u32 bw, bh, bytes;
    block_of(fmt, bw, bh, bytes);
    return ((w + bw - 1) / bw) * ((h + bh - 1) / bh) * bytes;
}

// GXGetTexBufferSize.
u32 tex_buffer_size(u32 w, u32 h, u32 fmt, bool mip, u32 max_lod) {
    u32 fmt_low = fmt;
    if (!mip) return tex_level_bytes(w & 0xffff, h & 0xffff, fmt_low);
    u32 total = 0;
    w &= 0xffff;
    h &= 0xffff;
    for (u32 lod = max_lod & 0xff; lod != 0; lod--) {
        total += tex_level_bytes(w, h, fmt_low);
        if (w == 1 && h == 1) return total;
        w = w < 2 ? 1 : w >> 1;
        h = h < 2 ? 1 : h >> 1;
    }
    return total;
}

// Una expansión por entrada de paleta, incluso si miles de texeles la comparten.
// Cada bloque ocupa 32 bytes en GX, también en el borde de una textura impar.
template<bool FourBit>
static void decode_paletted(const u8 *s, u32 w, u32 h, const u16 *tlut, u32 tlut_fmt, u8 *rgba) {
    constexpr u32 colors = FourBit ? 16 : 256, bh = FourBit ? 8 : 4;
    u32 palette[colors];
    for (u32 i = 0; i < colors; i++) from_tlut(tlut, tlut_fmt, i, (u8 *)&palette[i]);
    for (u32 by = 0; by < h; by += bh) for (u32 bx = 0; bx < w; bx += 8, s += 32) {
        const u32 rows = h - by < bh ? h - by : bh;
        const u32 cols = w - bx < 8 ? w - bx : 8;
        for (u32 y = 0; y < rows; y++) {
            const u8 *indices = s + y * (FourBit ? 4 : 8);
            u8 *out = rgba + ((size_t)(by + y) * w + bx) * 4;
            for (u32 x = 0; x < cols; x++) {
                const u32 index = FourBit ? (indices[x / 2] >> ((x & 1) ? 0 : 4)) & 15 : indices[x];
                memcpy(out + 4 * x, &palette[index], 4);
            }
        }
    }
}

void tex_decode(const u8 *s, u32 w, u32 h, u32 fmt, const u16 *tlut, u32 tlut_fmt, u8 *rgba, u32 tlut_count) {
    if (tlut && fmt == TEX_CI4 && tlut_count >= 16 && (size_t)w * h >= 64)
        return decode_paletted<true>(s, w, h, tlut, tlut_fmt, rgba);
    if (tlut && fmt == TEX_CI8 && tlut_count >= 256 && (size_t)w * h >= 1024)
        return decode_paletted<false>(s, w, h, tlut, tlut_fmt, rgba);
    u32 bw, bh, bytes;
    block_of(fmt, bw, bh, bytes);
    for (u32 by = 0; by < h; by += bh) {
        for (u32 bx = 0; bx < w; bx += bw, s += bytes) {
            switch (fmt) {
                case TEX_I4:
                    for (u32 y = 0; y < 8; y++) {
                        for (u32 x = 0; x < 8; x++) {
                            u8 v = (x & 1) ? (s[y * 4 + x / 2] & 15) : (s[y * 4 + x / 2] >> 4);
                            v = (u8)(v * 17);
                            put(rgba, w, h, bx + x, by + y, v, v, v, v);
                        }
                    }
                    break;
                case TEX_I8:
                    for (u32 y = 0; y < 4; y++) {
                        for (u32 x = 0; x < 8; x++) {
                            u8 v = s[y * 8 + x];
                            put(rgba, w, h, bx + x, by + y, v, v, v, v);
                        }
                    }
                    break;
                case TEX_IA4:
                    for (u32 y = 0; y < 4; y++) {
                        for (u32 x = 0; x < 8; x++) {
                            u8 b = s[y * 8 + x], a = (u8)((b >> 4) * 17), i = (u8)((b & 15) * 17);
                            put(rgba, w, h, bx + x, by + y, i, i, i, a);
                        }
                    }
                    break;
                case TEX_IA8:
                    for (u32 y = 0; y < 4; y++) {
                        for (u32 x = 0; x < 4; x++) {
                            const u8 *p = s + (y * 4 + x) * 2;
                            put(rgba, w, h, bx + x, by + y, p[1], p[1], p[1], p[0]);
                        }
                    }
                    break;
                case TEX_RGB565:
                    for (u32 y = 0; y < 4; y++) {
                        for (u32 x = 0; x < 4; x++) {
                            u32 v = be16(s + (y * 4 + x) * 2);
                            put(rgba, w, h, bx + x, by + y, (u8)(((v >> 11) << 3) | (v >> 13)), (u8)((((v >> 5) & 63) << 2) | (((v >> 5) & 63) >> 4)), (u8)(((v & 31) << 3) | ((v & 31) >> 2)), 255);
                        }
                    }
                    break;
                case TEX_RGB5A3:
                    for (u32 y = 0; y < 4; y++) {
                        for (u32 x = 0; x < 4; x++) {
                            u32 v = be16(s + (y * 4 + x) * 2);
                            u8 c[4];
                            u16 t = (u16)v;
                            from_tlut(&t, TL_RGB5A3, 0, c);
                            put(rgba, w, h, bx + x, by + y, c[0], c[1], c[2], c[3]);
                        }
                    }
                    break;
                case TEX_RGBA8:
                    // Primero 32 B de pares AR, después 32 B de pares GB.
                    for (u32 y = 0; y < 4; y++) {
                        for (u32 x = 0; x < 4; x++) {
                            const u8 *ar = s + (y * 4 + x) * 2, *gb = s + 32 + (y * 4 + x) * 2;
                            put(rgba, w, h, bx + x, by + y, ar[1], gb[0], gb[1], ar[0]);
                        }
                    }
                    break;
                case TEX_CI4:
                    for (u32 y = 0; y < 8; y++) {
                        for (u32 x = 0; x < 8; x++) {
                            u32 v = (x & 1) ? (s[y * 4 + x / 2] & 15) : (s[y * 4 + x / 2] >> 4);
                            u8 c[4];
                            from_tlut(tlut, tlut_fmt, v, c);
                            put(rgba, w, h, bx + x, by + y, c[0], c[1], c[2], c[3]);
                        }
                    }
                    break;
                case TEX_CI8:
                    for (u32 y = 0; y < 4; y++) {
                        for (u32 x = 0; x < 8; x++) {
                            u8 c[4];
                            from_tlut(tlut, tlut_fmt, s[y * 8 + x], c);
                            put(rgba, w, h, bx + x, by + y, c[0], c[1], c[2], c[3]);
                        }
                    }
                    break;
                case TEX_CI14:
                    for (u32 y = 0; y < 4; y++) {
                        for (u32 x = 0; x < 4; x++) {
                            u8 c[4];
                            from_tlut(tlut, tlut_fmt, be16(s + (y * 4 + x) * 2) & 0x3fff, c);
                            put(rgba, w, h, bx + x, by + y, c[0], c[1], c[2], c[3]);
                        }
                    }
                    break;
                case TEX_CMPR:
                    for (u32 sub = 0; sub < 4; sub++) {
                        const u8 *b = s + sub * 8;
                        u32 c0 = be16(b), c1 = be16(b + 2);
                        u8 pal[4][4];
                        u32 r0 = ((c0 >> 11) << 3) | (c0 >> 13), g0 = (((c0 >> 5) & 63) << 2) | (((c0 >> 5) & 63) >> 4), b0 = ((c0 & 31) << 3) | ((c0 & 31) >> 2);
                        u32 r1 = ((c1 >> 11) << 3) | (c1 >> 13), g1 = (((c1 >> 5) & 63) << 2) | (((c1 >> 5) & 63) >> 4), b1 = ((c1 & 31) << 3) | ((c1 & 31) >> 2);
                        pal[0][0] = (u8)r0; pal[0][1] = (u8)g0; pal[0][2] = (u8)b0; pal[0][3] = 255;
                        pal[1][0] = (u8)r1; pal[1][1] = (u8)g1; pal[1][2] = (u8)b1; pal[1][3] = 255;
                        if (c0 > c1) {
                            // Mezcla 3/8-5/8 del hardware, como Dolphin.
                            pal[2][0] = (u8)((r1 * 3 + r0 * 5) >> 3); pal[2][1] = (u8)((g1 * 3 + g0 * 5) >> 3); pal[2][2] = (u8)((b1 * 3 + b0 * 5) >> 3); pal[2][3] = 255;
                            pal[3][0] = (u8)((r0 * 3 + r1 * 5) >> 3); pal[3][1] = (u8)((g0 * 3 + g1 * 5) >> 3); pal[3][2] = (u8)((b0 * 3 + b1 * 5) >> 3); pal[3][3] = 255;
                        } else {
                            pal[2][0] = (u8)((r0 + r1) / 2); pal[2][1] = (u8)((g0 + g1) / 2); pal[2][2] = (u8)((b0 + b1) / 2); pal[2][3] = 255;
                            pal[3][0] = pal[2][0]; pal[3][1] = pal[2][1]; pal[3][2] = pal[2][2]; pal[3][3] = 0;
                        }
                        u32 ox = bx + (sub & 1) * 4, oy = by + (sub >> 1) * 4;
                        for (u32 y = 0; y < 4; y++) {
                            u8 bits = b[4 + y];
                            for (u32 x = 0; x < 4; x++) {
                                const u8 *c = pal[(bits >> (6 - x * 2)) & 3];
                                put(rgba, w, h, ox + x, oy + y, c[0], c[1], c[2], c[3]);
                            }
                        }
                    }
                    break;
                default:
                    for (u32 y = 0; y < bh; y++) for (u32 x = 0; x < bw; x++) put(rgba, w, h, bx + x, by + y, 255, 0, 255, 255);
            }
        }
    }
}

// Hash rápido del contenido. Las texturas grandes se muestrean cada 8 líneas de caché: el juego las
// reescribe enteras (planos THP) o solo por objeto, nunca un trozo de 32 B aislado.
uint64_t tex_hash(const u8 *src, size_t bytes) {
    uint64_t h = 0xcbf29ce484222325ull ^ bytes;
    size_t step = bytes > 32768 ? 256 : 8;
    size_t i = 0;
    for (; i + 8 <= bytes; i += step) {
        uint64_t v;
        memcpy(&v, src + i, 8);
        h = (h ^ v) * 0x100000001b3ull;
        h ^= h >> 29;
    }
    for (i = bytes & ~(size_t)7; i < bytes; i++) h = (h ^ src[i]) * 0x100000001b3ull;
    return h;
}

namespace { TlutSlot *g_tlut; }
#ifdef __3DS__
namespace backend { bool range_clean_since(u32 a, u32 n, u32 since); u32 stamp_now(); }   // gx_pica.cpp
#endif

const TlutSlot &tlut_slot(u32 name) {
    if (!g_tlut) g_tlut = (TlutSlot *)calloc(TLUT_SLOTS, sizeof(TlutSlot));
    return g_tlut[name < TLUT_SLOTS ? name : 0];
}
const u16 *tlut_data(const TlutSlot &t) {
    if (!t.loaded && t.src && t.count) {
        TlutSlot &m = const_cast<TlutSlot &>(t);
        memcpy(m.entries, g2h(t.src), t.count * 2);
        m.loaded = true;
    }
    return t.entries;
}

#ifdef __3DS__
// Firma de las paletas ya vistas, por dirección (tlut_load).
struct Seen { u32 addr, n, stamp, uses; u8 fmt; uint64_t hash; };
Seen g_seen[512];
#endif
// v34: ¿la ranura ya tiene esta misma paleta? Misma dirección, tamaño y formato, y la firma conocida de esa dirección sin
// escrituras desde entonces (cada 64 usos se vuelve a calcular, como en tlut_load). Sin cambio, GXLoadTlut no hace nada.
bool tlut_same(const GTlutObj &o, u32 name) {
#ifdef __3DS__
    if (!g_tlut) return false;
    const TlutSlot &t = g_tlut[name < TLUT_SLOTS ? name : 0];
    u32 n = o.count > 16384 ? 16384 : o.count;
    if (t.src != o.lut || t.count != n || t.format != o.format) return false;
    Seen &c = g_seen[((o.lut >> 5) ^ (o.lut >> 14)) & 511];
    if (c.addr != o.lut || c.n != n || c.fmt != o.format || c.hash != t.hash || c.uses >= 64) return false;
    if (!backend::range_clean_since(o.lut, n * 2, c.stamp)) return false;
    c.uses++;
    return true;
#else
    (void)o; (void)name;
    return false;
#endif
}

void tlut_load(const GTlutObj &o, u32 name) {
#ifdef __3DS__
    // zones_3ds.cpp (v34): con 300-420 cargas por cuadro, el reloj solo con detalle
    struct ZoneGuard { bool on; ZoneGuard() : on(::g_detail != 0) { if (on) w3d_zone_begin(W3D_Z_TLUT); } ~ZoneGuard() { if (on) w3d_zone_end(W3D_Z_TLUT); } } zone_;
#endif
    tlut_slot(0);
    TlutSlot &t = g_tlut[name < TLUT_SLOTS ? name : 0];
    u32 n = o.count > 16384 ? 16384 : o.count;
#ifdef __3DS__
    // Firma de las paletas ya vistas, por dirección: si nadie ha vaciado sus páginas desde entonces, se copia la
    // paleta (512 B la de 256 colores) pero no se vuelve a calcular la firma, que es lo caro (1-1,5 ms por cuadro en
    // la consola con 150-300 cargas). El juego carga paletas distintas en la misma ranura, así que la caché no va
    // por ranura. Cada 64 usos se recalcula de todos modos, por si cambió sin DCFlushRange, como las texturas.
    // v34: con la firma ya conocida tampoco se copian los colores: solo hacen falta si hay que subir una textura con esta
    // paleta (tlut_data). Son 300-420 cargas por cuadro en partida (zona 10: 0,5-1 ms).
    Seen &c = g_seen[((o.lut >> 5) ^ (o.lut >> 14)) & 511];
    t.count = n;
    t.format = o.format;
    t.src = o.lut;
    if (c.addr == o.lut && c.n == n && c.fmt == o.format && c.uses < 64 && backend::range_clean_since(o.lut, n * 2, c.stamp)) { c.uses++; t.hash = c.hash; t.loaded = false; return; }
    memcpy(t.entries, g2h(o.lut), n * 2);
    t.loaded = true;
    c.addr = o.lut; c.n = n; c.fmt = o.format; c.uses = 0; c.stamp = backend::stamp_now();
    t.hash = tex_hash((const u8 *)t.entries, n * 2) ^ ((uint64_t)o.format << 56);
    c.hash = t.hash;
    return;
#endif
    memcpy(t.entries, g2h(o.lut), n * 2);
    t.count = n;
    t.format = o.format;
    t.hash = tex_hash((const u8 *)t.entries, n * 2) ^ ((uint64_t)o.format << 56);
}

}  // namespace gx
}  // namespace w3d
