// Compute an attachment matrix: bind a solver to the object and instance, attach
// a temporary node, compute the 48-byte matrix through a second service, copy it
// out and detach the temporary node again. GWMP8P rev0 0x80181e3c.
extern "C" void *w3d_s10_service_forward_8020b680(void *);
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
};
struct Mat { float m[12]; };
struct List { char p0[24]; unsigned int count; char p1c[4]; Iface *data[1]; };
struct Owner { char p0[44]; List *list; };
extern "C" void w3d_k5b_iface_array_field_append_801ef174(Owner *, int, int, Iface *);
extern "C" void fn_801ef380(Owner *, int, int, unsigned int, int);
struct X : Iface {
  virtual void s20(); virtual int bind(Iface *); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual int set(Iface *); virtual Owner *owner();
  virtual void s56(); virtual void s60(); virtual void s64(); virtual void s68(); virtual void s72(); virtual int solve(Iface *, Iface *, Mat **);
};
struct Self { char p0[120]; Iface *inst; };
extern char lbl_804164c0[], lbl_804163f8[], lbl_80414a40[], lbl_804140d0[];
extern "C" int d30j_solve_attachment_matrix_80181e3c(Self *self, Iface *a, Mat *out) {
  if (a) {
    Ref<X> x((X *)w3d_s10_service_forward_8020b680(lbl_804164c0));
    x->set(a);
    if (x->bind(self->inst) >= 0) {
      Ref<X> c((X *)w3d_s10_service_forward_8020b680(lbl_804163f8));
      Ref<Iface> d((Iface *)w3d_s10_service_forward_8020b680(lbl_80414a40));
      Ref<X> e((X *)w3d_s10_service_forward_8020b680(lbl_804140d0));
      Owner *o = x->owner();
      w3d_k5b_iface_array_field_append_801ef174(o, 44, 3, d.p);
      Iface *i = self->inst;
      e->set(c.p);
      e->bind(i);
      Mat *m;
      c->solve(d.p, i, &m);
      *out = *m;
      List *l = o->list;
      unsigned int n = l->count;
      Iface **q = l->data;
      for (unsigned int k = 0; k < n; k++) {
        if (q[k] == d.p) {
          fn_801ef380(o, 44, 3, k, 1);
          return 0;
        }
      }
    }
  }
  return 0x80004005;
}
