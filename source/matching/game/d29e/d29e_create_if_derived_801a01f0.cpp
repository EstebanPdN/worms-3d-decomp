// (Worms 3D GameCube PAL, 0x801a01f0).
//
// Queries the service at 0x8020b648 for the interface 0x804138b0 into a held
// reference, looks up an entry by name (slot 3) and, if the entry exists and
// base is null or found on the entry's parent chain at +20, returns the
// result of the entry's create call at table offset 88; otherwise returns 0.
// Names are inferred.

struct Obj {
  char p[20];
  Obj *parent;
  bool isA(Obj *base) {
    Obj *t = this;
    while (t != base) {
      Obj *n = t->parent;
      if (t == n) return false;
      t = n;
    }
    return true;
  }
};
struct Made;
struct Thing : Obj {};
struct Registry {
  virtual void v0();
  virtual void v1();
  virtual void release();
  virtual Obj *find(void *);
};
struct Svc { virtual int query(const void *, void *); };
extern char lbl_804138b0[];
extern "C" Svc *w3d_auto_8020b648();
struct Ref {
  Registry *p;
  Ref() : p(0) {}
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
};
struct Fac { virtual void a(); };
typedef void *(*Create)(Obj *);
extern "C" void *w3d_d29e_create_if_derived_801a01f0(void *name, Obj *base) {
  Svc *s = w3d_auto_8020b648();
  Ref m;
  if (s) s->query(lbl_804138b0, &m.p);
  Obj *o = m.p->find(name);
  if (!o || (base && !o->isA(base))) return 0;
  return (*(Create *)(*(char **)o + 88))(o);
}
