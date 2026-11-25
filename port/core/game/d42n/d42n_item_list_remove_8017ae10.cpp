#include "w3d_ptr.h"
#line 1 "d42n_item_list_remove_8017ae10.cpp"
// GWMP8P rev0 0x8017ae10. Removes one item from a four-way parallel list:
// finds its slot, takes the matching key out of the owner's list, erases the
// slot from all four arrays and releases the item. If the item is absent it
// reads both names (discarded copies) and returns 0x80004005. Names are
// inferred from use.
extern "C" {
void w3d_string_base_init(Ptr32<void>);
void w3d_string_base_finish(Ptr32<void>);
void w3d_string_release(Ptr32<void>);
Ptr32<unsigned short> w3d_string_header(Ptr32<void>);
Ptr32<void> fn_802eee50(Ptr32<void>, Ptr32<const void>, unsigned int, ...);
}
struct Str {
  Ptr32<char> p;
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
};
inline void use(Str) {}
struct Named;
struct NamedVt { char q[68]; Ptr32<w3d::Ref32<const Str>(Ptr32<Named>)> text; };
struct Named { Ptr32<NamedVt> vt; };
struct Item;
struct ItemVt { char q[20]; Ptr32<int (Ptr32<Item>, int)> drop; char r[40]; Ptr32<Ptr32<Named> (Ptr32<Item>)> name; };
struct Item { Ptr32<ItemVt> vt; const Str &label() { Ptr32<Named> n = vt->name(this); return n->vt->text(n); } };
struct List { char p0[24]; unsigned int count; char p1c[4]; int data[1]; };
struct Owner { char p0[44]; Ptr32<List> list; };
extern "C" void fn_801ef380(Ptr32<Owner>, int, int, unsigned int, int);
extern "C" void w3d_cx15b_interface_range_remove_801f2a30(Ptr32<void>, Ptr32<int>, Ptr32<int>);
extern "C" void f4c_erase_80210dd8(Ptr32<void>, Ptr32<int>, Ptr32<int>);
struct Arr { int n; int m; Ptr32<int> start; };
struct ORef { Ptr32<Owner> p; };
struct OArr { int n; int m; Ptr32<ORef> start; };
struct Vec {
  Ptr32<Ptr32<Item>> begin; Ptr32<Ptr32<Item>> end_;
  void erase(Ptr32<Ptr32<Item>> i) {
    if (i + 1 != end_) { unsigned z = (Ptr32<char>)end_ - (Ptr32<char>)(i + 1); fn_802eee50(i, i + 1, z); }
    --end_;
  }
};
struct Self : Item {
  char p4[100] __attribute__((aligned(__alignof__(Item)))); Vec v; char p70[16]; Arr a; Arr b; OArr c;
};
extern "C" int w3d_d42n_item_list_remove_8017ae10(Ptr32<Self> self, Ptr32<Item> item) {
  Ptr32<Ptr32<Item>> i = self->v.begin;
  Ptr32<int> b = self->b.start;
  Ptr32<int> a = self->a.start;
  Ptr32<ORef> o = self->c.start;
  for (; i != self->v.end_; ++i, ++b, ++a, ++o) {
    if (*i == item) {
      if (o->p) {
        Ptr32<List> l = o->p->list;
        unsigned int n = l->count;
        Ptr32<int> d = l->data;
        for (unsigned int k = 0; k < n; ++k) {
          if (d[k] == *b) { fn_801ef380(o->p, 44, 3, k, 1); break; }
        }
      }
      Vec &rv = self->v; Arr &rb = self->b; Arr &ra = self->a; OArr &rc = self->c;
      rv.erase(i);
      w3d_cx15b_interface_range_remove_801f2a30(&rb, b, b + 1);
      f4c_erase_80210dd8(&ra, a, a + 1);
      w3d_cx15b_interface_range_remove_801f2a30(&rc, (Ptr32<int>)o, (Ptr32<int>)(o + 1));
      item->vt->drop(item, 0);
      return 0;
    }
  }
  use(item->label()), use(self->label());
  return 0x80004005;
}


