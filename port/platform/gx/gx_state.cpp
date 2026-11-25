#if defined(__APPLE__)
#include <execinfo.h>
#endif
// Máquina de estado GX: FIFO, decodificación de vértices, lotes y censo.
#include "gx_internal.h"
#include "gx_mt.h"
#include "w3d_ptr.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#if defined(__3DS__)
#include "../3ds/zones_3ds.h"
#endif

namespace w3d {
namespace gx {

State g;
Census census;
static u32 census_frame;

#if defined(__3DS__)
u32 g_prims_culled, g_verts_culled;
unsigned long long g_decode_ticks;
#endif

namespace {

// Lote: primitivas consecutivas con el mismo estado se dibujan juntas. El juego emite una tira por GXBegin.
std::vector<u8> g_vb;
std::vector<u16> g_ib;
u32 g_batch_verts, g_batch_stride, g_batch_topology;
u16 g_batch_attrs;

// FIFO inmediata: bytes reales entre GXBegin y su último vértice.
// v36: búfer fijo con cursor (antes un std::vector con una inserción por cada componente de cada vértice).
u8 *g_fifo; u32 g_fifo_cap, g_fifo_n;
u32 g_prim, g_fmt, g_count, g_expect;
bool g_open;

// Lista en grabación: se escribe en el búfer del juego.
u8 *g_dl_base, *g_dl_cur, *g_dl_end;
bool g_dl_overflow, g_dl_warned;

inline u16 be16(const u8 *p) { return (u16)(p[0] << 8 | p[1]); }
inline u32 be32(const u8 *p) { return (u32)p[0] << 24 | (u32)p[1] << 16 | (u32)p[2] << 8 | p[3]; }
inline u16 rd16(const u8 *p) { u16 v; memcpy(&v, p, 2); return v; }
inline u32 rd32(const u8 *p) { u32 v; memcpy(&v, p, 4); return v; }

const u8 kCompSize[5] = {1, 1, 2, 2, 4};

inline float comp_fifo(const u8 *p, u32 type, float scale) {
    switch (type) {
        case 0: return p[0] * scale;
        case 1: return (s8)p[0] * scale;
        case 2: return be16(p) * scale;
        case 3: return (s16)be16(p) * scale;
        default: { u32 v = be32(p); float f; memcpy(&f, &v, 4); return f; }
    }
}
inline float comp_host(const u8 *p, u32 type, float scale) {
    switch (type) {
        case 0: return p[0] * scale;
        case 1: return (s8)p[0] * scale;
        case 2: return rd16(p) * scale;
        case 3: return (s16)rd16(p) * scale;
        default: { float f; memcpy(&f, p, 4); return f; }
    }
}

u32 elem_comps(u32 attr, const VtxAttr &a) {
    if (attr == VA_POS) return a.cnt == 0 ? 2 : 3;
    if (attr == VA_NRM || attr == VA_NBT) return a.cnt == 0 ? 3 : 9;
    if (attr >= VA_TEX0 && attr < VA_TEX0 + 8) return a.cnt == 0 ? 1 : 2;
    return 0;
}
u32 color_bytes(u32 type) {
    static const u8 t[6] = {2, 3, 4, 2, 3, 4};
    return t[type > 5 ? 5 : type];
}
u32 elem_bytes(u32 attr, const VtxAttr &a) {
    if (attr == VA_CLR0 || attr == VA_CLR1) return color_bytes(a.type);
    return elem_comps(attr, a) * kCompSize[a.type > 4 ? 4 : a.type];
}

// Bytes de un vértice en la FIFO con el VCD y el VAT actuales.
// v36: `s` es el estado del hilo que llama (gx_mt.h): el del juego en GXBegin, el del backend al recorrer una lista.
u32 stream_stride(u32 fmt, const State &s = g) {
    u32 n = 0;
    if (s.vcd[VA_PNMTX]) n++;
    for (int i = 0; i < 8; i++) if (s.vcd[VA_TEX0MTX + i]) n++;
    for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) {
        switch (s.vcd[a]) {
            case ATTR_DIRECT: n += elem_bytes(a, s.vat[fmt][a]); break;
            case ATTR_INDEX8: n += 1; break;
            case ATTR_INDEX16: n += 2; break;
        }
    }
    return n;
}

void read_color(const u8 *p, u32 type, bool fifo, u8 *o) {
    u32 v;
    switch (type) {
        case 0:  // RGB565
            v = fifo ? be16(p) : rd16(p);
            o[0] = (u8)(((v >> 11) << 3) | (v >> 13)); o[1] = (u8)((((v >> 5) & 63) << 2) | (((v >> 5) & 63) >> 4));
            o[2] = (u8)(((v & 31) << 3) | ((v & 31) >> 2)); o[3] = 255;
            break;
        case 1: o[0] = p[0]; o[1] = p[1]; o[2] = p[2]; o[3] = 255; break;
        case 2: o[0] = p[0]; o[1] = p[1]; o[2] = p[2]; o[3] = 255; break;
        case 3:  // RGBA4
            v = fifo ? be16(p) : rd16(p);
            o[0] = (u8)(((v >> 12) & 15) * 17); o[1] = (u8)(((v >> 8) & 15) * 17); o[2] = (u8)(((v >> 4) & 15) * 17); o[3] = (u8)((v & 15) * 17);
            break;
        case 4:  // RGBA6, 24 bits en orden de bytes.
            v = (u32)p[0] << 16 | (u32)p[1] << 8 | p[2];
            o[0] = (u8)(((v >> 18) & 63) * 255 / 63); o[1] = (u8)(((v >> 12) & 63) * 255 / 63); o[2] = (u8)(((v >> 6) & 63) * 255 / 63); o[3] = (u8)((v & 63) * 255 / 63);
            break;
        default: o[0] = p[0]; o[1] = p[1]; o[2] = p[2]; o[3] = p[3]; break;
    }
}

// Escala fija de las normales: el VAT de la consola no tiene frac para ellas.
inline float nrm_scale(u32 type) {
    switch (type) {
        case 0: return 1.f / 128.f;
        case 1: return 1.f / 64.f;
        case 2: return 1.f / 32768.f;
        case 3: return 1.f / 16384.f;
        default: return 1.f;
    }
}

u32 topology_of(u32 prim) {
    if (prim == PRIM_LINES || prim == PRIM_LINESTRIP) return TOPO_LINE;
    if (prim == PRIM_POINTS) return TOPO_POINT;
    return TOPO_TRI;
}

// Cuenta una primitiva de n vértices recién añadida al lote.
inline void batch_added(u32 n) {
    g_batch_verts += n;
    census.begins++;
    census.vertices += n;
    census.tev_stage_sum += g.num_stages;
    if (g.num_stages > census.tev_stage_max) census.tev_stage_max = g.num_stages;
    if (g.num_ind) census.ind_draws++;
    if (g.blend_type != 0) census.blend_draws++;
    if (!(g.cmp0 == 7 && g.cmp1 == 7)) census.alphatest_draws++;
    if (g.num_chans && (g.chan[0].enable || g.chan[2].enable)) {
        census.lit_draws++;
        u32 m = (u32)g.chan[0].mask | g.chan[2].mask | g.chan[1].mask | g.chan[3].mask, c = 0;
        for (; m; m >>= 1) c += m & 1;
        if (c > census.lights_max) census.lights_max = c;
    }
}

// Decodifica n vértices de la FIFO con el VCD y el VAT actuales y los añade al lote.
#if defined(__3DS__)
extern "C" unsigned long long svcGetSystemTick(void);
#endif

const u8 *decode_prim(u32 prim, u32 fmt, u32 n, const u8 *src) {
#if defined(__3DS__)
    unsigned long long t0_ = svcGetSystemTick();
    struct TickGuard { unsigned long long t; ~TickGuard() { g_decode_ticks += svcGetSystemTick() - t; } } guard_{t0_};
#endif
    u16 attrs = 1;
    if (g.vcd[VA_NRM]) attrs |= 2;
    if (g.vcd[VA_CLR0]) attrs |= 4;
    if (g.vcd[VA_CLR1]) attrs |= 8;
    for (int i = 0; i < 8; i++) if (g.vcd[VA_TEX0 + i]) attrs |= (u16)(16 << i);
    u32 stride = 12 + (attrs & 2 ? 12 : 0) + (attrs & 4 ? 4 : 0) + (attrs & 8 ? 4 : 0);
    for (int i = 0; i < 8; i++) if (attrs & (16 << i)) stride += 8;
    u32 topo = topology_of(prim);
    if (g_batch_verts && (g_batch_attrs != attrs || g_batch_topology != topo || g_batch_verts + n > 60000)) flush_batch();
    g_batch_attrs = attrs;
    g_batch_stride = stride;
    g_batch_topology = topo;
    size_t voff = g_vb.size();
    g_vb.resize(voff + (size_t)stride * n);
    u8 *out = g_vb.data() + voff;
    const VtxAttr *vat = g.vat[fmt];
    struct Input {
        const u8 *base;
        u32 attr, kind, type, offset, array_stride, component_bytes, components;
        float scale;
    };
    Input inputs[VA_TEX0 + 8 - VA_POS];
    u32 input_count = 0, wire_stride = g.vcd[VA_PNMTX] != 0;
    static bool warned;
    if (n && wire_stride && !warned) {
        warned = true;
        fprintf(stderr, "[gx] índices de matriz por vértice sin soporte: se ignoran\n");
    }
    for (int i = 0; i < 8; i++) wire_stride += g.vcd[VA_TEX0MTX + i] != 0;
    for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) {
        const u32 kind = g.vcd[a];
        if (!kind) continue;
        const VtxAttr &at = vat[a];
        Input &in = inputs[input_count++];
        in.base = (const u8 *)g2h(g.array_base[a]);
        in.attr = a;
        in.kind = kind;
        in.type = at.type;
        in.offset = wire_stride;
        in.array_stride = g.array_stride[a];
        in.component_bytes = kCompSize[at.type > 4 ? 4 : at.type];
        in.components = a == VA_NRM ? 3 : elem_comps(a, at);
        in.scale = 1.0f;
        if (a == VA_NRM) in.scale = nrm_scale(at.type);
        else if (in.components && at.type < 4) in.scale = 1.f / (float)(1u << at.frac);
        wire_stride += kind == ATTR_DIRECT ? elem_bytes(a, at) : kind == ATTR_INDEX8 ? 1 : 2;
    }
    for (u32 v = 0; v < n; v++, src += wire_stride) {
        for (u32 i = 0; i < input_count; i++) {
            const Input &in = inputs[i];
            const u8 *p = src + in.offset;
            const bool fifo = in.kind == ATTR_DIRECT;
            if (!fifo) {
                const u32 index = in.kind == ATTR_INDEX8 ? *p : be16(p);
                p = in.base + index * in.array_stride;
            }
            if (!in.components) {
                read_color(p, in.type, fifo, out);
                out += 4;
                continue;
            }
            const u32 bytes = in.attr >= VA_TEX0 ? 8 : 12;
            if (!fifo && in.type >= 4 && in.components * 4 == bytes) {
                memcpy(out, p, bytes);
            } else {
                float values[3] = {};
                for (u32 c = 0; c < in.components; c++, p += in.component_bytes)
                    values[c] = fifo ? comp_fifo(p, in.type, in.scale) : comp_host(p, in.type, in.scale);
                memcpy(out, values, bytes);
            }
            out += bytes;
        }
    }
    const u32 b = g_batch_verts;
    // Reservar el tramo completo evita una inserción de vector por triángulo.
    auto indices = [](u32 count) {
        const size_t start = g_ib.size();
        g_ib.resize(start + count);
        return count ? g_ib.data() + start : nullptr;
    };
    switch (prim) {
        case PRIM_QUADS: case PRIM_QUADS2: {
            u16 *ix = indices(n / 4 * 6);
            for (u32 i = 0; i + 3 < n; i += 4) {
                *ix++ = b + i; *ix++ = b + i + 1; *ix++ = b + i + 2;
                *ix++ = b + i; *ix++ = b + i + 2; *ix++ = b + i + 3;
            }
            census.triangles += n / 4 * 2;
            break;
        }
        case PRIM_TRIS: case PRIM_LINES: case PRIM_POINTS: {
            u16 *ix = indices(n);
            for (u32 i = 0; i < n; i++) ix[i] = b + i;
            if (prim == PRIM_TRIS) census.triangles += n / 3;
            break;
        }
        case PRIM_STRIP: case PRIM_FAN: {
            const u32 triangles = n > 2 ? n - 2 : 0;
            u16 *ix = indices(triangles * 3);
            for (u32 i = 0; i < triangles; i++) {
                if (prim == PRIM_FAN) { *ix++ = b; *ix++ = b + i + 1; }
                else { *ix++ = b + i + (i & 1); *ix++ = b + i + 1 - (i & 1); }
                *ix++ = b + i + 2;
            }
            census.triangles += triangles;
            break;
        }
        case PRIM_LINESTRIP: {
            u16 *ix = indices(n ? (n - 1) * 2 : 0);
            for (u32 i = 0; i + 1 < n; i++) { *ix++ = b + i; *ix++ = b + i + 1; }
            break;
        }
        default:
            fprintf(stderr, "[gx] primitiva desconocida 0x%02x\n", prim);
    }
    batch_added(n);
    return src;
}

#if defined(__3DS__)
}  // namespace
bool dl_resident(u32 guest, u32 size, u32 key);
namespace backend { extern bool g_touch_log_on; void touch_log_note(const void *ra); extern u32 g_list_dbg[6]; }   // gx_pica.cpp
namespace {
std::vector<u8> g_tmp_list;
#endif
// Primitiva inmediata completa (bytes de la FIFO): lista residente si es una malla por índices, o al lote.
void prim_done(u32 prim, u32 fmt, u32 count, const u8 *data, u32 bytes) {
#if defined(__3DS__)
    // Malla enviada como índices inmediatos: es una lista con otro nombre; su identidad es el hash del flujo.
    if (count >= 24 && (prim == PRIM_TRIS || prim == PRIM_STRIP || prim == PRIM_FAN || prim == PRIM_QUADS || prim == PRIM_QUADS2)) {
        bool all = !g.vcd[VA_PNMTX];
        for (u32 a = VA_POS; a < VA_TEX0 + 8 && all; a++) if (g.vcd[a] == ATTR_DIRECT) all = false;
        if (all) {
            g_tmp_list.resize(bytes + 3);
            g_tmp_list[0] = (u8)(prim | fmt); g_tmp_list[1] = (u8)(count >> 8); g_tmp_list[2] = (u8)count;
            memcpy(g_tmp_list.data() + 3, data, bytes);
            u32 h = 2166136261u ^ count;
            const u8 *q = g_tmp_list.data(); u32 m = (u32)g_tmp_list.size();
            for (u32 i = 0; i + 4 <= m; i += 4) { u32 w; memcpy(&w, q + i, 4); h = (h ^ w) * 16777619u; }
            flush_batch();
            if (dl_resident(h2g(q), m, h | 1)) return;
        }
    }
#else
    (void)bytes;
#endif
    decode_prim(prim, fmt, count, data);
}

#if defined(__3DS__)
// --- v37: caminos nativos de la capa XGX (gx_internal.h) ---
// Hilo que ejecuta: cuadrados que llegan ya en el formato del lote. layout 0: posición, RGBA8 y uv (24 B); 1: posición y uv (20 B).
void raw_quads(u32 layout, u32 n, const u8 *src) {
    unsigned long long t0_ = svcGetSystemTick();
    struct TickGuard { unsigned long long t; ~TickGuard() { g_decode_ticks += svcGetSystemTick() - t; } } guard_{t0_};
    const u16 attrs = layout == 0 ? (u16)(1 | 4 | 16) : (u16)(1 | 16);
    const u32 stride = layout == 0 ? 24 : 20;
    if (g_batch_verts && (g_batch_attrs != attrs || g_batch_topology != TOPO_TRI || g_batch_verts + n > 60000)) flush_batch();
    g_batch_attrs = attrs;
    g_batch_stride = stride;
    g_batch_topology = TOPO_TRI;
    if (n) g_vb.insert(g_vb.end(), src, src + (size_t)stride * n);
    const u32 b = g_batch_verts, quads = n / 4;
    const size_t ioff = g_ib.size();
    g_ib.resize(ioff + (size_t)quads * 6);
    u16 *ix = g_ib.data() + ioff;
    for (u32 i = 0; i < quads; i++, ix += 6) {
        const u16 v = (u16)(b + i * 4);
        ix[0] = v; ix[1] = (u16)(v + 1); ix[2] = (u16)(v + 2); ix[3] = v; ix[4] = (u16)(v + 2); ix[5] = (u16)(v + 3);
    }
    census.triangles += quads * 2;
    batch_added(n);
}

// Identidad de una malla por índices: hash de sus índices tal como están en la memoria del juego. La calcula el hilo
// del juego al dibujar, y el que ejecuta al construir el flujo desde esa memoria (para saber que no ha cambiado).
u32 mesh_key(const MeshSrc &s, u32 count, u32 prim, u32 fmt) {
    u32 h = (2166136261u ^ count ^ prim << 16 ^ fmt << 24 ^ s.n << 28) * 16777619u;
    for (u32 j = 0; j < s.n; j++) {
        h = (h ^ s.isz[j]) * 16777619u;
        if (!s.ptr[j]) { h = (h ^ 0x5e9u) * 16777619u; continue; }
        if (j && s.ptr[j] == s.ptr[j - 1] && s.isz[j] == s.isz[j - 1]) { h = (h ^ 0x51au) * 16777619u; continue; }   // el mismo flujo otra vez
        const u8 *p = (const u8 *)g2h(s.ptr[j]);
        const u32 n = count * s.isz[j];
        u32 i = 0;
        for (; i + 4 <= n; i += 4) { u32 w; memcpy(&w, p + i, 4); h = (h ^ w) * 16777619u; }
        for (; i < n; i++) h = (h ^ p[i]) * 16777619u;
    }
    return h | 1;
}
// Los bytes que el juego habría escrito en la FIFO: por vértice, un índice de cada flujo, en big-endian.
void mesh_stream(const MeshSrc &s, u32 count, u8 *d) {
    const u8 *p[4];
    for (u32 j = 0; j < s.n; j++) p[j] = s.ptr[j] ? (const u8 *)g2h(s.ptr[j]) : nullptr;
    for (u32 i = 0; i < count; i++)
        for (u32 j = 0; j < s.n; j++) {
            if (!p[j]) { *d++ = (u8)(i >> 8); *d++ = (u8)i; }
            else if (s.isz[j] == 1) *d++ = p[j][i];
            else { const u16 v = rd16(p[j] + i * 2); *d++ = (u8)(v >> 8); *d++ = (u8)v; }
        }
}

// La lista equivalente a la malla (orden de primitiva y flujo) solo se construye si hace falta: cuando la malla no
// está residente o va por el anillo.
struct MeshLazy { u32 prim, fmt, count, key, bytes; const MeshSrc *src; const u8 *stream; bool done, ok; };
MeshLazy *g_lazy;
volatile u32 g_mesh_gen;        // sube si la memoria del juego ya no era la de la identidad: el hilo del juego olvida lo visto
u32 g_mesh_dropped;
const u8 *lazy_list(MeshLazy &z) {
    if (z.done) return z.ok ? g_tmp_list.data() : nullptr;
    z.done = true;
    g_tmp_list.resize(z.bytes + 3);
    u8 *d = g_tmp_list.data();
    d[0] = (u8)(z.prim | z.fmt); d[1] = (u8)(z.count >> 8); d[2] = (u8)z.count;
    if (z.stream) memcpy(d + 3, z.stream, z.bytes);
    else {
        mesh_stream(*z.src, z.count, d + 3);
        if (mesh_key(*z.src, z.count, z.prim, z.fmt) != z.key) {
            g_mesh_gen = g_mesh_gen + 1;
            if (!g_mesh_dropped++) fprintf(stderr, "[gx] malla por identidad: los índices cambiaron antes de dibujarla; se salta este cuadro\n");
            return nullptr;
        }
    }
    z.ok = true;
    return d;
}
void mesh_exec(u32 prim, u32 fmt, u32 count, u32 key, const MeshSrc *src, const u8 *stream) {
    flush_batch();
    MeshLazy z{prim, fmt, count, key, stream_stride(fmt) * count, src, stream, false, false};
    g_lazy = &z;
    const bool drawn = dl_resident(0, z.bytes + 3, key);
    g_lazy = nullptr;
    if (drawn) return;
    const u8 *q = lazy_list(z);
    if (q) decode_prim(prim, fmt, count, q + 3);
}

// Hilo del juego: mallas ya vistas (su flujo ya se envió una vez con esta identidad).
u32 g_seen[2048], g_seen_n, g_seen_gen;
bool seen_test_add(u32 key) {
    if (g_seen_gen != g_mesh_gen || g_seen_n > 1400) { memset(g_seen, 0, sizeof g_seen); g_seen_n = 0; g_seen_gen = g_mesh_gen; }
    const u32 h = (key * 2654435761u) >> 21;
    for (u32 k = 0; k < 8; k++) {
        u32 &e = g_seen[(h + k) & 2047];
        if (e == key) return true;
        if (!e) { e = key; g_seen_n++; return false; }
    }
    g_seen[h] = key;
    return false;
}
u32 g_native = ~0u;
inline u32 native_bits() {
    if (g_native == ~0u) { const char *e = getenv("W3D_GX_NATIVE"); g_native = e ? (u32)atoi(e) : 15; }
    return g_native;
}
// Solo los atributos de `direct` van directos y no hay ningún otro.
inline bool vcd_is(const State &s, u32 direct) {
    if (s.vcd[VA_PNMTX]) return false;
    for (u32 a = VA_TEX0MTX; a < VA_TEX0 + 8; a++) if (s.vcd[a] != ((direct >> a & 1) ? ATTR_DIRECT : ATTR_NONE)) return false;
    return true;
}
inline void raw_send(u32 layout, u32 count, const u8 *data, u32 bytes) {
    g_open = false;
    g_fifo_n = 0;
    if (mt::on) mt::prim(PRIM_QUADS, 0x80 | layout, count, data, bytes);
    else raw_quads(layout, count, data);
}
#endif

void fifo_push(const u8 *p, u32 n) {
    if (g_dl_base) {
        if (g_dl_cur + n > g_dl_end) { g_dl_overflow = true; return; }
        memcpy(g_dl_cur, p, n);
        g_dl_cur += n;
        return;
    }
    if (!g_open) {
        static bool warned;
        if (!warned) { warned = true; fprintf(stderr, "[gx] escritura en la FIFO fuera de GXBegin\n"); }
        return;
    }
    if (n > g_expect - g_fifo_n) n = g_expect - g_fifo_n;   // lo que pase de la primitiva no se usa
    u8 *d = g_fifo + g_fifo_n;
    if (n == 4) memcpy(d, p, 4); else if (n == 2) memcpy(d, p, 2); else if (n == 1) *d = *p; else memcpy(d, p, n);
    g_fifo_n += n;
    if (g_fifo_n >= g_expect) {
        g_open = false;
        // v36: con la cola activa, la primitiva entera va al otro núcleo (gx_mt.h).
        if (mt::on) mt::prim(g_prim, g_fmt, g_count, g_fifo, g_fifo_n);
        else prim_done(g_prim, g_fmt, g_count, g_fifo, g_fifo_n);
        g_fifo_n = 0;
    }
}

}  // namespace

