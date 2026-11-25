#include "w3d_ptr.h"
#line 1 "d30k_gauge_bar_layout_8026807c.cpp"
// GWMP8P rev0 0x8026807c. Eases a bar's current percentage toward its target
// by a quarter each update, snapping within 0.01, then positions the fill
// node and the two groups of four edge nodes from the width, height and edge
// size. Names are inferred from use. The leading literal 0.01 stays extern
// because the pool starts 4 bytes past an 8-byte boundary; owns the tail
// from 0x803cb728. Built with -mps-float: frame gap only without it.
extern float lbl_803cb724[];
struct Vec { float x, y, z; Vec(float a, float b, float c) { Ptr32<Vec> p = this; x = a; y = b; p->z = c; } Vec(const Vec &); };
struct Node;
struct NodeVt { Ptr32<void> u[19]; Ptr32<void (Ptr32<Node>, Ptr32<const Vec>, int)> setpos; Ptr32<void> u80; Ptr32<void (Ptr32<Node>, Ptr32<const Vec>, int)> setscale; };
struct Node { Ptr32<NodeVt> vt; };
struct Geom { char u[20]; float width; };
struct Panel {
 char u0[40]; Ptr32<Geom> geom; char u44[168]; Ptr32<Node> root; char u216[240]; Ptr32<Node> a[2]; Ptr32<Node> b[2]; Ptr32<Node> c[2]; Ptr32<Node> d[2]; char u488[8]; int on; int ready; char u504[32]; float size; char u540[8]; float cur; float target; char u556[4]; float edge;
};
extern "C" void w3d_d30k_gauge_bar_layout_8026807c(Ptr32<Panel> self) {
 if (self->on == 0) return;
 if (self->ready == 0) return;
 if (self->cur == self->target) return;
 if (self->target != self->cur) {
  float d = self->target - self->cur;
  if (d < lbl_803cb724[0] && d > -0.01f) self->cur = self->target;
  else { float k = 0.25f; self->cur = self->cur * (1.0f - k) + self->target * k; }
 }
 float s = self->cur / 100.0f;
 Vec v(self->geom->width * s, 0.0f, 0.0f);
 self->root->vt->setpos(self->root, &v, 0);
 float size = self->size;
 float w = self->geom->width * (self->cur / 100.0f);
 float h = self->edge * 0.5f;
 float m = size / 7.0f * 2.33334f * 6.0f + w;
 float n = m * 0.5f;
 Vec v1(n - w, size * 0.5f + h, 0.0f);
 Vec v2(n - w, -size * 0.5f - h, 0.0f);
 float hh = h * 0.5f;
 float q = m + hh - w;
 Vec v3(q, size * 0.5f + h, 0.0f);
 Vec v4(q, -size * 0.5f - h, 0.0f);
 Vec v5(n, h, 1.0f);
 Vec v6(hh, h, 1.0f);
 Ptr32<Ptr32<Node>> p = &self->d[0];
 for (int i = 2; i != 0; i--) {
  p[-6]->vt->setpos(p[-6], &v1, 0);
  p[-4]->vt->setpos(p[-4], &v2, 0);
  p[-2]->vt->setpos(p[-2], &v3, 0);
  p[0]->vt->setpos(p[0], &v4, 0);
  p[-6]->vt->setscale(p[-6], &v5, 0);
  p[-4]->vt->setscale(p[-4], &v5, 0);
  p[-2]->vt->setscale(p[-2], &v6, 0);
  p[0]->vt->setscale(p[0], &v6, 0);
  p++;
 }
}


