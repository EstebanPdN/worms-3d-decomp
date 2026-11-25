// 0x8007bc2c: une los trozos de terreno de una celda en una sola malla. Concatena sus vértices en tres buffers compartidos y,
// por cada material, encadena las tiras de índices (repitiendo vértices para enlazarlas con triángulos degenerados), separando
// las capas opaca y transparente. El resultado queda en el primer trozo, dentro de un conmutador con las dos capas.
#include "native_common.h"

namespace {
template <class T> struct XomArray {
    w3d_u32 table;
    uint16_t references;  // +4
    char pad[0x18 - 6];
    int count;            // +0x18
    uint16_t locks;       // +0x1c
    uint16_t pad2;
    T data[1];            // +0x20
};
struct Sphere { float x, y, z, radius; };
template <class T> struct Holder { char pad[0x14]; Ptr32<XomArray<T>> array; };
struct Position { int16_t x, y, z; };
struct Geometry {
    char pad[8];
    w3d_u32 flags;                     // +0x08
    char pad2[0x44 - 0xc];
    Ptr32<Holder<w3d_u32>> colors;     // +0x44
    Ptr32<Holder<uint16_t>> uvs;       // +0x48
    char pad3[4];
    Ptr32<Holder<Position>> positions; // +0x50
    w3d_u32 strip_count;               // +0x54
    char pad4[4];
    Ptr32<char> indices;               // +0x5c: objeto con el array de índices en +0x18
    Ptr32<XomArray<uint16_t>> strip_lengths;  // +0x60
};
struct Node;
struct Node {
    char pad[0x14];
    Sphere bounds;          // +0x14
    w3d_u32 pad2;           // +0x24
    w3d_u32 parent;         // +0x28
    Ptr32<XomArray<Ptr32<Node>>> children;   // +0x2c
    Ptr32<Geometry> geometry;  // +0x30
    Ptr32<void> material;      // +0x34
    char pad3[4];
    int material_index;        // +0x3c
    char pad4[0x44 - 0x40];
    Ptr32<void> merged_positions;  // +0x44
    Ptr32<void> merged_uvs;        // +0x48
    char pad5[0x58 - 0x4c];
    Ptr32<void> bound;             // +0x58
    Ptr32<Node> layers;            // +0x5c
    char pad6[0x64 - 0x60];
    int16_t merged_index_count;    // +0x64
    int16_t index_count;           // +0x66
    int16_t has_indices;           // +0x68
};
struct Holder14 { char pad[0x14]; Ptr32<Node> child; };
struct LayerPair { char pad[0x14]; Ptr32<Node> child; uint8_t mode_b; uint8_t mode_a; };   // +0x18 y +0x19 son bytes crudos
struct Mesher {
    char pad[0x80];
    Ptr32<Ptr32<void>> opaque_materials;     // +0x80
    char pad2[0xbc - 0x84];
    Ptr32<Ptr32<void>> alpha_materials;      // +0xbc
    char pad3[0x22c - 0xc0];
    Ptr32<Holder<Position>> vertex_holder;   // +0x22c
    char pad4[0x900 - 0x230];
    Ptr32<Ptr32<uint16_t>> opaque_cursors;   // +0x900
    char pad5[0x93c - 0x904];
    Ptr32<uint16_t> materials_begin;         // +0x93c
    Ptr32<uint16_t> materials_end;           // +0x940
    char pad6[4];
    Ptr32<Ptr32<uint16_t>> alpha_cursors;    // +0x948
};
struct Cell { char pad[0x1d8]; Ptr32<XomArray<uint16_t>> pieces; };
struct World { char pad[0x2c]; Ptr32<XomArray<Ptr32<Node>>> nodes; };
const unsigned kAddRef = 0xc, kRelease = 0x10;
const int kMaxPieces = 10;
template <class T> void assign_ref(Ptr32<T> &slot, T *value) {
    T *previous = slot;
    slot = value;
    if (value) call_virtual(value, kAddRef);
    if (previous) call_virtual(previous, kRelease);
}
}
extern "C" {
extern Ptr32<World> A804ae5e4;
extern char A804149f0[], A804144f8[], A804147b0[], A80414890[], A80414840[], A8041b5a8[], A804148d0[], A80414710[];
// Tablas estáticas de la pasada, en bytes de 16 bits por material.
extern uint16_t A80430860[0x180], A80430b60[0x180], A80430e60[0x180], A80431160[0x180];
extern Ptr32<Node> A80430770[kMaxPieces], A80430170[kMaxPieces], A80430798[kMaxPieces], A804307c0[kMaxPieces];
extern w3d_u32 A80430120[kMaxPieces], A80430148[kMaxPieces];
extern Ptr32<Position> A804307e8[kMaxPieces];
extern Ptr32<w3d_u32> A80430810[kMaxPieces];
extern Ptr32<uint16_t> A80430838[kMaxPieces];
void A801f53bc(Sphere *out, const Sphere *a, const Sphere *b);
w3d_u32 A8020b680(void *type);
void A801ef174(void *list, w3d_u32 descriptor, w3d_u32 kind, void *item);
w3d_u32 A801ef380(void *list, w3d_u32 descriptor, w3d_u32 kind, w3d_u32 first, w3d_u32 count, float, float, float, float, float, float, float, float);
w3d_u32 A801ef048(void *reference, int count, int element, int mode);
void A802eefe0(void *, w3d_u32, w3d_u32);
}
namespace {
template <class T> T *lock_array(Ptr32<XomArray<T>> &array, int count, int mode) {
    if (array->references == 1 && count == array->count) {
        array->locks++;
        return array->data;
    }
    return at<T>(A801ef048(&array, count, sizeof(T), mode));
}
template <class T> T *make(char *type) { return at<T>(A8020b680(type)); }

void take_piece_buffers(int piece, const Node *strip, int *vertex_count, Sphere *bounds) {
    const Geometry *geometry = strip->geometry;
    A804307e8[piece].v = h2g(geometry->positions->array->data);
    A80430810[piece].v = h2g(geometry->colors->array->data);
    XomArray<uint16_t> *uvs = geometry->uvs->array;
    *vertex_count = uvs->count;
    A80430838[piece].v = h2g(uvs->data);
    if (bounds->radius == 0.0f) *bounds = strip->bounds;
    else A801f53bc(bounds, bounds, &strip->bounds);
}
const XomArray<uint16_t> *strip_indices(const Node *strip) {
    return *(const Ptr32<XomArray<uint16_t>> *)(strip->geometry->indices.get() + 0x18);
}
// Reserva: por cada material, las longitudes más dos índices de enlace y, si hace falta, uno de paridad.
void count_indices(const XomArray<Ptr32<Node>> *strips, uint16_t *counts) {
    for (int i = 0; i < strips->count; i++) {
        const Node *strip = strips->data[i];
        const int material = strip->material_index;
        const uint16_t length = (uint16_t)strip_indices(strip)->count;
        if (counts[material] == 0) counts[material] = length;
        else counts[material] = length + ((counts[material] + 3) & 0xfffe);
    }
}
// Encadena las tiras: repite el primer índice de cada una salvo la primera y el último, y mantiene par el número de caras.
void emit_strips(const XomArray<Ptr32<Node>> *strips, Ptr32<uint16_t> *cursors, uint16_t *written, const uint16_t *counts, uint16_t base) {
    for (int i = 0; i < strips->count; i++) {
        const Node *strip = strips->data[i];
        const int material = strip->material_index;
        const XomArray<uint16_t> *indices = strip_indices(strip);
        int emitted = indices->count;
        const uint16_t length = (uint16_t)emitted;
        uint16_t *out = cursors[material];
        if (written[material] != 0) {
            *out++ = indices->data[0] + base;
            emitted++;
        }
        for (uint16_t j = 0; j < length; j++) *out++ = indices->data[j] + base;
        if (written[material] + emitted < counts[material]) {
            if ((written[material] + emitted) & 1) {
                *out = out[-1];
                out++;
                emitted++;
            }
            *out = out[-1];
            out++;
            emitted++;
        }
        cursors[material].v = h2g(out);
        written[material] += (uint16_t)emitted;
    }
}
// Un nodo por material y capa con su tira unida.
void add_material_node(Mesher *self, int material, uint16_t count, Ptr32<uint16_t> *cursors, Ptr32<void> *materials, Holder<w3d_u32> *colors, Holder<uint16_t> *uvs,
                       Node *layer, const Sphere &bounds) {
    Node *node = make<Node>(A8041b5a8);
    node->material_index = material;
    char *indices = make<char>(A804148d0);
    Geometry *geometry = make<Geometry>(A80414710);
    cursors[material].v = h2g(lock_array(*(Ptr32<XomArray<uint16_t>> *)(indices + 0x18), count, 0));
    geometry->flags |= 1;
    assign_ref(*(Ptr32<char> *)&geometry->indices, indices);
    assign_ref(*(Ptr32<Holder<Position>> *)&geometry->positions, (Holder<Position> *)self->vertex_holder);
    assign_ref(geometry->uvs, uvs);
    assign_ref(geometry->colors, colors);
    geometry->strip_count = 1;
    *lock_array(geometry->strip_lengths, 1, 0) = count;
    assign_ref(node->geometry, geometry);
    assign_ref(node->material, materials[material].get());
    node->parent = 0;
    node->bounds = bounds;
    A801ef174(layer, 0x2c, 3, node);
}
}

