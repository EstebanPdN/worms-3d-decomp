// Terreno al cargar: cajas, centro, piezas enlazadas, tablas de qué trozo tapa a cuál según la luz, y datos de terreno guardados.
#include "native_game.h"

namespace {
struct Vector3 { float x, y, z; };
struct Matrix3x4 { float m[12]; };
struct Vector3Raw { w3d_u32 w[3]; };
struct LandChunk {
    char pad[0x14];
    Vector3 centre;         // +0x14
    float radius;           // +0x20
    char pad2[0x4c - 0x24];
    Ptr32<XomArray<w3d_u32>> heights;  // +0x4c
};
struct LandMesh {
    char pad[0x2c];
    Ptr32<XomArray<Ptr32<LandChunk>>> chunks;  // +0x2c
};
struct LandOwner {
    char pad[0x44];
    w3d_u32 seed;           // +0x44
    Vector3 box_min;        // +0x48
    Vector3 box_size;       // +0x54
    char pad2[0x68 - 0x60];
    Vector3 centre;         // +0x68
    char pad3[0x3100 - 0x74];
    Ptr32<void> scene;      // +0x3100
};
struct LandList { Ptr32<Ptr32<void>> begin, end; int size() const { return (int)(end.v - begin.v) >> 2; } };
}
extern "C" {
extern LandList A8043bb64;
extern w3d_u32 A804b1828, A804aad90, A804adde4;
extern Ptr32<uint16_t> A804b182c, A804b1834;
extern Ptr32<w3d_u32> A804b1830;
extern Matrix3x4 A8045e748;
extern const float A80382cb8, A80382cbc, A80382cc0, A80382cc4, A80382d0c, A80382d10, A80382d14;
extern const char A80382b38[], A80382ca0[], A80382cfc[];
w3d_u32 A800bb548(void *self, void *node, Vector3 *at, Matrix3x4 *transform, int parent);
void A800bc410(void *self);
void A800b3d78(void *land);
w3d_u32 A800b8140(void *land);
w3d_u32 A800b4d98(void *land);
void A80251398(void *chunk, w3d_u32 value);
void A8008e7d4(void *mesh, void *chunk);
w3d_u32 A80200050(void *object);
w3d_u32 A8008ed18(w3d_u32 value, w3d_u32 id);
void A8008eb98();
w3d_u32 A80343994();
w3d_u32 A801fdbec(w3d_u32 object, w3d_u32 value);
w3d_u32 A80344278();
void A801fe314(w3d_u32 object);
void A801ea57c();
w3d_u32 A80209b78();
w3d_u32 A800fc270(void *key, void *out, ...);
w3d_u32 A800fc2f0(void *key, void *out, ...);
w3d_u32 A800fc4c8(float value, void *key);
float A802e82c0(float value);
w3d_u32 A802098d8(void *pool, w3d_u32 bytes);
w3d_u32 A801ef048(void *reference, int count, int element, int mode);
void A802eee50(void *to, const void *from, w3d_u32 bytes);

static inline LandMesh *mesh_of(int land) { return at<LandMesh>(A800b4d98(A8043bb64.begin[land].get())); }

// El trozo b tapa a a mirando en la dirección de la luz: b queda por delante y dentro del cilindro de sus radios sumados.
static bool shadowed(const LandChunk *a, const LandChunk *b, const Vector3 &light, float bias, float own_minimum, bool same_land) {
    const Vector3 d = {(float)(a->centre.x - b->centre.x), (float)(a->centre.y - b->centre.y), (float)(a->centre.z - b->centre.z)};
    float along = fused_madd(d.x, light.x, (float)(d.y * light.y));
    along = fused_madd(d.z, light.z, along);
    const float radii = (float)(b->radius + a->radius);
    if (!(along < (float)(bias + radii))) return false;
    if (same_land) {
        if (!(along > own_minimum)) return false;
    } else {
        if (!(along > -radii)) return false;
    }
    const float limit = fused_madd(radii, radii, (float)(along * along));
    float distance = fused_madd(d.x, d.x, (float)(d.y * d.y));
    distance = fused_madd(d.z, d.z, distance);
    return distance < limit;
}
// 0x800bdcf8: tablas de sombras entre trozos. A804b182c[tierra] da el primer trozo; A804b1830[trozo], su primer par; A804b1834, los pares (tierra << 6 | trozo).
w3d_u32 A800bdcf8() {
    Vector3 light;
    Ptr32<const char> key(A80382cfc);
    ((w3d_u32 (*)(void *, void *))A800fc2f0)(&key, &light);
    const float bias = A80382d0c, own_minimum = A80382d14;
    const float length = A802e82c0(fused_madd(light.z, light.z, fused_madd(light.x, light.x, (float)(light.y * light.y))));
    const float scale = (float)(A80382d10 / length);
    light = {(float)(light.x * scale), (float)(light.y * scale), (float)(light.z * scale)};

    const int lands = A8043bb64.size();
    int total_chunks = 0;
    for (int land = 0; land < lands; land++) total_chunks += mesh_of(land)->chunks->count;
    A804b182c.v = A802098d8(&A804adde4, (w3d_u32)((lands + 1) << 1));
    A804b1830.v = A802098d8(&A804adde4, (w3d_u32)((total_chunks + 1) << 2));

    int pairs = 0;
    for (int land = 0; land < lands; land++) {
        XomArray<Ptr32<LandChunk>> *chunks = mesh_of(land)->chunks;
        const w3d_u32 count = (w3d_u32)chunks->count;
        for (w3d_u32 chunk = 0; chunk < count; chunk++) {
            const LandChunk *a = chunks->data[chunk];
            for (int other = 0; other < lands; other++) {
                XomArray<Ptr32<LandChunk>> *others = mesh_of(other)->chunks;
                const w3d_u32 other_count = (w3d_u32)others->count;
                const bool same_land = land == other;
                for (w3d_u32 i = 0; i < other_count; i++) {
                    if (same_land && chunk == i) continue;
                    if (shadowed(a, others->data[i], light, bias, own_minimum, same_land)) pairs++;
                }
            }
        }
    }
    A804b1834.v = A802098d8(&A804adde4, (w3d_u32)(pairs << 1));

    int written = 0, chunk_index = 0;
    for (int land = 0; land < lands; land++) {
        XomArray<Ptr32<LandChunk>> *chunks = mesh_of(land)->chunks;
        const w3d_u32 count = (w3d_u32)chunks->count;
        A804b182c.get()[land] = (uint16_t)chunk_index;
        for (w3d_u32 chunk = 0; chunk < count; chunk++) {
            A804b1830.get()[chunk_index++] = (w3d_u32)written;
            const LandChunk *a = chunks->data[chunk];
            for (int other = 0; other < lands; other++) {
                XomArray<Ptr32<LandChunk>> *others = mesh_of(other)->chunks;
                const w3d_u32 other_count = (w3d_u32)others->count;
                const bool same_land = land == other;
                for (w3d_u32 i = 0; i < other_count; i++) {
                    if (same_land && chunk == i) continue;
                    if (shadowed(a, others->data[i], light, bias, own_minimum, same_land)) A804b1834.get()[written++] = (uint16_t)((i & 0x3f) | ((w3d_u32)other << 6));
                }
            }
        }
    }
    A804b182c.get()[lands] = (uint16_t)chunk_index;
    A804b1830.get()[chunk_index] = (w3d_u32)written;
    return 0;
}

// 0x800bc7c4
w3d_u32 A800bc7c4(Ptr32<LandOwner> self, Ptr32<void> node, w3d_u32 poll_value, Ptr32<const w3d_u32> saved, w3d_u32 saved_words) {
    Vector3 at_origin = {A80382cb8, A80382cb8, A80382cb8};
    Vector3Raw translation;
    memset(&translation, 0, sizeof translation);
    Matrix3x4 identity = A8045e748;
    self->box_min = {A80382cbc, A80382cbc, A80382cbc};
    self->box_size = {A80382cc0, A80382cc0, A80382cc0};
    self->centre = {A80382cb8, A80382cb8, A80382cb8};
    Matrix3x4 transform;
    memcpy(&transform, &identity, 36);
    memcpy(&transform.m[9], &translation, sizeof translation);
    A800bb548(self.get(), node.get(), &at_origin, &transform, -1);
    A804b1828 = self->seed;
    const float half = A80382cc4;
    self->centre = {(float)((float)(self->box_size.x + self->box_min.x) * half), (float)((float)(self->box_size.y + self->box_min.y) * half), (float)((float)(self->box_size.z + self->box_min.z) * half)};
    call_virtual<void>(self->scene.get(), 0x4c, &self->centre, (void *)0);
    self->centre = {-self->centre.x, -self->centre.y, -self->centre.z};
    A800bc410(self.get());

    const int lands = A8043bb64.size();
    Ptr32<LandChunk> *last_chunks = nullptr;
    for (int land = 0; land < lands; land++) {
        void *piece = A8043bb64.begin[land].get();
        A800b3d78(piece);
        A800b8140(piece);
        XomArray<Ptr32<LandChunk>> *chunks = mesh_of(land)->chunks;
        const w3d_u32 count = (w3d_u32)chunks->count;
        last_chunks = chunks->data;
        for (w3d_u32 i = 0; i < count; i++) {
            A80251398(chunks->data[i].get(), 1);
            A8008e7d4(mesh_of(land), chunks->data[i].get());
        }
    }
    call_virtual<void>(mesh_of(0), 0x14);
    call_virtual<void>(last_chunks[0].get(), 0x14);
    A80200050(g2h(call_virtual<w3d_u32>(mesh_of(0), 0x14)));
    A80200050(g2h(call_virtual<w3d_u32>(last_chunks[0].get(), 0x14)));
    A800bdcf8();

    if (saved) {
        const w3d_u32 *cursor = saved.get();
        const w3d_u32 *const end = cursor + saved_words;
        for (int land = 0; land < A8043bb64.size(); land++) {
            XomArray<Ptr32<LandChunk>> *chunks = mesh_of(land)->chunks;
            const w3d_u32 count = (w3d_u32)chunks->count;
            for (w3d_u32 i = 0; i < count; i++) {
                if (cursor >= end) continue;
                const w3d_u32 words = *cursor++;
                w3d_u32 *heights = lock_xom_array(chunks->data[i]->heights, (int)words, 4, 0);
                A802eee50(heights, cursor, words << 2);
                cursor += words;
            }
        }
    }
    while (A8008ed18(poll_value, 0x7d0)) {
        A801fdbec(A80343994(), 1);
        A801fe314(A80344278());
        if (A804aad90) ((void (*)(w3d_u32, w3d_u32))g2h(A804aad90))(0, 1);
    }
    A8008eb98();
    float level;
    Ptr32<const char> read_key(A80382b38);
    ((w3d_u32 (*)(void *, void *))A800fc270)(&read_key, &level);
    Ptr32<const char> write_key(A80382ca0);
    A800fc4c8(level, &write_key);
    A801ea57c();
    A80209b78();
    return 0;
}
}