#if defined(__3DS__)

bool fifo_mesh(const MeshSrc &s, u32 count) {
    if (!(native_bits() & 1) || g_dl_base || !g_open || g_fifo_n || g_count != count || count < 24 || !s.n) return false;
    if (g_prim != PRIM_TRIS && g_prim != PRIM_STRIP && g_prim != PRIM_FAN && g_prim != PRIM_QUADS && g_prim != PRIM_QUADS2) return false;
    const State &st = *mt::front;
    if (st.vcd[VA_PNMTX]) return false;
    for (int i = 0; i < 8; i++) if (st.vcd[VA_TEX0MTX + i]) return false;
    u32 j = 0, bytes = 0;
    for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) {
        const u32 kind = st.vcd[a];
        if (!kind) continue;
        if (j >= s.n || kind != (s.isz[j] == 1 ? (u32)ATTR_INDEX8 : (u32)ATTR_INDEX16)) return false;
        bytes += s.isz[j++];
    }
    if (j != s.n || g_expect != bytes * count) return false;
    const u32 key = mesh_key(s, count, g_prim, g_fmt);
    g_open = false;
    if (!mt::on) { mesh_exec(g_prim, g_fmt, count, key, &s, nullptr); return true; }
    if (seen_test_add(key)) mt::mesh(g_prim, g_fmt, count, key, s, nullptr, 0);
    else { mesh_stream(s, count, g_fifo); mt::mesh(g_prim, g_fmt, count, key, s, g_fifo, g_expect); }
    return true;
}
u8 *quads_begin(u32 count) {
    if (!(native_bits() & 2) || g_dl_base || !g_open || g_fifo_n || g_prim != PRIM_QUADS || g_count != count) return nullptr;
    const State &st = *mt::front;
    if (!vcd_is(st, 1u << VA_POS | 1u << VA_CLR0 | 1u << VA_TEX0)) return nullptr;
    const VtxAttr *v = st.vat[g_fmt];
    if (v[VA_POS].type != 4 || v[VA_POS].cnt != 1 || v[VA_CLR0].type != 5 || v[VA_TEX0].type != 4 || v[VA_TEX0].cnt != 1) return nullptr;
    if (g_expect != count * 24) return nullptr;
    return g_fifo;
}
void quads_end() { raw_send(0, g_count, g_fifo, g_expect); }
bool quad_s16(const s16 *q) {
    if (!(native_bits() & 4) || g_dl_base || !g_open || g_fifo_n || g_prim != PRIM_QUADS || g_count != 4 || g_expect != 40) return false;
    const State &st = *mt::front;
    if (!vcd_is(st, 1u << VA_POS | 1u << VA_TEX0)) return false;
    const VtxAttr *v = st.vat[g_fmt];
    if (v[VA_POS].type != 3 || v[VA_POS].cnt != 1 || v[VA_TEX0].type != 3 || v[VA_TEX0].cnt != 1) return false;
    const float ps = 1.f / (float)(1u << v[VA_POS].frac), ts = 1.f / (float)(1u << v[VA_TEX0].frac);
    float o[20];
    for (int i = 0; i < 4; i++) {
        o[i * 5] = q[i * 5] * ps; o[i * 5 + 1] = q[i * 5 + 1] * ps; o[i * 5 + 2] = q[i * 5 + 2] * ps;
        o[i * 5 + 3] = q[i * 5 + 3] * ts; o[i * 5 + 4] = q[i * 5 + 4] * ts;
    }
    raw_send(1, 4, (const u8 *)o, sizeof o);
    return true;
}
#endif
u32 g_state_gen = 1;
void dl_call_now(u32 guest, u32 size);
__attribute__((noinline)) void touch() {
#if defined(__3DS__)
    void *volatile ra = __builtin_return_address(0);
    if (__builtin_expect(backend::g_touch_log_on, 0)) backend::touch_log_note(ra);
#endif
    if (g_batch_verts) flush_batch();
    census.state_changes++;
    g_state_gen++;
    if (g_dl_base && !g_dl_warned) {
        g_dl_warned = true;
        fprintf(stderr, "[gx] cambio de estado dentro de una lista: se aplica al momento, no al llamarla\n");
    }
}
__attribute__((noinline)) void touch_keep() {
#if defined(__3DS__)
    void *volatile ra = __builtin_return_address(0);
    if (__builtin_expect(backend::g_touch_log_on, 0)) backend::touch_log_note(ra);
#endif
    if (g_batch_verts) flush_batch();
    census.state_changes++;
    if (g_dl_base && !g_dl_warned) {
        g_dl_warned = true;
        fprintf(stderr, "[gx] cambio de estado dentro de una lista: se aplica al momento, no al llamarla\n");
    }
}

