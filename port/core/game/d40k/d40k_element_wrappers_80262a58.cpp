#include "w3d_ptr.h"
#line 1 "d40k_element_wrappers_80262a58.cpp"
struct Str_803426b8;
typedef Str_803426b8 Str;
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str_803426b8 {
 Ptr32<char> p;
 Str_803426b8();
 Str_803426b8(const Str_803426b8 &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
 unsigned short len() const { return ((Ptr32<Header>)(p - 6))->length; }
};
struct Type { char u0[20]; Ptr32<Type> parent; };
struct Obj;
struct ObjVt { char u0[12]; Ptr32<void (Ptr32<Obj>)> add; Ptr32<void (Ptr32<Obj>)> rel; Ptr32<Ptr32<Type> (Ptr32<Obj>)> type; char u24[8]; Ptr32<void (Ptr32<Obj>)> fail; };
struct Obj { Ptr32<ObjVt> vt; };
struct Wrap : Obj { char u4[24] __attribute__((aligned(__alignof__(Obj)))); Ptr32<void> attr; char u32[8]; Ptr32<Obj> elem; };
struct Key { Ptr32<char> name; };
struct Ref { Ptr32<Wrap> p; template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Wrap *)w3d_p.get()) {}
 Ref(Wrap *q) : p(q) { if (p) p->vt->add(p); } Ref(const Ref &); ~Ref() { if (p) p->vt->rel(p); } };
