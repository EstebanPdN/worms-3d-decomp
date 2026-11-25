// Finish copying a dynamic texture from another: copy its format fields, clear
// its work buffer, mark the selected image dirty, take references to the source
// object and its helper, recompute the tile size, lock the mesh's vertex arrays
// and reapply its three modes. GWMP8P rev0 0x80170374.
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
struct Ref {
  Iface *p;
  void set(Iface *q) { if (q) q->add(); if (p) p->release(); p = q; }
};
struct Blob { char p0[4]; unsigned short kind; char p6[18]; int locked; unsigned short count; };
struct Handle {
  Blob *b;
  void lock(int stride);
};
extern "C" int w3d_k5b_array_ref_lock_801ef048(Handle *, int, int, int);
inline void Handle::lock(int stride) {
  if (b->kind == 1 && b->locked == 0) b->count++;
  else w3d_k5b_array_ref_lock_801ef048(this, 0, stride, 0);
}
struct Mesh { char p0[64]; Handle a64; Handle a68; char p48[12]; Handle a84; Handle a88; unsigned char skinned; char p5d[3]; Handle a96; Handle a100; };
struct Geom { char p0[48]; Mesh *mesh; Iface *ref52; };
struct Inner { char p0[32]; Iface *ref; };
struct Node { char p0[44]; Inner *inner; };
struct Bits { char p0[7]; unsigned char flags; void mark() { flags |= 4; } };
struct Sel { void *vt; Bits bits; };
struct Buf { char *start; char *finish; char p8[4]; int used; };
struct Vec { int n; int m; Ref *start; };
struct NVec { int n; int m; Node **start; };
struct GVec { int n; int m; Geom **start; };
struct Tex {
  char p0[24]; int flags; unsigned char pad; unsigned char mode_; char p1a[6];
};
struct Self {
  char p0[24]; union { int flags; struct { unsigned char c0, mode; } b; } u; char p1c[4]; int w32; unsigned short h36, h38, h40, h42, h44, h46, h48, h50;
  Vec refs; NVec nodes; Ref extra;
};
extern "C" {
Self *w3d_empty_80343808(void *);
Buf *w3d_auto_801720c0(Self *, int);
int fn_801720fc(Self *, int);
Sel *w3d_s20_get_selected_80172088(Self *, int);
int w3d_auto_80171b1c(Self *, int);
int w3d_auto_80171ab8(Self *, int);
int w3d_auto_80171b80(Self *, int);
void *fn_802eee50(void *, const void *, ...);
}
extern "C" int d30j_copy_cube_texture_80170374(Self *self, void *from) {
  int zero = 0;
  Vec &refs = self->refs;
  Self *src = w3d_empty_80343808(from);
  self->u.b.mode = src->u.b.mode;
  self->w32 = src->w32;
  self->h42 = src->h42;
  self->h40 = src->h40;
  self->h42 = src->h42;
  self->h36 = src->h36;
  self->h38 = src->h38;
  self->h48 = src->h48;
  self->u.flags |= 0x8000;
  self->h50 = src->h50;
  Buf *v = w3d_auto_801720c0(self, self->u.b.mode);
  char *e = v->finish;
  char *s = v->start;
  int n = e - s;
  fn_802eee50(s, e, 0);
  v->used = zero;
  v->finish -= n;
  int k = fn_801720fc(self, self->u.b.mode);
  w3d_s20_get_selected_80172088(self, self->u.b.mode)->bits.mark();
  refs.start[k].set(self->nodes.start[k]->inner->ref);
  self->extra.set(((Geom **)refs.start)[k]->ref52);
  if (self->h50 & 32) {
    self->h40 = self->h44 / self->h36;
    self->h42 = self->h46 / self->h38;
  } else {
    self->h36 = self->h44 / self->h40;
    self->h38 = self->h46 / self->h42;
  }
  Mesh *m = ((Geom **)self->refs.start)[k]->mesh;
  m->a84.lock(4);
  m->a96.lock(1);
  m->a100.lock(1);
  m->a64.lock(12);
  m->a88.lock(4);
  m->a68.lock(8);
  if (self->h50 & 1024) m->skinned = 1;
  if (self->h50 & 2) w3d_auto_80171b1c(self, 1); else w3d_auto_80171b1c(self, 0);
  if (self->h50 & 1) w3d_auto_80171ab8(self, 1); else w3d_auto_80171ab8(self, 0);
  if (self->h50 & 16) w3d_auto_80171b80(self, 1); else w3d_auto_80171b80(self, 0);
  return 0;
}
