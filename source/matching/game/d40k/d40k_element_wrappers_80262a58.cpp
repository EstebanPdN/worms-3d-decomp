struct Str_803426b8;
typedef Str_803426b8 Str;
extern "C" void fn_8020c5c4(void *), fn_80341588(void *), fn_8020c5c0(void *);
struct Header { unsigned short refs, length, capacity; };
extern "C" Header *fn_80341884(void *);
struct Str_803426b8 {
 char *p;
 Str_803426b8();
 Str_803426b8(const Str_803426b8 &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
 unsigned short len() const { return ((Header *)(p - 6))->length; }
};
struct Type { char u0[20]; Type *parent; };
struct Obj;
struct ObjVt { char u0[12]; void (*add)(Obj *); void (*rel)(Obj *); Type *(*type)(Obj *); char u24[8]; void (*fail)(Obj *); };
struct Obj { ObjVt *vt; };
struct Wrap : Obj { char u4[24]; void *attr; char u32[8]; Obj *elem; };
struct Key { char *name; };
struct Ref { Wrap *p; Ref(Wrap *q) : p(q) { if (p) p->vt->add(p); } Ref(const Ref &); ~Ref() { if (p) p->vt->rel(p); } };
struct Items { char u0[24]; unsigned count; char u28[4]; Obj *v[1]; };
struct Source { char u0[20]; Items *items; void *attr; char u28[12]; const char *text; };
struct Self { char u0[20]; int f20; char u24[4]; Obj *f28; void *f32; char u36[148]; void *names; };
extern "C" {
int fn_800c4d9c(void *, Str *);
int fn_800fc1b0(Key *, Obj **);
int fn_801790bc(void *, const char *);
void *fn_80341584(Obj *);
Source *fn_801797b4(void *);
void fn_802b1258(void *);
Wrap *fn_8020b680(const void *);
void fn_802b1250(void *, void *);
int fn_80164514(void *, Wrap *, int);
void *fn_801613f0(void *, int);
short fn_8015f5a0(struct IdCache *, int);
void *fn_8010a8e0(void *, unsigned short, const char *);
int fn_8016239c(void *);
}
extern void *lbl_804abb5c, *lbl_804b178c, *lbl_804b1754;
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
inline bool IsOf(Obj *o, Type *want) {
 Type *t = o->vt->type(o);
 while (t != want) {
  Type *up = t->parent;
  if (t == up) return false;
  t = up;
 }
 return true;
}
template <Type *want> inline bool IsA(Obj *o) {
 Type *t = o->vt->type(o);
 while (t != want) {
  Type *up = t->parent;
  if (t == up) return false;
  t = up;
 }
 return true;
}
inline void Bind(Wrap *w, Obj *e) {
 if (e) e->vt->add(e);
 if (w->elem) w->elem->vt->rel(w->elem);
 w->elem = e;
}
inline void Add1(const Ref &w, Obj *const &e, Self *self) {
 fn_802b1250(&w.p->attr, lbl_804abb5c);
 Bind(w.p, e);
 fn_80164514(lbl_804b178c, w.p, self->f20);
}
inline void Add2(const Ref &w, Obj *const &e, Self *self) {
 Bind(w.p, e);
 fn_802b1250(&w.p->attr, lbl_804abb5c);
 fn_80164514(lbl_804b178c, w.p, self->f20);
}
extern "C" void w3d_d40k_element_wrappers_80262a58(Self *self) {
 Str name;
 fn_800c4d9c(self->names, &name);
 Key key;
 if (name.len() == 0 || (key.name = name.p, fn_800fc1b0(&key, &self->f28) < 0)) {
  fn_801790bc(self->f32, lbl_803cac08);
  return;
 }
 (void)Str(name);
 Source *src = fn_801797b4(fn_80341584(self->f28));
 Items *items = src->items;
 unsigned n = items->count;
 Obj **v = items->v;
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
 void *m = fn_801613f0(lbl_804b1754, 12);
 unsigned short id = fn_8015f5a0(&lbl_804b0974, 1);
 fn_8016239c(fn_8010a8e0(m, id, src->text));
}
