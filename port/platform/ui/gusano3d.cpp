// El worm de Worms 3D en 3D para la pantalla de arriba de Crear equipo (pedido del dueño, 2026-11-07: «el modelo 3D del
// gusano, parado, con animaciones de espera, sonriendo de vez en cuando», como en Worms 4 / Ultimate Mayhem).
// - Datos del juego sin retocar (gusano_modelo.inc y gusano_atlas.w3ui, de tools/build3ds/ui/export_gusano.py): la malla
//   de Objects/boggyb.xom con su esqueleto y su piel, y los clips de Bundles/bundle04.xom (XCULLEDBoggyB).
// - Evaluado como el juego (y como mods/ahogo-um/tools/rig.py, comprobado contra sus matrices): curvas de Maya (Hermite,
//   o Bézier pesada, xomlib.evaluar), local = S * RA * R * JO y + T, mundo = local * mundo del padre, piel = suma de
//   peso * (v * postura del hueso * mundo de su articulación). Los clips escriben valores absolutos; las capas se mezclan
//   por peso (las rotaciones por el camino corto) y los selectores de ojos y dientes los pone la capa que pesa más.
// - Espera: Neutral_pose (de pie, la cola detrás), un micromovimiento en bucle (uno de los seis, con fundido de 0,5 s al
//   cambiar), la respiración, parpadeos y, de vez en cuando, una sonrisa o un gesto de cejas; gusano_react() saluda.
// - Sombrero: la malla del gorro (ropa_mallas_*.w3h, en el espacio del HatLocator, como lo engancha el juego) va con la
//   matriz del HatLocator del esqueleto.
// - Dibujo: luz difusa con ambiente por vértice; en Mac a la imagen del juego con z-buffer (tris_under); en 3DS en la
//   capa de la UI, ordenado del fondo hacia delante.
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include "ui.h"
#ifdef W3D_PUBLIC
namespace ui {
void gusano_react() {}
void gusano_turn(int) {}
void gusano_turn_reset() {}
void gusano_draw(int, float, float, float, int, float) {}
}
#else
#include "gusano_modelo.inc"