// v36: desde el hilo del juego (GXDrawDone, cambio de cámara): a la cola si está activa.
void flush_any() { if (mt::on) mt::flush(); else flush_batch(); }

void flush_batch() {
    if (!g_batch_verts) return;
    // W3D_MTX_LOG=<cuadro>: proyección y matriz de cada dibujo en perspectiva, para comparar plataformas.
    { static const char *ml = getenv("W3D_MTX_LOG");
      if (ml && census_frame >= (u32)atoi(ml) && census_frame < (u32)atoi(ml) + 2 && g.proj_type == 0) {
        const float *m = g.xf + g.cur_pos * 4, *v = (const float *)g_vb.data();
        fprintf(stderr, "[mtx] f%u d%u n=%u cull=%u P %.3f %.3f %.3f %.3f %.3f %.3f M %.3f %.3f %.3f %.2f / %.3f %.3f %.3f %.2f / %.3f %.3f %.3f %.2f v0 %.1f %.1f %.1f vp %.0f,%.0f,%.0f,%.0f z%.2f-%.2f sc %u,%u,%u,%u zt %u,%u,%u bl %u,%u,%u col %u\n", census_frame, census.draws, g_batch_verts, g.cull, g.proj[0], g.proj[1], g.proj[2], g.proj[3], g.proj[4], g.proj[5], m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10], m[11], v[0], v[1], v[2], g.vp[0], g.vp[1], g.vp[2], g.vp[3], g.vp[4], g.vp[5], g.scissor[0], g.scissor[1], g.scissor[2], g.scissor[3], g.z_enable, g.z_func, g.z_update, g.blend_type, g.blend_src, g.blend_dst, g.color_update);
      } }
