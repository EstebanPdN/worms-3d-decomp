// GWMP8P rev0 0x80182e74. Sets up an instance object: base init, service-
// fetched instance and texture, a name built from 'Instance-' and the item's
// text, default colour vectors, stored item, registry append. Names are
// inferred from use.
struct Src;
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
int w3d_auto_80179aec(void *, void *, unsigned char);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
void w3d_string_release_header(void *);
void *w3d_empty_8034cc30(void *);
struct Geo;
Geo *w3d_s21_fetch_801ea470(void *);
void w3d_k5b_iface_array_field_append_801ef174(void *, int, int, void *);
}
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref() { p = 0; }
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  Ref &operator=(T *q) { if (q) q->add(); if (p) p->release(); p = q; return *this; }
  Ref &operator=(const Ref &o) { T *old = p; p = o.p; if (p) p->add(); if (old) old->release(); return *this; }
};
struct String_8020bb54 {
  char *p;
  String_8020bb54(const char *);
  String_8020bb54(const String_8020bb54 &);
  ~String_8020bb54() { w3d_string_base_finish(this); w3d_string_release(this); }
  String_8020bb54 &operator=(const String_8020bb54 &o) {
    ++*(unsigned short *)(o.p - 6);
    unsigned short *h = (unsigned short *)(p - 6);
    if (--*h == 0) w3d_string_release_header(h);
    p = o.p;
    return *this;
  }
};
struct Vec { float x, y, z; void set(float f) { x = f; y = f; z = f; } };
struct Bits { char p0[7]; unsigned char flags; void mark() { flags |= 2; } };
struct Tex : Iface {
  Bits bits; char pc[60];
  Vec a; Vec b; Vec c;
  void setA(const Vec &v) { a = v; bits.mark(); }
  void setB(const Vec &v) { b = v; bits.mark(); }
  void setC(const Vec &v) { c = v; bits.mark(); }
};
struct Inst : Iface { char p4[32]; String_8020bb54 name; char p28[8]; Ref<Tex> tex; };
struct Item : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual const String_8020bb54 &text(); };
struct Holder { char p0[20]; Iface *value; };
struct Reg : Iface { virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15(); virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19(); virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23(); virtual void a24(); virtual void a25(); virtual void a26(); virtual Holder *find(unsigned char *); };
extern Reg *lbl_804ab5fc;
extern int lbl_804ab650;
extern char lbl_804144f8[], lbl_80414940[], lbl_80414600[];
extern "C" void *fn_802eee50(void *, const void *, ...);
struct Blob { char p0[4]; unsigned short kind; char p6[18]; int count; unsigned short locks; char p1e[2]; char data[1]; };
struct Handle;
extern "C" void *w3d_k5b_array_ref_lock_801ef048(Handle *, int, int, int);
struct Handle {
  Blob *b;
  void *lock(int count, int stride, unsigned fl) {
    Blob *x = b;
    unsigned flags = fl; int size; if (flags & 2) size = x->count + count; else size = count;
    if (x->kind == 1 && size == x->count) { x->locks++; return x->data; }
    return w3d_k5b_array_ref_lock_801ef048(this, size, stride, flags);
  }
};
struct Geo;
struct Src { char p0[44]; Geo *shape; };
struct Mod : Iface { char p4[80]; unsigned char blend; };
struct Geo : Iface { char p4[32]; Handle uv; Handle st; char p2c[4]; Ref<Iface> sp; Ref<Geo> next; };
struct Clr { char *a; char *b; };
struct Self {
  void *vt; int p4; int flags; Vec c; Vec b; Vec a; int p30; char p34[64]; Ref<Iface> item; Ref<Inst> inst; char p7c[44]; int on; int count;
};
extern "C" int w3d_d43n_instance_object_setup_80182e74(Self *self, Item *item, unsigned char kind) {
  int hr = w3d_auto_80179aec(self, item, kind);
  if (hr < 0) return hr;
  self->inst = (Inst *)w3d_s10_service_forward_8020b680(lbl_804144f8);
  Ref<Tex> tex((Tex *)w3d_s10_service_forward_8020b680(lbl_80414940));
  int one = 1;
  char name[256];
  strcpy(name, "Instance-");
  strcat(name, item->text().p);
  self->inst->name = String_8020bb54(name);
  self->a.set(1.0f);
  self->c.set(0.0f);
  self->b.set(0.0f);
  tex->setA(self->a);
  tex->setC(self->c);
  tex->setB(self->b);
  self->inst->tex = tex;
  self->item = item;
  w3d_empty_8034cc30(item);
  {
    Ref<Iface> reg(lbl_804ab5fc->find(&kind)->value);
    w3d_k5b_iface_array_field_append_801ef174(reg.p, 44, 3, self->inst.p);
    self->flags |= 1;
    self->p30 = 0;
    self->on = one;
    self->count = 0;
    lbl_804ab650++;
  }
  return 0;
}
