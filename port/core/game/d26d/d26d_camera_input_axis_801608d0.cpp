#include "w3d_ptr.h"
#line 1 "d26d_camera_input_axis_801608d0.cpp"
// GWMP8P rev0 0x801608d0. Handle a camera input axis: kind 0 adds the value
// times the yaw rate to the yaw, kind 1 subtracts the value times the pitch
// rate from the pitch, both clamped to plus or minus 1, and any other kind
// scales the value by the zoom rate. Each posts a 36-byte message 0x1004
// with the current yaw and pitch. Names are inferred.
inline const float &fmin(const float &a, const float &b) { return a < b ? a : b; }
inline const float &fmax(const float &a, const float &b) { return a < b ? b : a; }
inline float clamp(const float &v, const float &lo, const float &hi) { return fmax(fmin(v, hi), lo); }
struct Message { unsigned short id; Ptr32<Ptr32<void>> type; int mode; int size; unsigned short a; unsigned short b; char flag; float x, y, z; };
struct Camera { char u0[32]; float yaw; float pitch; float zoomRate; float yawRate; float pitchRate; };
extern Ptr32<void> heap_804b1754;
extern Ptr32<void> type_8040db38[];
extern "C" Ptr32<Message> alloc_801613f0(Ptr32<void>, int);
extern "C" int post_8015fc84(Ptr32<Camera>, Ptr32<Message>);
inline Ptr32<Message> init(Ptr32<Message> m, int mode, unsigned short a, unsigned short b, float x, float y, float z) {
    int size = 8; m->id = 0x1004; m->type = type_8040db38; m->mode = mode; m->size = size;
    m->a = a; m->b = b; m->flag = 0; m->x = x; m->y = y; m->z = z;
    return m;
}
extern "C" void d26d_camera_input_axis_801608d0(Ptr32<Camera> self, Ptr32<void> unused, int kind, int value) {
    switch (kind) {
    case 0:
        self->yaw += (float)value * self->yawRate;
        self->yaw = clamp(self->yaw, -1.0f, 1.0f);
        post_8015fc84(self, init(alloc_801613f0(heap_804b1754, 36), 0, value, 0, self->yaw, self->pitch, 0.0f));
        break;
    case 1:
        self->pitch -= (float)value * self->pitchRate;
        self->pitch = clamp(self->pitch, -1.0f, 1.0f);
        post_8015fc84(self, init(alloc_801613f0(heap_804b1754, 36), 0, 0, value, self->yaw, self->pitch, 0.0f));
        break;
    default:
        post_8015fc84(self, init(alloc_801613f0(heap_804b1754, 36), 4, 0, 0, self->yaw, self->pitch, (float)value * self->zoomRate));
        break;
    }
}


