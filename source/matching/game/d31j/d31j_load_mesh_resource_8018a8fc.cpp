// Loads the mesh resource of an instance node, attaches it to a new node and
// instance, and rebuilds its sorted edges. Ref default constructor does not
// initialise; the texture Ref is declared with the mesh Ref. GWMP8P rev0
// 0x8018a8fc.
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
void w3d_string_base_init(void *);
unsigned short *w3d_string_header(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_release_header(void *);
void w3d_k5b_iface_array_field_append_801ef174(void *, int, int, void *);
int w3d_k8b_iface_add_801b14e8(void *, void *);
}
struct Iface { virtual int query(void *, void *); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref() {}
  void attach(T *q) { p = q; if (p) p->add(); }
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
  Ref &operator=(const Ref &o) { T *old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct Str {
  char *p;
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
  Str &operator=(const Str &o) {
    ++*(unsigned short *)(o.p - 6);
    unsigned short *h = (unsigned short *)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
inline void use(Str) {}
struct Vec { float x, y, z; };
struct Sphere { Vec c; float r; };
struct Box { Vec lo; Vec hi; };
struct Bits { char p0[7]; unsigned char flags; void mark() { flags |= 2; } };
struct Tex : Iface {
  Bits bits; char pc[60];
  Vec a; Vec b; Vec c;
  void setB(const Vec &v) { b = v; bits.mark(); }
  void setC(const Vec &v) { c = v; bits.mark(); }
};
struct Part { char p0[36]; struct Leaf *leaf; };
struct Leaf { char p0[56]; int dirty; };
struct Blob { char p0[24]; unsigned int count; char p1c[4]; Part *data[1]; };
struct Mesh : Iface { char p4[24]; Blob *parts; };
struct Inst : Iface { void setBound(const Sphere &v) { bound = v; } char p4[16]; Sphere bound; Str name; int z40; char p2c[4]; Ref<Tex> tex; };
struct Node : Iface { void setBound(const Sphere &v) { bound = v; } char p4[16]; Sphere bound; char p24[4]; int z40; char p2c[8]; Ref<Mesh> mesh; };
struct Loader : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual int create(void *, int, Ref<Mesh> *); };
struct Sink : Iface { virtual void a3(); virtual void attach(Mesh *); };
struct Self : Iface {
  virtual void v20(); virtual void v24(); virtual void v28(); virtual void v32(); virtual void v36(); virtual void v40(); virtual void v44(); virtual void v48(); virtual void v52(); virtual void v56(); virtual void v60(); virtual void v64(); virtual void v68(); virtual void v72(); virtual void v76(); virtual void v80(); virtual void v84(); virtual void v88();
  virtual void set92(int); virtual void set96(int); virtual void set100(int);
  char p4[16]; Str name; int flags; char p1c[4]; Ref<Inst> inst; Ref<Mesh> mesh; Ref<Node> node; char p2c[16]; unsigned short opts; char p3e[2]; void *res;
};
extern "C" int w3d_d29e_run_file_8020b6e8(void *, void *);
extern "C" void w3d_cx13b_sphere_bounds_801f5724(Box *, Sphere *);
extern "C" int d26j_rebuild_sorted_edges_8018b638(Self *);
extern void *lbl_804b0240, *lbl_804b0244, *lbl_804b0250;
extern Sink *lbl_804b025c, *lbl_804b0264, *lbl_804b0260, *lbl_804b026c;
extern char lbl_8040e058[], lbl_8040e118[], lbl_80414518[], lbl_804144f8[], lbl_80414940[];
extern "C" int d31j_load_mesh_resource_8018a8fc(Self *self) {
  int on = (self->flags >> 15) & 1;
  if (on) return 0x80004005;
  Ref<Iface> file(0);
  Loader *loader;
  if (w3d_d29e_run_file_8020b6e8(self->res, &file) < 0) {
    use(self->name);
    goto bad;
  }
  if (file->query(lbl_8040e058, &loader) < 0) {
    bad:
    return 0x80004005;
  }
  Ref<Mesh> got(0);
  Ref<Tex> tex;
  loader->create(lbl_8040e118, 0, &got);
  loader->release();
  self->mesh = got.p;
  self->node = (Node *)w3d_s10_service_forward_8020b680(lbl_80414518);
  Node *n = self->node.p;
  n->mesh = self->mesh;
  Vec a; Vec *pa = &a;
  Vec b; Vec *pb = &b;
  Box box;
  Sphere s; Sphere *ps = &s;
  Box *pbox = &box;
  Blob *parts = self->mesh.p->parts;
  unsigned int count = parts->count;
  Part **d = parts->data;
  for (unsigned int i = 0; i < count; i++) d[i]->leaf->dirty = 1;
  w3d_k8b_iface_add_801b14e8(self->mesh.p, lbl_804b0240);
  w3d_k8b_iface_add_801b14e8(self->mesh.p, lbl_804b0244);
  w3d_k8b_iface_add_801b14e8(self->mesh.p, lbl_804b0250);
  lbl_804b025c->attach(self->mesh.p);
  lbl_804b0264->attach(self->mesh.p);
  lbl_804b0260->attach(self->mesh.p);
  lbl_804b026c->attach(self->mesh.p);
  self->inst = (Inst *)w3d_s10_service_forward_8020b680(lbl_804144f8);
  tex.attach((Tex *)w3d_s10_service_forward_8020b680(lbl_80414940));
  a.x = 0.0f; pa->y = 0.0f; pa->z = 0.0f;
  b.x = 0.0f; pb->y = 0.0f; pb->z = 0.0f;
  {
    Inst *ni = self->inst.p;
    ni->name = self->name;
  }
  w3d_k5b_iface_array_field_append_801ef174(self->inst.p, 44, 3, self->node.p);
  self->inst->tex = tex;
  tex->setC(a);
  tex->setB(b);
  self->flags |= 0x8000;
  if (self->opts & 1) self->set92(1); else self->set92(0);
  if (self->opts & 2) self->set96(1); else self->set96(0);
  if (self->opts & 16) self->set100(1); else self->set100(0);
  s.r = 5e10f; s.c.x = 0.0f; ps->c.y = 0.0f; ps->c.z = 0.0f;
  w3d_cx13b_sphere_bounds_801f5724(pbox, ps);
  self->inst->setBound(s);
  self->inst->z40 = 0;
  self->node->setBound(s);
  self->node->z40 = 0;
  return d26j_rebuild_sorted_edges_8018b638(self);
}
