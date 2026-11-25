// Emits one textured, coloured, world-transformed quad per sprite to the GX FIFO. Size comes from each position's
// fourth component; colour and alpha are per-sprite when the arrays have more than one entry; rotation by a sine
// table angle and per-sprite frame ids are optional. Twin of particle_quads_emit_8016c7d0. Member names are inferred.
union Fifo { float f; int i; };
extern "C" volatile Fifo fifo_cc008000[];
struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };
struct Vec2 { float x, y; float &Y() { return y; } };
struct Arr { char p0[24]; unsigned int count; int p1c; char data[1]; };
struct Tex { char p0[36]; Arr *scale; Arr *offset; };
struct Mesh { char p0[64]; Arr *color; Arr *pos; Arr *rot; Arr *ids; Arr *alpha; };
struct Sprites;
struct SpritesVt { char p0[72]; Tex *(*texture)(Sprites *); };
struct Face { int f; };
struct Base { SpritesVt *vt; };
struct Mat { float m[12]; };
struct Sprites : Base, Face { char p8[228]; Mat world; };
extern const float lbl_803a5f3c[];
extern void *lbl_804b1884;
extern "C" {
void push_world_8016a1bc(Sprites *);
void pop_world_8016a194(Sprites *);
void d30j_set_vertex_format_8016797c(void *, int, int, int);
void gx_begin_803089c8(unsigned char, unsigned char, unsigned short);
}
struct Color { unsigned char r, g, b, a; unsigned char &G() { return g; } unsigned char &B() { return b; } unsigned char &A() { return a; } };
inline unsigned Get(const unsigned &n) { return n; }
inline void P(float x, float y, float z) { fifo_cc008000[0].f = x; fifo_cc008000[0].f = y; fifo_cc008000[0].f = z; }
inline void T(float x, float y) { fifo_cc008000[0].f = x; fifo_cc008000[0].f = y; }
extern "C" int sprite_quads_emit_8016da74(Face *face, Mesh *mesh) {
  Sprites *self = static_cast<Sprites *>(face);
  Arr *aIds = mesh->ids, *aPos = mesh->pos, *aAlpha = mesh->alpha, *aColor = mesh->color;
  unsigned idCount = aIds->count;
  unsigned int n = aPos->count;
  unsigned int nAlpha = aAlpha->count;
  unsigned int nColor = aColor->count;
  float *ids = (float *)aIds->data;
  Vec4 *pos = (Vec4 *)aPos->data;
  float *alpha = (float *)aAlpha->data;
  Vec4 *colors = (Vec4 *)aColor->data;
  if (idCount == 0) ids = 0;
  Arr *aRot = mesh->rot;
  unsigned int nRot = aRot->count;
  float *rot = (float *)aRot->data;
  const Mat &m = self->world;
  Tex *tex = self->vt->texture(self);
  Vec2 *offs = (Vec2 *)tex->offset->data;
  Vec2 *scale = (Vec2 *)tex->scale->data;
  push_world_8016a1bc(self);
  d30j_set_vertex_format_8016797c(lbl_804b1884, 145, 1, 0);
  gx_begin_803089c8(128, 0, n * 4);
  for (unsigned int i = 0; i < n; i++) {
    unsigned int id = ids ? (unsigned char)ids[i] : 0;
    Vec2 *o = offs + id;
    Vec2 *s = scale + id;
    Vec3 v;
    Color c;
    if (Get(nColor) > 1) {
      if (nAlpha > 1) {
        c.r = (unsigned char)(colors[i].x * 255.0f);
        c.G() = (unsigned char)(colors[i].y * 255.0f);
        c.B() = (unsigned char)(colors[i].z * 255.0f);
        c.A() = (unsigned char)(alpha[i] * 255.0f);
      } else {
        c.r = (unsigned char)(colors[i].x * 255.0f);
        c.G() = (unsigned char)(colors[i].y * 255.0f);
        c.B() = (unsigned char)(colors[i].z * 255.0f);
        c.A() = (unsigned char)(colors[i].w * 255.0f);
      }
    } else {
      if (nAlpha > 1) {
        c.r = 255; c.G() = 255; c.B() = 255;
        c.A() = (unsigned char)(alpha[i] * 255.0f);
      } else {
        c.r = 255; c.G() = 255; c.B() = 255; c.A() = 255;
      }
    }
    v.x = pos[i].x * m.m[0] + pos[i].y * m.m[1] + pos[i].z * m.m[2] + m.m[3];
    v.y = pos[i].x * m.m[4] + pos[i].y * m.m[5] + pos[i].z * m.m[6] + m.m[7];
    v.z = pos[i].x * m.m[8] + pos[i].y * m.m[9] + pos[i].z * m.m[10] + m.m[11];
    if (Get(nRot) != 0) {
      Vec2 u, w;
      unsigned char ang = (int)(rot[i] * 40.743664f);
      float sn = lbl_803a5f3c[ang];
      float cs = lbl_803a5f3c[(ang + 64) & 0xff];
      float h = pos[i].w;
      u.x = h * cs + sn * 0.0f;
      u.Y() = cs * 0.0f - h * sn;
      float hy = pos[i].w;
      w.x = hy * sn + cs * 0.0f;
      w.Y() = hy * cs - sn * 0.0f;
      P(v.x - u.x - w.x, v.y - u.Y() - w.Y(), v.z);
      fifo_cc008000[0].i = *(int *)&c;
      T(o->x, o->y);
      P(v.x + u.x - w.x, v.y + u.Y() - w.Y(), v.z);
      fifo_cc008000[0].i = *(int *)&c;
      T(o->x + s->x, o->y);
      P(v.x + u.x + w.x, v.y + u.Y() + w.Y(), v.z);
      fifo_cc008000[0].i = *(int *)&c;
      T(o->x + s->x, o->y + s->y);
      P(v.x - u.x + w.x, v.y - u.Y() + w.Y(), v.z);
      fifo_cc008000[0].i = *(int *)&c;
      T(o->x, o->y + s->y);
    } else {
      float sz = pos[i].w;
      P(v.x - sz, v.y - sz, v.z);
      fifo_cc008000[0].i = *(int *)&c;
      T(o->x, o->y);
      P(v.x + sz, v.y - sz, v.z);
      fifo_cc008000[0].i = *(int *)&c;
      T(o->x + s->x, o->y);
      P(v.x + sz, v.y + sz, v.z);
      fifo_cc008000[0].i = *(int *)&c;
      T(o->x + s->x, o->y + s->y);
      P(v.x - sz, v.y + sz, v.z);
      fifo_cc008000[0].i = *(int *)&c;
      T(o->x, o->y + s->y);
    }
  }
  pop_world_8016a194(self);
  return 0;
}
