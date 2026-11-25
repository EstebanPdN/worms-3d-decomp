#include "w3d_ptr.h"
#line 1 "d42j_particle_quads_emit_8016c7d0.cpp"
// Emits one textured, coloured quad per particle to the GX FIFO: position, optional world transform, optional
// rotation by a sine table angle, per-particle or shared size and colour, optional visibility mask.
// Member names are inferred from the data flow.
inline void *operator new(__SIZE_TYPE__, void *p) { return p; }
union Fifo { float f; int i; };
extern "C" volatile Fifo fifo_cc008000[];
struct Vec3 { float x, y, z; };
struct Vec2 { float x, y; Vec2() {} Vec2(float a, float b) { x = a; y = b; } float &Y() { return y; } };
struct Color { unsigned char r, g, b, a;
  Color(unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_) { r = r_; g = g_; b = b_; a = a_; } };
struct Arr { char p0[24]; unsigned int count; int p1c; char data[1]; };
struct Tex { char p0[36]; Ptr32<Arr> size; Ptr32<Arr> offset; };
struct Mesh { char p0[64]; Ptr32<Arr> pos; Ptr32<Arr> size; char p[12]; Ptr32<Arr> color; Ptr32<Arr> rot; char q[4]; Ptr32<Arr> mask; Ptr32<Arr> ids; };
struct Mat { float m[12]; };
struct R;
struct RVt { Ptr32<void> u[18]; Ptr32<Ptr32<Tex> (Ptr32<R>)> tex; };
struct R { Ptr32<RVt> vt; char p[232]; Mat world; };
extern int lbl_804b00fc;
extern Vec2 lbl_804b00f4;
extern const float lbl_803a5f3c[];
extern Ptr32<void> lbl_804b1884;
extern "C" {
void d30j_set_vertex_format_8016797c(Ptr32<void>, int, int, int);
void gx_begin_803089c8(unsigned char, unsigned char, unsigned short);
void push_world_8016a1bc(Ptr32<R>);
void pop_world_8016a194(Ptr32<R>);
}
inline unsigned Get(const unsigned &n) { return n; }
inline bool Lt(unsigned a, const unsigned &b) { return a < b; }
inline void P(float x, float y, float z) { fifo_cc008000[0].f = x; fifo_cc008000[0].f = y; fifo_cc008000[0].f = z; }
inline void T(float x, float y) { fifo_cc008000[0].f = x; fifo_cc008000[0].f = y; }
extern "C" void particle_quads_emit_8016c7d0(Ptr32<R> self, Ptr32<Mesh> m, int world) {
  Ptr32<unsigned char> ids = (Ptr32<unsigned char>)m->ids->data;
  unsigned int n = m->ids->count;
  if (n) {
  Ptr32<Arr> aRot = m->rot; Ptr32<Arr> aSize = m->size; Ptr32<Arr> aColor = m->color; Ptr32<Arr> aPos = m->pos; Ptr32<Arr> aMask = m->mask;
  unsigned maskCount = aMask->count;
  unsigned int nRot = aRot->count;
  unsigned int nSize = aSize->count;
  unsigned int nColor = aColor->count;
  Ptr32<float> rot = (Ptr32<float>)aRot->data;
  Ptr32<Vec2> size = (Ptr32<Vec2>)aSize->data;
  Ptr32<int> colors = (Ptr32<int>)aColor->data;
  Ptr32<Vec3> pos = (Ptr32<Vec3>)aPos->data;
  Ptr32<unsigned char> mask = (Ptr32<unsigned char>)aMask->data;
  if (maskCount == 0) mask = 0;
  if (lbl_804b00fc == 0) { lbl_804b00fc = 1; new (&lbl_804b00f4) Vec2(1.0f, 1.0f); }
  Ptr32<Vec2> sz = size;
  if (nSize == 0) sz = &lbl_804b00f4;
  const Mat &w_ = self->world;
  Ptr32<Tex> tex = self->vt->tex(self);
  Ptr32<Vec2> off = (Ptr32<Vec2>)tex->offset->data;
  Ptr32<Vec2> scale = (Ptr32<Vec2>)tex->size->data;
  Color white(255, 255, 255, 255);
  unsigned int total = 0;
  if (mask) {
    for (unsigned int j = 0; Lt(j, n); j++) if (mask[j]) total += 4;
  } else total = n * 4;
  if (total == 0) return;
  if (world) push_world_8016a1bc(self);
  d30j_set_vertex_format_8016797c(lbl_804b1884, 145, 1, 0);
  gx_begin_803089c8(128, 0, total);
  for (unsigned int i = 0; i < n; i++) {
    if (mask == 0 || mask[i] != 0) {
      unsigned int id = ids[i];
      Ptr32<Vec2> o = off + id;
      Ptr32<Vec2> s = scale + id;
      Ptr32<Vec3> q = &pos[i];
      Ptr32<int> c;
      if (Get(nColor) == 0) c = (Ptr32<int>)&white;
      else if (nColor == 1) c = colors;
      else c = colors + i;
      Vec3 v; Ptr32<Vec3> p;
      if (world) {
        v.x = q->x * w_.m[0] + q->y * w_.m[1] + q->z * w_.m[2] + w_.m[3];
        v.y = q->x * w_.m[4] + q->y * w_.m[5] + q->z * w_.m[6] + w_.m[7];
        v.z = q->x * w_.m[8] + q->y * w_.m[9] + q->z * w_.m[10] + w_.m[11];
        p = &v;
      } else p = q;
      if (Get(nRot) != 0) {
        Vec2 h, u, w;
        unsigned char ang = (int)(rot[i] * 40.743664f);
        float ax = sz->x, ay = sz->y; h.x = ax; h.Y() = ay;
        float sn = lbl_803a5f3c[ang];
        float cs = lbl_803a5f3c[(ang + 64) & 0xff];
        u.x = h.x * cs + sn * 0.0f;
        u.Y() = cs * 0.0f - h.x * sn;
        float hy = h.Y();
        w.x = hy * sn + cs * 0.0f;
        w.Y() = hy * cs - sn * 0.0f;
        P(p->x - u.x - w.x, p->y - u.Y() - w.Y(), p->z);
        fifo_cc008000[0].i = *c;
        T(o->x, o->y);
        P(p->x + u.x - w.x, p->y + u.Y() - w.Y(), p->z);
        fifo_cc008000[0].i = *c;
        T(o->x + s->x, o->y);
        P(p->x + u.x + w.x, p->y + u.Y() + w.Y(), p->z);
        fifo_cc008000[0].i = *c;
        T(o->x + s->x, o->y + s->y);
        P(p->x - u.x + w.x, p->y - u.Y() + w.Y(), p->z);
        fifo_cc008000[0].i = *c;
        T(o->x, o->y + s->y);
      } else {
        float sx = sz->x, sy = sz->y;
        P(p->x - sx, p->y - sy, p->z);
        fifo_cc008000[0].i = *c;
        T(o->x, o->y);
        P(p->x + sx, p->y - sy, p->z);
        fifo_cc008000[0].i = *c;
        T(o->x + s->x, o->y);
        P(p->x + sx, p->y + sy, p->z);
        fifo_cc008000[0].i = *c;
        T(o->x + s->x, o->y + s->y);
        P(p->x - sx, p->y + sy, p->z);
        fifo_cc008000[0].i = *c;
        T(o->x, o->y + s->y);
      }
    }
    if (Get(nSize) > 1) sz++;
  }
  if (world) pop_world_8016a194(self);
  }
}


