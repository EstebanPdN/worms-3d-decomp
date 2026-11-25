// Adds a target to an animation container: optionally builds a named template
// with sub-objects, pushes them into three compact arrays, appends the item and
// updates the new target. GWMP8P rev0 0x80179b24.
extern "C" {
void *w3d_s10_service_forward_8020b680(void *);
void w3d_k5b_iface_array_field_append_801ef174(void *, int, int, void *);
void *w3d_handle_storage_allocate(unsigned int);
void w3d_handle_storage_release(void *);
void *memcpy_802eee50(void *, const void *, unsigned int, ...);
}
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
template <class T> struct Array {
  T *start, *finish, *storage_end;
  int size() const { return finish - start; }
  void grow() {
    unsigned int used = (char *)finish - (char *)start;
    int a = used + 1, b = used + (used >> 1);
    unsigned int bytes = Max(a, b) * 4;
    T *p = (T *)w3d_handle_storage_allocate(bytes);
    if (start) {
      memcpy_802eee50(p, start, Min(bytes, used));
      w3d_handle_storage_release(start);
    }
    start = p; finish = (T *)((char *)p + used); storage_end = (T *)((char *)p + bytes);
  }
  void push_back(const T &v) {
    if (finish == storage_end) grow();
    *finish = v;
    finish++;
  }
};
struct SlotsA { unsigned n; int cap; Iface **d; };
struct SlotsB { unsigned n; int cap; Iface **d; };
extern "C" void w3d_cx11b_compact_vector_grow_80210d54(SlotsA *, unsigned);
extern "C" void w3d_k5b_task_pool_reserve_801f29d0(SlotsB *, unsigned);
struct Self;
struct Item : Iface { virtual void attach(Self *); };
struct Tmpl : Iface { virtual void a3(); virtual int bind(Iface *); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void setName(const char *); virtual Iface *sub(); };
struct Mgr : Iface { virtual void a3(); virtual void a24(Iface *); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a48(Iface *); };
struct Self { char p0[104]; Array<Item *> items; char p74[4]; Iface *r120; char p7c[4]; SlotsA a; SlotsB b; SlotsB c; };
extern Mgr *lbl_804b0160;
extern "C" void d25j_update_one_target_8017a07c(Self *, int);
extern char lbl_804164c0[], lbl_804163f8[], lbl_80414a40[];
extern "C" int d31j_add_named_target_80179b24(Self *self, Item *item, const char *name) {
  if (name && *name) {
    Ref<Tmpl> t((Tmpl *)w3d_s10_service_forward_8020b680(lbl_804164c0));
    t->setName(name);
    if (t->bind(self->r120) < 0) return 0x80004005;
    Ref<Iface> u((Iface *)w3d_s10_service_forward_8020b680(lbl_804163f8));
    Ref<Iface> v((Iface *)w3d_s10_service_forward_8020b680(lbl_80414a40));
    Ref<Iface> w(t->sub());
  {
    Iface *q = u.p;
    SlotsA &sl = self->a;
    w3d_cx11b_compact_vector_grow_80210d54(&sl, self->a.n + 1);
    
    Iface *&slot = *(Iface **)(self->a.n * 4 + (int)sl.d);
    if (q) q->add();
    if (slot) slot->release();
    slot = q;
    self->a.n++;
  }
  {
    Iface *q = v.p;
    SlotsB &sl = self->b;
    w3d_k5b_task_pool_reserve_801f29d0(&sl, self->b.n + 1);
    
    Iface *&slot = *(Iface **)(self->b.n * 4 + (int)sl.d);
    if (q) q->add();
    if (slot) slot->release();
    slot = q;
    self->b.n++;
  }
  {
    Iface *q = w.p;
    SlotsB &sl = self->c;
    w3d_k5b_task_pool_reserve_801f29d0(&sl, self->c.n + 1);
    
    Iface *&slot = *(Iface **)(self->c.n * 4 + (int)sl.d);
    if (q) q->add();
    if (slot) slot->release();
    slot = q;
    self->c.n++;
  }
    w3d_k5b_iface_array_field_append_801ef174(w.p, 44, 3, v.p);
    lbl_804b0160->a48(u.p);
    lbl_804b0160->a24(self->r120);
    lbl_804b0160->a48(0);
  } else {
  {
    Iface *q = 0;
    SlotsA &sl = self->a;
    w3d_cx11b_compact_vector_grow_80210d54(&sl, self->a.n + 1);
    
    Iface *&slot = *(Iface **)(self->a.n * 4 + (int)sl.d);
    
    if (slot) slot->release();
    slot = q;
    self->a.n++;
  }
  {
    Iface *q = 0;
    SlotsB &sl = self->b;
    w3d_k5b_task_pool_reserve_801f29d0(&sl, self->b.n + 1);
    
    Iface *&slot = *(Iface **)(self->b.n * 4 + (int)sl.d);
    
    if (slot) slot->release();
    slot = q;
    self->b.n++;
  }
  {
    Iface *q = 0;
    SlotsB &sl = self->c;
    w3d_k5b_task_pool_reserve_801f29d0(&sl, self->c.n + 1);
    
    Iface *&slot = *(Iface **)(self->c.n * 4 + (int)sl.d);
    
    if (slot) slot->release();
    slot = q;
    self->c.n++;
  }
  }
  self->items.push_back(item);
  item->attach(self);
  d25j_update_one_target_8017a07c(self, self->items.size() - 1);
  return 0;
}
