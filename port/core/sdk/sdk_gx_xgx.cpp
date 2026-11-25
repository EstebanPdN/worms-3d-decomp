// Capa XGX del juego (0x8016xxxx): funciones que tras GXBegin escriben directamente en la FIFO 0xcc008000.
// Se sustituyen por dirección para entregar los mismos valores, con el mismo tamaño, a gx::fifo_*: la dirección
// del puerto no existe en el anfitrión. La lógica sale de su pseudocódigo en source/recovered/refined/functions
// y de la fuente admitida cuando la hay (ver analysis/recovery-ledger.json).
//
// Dos correcciones de fidelidad:
// - Conversión float a u8: el original usa psq_st con GQR2 (u8), que satura. Aquí sat_u8 hace lo mismo; un cast de C
//   daría basura con valores fuera de rango. Los ángulos no van por psq: conservan su recorte a 8 bits.
// - Colores: el puerto recibe la palabra con el primer byte en memoria como byte alto (R). Con memoria
//   little-endian se escriben los 4 bytes en su orden de memoria con fifo_bytes, nunca la palabra leída.
#include "../../platform/gx/gx_internal.h"
#include "w3d_ptr.h"
#include <stdint.h>
#include <string.h>

using namespace w3d;
using namespace w3d::gx;
typedef w3d_u32 GA;

extern "C" {
extern float A803a5f3c[];    // Tabla de senos de 256 entradas.
extern w3d_u32 A804b1884;    // Global de la capa XGX.
void A8016a1bc(GA);          // Empuja la matriz de mundo.
void A8016a194(GA);          // La retira.
void A8016797c(GA, unsigned, int, int);  // Formato de vértice XGX.
void A803089c8(int, int, int);
void A8030a21c(GA, int);
void A8030b3dc(int, int, int, int, int);
void A8030ba98(int);
void A8030bacc(int, int);
void A8030bec4(GA, int);
void A8030c264(float, float, float, float, float, float);
void A8030c2ac(unsigned, unsigned, unsigned, unsigned);
void A8030bff4(GA, unsigned);
void A8030c094(unsigned);
void A8030ba64(int, unsigned, int);
void A8030b9b8(int, int, int, int);
void A8030ba0c(int);
void A8030ba38(int);
void A8030990c(int);
void A803080a4(int);
void A80307e24(int, int, int, unsigned, int, unsigned);
void A8030a46c(void);
void A80307558(void);
void A80306cd0(int, int);
void A80307590(int, int, int, int, int);
void A8030b648(int);
void A8030b4ac(int, int, int, int);
void A8030b014(int, int, int, int, int);
void A8030b058(int, int, int, int, int);
void A8030b09c(int, int, int, int, int, int);
void A8030b104(int, int, int, int, int, int);
void A8030b25c(int, int);
void A8030b2b8(int, int);
void A8030b314(int, int, int);
#if W3D_POINTER_64
void A8030b16c(int, uint64_t);
void A8030b1e8(int, uint64_t);
#else
// ARM (sdk_gx.cpp): GXColorS10 es S10Arg {u32 a, b} en r1 y r2, y GXColor una palabra en r1. Con uint64_t el valor iba en
// r2:r3 y r1 quedaba con basura: colores de TEV basura en la preparación de las películas.
void A8030b16c(int, uint32_t, uint32_t);
void A8030b1e8(int, uint32_t);
#endif
void A8030b35c(int, int, int, int, int);
}

namespace {

inline u8 sat_u8(float v) {
    if (!(v > 0.f)) return 0;
    if (v >= 255.f) return 255;
    return (u8)v;
}
inline void P(float x, float y, float z) { fifo_f32(x); fifo_f32(y); fifo_f32(z); }
inline void T(float s, float t) { fifo_f32(s); fifo_f32(t); }
inline float rdf(GA a) { return *(const float *)g2h(a); }
inline u32 rdw(GA a) { return *(const u32 *)g2h(a); }

// La malla XGX guarda arrays con la cuenta en +0x18 y los datos en +0x20.
struct Arr { GA data; u32 count; };
inline Arr arr_at(GA obj, u32 off) {
    GA a = rdw(obj + off);
    return Arr{a + 0x20, rdw(a + 0x18)};
}

// Llamada virtual del desplazamiento 0x48: devuelve el descriptor de teselas del atlas.
inline GA vtex(GA self) {
    GA vt = rdw(self);
    GA fn = rdw(vt + 0x48);
    return ((GA (*)(uint64_t))g2h(fn))(self);
}

static const u8 kWhite[4] = {255, 255, 255, 255};

// v37: un vértice de cuadrado (posición, color, uv). Con sitio nativo (gx::quads_begin) se escribe ya en el formato del
// lote, 24 B; si no, va por la FIFO como siempre.
struct QuadOut {
    u8 *w;
    inline void operator()(float x, float y, float z, const u8 *c, float s, float t) {
        if (w) {
            const float f[3] = {x, y, z}, uv[2] = {s, t};
            memcpy(w, f, 12); memcpy(w + 12, c, 4); memcpy(w + 16, uv, 8);
            w += 24;
        } else { P(x, y, z); fifo_bytes(c, 4); T(s, t); }
    }
    inline void end() { if (w) quads_end(); }
};

}  // namespace