#if defined(__3DS__)
    // PICA200: sin claves de tubería ni uniformes genéricos, el backend lee el estado directamente.
    backend::draw3ds(g_vb.data(), g_batch_verts, g_batch_stride, g_batch_attrs, g_ib.data(), (u32)g_ib.size(), g_batch_topology);
    census.draws++;
    g_vb.clear();
    g_ib.clear();
    g_batch_verts = 0;
    return;
#endif
    PipelineKey k;
    build_pipeline_key(k, g_batch_topology, g_batch_attrs);
    VsUniforms vu;
    FsUniforms fu;
    // Lienzo alto (Mac a dos pantallas, menús): solo los dibujos a pantalla completa siguen hacia abajo.
    g_tall_proj = g_tall_frame && g.vp[0] <= 0.5f && g.vp[1] <= 0.5f && g.vp[2] >= 639.f && g.vp[3] >= 400.f;   // PAL: 640x454
    build_vs_uniforms(vu);
    build_fs_uniforms(fu);
    // W3D_GX_TRACE=<cuadro>: lista de dibujos de ese cuadro, para comparar con lo que debería verse.
    static const char *trace = getenv("W3D_GX_TRACE");
    if (trace && census_frame == (u32)atoi(trace)) {
        const float *f = (const float *)g_vb.data();
        #if defined(__APPLE__)
        if (census.draws == 0 || census.draws == 1 || census.draws == 12 || census.draws == 20) { void *bt[24]; int nb = backtrace(bt, 24); backtrace_symbols_fd(bt, nb, 2); }
#endif
        fprintf(stderr, "[prim] %x ib=%zu\n", g_prim, g_ib.size() / 2);
        fprintf(stderr, "[draw] v=%u stride=%u top=%u blend=%u/%u/%u cmp=%u,%u stages=%u tex=%ux%u fmt=%u img=%x zm=%u vp=%.0f,%.0f,%.0f,%.0f sc=%u,%u,%u,%u pos=%.2f,%.2f,%.2f proj=%u %.3f %.3f\n",
                g_batch_verts, g_batch_stride, g_batch_topology, g.blend_type, g.blend_src, g.blend_dst, g.cmp0, g.cmp1, g.num_stages,
                g.map[0].width, g.map[0].height, g.map[0].format, g.map[0].image, 0, 0.f, 0.f, 0.f, 0.f, g.scissor[0], g.scissor[1], g.scissor[2], g.scissor[3], f[0], f[1], f[2], g.proj_type, g.proj[0], g.proj[2]);
        {
            for (u32 i = 0; i < (g_batch_verts == 54 ? 54u : 4u) && i < g_batch_verts; i++) { const float *q = (const float *)(g_vb.data() + i * g_batch_stride); fprintf(stderr, "   v%u pos %.1f,%.1f,%.1f uv %.3f,%.3f\n", i, q[0], q[1], q[2], q[g_batch_stride / 4 - 2], q[g_batch_stride / 4 - 1]); }
            fprintf(stderr, "   texmtx %.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f\n", vu.texmtx[0][0], vu.texmtx[0][1], vu.texmtx[0][2], vu.texmtx[0][3], vu.texmtx[0][4], vu.texmtx[0][5], vu.texmtx[0][6], vu.texmtx[0][7]);
            const auto &t0 = k.fs.s[0];
            fprintf(stderr, "   tev c=%u,%u,%u,%u a=%u,%u,%u,%u tex=%u ras=%u uv=%u cmpop=%u z=%u,%u,%u cull=%u chans=%u texgens=%u ch0 mat=%u amb=%u en=%u\n", t0.ca, t0.cb, t0.cc, t0.cd, t0.aa, t0.ab, t0.ac, t0.ad, t0.tex, t0.ras, t0.uv, g.cmp_op, g.z_enable, g.z_func, g.z_update, g.cull, k.vs.num_chans, k.vs.num_texgens, k.vs.ch[0].mat_src, k.vs.ch[0].amb_src, k.vs.ch[0].enable);
            const u8 *v = g_vb.data() + 12; const u8 *im = (const u8 *)w3d::g2h(g.map[0].image);
            const TlutSlot &ts = tlut_slot(g.map[0].tlut);
            fprintf(stderr, "   color %02x %02x %02x %02x ref=%u,%u tev_reg0=%d,%d,%d,%d pix %02x %02x %02x %02x tlut=%u fmt=%u e0=%04x e1=%04x e2=%04x\n", v[0], v[1], v[2], v[3], g.ref0, g.ref1, fu.reg[0][0], fu.reg[0][1], fu.reg[0][2], fu.reg[0][3], im ? im[0] : 0, im ? im[1] : 0, im ? im[2] : 0, im ? im[3] : 0, g.map[0].tlut, ts.format, ts.entries[im ? im[0] : 0], ts.entries[1], ts.entries[255]);
        }
        float mn[3] = {1e9f, 1e9f, 1e9f}, mx[3] = {-1e9f, -1e9f, -1e9f}; int behind = 0;
        for (u32 i = 0; i < g_batch_verts; i++) {
            const float *q = (const float *)(g_vb.data() + i * g_batch_stride);
            float v[4] = {q[0], q[1], q[2], 1}, e[3];
            for (int r = 0; r < 3; r++) e[r] = vu.posmtx[r * 4] * v[0] + vu.posmtx[r * 4 + 1] * v[1] + vu.posmtx[r * 4 + 2] * v[2] + vu.posmtx[r * 4 + 3];
            float c[4];
            for (int r = 0; r < 4; r++) c[r] = vu.proj[r * 4] * e[0] + vu.proj[r * 4 + 1] * e[1] + vu.proj[r * 4 + 2] * e[2] + vu.proj[r * 4 + 3];
            if (c[3] <= 0.0001f && g.proj_type == 0) { behind++; continue; }
            float w = c[3] ? c[3] : 1;
            for (int r = 0; r < 3; r++) { float n = c[r] / w; if (n < mn[r]) mn[r] = n; if (n > mx[r]) mx[r] = n; }
        }
        fprintf(stderr, "   ndc x %.2f..%.2f y %.2f..%.2f z %.3f..%.3f detras=%d\n", mn[0], mx[0], mn[1], mx[1], mn[2], mx[2], behind);
    }
    // W3D_GX_ONLY=<a>-<b>: solo esos dibujos de cada cuadro, para aislar quién pinta qué.
    static const char *cycle = getenv("W3D_GX_CYCLE");
    if (cycle && census_frame > 300) {
        // W3D_GX_CYCLE=<cuadros>: desde el cuadro 300, un solo dibujo cada vez, avanzando cada tantos cuadros.
        int want = (census_frame - 300) / atoi(cycle);
        if ((int)census.draws != want) { census.draws++; g_vb.clear(); g_ib.clear(); g_batch_verts = 0; return; }
    }
    static const char *only = getenv("W3D_GX_ONLY");
    if (only) {
        int lo = atoi(only), hi = lo; if (const char *c = strchr(only, '-')) hi = atoi(c + 1);
        if ((int)census.draws < lo || (int)census.draws > hi) { census.draws++; g_vb.clear(); g_ib.clear(); g_batch_verts = 0; return; }
    }
    backend::draw(k, vu, fu, g_vb.data(), (u32)g_vb.size(), g_batch_stride, g_ib.data(), (u32)g_ib.size(), g_batch_topology);
    census.draws++;
    g_vb.clear();
    g_ib.clear();
    g_batch_verts = 0;
}

