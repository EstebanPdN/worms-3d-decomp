// Estela de un proyectil: cinta de cuadriláteros de cara a la cámara, con dos mallas que se alternan como doble búfer, y su final.
#include "native_game.h"

namespace {
struct Vector3 { float x, y, z; };
struct Segment { Vector3 v[6]; };
static_assert(sizeof(Segment) == 72, "seis vértices");
struct TrailPoint { float x, y, z, half_width; };
struct TrailMesh {
    char pad[0x14];
    Ptr32<XomArray<Segment>> segments;  // +0x14
};
struct DrawSlot {
    char pad[0x50];
    Ptr32<TrailMesh> mesh;  // +0x50
};
struct PendingPoints {
    char pad[0x18];
    Ptr32<XomArray<TrailPoint>> points;  // +0x18
};
struct Vertex { Vector3 position, normal; };
struct Trail {
    char pad[0x1c];
    uint16_t mode;          // +0x1c
    char pad2[2];
    Ptr32<TrailMesh> mesh_a, mesh_b;  // +0x20
    char pad3[4];
    Ptr32<DrawSlot> fade_slot;   // +0x2c
    Ptr32<DrawSlot> ribbon_slot; // +0x30
    char pad4[4];
    Ptr32<void> texture;    // +0x38
    char pad5[0x64 - 0x3c];
    Ptr32<void> sound;      // +0x64
    Ptr32<void> emitter;    // +0x68
    char pad6[4];
    w3d_u32 frames_left;    // +0x70
    w3d_u32 dying;          // +0x74
    uint16_t count;         // +0x78
    char pad7[2];
    w3d_u32 dirty;          // +0x7c
    char pad8[0x170 - 0x80];
    Ptr32<PendingPoints> pending;  // +0x170
    char pad9[0x354 - 0x174];
    Vertex ends[1];         // +0x354
    char pad10[0x584 - 0x354 - sizeof(Vertex)];
    float rotation[9];      // +0x584
    float translation[3];   // +0x5a8
};
struct Application { char pad[0x30]; Ptr32<void> camera; };
const int kModeRibbon = 2;
const w3d_u32 kFrameBlinkStart = 9;
}
extern "C" {
extern Ptr32<Application> A804b1788;
extern Ptr32<uint8_t> A804ab8d0;   // Tabla de raíces inversas.
extern const float A8039b7c8, A8039b7cc, A8039b7d0;
void A80122864(void *self, void *from, void *to, w3d_u32 index);
void A8015fd1c(void *self);

static Segment *lock_segments(TrailMesh *mesh) {
    XomArray<Segment> *array = mesh->segments;
    if (array->references == 1) {
        array->locks++;
        return array->data;
    }
    return at<Segment>(A801ef048(&mesh->segments, array->count, 0xc, 2));
}
// Lo que se dibuja pasa a ser la malla que no se dibujaba, y se devuelve para escribir en ella.
static Segment *flip(Ptr32<DrawSlot> slot, TrailMesh *a, TrailMesh *b, const Segment **previous) {
    TrailMesh *next = slot->mesh.get() == a ? b : a;
    TrailMesh *shown = next == b ? a : b;
    Segment *writer = lock_segments(next);
    if (previous) *previous = shown->segments->data;
    TrailMesh *old = slot->mesh.get();
    slot->mesh = next;
    if (next) add_reference(next);
    release_if_set(old);
    return writer;
}
static inline Vector3 inverse_length_scaled(Vector3 n) {
    if (n.x == A8039b7c8 && n.y == A8039b7c8 && n.z == A8039b7c8) return n;
    const float squared = fused_madd(n.z, n.z, fused_madd(n.x, n.x, (float)(n.y * n.y)));
    w3d_u32 bits;
    memcpy(&bits, &squared, 4);
    const w3d_u32 root_bits = ((380 - (bits >> 23 & 0xff)) << 22 & 0xff800000u) | (w3d_u32)A804ab8d0.get()[bits >> 17 & 0x7f] << 15;
    float estimate;
    memcpy(&estimate, &root_bits, 4);
    estimate = (float)((float)((float)(A8039b7cc - (float)((float)(estimate * estimate) * squared)) * estimate) * A8039b7d0);
    return {(float)(n.x * estimate), (float)(n.y * estimate), (float)(n.z * estimate)};
}
static void build_ribbon(Trail *self, Segment *writer, const Segment *reader) {
    if (!self->pending) return;
    const TrailPoint *point = self->pending->points->data;
    for (w3d_u32 i = 0; i < self->count; i++, writer++, reader++, point++) {
        writer->v[0] = reader->v[4];
        writer->v[1] = reader->v[5];
        writer->v[3] = reader->v[5];
        const float *m = self->rotation, *t = self->translation;
        const Vector3 world = {
            (float)(fused_madd(point->z, m[6], fused_madd(point->x, m[0], (float)(point->y * m[3]))) + t[0]),
            (float)(fused_madd(point->z, m[7], fused_madd(point->x, m[1], (float)(point->y * m[4]))) + t[1]),
            (float)(fused_madd(point->z, m[8], fused_madd(point->x, m[2], (float)(point->y * m[5]))) + t[2]),
        };
        const Vector3 *eye = at<Vector3>(call_virtual<w3d_u32>(A804b1788->camera.get(), 0x38));
        const Vector3 to_eye = {(float)(world.x - eye->x), (float)(world.y - eye->y), (float)(world.z - eye->z)};
        const Vector3 along = {
            (float)((float)((float)(world.x + world.x) - reader->v[2].x) - reader->v[5].x),
            (float)((float)((float)(world.y + world.y) - reader->v[2].y) - reader->v[5].y),
            (float)((float)((float)(world.z + world.z) - reader->v[2].z) - reader->v[5].z),
        };
        const Vector3 side = inverse_length_scaled({
            fused_msub(along.y, to_eye.z, (float)(along.z * to_eye.y)),
            fused_msub(along.z, to_eye.x, (float)(along.x * to_eye.z)),
            fused_msub(along.x, to_eye.y, (float)(along.y * to_eye.x)),
        });
        const Vector3 offset = {(float)(side.x * point->half_width), (float)(side.y * point->half_width), (float)(side.z * point->half_width)};
        writer->v[2] = {(float)(world.x + offset.x), (float)(world.y + offset.y), (float)(world.z + offset.z)};
        writer->v[4] = writer->v[2];
        writer->v[5] = {(float)(world.x - offset.x), (float)(world.y - offset.y), (float)(world.z - offset.z)};
    }
    release_if_set(self->pending.get());
    self->pending.v = 0;
}
static inline void update_ends(Trail *self) {
    for (uint16_t i = 0; i < self->count; i = (uint16_t)(i + 1)) A80122864(self, &self->ends[i].position, &self->ends[i].normal, i);
}
static inline void drop(Ptr32<void> &slot) {
    release_if_set(slot.get());
    slot.v = 0;
}
// 0x80121b00
w3d_u32 A80121b00(Ptr32<Trail> self) {
    if (self->mode == kModeRibbon) {
        const Segment *previous;
        Segment *writer = flip(self->ribbon_slot, self->mesh_a.get(), self->mesh_b.get(), &previous);
        build_ribbon(self.get(), writer, previous);
    } else {
        flip(self->fade_slot, self->mesh_a.get(), self->mesh_b.get(), nullptr);
        update_ends(self.get());
        if (self->dying) {
            if (--self->frames_left == 0) {
                self->dying = 0;
                drop(*(Ptr32<void> *)&self->mesh_a);
                drop(*(Ptr32<void> *)&self->mesh_b);
                drop(*(Ptr32<void> *)&self->fade_slot);
                drop(self->texture);
                drop(self->sound);
                drop(self->emitter);
                A8015fd1c(self.get());
            } else {
                call_virtual<void>(self->emitter.get(), 0x58, (w3d_u32)(self->frames_left > kFrameBlinkStart ? 1 : 0));
            }
        }
    }
    self->dirty = 1;
    return 0;
}
}
