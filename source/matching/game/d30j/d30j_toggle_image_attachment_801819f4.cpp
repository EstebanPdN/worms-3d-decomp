// Attach or detach the default image of a resource: fetch the image from the
// store; to attach, create a node holding it and append it to the instance; to
// detach, find the node of the right type holding it and remove it. Keeps the
// state in a flag. GWMP8P rev0 0x801819f4.
extern "C" void *w3d_s10_service_forward_8020b680(void *);
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref() { p = 0; }
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  Ref &operator=(const Ref &o) { T *old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct Type { char p0[20]; Type *parent; };
extern char lbl_80362844[];
extern char lbl_8040e0d8[], lbl_80414518[];
struct Node : Iface { virtual Type *type(); char p4[44]; Ref<Iface> image; 
  bool isA(Type *t) {
    Type *c = type();
    while (c != t) {
      if (c == c->parent) return false;
      c = c->parent;
    }
    return true;
  }
};
struct List { char p0[24]; unsigned int count; char p1c[4]; Node *data[1]; };
struct Owner { char p0[44]; List *list; };
extern "C" void w3d_k5b_iface_array_field_append_801ef174(Owner *, int, int, Node *);
extern "C" void fn_801ef380(Owner *, int, int, unsigned int, int);
struct Store : Iface { virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual int get(void *, int, Ref<Iface> *); };
struct Res { char p0[40]; Store *store; };
extern "C" Res *w3d_empty_80341348(void *);
struct Self { char p0[116]; void *item; Owner *inst; char p7c[56]; unsigned int flags; };
extern "C" int d30j_toggle_image_attachment_801819f4(Self *self, int on) {
  if (on == (int)((self->flags >> 30) & 1)) return 0;
  Ref<Iface> t;
  int hr = w3d_empty_80341348(self->item)->store->get(lbl_8040e0d8, 0, &t);
  Ref<Iface> u(t.p);
  if (hr < 0) return hr;
  if (on) {
    Ref<Node> n((Node *)w3d_s10_service_forward_8020b680(lbl_80414518));
    n->image = u;
    w3d_k5b_iface_array_field_append_801ef174(self->inst, 44, 3, n.p);
    self->flags |= 0x40000000;
  } else {
    List *l = self->inst->list;
    unsigned int c = l->count;
    Node **q = l->data;
    for (unsigned int k = 0; k < c; k++) {
      if (q[k]->isA((Type *)lbl_80362844) && q[k]->image.p == u.p) {
        fn_801ef380(self->inst, 44, 3, k, 1);
        self->flags &= ~0x40000000;
        return 0;
      }
    }
    return 0x80004005;
  }
  return 0;
}
