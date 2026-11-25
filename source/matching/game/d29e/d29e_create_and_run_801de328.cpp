// (Worms 3D GameCube PAL, 0x801de328).
//
// Creates an object through the given factory (the singleton at 0x8020b884
// when null, virtual slot 3, kind 2) into a held reference; on success finds
// the service for 0x80418f78, binds the new object to it (slot 3), runs it
// with self and 0 (slot 6), releases both references and returns the result.
// Names are inferred.

struct Iface {
  virtual void v0();
  virtual void add();
  virtual void release();
  virtual void bind(Iface *);
  virtual void v4();
  virtual void v5();
  virtual int run(void *, int);
};
struct Ref {
  Iface *p;
  Ref() : p(0) {}
  Ref(Iface *q) : p(q) { if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Iface *operator->() { return p; }
};
struct Factory {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual int create(void *, int, Ref *);
};
extern char lbl_80418f78[];
extern "C" Factory *cxc2_singleton_8020b884();
extern "C" Iface *w3d_s10_service_forward_8020b680(void *);
extern "C" int w3d_d29e_create_and_run_801de328(void *self, void *arg, Factory *factory) {
  Ref a;
  Ref *pa = &a;
  if (!factory) factory = cxc2_singleton_8020b884();
  int hr = factory->create(arg, 2, pa);
  if (hr >= 0) {
    Ref b(w3d_s10_service_forward_8020b680(lbl_80418f78));
    b->bind(a.p);
    hr = b->run(self, 0);
    // Empty statement of a compiled-out check: its loop notes pin the
    // destructor's load after the result copy.
    do { } while (0);
  }
  return hr;
}
