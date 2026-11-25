// GWMP8P rev0 0x8017ae10. Removes one item from a four-way parallel list:
// finds its slot, takes the matching key out of the owner's list, erases the
// slot from all four arrays and releases the item. If the item is absent it
// reads both names (discarded copies) and returns 0x80004005. Names are
// inferred from use.
extern "C" {
void w3d_string_base_init(void *);
void w3d_string_base_finish(void *);
void w3d_string_release(void *);
unsigned short *w3d_string_header(void *);
void *fn_802eee50(void *, const void *, unsigned int, ...);
}
struct Str {
  char *p;
  Str(const Str &o) { w3d_string_base_init(this); p = o.p; ++*w3d_string_header(this); }
  ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
};
inline void use(Str) {}
struct Named;
struct NamedVt { char q[68]; const Str &(*text)(Named *); };
struct Named { NamedVt *vt; };
struct Item;
struct ItemVt { char q[20]; int (*drop)(Item *, int); char r[40]; Named *(*name)(Item *); };
struct Item { ItemVt *vt; const Str &label() { Named *n = vt->name(this); return n->vt->text(n); } };
struct List { char p0[24]; unsigned int count; char p1c[4]; int data[1]; };
struct Owner { char p0[44]; List *list; };
extern "C" void fn_801ef380(Owner *, int, int, unsigned int, int);
extern "C" void w3d_cx15b_interface_range_remove_801f2a30(void *, int *, int *);
extern "C" void f4c_erase_80210dd8(void *, int *, int *);
struct Arr { int n; int m; int *start; };
struct ORef { Owner *p; };
struct OArr { int n; int m; ORef *start; };
struct Vec {
  Item **begin; Item **end_;
  void erase(Item **i) {
    if (i + 1 != end_) { unsigned z = (char *)end_ - (char *)(i + 1); fn_802eee50(i, i + 1, z); }
    --end_;
  }
};
struct Self : Item {
  char p4[100]; Vec v; char p70[16]; Arr a; Arr b; OArr c;
};
extern "C" int w3d_d42n_item_list_remove_8017ae10(Self *self, Item *item) {
  Item **i = self->v.begin;
  int *b = self->b.start;
  int *a = self->a.start;
  ORef *o = self->c.start;
  for (; i != self->v.end_; ++i, ++b, ++a, ++o) {
    if (*i == item) {
      if (o->p) {
        List *l = o->p->list;
        unsigned int n = l->count;
        int *d = l->data;
        for (unsigned int k = 0; k < n; ++k) {
          if (d[k] == *b) { fn_801ef380(o->p, 44, 3, k, 1); break; }
        }
      }
      Vec &rv = self->v; Arr &rb = self->b; Arr &ra = self->a; OArr &rc = self->c;
      rv.erase(i);
      w3d_cx15b_interface_range_remove_801f2a30(&rb, b, b + 1);
      f4c_erase_80210dd8(&ra, a, a + 1);
      w3d_cx15b_interface_range_remove_801f2a30(&rc, (int *)o, (int *)(o + 1));
      item->vt->drop(item, 0);
      return 0;
    }
  }
  use(item->label()), use(self->label());
  return 0x80004005;
}
