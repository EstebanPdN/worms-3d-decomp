// Esferas de recorte de los trozos de terreno: cada trozo es una caja deformada por los mapas de altura y la curva del mundo.
#include "native_common.h"

namespace {
struct Vector3 { float x, y, z; };
struct EdgePoint { float start, end; };
struct BoundingNode {
    char pad[0x14];
    Vector3 centre;           // +0x14
    float radius;             // +0x20
    char pad2[4];
    w3d_u32 occluder;         // +0x28
    char pad3[0x6a - 0x2c];
    uint8_t culled;           // +0x6a
};
template <class T> struct Array { char pad[0x20]; T data[1]; };
struct LandShape {
    char pad0[0x2c];
    Ptr32<Array<Ptr32<BoundingNode>>> nodes;  // +0x2c
    char pad1[0xf0 - 0x30];
    float rows[4][3];         // +0xf0: filas de la matriz del mundo (la última es la traslación)
    Vector3 pivot;            // +0x120
    char pad2[0x18c - 0x12c];
    Ptr32<Array<EdgePoint>> lower_edge;  // +0x18c
    Ptr32<Array<EdgePoint>> upper_edge;  // +0x190
    char pad3[0x1ac - 0x194];
    Ptr32<Array<float>> heights;         // +0x1ac
    char pad4[0x1c5 - 0x1b0];
    uint8_t height_stride;    // +0x1c5
    uint8_t layers;           // +0x1c6
    uint8_t columns;          // +0x1c7
    uint8_t rows_count;       // +0x1c8
    uint8_t total_depth;      // +0x1c9
    uint8_t total_height;     // +0x1ca
    uint8_t total_width;      // +0x1cb
};
struct LandOwner { w3d_u32 pad; Ptr32<LandShape> shape; };
struct World { char pad[0x68]; Vector3 offset; };
struct CornerStep { int width_step, depth_step; };
const int kChunkCells = 7;
inline int chunk_size(int total, int index) {
    const int left = total - index * kChunkCells;
    return left < kChunkCells ? left : kChunkCells;
}
}
extern "C" {
extern const CornerStep A803f4c78[8];
extern const Vector3 A8043b23c[8];
extern Vector3 A8043b29c[8];
extern Ptr32<World> A804b17e0;
extern const float A80382508, A8038250c, A80382518, A8038251c;
float A802e82c0(float value);

// 0x800b8140
void A800b8140(Ptr32<LandOwner> self) {
    LandShape *shape = self->shape;
    Ptr32<BoundingNode> *node = shape->nodes->data;
    const EdgePoint *lower = shape->lower_edge->data, *upper = shape->upper_edge->data;
    const int stride = shape->height_stride;
    for (int layer = 0; layer < shape->layers; layer++) {
        const int depth = chunk_size(shape->total_depth, layer);
        for (int row = 0; row < shape->rows_count; row++) {
            const int width = chunk_size(shape->total_width, row);
            const float *row_heights = &shape->heights->data[row * 7 + layer * kChunkCells * stride];
            for (int column = 0; column < shape->columns; column++) {
                const int height = chunk_size(shape->total_height, column);
                const Vector3 base = {(float)((float)row * A80382508), (float)((float)column * A80382508), (float)((float)layer * A80382508)};
                float sum_x = A8038250c, sum_y = A8038250c, sum_z = A8038250c;
                for (int i = 0; i < 8; i++) {
                    const Vector3 &corner = A8043b23c[i];
                    const float x = fused_madd(corner.x, (float)width, base.x);
                    const float lifted = fused_madd(corner.y, (float)height, base.y);
                    const float z = fused_madd(corner.z, (float)depth, base.z);
                    const float *cell = row_heights + A803f4c78[i].width_step * width + A803f4c78[i].depth_step * depth * stride;
                    const float y = (float)(lifted + *cell);
                    int edge = ppc_ftoi(y);
                    if (edge < 0) edge = 0;
                    if (edge > shape->total_height - 1) edge = shape->total_height - 1;
                    const float along = (float)(y - (float)edge);
                    const float before = (float)(A80382518 - along);
                    const float low_x = fused_madd(upper[edge + 1].start, along, (float)(upper[edge].start * before));
                    const float high_x = fused_madd(lower[edge + 1].start, along, (float)(lower[edge].start * before));
                    const float low_z = fused_madd(upper[edge + 1].end, along, (float)(upper[edge].end * before));
                    const float high_z = fused_madd(lower[edge + 1].end, along, (float)(lower[edge].end * before));
                    const float flat_x = (float)(x + (float)(low_x + (float)((float)(x * (float)(high_x - low_x)) / (float)shape->total_width)));
                    const float flat_z = (float)(z + (float)(low_z + (float)((float)(z * (float)(high_z - low_z)) / (float)shape->total_depth)));
                    const float px = (float)(flat_x - shape->pivot.x), py = (float)(y - shape->pivot.y), pz = (float)(flat_z - shape->pivot.z);
                    const Vector3 world = {
                        (float)(fused_madd(pz, shape->rows[2][0], fused_madd(px, shape->rows[0][0], (float)(py * shape->rows[1][0]))) + shape->rows[3][0]),
                        (float)(fused_madd(pz, shape->rows[2][1], fused_madd(px, shape->rows[0][1], (float)(py * shape->rows[1][1]))) + shape->rows[3][1]),
                        (float)(fused_madd(pz, shape->rows[2][2], fused_madd(px, shape->rows[0][2], (float)(py * shape->rows[1][2]))) + shape->rows[3][2]),
                    };
                    sum_x = (float)(sum_x + world.x);
                    sum_y = (float)(sum_y + world.y);
                    sum_z = (float)(sum_z + world.z);
                    A8043b29c[i] = world;
                }
                const Vector3 centre = {(float)(sum_x * A8038251c), (float)(sum_y * A8038251c), (float)(sum_z * A8038251c)};
                float farthest = A8038250c;
                for (const Vector3 &corner : A8043b29c) {
                    const float dx = (float)(corner.x - centre.x), dy = (float)(corner.y - centre.y), dz = (float)(corner.z - centre.z);
                    const float squared = fused_madd(dz, dz, fused_madd(dx, dx, (float)(dy * dy)));
                    if (squared > farthest) farthest = squared;
                }
                const Vector3 &offset = A804b17e0->offset;
                BoundingNode *box = *node++;
                box->occluder = 0;
                box->centre = {(float)(centre.x + offset.x), (float)(centre.y + offset.y), (float)(centre.z + offset.z)};
                box->radius = A802e82c0(farthest);
                box->culled = 0;
            }
        }
    }
}
}
