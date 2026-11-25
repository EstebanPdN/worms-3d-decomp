// 0x800c96f0: el indicador de viento del HUD. Son dos mallas en anillo de 20 sectores y 4 coronas: colores desde la paleta del tema,
// con alfa según la intensidad; UV de las coronas según el tamaño, y el sector al que apunta el viento se resalta en blanco.
#include "native_common.h"

namespace {
struct Rgba { uint8_t r, g, b, a; };
struct Vec2 { float x, y; };
struct Array {
    w3d_u32 table;
    uint16_t references;  // +4
    char pad[0x12];
    int count;            // +0x18
    uint16_t locks;       // +0x1c
    uint16_t pad2;
    char data[1];         // +0x20
};
struct ArrayHolder { w3d_u32 table; char pad[0x10]; Ptr32<Array> array; };   // +0x14
struct RingMesh { w3d_u32 table; char pad[0x40]; Ptr32<ArrayHolder> uvs; Ptr32<ArrayHolder> colors; };   // +0x44, +0x48
struct RingNode { char pad[0x30]; Ptr32<RingMesh> mesh; };
struct Palette { char pad[0x20]; Rgba colors[5]; };   // +0x20, en orden inverso
struct GaugeMaterial { char pad[0x50]; float scale_u, scale_v; };
struct GaugeNode { char pad[0x34]; Ptr32<GaugeMaterial> material; };
struct Hud { char pad[0x3c]; Ptr32<GaugeNode> gauge[2]; };
struct WindGauge {
    char pad[0x3c];
    Ptr32<RingNode> rings[2];   // +0x3c
    char pad2[0x4c - 0x44];
    float directions[21][3];    // +0x4c (x, -, z) por sector, desde el 1
    char pad3[0x168 - (0x4c + 21 * 12)];
    float texture_scale;        // +0x168
};
struct Game { char pad[0xd0]; int theme; };
inline uint8_t to_byte(float value) {
    if (value != value || value <= 0) return 0;
    if (value >= 255) return 255;
    return (uint8_t)value;
}
const unsigned kAddRef = 0xc, kRelease = 0x10;
const int kSectors = 20;
}
extern "C" {
extern Ptr32<Hud> A804b1794;
extern Ptr32<Game> A804aaabc;
extern const float A80387bf8, A80387bfc, A80387c00, A80387c04, A80387c08, A80387c0c, A80387c10, A80387c14, A80387c18, A80387c1c, A80387c20, A80387c24, A80387c28, A80387c2c, A80387c30, A80387c34;
extern char A80387b04[], A80387b14[];
extern const float A8044b688, A8044b690;
w3d_u32 A801ef048(void *, int, int, int);
void A800fc2b0();
void A800fc330();
void A802fa988(void *, w3d_u32);
float A802e7e5c(float, float);
}
namespace {
template <class T> T *lock_array(Ptr32<Array> &array, int element) {
    if (array->references == 1) {
        array->locks++;
        return (T *)array->data;
    }
    return at<T>(A801ef048(&array, array->count, element, 2));
}
inline void *retained(void *object) {
    if (object) call_virtual(object, kAddRef);
    return object;
}
inline void release(void *object) {
    if (object) call_virtual(object, kRelease);
}
inline Rgba with_alpha(Rgba color, uint8_t alpha) {
    color.a = alpha;
    return color;
}
}
extern "C" w3d_u32 A800c96f0(Ptr32<WindGauge> self, Ptr32<const Vec2> center, w3d_u32, w3d_u32, w3d_u32, w3d_u32, w3d_u32, w3d_u32, float inner, float outer, float strength, float base) {
    WindGauge *gauge = self;
    RingMesh *mesh_a = (RingMesh *)retained(gauge->rings[0]->mesh.get());
    RingMesh *mesh_b = (RingMesh *)retained(gauge->rings[1]->mesh.get());
    ArrayHolder *colors_a_holder = (ArrayHolder *)retained(mesh_a->colors.get());
    Rgba *colors_a = lock_array<Rgba>(colors_a_holder->array, 4);
    ArrayHolder *colors_b_holder = (ArrayHolder *)retained(mesh_b->colors.get());
    Rgba *colors_b = lock_array<Rgba>(colors_b_holder->array, 4);
    ArrayHolder *uvs_holder = (ArrayHolder *)retained(mesh_b->uvs.get());
    const int uv_count = uvs_holder->array->count;
    Vec2 *uvs = lock_array<Vec2>(uvs_holder->array, 8);

    const Hud *hud = A804b1794;
    for (int i = 0; i < 2; i++) {
        GaugeMaterial *material = hud->gauge[i]->material;
        material->scale_u = gauge->texture_scale;
        material->scale_v = gauge->texture_scale * A80387bf8;
    }
    if (strength > A80387bfc) strength = A80387bfc;
    const float falloff = fused_madd(A80387c08 - strength / A80387bfc, A80387c0c, A80387c10);
    const float glow = fused_madd(base, A80387c00, A80387c04);
    const float fade = falloff * glow;

    Ptr32<char> key(A80387b04);
    Ptr32<char> text;
    ((w3d_u32 (*)(void *, void *))A800fc2b0)(&key, &text);
    Ptr32<Palette> palette(0);
    if (A804aaabc->theme == 7) {
        ((w3d_u32 (*)(void *, void *))A800fc330)(&text, &palette);
    } else {
        Ptr32<char> theme_key(A80387b14);
        ((w3d_u32 (*)(void *, void *))A800fc330)(&theme_key, &palette);
    }
    const Rgba *p = palette->colors;
    const uint8_t a1 = to_byte(glow * A80387c14), a2 = to_byte(glow * A80387c18), a3 = to_byte(glow * A80387c1c);
    const uint8_t b1 = to_byte(fade * A80387c20), b2 = to_byte(fade * A80387c24), b3 = to_byte(fade * A80387c28);
    const Rgba ring_a[5] = {with_alpha(p[4], 0), with_alpha(p[3], a1), with_alpha(p[2], a2), with_alpha(p[1], a3), with_alpha(p[0], 0)};
    const Rgba ring_b[5] = {with_alpha(p[4], b1), with_alpha(p[3], b2), with_alpha(p[2], b3), with_alpha(p[1], 0), with_alpha(p[0], 0)};

    colors_a[0] = ring_a[0];
    colors_b[0] = ring_b[0];
    const float uv_scale = A80387c2c;
    uvs[0] = {center->x * uv_scale, center->y * uv_scale};
    for (int i = 1; i <= kSectors; i++) {
        for (int ring = 0; ring < 4; ring++) {
            colors_a[i + ring * kSectors] = ring_a[ring + 1];
            colors_b[i + ring * kSectors] = ring_b[ring + 1];
        }
        const float dx = gauge->directions[i][0];
        const float dz = gauge->directions[i][2];
        const float cx = center->x, cz = center->y;
        uvs[i] = {fused_madd(dx, inner, cx) * uv_scale, fused_madd(dz, inner, cz) * uv_scale};
        uvs[i + kSectors] = {fused_madd(dx, outer, cx) * uv_scale, fused_madd(dz, outer, cz) * uv_scale};
        uvs[i + 2 * kSectors] = {fused_madd(dx, A80387bf8, cx) * uv_scale, fused_madd(dz, A80387bf8, cz) * uv_scale};
        uvs[i + 3 * kSectors] = {(dx + cx) * uv_scale, (dz + cz) * uv_scale};
    }
    A802fa988(uvs, uv_count << 3);

    // El sector del viento, en blanco con el alfa de sus coronas.
    const float sector = (A802e7e5c(A8044b690, A8044b688) / A80387c30) * A80387c34;
    const w3d_u32 index = sector >= 2147483648.0f ? (w3d_u32)ppc_ftoi(sector - 2147483648.0f) ^ 0x80000000u : (w3d_u32)ppc_ftoi(sector);
    colors_a[index + 40] = {0xff, 0xff, 0xff, ring_a[3].a};
    colors_a[index + 60] = {0xff, 0xff, 0xff, ring_a[4].a};

    release(uvs_holder);
    release(colors_b_holder);
    release(colors_a_holder);
    release(mesh_b);
    release(mesh_a);
    return 0;
}
