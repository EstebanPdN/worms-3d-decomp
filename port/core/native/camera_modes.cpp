// Modos de la cámara por nombre.
#include "native_game.h"

namespace {
struct CameraMode {
    char pad[0x30];
    w3d_u32 setup;            // +0x30
    char pad2[0x3c - 0x34];
    Ptr32<const char> name;   // +0x3c
    char pad3[0x48 - 0x40];
    w3d_u32 transitions;      // +0x48: tabla de la interfaz de cambio
};
struct Blend {
    w3d_u32 flags;            // +0
    float elapsed;            // +4
    w3d_u32 a, b, c;
};
struct Camera {
    char pad[0x138];
    w3d_u32 current;          // +0x138
    Ptr32<Ptr32<CameraMode>> modes, modes_end;  // +0x13c
    char pad2[0x2d8 - 0x144];
    Blend blend;              // +0x2d8
    char pad3[0x324 - 0x2ec];
    w3d_u32 locked;           // +0x324
    char pad4[0x334 - 0x328];
    float blend_time;         // +0x334
};
const w3d_u32 kKeepBlendBits = 0x7fffff & 0xff9fffff;
}
extern "C" {
w3d_u32 A8006e71c();
int A802ef234(const char *, const char *);
w3d_u32 A8015ab1c(void *mode);
void A80032bb0(void *camera, w3d_u32 setup);
void A800358b4(void *camera);
extern const float A803733c4;

// 0x80035714: pasa al modo con ese nombre. Devuelve 1 si cambió.
void w3d_franco_camera_mode(w3d_u32 type);   // francotirador.cpp
w3d_u32 A80035714(Ptr32<Camera> self, Ptr32<const char> name, float blend_time) {
    if (A8006e71c() || self->locked) return 0;
    ScopedString wanted(name.get());
    w3d_u32 changed = 0;
    const int index_end = self->modes_end - self->modes;
    for (int index = 0; index < index_end; index++) {
        CameraMode *mode = self->modes[index];
        if (A802ef234(mode->name, wanted.text)) continue;
        if (!A8015ab1c(mode)) { A800358b4(self.get()); break; }
        if (self->current < (w3d_u32)index_end) {
            CameraMode *previous = self->modes[self->current];
            call_in_table<void>(previous, previous->transitions, 0x14);
        }
        call_in_table<void>(mode, mode->transitions, 0x10, self->modes[self->current].get());
        A80032bb0(self.get(), mode->setup);
        self->current = index;
        w3d_franco_camera_mode(mode->setup);   // francotirador de UM: quita o pone el zoom al cambiar de cámara
        self->blend_time = blend_time;
        self->blend.flags &= kKeepBlendBits;
        self->blend.elapsed = A803733c4;
        self->blend.a = self->blend.b = self->blend.c = 0;
        changed = 1;
        break;
    }
    return changed;
}
}
