// Insert an object into the pool manager's 1920-slot open-addressing table: hash
// its name, probe linearly, note whether an entry of the same name was seen,
// keep the longest and total probe counts, and hold a reference in the free
// slot. GWMP8P rev0 0x8017c464.
extern "C" {
void w3d_string_base_init(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
unsigned short *w3d_string_header(void *);
int strcmp(const char *, const char *);
}
struct Str {
  char *p;
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
};
inline void use(Str) {}
struct Item {
  virtual void a0(); virtual void add(); virtual void release();
  virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13(); virtual void a14();
  virtual const Str &text();
};
struct Ref {
  Item *p;
  Item *get() { return p; }
  void set(Item *q) { if (q) q->add(); if (p) p->release(); p = q; }
};
struct Cell { char p0[24]; Ref r; };
struct Table { char p0[24]; Ref slots[1920]; 
  char names[8 * 256]; int count; };
extern "C" unsigned int w3d_k1d_hash_name_8017e1c4(Table *, const char *);
extern unsigned int lbl_804ab5e4, lbl_804ab5ec, lbl_804ab5f0;
template <class T> inline const T &mx(const T &a, const T &b) { return a < b ? b : a; }
#define SLOT(i) (self->slots[i])
extern "C" bool d30j_insert_pool_item_8017c464(Table *self, Item *item) {
  bool found = false;
  unsigned int h = w3d_k1d_hash_name_8017e1c4(self, item->text().p);
  if (SLOT(h).get() == 0) {
    SLOT(h).set(item);
    self->count++;
  } else {
    const Str &a = item->text();
    const Str &a2 = SLOT(h).get()->text();
    if (strcmp(a.p, a2.p) == 0) {
      found = true;
      use(item->text());
    }
    unsigned int probe = 1;
    lbl_804ab5e4++;
    while (SLOT((h + probe) % 1920).get()) {
      const Str &b = item->text();
      const Str &b2 = SLOT((h + probe) % 1920).get()->text();
      if (strcmp(b.p, b2.p) == 0) {
        found = true;
        use(item->text());
      }
      probe++;
    }
    lbl_804ab5ec = mx(lbl_804ab5ec, probe);
    lbl_804ab5f0 += probe;
    SLOT((h + probe) % 1920).set(item);
    self->count++;
  }
  return !found;
}
