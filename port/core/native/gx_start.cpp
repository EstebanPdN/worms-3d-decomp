// Arranque del dibujo: ajustes de pantalla, búfer de órdenes, modo de vídeo y primera imagen.
#include "native_common.h"

namespace {
struct RenderMode {
    w3d_u32 tv;
    uint16_t framebuffer_width;   // +4
    uint16_t efb_height;          // +6
    uint16_t xfb_height;          // +8
    char pad[25 - 10];
    uint8_t antialias;            // +0x19
    uint8_t samples[24];          // +0x1a
    uint8_t filter[7];            // +0x32
};
struct VideoOwner {
    char pad[0x28];
    Ptr32<RenderMode> mode;       // +0x28
    char pad2[0x21c - 0x2c];
    w3d_u32 clear_colour;         // +0x21c
};
struct Renderer {
    w3d_u32 table;
    char pad[0x14 - 4];
    w3d_u32 view;                 // +0x14
    char pad2[0xb8 - 0x18];
    Ptr32<void> fifo_memory;      // +0xb8
    w3d_u32 pad3;
    w3d_u32 fifo;                 // +0xc0
    char pad4[0xe8 - 0xc4];
    w3d_u32 a;                    // +0xe8
    w3d_u32 pad5;
    w3d_u32 b;                    // +0xf0
    char pad6[0x308 - 0xf4];
    w3d_u32 c;                    // +0x308
    float projection[4][4];       // +0x30c
    float view_matrix[3][4];      // +0x34c
    char pad7[0x458 - 0x37c];
    float texture_matrix[3][4];   // +0x458
};
const w3d_u32 kFifoBytes = 0x80000;
}
extern "C" {
extern Ptr32<VideoOwner> A804b1888;
extern const float A803a4dfc, A803a4e00, A803a4e04, A803a4e08;
extern const char A803a4d80[], A803a4d94[], A803a4da8[], A803a4dbc[], A803a4dd0[], A803a4de0[], A803a4df0[];
w3d_u32 A801fdfc8(w3d_u32);
void A80206920(const char *name, int *value);
w3d_u32 A801fe2a8(w3d_u32 bytes, w3d_u32 align);
w3d_u32 A80305374(void *memory, w3d_u32 bytes);
void A8030c264(float x, float y, float width, float height, float near_z, float far_z);
void A8030c2ac(w3d_u32 x, w3d_u32 y, w3d_u32 width, w3d_u32 height);
void A80308dc8(w3d_u32 x, w3d_u32 y, w3d_u32 width, w3d_u32 height);
void A80308e44(w3d_u32 width, w3d_u32 height);
void A80308ef4(float scale);
void A80309038(w3d_u32 antialias, void *samples, w3d_u32 enable, void *filter);
void A8030bacc(w3d_u32 format, w3d_u32);
void A80309240(w3d_u32 colour);
void A801680ec(w3d_u32);
void A803080e0(w3d_u32, w3d_u32);
void A80302ec4(void *matrix, float, float, float, float, float, float);
void A80302b60(void *matrix);
void A801685cc(void *self);
void A8016710c(void *self);
void A80304b84(w3d_u32);
void A8030bba0(w3d_u32);
void A8016eed0(void *owner);

// 0x80167118. Los GQR que fija el original no existen en el anfitrión. El original informa de la memoria libre en dos puntos (A80347324 no hace nada).
w3d_u32 A80167118(Ptr32<Renderer> self, w3d_u32 view) {
    self->view = view;
    A801fdfc8(0);
    int width = 0x280, height = 0x1c0, red_bits = 0x20, depth_bits = 0x20, a = 0, b = 0, c = 1;
    A80206920(A803a4d80, &width);
    A80206920(A803a4d94, &height);
    A80206920(A803a4da8, &red_bits);
    A80206920(A803a4dbc, &depth_bits);
    A80206920(A803a4dd0, &a);
    A80206920(A803a4de0, &b);
    A80206920(A803a4df0, &c);
    self->fifo_memory.v = A801fe2a8(kFifoBytes, 0x20);
    self->fifo = A80305374(self->fifo_memory.get(), kFifoBytes);
    VideoOwner *owner = A804b1888;
    RenderMode *mode = owner->mode;
    A8030c264(A803a4dfc, A803a4dfc, (float)mode->framebuffer_width, (float)mode->efb_height, A803a4dfc, A803a4e00);
    A8030c2ac(0, 0, mode->framebuffer_width, mode->efb_height);
    A80308dc8(0, 0, mode->framebuffer_width, mode->efb_height);
    A80308e44(mode->framebuffer_width, mode->xfb_height);
    A80308ef4((float)((float)mode->xfb_height / (float)mode->efb_height));
    A80309038(mode->antialias, mode->samples, 1, mode->filter);
    A8030bacc(mode->antialias ? 2 : 0, 0);
    A80309240(owner->clear_colour);
    A801fdfc8(0);
    A801680ec(2);
    A803080e0(1, 8);
    self->c = 0;
    self->a = 0;
    self->b = 0;
    A80302ec4(self->projection, A803a4e04, A803a4e08, A803a4e04, A803a4e08, A803a4e04, A803a4e00);
    A80302b60(self->view_matrix);
    A80302b60(self->texture_matrix);
    A801685cc(self.get());
    A8016710c(self.get());
    A80304b84(1);
    A8030bba0(1);
    call_virtual<void>(self.get(), 0x18);
    A8016eed0(owner);
    return 0;
}
}