namespace ui {
namespace {
using namespace gusano_datos;
const float kPi = 3.14159265f;

// --- Matrices afines 4x3 con vector fila: p' = p * r + t --------------------------------------------------------
struct M { float r[3][3], t[3]; };
void euler(const float e[3], float m[3][3]) {   // d26e_euler_matrix_801a3eb0, orden XYZ
    const float sx = sinf(e[0]), cx = cosf(e[0]), sy = sinf(e[1]), cy = cosf(e[1]), sz = sinf(e[2]), cz = cosf(e[2]);
    m[0][0] = cz * cy;                m[0][1] = cy * sz;                m[0][2] = -sy;
    m[1][0] = sx * sy * cz - cx * sz; m[1][1] = sx * sy * sz + cx * cz; m[1][2] = sx * cy;
    m[2][0] = cx * sy * cz + sx * sz; m[2][1] = cx * sy * sz - sx * cz; m[2][2] = cx * cy;
}
void mul3(const float a[3][3], const float b[3][3], float o[3][3]) {
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) o[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
}
M after(const M &a, const M &b) {   // primero a y después b
    M o; mul3(a.r, b.r, o.r);
    for (int k = 0; k < 3; k++) o.t[k] = a.t[0] * b.r[0][k] + a.t[1] * b.r[1][k] + a.t[2] * b.r[2][k] + b.t[k];
    return o;
}
inline void app(const M &m, const float v[3], float o[3]) {
    for (int k = 0; k < 3; k++) o[k] = v[0] * m.r[0][k] + v[1] * m.r[1][k] + v[2] * m.r[2][k] + m.t[k];
}
inline void rot(const M &m, const float v[3], float o[3]) {
    for (int k = 0; k < 3; k++) o[k] = v[0] * m.r[0][k] + v[1] * m.r[1][k] + v[2] * m.r[2][k];
}
inline void normalize(float v[3]) {
    const float l = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (l > 1e-12f) { v[0] /= l; v[1] /= l; v[2] /= l; }
}

// --- Curvas y clips ---------------------------------------------------------------------------------------------
const float kMaxTan = 5729578.0f;   // 0x803a84d8: pendiente «infinita» de una tangente sin x
float bezier_x(float p1, float p2, float s) { const float u = 1 - s; return 3 * u * u * s * p1 + 3 * u * s * s * p2 + s * s * s; }
float curve(const Chan &c, float t) {
    const float (*k)[6] = &kKey[c.k0];
    const int n = c.nk;
    if (c.still || t <= k[0][4]) return k[0][5];
    if (t >= k[n - 1][4]) return k[n - 1][5];
    int i = 0;
    while (i + 1 < n && k[i + 1][4] <= t) i++;
    const float *a = k[i], *b = k[i + 1];
    const float t0 = a[4], v0 = a[5], t1 = b[4], v1 = b[5];
    if (a[2] == 0.0f && a[3] == 0.0f) return v0;   // tangente de salida (0, 0): escalón
    const float x1 = t0 + a[2] / 3, y1 = v0 + a[3] / 3, x2 = t1 - b[0] / 3, y2 = v1 - b[1] / 3, dx = t1 - t0;
    if (!c.heavy) {   // Hermite (0x801968e8 y 0x8019661c)
        const float m1 = x1 != t0 ? (y1 - v0) / (x1 - t0) : kMaxTan, m2 = t1 != x2 ? (v1 - y2) / (t1 - x2) : kMaxTan;
        const float dy = v1 - v0, d1 = dx * m1, inv = 1 / (dx * dx);
        const float c0 = ((d1 + dx * m2 - dy - dy) * inv) / dx, c1 = (dy + dy + dy - d1 - d1 - dx * m2) * inv, s = t - t0;
        return ((c0 * s + c1) * s + m1) * s + v0;
    }
    // Bézier pesada (0x801966a0, 0x80196504): se busca el s de x(s) y se evalúa y(s).
    const float p1 = fminf(fmaxf((x1 - t0) / dx, 0), 1), p2 = fminf(fmaxf((x2 - t0) / dx, 0), 1), target = (t - t0) / dx;
    float lo = 0, hi = 1;
    for (int it = 0; it < 30; it++) { const float mid = (lo + hi) / 2; if (bezier_x(p1, p2, mid) < target) lo = mid; else hi = mid; }
    const float s = (lo + hi) / 2, u = 1 - s;
    return u * u * u * v0 + 3 * u * u * s * y1 + 3 * u * s * s * y2 + s * s * s * v1;
}
struct Pose { float trs[kJoints][3][3]; float sel[3]; };   // [articulación][T, R, S][x, y, z]; selectores de ojos y dientes
void rest(Pose &p) {
    for (int j = 0; j < kJoints; j++) {
        memcpy(p.trs[j][0], kJoint[j].t, 12); memcpy(p.trs[j][1], kJoint[j].r, 12); memcpy(p.trs[j][2], kJoint[j].s, 12);
    }
    p.sel[0] = p.sel[1] = p.sel[2] = 0;
}
// Mezcla el clip en el tiempo t con el peso w sobre lo que ya hay.
void apply(Pose &p, int clip, float t, float w) {
    if (clip < 0 || w <= 0) return;
    const Clip &cl = kClip[clip];
    t = fminf(fmaxf(t, 0), cl.dur);
    for (int i = cl.c0; i < cl.c0 + cl.nc; i++) {
        const Chan &c = kChan[i];
        const float v = curve(c, t);
        if (c.type == 0) { if (w >= 0.5f) p.sel[c.target] = v; continue; }
        float &cur = p.trs[c.target][c.type - 2][c.comp];
        float d = v - cur;
        if (c.type == 3) { while (d > kPi) d -= 2 * kPi; while (d < -kPi) d += 2 * kPi; }
        cur += (w >= 1 ? 1 : w) * d;
    }
}
int clip_of(const char *name) {
    for (int i = 0; i < kClips; i++) if (!strcmp(kClip[i].name, name)) return i;
    return -1;
}
void world(const Pose &p, M *wm) {   // los nodos vienen con el padre antes que los hijos
    for (int j = 0; j < kJoints; j++) {
        const Joint &J = kJoint[j];
        float a[3][3], b[3][3], c[3][3], ab[3][3], m[3][3];
        euler(J.ra, a); euler(p.trs[j][1], b); euler(J.jo, c);
        mul3(a, b, ab); mul3(ab, c, m);
        M loc;
        for (int i = 0; i < 3; i++) for (int k = 0; k < 3; k++) loc.r[i][k] = m[i][k] * p.trs[j][2][i];
        memcpy(loc.t, p.trs[j][0], 12);
        wm[j] = J.parent >= 0 ? after(loc, wm[J.parent]) : loc;
    }
}

// --- Espera: qué suena en cada capa -------------------------------------------------------------------------------
struct Idle {
    bool ready = false;
    int neutral = -1, breathe = -1, blink = -1, micro[6] = {-1, -1, -1, -1, -1, -1}, faces[4] = {-1, -1, -1, -1}, react[2] = {-1, -1};
    int cur = 0, prev = -1; double cur_at = 0, prev_at = 0;   // micromovimiento en curso y el anterior (fundido)
    double next_blink = 0, blink_at = -10;
    int face = -1; double face_at = 0, next_face = 0;          // sonrisa o cejas
    int act = -1; double act_at = 0;                           // reacción (saludo, alegría)
    unsigned seed = 12345;
    float rnd() { seed = seed * 1103515245u + 12345u; return (float)((seed >> 8) & 0xffff) / 65535.f; }
    void init(double t) {
        ready = true;
        neutral = clip_of("Neutral_pose"); breathe = clip_of("Breathe"); blink = clip_of("Blink");
        static const char *const kMicro[6] = {"Micromovements", "Micromovements2", "Micromovements3", "Micromovements4", "Micromovements5", "Micromovements6"};
        for (int i = 0; i < 6; i++) micro[i] = clip_of(kMicro[i]);
        static const char *const kFace[4] = {"Smile", "Smile2", "Smile3", "Idle_7_Brows"};
        for (int i = 0; i < 4; i++) faces[i] = clip_of(kFace[i]);
        react[0] = clip_of("Salute"); react[1] = clip_of("Happy5");
        cur = 0; cur_at = t; next_blink = t + 1.5; next_face = t + 3.5;
    }
    void pose(Pose &p, double t) {
        rest(p);
        apply(p, neutral, 0, 1);
        // Micromovimiento en bucle; al acabar, otro al azar con fundido.
        const float cdur = kClip[micro[cur]].dur;
        if (t - cur_at >= cdur) {
            prev = cur; prev_at = cur_at;
            int n = (int)(rnd() * 6) % 6; if (n == cur) n = (n + 1) % 6;
            cur = n; cur_at = t;
        }
        const float fade = (float)((t - cur_at) / 0.5);
        if (prev >= 0 && fade < 1) {
            apply(p, micro[prev], kClip[micro[prev]].dur, 1);
            apply(p, micro[cur], (float)(t - cur_at), fade);
        } else apply(p, micro[cur], (float)(t - cur_at), 1);
        apply(p, breathe, fmodf((float)t, kClip[breathe].dur), 0.6f);
        // Reacción (por encima de todo, con fundidos de 0,25 s).
        if (act >= 0) {
            const float d = kClip[act].dur, e = (float)(t - act_at);
            if (e >= d) act = -1;
            else apply(p, act, e, fminf(1, fminf(e / 0.25f, (d - e) / 0.25f)));
        }
        // Sonrisa o gesto de cejas cada 5 a 10 s (sin reacción en curso).
        if (face < 0 && act < 0 && t >= next_face) { face = faces[(int)(rnd() * 4) % 4]; face_at = t; }
        if (face >= 0) {
            const float d = kClip[face].dur, e = (float)(t - face_at);
            if (e >= d) { face = -1; next_face = t + 5 + rnd() * 5; }
            else apply(p, face, e, fminf(1, fminf(e / 0.2f, (d - e) / 0.2f)));
        }
        // Parpadeo cada 2,5 a 6 s.
        if (t >= next_blink) { blink_at = t; next_blink = t + 2.5 + rnd() * 3.5; }
        if (t - blink_at < kClip[blink].dur) apply(p, blink, (float)(t - blink_at), 1);
    }
};
Idle g_idle;

// --- Sombreros (ropa_mallas_*.w3h) -------------------------------------------------------------------------------
#if defined(__3DS__)
// Un archivo por sombrero (ropa/mallas_NN.w3h, de tools/build3ds/ui/ropa_3ds.py, con los NN-1 anteriores vacíos para que
// el índice siga siendo hat - 1) y en memoria solo el que se ve: de 22 a 81 KB en lugar de los 2,4 MB de los 76.
const char *const kHatFile = "ropa/mallas_%02d.w3h";
#else
const char *const kHatFile = "ropa_mallas_76.w3h.mac";
#endif
struct HatPiece { int nv, nt; const float *v; const unsigned short *t; const unsigned char *pal, *idx; };
struct Hat { int first, count; };
// v32: los vértices de cada pieza van copiados a g_hat_verts (alineados a 4). En el archivo empiezan en el byte 14 y la
// consola falla al leer floats desalineados (volcado fallo_002 de la v31, fsr=1 en gusano_draw); Azahar no lo comprueba.
std::vector<std::vector<float>> g_hat_verts;
std::vector<unsigned char> g_hat_file; std::vector<HatPiece> g_hat_pieces; std::vector<Hat> g_hats; int g_hat_loaded = -1;
void load_hats(int hat) {
#if defined(__3DS__)
    if (g_hat_loaded == hat) return;
    g_hat_pieces.clear(); g_hats.clear(); g_hat_verts.clear(); std::vector<unsigned char>().swap(g_hat_file);
    char file[32]; snprintf(file, sizeof file, kHatFile, hat);
#else
    if (g_hat_loaded >= 0) return;
    const char *const file = kHatFile;
#endif
    g_hat_loaded = hat;
    unsigned char *d = nullptr; long n = 0;
    if (!uib_read_own(file, &d, &n) || !d) { uib_log("[gusano] sin %s\n", file); return; }
    g_hat_file.assign(d, d + n); uib_free(d);
    const unsigned char *p = g_hat_file.data(), *end = p + g_hat_file.size();
    auto u16 = [&](const unsigned char *q) { return (unsigned)q[0] | (unsigned)q[1] << 8; };
    if (n < 8 || memcmp(p, "W3RM", 4) || u16(p + 4) != 1) { uib_log("[gusano] %s: formato desconocido\n", file); g_hat_file.clear(); return; }
    const unsigned hats = u16(p + 6); p += 8;
    for (unsigned h = 0; h < hats && p + 2 <= end; h++) {
        Hat hat = {(int)g_hat_pieces.size(), (int)u16(p)}; p += 2;
        for (int k = 0; k < hat.count; k++) {
            if (p + 4 > end) { g_hats.clear(); return; }
            HatPiece pc; pc.nv = (int)u16(p); pc.nt = (int)u16(p + 2); p += 4;
            const size_t need = (size_t)pc.nv * 32 + (size_t)pc.nt * 6 + 1024 + 128 * 128;
            if (p + need > end) { g_hats.clear(); return; }
            g_hat_verts.emplace_back((size_t)pc.nv * 8);
            memcpy(g_hat_verts.back().data(), p, (size_t)pc.nv * 32);
            pc.v = g_hat_verts.back().data(); p += (size_t)pc.nv * 32;
            pc.t = (const unsigned short *)p; p += (size_t)pc.nt * 6;
            pc.pal = p; p += 1024; pc.idx = p; p += 128 * 128;
            g_hat_pieces.push_back(pc);
        }
        g_hats.push_back(hat);
    }
    uib_log("[gusano] %s: %u sombreros\n", file, (unsigned)g_hats.size());
}
// Textura de una pieza del sombrero (índices por su paleta), hecha en memoria la primera vez.
const Img *hat_texture(int hat, int piece) {
    char name[48]; snprintf(name, sizeof name, "gorro_%d_%d", hat, piece);
    static int last_hat = -1; static int last_pieces = 0;
    if (hat != last_hat) {   // suelta las del anterior
        for (int k = 0; k < last_pieces; k++) { char o[48]; snprintf(o, sizeof o, "gorro_%d_%d", last_hat, k); img_mem_forget(o); }
        last_hat = hat; last_pieces = g_hats[hat - 1].count;
    }
    const HatPiece &pc = g_hat_pieces[g_hats[hat - 1].first + piece];
    static std::vector<u8> rgba; rgba.resize(128 * 128 * 4);
    for (int i = 0; i < 128 * 128; i++) memcpy(&rgba[(size_t)i * 4], pc.pal + pc.idx[i] * 4, 4);
#if defined(__3DS__)
    return img_mem(name, rgba.data(), 128, 128, 1);
#else
    return img_mem(name, rgba.data(), 128, 128, 0 + 8);
#endif
}

// --- Dibujo -----------------------------------------------------------------------------------------------------
struct Tri { float z; int a; };   // profundidad media y su primer vértice en g_out
std::vector<float> g_xyzuv; std::vector<unsigned> g_rgba; std::vector<Tri> g_tris; std::vector<int> g_tex;
float g_P[kVerts][3], g_N[kVerts][3];
}  // namespace

void gusano_react() {
    if (!g_idle.ready) return;
    g_idle.act = g_idle.react[(int)(g_idle.rnd() * 2) % 2]; g_idle.act_at = now(); g_idle.face = -1;
}
// Giro con L/R (el dueño, 2026-11-07: «si le doy a la R o a la L, el gusano se va rotando lentamente»): unos 70° por
// segundo, con arranque y frenada de 0,12 s, y se queda mirando a donde lo dejan. Es la cámara la que da la vuelta al
// worm, con la luz, como en una peana que gira bajo un foco fijo.
namespace { float g_turn, g_turn_speed; double g_turn_at; }
void gusano_turn(int dir) {
    const double t = now();
    const float dt = g_turn_at > 0 ? fminf(0.05f, (float)(t - g_turn_at)) : 0;
    g_turn_at = t;
    g_turn_speed += (-1.22f * (float)dir - g_turn_speed) * (1 - expf(-dt / 0.12f));   // +1: el frente hacia la derecha
    g_turn = fmodf(g_turn + g_turn_speed * dt, 2 * kPi);
}
void gusano_turn_reset() { g_turn = g_turn_speed = 0; g_turn_at = 0; }

void gusano_draw(int screen, float cx, float cy, float h, int hat, float pop) {
    if (pop <= 0.02f) return;
    const Img *atlas = img("gusano_atlas.w3ui",
#if defined(__3DS__)
                           1);
#else
                           0 + 8);
#endif
    if (atlas->tex < 0) return;
    const double t = now();
    if (!g_idle.ready) g_idle.init(t);
    static Pose pose; static M wm[kJoints], bm[kBones];
    g_idle.pose(pose, t);
    world(pose, wm);
    for (int b = 0; b < kBones; b++) {
        M ps; const float *q = kBone[b].pose;
        for (int i = 0; i < 3; i++) for (int k = 0; k < 3; k++) ps.r[i][k] = q[i * 3 + k];
        for (int k = 0; k < 3; k++) ps.t[k] = q[9 + k];
        bm[b] = after(ps, wm[kBone[b].joint]);
    }
    // Cámara: de frente y un poco girada hacia la derecha de la pantalla, algo desde arriba (como el dibujo de rig.py), más
    // lo que el jugador lo haya girado (gusano_turn).
    const float yaw = -24 * kPi / 180 + g_turn, pitch = 9 * kPi / 180;
    float back[3] = {sinf(yaw) * cosf(pitch), sinf(pitch), cosf(yaw) * cosf(pitch)}, right[3] = {back[2], 0, -back[0]};
    normalize(right);
    float up[3] = {back[1] * right[2] - back[2] * right[1], back[2] * right[0] - back[0] * right[2], back[0] * right[1] - back[1] * right[0]};
    normalize(up);
    float L[3] = {-0.35f * right[0] + 0.6f * up[0] + 0.7f * back[0], -0.35f * right[1] + 0.6f * up[1] + 0.7f * back[1], -0.35f * right[2] + 0.6f * up[2] + 0.7f * back[2]};
    normalize(L);
    // El worm de pie mide unas 20 unidades (y de -4 a 16) y con sombrero hasta ~28: el centro de la vista va en y = 9.
    const float center[3] = {0, 9.0f, 0}, scale = h * pop / 30.0f;
    g_xyzuv.clear(); g_rgba.clear(); g_tris.clear(); g_tex.clear();
    auto emit = [&](const float p[3], const float n[3], const float uv[2]) {
        const float d0 = p[0] - center[0], d1 = p[1] - center[1], d2 = p[2] - center[2];
        const float sx = cx + scale * (d0 * right[0] + d1 * right[1] + d2 * right[2]);
        const float sy = cy - scale * (d0 * up[0] + d1 * up[1] + d2 * up[2]);
        const float zv = d0 * back[0] + d1 * back[1] + d2 * back[2];   // hacia la cámara, en unidades
        const float lit = fminf(1.0f, 0.52f + 0.55f * fmaxf(0, n[0] * L[0] + n[1] * L[1] + n[2] * L[2]));
        const unsigned c = (unsigned)(lit * 255.f + 0.5f);
        g_xyzuv.push_back(sx); g_xyzuv.push_back(sy); g_xyzuv.push_back(fminf(1, fmaxf(0, 0.5f - zv / 80.f)));
        g_xyzuv.push_back(uv[0]); g_xyzuv.push_back(uv[1]);
        g_rgba.push_back(c | c << 8 | c << 16 | 0xff000000u);
    };
    auto tri = [&](const float *P0, const float *P1, const float *P2, const float *N0, const float *N1, const float *N2,
                   const float *U0, const float *U1, const float *U2, int tex) {
        float n[3] = {N0[0] + N1[0] + N2[0], N0[1] + N1[1] + N2[1], N0[2] + N1[2] + N2[2]};
        normalize(n);
        if (n[0] * back[0] + n[1] * back[1] + n[2] * back[2] < -0.2f) return;   // de espaldas
        float z = 0;
        for (const float *p : {P0, P1, P2}) z += (p[0] - center[0]) * back[0] + (p[1] - center[1]) * back[1] + (p[2] - center[2]) * back[2];
        g_tris.push_back({z / 3, (int)(g_xyzuv.size() / 5)});
        g_tex.push_back(tex);
        emit(P0, N0, U0); emit(P1, N1, U1); emit(P2, N2, U2);
    };
    // Piezas del worm (las de un selector, solo la que toca).
    for (int pi = 0; pi < kPieces; pi++) {
        const Piece &pc = kPiece[pi];
        if (pc.sel >= 0 && (int)floorf(pose.sel[pc.sel]) != pc.value) continue;
        for (int v = pc.v0; v < pc.v0 + pc.nv; v++) {
            const Vert &V = kVert[v];
            float acc[3] = {0, 0, 0}, an[3] = {0, 0, 0};
            for (int k = 0; k < V.nb; k++) {
                float q[3], r[3]; app(bm[V.b[k]], V.p, q); rot(bm[V.b[k]], V.n, r);
                for (int c = 0; c < 3; c++) { acc[c] += V.w[k] * q[c]; an[c] += V.w[k] * r[c]; }
            }
            normalize(an);
            memcpy(g_P[v], acc, 12); memcpy(g_N[v], an, 12);
        }
        for (int k = pc.t0; k < pc.t0 + pc.nt; k++) {
            const int a = pc.v0 + kTri[k][0], b = pc.v0 + kTri[k][1], c = pc.v0 + kTri[k][2];
            tri(g_P[a], g_P[b], g_P[c], g_N[a], g_N[b], g_N[c], kVert[a].uv, kVert[b].uv, kVert[c].uv, atlas->tex);
        }
    }
    // Sombrero: en el HatLocator, rígido.
    if (hat > 0) {
        load_hats(hat);
        if (hat <= (int)g_hats.size()) {
            const M &hl = wm[kHatLocator];
            for (int k = 0; k < g_hats[hat - 1].count; k++) {
                const HatPiece &pc = g_hat_pieces[g_hats[hat - 1].first + k];
                const Img *tx = hat_texture(hat, k);
                if (tx->tex < 0) continue;   // aún subiéndose: el cuadro siguiente
                static std::vector<float> P, N;
                P.resize((size_t)pc.nv * 3); N.resize((size_t)pc.nv * 3);
                for (int v = 0; v < pc.nv; v++) {
                    app(hl, pc.v + v * 8, &P[v * 3]); rot(hl, pc.v + v * 8 + 3, &N[v * 3]); normalize(&N[v * 3]);
                }
                for (int i = 0; i < pc.nt; i++) {
                    const int a = pc.t[i * 3], b = pc.t[i * 3 + 1], c = pc.t[i * 3 + 2];
                    if (a >= pc.nv || b >= pc.nv || c >= pc.nv) continue;
                    tri(&P[a * 3], &P[b * 3], &P[c * 3], &N[a * 3], &N[b * 3], &N[c * 3], pc.v + a * 8 + 6, pc.v + b * 8 + 6, pc.v + c * 8 + 6, tx->tex);
                }
            }
        }
    }
    // Del fondo hacia delante (lo necesita 3DS, sin z-buffer en la UI; en Mac lo resuelve el z-buffer igual).
    std::vector<int> order(g_tris.size());
    for (size_t i = 0; i < order.size(); i++) order[i] = (int)i;
    std::sort(order.begin(), order.end(), [](int a, int b) { return g_tris[a].z < g_tris[b].z; });
    static std::vector<float> xyzuv; static std::vector<unsigned> rgba;
    size_t i = 0;
    while (i < order.size()) {   // tandas de triángulos con la misma textura
        const int tex = g_tex[order[i]];
        xyzuv.clear(); rgba.clear();
        for (; i < order.size() && g_tex[order[i]] == tex; i++) {
            const int a = g_tris[order[i]].a;
            xyzuv.insert(xyzuv.end(), &g_xyzuv[(size_t)a * 5], &g_xyzuv[(size_t)a * 5] + 15);
            rgba.insert(rgba.end(), &g_rgba[a], &g_rgba[a] + 3);
        }
        tris_under(screen, tex, xyzuv.data(), rgba.data(), (int)rgba.size());
    }
}
}  // namespace ui

#endif
