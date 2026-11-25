// Load the image of a resource if it is flagged as loadable: resolve the file
// through the loader service, flush its texels, optionally create a default
// texture for it, store the image on the matching map entry, and finish the
// loader. GWMP8P rev0 0x801712c4.
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
void w3d_string_base_init(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_release_header(void *);
unsigned short *w3d_string_header(void *);
void fn_802fa988(void *, unsigned int);
}
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
struct Str {
  char *p;
  Str(const char *);
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
struct Block { char p0[24]; unsigned int size; unsigned short lock; char p1e[2]; char data[1]; };
struct Image : Iface { char p4[44]; Block *block; };
struct Loader : Iface { virtual void s20(); virtual void s24(); virtual void s28(); virtual int load(char *, Ref<Image> *); virtual void s36(); virtual void s40(); virtual void s44(); virtual int done(int); };
struct RootV : Iface { virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60(); virtual void s64(); virtual void s68(); virtual void s72(); virtual void s76(); virtual void s80(); virtual void s84(); virtual void s88(); virtual Loader *loader(void *); };
extern "C" RootV *w3d_auto_8020b648();
struct Tex : Iface { virtual void s20(); virtual void set(Image *); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void setWrap(int); virtual void s60(); virtual void setMip(int); virtual void s68(); virtual void s72(); virtual void s76(); virtual void setName(const char *, int); virtual void s84(); virtual void s88(); virtual void s92(); virtual void s96(); virtual void s100(); virtual void s104(); virtual void s108(); virtual void s112(); virtual void s116(); virtual void s120(); virtual void s124(); virtual void s128(); virtual void s132(); virtual void s136(); virtual void s140(); virtual void setFilter(int); };
struct Item { char p0[60]; Ref<Image> image; };
struct Holder { char p0[20]; Str name; char p18[4]; Block *block; };
extern "C" Item **w3d_auto_801d0858(Holder *, int *);
struct Self { char p0[20]; Str name; int flags; char p1c[4]; const char *file; char p24[14]; unsigned short state; char p34[24]; Holder *holder; };
extern char lbl_804143e0[], lbl_80413db0[];
extern const char lbl_803a6648[];
static inline Loader *get_loader(void *type) { return w3d_auto_8020b648()->loader(type); }
extern "C" int d30j_load_image_resource_801712c4(Self *self, const char *name) {
  if (!(self->flags & 0x8000)) return 0x80004005;
  Loader *ld = get_loader(lbl_804143e0);
  Ref<Image> img;
  Str path(name);
  { Holder *h = self->holder; h->name = Str(self->file); }
  self->holder->block->lock++;
  if (ld->load(path.p, &img) < 0) {
    use(path), use(self->name);
    return 0x80004005;
  }
  if (!(self->state & 256)) {
    Ref<Tex> t((Tex *)w3d_s10_service_forward_8020b680(lbl_80413db0));
    t->setWrap(4);
    t->setFilter(0);
    t->setMip(1);
    t->setName(lbl_803a6648, 5);
    t->set(img.p);
    Block *b = img->block;
    fn_802fa988(b->data, b->size);
  }
  int found;
  Item **e = w3d_auto_801d0858(self->holder, &found);
  Item *it = found ? *e : 0;
  it->image = img;
  ld->done(0);
  return 0;
}
