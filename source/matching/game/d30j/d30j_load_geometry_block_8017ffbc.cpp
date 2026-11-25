// Load a geometry block once: read it from the buffer service into temporary
// memory, parse it through a stream into a new object, store the object under
// the name GeoMoik and keep a reference to it. GWMP8P rev0 0x8017ffbc.
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
void *tsonnet_c26_temp_alloc_801fe0b8(int);
void w3d_temporary_release(void *);
void *w3d_buffer_request_service();
int w3d_buffer_request_read(void *, void *, void *, int);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
}
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref() { p = 0; }
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  Ref &operator=(const Ref &o) { T *q = o.p; if (q) q->add(); if (p) p->release(); p = q; return *this; }
};
struct Str {
  char *p;
  Str(const char *);
  Str(const Str &);
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Stream : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual int header(void *); };
extern "C" Stream *w3d_s21_create_80208af8(void *, int);
struct Parser : Iface { virtual int read(Stream *); virtual void a4(); virtual void a5(); virtual int run(Iface **, int); };
struct Store : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual int put(void *, Iface *, const Str &); };
extern char lbl_80418de0[], lbl_8040e078[];
struct Block { char p0[20]; int size; };
struct Geo { char p0[36]; unsigned short flags; char p26[2]; Store *store; char p2c[4]; Ref<Iface> geom; char p34[4]; Block block; char p6e[32]; int loaded; };
extern "C" int d30j_load_geometry_block_8017ffbc(Geo *self) {
  if ((self->flags & 32) && self->loaded <= 0) {
    Block *b = &self->block;
    void *mem = tsonnet_c26_temp_alloc_801fe0b8(b->size);
    w3d_buffer_request_read(w3d_buffer_request_service(), b, mem, b->size);
    Ref<Stream> s(w3d_s21_create_80208af8(mem, b->size));
    char hdr[8];
    s->header(hdr);
    Ref<Parser> pr((Parser *)w3d_s10_service_forward_8020b680(lbl_80418de0));
    pr->read(s.p);
    Ref<Iface> res;
    pr->run(&res.p, 0);
    w3d_temporary_release(mem);
    Str name("GeoMoik!!!");
    self->store->put(lbl_8040e078, res.p, name);
    self->geom = res;
  }
  return 0;
}
