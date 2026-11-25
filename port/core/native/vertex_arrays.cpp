// Enlace de los arrays de vértices de una malla con GX. El visitante de la malla recibe cada propiedad como un mensaje con el
// array XOM en +0x14; flushea la caché si el array está sucio y llama a GXSetArray. Si la malla tiene piel, posiciones y normales
// se transforman antes a un búfer temporal.
#include "native_common.h"

namespace {
struct XomArray {
    char pad[0x18];
    int count;
    uint16_t dirty;
    uint16_t pad2;
    char data[1];
};
struct ArrayMessage {
    char pad[0x14];
    Ptr32<XomArray> array;
    uint8_t component_shift;   // +0x18: bits fraccionarios de la cuantización.
};
struct SkinType { char pad[0x14]; Ptr32<SkinType> parent; };
struct Skin {
    w3d_u32 table;
    char pad[0x10];
    Ptr32<XomArray> weights_positions;   // +0x14
    uint16_t influences;                 // +0x18
    char pad2[2];
    Ptr32<XomArray> weights;             // +0x1c: solo en la piel con influencias.
};
struct BoneInstance { char pad[0x30]; float world[12]; };
// La clase que hereda del visitante en +4: un mensaje llega con el puntero a esa base.
struct MeshBinder {
    char pad[0x7c];
    Ptr32<Skin> skin;                  // +0x7c
    Ptr32<Ptr32<BoneInstance>> bones;  // +0x80
    w3d_u32 bone_count;                // +0x84
    char pad2[0xf8 - 0x88];
    float axis_x;                      // +0xf8
    char pad3[0x108 - 0xfc];
    float axis_y;                      // +0x108
    char pad4[0x118 - 0x10c];
    float axis_z;                      // +0x118
    w3d_u32 bound_count;               // +0x11c
    w3d_u32 bound_mask;                // +0x120
    char pad5[0x13c - 0x124];
    uint8_t position_shift;            // +0x13c
    uint8_t normal_shift;              // +0x13d
    uint8_t tex0_shift;                // +0x13e
};
enum Attribute { kPosition = 9, kNormal = 10, kColor0 = 11, kTex0 = 13 };
inline MeshBinder *from_visitor(w3d_u32 visitor) { return visitor ? at<MeshBinder>(visitor - 4) : nullptr; }
}

extern "C" {
void A802fa988(void *, w3d_u32);                  // DCStoreRange
void A80307d88(w3d_u32, void *, w3d_u32);         // GXSetArray
w3d_u32 A8016a21c(void *, w3d_u32);               // búfer temporal del cuadro
void A8016805c(void *);
void A8016808c(void *);
void A801a1460(void *, w3d_u32, void *, void *, void *, void *, w3d_u32, w3d_u32, unsigned long);
void A801a15f8(void *, w3d_u32, void *, void *, void *, void *, w3d_u32, w3d_u32, unsigned long);
void A801a1250(void *, w3d_u32, void *, void *, void *, w3d_u32);
void A802134fc(void *);
w3d_u32 A80212fd4(w3d_u32);
w3d_u32 A803413d8(w3d_u32);
extern w3d_u32 A804b1884;
extern char A80363654[];   // Tipo de la piel con influencias por vértice.
}

namespace {
void flush_if_dirty(XomArray *array, w3d_u32 bytes) {
    if (!array->dirty) return;
    A802fa988(array->data, bytes);
    array->dirty = 0;
}
void set_array(MeshBinder *binder, Attribute attribute, void *data, w3d_u32 stride, w3d_u32 mask) {
    A80307d88(attribute, data, stride);
    binder->bound_mask |= mask;
    binder->bound_count++;
}
// ¿El objeto es de ese tipo o de uno derivado? La raíz de la jerarquía es su propio padre.
bool is_kind_of(Skin *object, const char *type) {
    w3d_u32 current = call_virtual(object, 0x14);
    while ((const char *)g2h(current) != type) {
        const w3d_u32 parent = at<SkinType>(current)->parent.v;
        if (parent == current) return false;
        current = parent;
    }
    return true;
}
void bone_matrices(const MeshBinder *binder, w3d_u32 *out) {
    for (w3d_u32 i = 0; i < binder->bone_count; i++) out[i] = h2g(binder->bones[i]->world);
}
}

