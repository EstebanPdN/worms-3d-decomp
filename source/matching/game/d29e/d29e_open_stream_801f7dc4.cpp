// (Worms 3D GameCube PAL, 0x801f7dc4).
//
// Clears out, opens a tagged file reader for name with mode 1 (constructor
// 0x80207fec, retain 0x80207f8c, refill 0x802080a0); on success creates a
// stream object from the type at 0x80365808, adds a reference and attaches
// the reader's data word through 0x801f8754, storing the object through out
// on success and releasing it on failure. The reader's destructor 0x8020803c
// runs on every path. Returns the result. Names are inferred.

struct Iface { virtual void v0(); virtual void add(); virtual void release(); };
extern char lbl_80365808[];
extern "C" int w3d_registry_retain_80207f8c(void *);
extern "C" Iface *w3d_r24b_invoke_ready_callback_8020fcb4(void *);
extern "C" int w3d_cx14b_stream_interface_attach_801f8754(Iface *, void *);
struct Tagged {
  int w[5];
  int value;
  Tagged();
  ~Tagged();
  int refill(void *, int);
  int data() { return value; }
};
extern "C" int w3d_d29e_open_stream_801f7dc4(void *self, void *name, Iface **out) {
  *out = 0;
  Tagged t;
  w3d_registry_retain_80207f8c(&t);
  int hr = t.refill(name, 1);
  if (hr < 0) return hr;
  Iface *o = w3d_r24b_invoke_ready_callback_8020fcb4(lbl_80365808);
  o->add();
  hr = w3d_cx14b_stream_interface_attach_801f8754(o, (void *)(t.data()));
  if (hr < 0) { o->release(); return hr; }
  *out = o;
  return 0;
}