void begin(u32 prim, u32 fmt, u32 count) {
    prim &= 0xff;
    fmt &= 7;
    count &= 0xffff;
    if (g_dl_base) {
        u8 hdr[3] = {(u8)(prim | fmt), (u8)(count >> 8), (u8)count};
        fifo_push(hdr, 3);
        return;
    }
    if (g_open) {
        static bool warned;
        if (!warned) { warned = true; fprintf(stderr, "[gx] GXBegin con la primitiva anterior incompleta: faltan %u B\n", g_expect - g_fifo_n); }
    }
    g_fifo_n = 0;
    g_prim = prim;
    g_fmt = fmt;
    g_count = count;
    g_expect = stream_stride(fmt, *mt::front) * count;
    if (g_expect > g_fifo_cap) {
        g_fifo_cap = g_expect < 4096 ? 4096 : g_expect + g_expect / 2;
        g_fifo = (u8 *)realloc(g_fifo, g_fifo_cap);
        if (!g_fifo) { g_fifo_cap = 0; g_expect = 0; fprintf(stderr, "[gx] sin memoria para la FIFO\n"); }
    }
    g_open = g_expect != 0;
}

void fifo_u8(u8 v) { fifo_push(&v, 1); }
void fifo_u16(u16 v) { u8 b[2] = {(u8)(v >> 8), (u8)v}; fifo_push(b, 2); }
void fifo_u32(u32 v) { u8 b[4] = {(u8)(v >> 24), (u8)(v >> 16), (u8)(v >> 8), (u8)v}; fifo_push(b, 4); }
void fifo_f32(float f) { u32 v; memcpy(&v, &f, 4); fifo_u32(v); }
void fifo_bytes(const void *p, u32 n) { fifo_push((const u8 *)p, n); }