extern "C" {
// Posiciones con piel en coma flotante (0x80169094): piel con influencias o transformación rígida con los huesos.
w3d_u32 A80169094(w3d_u32 visitor, Ptr32<ArrayMessage> message) {
    MeshBinder *binder = from_visitor(visitor);
    XomArray *positions = message->array;
    const int count = positions->count;
    if (count == 0) return 0;
    const w3d_u32 bytes = count * 12;
    flush_if_dirty(positions, bytes);

    Skin *skin = binder->skin;
    if (!skin) {
        set_array(binder, kPosition, positions->data, 12, 1);
        return 0;
    }
    if (is_kind_of(skin, A80363654)) {
        void *rest = skin->weights->data, *weights = skin->weights_positions->data;
        const w3d_u32 temp = A8016a21c(binder, bytes);
        w3d_u32 *matrices = (w3d_u32 *)__builtin_alloca(binder->bone_count * 4 + 8);
        bone_matrices(binder, matrices);
        A801a1460(positions->data, skin->influences, weights, rest, matrices, g2h(temp), count, 12, 12);
        A8016805c(arg(A804b1884));
        A802fa988(g2h(temp), bytes);
        set_array(binder, kPosition, g2h(temp), 12, 1);
        return 0;
    }
    // Sin influencias: cada vértice pertenece a un hueso, con la lista de huesos en un vector.
    void *indices = binder->skin->weights_positions->data;
    const w3d_u32 temp = A8016a21c(binder, bytes);
    const w3d_u32 n = binder->bone_count;
    w3d_u32 *matrices = nullptr;
    if (n) {
        w3d_u32 list = A80212fd4(n * 4);
        if (!list) list = A803413d8(n * 4);
        matrices = at<w3d_u32>(list);
        memset(matrices, 0, n * 4);
    }
    bone_matrices(binder, matrices);
    A801a1250(positions->data, binder->bone_count, indices, matrices, g2h(temp), count);
    A8016805c(arg(A804b1884));
    A802fa988(g2h(temp), bytes);
    set_array(binder, kPosition, g2h(temp), 12, 1);
    if (matrices) A802134fc(matrices);
    return 0;
}

// Normales en coma flotante. Si los ejes del objeto están casi a cero no hay rotación: con piel se calculan las normales
// con los huesos, y sin piel con influencias no se enlaza nada.
w3d_u32 A801694e8(w3d_u32 visitor, Ptr32<ArrayMessage> message) {
    MeshBinder *binder = from_visitor(visitor);
    XomArray *normals = message->array;
    const int count = normals->count;
    if (count == 0) return 0;
    const w3d_u32 bytes = count * 12;
    flush_if_dirty(normals, bytes);

    bool use_skin = false;
    if (binder->skin) {
        const float x = binder->axis_x, y = binder->axis_y, z = binder->axis_z;
        extern float A803a5030;
        const float length2 = fused_madd(z, z, fused_madd(x, x, y * y));
        use_skin = length2 < A803a5030;
    }
    if (!use_skin) {
        set_array(binder, kNormal, normals->data, 12, 4);
        return 0;
    }
    Skin *skin = binder->skin;
    if (!skin || !is_kind_of(skin, A80363654)) return 0;
    void *rest = skin->weights->data, *weights = skin->weights_positions->data;
    const w3d_u32 temp = A8016a21c(binder, bytes);
    w3d_u32 *matrices = (w3d_u32 *)__builtin_alloca(binder->bone_count * 4 + 8);
    bone_matrices(binder, matrices);
    A801a15f8(normals->data, skin->influences, weights, rest, matrices, g2h(temp), count, 12, 12);
    A8016808c(arg(A804b1884));
    A802fa988(g2h(temp), bytes);
    set_array(binder, kNormal, g2h(temp), 12, 4);
    return 0;
}

// Arrays cuantizados de la malla sin piel: en las mallas con piel, posición y normal se ignoran porque ya llegan en float.
w3d_u32 A8016939c(w3d_u32 visitor, Ptr32<ArrayMessage> message) {
    MeshBinder *binder = from_visitor(visitor);
    XomArray *positions = message->array;
    if (positions->count == 0) return 0;
    flush_if_dirty(positions, positions->count * 6);
    if (binder->skin) return 0;
    set_array(binder, kPosition, positions->data, 6, 2);
    binder->position_shift = message->component_shift;
    return 0;
}
w3d_u32 A80169704(w3d_u32 visitor, Ptr32<ArrayMessage> message) {
    MeshBinder *binder = from_visitor(visitor);
    XomArray *normals = message->array;
    if (normals->count == 0) return 0;
    flush_if_dirty(normals, normals->count * 6);
    if (binder->skin) return 0;
    set_array(binder, kNormal, normals->data, 6, 8);
    binder->normal_shift = message->component_shift;
    return 0;
}
static w3d_u32 bind_plain(w3d_u32 visitor, ArrayMessage *message, Attribute attribute, w3d_u32 stride, w3d_u32 mask) {
    MeshBinder *binder = from_visitor(visitor);
    XomArray *array = message->array;
    if (array->count == 0) return 0;
    flush_if_dirty(array, array->count * stride);
    set_array(binder, attribute, array->data, stride, mask);
    return 0;
}
w3d_u32 A801698f0(w3d_u32 visitor, Ptr32<ArrayMessage> message) { return bind_plain(visitor, message, kColor0, 4, 0x10); }  // RGBA8
w3d_u32 A8016998c(w3d_u32 visitor, Ptr32<ArrayMessage> message) { return bind_plain(visitor, message, kColor0, 2, 0x20); }  // RGB565
w3d_u32 A80168c8c(w3d_u32 visitor, Ptr32<ArrayMessage> message) { return bind_plain(visitor, message, kTex0, 8, 0x80); }    // UV en float
// UV en 16 bits con 12 bits de fracción.
w3d_u32 A80168d28(w3d_u32 visitor, Ptr32<ArrayMessage> message) {
    MeshBinder *binder = from_visitor(visitor);
    XomArray *array = message->array;
    if (array->count == 0) return 0;
    flush_if_dirty(array, array->count * 4);
    binder->tex0_shift = 12;
    set_array(binder, kTex0, array->data, 4, 0x100);
    return 0;
}
}