struct Items { char u0[24]; unsigned count; char u28[4]; Ptr32<Obj> v[1]; };
struct Source { char u0[20]; Ptr32<Items> items; Ptr32<void> attr; char u28[12]; Ptr32<const char> text; };
struct Self { char u0[20]; int f20; char u24[4]; Ptr32<Obj> f28; Ptr32<void> f32; char u36[148]; Ptr32<void> names; };
extern "C" {
int fn_800c4d9c(Ptr32<void>, Ptr32<Str>);
int fn_800fc1b0(Ptr32<Key>, Ptr32<Ptr32<Obj>>);
int fn_801790bc(Ptr32<void>, Ptr32<const char>);
Ptr32<void> fn_80341584(Ptr32<Obj>);
Ptr32<Source> fn_801797b4(Ptr32<void>);
void fn_802b1258(Ptr32<void>);
Ptr32<Wrap> fn_8020b680(Ptr32<const void>);
void fn_802b1250(Ptr32<void>, Ptr32<void>);
int fn_80164514(Ptr32<void>, Ptr32<Wrap>, int);
Ptr32<void> fn_801613f0(Ptr32<void>, int);
short fn_8015f5a0(Ptr32<struct IdCache>, int);
Ptr32<void> fn_8010a8e0(Ptr32<void>, unsigned short, Ptr32<const char>);
int fn_8016239c(Ptr32<void>);
}
extern Ptr32<void> lbl_804abb5c; extern Ptr32<void> lbl_804b178c; extern Ptr32<void> lbl_804b1754;
struct IdCache { short id; };
extern IdCache lbl_804b0974;
extern char lbl_803cac08[];
extern Type type_80365b78[];
extern Type type_80366028[];
extern Type type_80365b28[];
extern Type type_80365bc8[];
extern Type type_80365c18[];
extern Type type_80365c68[];
extern Type type_80365d58[];
extern Type type_80365fd8[];
extern Type type_80365da8[];
extern Type type_80365e48[];
extern Type type_80365e98[];
extern Type type_80365cb8[];
extern Type type_80365f38[];
extern Type type_80365df8[];
extern Type type_80365ee8[];
extern Type type_80366078[];
extern Type type_80365f88[];
extern Type type_80365d08[];
extern const char class_8041c080[];
extern const char class_8041c6a0[];
extern const char class_8041bb20[];
extern const char class_8041c110[];
extern const char class_8041c3d0[];
extern const char class_8041c580[];
extern const char class_8041bf30[];
extern const char class_8041c338[];
extern const char class_8041c2a0[];
extern const char class_8041bd50[];
extern const char class_8041c730[];
extern const char class_8041c4f0[];
extern const char class_8041c460[];
extern const char class_8041c7c0[];
extern const char class_8041bc80[];
extern const char class_8041bde0[];
extern const char class_8041bbf0[];
inline bool IsOf(Ptr32<Obj> o, Ptr32<Type> want) {
 Ptr32<Type> t = o->vt->type(o);
 while (t != want) {
  Ptr32<Type> up = t->parent;
  if (t == up) return false;
  t = up;
 }
 return true;
}
template <Type *want> inline bool IsA(Ptr32<Obj> o) {
 Ptr32<Type> t = o->vt->type(o);
 while (t != want) {
  Ptr32<Type> up = t->parent;
  if (t == up) return false;
  t = up;
 }
 return true;
}
inline void Bind(Ptr32<Wrap> w, Ptr32<Obj> e) {
 if (e) e->vt->add(e);
 if (w->elem) w->elem->vt->rel(w->elem);
 w->elem = e;
}
inline void Add1(const Ref &w, Ptr32<Obj> const &e, Ptr32<Self> self) {
 fn_802b1250(&w.p->attr, lbl_804abb5c);
 Bind(w.p, e);
 fn_80164514(lbl_804b178c, w.p, self->f20);
}
inline void Add2(const Ref &w, Ptr32<Obj> const &e, Ptr32<Self> self) {
 Bind(w.p, e);
 fn_802b1250(&w.p->attr, lbl_804abb5c);
 fn_80164514(lbl_804b178c, w.p, self->f20);
}
extern "C" void w3d_fe_building_menu(const char *name);
extern "C" void w3d_d40k_element_wrappers_80262a58(Ptr32<Self> self) {
 Str name;
 fn_800c4d9c(self->names, &name);
 Key key;
 if (name.len() == 0 || (key.name = name.p, fn_800fc1b0(&key, &self->f28) < 0)) {
  fn_801790bc(self->f32, lbl_803cac08);
  return;
 }
 // The native queue can create menus without posting FE.ChangeMenu.
 // Record the actual table before any control is constructed.
 w3d_fe_building_menu(name.p.get());
 (void)Str(name);
 Ptr32<Source> src = fn_801797b4(fn_80341584(self->f28));
 Ptr32<Items> items = src->items;
 unsigned n = items->count;
 Ptr32<Ptr32<Obj>> v = items->v;
 fn_802b1258(src->attr);
 for (unsigned i = 0; i < n; i++) {
  if (IsOf(v[i], type_80365b78)) Add1(Ref(fn_8020b680(class_8041c080)), v[i], self);
  else if (IsA<type_80366028>(v[i])) Add1(Ref(fn_8020b680(class_8041c6a0)), v[i], self);
  else if (IsA<type_80365b28>(v[i])) Add1(Ref(fn_8020b680(class_8041bb20)), v[i], self);
  else if (IsA<type_80365bc8>(v[i])) Add1(Ref(fn_8020b680(class_8041c110)), v[i], self);
  else if (IsA<type_80365c18>(v[i])) Add1(Ref(fn_8020b680(class_8041c3d0)), v[i], self);
  else if (IsA<type_80365c68>(v[i])) Add1(Ref(fn_8020b680(class_8041c580)), v[i], self);
  else if (IsA<type_80365d58>(v[i])) Add1(Ref(fn_8020b680(class_8041bf30)), v[i], self);
  else if (IsA<type_80365d08>(v[i])) { }
  else if (IsA<type_80365fd8>(v[i])) Add2(Ref(fn_8020b680(class_8041c338)), v[i], self);
  else if (IsA<type_80365da8>(v[i])) Add2(Ref(fn_8020b680(class_8041c2a0)), v[i], self);
  else if (IsA<type_80365e48>(v[i])) Add2(Ref(fn_8020b680(class_8041bd50)), v[i], self);
  else if (IsA<type_80365e98>(v[i])) Add2(Ref(fn_8020b680(class_8041c730)), v[i], self);
  else if (IsA<type_80365cb8>(v[i])) Add2(Ref(fn_8020b680(class_8041c4f0)), v[i], self);
  else if (IsA<type_80365f38>(v[i])) Add2(Ref(fn_8020b680(class_8041c460)), v[i], self);
  else if (IsA<type_80365df8>(v[i])) Add2(Ref(fn_8020b680(class_8041c7c0)), v[i], self);
  else if (IsA<type_80365ee8>(v[i])) Add2(Ref(fn_8020b680(class_8041bc80)), v[i], self);
  else if (IsA<type_80366078>(v[i])) Add2(Ref(fn_8020b680(class_8041bde0)), v[i], self);
  else if (IsA<type_80365f88>(v[i])) Add2(Ref(fn_8020b680(class_8041bbf0)), v[i], self);
 else self->f28->vt->fail(self->f28);
 }
 if (lbl_804abb5c == 0) fn_801790bc(self->f32, name.p);
 Ptr32<void> m = fn_801613f0(lbl_804b1754, 12);
 unsigned short id = fn_8015f5a0(&lbl_804b0974, 1);
 fn_8016239c(fn_8010a8e0(m, id, src->text));
}


