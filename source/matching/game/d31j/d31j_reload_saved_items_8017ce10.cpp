// Reloads saved items from the kind's file: for each stored item finds the
// matching entry, checks kind and flags and replaces it. GWMP8P rev0 0x8017ce10.
extern "C" {
void * w3d_string_default(void *);
void w3d_string_format(void *, const char *, ...);
void w3d_string_base_init(void *);
unsigned short *w3d_string_header(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
int w3d_constant_8020b5c8(int);
void w3d_empty_8020b5d0();
}
struct Iface { virtual int query(void *, void *); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref() { p = 0; }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  Ref &operator=(const Ref &o) { if (o.p) o.p->add(); if (p) p->release(); p = o.p; return *this; }
};
struct Str {
  char *p;
  Str() {}
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
};
inline void use(Str) {}
struct Info { char p0[16]; };
struct Node : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual int commit(Node *); virtual int size36(); virtual void a8(); virtual void a9(); virtual int v48(); virtual void a11(); virtual void a12(); virtual void a13(); virtual int v64(); virtual const Str &name(); virtual unsigned char *kind(); virtual void a15(); virtual int v80(); };
struct Item : Node {};
struct Src : Node { };
struct Holder : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual unsigned count(); virtual void at(unsigned, Info *, Ref<Iface> *, int); };
struct Self;
struct Entry { char p0[24]; Ref<Node> r; };
struct Self { char p0[9804]; void (*progress)(unsigned, unsigned); char p2650[16]; const char *fmt; };
extern "C" int d24j_find_named_item_8017e22c(Self *, const Str &, unsigned short *);
extern "C" int w3d_d29e_run_file_8020b6e8(const char *, Ref<Iface> *);
extern int lbl_804a8dd8[];
extern char lbl_8040e058[], lbl_8040ca90[];
extern "C" int d31j_reload_saved_items_8017ce10(Self *self, unsigned char *kind) {
  Ref<Iface> file;
  Str path;
  Str *pp = &path;
  w3d_string_default(pp);
  w3d_string_format(pp, self->fmt, *kind);
  int hr = w3d_d29e_run_file_8020b6e8(path.p, &file);
  if (hr >= 0) {
  Ref<Holder> h;
  hr = file->query(lbl_8040e058, &h);
  if (hr < 0) return hr;
  unsigned n = h->count();
  for (unsigned i = 0; i < n; i++) {
    Info info;
    Ref<Iface> a;
    h->at(i, &info, &a, 0);
    Ref<Node> b;
    a->query(lbl_8040ca90, &b);
    unsigned short idx;
    if (d24j_find_named_item_8017e22c(self, b->name(), &idx) < 0) {
      hr = 0x80004005;
      use(b->name());
    } else {
      int flags = 0;
      Node *item = ((Entry *)(idx * 4 + (int)self))->r.p;
      if (*item->kind() != *kind) flags = 1;
      if (item->size36() != b->size36()) flags |= 2;
      if (item->v64()) flags |= 4;
      if (item->v80()) flags |= 8;
      if (flags == 0) {
        w3d_constant_8020b5c8(-1);
        int r = b->commit(item);
        if (r < 0) hr = r;
        r = b->v48();
        if (r < 0) hr = r;
        ((Entry *)(idx * 4 + (int)self))->r = b;
        w3d_empty_8020b5d0();
      } else {
        hr = 0x80004005;
        use(b->name()), use(path);
      }
    }
    if (self->progress) self->progress(i, n);
  }
  } else {
    lbl_804a8dd8[*kind] = 0;
  }
  return hr;
}
