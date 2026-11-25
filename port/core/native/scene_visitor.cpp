// Recorrido de transformaciones del grafo de escena. El visitante mantiene la matriz acumulada en una pila implícita:
// cada nodo calcula la suya en un local, la deja como actual mientras recorre a sus hijos y restaura la anterior.
#include "native_common.h"

namespace {
struct Matrix44 { float m[4][4]; };
struct SceneNode {
    w3d_u32 table;
    char pad[0x10];
    char local[0x48 - 0x14];   // +0x14: transformación local, la lee 0x801f68c8.
    float scale[3];     // +0x48: solo en los nodos de escala pura.
};
struct NodeList {
    char pad[0x18];
    int count;
    char pad2[4];
    w3d_u32 children[1];   // +0x20
};
struct NodeHeader { char pad[6]; uint16_t type_index; };
// Base del visitante (en +4 de la clase): recibe los mensajes y despacha por el índice de tipo de cada hijo.
struct NodeVisitor {
    w3d_u32 table;
    char pad[0x10];
    Ptr32<char> children_owner;   // +0x14
    w3d_u32 dispatch_table;       // +0x18
};
struct TransformVisitor {
    w3d_u32 table;
    NodeVisitor visitor;          // +4
    char pad[0x30 - (4 + sizeof(NodeVisitor))];
    w3d_u32 revision;             // +0x30
    char pad2[4];
    w3d_u32 current;              // +0x38: puntero a la matriz acumulada.
};
}
extern "C" {
extern char A80363a14[];       // Tipo del nodo de escala.
extern float A803aa0f8;        // 0
void A801f68c8(void *out, void *local, void *parent);

// 0x801aa9dc: un nodo de transformación.
int A801aa9dc(w3d_u32 visitor_ptr, Ptr32<SceneNode> node) {
    TransformVisitor *self = visitor_ptr ? at<TransformVisitor>(visitor_ptr - 4) : nullptr;
    Matrix44 world;
    A801f68c8(&world, &node->local, g2h(self->current));
    if ((char *)g2h(call_virtual(node.get(), 0x14)) == A80363a14) {
        // Escala pura: solo la diagonal, la traslación sigue siendo la del producto.
        const float zero = A803aa0f8;
        world.m[0][0] = node->scale[0];
        world.m[0][1] = zero;
        world.m[0][2] = zero;
        world.m[1][0] = zero;
        world.m[1][1] = node->scale[1];
        world.m[1][2] = zero;
        world.m[2][0] = zero;
        world.m[2][1] = zero;
        world.m[2][2] = node->scale[2];
    }
    const w3d_u32 parent = self->current;
    self->revision++;
    self->current = h2g(&world);

    NodeVisitor *visitor = self ? &self->visitor : nullptr;
    const NodeList *list = *(const Ptr32<NodeList> *)(self->visitor.children_owner.get() + 0x2c);
    int result = 0;
    for (int i = 0; i < list->count; i++) {
        const w3d_u32 child = list->children[i];
        result = call_in_table<int>(visitor, visitor->dispatch_table, at<NodeHeader>(child)->type_index * 4, arg(child));
        if (result < 0) break;
    }
    self->current = parent;
    self->revision++;
    return result;
}
}

// Luces: al visitar una luz con ámbito, su posición de vista se calcula con la inversa de la cámara de la escena y se normaliza.
namespace {
struct LightNode {
    char pad[0x2c];
    float world[16];    // +0x2c
    char pad2[0x90 - 0x6c];
    w3d_u32 scoped;     // +0x90
    char pad3[0x9c - 0x94];
    float position[3];  // +0x9c
};
struct LightVisitor { w3d_u32 table; char pad[0xc8]; w3d_u32 copy_only; };   // +0xcc
}
extern "C" {
extern w3d_u32 A804b1884;       // Estado de dibujo.
extern float A803a5694;         // 1
extern char A803a5678[];        // "Non scopped light applied"
void A801f69a8(void *out, const void *in);
float A802e82c0(float);
void A802fb7ac(const char *);
void A803095c0(void *, float, float, float);
void A8016b9ec(void *, void *);
void A8016857c(void *, w3d_u32);

// 0x8016bbbc
w3d_u32 A8016bbbc(w3d_u32 visitor, Ptr32<LightNode> light) {
    LightVisitor *self = visitor ? at<LightVisitor>(visitor - 4) : nullptr;
    float x = light->position[0], y = light->position[1], z = light->position[2];
    char *const state = at<char>(A804b1884);
    void *const gx_light = state + 0x108;
    if (light->scoped == 0) {
        A802fb7ac(A803a5678);
    } else {
        if (self->copy_only == 0) {
            // Primera pasada: guarda en la luz la matriz actual del visitante.
            memcpy(light->world, at<float>(call_virtual(self, 0x3c)), sizeof light->world);
            return 0;
        }
        float m[4][4];
        call_virtual(state, 0x60, m);
        A801f69a8(m, m);
        // Cada componente ya usa los anteriores recién transformados, como en el original.
        x = fused_madd(z, m[2][0], fused_madd(x, m[0][0], y * m[1][0])) + m[3][0];
        y = fused_madd(z, m[2][1], fused_madd(x, m[0][1], y * m[1][1])) + m[3][1];
        z = fused_madd(z, m[2][2], fused_madd(x, m[0][2], y * m[1][2])) + m[3][2];
        const float length = A802e82c0(fused_madd(z, z, fused_madd(x, x, y * y)));
        const float scale = A803a5694 / length;
        x *= scale;
        y *= scale;
        z *= scale;
    }
    A803095c0(gx_light, x, y, z);
    A8016b9ec(gx_light, light.get());
    A8016857c(state, 0);
    return 0;
}
}