void dl_begin(u32 guest, u32 size) {
    if (mt::on) mt::flush(); else flush_batch();
    g_dl_base = g_dl_cur = (u8 *)g2h(guest);
    g_dl_end = g_dl_base + size;
    g_dl_overflow = false;
}

bool dl_recording() { return g_dl_base != nullptr; }

u32 dl_end() {
    // Relleno con NOP hasta 32 B, como GXEndDisplayList.
    while (((uintptr_t)(g_dl_cur - g_dl_base) & 31) && g_dl_cur < g_dl_end) *g_dl_cur++ = 0;
    u32 n = g_dl_overflow ? 0 : (u32)(g_dl_cur - g_dl_base);
    g_dl_base = g_dl_cur = g_dl_end = nullptr;
    return n;
}

#if defined(__3DS__)
// Dibuja una lista desde su geometría residente. key: identidad de la lista (la dirección, o el hash de un flujo inmediato).
bool dl_resident(u32 guest, u32 size, u32 key) {
    {
        // Geometría residente: el contenido se comprueba con un hash de la lista y de los tramos de array que usa.
        flush_batch();
        u16 attrs0 = 1;
        if (g.vcd[VA_NRM]) attrs0 |= 2; if (g.vcd[VA_CLR0]) attrs0 |= 4; if (g.vcd[VA_CLR1]) attrs0 |= 8;
        for (int i = 0; i < 8; i++) if (g.vcd[VA_TEX0 + i]) attrs0 |= (u16)(16 << i);
        u32 bases = 2166136261u;
        for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) if (g.vcd[a]) bases = (bases ^ g.array_base[a] ^ (u32)g.vcd[a] << 24 ^ (u32)g.array_stride[a] << 16) * 16777619u;
        for (int f = 0; f < 8; f++) bases = (bases ^ g.vat[f][VA_POS].frac ^ (u32)g.vat[f][VA_TEX0].frac << 8 ^ (u32)g.vat[f][VA_POS].type << 16 ^ (u32)g.vat[f][VA_TEX0].type << 20) * 16777619u;
        if (backend::list_try_fast(key, size, attrs0, bases)) return true;
        u32 bases2 = 2166136261u;
        for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) if (g.vcd[a]) { bases2 = (bases2 ^ (a == VA_POS || a == VA_NRM ? 0 : g.array_base[a]) ^ (u32)g.vcd[a] << 24 ^ (u32)g.array_stride[a] << 16) * 16777619u; }
        for (int f = 0; f < 8; f++) bases2 = (bases2 ^ g.vat[f][VA_POS].type ^ (u32)g.vat[f][VA_TEX0].frac << 8 ^ (u32)g.vat[f][VA_TEX0].type << 20) * 16777619u;
        if (backend::list_try_dyn(key, size, attrs0, bases2)) return true;
        if (backend::list_vol_skip(key, size, attrs0, bases)) return false;   // v34: cambia en cada cuadro: al anillo sin firma
        // v37: malla por identidad: ahora sí hace falta su lista. Si la memoria del juego ya cambió, no se dibuja.
        if (g_lazy) { const u8 *q = lazy_list(*g_lazy); if (!q) return true; guest = h2g(q); }
        // Vía lenta: recorrer la lista y calcular el hash de sus arrays (zona 17, v23, solo medida). Termina antes de
        // list_try, que en un acierto dibuja (eso es tiempo de dibujo), o al salir si la lista no se puede guardar.
        struct SlowZone { bool on = true; SlowZone() { w3d_zone_begin(W3D_Z_DL_SLOW); } void end() { if (on) { w3d_zone_end(W3D_Z_DL_SLOW); on = false; } } ~SlowZone() { end(); } } slow_zone_;
        const u8 *lp = (const u8 *)g2h(guest), *le = lp + size;
        u32 maxi[VA_COUNT]; memset(maxi, 0, sizeof maxi);
        bool ok = true;
        { const u8 *q = lp;
          while (q < le && ok) {
              u8 cmd = *q++; if (!cmd) continue;
              u32 fmt_ = cmd & 7, pr = cmd & 0xf8;
              if (pr < PRIM_QUADS || pr > PRIM_POINTS || q + 2 > le) { ok = false; break; }
              u32 n_ = be16(q); q += 2;
              for (u32 v = 0; v < n_ && ok; v++) {
                  if (g.vcd[VA_PNMTX]) { ok = false; break; }
                  for (int i = 0; i < 8; i++) if (g.vcd[VA_TEX0MTX + i]) ok = false;
                  for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) {
                      u32 kind = g.vcd[a]; if (!kind) continue;
                      if (kind == ATTR_DIRECT) q += elem_bytes(a, g.vat[fmt_][a]);
                      else { u32 idx = kind == ATTR_INDEX8 ? *q : be16(q); q += kind == ATTR_INDEX8 ? 1 : 2; if (idx > maxi[a]) maxi[a] = idx; }
                  }
              }
              if (pr != PRIM_TRIS && pr != PRIM_STRIP && pr != PRIM_FAN && pr != PRIM_QUADS && pr != PRIM_QUADS2) ok = false;
          } }
        if (ok) {
            u32 h = 2166136261u ^ size;
            auto mix = [&](const u8 *p, u32 n) { for (u32 i = 0; i + 4 <= n; i += 4) { u32 w; memcpy(&w, p + i, 4); h = (h ^ w) * 16777619u; } };
            mix(lp, size);
            int dbg_n = 0; backend::g_list_dbg[dbg_n++] = h;   // W3D_LIST_LOG: firma tras la lista y tras cada array
            u16 attrs = 1;
            if (g.vcd[VA_NRM]) attrs |= 2; if (g.vcd[VA_CLR0]) attrs |= 4; if (g.vcd[VA_CLR1]) attrs |= 8;
            for (int i = 0; i < 8; i++) if (g.vcd[VA_TEX0 + i]) attrs |= (u16)(16 << i);
            for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) if (g.vcd[a] > ATTR_DIRECT) {
                h = (h ^ g.array_base[a]) * 16777619u;
                mix((const u8 *)g2h(g.array_base[a]), (maxi[a] + 1) * g.array_stride[a]);
                if (dbg_n < 6) backend::g_list_dbg[dbg_n++] = h;
            }
            while (dbg_n < 6) backend::g_list_dbg[dbg_n++] = 0;
            for (int f = 0; f < 8; f++) h = (h ^ g.vat[f][VA_POS].frac ^ (u32)g.vat[f][VA_TEX0].frac << 8 ^ (u32)g.vat[f][VA_POS].type << 16) * 16777619u;
            { u32 st[VA_COUNT + 1], by[VA_COUNT + 1]; int nr = 0; st[nr] = key == guest ? guest : 0; by[nr++] = key == guest ? size : 0;
              for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) if (g.vcd[a] > ATTR_DIRECT) { st[nr] = g.array_base[a]; by[nr++] = (maxi[a] + 1) * g.array_stride[a]; }
              backend::list_set_ranges(st, by, nr, bases); }
            slow_zone_.end();
            if (backend::list_try(key, size, attrs, h)) return true;
            // Pasa a malla con piel: mapa de índices de posición y normal, en el orden en que se decodifica.
            if (backend::list_wants_maps() && g.vcd[VA_POS] > ATTR_DIRECT && (!g.vcd[VA_NRM] || g.vcd[VA_NRM] > ATTR_DIRECT)) {
                static std::vector<u16> pm, nm; pm.clear(); nm.clear();
                bool good = true;
                for (int f = 0; f < 8; f++) (void)f;
                const u8 *q = lp;
                while (q < le && good) {
                    u8 cmd = *q++; if (!cmd) continue;
                    u32 fmt_ = cmd & 7, n_ = be16(q); q += 2;
                    if (g.vat[fmt_][VA_POS].type != 4 || g.vat[fmt_][VA_POS].cnt != 1 || (g.vcd[VA_NRM] && g.vat[fmt_][VA_NRM].type != 4) || g.array_stride[VA_POS] != 12 || (g.vcd[VA_NRM] && g.array_stride[VA_NRM] != 12)) { good = false; break; }
                    for (u32 v = 0; v < n_; v++) for (u32 a = VA_POS; a < VA_TEX0 + 8; a++) {
                        u32 kind = g.vcd[a]; if (!kind) continue;
                        if (kind == ATTR_DIRECT) { q += elem_bytes(a, g.vat[fmt_][a]); continue; }
                        u32 idx = kind == ATTR_INDEX8 ? *q : be16(q); q += kind == ATTR_INDEX8 ? 1 : 2;
                        if (a == VA_POS) pm.push_back((u16)idx); else if (a == VA_NRM) nm.push_back((u16)idx);
                    }
                }
                if (good) backend::list_set_maps(pm.data(), nm.empty() ? nullptr : nm.data(), (u32)pm.size(), bases2);
            }
            backend::list_capture_begin();
            const u8 *p = lp;
            while (p < le) {
                u8 cmd = *p++; if (!cmd) continue;
                u32 n = be16(p); p += 2;
                u32 need = stream_stride(cmd & 7) * n;
                if (p + need > le) break;
                decode_prim(cmd & 0xf8, cmd & 7, n, p);
                p += need;
            }
            flush_batch();
            backend::list_capture_end();
            return true;
        }
    }
    return false;
}
#endif

