// Mapa de rutas de la IA y máscara de trozos del terreno.
#include "native_common.h"

namespace {
template <class T> struct Vector { Ptr32<T> begin, end; w3d_u32 allocator; Ptr32<T> capacity; };
struct RouteGrid { char pad[0x68]; float cell; char pad2[0x74 - 0x6c]; float origin_x; char pad3[4]; float origin_z; };
struct RouteLayerBlock {
    char pad[4];
    float min_x;                  // +4
    char pad2[4];
    float min_z;                  // +0xc
    float max_x;                  // +0x10
    char pad3[4];
    float max_z;                  // +0x18
    int16_t cell_min_x, cell_min_z, cell_max_x, cell_max_z;  // +0x1c
    Vector<uint8_t> flags[2];     // +0x24
    Vector<float> lower[2];       // +0x44
    Vector<float> upper[2];       // +0x64
};
}
extern "C" {
extern const float A8036b730, A8036b734;
void A80342bac(void *vector, void *at, w3d_u32 count, const float *value);
void A80342ddc(void *vector, void *at, w3d_u32 count, const uint8_t *value);

static inline int16_t to_cell(float value, float origin, float cell) {
    return (int16_t)ppc_ftoi((float)((float)((float)(value - origin) / cell) + A8036b730));
}
// 0x8001d388: celdas que cubre el bloque, y sus mapas por capa con el valor inicial.
void A8001d388(Ptr32<RouteLayerBlock> self, Ptr32<RouteGrid> grid) {
    self->cell_min_x = to_cell(self->min_x, grid->origin_x, grid->cell);
    self->cell_min_z = to_cell(self->min_z, grid->origin_z, grid->cell);
    self->cell_max_x = (int16_t)(to_cell(self->max_x, grid->origin_x, grid->cell) + 1);
    self->cell_max_z = (int16_t)(to_cell(self->max_z, grid->origin_z, grid->cell) + 1);
    const w3d_u32 cells = (w3d_u32)((self->cell_max_x - self->cell_min_x) * (self->cell_max_z - self->cell_min_z));
    for (int layer = 0; layer < 2; layer++) {
        const float empty = A8036b734;
        const uint8_t walkable = 1;
        self->lower[layer].end = self->lower[layer].begin;
        A80342bac(&self->lower[layer], self->lower[layer].end.get(), cells, &empty);
        self->upper[layer].end = self->upper[layer].begin;
        A80342bac(&self->upper[layer], self->upper[layer].end.get(), cells, &empty);
        self->flags[layer].end = self->flags[layer].begin;
        A80342ddc(&self->flags[layer], self->flags[layer].end.get(), cells, &walkable);
    }
}
}

namespace {
struct Vector3 { float x, y, z; };
// Árbol de cajas aplanado: cada nodo sabe cuántos nodos ocupa su subárbol y cuántas hojas tiene debajo.
struct LandBox {
    Vector3 min, max;
    char pad[4];
    uint16_t subtree_nodes;  // +0x1c
    uint16_t leaves;         // +0x1e
};
static_assert(sizeof(LandBox) == 32, "los nodos ocupan 32 B");
struct LandTree {
    char pad[0x74];
    Ptr32<LandBox> begin, end;  // +0x74
    char pad2[0x80 - 0x7c];
    w3d_u32 mask[1];            // +0x80
};
struct MaskWriter {
    w3d_u32 *word;
    w3d_u32 value, bit;
    void advance() {
        bit <<= 1;
        if (!bit) {
            *word++ = value;
            bit = 1;
            value = 0;
        }
    }
};
}
extern "C" {
// 0x800bd53c: una máscara de bits, con un bit por hoja, de las hojas cuya caja está a menos de radius del punto.
void A800bd53c(Ptr32<LandTree> self, Ptr32<const Vector3> point, float radius) {
    MaskWriter out = {self->mask, 0, 1};
    const LandBox *box = self->begin;
    const LandBox *const end = self->end;
    while (box != end) {
        const bool near = (float)(box->min.x - point->x) < radius && (float)(box->min.y - point->y) < radius && (float)(box->min.z - point->z) < radius &&
                          (float)(point->x - box->max.x) < radius && (float)(point->y - box->max.y) < radius && (float)(point->z - box->max.z) < radius;
        if (near) {
            if (box->subtree_nodes == 1) {
                out.value |= out.bit;
                out.advance();
            }
            box++;
        } else {
            for (int i = 0; i < box->leaves; i++) out.advance();
            box += box->subtree_nodes;
        }
    }
    *out.word = out.value;
}
}
