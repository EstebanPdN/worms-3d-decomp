// (Worms 3D GameCube PAL, 0x8020b6e8).
//
// Opens a tagged file reader for name with mode 1, tracing the failure
// unless the flag at 0x804b069c is set; on success gets the services for
// 0x80419848 and 0x80418de0, assigns the reader's data word to the first
// (0x802199c0), binds it to the second (slot 3), runs the second with arg
// (slot 6), traces a negative result, releases both and destroys the reader.
// Returns the result. Names are inferred.

struct Iface {
  virtual void v0(); virtual void add(); virtual void release();
  virtual void bind(Iface *);
  virtual void v4(); virtual void v5();
  virtual int run(void *, int);
};
extern char lbl_80419848[], lbl_80418de0[];
extern const char lbl_803b3104[], lbl_803b3130[];
extern int lbl_804b069c;
extern int lbl_804b0640;
extern "C" void w3d_trace_stub_80347324(int *, const char *, ...);
extern "C" Iface *w3d_s10_service_forward_8020b680(void *);
extern "C" void w3d_s10_assign_interface_802199c0(Iface *, void *);
struct Ref {
  Iface *p;
  Ref(Iface *q) : p(q) { if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  Iface *operator->() { return p; }
};
struct Tagged {
  int w[5];
  int value;
  Tagged();
  ~Tagged();
  int refill(void *, int);
  int data() { return value; }
};
extern "C" int w3d_d29e_run_file_8020b6e8(void *name, void *arg) {
  Tagged t;
  int hr = t.refill(name, 1);
  if (hr < 0) {
    if (lbl_804b069c == 0) w3d_trace_stub_80347324(&lbl_804b0640, lbl_803b3104, name);
    return hr;
  }
  Ref a(w3d_s10_service_forward_8020b680(lbl_80419848));
  Ref b(w3d_s10_service_forward_8020b680(lbl_80418de0));
  w3d_s10_assign_interface_802199c0(a.p, (void *)(t.data()));
  b->bind(a.p);
  hr = b->run(arg, 0);
  if (hr < 0) w3d_trace_stub_80347324(&lbl_804b0640, lbl_803b3130, name);
  return hr;
}