void dl_call(u32 guest, u32 size) {
    if (mt::on) { mt::call(guest, size); return; }   // v36: la ejecuta el otro núcleo (mt::exec_call)
    dl_call_now(guest, size);
}
#if defined(__3DS__)
void mt::exec_prim(u32 prim, u32 fmt, u32 count, const u8 *data, u32 n) {
    if (fmt & 0x80) raw_quads(fmt & 7, count, data);
    else prim_done(prim, fmt, count, data, n);
}
void mt::exec_mesh(u32 prim, u32 fmt, u32 count, u32 key, const MeshSrc *s, const u8 *stream, u32) { mesh_exec(prim, fmt, count, key, s, stream); }
void mt::exec_call(u32 guest, u32 size) { dl_call_now(guest, size); }
#endif
void dl_call_now(u32 guest, u32 size) {
    census.dl_calls++;
#if defined(__3DS__)
    flush_batch();
    if (dl_resident(guest, size, guest)) return;
#endif
    { static const char *trace = getenv("W3D_GX_TRACE"); if (trace && census_frame == (u32)atoi(trace)) fprintf(stderr, "[dl] guest=%x size=%u\n", guest, size); }
    const u8 *p = (const u8 *)g2h(guest), *e = p + size;
    while (p < e) {
        u8 cmd = *p++;
        if (cmd == 0) continue;
        u32 prim = cmd & 0xf8, fmt = cmd & 7;
        if (prim < PRIM_QUADS || prim > PRIM_POINTS || p + 2 > e) {
            fprintf(stderr, "[gx] lista 0x%08x: orden 0x%02x desconocida en +%ld\n", guest, cmd, (long)(p - 1 - (const u8 *)g2h(guest)));
            return;
        }
        u32 n = be16(p);
        p += 2;
        u32 need = stream_stride(fmt) * n;
        if (p + need > e) {
            fprintf(stderr, "[gx] lista 0x%08x: primitiva de %u B más allá del final\n", guest, need);
            return;
        }
        decode_prim(prim, fmt, n, p);
        p += need;
    }
}

