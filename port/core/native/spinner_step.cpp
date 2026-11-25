// Paso de los selectores del menú en pasos fijos de 20 ms: valor que se acerca al pedido, desplazamiento automático de lista y fundido.
#include "native_common.h"

namespace {
template <class T> struct RotatingList {
    Ptr32<T> begin, end;
    w3d_u32 allocator;
    Ptr32<T> capacity;
};
struct Attached { char pad[0x44]; w3d_u32 snaps; char pad2[0x5c - 0x48]; float value; };
struct Spinner {
    char pad[0x1c];
    char base[0xd4 - 0x1c];     // +0x1c
    w3d_u32 last_step;          // +0xd4
    char pad2[0x100 - 0xd8];
    w3d_u32 start_pending;      // +0x100
    char pad3[0x118 - 0x104];
    float fade_target;          // +0x118
    float fade;                 // +0x11c
    w3d_u32 auto_scroll;        // +0x120
    w3d_u32 pause_steps;        // +0x124
    char pad4[0x12c - 0x128];
    float scroll_speed;         // +0x12c
    char pad5[0x150 - 0x130];
    RotatingList<w3d_u32> items;  // +0x150
    char pad6[0x178 - 0x160];
    Ptr32<Attached> attached;   // +0x178
    float position;             // +0x17c
    float target;               // +0x180
};
const int kStepMs = 20, kMaxElapsed = 100;
const w3d_u32 kPauseSteps = 100;
}
extern "C" {
void A802b0668(void *base);
w3d_u32 A801fe45c();
w3d_u32 A802b264c(void *base);
void A80296410(void *attached, float value);
void A802a0d44(void *self);
void A802eeef4(void *to, const void *from, w3d_u32 bytes);
w3d_u32 A80212fd4(w3d_u32 bytes);
w3d_u32 A803413d8(w3d_u32 bytes);
void A802134fc(void *block);
extern const float A803d1d00, A803d1d04, A803d1d08, A803d1d0c, A803d1d10, A803d1d14;

static void rotate_front_to_back(RotatingList<w3d_u32> *list) {
    const w3d_u32 first = *list->begin;
    const w3d_u32 *second = list->begin.get() + 1;
    if (second != list->end.get()) A802eeef4(list->begin.get(), second, (w3d_u32)((const char *)list->end.get() - (const char *)second));
    list->end.v -= 4;
    if (list->end.v != list->capacity.v) {
        *list->end = first;
        list->end.v += 4;
        return;
    }
    const w3d_u32 used = (w3d_u32)((int)(list->end.v - list->begin.v) >> 2);
    const w3d_u32 bytes = (used + (used < 1 ? 1 : used)) << 2;
    w3d_u32 storage = A80212fd4(bytes);
    if (!storage) storage = A803413d8(bytes);
    w3d_u32 *out = at<w3d_u32>(storage);
    const w3d_u32 used_bytes = list->end.v - list->begin.v;
    if (used_bytes) {
        A802eeef4(out, list->begin.get(), used_bytes);
        out = (w3d_u32 *)((char *)out + used_bytes);
    }
    *out++ = first;
    if (list->begin) A802134fc(list->begin.get());
    list->begin.v = storage;
    list->capacity.v = storage + bytes;
    list->end = out;
}
static inline float ease(float towards, float current) { return fused_madd(current, A803d1d14, (float)(towards * A803d1d10)); }
static inline bool close_enough(float difference) { return difference < A803d1d08 && difference > A803d1d0c; }

// 0x8029e194
w3d_u32 A8029e194(Ptr32<Spinner> self) {
    A802b0668(self->base);
    const w3d_u32 now = A801fe45c();
    int elapsed = (int)(now - self->last_step);
    if (elapsed > kMaxElapsed) elapsed = kMaxElapsed;
    for (; elapsed >= kStepMs; elapsed -= kStepMs) {
        if (self->start_pending && A802b264c(self->base)) {
            call_virtual<void>(self.get(), 0x30);
            self->start_pending = 0;
        }
        if (A802b264c(self->base)) {
            if (self->auto_scroll == 1) {
                if (self->pause_steps) {
                    self->pause_steps--;
                } else {
                    if (self->position > A803d1d00) {
                        self->position -= A803d1d00;
                        rotate_front_to_back(&self->items);
                    } else {
                        self->position += self->scroll_speed;
                    }
                    if (self->position < A803d1d04) {
                        self->position = A803d1d04;
                        self->scroll_speed = self->scroll_speed < A803d1d04 ? A803d1d08 : -self->scroll_speed;
                        self->pause_steps = kPauseSteps;
                    }
                    call_virtual<void>(self.get(), 0x28);
                }
            } else {
                bool moved = false;
                Attached *attached = self->attached;
                if (attached && attached->value != self->position) {
                    if (attached->snaps) self->position = attached->value;
                    self->target = attached->value;
                    moved = true;
                }
                if (self->target != self->position) {
                    moved = true;
                    const float difference = (float)(self->target - self->position);
                    self->position = close_enough(difference) ? self->target : ease(self->target, self->position);
                }
                if (self->attached) {
                    A80296410(self->attached.get(), self->position);
                    if (moved) call_virtual<void>(self.get(), 0x28);
                }
            }
        }
        if (self->fade_target != self->fade) {
            const float eased = ease(self->fade_target, self->fade);
            self->fade = close_enough((float)(self->fade_target - eased)) ? self->fade_target : eased;
            A802a0d44(self.get());
        }
    }
    self->last_step = now - elapsed;
    return 0;
}
}
