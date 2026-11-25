// (Worms 3D GameCube PAL, 0x801acb34).
//
// Resets a scene node: recomputes its transform through 0x801acd6c with the
// table at 0x8045e748, marks it ready at +136, clears the tree at +100 and
// the 16-byte element vector at +116 (STLport erase with an empty copy and a
// destroy loop), then replaces the held service at +132 with the one found
// for 0x80413b28 (add, release old, store) and calls its virtual slot 12
// with 0. Returns 0. Names are inferred.

extern "C" void f4c_inverse_transpose_801acd6c(void *, void *);
extern char lbl_8045e748[];
extern char lbl_80413b28[];
struct Service {
  virtual void v0(); virtual void add(); virtual void release();
  virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11();
  virtual void bind(int);
};
extern "C" Service *w3d_s10_service_forward_8020b680(void *);
extern "C" void w3d_auto_801f2758(void *, int);
extern "C" void w3d_auto_80355800(void *, void *);
struct Node { int p0; Node *parent; Node *left; Node *right; };
struct Tree {
  int p0;
  Node *header;
  int count;
  void erase(Node *n) { w3d_auto_80355800(this, n); }
  void clear() {
    if (count != 0) {
      erase(header->parent);
      header->left = header;
      header->parent = 0;
      header->right = header;
      count = 0;
    }
  }
};
struct Elem { char p[16]; ~Elem() { w3d_auto_801f2758(this, 2); } };
template<class T> inline void v_dist(T *first, T *last, int &n) { n += last - first; }
template<class T> inline T *v_copy(T *first, T *last, T *out) {
    int n = 0;
    v_dist(first, last, n);
    for (; n > 0; --n) { *out = *first; ++first; ++out; }
    return out;
}
template<class T> inline void v_destroy(T *first, T *last) { for (; first != last; ++first) first->~T(); }
struct Vec { Elem *b, *e;
  Elem *begin() { return b; } Elem *end() { return e; }
  void erase(Elem *first, Elem *last) {
    Elem *n = v_copy(last, e, first);
    { Elem *l = e; v_destroy(n, l); }
    e = n;
  }
  void clear() { erase(begin(), end()); }
};
struct Scene {
  char p0[100];
  Tree tree;
  char p1[4];
  Vec vec;
  char p2[8];
  Service *service;
  int ready;
};
extern "C" int w3d_d29e_reset_scene_801acb34(Scene *self) {
  f4c_inverse_transpose_801acd6c(self, lbl_8045e748);
  self->ready = 1;
  self->tree.clear();
  self->vec.clear();
  Service *s = w3d_s10_service_forward_8020b680(lbl_80413b28);
  if (s) s->add();
  if (self->service) self->service->release();
  self->service = s;
  s->bind(0);
  return 0;
}
