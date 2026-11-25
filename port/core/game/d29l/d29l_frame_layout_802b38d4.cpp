#include "w3d_ptr.h"
#line 1 "d29l_frame_layout_802b38d4.cpp"
// GWMP8P rev0 0x802b38d4. Nine-slice frame layout: computes half sizes and
// border, sets the scale and position of each part, rotates the right edge a
// quarter turn and lays out the inner object. Part and field names are
// inferred from the arithmetic.
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Node;
struct NodeVt { char u0[76]; Ptr32<void (Ptr32<Node>, Ptr32<Vec>, int)> place; Ptr32<void (Ptr32<Node>, Ptr32<Vec>, int)> rotate; Ptr32<void (Ptr32<Node>, Ptr32<Vec>, int)> scale; };
struct Node { Ptr32<NodeVt> vt; };
struct Frame {
    char u0[36];
    Ptr32<Node> tl; Ptr32<Node> tr; Ptr32<Node> bl; Ptr32<Node> right; Ptr32<Node> top; Ptr32<Node> centre;
    char u60[4];
    float border;
    char u68[12];
    float w, h;
    char u88[12];
    Ptr32<void> inner;
};
extern "C" void fn_802ae5f8(Ptr32<void>, float, float, float);
extern "C" void d29l_frame_layout_802b38d4(Ptr32<Frame> self) {
    float b = self->border;
    float hw = self->w * 0.5f;
    float hh = self->h * 0.5f;
    float bh = b * 0.5f;
    Vec sTop(hw - b, bh, 1.0f);
    Vec sSide(hh - b, bh, 1.0f);
    Vec sCorner(bh, bh, 1.0f);
    float iw = hw - bh;
    float ih = hh - bh;
    Vec sCentre(iw, ih, 1.0f);
    self->tl->vt->scale(self->tl, &sCorner, 0);
    self->tr->vt->scale(self->tr, &sCorner, 0);
    self->bl->vt->scale(self->bl, &sCorner, 0);
    self->right->vt->scale(self->right, &sSide, 0);
    self->top->vt->scale(self->top, &sTop, 0);
    self->centre->vt->scale(self->centre, &sCentre, 0);
    Vec p0(-iw, ih, 0.0f);
    Vec p1(iw, ih, 0.0f);
    Vec p2(-iw, -ih, 0.0f);
    Vec p3(iw, -ih, 0.0f);
    Vec p4(-iw, 0.0f, 0.0f);
    Vec p5(iw, 0.0f, 0.0f);
    Vec p6(0.0f, ih, 0.0f);
    Vec p7(0.0f, -ih, 0.0f);
    Vec p8(0.0f, 0.0f, 0.0f);
    self->centre->vt->place(self->centre, &p8, 0);
    p1.x += bh; p1.y -= bh;
    p2.x += bh; p2.y -= bh;
    p3.x += bh; p3.y -= bh;
    p5.x += bh; p5.y -= bh;
    p7.x += bh; p7.y -= bh;
    self->tl->vt->place(self->tl, &p1, 0);
    self->tr->vt->place(self->tr, &p2, 0);
    self->bl->vt->place(self->bl, &p3, 0);
    self->right->vt->place(self->right, &p5, 0);
    self->top->vt->place(self->top, &p7, 0);
    Vec r(0.0f, 0.0f, 1.57079637f);
    self->right->vt->rotate(self->right, &r, 0);
    if (self->inner) fn_802ae5f8(self->inner, b, self->w * 0.5f, self->h * 0.5f);
}


