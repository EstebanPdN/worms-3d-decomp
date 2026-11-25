// Pasa la geometría calculada de un trozo de terreno a nodos de escena: posiciones y UV cuantizadas, y una malla por material.
#include "native_game.h"

namespace {
struct Sphere { w3d_u32 w[4]; };
struct ArrayNode {
    char pad[0x14];
    Ptr32<XomArray<char>> data;  // +0x14
    uint8_t format;              // +0x18
};
struct IndexNode {
    char pad[0x18];
    Ptr32<XomArray<uint16_t>> data;  // +0x18
};
struct RootNode {
    char pad[0x14];
    Ptr32<void> group;   // +0x14
    uint8_t format, stride;  // +0x18
};
struct GroupNode {
    char pad[0x14];
    Sphere bounds;       // +0x14
    char pad2[4];
    w3d_u32 cull;        // +0x28
};
struct MeshNode {
    char pad[0x14];
    Sphere bounds;       // +0x14
    char pad3[4];
    w3d_u32 cull;        // +0x28
    char pad2[0x30 - 0x2c];
    Ptr32<void> primitive;  // +0x30
    Ptr32<void> material;   // +0x34
};
struct IndexSet {
    char pad[0x18];
    Ptr32<void> triangles, outline;  // +0x18
    char pad2[0x24 - 0x20];
    Ptr32<void> indices;    // +0x24
};
struct Primitive {
    char pad[8];
    uint8_t flags;          // +8
    char pad2[0x44 - 9];
    Ptr32<void> uvs;        // +0x44
    Ptr32<void> texture;    // +0x48
    char pad3[0x50 - 0x4c];
    Ptr32<void> positions;  // +0x50
    w3d_u32 triangle_count; // +0x54
    char pad4[0x5c - 0x58];
    Ptr32<void> indices;    // +0x5c
};
struct LandGeometry {
    char pad[0x74];
    Ptr32<Ptr32<void>> materials;  // +0x74
    char pad2[0x21c - 0x78];
    Sphere bounds;          // +0x21c
    char pad3[0x230 - 0x22c];
    Ptr32<void> texture;    // +0x230
    char pad4[0x2c0 - 0x234];
    Ptr32<float> positions; // +0x2c0
    Ptr32<float> uvs;       // +0x2c4
    char pad5[0x2cc - 0x2c8];
    Ptr32<uint16_t> pairs;  // +0x2cc
    char pad6[0x990 - 0x2d0];
    Ptr32<Ptr32<uint16_t>> index_lists;  // +0x990
    char pad7[0x99c - 0x994];
    Ptr32<uint16_t> counts_begin, counts_end;  // +0x99c
    char pad8[0x9ae - 0x9a4];
    uint16_t vertices;      // +0x9ae
};
const w3d_u32 kPrimitiveVisible = 1;
}
extern "C" w3d_u32 A8020b680(void *type);
template <class T> static inline T *create(void *type) { return at<T>(A8020b680(type)); }
extern "C" {
extern char A804149f0, A804144f8, A804147b0, A80414890, A80414518, A804148f0, A804146e0;
extern Ptr32<void> A8037ceb0;
extern const float A8037cea8, A8037ceac;
void A801ef174(void *group, w3d_u32 field, w3d_u32 count, void *child);

// psq_st en s16 con escala 0: satura y trunca; NaN da 0.
static inline int16_t to_s16(float value) {
    if (value != value) return 0;
    if (value <= -32768.0f) return -32768;
    if (value >= 32767.0f) return 32767;
    return (int16_t)value;
}
// Guarda antes de sumar y soltar, como el original.
static inline void set_reference(Ptr32<void> &slot, void *object) {
    void *old = slot.get();
    slot = object;
    if (object) add_reference(object);
    release_if_set(old);
}

// 0x8007e10c
w3d_u32 A8007e10c(Ptr32<LandGeometry> self) {
    if (!self->vertices) return 0;
    RootNode *root = create<RootNode>(&A804149f0);
    root->format = 0x21;
    root->stride = 0x20;
    GroupNode *group = create<GroupNode>(&A804144f8);
    set_reference(root->group, group);

    ArrayNode *positions = create<ArrayNode>(&A804147b0);
    positions->format = 4;
    int16_t *out_position = (int16_t *)lock_xom_array(positions->data, self->vertices, 6, 1);
    ArrayNode *uvs = create<ArrayNode>(&A80414890);
    int16_t *out_uv = (int16_t *)lock_xom_array(uvs->data, self->vertices, 4, 1);
    const float position_scale = A8037cea8, uv_scale = A8037ceac;
    for (w3d_u32 i = 0; i < self->vertices; i++, out_position += 3) {
        const float *in = self->positions.get() + i * 3;
        for (int axis = 0; axis < 3; axis++) out_position[axis] = to_s16((float)(in[axis] * position_scale));
    }
    for (w3d_u32 i = 0; i < self->vertices; i++, out_uv += 2) {
        const float *in = self->uvs.get() + i * 2;
        for (int axis = 0; axis < 2; axis++) out_uv[axis] = to_s16((float)(in[axis] * uv_scale));
    }
    const Sphere bounds = self->bounds;
    const w3d_u32 materials = (w3d_u32)((int)(self->counts_end.v - self->counts_begin.v) >> 1);
    for (w3d_u32 material = 0; material < materials; material++) {
        const w3d_u32 count = self->counts_begin.get()[material];
        if (!count) continue;
        MeshNode *mesh = create<MeshNode>(&A80414518);
        IndexNode *triangles = create<IndexNode>(A8037ceb0.get());
        IndexNode *outline = create<IndexNode>(A8037ceb0.get());
        IndexSet *set = create<IndexSet>(&A804148f0);
        Primitive *primitive = create<Primitive>(&A804146e0);
        uint16_t *triangle_out = lock_xom_array(triangles->data, (int)self->counts_begin.get()[material], 2, 0);
        uint16_t *outline_out = lock_xom_array(outline->data, (int)self->counts_begin.get()[material], 2, 0);
        const w3d_u32 total = self->counts_begin.get()[material];
        const uint16_t *pair = self->pairs.get();
        for (w3d_u32 i = 0; i < total; i += 6, pair += 2, outline_out += 6) {
            outline_out[0] = pair[0];
            outline_out[1] = pair[0];
            outline_out[2] = pair[1];
            outline_out[3] = pair[0];
            outline_out[4] = pair[1];
            outline_out[5] = pair[1];
        }
        A802eee50(triangle_out, self->index_lists.get()[material].get(), total << 1);
        set_reference(set->indices, triangles);
        set_reference(set->triangles, triangles);
        set_reference(set->outline, outline);
        primitive->flags |= kPrimitiveVisible;
        set_reference(primitive->indices, set);
        set_reference(primitive->positions, positions);
        set_reference(primitive->texture, self->texture.get());
        set_reference(primitive->uvs, uvs);
        primitive->triangle_count = (w3d_u32)(self->counts_begin.get()[material] / 3);
        set_reference(mesh->primitive, primitive);
        set_reference(mesh->material, self->materials.get()[material].get());
        mesh->cull = 0;
        mesh->bounds = bounds;
        A801ef174(group, 0x2c, 3, mesh);
    }
    group->cull = 0;
    group->bounds = bounds;
    return h2g(root);
}
}
