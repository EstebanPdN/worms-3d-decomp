// Arranque de una búsqueda de camino de la IA: nodos de origen y destino sobre la rejilla de rutas.
#include "native_common.h"

namespace {
struct RouteNode {
    uint16_t pad;
    int16_t x, z;     // +2
    uint8_t layer;    // +6
    uint8_t pad2;
    uint16_t to_goal; // +8
    uint16_t walked;  // +0xa
    uint16_t total;   // +0xc
};
struct GridPoint { int16_t x, z; w3d_u32 layer; };
struct PathSearch {
    char pad0[4];
    char open_list[0x8008];            // +4
    Ptr32<RouteNode> start, goal;      // +0x800c
    w3d_u32 elapsed;                   // +0x8014
    char pad3[0x8038 - 0x8018];
    float hop_height;                  // +0x8038
    char pad4[0x8040 - 0x803c];
    w3d_u32 jump_limit, fall_limit;    // +0x8040
    char pad5[0x805c - 0x8048];
    w3d_u32 result[3];                 // +0x805c
};
struct AiProfile { char pad[0x1ec]; w3d_u32 fall_limit, jump_limit; };
enum PathStatus { kSearching = 10, kGoalUnreachable = 5, kGoalMine = 6, kGoalCrate = 7, kGoalWater = 8, kGoalEdge = 9, kAlreadyThere = 11 };
}
extern "C" {
extern Ptr32<void> A804b1758;     // La rejilla.
extern w3d_u32 A804b175c;         // Estado de la búsqueda.
extern w3d_u32 A804aa794;         // Se acepta un destino no alcanzable.
extern Ptr32<AiProfile> A804aa6d8;
void A80004394(void *search);
float A8001e2dc(void *grid);
w3d_u32 A8001e328(void *grid, void *position, int16_t *x, int16_t *z, w3d_u32 *layer);
w3d_u32 A8001523c(w3d_u32 bytes);
void A8034141c(void *node);
void A800053e4(void *list, void *node);
int A8000443c(void *from, void *to);
w3d_u32 A8001dff8(void *grid, int x, int z, w3d_u32 layer);
void A80005d4c(void *search);

static RouteNode *make_node(const GridPoint &point) {
    RouteNode *node = at<RouteNode>(A8001523c(0x14));
    A8034141c(node);
    node->x = point.x;
    node->z = point.z;
    node->layer = (uint8_t)point.layer;
    return node;
}
// 0x80004498
void A80004498(Ptr32<PathSearch> self, Ptr32<void> from, Ptr32<void> to) {
    A80004394(self.get());
    self->elapsed = 0;
    self->result[0] = self->result[1] = self->result[2] = 0;
    A804b175c = kSearching;
    self->hop_height = A8001e2dc(A804b1758.get());
    GridPoint origin, target;
    A8001e328(A804b1758.get(), from.get(), &origin.x, &origin.z, &origin.layer);
    RouteNode *start = make_node(origin);
    self->start = start;
    A800053e4(self->open_list, start);
    const w3d_u32 reachable = A8001e328(A804b1758.get(), to.get(), &target.x, &target.z, &target.layer);
    self->goal = make_node(target);
    start->walked = 0;
    start->to_goal = (uint16_t)A8000443c(start, self->goal.get());
    start->total = start->walked + start->to_goal;
    bool finish = false;
    if (!A804aa794) {
        if (!reachable) {
            finish = true;
            A804b175c = kGoalUnreachable;
        }
        const uint8_t blocker = *at<uint8_t>(A8001dff8(A804b1758.get(), target.x, target.z, target.layer));
        if (blocker) {
            finish = true;
            switch (blocker) {
            case 1: A804b175c = kGoalMine; break;
            case 2: A804b175c = kGoalCrate; break;
            case 3: A804b175c = kGoalWater; break;
            case 4: A804b175c = kGoalEdge; break;
            }
        }
    }
    if (origin.x == target.x && origin.z == target.z && origin.layer == target.layer) {
        A804aa794 = 0;
        finish = true;
        A804b175c = kAlreadyThere;
    }
    if (finish) A80005d4c(self.get());
    self->jump_limit = A804aa6d8->jump_limit;
    self->fall_limit = A804aa6d8->fall_limit;
}
}
