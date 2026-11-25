// Material set reset (Worms 3D GameCube PAL, 0x80171624): clears flag 0x8000, and for
// each key removes the selected part from the owner's array field through
// 0x801ef380, clears both compact arrays, frees the entries' storage, empties the
// key array and releases the shared interface. Returns 0. Names are inferred.
struct Iface { virtual void a0(); virtual void add(); virtual void release(); };
template <class T> struct Ref {
  T *p;
  Ref(T *q) { p = q; if (p) p->add(); }
  Ref(const Ref &);
  ~Ref() { if (p) p->release(); }
  T *operator->() { return p; }
  void clear(T *q) { if (p) p->release(); p = q; }
};
struct List { char p0[24]; unsigned int count; char p1c[4]; Iface *data[1]; };
struct Owner : Iface { char p4[40]; List *list; };
extern "C" {
void fn_801ef380(Owner *, int, int, unsigned int, int);
Iface *w3d_s20_get_selected_80172088(void *, unsigned char);
void w3d_task_deferred_clear(void *);
void w3d_handle_storage_release(void *);
void *fn_802eee50(void *, const void *, ...);
}
struct Holder { char p0[20]; Owner *owner; };
struct Mgr { virtual void a0(); virtual void add(); virtual void release(); virtual void s20(); virtual void s24(); virtual void s28(); virtual void s32(); virtual void s36(); virtual void s40(); virtual void s44(); virtual void s48(); virtual void s52(); virtual void s56(); virtual void s60(); virtual void s64(); virtual void s68(); virtual void s72(); virtual void s76(); virtual void s80(); virtual void s84(); virtual void s88(); virtual void s92(); virtual void s96(); virtual void s100(); virtual void s104(); virtual void s108(); virtual void s112(); virtual Holder *find(unsigned char *); };
extern Mgr *lbl_804ab5fc;
struct Slot { void *data; char p4[12]; };
struct Cfg { Slot *start; Slot *finish; char p8[8]; unsigned char *ids; unsigned char *ids_end; };
struct Self { char p0[24]; int flags; char p1c[24]; char v52[12]; char v64[12]; Ref<Iface> ref76; Cfg *cfg; };
extern "C" int w3d_d40j_material_set_clear_80171624(Self *self) {
  self->flags &= ~0x8000;
  unsigned char *i = self->cfg->ids;
  if (i != self->cfg->ids_end) {
    do {
      Ref<Owner> a(lbl_804ab5fc->find(i)->owner);
      List *l = a->list;
      unsigned int n = l->count;
      Iface **d = l->data;
      {
        Ref<Iface> b(w3d_s20_get_selected_80172088(self, *i));
        unsigned int k = 0;
        for (; k < n; k++) {
          if (*(Iface **)((char *)d + (k << 2)) == b.p) {
            fn_801ef380(a.p, 44, 3, k, 1);
            break;
          }
        }
        i++;
      }
    } while (i != self->cfg->ids_end);
  }
  w3d_task_deferred_clear(self->v52);
  w3d_task_deferred_clear(self->v64);
  {
    Cfg *c = self->cfg;
    Slot *s = c->start;
    Slot *e = c->finish;
    for (Slot *p = s; p != e; p++) if (p->data) w3d_handle_storage_release(p->data);
    c->finish = s;
  }
  {
    unsigned char *&fs = self->cfg->ids;
    unsigned char *b = fs;
    unsigned char *e = (&fs)[1];
    int cnt = e - b;
    fn_802eee50(b, e, 0);
    (&fs)[1] -= cnt;
  }
  self->ref76.clear(0);
  return 0;
}
