// Vecinos de un nodo en la búsqueda de camino de la IA: las ocho celdas de al lado y, desde el suelo, los saltos y caídas con su trayectoria libre.
#include "native_common.h"

namespace {
template <class T> struct Vector { Ptr32<T> begin, end; w3d_u32 allocator; Ptr32<T> capacity; };
struct RouteNode {
    uint16_t pad;
    int16_t x, z;     // +2
    uint8_t layer;    // +6
};
struct RouteGrid {
    char pad[0x34];
    int hop_range[2]; // +0x34
};
struct RouteLayerBlock {
    char pad[0x1c];
    int16_t cell_min_x, cell_min_z, cell_max_x, cell_max_z;  // +0x1c
    Vector<uint8_t> flags[2];     // +0x24
    Vector<float> lower[2];       // +0x44
    Vector<float> upper[2];       // +0x64
};
struct PathSearch {
    char pad[0x8040];
    w3d_u32 hop_allowed[2];       // +0x8040
};
enum HopKind { kWalk = 0, kJump = 3, kFall = 4 };
}
extern "C" {
extern Ptr32<RouteGrid> A804b1758;
extern const float A80368ed8, A80368ee8, A80368eec;
w3d_u32 A8001e11c(void *grid, int x, int z, int layer);
w3d_u32 A8001e1a0(void *grid, int x, int z, int layer);
w3d_u32 A8001dff8(void *grid, int x, int z, int layer);
w3d_u32 A8001df1c(void *grid, int x, int z);
w3d_u32 A800203a0(void *grid, int kind, int dx, int dz);
w3d_u32 A800203cc(void *grid, int kind, int dx, int dz);
w3d_u32 A8000519c(void *search, int x, int z, int layer, float low, float high);
void A800055b8(void *search, void *node, int x, int z, int layer, int kind);

static inline float cell_low(RouteGrid *grid, int x, int z, int layer) { return *at<float>(A8001e11c(grid, x, z, layer)); }
static inline float cell_high(RouteGrid *grid, int x, int z, int layer) { return *at<float>(A8001e1a0(grid, x, z, layer)); }
static inline int absolute(int value) { return value < 0 ? -value : value; }

// Añade la celda en la primera capa libre y transitable. Las dos comprobaciones se hacen siempre, como en el original.
static bool try_neighbour(PathSearch *search, RouteNode *node, RouteGrid *grid, int x, int z, float low, float high) {
    for (int layer = 0; layer <= 1; layer++) {
        const bool empty = *at<uint8_t>(A8001dff8(grid, x, z, layer)) == 0;
        const bool passable = A8000519c(search, x, z, layer, low, high) != 0;
        if (empty && passable) {
            A800055b8(search, node, (int16_t)x, (int16_t)z, layer, kWalk);
            return true;
        }
    }
    return false;
}
// Recorre las celdas desde el destino hacia el origen y mira si el terreno corta el arco del salto.
static bool hop_blocked(RouteGrid *grid, int kind, int layer, int origin_x, int origin_z, int target_x, int target_z, int dx, int dz, float low, float fraction) {
    const int step_x = dx > 0 ? -1 : 1, step_z = dz > 0 ? -1 : 1;
    float slope = A80368ed8;
    if (dz != 0) slope = (float)absolute(dx) / (float)absolute(dz);
    int x = target_x, z = target_z;
    while (x != origin_x || z != origin_z || layer != 0) {
        const int away_x = absolute(x - origin_x), away_z = absolute(z - origin_z);
        if (x != target_x || z != target_z) {
            const float bottom = *at<float>(A800203cc(grid, kind, away_x, away_z));
            const float top = *at<float>(A800203a0(grid, kind, away_x, away_z));
            const float arc = fused_madd(bottom, fraction, (float)((float)(A80368eec - fraction) * top));
            const float ground = (float)(cell_high(grid, x, z, 0) - low);
            if (ground >= arc) return true;
        }
        if (dz != 0 && away_z != 0 && !((float)away_x / (float)away_z > slope)) {
            z += step_z;
        } else {
            if (dx == 0) return false;
            x += step_x;
        }
    }
    return false;
}
// 0x800047f0
w3d_u32 A800047f0(Ptr32<PathSearch> self, Ptr32<RouteNode> node) {
    PathSearch *search = self.get();
    RouteGrid *grid = A804b1758.get();
    const int x = node->x, z = node->z;
    const int own_layer = node->layer;
    const float low = cell_low(grid, x, z, own_layer), high = cell_high(grid, x, z, own_layer);

    const bool west = try_neighbour(search, node.get(), grid, x - 1, z, low, high);
    const bool east = try_neighbour(search, node.get(), grid, x + 1, z, low, high);
    const bool north = try_neighbour(search, node.get(), grid, x, z - 1, low, high);
    const bool south = try_neighbour(search, node.get(), grid, x, z + 1, low, high);
    if (west && north) try_neighbour(search, node.get(), grid, x - 1, z - 1, low, high);
    if (east && north) try_neighbour(search, node.get(), grid, x + 1, z - 1, low, high);
    if (west && south) try_neighbour(search, node.get(), grid, x - 1, z + 1, low, high);
    if (east && south) try_neighbour(search, node.get(), grid, x + 1, z + 1, low, high);
    if (own_layer != 0) return 0;

    for (int hop = 0; hop < 2; hop++) {
        if (!search->hop_allowed[hop]) continue;
        const int kind = hop == 1 ? kFall : kJump;
        const int range = grid->hop_range[hop];
        for (int dx = 1 - range; dx < range; dx++) {
            for (int dz = 1 - range; dz < range; dz++) {
                const int target_x = x + dx, target_z = z + dz;
                RouteLayerBlock *block = at<RouteLayerBlock>(A8001df1c(grid, target_x, target_z));
                if (!block) continue;
                for (int layer = 0; layer <= 1; layer++) {
                    const int index = ((int)(int16_t)target_z - block->cell_min_z) * (block->cell_max_x - block->cell_min_x) + (int16_t)target_x - block->cell_min_x;
                    if (block->flags[layer].begin.get()[index]) continue;
                    const float to_floor = (float)(block->upper[layer].begin.get()[index] - low);
                    const float to_ceiling = (float)(block->lower[layer].begin.get()[index] - high);
                    const int away_x = absolute(dx), away_z = absolute(dz);
                    const float top = *at<float>(A800203a0(grid, hop, away_x, away_z));
                    const float bottom = *at<float>(A800203cc(grid, hop, away_x, away_z));
                    if (!(to_floor < top) || !(to_floor > bottom) || !(to_ceiling < top) || !(to_ceiling > bottom)) continue;
                    const float middle = (float)((float)(to_floor + to_ceiling) * A80368ee8);
                    float fraction = A80368ed8;
                    if (top > bottom) fraction = (float)((float)(top - middle) / (float)(top - bottom));
                    if (!hop_blocked(grid, hop, layer, x, z, target_x, target_z, dx, dz, low, fraction)) A800055b8(search, node.get(), (int16_t)target_x, (int16_t)target_z, layer, kind);
                }
            }
        }
    }
    return 0;
}
}