extern "C" void A8007bc2c(Ptr32<Mesher> self, Ptr32<Cell> cell) {
    XomArray<Ptr32<Node>> *nodes = A804ae5e4->nodes;
    A802eefe0(A80430860, 0, 0x300);
    A802eefe0(A80430b60, 0, 0x300);
    A802eefe0(A80430e60, 0, 0x300);
    A802eefe0(A80431160, 0, 0x300);

    const XomArray<uint16_t> *piece_list = cell->pieces;
    const w3d_u32 pieces = piece_list->count;
    for (w3d_u32 i = 0; i < pieces; i++) A80430770[i] = nodes->data[piece_list->data[i]]->children->data[0];
    for (w3d_u32 i = 0; i < pieces; i++) A80430170[i] = A80430770[i]->layers;
    for (w3d_u32 i = 0; i < pieces; i++) {
        const Node *layers = A80430170[i];
        if (!layers) {
            A804307c0[i].v = 0;
            A80430798[i].v = 0;
        } else {
            A80430798[i] = ((Holder14 *)layers->children->data[0].get())->child;
            A804307c0[i] = ((Holder14 *)layers->children->data[1].get())->child;
        }
    }

    int total_vertices = 0;
    Sphere bounds;
    bounds.radius = 0.0f;
    for (w3d_u32 i = 0; i < pieces; i++) {
        A804307e8[i].v = 0;
        A80430120[i] = total_vertices;
        if (!A80430170[i]) {
            A80430148[i] = 0;
            continue;
        }
        int vertices = 0;
        const XomArray<Ptr32<Node>> *opaque = A80430798[i]->children;
        if (opaque->count != 0) take_piece_buffers(i, opaque->data[0], &vertices, &bounds);
        count_indices(opaque, A80430860);
        const XomArray<Ptr32<Node>> *alpha = A804307c0[i]->children;
        if (alpha->count != 0 && vertices == 0) take_piece_buffers(i, alpha->data[0], &vertices, &bounds);
        count_indices(alpha, A80430b60);
        A80430148[i] = vertices;
        total_vertices += vertices;
    }
    if (total_vertices == 0) return;

    LayerPair *opaque_switch = make<LayerPair>(A804149f0);
    opaque_switch->mode_a = 2;
    opaque_switch->mode_b = 3;
    LayerPair *alpha_switch = make<LayerPair>(A804149f0);
    alpha_switch->mode_a = 4;
    alpha_switch->mode_b = 5;
    Node *opaque_layer = make<Node>(A804144f8);
    Node *root = make<Node>(A804144f8);
    Node *alpha_layer = make<Node>(A804144f8);

    Holder<Position> *vertices = make<Holder<Position>>(A804147b0);
    assign_ref(self->vertex_holder, vertices);
    *(uint8_t *)((char *)vertices + 0x18) = 4;
    Position *out_positions = lock_array(self->vertex_holder->array, total_vertices, 1);
    Holder<w3d_u32> *colors = make<Holder<w3d_u32>>(A80414890);
    w3d_u32 *out_colors = lock_array(colors->array, total_vertices, 1);
    Holder<uint16_t> *uvs = make<Holder<uint16_t>>(A80414840);
    uint16_t *out_uvs = lock_array(uvs->array, total_vertices, 1);
    for (w3d_u32 i = 0; i < pieces; i++) {
        if (!A80430170[i]) continue;
        const int n = A80430148[i];
        memcpy(out_positions, A804307e8[i].get(), n * sizeof(Position));
        memcpy(out_colors, A80430810[i].get(), n * sizeof(w3d_u32));
        memcpy(out_uvs, A80430838[i].get(), n * sizeof(uint16_t));
        out_positions += n;
        out_colors += n;
        out_uvs += n;
    }

    const w3d_u32 materials = (self->materials_end.v - self->materials_begin.v) >> 1;
    for (w3d_u32 m = 0; m < materials; m++) {
        if (A80430860[m]) add_material_node(self, m, A80430860[m], self->opaque_cursors, self->opaque_materials, colors, uvs, opaque_layer, bounds);
        if (A80430b60[m]) add_material_node(self, m, A80430b60[m], self->alpha_cursors, self->alpha_materials, colors, uvs, alpha_layer, bounds);
    }
    for (w3d_u32 i = 0; i < pieces; i++) {
        if (!A80430170[i]) continue;
        // El original lee la mitad baja de una palabra: en el anfitrión es el truncado a 16 bits.
        const uint16_t base = (uint16_t)A80430120[i];
        emit_strips(A80430798[i]->children, self->opaque_cursors, A80430e60, A80430860, base);
        emit_strips(A804307c0[i]->children, self->alpha_cursors, A80431160, A80430b60, base);
    }

    Node *const layers[3] = {opaque_layer, alpha_layer, root};
    for (Node *layer : layers) {
        layer->parent = 0;
        layer->bounds = bounds;
    }
    assign_ref(opaque_switch->child, opaque_layer);
    assign_ref(alpha_switch->child, alpha_layer);
    A801ef174(root, 0x2c, 3, opaque_switch);
    A801ef174(root, 0x2c, 3, alpha_switch);

    int16_t index_total = 0;
    bool any_indices = false;
    for (w3d_u32 i = 0; i < pieces; i++) {
        Node *piece = A80430770[i];
        Node *old_layers = piece->layers;
        piece->layers.v = 0;
        if (old_layers) call_virtual(old_layers, kRelease);
        A801ef380(piece, 0x2c, 3, 0, piece->children->count, 0, 0, 0, 0, 0, 0, 0, 0);
        if (piece->bound) A801ef174(piece, 0x2c, 3, piece->bound.get());
        index_total += piece->index_count;
        if (piece->has_indices) any_indices = true;
    }
    Node *first = A80430770[0];
    first->merged_index_count = index_total;
    first->has_indices = any_indices ? index_total : 0;
    assign_ref(*(Ptr32<Holder<Position>> *)&first->merged_positions, (Holder<Position> *)self->vertex_holder);
    assign_ref(*(Ptr32<Holder<uint16_t>> *)&first->merged_uvs, uvs);
    assign_ref(first->layers, root);
    A801ef174(first, 0x2c, 3, root);
    first->bounds = bounds;
    nodes->data[piece_list->data[0]]->bounds = bounds;
}
