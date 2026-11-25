// GWMP8P rev0 0x8021cd10. Front-end player list: creates the list object,
// reads the player list and the local nickname properties, then for each
// player builds an entry and a partner entry linked to each other, marks the
// entry whose nick matches the local one as first, and appends it to the
// list.
struct Obj;
struct ObjVt { void *u[3]; void (*retain)(Obj *); void (*release)(Obj *); };
struct Obj { ObjVt *vt; };
struct Slot {
 Obj *p;
 void operator=(Obj *q) { Obj *old = p; p = q; if (q) q->vt->retain(q); if (old) old->vt->release(old); }
};
struct Ref {
 Obj *p;
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->release(p); }
};
struct Entry { ObjVt *vt; char u4[20]; int index; char u28[4]; int kind; char u36[20]; Slot partner; char u60[4]; Slot player; char u68[4]; int local; void SetLocal(int v) { local = v; } void SetKind(int v) { kind = v; } };
struct View { ObjVt *vt; char u4[20]; Obj *first; };
struct Item { char u[52]; const char *nick; };
struct Key { const char *name; };
struct Page { char u[36]; Obj *list; };
extern "C" Obj *fn_8020b680(void *);
extern "C" int fn_800fc330(Key *, void **);
extern "C" int fn_800fc2b0(Key *, const char **);
extern "C" Item *fn_8021ed9c(void *, unsigned);
extern "C" unsigned fn_8021edc4(void *);
extern "C" int strcmp(const char *, const char *);
extern "C" void fn_801ef174(Obj *, int, int, Obj *);
inline Obj *Make(char *t) { return fn_8020b680(t); }
extern char lbl_8041aa48[], lbl_8041aa38[], lbl_8041aa28[];
extern char lbl_803b42c4[], lbl_803b42d4[];
extern "C" void w3d_d42k_player_list_page_8021cd10(Page *self) {
 {
  Obj *q = fn_8020b680(lbl_8041aa48);
  if (q) q->vt->retain(q);
  if (self->list) self->list->vt->release(self->list);
  self->list = q;
 }
 void *list; const char *nick;
 Key k1 = { lbl_803b42c4 };
 fn_800fc330(&k1, &list);
 Key k2 = { lbl_803b42d4 };
 fn_800fc2b0(&k2, &nick);
 void *l = list;
 for (unsigned i = 0; i < fn_8021edc4(l); i++) {
  Ref a(Make(lbl_8041aa38));
  { Entry *e = (Entry *)a.p; e->player = (Obj *)fn_8021ed9c(l, i); }
  Ref b(Make(lbl_8041aa28));
  ((Entry *)b.p)->partner = a.p;
  ((Entry *)a.p)->partner = b.p;
  ((Entry *)a.p)->index = i;
  if (!strcmp(fn_8021ed9c(l, i)->nick, nick)) {
   ((Entry *)a.p)->SetLocal(1);
   ((View *)self->list)->first = a.p;
   ((Entry *)a.p)->SetKind(16);
  }
  fn_801ef174(self->list, 20, 0, a.p);
 }
}
