#include "w3d_ptr.h"
#line 1 "d42k_player_list_page_8021cd10.cpp"
// GWMP8P rev0 0x8021cd10. Front-end player list: creates the list object,
// reads the player list and the local nickname properties, then for each
// player builds an entry and a partner entry linked to each other, marks the
// entry whose nick matches the local one as first, and appends it to the
// list.
struct Obj;
struct ObjVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Obj>)> retain; Ptr32<void (Ptr32<Obj>)> release; };
struct Obj { Ptr32<ObjVt> vt; };
struct Slot {
 Ptr32<Obj> p;
 template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *q) { Ptr32<Obj> old = p; p = q; if (q) q->vt->retain(q); if (old) old->vt->release(old); }
};
struct Ref {
 Ptr32<Obj> p;
 template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *o) : p(o) { if (o) o->vt->retain(o); }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->release(p); }
};
struct Entry { Ptr32<ObjVt> vt; char u4[20]; int index; char u28[4]; int kind; char u36[20]; Slot partner; char u60[4]; Slot player; char u68[4]; int local; void SetLocal(int v) { local = v; } void SetKind(int v) { kind = v; } };
struct View { Ptr32<ObjVt> vt; char u4[20]; Ptr32<Obj> first; };
struct Item { char u[52]; Ptr32<const char> nick; };
struct Key { Ptr32<const char> name; };
struct Page { char u[36]; Ptr32<Obj> list; };
extern "C" Ptr32<Obj> fn_8020b680(Ptr32<void>);
extern "C" int fn_800fc330(Ptr32<Key>, Ptr32<Ptr32<void>>);
extern "C" int fn_800fc2b0(Ptr32<Key>, Ptr32<Ptr32<const char>>);
extern "C" Ptr32<Item> fn_8021ed9c(Ptr32<void>, unsigned);
extern "C" unsigned fn_8021edc4(Ptr32<void>);
extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" void fn_801ef174(Ptr32<Obj>, int, int, Ptr32<Obj>);
inline Ptr32<Obj> Make(Ptr32<char> t) { return fn_8020b680(t); }
extern char lbl_8041aa48[], lbl_8041aa38[], lbl_8041aa28[];
extern char lbl_803b42c4[], lbl_803b42d4[];
extern "C" void w3d_d42k_player_list_page_8021cd10(Ptr32<Page> self) {
 {
  Ptr32<Obj> q = fn_8020b680(lbl_8041aa48);
  if (q) q->vt->retain(q);
  if (self->list) self->list->vt->release(self->list);
  self->list = q;
 }
 Ptr32<void> list; Ptr32<const char> nick;
 Key k1 = { lbl_803b42c4 };
 fn_800fc330(&k1, &list);
 Key k2 = { lbl_803b42d4 };
 fn_800fc2b0(&k2, &nick);
 Ptr32<void> l = list;
 for (unsigned i = 0; i < fn_8021edc4(l); i++) {
  Ref a(Make(lbl_8041aa38));
  { Ptr32<Entry> e = (Ptr32<Entry>)a.p; e->player = (Ptr32<Obj>)fn_8021ed9c(l, i); }
  Ref b(Make(lbl_8041aa28));
  ((Ptr32<Entry>)b.p)->partner = a.p;
  ((Ptr32<Entry>)a.p)->partner = b.p;
  ((Ptr32<Entry>)a.p)->index = i;
  if (!strcmp(fn_8021ed9c(l, i)->nick, nick)) {
   ((Ptr32<Entry>)a.p)->SetLocal(1);
   ((Ptr32<View>)self->list)->first = a.p;
   ((Ptr32<Entry>)a.p)->SetKind(16);
  }
  fn_801ef174(self->list, 20, 0, a.p);
 }
}


