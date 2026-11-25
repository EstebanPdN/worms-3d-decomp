#include "w3d_ptr.h"
#line 1 "d42n_property_tables_apply_80178108.cpp"
// GWMP8P rev0 0x80178108. Applies a source object's eight property tables to
// this object through its typed setter slots: integer, float and block
// values, keyed per entry. The setter slots return a status that is ignored
// here. Names are inferred from use.
struct Key { int id; };
struct Item { char u[20]; unsigned flags; int key; int value; };
struct FItem { char u[20]; unsigned flags; int key; float value; };
struct AItem { char u[20]; unsigned flags; int key; char value[4]; };
struct Tab { char u[24]; int count; int u1c; Ptr32<Item> items[1]; };
struct FTab { char u[24]; int count; int u1c; Ptr32<FItem> items[1]; };
struct ATab { char u[24]; int count; int u1c; Ptr32<AItem> items[1]; };
struct Src { char u[20]; Ptr32<ATab> t20; Ptr32<Tab> t24; Ptr32<Tab> t28; Ptr32<ATab> t32; Ptr32<FTab> t36; Ptr32<Tab> t40; Ptr32<Tab> t44; Ptr32<Tab> t48; };
struct Self;
typedef Ptr32<int (Ptr32<Self>, Ptr32<Key>, int, int, unsigned int)> SetInt;
typedef Ptr32<int (Ptr32<Self>, Ptr32<Key>, float, int, unsigned int)> SetFloat;
typedef Ptr32<int (Ptr32<Self>, Ptr32<Key>, Ptr32<void>, int, unsigned int)> SetBlock;
struct Vt {
 char u0[36];
 SetInt s36;
 SetInt s40;
 SetFloat s44;
 SetBlock s48;
 SetInt s52;
 SetInt s56;
 char u3c[4];
 SetBlock s64;
};
struct Self { Ptr32<Vt> vt; };
struct Count { int v; Count(int n) : v(n) {} int dec() { return --v; } };
extern "C" int w3d_d42n_property_tables_apply_80178108(Ptr32<Self> self, Ptr32<Src> s, int id) {
 unsigned mode = 1;
 if (id == 255) mode = 5;
 Ptr32<Tab> ta = s->t28; int na = ta->count; Ptr32<Ptr32<Item>> a = ta->items;
 Ptr32<FTab> tb = s->t36; int nb = tb->count; Ptr32<Ptr32<FItem>> b = tb->items;
 Ptr32<Tab> tc = s->t48; int nc = tc->count; Ptr32<Ptr32<Item>> c = tc->items;
 Ptr32<Tab> td = s->t40; int nd = td->count; Ptr32<Ptr32<Item>> d = td->items;
 Ptr32<Tab> te = s->t24; int ne = te->count; Ptr32<Ptr32<Item>> e = te->items;
 Ptr32<Tab> tf = s->t44; int nf = tf->count; Ptr32<Ptr32<Item>> f = tf->items;
 Ptr32<ATab> tg = s->t32; int ng = tg->count; Ptr32<Ptr32<AItem>> g = tg->items;
 Ptr32<ATab> th = s->t20; int nh = th->count; Ptr32<Ptr32<AItem>> h = th->items;
 { Count z(na); while (z.dec() != -1) { SetInt fn = self->vt->s56; Key k; k.id = (*a)->key; Ptr32<Item> i = *a++; fn(self, &k, i->value, id, i->flags | mode | 16); } }
 { Count z(nb); while (z.dec() != -1) { SetFloat fn = self->vt->s44; Key k; k.id = (*b)->key; Ptr32<FItem> i = *b++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(nc); while (z.dec() != -1) { SetInt fn = self->vt->s36; Key k; k.id = (*c)->key; Ptr32<Item> i = *c++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(nd); while (z.dec() != -1) { SetInt fn = self->vt->s52; Key k; k.id = (*d)->key; Ptr32<Item> i = *d++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(ne); while (z.dec() != -1) { SetInt fn = self->vt->s56; Key k; k.id = (*e)->key; Ptr32<Item> i = *e++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(nf); while (z.dec() != -1) { SetInt fn = self->vt->s40; Key k; k.id = (*f)->key; Ptr32<Item> i = *f++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(ng); while (z.dec() != -1) { SetBlock fn = self->vt->s48; Key k; k.id = (*g)->key; Ptr32<AItem> i = *g++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(nh); while (z.dec() != -1) { SetBlock fn = self->vt->s64; Key k; k.id = (*h)->key; Ptr32<AItem> i = *h++; fn(self, &k, i->value, id, i->flags | mode); } }
 return 0;
}