extern "C" {

// Malla indexada de un solo flujo, atributos 0x122: tres veces el mismo índice por vértice.
int A8016ac3c(unsigned mask, unsigned count, GA self) {
    u32 flags = rdw(self + 0xb4);
    if ((int)flags < 0 || (flags & 0x40000000u) || mask != 0x122) return 0;
    const u16 *p = (const u16 *)g2h(rdw(self + 0xa0));
    const GA a = rdw(self + 0xa0);
    if (count <= 0xffff && fifo_mesh(MeshSrc{{a, a, a, 0}, {2, 2, 2, 0}, 3}, count)) p += count;
    else for (u32 i = 0; (u16)i < count; i++, p++) { fifo_u16(*p); fifo_u16(*p); fifo_u16(*p); }
    *(u32 *)g2h(self + 0xa0) = h2g(p);
    return 1;
}

// Malla indexada general: flujo compartido u8/u16 o cuatro flujos separados.
void A8016acac(unsigned mask, unsigned count, GA self) {
    u32 flags = rdw(self + 0xb4);
    if ((int)flags < 0) {
        const u8 *s[4] = {(const u8 *)g2h(rdw(self + 0xa4)), (const u8 *)g2h(rdw(self + 0xa8)), (const u8 *)g2h(rdw(self + 0xac)), (const u8 *)g2h(rdw(self + 0xb0))};
        {
            static const u32 kGroup[4] = {0x3, 0xc, 0x30, 0x180}, kByte[4] = {0x20000000u, 0x10000000u, 0x08000000u, 0x04000000u};
            MeshSrc ms{};
            bool null = false;
            for (int k = 0; k < 4; k++) if (mask & kGroup[k]) {
                ms.ptr[ms.n] = rdw(self + 0xa4 + 4 * k); ms.isz[ms.n] = flags & kByte[k] ? 1 : 2;
                if (!ms.ptr[ms.n]) null = true;
                ms.n++;
            }
            if (!null && fifo_mesh(ms, count)) return;
        }
        for (u32 i = 0; i < count; i++) {
            if (mask & 0x3) { if (flags & 0x20000000u) fifo_u8(s[0][i]); else fifo_u16(((const u16 *)s[0])[i]); }
            if (mask & 0xc) { if (flags & 0x10000000u) fifo_u8(s[1][i]); else fifo_u16(((const u16 *)s[1])[i]); }
            if (mask & 0x30) { if (flags & 0x08000000u) fifo_u8(s[2][i]); else fifo_u16(((const u16 *)s[2])[i]); }
            if (mask & 0x180) { if (flags & 0x04000000u) fifo_u8(s[3][i]); else fifo_u16(((const u16 *)s[3])[i]); }
        }
        return;
    }
    GA cur = rdw(self + 0xa0);
    if (cur) {
        const bool b8 = (flags & 0x40000000u) != 0;
        static const u32 kGroup8[4] = {0x2, 0xc, 0x30, 0x180}, kGroup16[4] = {0x3, 0xc, 0x30, 0x180};
        MeshSrc ms{};
        for (int k = 0; k < 4; k++) if (mask & (b8 ? kGroup8 : kGroup16)[k]) { ms.ptr[ms.n] = cur; ms.isz[ms.n] = b8 ? 1 : 2; ms.n++; }
        if (fifo_mesh(ms, count)) { *(u32 *)g2h(self + 0xa0) = cur + count * (b8 ? 1 : 2); return; }
    }
    if (flags & 0x40000000u) {
        const u8 *p = (const u8 *)g2h(cur);
        for (u32 i = 0; i < count; i++, p++) {
            // El original comprueba aquí mask&2 y no mask&3: se conserva.
            if (mask & 0x2) fifo_u8(*p);
            if (mask & 0xc) fifo_u8(*p);
            if (mask & 0x30) fifo_u8(*p);
            if (mask & 0x180) fifo_u8(*p);
        }
        *(u32 *)g2h(self + 0xa0) = h2g(p);
    } else {
        const u16 *p = (const u16 *)g2h(cur);
        for (u32 i = 0; i < count; i++, p++) {
            if (mask & 0x3) fifo_u16(*p);
            if (mask & 0xc) fifo_u16(*p);
            if (mask & 0x30) fifo_u16(*p);
            if (mask & 0x180) fifo_u16(*p);
        }
        *(u32 *)g2h(self + 0xa0) = h2g(p);
    }
}

// Índices secuenciales.
void A8016b3f0(int prim, unsigned mask, unsigned count) {
    A803089c8(prim, 0, (int)count);
    if (count <= 0xffff) {
        static const u32 kGroup[4] = {0x3, 0xc, 0x30, 0x180};
        MeshSrc ms{};
        for (int k = 0; k < 4; k++) if (mask & kGroup[k]) { ms.ptr[ms.n] = 0; ms.isz[ms.n] = 2; ms.n++; }
        if (fifo_mesh(ms, count)) return;
    }
    for (u32 i = 0; i < count; i = (i + 1) & 0xffff) {
        u16 v = (u16)i;
        if (mask & 0x3) fifo_u16(v);
        if (mask & 0xc) fifo_u16(v);
        if (mask & 0x30) fifo_u16(v);
        if (mask & 0x180) fifo_u16(v);
    }
}

// Partículas: un cuadrado por partícula, con transformación de mundo opcional.
void A8016c7d0(GA self, GA m, int world) {
    Arr ids = arr_at(m, 0x64);
    u32 n = ids.count;
    if (!n) return;
    Arr mask = arr_at(m, 0x60), rot = arr_at(m, 0x58), size = arr_at(m, 0x44), color = arr_at(m, 0x54), pos = arr_at(m, 0x40);
    const u8 *mk = mask.count ? (const u8 *)g2h(mask.data) : nullptr;
    static const float kOne[2] = {1.f, 1.f};
    const float *sz = size.count ? (const float *)g2h(size.data) : kOne;
    GA tex = vtex(self);
    const float *scale = (const float *)g2h(rdw(tex + 0x24) + 0x20), *off = (const float *)g2h(rdw(tex + 0x28) + 0x20);
    u32 total = 0;
    if (mk) { for (u32 i = 0; i < n; i++) if (mk[i]) total += 4; } else total = n * 4;
    if (!total) return;
    const float *w = (const float *)g2h(self + 0xec);
    if (world) A8016a1bc(self);
    A8016797c(A804b1884, 0x91, 1, 0);
    A803089c8(0x80, 0, (int)(total & 0xffff));
    QuadOut V{quads_begin(total)};
    const u8 *idp = (const u8 *)g2h(ids.data);
    const float *pp = (const float *)g2h(pos.data), *rp = (const float *)g2h(rot.data);
    const u8 *cp = (const u8 *)g2h(color.data);
    for (u32 i = 0; i < n; i++, pp += 3) {
        if (!mk || mk[i]) {
            u32 id = idp[i];
            const float *o = off + id * 2, *s = scale + id * 2;
            const u8 *c = color.count == 0 ? kWhite : color.count == 1 ? cp : cp + i * 4;
            float p[3] = {pp[0], pp[1], pp[2]};
            if (world) {
                p[0] = pp[2] * w[2] + pp[0] * w[0] + pp[1] * w[1] + w[3];
                p[1] = pp[2] * w[6] + pp[0] * w[4] + pp[1] * w[5] + w[7];
                p[2] = pp[2] * w[10] + pp[0] * w[8] + pp[1] * w[9] + w[11];
            }
            float ux, uy, wx, wy;
            if (rot.count) {
                u32 ang = (u32)(int)(rp[i] * 40.743664f) & 0xff;
                float sn = A803a5f3c[ang], cs = A803a5f3c[(ang + 0x40) & 0xff];
                ux = sz[0] * cs + sn * 0.f;
                uy = cs * 0.f - sz[0] * sn;
                wx = sz[1] * sn + cs * 0.f;
                wy = sz[1] * cs - sn * 0.f;
            } else {
                ux = sz[0]; uy = 0.f; wx = 0.f; wy = sz[1];
            }
            V(p[0] - ux - wx, p[1] - uy - wy, p[2], c, o[0], o[1]);
            V(p[0] + ux - wx, p[1] + uy - wy, p[2], c, o[0] + s[0], o[1]);
            V(p[0] + ux + wx, p[1] + uy + wy, p[2], c, o[0] + s[0], o[1] + s[1]);
            V(p[0] - ux + wx, p[1] - uy + wy, p[2], c, o[0], o[1] + s[1]);
        }
        if (size.count > 1) sz += 2;
    }
    V.end();
    if (world) A8016a194(self);
}

// Partículas orientadas con dos ejes guardados en el objeto (+0x6c y +0x78).
int A8016cd38(GA self, GA m) {
    Arr ids = arr_at(m, 0x64);
    u32 n = ids.count;
    if (!n) return 0;
    Arr mask = arr_at(m, 0x60), rot = arr_at(m, 0x58), size = arr_at(m, 0x44), color = arr_at(m, 0x54), pos = arr_at(m, 0x40);
    const u8 *mk = mask.count ? (const u8 *)g2h(mask.data) : nullptr;
    static const float kOne[2] = {1.f, 1.f};
    const float *sz = size.count ? (const float *)g2h(size.data) : kOne;
    const float *a0 = (const float *)g2h(m + 0x6c), *a1 = (const float *)g2h(m + 0x78);
    GA tex = vtex(self);
    const float *scale = (const float *)g2h(rdw(tex + 0x24) + 0x20), *off = (const float *)g2h(rdw(tex + 0x28) + 0x20);
    u32 total = 0;
    if (mk) { for (u32 i = 0; i < n; i++) if (mk[i]) total += 4; } else total = n * 4;
    if (!total) return 0;
    A8016797c(A804b1884, 0x91, 1, 0);
    A803089c8(0x80, 0, (int)(total & 0xffff));
    QuadOut V{quads_begin(total)};
    const u8 *idp = (const u8 *)g2h(ids.data);
    const float *pp = (const float *)g2h(pos.data), *rp = (const float *)g2h(rot.data);
    const u8 *cp = (const u8 *)g2h(color.data);
    for (u32 i = 0; i < n; i++, pp += 3) {
        if (!mk || mk[i]) {
            u32 id = idp[i];
            const float *o = off + id * 2, *s = scale + id * 2;
            const u8 *c = color.count == 0 ? kWhite : color.count == 1 ? cp : cp + i * 4;
            if (rot.count == 0) {
                float hx = sz[0], hy = sz[1];
                float x1 = a1[0] * hx, y1 = a1[1] * hx, z1 = a1[2] * hx, x0 = a0[0] * hy, y0 = a0[1] * hy, z0 = a0[2] * hy;
                V(pp[0] - x1 - x0, pp[1] - y1 - y0, pp[2] - z1 - z0, c, o[0], o[1]);
                V(pp[0] + x1 - x0, pp[1] + y1 - y0, pp[2] + z1 - z0, c, o[0] + s[0], o[1]);
                V(pp[0] + x1 + x0, pp[1] + y1 + y0, pp[2] + z1 + z0, c, o[0] + s[0], o[1] + s[1]);
                V(pp[0] - x1 + x0, pp[1] - y1 + y0, pp[2] - z1 + z0, c, o[0], o[1] + s[1]);
            } else {
                float hx = sz[0], hy = sz[1];
                u32 ang = (u32)(int)(rp[i] * 40.743664f) & 0xff;
                float sn = A803a5f3c[ang], cs = A803a5f3c[(ang + 0x40) & 0xff];
                float ux = hx * cs + sn * 0.f, uy = cs * 0.f - hx * sn, wx = hy * sn + cs * 0.f, wy = hy * cs - sn * 0.f;
                float ax = ux + wx, ay = uy + wy, bx = ux - wx, by = uy - wy;
                V((pp[0] - ax * a1[0]) - ay * a0[0], (pp[1] - ax * a1[1]) - ay * a0[1], (pp[2] - ax * a1[2]) - ay * a0[2], c, o[0], o[1]);
                V(by * a0[0] + bx * a1[0] + pp[0], by * a0[1] + bx * a1[1] + pp[1], by * a0[2] + bx * a1[2] + pp[2], c, o[0] + s[0], o[1]);
                V(ay * a0[0] + ax * a1[0] + pp[0], ay * a0[1] + ax * a1[1] + pp[1], ay * a0[2] + ax * a1[2] + pp[2], c, o[0] + s[0], o[1] + s[1]);
                V((pp[0] - bx * a1[0]) - by * a0[0], (pp[1] - bx * a1[1]) - by * a0[1], (pp[2] - bx * a1[2]) - by * a0[2], c, o[0], o[1] + s[1]);
            }
        }
        if (size.count > 1) sz += 2;
    }
    V.end();
    return 0;
}

// Sprites filtrados por página: id alto == página, id bajo == celda; v invertida. Los que no pasan dejan un cuadrado nulo.
void A8016d49c(GA, GA m, GA tex, int page) {
    if (!tex) return;
    Arr ids = arr_at(m, 0x50), size = arr_at(m, 0x44), color = arr_at(m, 0x48), rot = arr_at(m, 0x4c), pos = arr_at(m, 0x40);
    GA mask_obj = rdw(m + 0x58);
    const u8 *mk = rdw(mask_obj + 0x18) ? (const u8 *)g2h(mask_obj + 0x20) : nullptr;
    static const float kOne[2] = {1.f, 1.f};
    const float *sz = size.count ? (const float *)g2h(size.data) : kOne;
    const float *scale = (const float *)g2h(rdw(tex + 0x1c) + 0x20), *off = (const float *)g2h(rdw(tex + 0x20) + 0x20);
    u32 n = ids.count;
    A8016797c(A804b1884, 0x91, 1, 0);
    A803089c8(0x80, 0, (int)((n & 0x3fff) << 2));
    QuadOut V{quads_begin(n * 4)};
    const u16 *idp = (const u16 *)g2h(ids.data);
    const float *pp = (const float *)g2h(pos.data), *rp = (const float *)g2h(rot.data);
    const u8 *cp = (const u8 *)g2h(color.data);
    for (u32 i = 0; i < n; i++, pp += 3) {
        u32 v = idp[i];
        if ((v & 0xff00) == ((u32)page << 8) && (!mk || mk[i])) {
            u32 id = v & 0xff;
            const float *o = off + id * 2, *s = scale + id * 2;
            const u8 *c = color.count == 0 ? kWhite : color.count == 1 ? cp : cp + i * 4;
            float ux, uy, wx, wy;
            if (rot.count) {
                u32 ang = (u32)(int)(rp[i] * 40.743664f) & 0xff;
                float sn = A803a5f3c[ang], cs = A803a5f3c[(ang + 0x40) & 0xff];
                ux = sz[0] * cs + sn * 0.f; uy = cs * 0.f - sz[0] * sn;
                wx = sz[1] * sn + cs * 0.f; wy = sz[1] * cs - sn * 0.f;
            } else {
                ux = sz[0]; uy = 0.f; wx = 0.f; wy = sz[1];
            }
            V(pp[0] - ux - wx, pp[1] - uy - wy, pp[2], c, o[0], 1.f - (o[1] + s[1]));
            V(pp[0] + ux - wx, pp[1] + uy - wy, pp[2], c, o[0] + s[0], 1.f - (o[1] + s[1]));
            V(pp[0] + ux + wx, pp[1] + uy + wy, pp[2], c, o[0] + s[0], 1.f - o[1]);
            V(pp[0] - ux + wx, pp[1] - uy + wy, pp[2], c, o[0], 1.f - o[1]);
        } else {
            for (int q = 0; q < 4; q++) { V(0.f, 0.f, 0.f, kWhite, 0.f, 0.f); }
        }
        if (size.count > 1) sz += 2;
    }
    V.end();
}

// Sprites con tamaño en el cuarto componente de la posición, gemelo de 0x8016c7d0.
int A8016da74(GA face, GA m) {
    GA self = face ? face - 4 : 0;
    Arr ids = arr_at(m, 0x4c), pos = arr_at(m, 0x44), alpha = arr_at(m, 0x50), color = arr_at(m, 0x40), rot = arr_at(m, 0x48);
    u32 n = pos.count;
    const float *idp = ids.count ? (const float *)g2h(ids.data) : nullptr;
    const float *ap_ = (const float *)g2h(alpha.data), *cp = (const float *)g2h(color.data);
    const float *rp = (const float *)g2h(rot.data), *pp = (const float *)g2h(pos.data);
    const float *mw = (const float *)g2h(self + 0xec);
    GA tex = vtex(self);
    const float *scale = (const float *)g2h(rdw(tex + 0x24) + 0x20), *off = (const float *)g2h(rdw(tex + 0x28) + 0x20);
    A8016a1bc(self);
    A8016797c(A804b1884, 0x91, 1, 0);
    A803089c8(0x80, 0, (int)((n & 0x3fff) << 2));
    QuadOut V{quads_begin(n * 4)};
    for (u32 i = 0; i < n; i++, pp += 4) {
        u32 id = idp ? sat_u8(idp[i]) : 0;
        const float *o = off + id * 2, *s = scale + id * 2;
        u8 c[4];
        if (color.count > 1) {
            const float *cc = cp + i * 4;
            c[0] = sat_u8(cc[0] * 255.f); c[1] = sat_u8(cc[1] * 255.f); c[2] = sat_u8(cc[2] * 255.f);
            c[3] = alpha.count > 1 ? sat_u8(ap_[i] * 255.f) : sat_u8(cc[3] * 255.f);
        } else {
            c[0] = c[1] = c[2] = 255;
            c[3] = alpha.count > 1 ? sat_u8(ap_[i] * 255.f) : 255;
        }
        float vx = pp[2] * mw[2] + pp[0] * mw[0] + pp[1] * mw[1] + mw[3];
        float vy = pp[2] * mw[6] + pp[0] * mw[4] + pp[1] * mw[5] + mw[7];
        float vz = pp[2] * mw[10] + pp[0] * mw[8] + pp[1] * mw[9] + mw[11];
        float h = pp[3];
        float ux, uy, wx, wy;
        if (rot.count) {
            u32 ang = (u32)(int)(rp[i] * 40.743664f) & 0xff;
            float sn = A803a5f3c[ang], cs = A803a5f3c[(ang + 0x40) & 0xff];
            ux = h * cs + sn * 0.f; uy = cs * 0.f - h * sn;
            wx = h * sn + cs * 0.f; wy = h * cs - sn * 0.f;
        } else {
            ux = h; uy = 0.f; wx = 0.f; wy = h;
        }
        V(vx - ux - wx, vy - uy - wy, vz, c, o[0], o[1]);
        V(vx + ux - wx, vy + uy - wy, vz, c, o[0] + s[0], o[1]);
        V(vx + ux + wx, vy + uy + wy, vz, c, o[0] + s[0], o[1] + s[1]);
        V(vx - ux + wx, vy - uy + wy, vz, c, o[0], o[1] + s[1]);
    }
    V.end();
    A8016a194(self);
    return 0;
}

// Glifo de texto: cuatro esquinas en s16.
void A8016dfcc(GA self, int x, int y, int u, int v) {
    GA d = rdw(self);
    s16 w = *(const s16 *)g2h(d + 0x10), h = *(const s16 *)g2h(d + 0x12);
    s16 l = (s16)x, t = (s16)y, su = (s16)u, sv = (s16)v;
    s16 r = (s16)(w + l), b = (s16)(h + t), eu = (s16)(w + su), ev = (s16)(h + sv);
    A803089c8(0x80, 0, 4);
    const s16 q[20] = {l, t, 0, su, sv, r, t, 0, eu, sv, r, b, 0, eu, ev, l, b, 0, su, ev};
    if (quad_s16(q)) return;
    for (s16 c : q) fifo_u16((u16)c);
}

// Imagen de película: tres planos en los mapas 0-2 y cuadrado en s16.
void A802e2a00(GA tex, int x, int y, int w, int h) {
    A8030a21c(tex, 0);
    A8030a21c(tex + 0x20, 1);
    A8030a21c(tex + 0x40, 2);
    A803089c8(0x80, 7, 4);
    s16 l = (s16)x, t = (s16)y, r = (s16)(x + w), b = (s16)(y + h);
    const s16 q[20] = {l, t, 0, 0, 0, r, t, 0, 1, 0, r, b, 0, 1, 1, l, b, 0, 0, 1};
    for (s16 c : q) fifo_u16((u16)c);
}

// Preparación de película (conversión YUV en cuatro etapas). Se sustituye por dirección porque la unidad escribe
// sus constantes de color en una palabra int local (c = 0xe258): en la consola esa memoria es big-endian, R es el
// byte alto, y aquí el orden se invertiría. Los valores de S10 son los de 0x803db3bc.
void A802e2508(GA, int w, int h) {
    float fw = (float)w, fh = (float)h, mo[16] = {0}, mi[12] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0};
    A8030b3dc(7, 0, 0, 7, 0);
    A8030ba98(1);
    A8030bacc(0, 0);
    mo[0] = 2.f / fw; mo[3] = -1.f; mo[5] = -2.f / fh; mo[7] = 1.f; mo[10] = 1.f; mo[11] = -1.f; mo[15] = 1.f;
    A8030bec4(h2g(mo), 1);
    A8030c264(0.f, 0.f, fw, fh, 0.f, 1.f);
    A8030c2ac(0, 0, (unsigned)w, (unsigned)h);
    A8030bff4(h2g(mi), 0);
    A8030c094(0);
    A8030ba64(1, 7, 0);
    A8030b9b8(0, 1, 0, 0);
    A8030ba0c(1);
    A8030ba38(0);
    A8030990c(0);
    A803080a4(2);
    A80307e24(0, 1, 4, 0x3c, 0, 0x7d);
    A80307e24(1, 1, 4, 0x3c, 0, 0x7d);
    A8030a46c();
    A80307558();
    A80306cd0(9, 1);
    A80306cd0(0xd, 1);
    A80307590(7, 9, 1, 3, 0);
    A80307590(7, 0xd, 1, 2, 0);
    A8030b648(4);
    A8030b4ac(0, 1, 1, 0xff);
    A8030b014(0, 0xf, 8, 0xe, 2);
    A8030b09c(0, 0, 0, 0, 0, 0);
    A8030b058(0, 7, 4, 6, 1);
    A8030b104(0, 1, 0, 0, 0, 0);
    A8030b25c(0, 0xc);
    A8030b2b8(0, 0x1c);
    A8030b314(0, 0, 0);
    A8030b4ac(1, 1, 2, 0xff);
    A8030b014(1, 0xf, 8, 0xe, 0);
    A8030b09c(1, 0, 0, 1, 0, 0);
    A8030b058(1, 7, 4, 6, 0);
    A8030b104(1, 1, 0, 0, 0, 0);
    A8030b25c(1, 0xd);
    A8030b2b8(1, 0x1d);
    A8030b314(1, 0, 0);
    A8030b4ac(2, 0, 0, 0xff);
    A8030b014(2, 0xf, 8, 0xc, 0);
    A8030b09c(2, 0, 0, 0, 1, 0);
    A8030b058(2, 4, 7, 7, 0);
    A8030b104(2, 0, 0, 0, 1, 0);
    A8030b314(2, 0, 0);
    A8030b4ac(3, 0xff, 0xff, 0xff);
    A8030b014(3, 1, 0, 0xe, 0xf);
    A8030b09c(3, 0, 0, 0, 1, 0);
    A8030b058(3, 7, 7, 7, 7);
    A8030b104(3, 0, 0, 0, 1, 0);
    A8030b314(3, 0, 0);
    A8030b25c(3, 0xe);
    { const uint64_t s10 = (uint64_t)(u16)-90 | (uint64_t)(u16)0 << 16 | (uint64_t)(u16)-114 << 32 | (uint64_t)(u16)135 << 48;
#if W3D_POINTER_64
      A8030b16c(1, s10);
#else
      A8030b16c(1, (uint32_t)s10, (uint32_t)(s10 >> 32));
#endif
    }
    // R es el byte bajo del valor por registro: 0xRRGGBBAA de la consola.
    A8030b1e8(0, 0x00u | 0x00u << 8 | 0xe2u << 16 | 0x58u << 24);
    A8030b1e8(1, 0xb3u | 0x00u << 8 | 0x00u << 16 | 0xb6u << 24);
    A8030b1e8(2, 0xffu | 0x00u << 8 | 0xffu << 16 | 0x80u << 24);
    A8030b35c(0, 0, 1, 2, 3);
}

// Contadores de rendimiento del vigilante de cuelgues: sin efecto en el anfitrión.
void A8016830c(int) {}
}
