#include "w3d_ptr.h"
#line 1 "d30j_draw_overlay_quads_8016e6fc.cpp"
// Draw the overlay's queued quads: clear colour black, an orthographic
// projection of the screen, identity view, GX state for textured 2D primitives,
// then one draw per quad, and a final swap. GWMP8P rev0 0x8016e6fc.
struct GXColor { unsigned char r, g, b, a; };
struct RenderMode { char p0[4]; unsigned short fbWidth; unsigned short efbHeight; };
struct Renderer { char p0[40]; Ptr32<RenderMode> mode; };
struct Quad { int a, b, c; };
struct Overlay { int vt; Quad quads[45]; char pad[8]; unsigned int count; int enabled; };
extern Ptr32<Renderer> lbl_804b1888;
extern Ptr32<void> lbl_804b1884;
extern "C" {
int cc45a_swap_8016eed0(Ptr32<Renderer>);
void fn_80308fc0(GXColor, unsigned int);
void fn_80302ec4(Ptr32<float>, float, float, float, float, float, float);
void fn_8030bec4(Ptr32<float>, int);
void fn_80302b60(Ptr32<float>);
void fn_8030bff4(Ptr32<float>, int);
void fn_8030c094(int);
void fn_80308be8(int);
void fn_8030b3dc(int, int, int, int, int);
void fn_8030ba98(int);
void fn_8030ba64(int, int, int);
void fn_8030ba0c(int);
void fn_8030ba38(int);
void fn_8030990c(int);
void fn_8030b648(int);
void fn_8030af88(int, int);
void fn_8030b4ac(int, int, int, int);
void fn_8030b9b8(int, int, int, int);
void fn_80307558();
void fn_80306cd0(int, int);
void fn_80307590(int, int, int, int, int);
int fn_8016e1c0(Ptr32<Overlay>, int, int, Ptr32<void>);
void d30j_draw_overlay_quads_8016e6fc(Ptr32<Overlay> self) {
  if (self->enabled && self->count && lbl_804b1884) {
    float proj[4][4];
    float view[3][4];
    GXColor black;
    black.r = 0; black.g = 0; black.b = 0; black.a = 255;
    fn_80308fc0(black, 0xffffff);
    Ptr32<RenderMode> m = lbl_804b1888->mode;
    fn_80302ec4(proj[0], 0.0f, (float)m->efbHeight, 0.0f, (float)m->fbWidth, 0.0f, -100.0f);
    fn_8030bec4(proj[0], 1);
    fn_80302b60(view[0]);
    fn_8030bff4(view[0], 0);
    fn_8030c094(0);
    fn_80308be8(0);
    fn_8030b3dc(7, 0, 0, 7, 0);
    fn_8030ba98(1);
    fn_8030ba64(1, 7, 1);
    fn_8030ba0c(1);
    fn_8030ba38(0);
    fn_8030990c(0);
    fn_8030b648(1);
    fn_8030af88(0, 3);
    fn_8030b4ac(0, 0, 0, 255);
    fn_8030b9b8(1, 1, 1, 0);
    fn_80307558();
    fn_80306cd0(9, 1);
    fn_80306cd0(13, 1);
    fn_80307590(0, 9, 1, 3, 0);
    fn_80307590(0, 13, 1, 3, 0);
    for (unsigned int i = 0; i < self->count; i++)
      { Quad &q = self->quads[i]; fn_8016e1c0(self, q.a, q.b, (Ptr32<void>)w3d::G(q.c)); }
    cc45a_swap_8016eed0(lbl_804b1888);
  }
}
}


