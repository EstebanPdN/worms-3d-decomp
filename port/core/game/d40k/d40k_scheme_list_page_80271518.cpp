#include "w3d_ptr.h"
#line 1 "d40k_scheme_list_page_80271518.cpp"
// GWMP8P rev0 0x80271518. Writes one page of the scheme list as text:
// collects the matching property objects and their names, builds a heading,
// prints up to twenty indexed lines and sends the text to the sink. Names
// are inferred from use; Menu and its members are partial views.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Str_803426b8;
typedef Str_803426b8 Str;
extern "C" void fn_8020c5c4(Ptr32<void>), fn_80341588(Ptr32<void>), fn_8020c5c0(Ptr32<void>), fn_8020bb2c(Ptr32<void>);
struct Header { unsigned short refs, length, capacity; };
extern "C" Ptr32<Header> fn_80341884(Ptr32<void>);
struct Str_803426b8 {
 Ptr32<char> p;
 Str_803426b8();
 template <class W3dU> Str_803426b8(Ptr32<W3dU> w3d_p) : Str_803426b8((const char *)w3d_p.get()) {}
 Str_803426b8(const char *);
 Str_803426b8(const Str_803426b8 &o) { fn_8020c5c0(this); p = o.p; ++fn_80341884(this)->refs; }
 ~Str_803426b8() { fn_8020c5c4(this); fn_80341588(this); }
 unsigned short len() const { return ((Ptr32<Header>)(p - 6))->length; }
 Str_803426b8 &operator=(const Str_803426b8 &o) {
  ++((Ptr32<Header>)(o.p - 6))->refs;
  Ptr32<Header> h = (Ptr32<Header>)(p - 6);
  if (--h->refs == 0) fn_8020bb2c(h);
  p = o.p;
  return *this;
 }
};
struct Type { char u0[20]; Ptr32<Type> parent; };
struct Obj;
struct ObjVt { char u0[12]; Ptr32<void (Ptr32<Obj>)> add; Ptr32<void (Ptr32<Obj>)> rel; Ptr32<Ptr32<Type> (Ptr32<Obj>)> type; Ptr32<int (Ptr32<Obj>)> kind; char u28[4]; Ptr32<Ptr32<const char> (Ptr32<Obj>)> name; };
struct Obj { Ptr32<ObjVt> vt; };
struct Ref {
 Ptr32<Obj> p;
 Ref() : p(0) {}
 template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Obj *)w3d_p.get()) {}
 Ref(Obj *n) : p(n) { if (p) p->vt->add(p); }
 Ref(const Ref &);
 ~Ref() { if (p) p->vt->rel(p); }
 Ref &operator=(const Ref &o) { Ptr32<Obj> n = o.p; if (n) { n->vt->add(n); if (p) p->vt->rel(p); p = n; } return *this; }
};
struct Descriptor_80178474 {
 Ptr32<void> value; unsigned tag;
 Descriptor_80178474() : value(0), tag(58280) {}
 ~Descriptor_80178474();
};
struct Item { char u0[28]; Ptr32<const char> label; };
struct Held { Ptr32<Obj> p; template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 void operator=(Obj *n) { if (p) p->vt->rel(p); p = n; } };
struct List;
extern "C" void fn_80210d54(Ptr32<List>, int);
struct List {
 int count; int cap; Ptr32<Ptr32<Obj>> data;
 Ptr32<Obj> At(int i) { return data[i]; }
 void Push(Ptr32<Obj> n) {
  fn_80210d54(this, count + 1);
  Ptr32<Ptr32<Obj>> d = data; int k = count << 2;
  if (n) n->vt->add(n);
  Ptr32<Ptr32<Obj>> slot = (Ptr32<Ptr32<Obj>>)w3d::G((k + (int)w3d::H(d)));
  if (*slot) (*slot)->vt->rel(*slot);
  *slot = n;
  count++;
 }
};
struct Menu { char u0[32]; Ptr32<void> sink; int f36; char u40[12]; List items; _STL::vector<Str> names; int page; int f84; Held f88; Held f92; };
extern "C" {
void fn_8027a934(Ptr32<Menu>, int);
void fn_802cd220(Ptr32<Str>);
int fn_802cd128(Ptr32<Str>);
int fn_800fc668();
void fn_80210afc(Ptr32<List>);
int fn_800fc69c(Ptr32<Ptr32<const char>>, Ptr32<Ref>);
Ptr32<void> fn_80341584(Ptr32<Obj>);
Ptr32<Obj> fn_801797b4(Ptr32<void>);
Ptr32<Obj> fn_80179598(Ptr32<void>, Ptr32<Descriptor_80178474>);
Ptr32<void> fn_8020bf2c(Ptr32<Str>, Ptr32<const char>);
void fn_8020c510(Ptr32<Str>, Ptr32<const char>, ...);
void fn_802cbf2c(Ptr32<Str>, Ptr32<const char>, int);
void fn_802cc0ac(Ptr32<Str>, Ptr32<const char>, int);
void fn_802cd26c(Ptr32<Str>, int, int);
void fn_802cbdf8(int, Ptr32<char>, int);
}
extern char lbl_803cc4f8[], lbl_803cc50c[], lbl_803cc510[], lbl_803cc514[], lbl_803cc524[], lbl_803cc528[], lbl_803cc534[], lbl_803cc57c[];
extern Type lbl_80366118[];
extern Ptr32<const char> lbl_804abba0;
extern Str lbl_804b06a0[];
inline bool IsKind(Ptr32<Type> t, Ptr32<Type> c) {
 while (t != c) {
  Ptr32<Type> n = t->parent;
  if (t == n) return false;
  t = n;
 }
 return true;
}
inline const unsigned &Min(const unsigned &a, const unsigned &b) { return b < a ? b : a; }
extern "C" void w3d_d40k_scheme_list_page_80271518(Ptr32<Menu> self, Ptr32<const char> title) {
 fn_8027a934(self, 1);
 Str text;
 fn_802cd220(&text);
 fn_802cd128(&text);
 self->f84 = 0;
 self->f36 = 1;
 fn_800fc668();
 Ptr32<const char> key = 0;
 Ref cur;
 fn_80210afc(&self->items);
 self->names.clear();
 while (fn_800fc69c(&key, &cur)) {
  if (cur.p->vt->kind(cur.p) != 5) continue;
  Ptr32<Obj> o = fn_801797b4(fn_80341584(cur.p));
  if (!IsKind(o->vt->type(o), lbl_80366118)) continue;
  Descriptor_80178474 d;
  Ref h;
  h = Ref(fn_80179598(fn_80341584(cur.p), &d));
  self->items.Push(h.p);
  self->names.push_back(Str(cur.p->vt->name(cur.p)));
 }
 Str hdr(lbl_803cc4f8);
 if (title) {
  fn_8020bf2c(&hdr, lbl_803cc50c);
  fn_8020bf2c(&hdr, title);
  fn_8020bf2c(&hdr, lbl_803cc510);
 } else {
  Str p;
  fn_8020c510(&p, lbl_803cc514, self->page + 1, (self->items.count - 1) / 20u + 1);
  fn_8020bf2c(&hdr, p.p);
 }
 fn_802cbf2c(&text, hdr.p, 7);
 int len = hdr.len();
 hdr = lbl_804b06a0[0];
 for (; len > 0; len--) fn_8020bf2c(&hdr, lbl_803cc524);
 fn_802cbf2c(&text, hdr.p, 7);
 unsigned first = self->page * 20;
 if (first >= (unsigned)self->items.count) { first = 0; self->page = 0; }
 unsigned a = first + 20, b = self->items.count;
 unsigned last = Min(a, b);
 unsigned i = first;
 if (i < last) {
  do {
   Str line;
   fn_8020c510(&line, lbl_803cc528, lbl_804abba0[i - first], w3d::VA(self->names[i].p), w3d::VA(((Ptr32<Item>)self->items.At(i))->label));
   fn_802cbf2c(&text, line.p, 9);
   i++;
  } while (i < last);
 }
 fn_802cd26c(&text, 0, 23);
 fn_802cbf2c(&text, lbl_803cc534, 7);
 fn_802cc0ac(&text, lbl_803cc57c, 7);
 fn_802cbdf8((int)w3d::H(self->sink), text.p, 9);
 self->f88 = 0;
 self->f92 = 0;
}


