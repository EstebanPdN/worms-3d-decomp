// Prepara un movimiento dirigido de la IA: se aleja del blanco la distancia pedida y busca un camino hasta ese punto.
#include "native_common.h"

namespace {
struct Vector3 { float x, y, z; };
inline Vector3 operator-(const Vector3 &a, const Vector3 &b) { return {(float)(a.x - b.x), (float)(a.y - b.y), (float)(a.z - b.z)}; }
inline Vector3 operator+(const Vector3 &a, const Vector3 &b) { return {(float)(a.x + b.x), (float)(a.y + b.y), (float)(a.z + b.z)}; }
inline Vector3 operator*(const Vector3 &a, float s) { return {(float)(a.x * s), (float)(a.y * s), (float)(a.z * s)}; }
struct AiWorm {
    char pad[8];
    w3d_u32 id;           // +8
    char pad2[4];
    Vector3 position;     // +0x10
};
struct WormList { Ptr32<Ptr32<AiWorm>> items; };
struct PathQueue {
    char pad[0x10];
    Ptr32<w3d_u32> table; // +0x10
    char pad2[0x2c - 0x14];
    int users;            // +0x2c
};
struct DirectedMove {
    char pad[0x10];
    w3d_u32 worm;         // +0x10
    char pad2[4];
    Vector3 target;       // +0x18
    Vector3 direction;    // +0x24
    char pad3[0x40 - 0x30];
    uint8_t allow_attack; // +0x40
    char pad4[0x4c - 0x41];
    Ptr32<PathQueue> queue;  // +0x4c
};
struct AiProfile { char pad[0xbc]; float attack_range; };
const int kResultAlreadyThere = 11;
}
extern "C" {
extern Ptr32<WormList> A804aa750;
extern Ptr32<void> A804b1758;
extern Ptr32<AiProfile> A804aa6d8;
extern w3d_u32 A804aa6dc, A804aa6e0, A804b175c;
extern Vector3 A8041d3a0;   // El punto de mira de la IA.
extern const float A8036a074, A8036a078, A8036a07c, A8036a080;
float A802e82c0(float value);
float A8001e2dc(void *grid);
void A8001f1d8(void *grid, w3d_u32 id);
void A8001f25c(void *grid, w3d_u32 id);
Vector3 A8001f9f0(void *grid, const Vector3 *where);
w3d_u32 A80009674(Ptr32<PathQueue> *out, const Vector3 *from, const Vector3 *to, w3d_u32 limit, float cost);
w3d_u32 A80009a94(Ptr32<PathQueue> *out, const Vector3 *from, const Vector3 *to, float cost);
w3d_u32 A80003e78(void *queue);
void A80003424(void *queue, const Vector3 *where, w3d_u32 kind);
}
namespace {
inline float length_of(const Vector3 &v) { return A802e82c0(fused_madd(v.z, v.z, fused_madd(v.x, v.x, (float)(v.y * v.y)))); }
inline void destroy_queue(Ptr32<PathQueue> &queue) {
    if (queue) call_in_table<void>(queue.get(), queue->table.v, 8, (w3d_u32)3);
}
// Deja al gusano apuntando desde donde está y marca el blanco en su posición.
void aim_from(DirectedMove *self, const Vector3 &position, const Vector3 &aim) {
    self->direction = position - aim;
    const float scale = (float)(A8036a078 / length_of(self->direction));
    self->direction = self->direction * scale;
    self->target = position;
    self->direction.y = (float)(self->direction.y + A8036a078);
}
}
extern "C" {
// 0x8000f804
w3d_u32 A8000f804(Ptr32<DirectedMove> self, float distance) {
    AiWorm *worm = A804aa750->items.get()[self->worm].get();
    const Vector3 position = worm->position;
    Vector3 away = self->target - position;
    const Vector3 none = {A8036a074, A8036a074, A8036a074};
    if (!memcmp(&away, &none, sizeof away)) away = A8041d3a0 - self->target;
    away = away * (float)(A8036a078 / length_of(away));

    const float near_margin = A8036a080;
    const float outer = (float)(distance + near_margin);
    float reach = A8036a07c;
    if (outer > reach) reach = outer;
    const float from_aim = length_of(A8041d3a0 - position);
    if (from_aim > (float)(distance - near_margin) && from_aim < outer) {
        aim_from(self.get(), position, A8041d3a0);
        return 1;
    }
    if (!A804aa6dc || A804aa6e0) return 0;

    Ptr32<PathQueue> queue{(PathQueue *)nullptr};
    const w3d_u32 id = worm->id;
    A8001f1d8(A804b1758.get(), id);
    self->target = position + away * reach;
    self->target = A8001f9f0(A804b1758.get(), &self->target);
    const float climb = __builtin_fabsf((float)(self->target.y - position.y));
    w3d_u32 found = 0;
    if (!(climb > A8001e2dc(A804b1758.get()))) {
        found = A80009674(&queue, &A8041d3a0, &self->target, 0x96, A804aa6d8->attack_range);
        if (!found && self->allow_attack) found = A80009a94(&queue, &A8041d3a0, &self->target, A804aa6d8->attack_range);
    }
    if (found) {
        self->target = position + away * distance;
        Ptr32<PathQueue> check{(PathQueue *)nullptr};
        found = A80009674(&check, at<const Vector3>(A80003e78(queue.get())), &self->target, 0x1e, A8036a074);
        if (A804b175c == kResultAlreadyThere) found = 1;
        destroy_queue(check);
        if (!found) {
            destroy_queue(queue);
            queue.v = 0;
        } else {
            A80003424(queue.get(), &self->target, 1);
            aim_from(self.get(), position, self->target);
        }
    }
    A8001f25c(A804b1758.get(), id);
    if (queue) {
        self->queue = queue;
        queue->users++;
    }
    return queue ? 1 : 0;
}
}
