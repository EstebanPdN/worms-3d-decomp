// Mallas del agua: reparto por tandas de una malla grande entre sus trozos, y construcción de la malla de una celda.
#include "native_game.h"

namespace {
struct Vec3s { int16_t x, y, z; };
struct ArrayOwner { char pad[0x14]; Ptr32<XomArray<char>> array; };
struct WaterChunk {
    char pad[0x14];
    char mesh[0x44 - 0x14];              // +0x14
    Ptr32<ArrayOwner> positions;         // +0x44
    Ptr32<ArrayOwner> indices;           // +0x48
    Ptr32<XomArray<w3d_u32>> colours;    // +0x4c
    char pad2[0x64 - 0x50];
    uint16_t total;                      // +0x64
    uint16_t count;                      // +0x66
    uint16_t remaining;                  // +0x68
    char pad3[0x6d - 0x6a];
    uint8_t hidden;                      // +0x6d
};
struct ChunkHolder { char pad[0x2c]; Ptr32<XomArray<Ptr32<WaterChunk>>> chunks; };
struct WaterScene {
    char pad[0x1d0];
    Ptr32<ArrayOwner> normals;            // +0x1d0
    w3d_u32 pad2;
    Ptr32<XomArray<uint16_t>> chunk_ids;  // +0x1d8
};
struct WaterStep { Ptr32<WaterScene> scene; Ptr32<WaterChunk> chunk; };
struct ChunkRegistry { char pad[0x2c]; Ptr32<XomArray<Ptr32<ChunkHolder>>> holders; };
template <class T> inline T *lock_all(Ptr32<XomArray<T>> &array, int element, int mode) {
    if (array->references == 1) {
        array->locks++;
        return array->data;
    }
    return at<T>(A801ef048(&array, array->count, element, mode));
}
inline uint16_t *lock_indices(WaterChunk *chunk) { return (uint16_t *)lock_all(chunk->indices->array, 2, 2); }
inline Vec3s *lock_positions(WaterChunk *chunk) { return (Vec3s *)lock_all(chunk->positions->array, 6, 2); }
}
extern "C" {
extern Ptr32<ChunkRegistry> A804ae5e4;
extern uint16_t A804aab58;  // Vértices por tanda.
void A8007ef70(void *self, void *colours, void *indices, void *positions, w3d_u32 count, void *normals, void *mesh);

// 0x8008ee80: dibuja la siguiente tanda. Con lista de trozos, la malla es la suma de todos y el avance se lleva en el primero.
w3d_u32 A8008ee80(Ptr32<void> self, Ptr32<WaterStep> step, Ptr32<w3d_u32> drew) {
    if (step->chunk->hidden) return 1;
    XomArray<uint16_t> *ids = step->scene->chunk_ids;
    WaterChunk *head, *chunk;
    uint16_t *indices;
    Vec3s *positions;
    char *normals;
    w3d_u32 offset;
    if (ids->count) {
        XomArray<Ptr32<ChunkHolder>> *holders = A804ae5e4->holders;
        head = chunk = holders->data[ids->data[0]]->chunks->data[0];
        if (!head->remaining) return 1;
        indices = lock_indices(chunk);
        WaterScene *scene = step->scene;
        positions = lock_positions(chunk);
        normals = scene->normals->array->data;
        offset = (uint16_t)(chunk->total - chunk->remaining);
        indices += offset;
        positions += offset;
        for (const uint16_t *id = &ids->data[1]; offset >= chunk->count; id++) {
            offset = (uint16_t)(offset - chunk->count);
            chunk = holders->data[*id]->chunks->data[0];
        }
    } else {
        head = chunk = step->chunk;
        if (!head->remaining) return 1;
        indices = lock_indices(chunk);
        WaterScene *scene = step->scene;
        positions = lock_positions(chunk);
        normals = scene->normals->array->data;
        offset = (uint16_t)(chunk->count - chunk->remaining);
        indices += offset;
        positions += offset;
    }
    const w3d_u32 left = (uint16_t)(chunk->count - offset);
    const w3d_u32 batch = A804aab58 < left ? A804aab58 : left;
    head->remaining -= batch;
    w3d_u32 *colours = lock_all(chunk->colours, 4, 2);
    A8007ef70(self.get(), colours + offset, indices, positions, batch, normals, chunk->mesh);
    *drew = 1;
    return head->remaining == 0;
}

// Malla de una celda de agua: vértices e índices ya calculados en el constructor, con material y color.
struct WaterVertexSource { char pad[0x14]; Ptr32<XomArray<w3d_u32>> vertices; };
struct IndexList { char pad[0x18]; Ptr32<XomArray<uint16_t>> indices; };
struct Primitive {
    char pad[8];
    uint8_t flags;                       // +8
    char pad2[0x48 - 9];
    Ptr32<WaterVertexSource> source;     // +0x48
    w3d_u32 pad3;
    Ptr32<void> material;                // +0x50
    w3d_u32 list_count;                  // +0x54
    w3d_u32 pad4;
    Ptr32<IndexList> list;               // +0x5c
    Ptr32<XomArray<uint16_t>> strip_lengths;  // +0x60
};
struct Colour { float r, g, b, a; };
struct DrawNode {
    char pad[0x14];
    Colour colour;                       // +0x14
    w3d_u32 pad2;
    w3d_u32 cleared;                     // +0x28
    char pad3[4];
    Ptr32<Primitive> primitive;          // +0x30
    Ptr32<void> texture;                 // +0x34
};
struct MeshGroup { char pad[0x14]; Ptr32<DrawNode> node; uint8_t second_key, first_key; };
struct WaterBuilder {
    char pad[0xc0];
    Ptr32<void> texture;                 // +0xc0
    char pad2[0x21c - 0xc4];
    float rgb[3];                        // +0x21c
    float alpha;                         // +0x228
    Ptr32<void> material;                // +0x22c
    char pad3[0x2b0 - 0x230];
    Ptr32<w3d_u32> vertices;             // +0x2b0
    char pad4[0x9a8 - 0x2b4];
    Ptr32<uint16_t> indices;             // +0x9a8
    uint16_t index_count;                // +0x9ac
    uint16_t vertex_count;               // +0x9ae
};
}
template <class T> static void set_reference(Ptr32<T> &slot, T *value) {
    T *old = slot;
    slot = value;
    if (value) add_reference(value);
    release_if_set(old);
}
extern "C" {
extern char A80414830, A804149f0, A80414518, A804148d0, A80414710;  // Descriptores de tipo.
w3d_u32 A8020b680(void *type);

// 0x800923f8: 0 si la celda no tiene geometría.
w3d_u32 A800923f8(Ptr32<WaterBuilder> self) {
    if (!self->vertex_count || !self->index_count) return 0;
    WaterVertexSource *source = at<WaterVertexSource>(A8020b680(&A80414830));
    A802eee50(lock_xom_array(source->vertices, self->vertex_count, 4, 1), self->vertices.get(), self->vertex_count * 4);
    const w3d_u32 group_address = A8020b680(&A804149f0);
    MeshGroup *group = at<MeshGroup>(group_address);
    group->first_key = 10;
    group->second_key = 11;
    DrawNode *node = at<DrawNode>(A8020b680(&A80414518));
    IndexList *list = at<IndexList>(A8020b680(&A804148d0));
    Primitive *primitive = at<Primitive>(A8020b680(&A80414710));
    A802eee50(lock_xom_array(list->indices, self->index_count, 2, 0), self->indices.get(), self->index_count * 2);
    primitive->flags |= 1;
    set_reference(primitive->list, list);
    set_reference(primitive->material, self->material.get());
    set_reference(primitive->source, source);
    primitive->list_count = 1;
    *lock_xom_array(primitive->strip_lengths, 1, 2, 0) = self->index_count;
    set_reference(node->primitive, primitive);
    set_reference(node->texture, self->texture.get());
    node->cleared = 0;
    node->colour = {self->rgb[0], self->rgb[1], self->rgb[2], self->alpha};
    set_reference(group->node, node);
    return group_address;
}
}