void copy_display(bool clear) {
    // v36: fin del cuadro, como GXCopyDisp en la consola: se espera a que el otro núcleo termine lo grabado. El resto
    // (UI, C3D_FrameEnd) lo hace este hilo con la cola parada.
    if (mt::on) mt::drain();
    flush_batch();
    backend::copy_display(clear, false);
    census_end_frame();
    mt::frame_end();
}

void census_end_frame() {
    static FILE *f;
    static bool checked;
    static u32 frame;
    if (!checked) {
        checked = true;
        const char *path = getenv("W3D_GX_CENSUS");
        if (path && *path) {
            f = fopen(strcmp(path, "1") ? path : "w3d_gx_census.csv", "w");
            if (f) fprintf(f, "frame,begins,draws,vertices,triangles,tev_stages_sum,tev_stages_max,indirect,blend,alpha_test,lit,lights_max,tex_binds,tex_unique,tex_uploads,pos_mtx_loads,nrm_mtx_loads,tex_mtx_loads,matrices_per_draw,state_changes,pipeline_switches,dl_calls\n");
        }
    }
    if (f) {
        const Census &c = census;
        fprintf(f, "%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%.2f,%u,%u,%u\n", frame, c.begins, c.draws, c.vertices, c.triangles, c.tev_stage_sum, c.tev_stage_max, c.ind_draws, c.blend_draws, c.alphatest_draws, c.lit_draws, c.lights_max, c.tex_binds, c.tex_unique, c.tex_uploads, c.pos_mtx_loads, c.nrm_mtx_loads, c.tex_mtx_loads, c.begins ? (double)(c.pos_mtx_loads + c.nrm_mtx_loads + c.tex_mtx_loads) / c.begins : 0.0, c.state_changes, c.pipeline_switches, c.dl_calls);
        fflush(f);
    }
    frame++;
    census_frame = frame;
    memset(&census, 0, sizeof census);
}

}  // namespace gx
}  // namespace w3d
