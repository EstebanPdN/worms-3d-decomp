// GWMP8P rev0 0x80178108. Applies a source object's eight property tables to
// this object through its typed setter slots: integer, float and block
// values, keyed per entry. The setter slots return a status that is ignored
// here. Names are inferred from use.
struct Key { int id; };
struct Item { char u[20]; unsigned flags; int key; int value; };
struct FItem { char u[20]; unsigned flags; int key; float value; };
struct AItem { char u[20]; unsigned flags; int key; char value[4]; };
struct Tab { char u[24]; int count; int u1c; Item *items[1]; };
struct FTab { char u[24]; int count; int u1c; FItem *items[1]; };
struct ATab { char u[24]; int count; int u1c; AItem *items[1]; };
struct Src { char u[20]; ATab *t20; Tab *t24; Tab *t28; ATab *t32; FTab *t36; Tab *t40; Tab *t44; Tab *t48; };
struct Self;
typedef int (*SetInt)(Self *, Key *, int, int, unsigned);
typedef int (*SetFloat)(Self *, Key *, float, int, unsigned);
typedef int (*SetBlock)(Self *, Key *, void *, int, unsigned);
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
struct Self { Vt *vt; };
struct Count { int v; Count(int n) : v(n) {} int dec() { return --v; } };
extern "C" int w3d_d42n_property_tables_apply_80178108(Self *self, Src *s, int id) {
 unsigned mode = 1;
 if (id == 255) mode = 5;
 Tab *ta = s->t28; int na = ta->count; Item **a = ta->items;
 FTab *tb = s->t36; int nb = tb->count; FItem **b = tb->items;
 Tab *tc = s->t48; int nc = tc->count; Item **c = tc->items;
 Tab *td = s->t40; int nd = td->count; Item **d = td->items;
 Tab *te = s->t24; int ne = te->count; Item **e = te->items;
 Tab *tf = s->t44; int nf = tf->count; Item **f = tf->items;
 ATab *tg = s->t32; int ng = tg->count; AItem **g = tg->items;
 ATab *th = s->t20; int nh = th->count; AItem **h = th->items;
 { Count z(na); while (z.dec() != -1) { SetInt fn = self->vt->s56; Key k; k.id = (*a)->key; Item *i = *a++; fn(self, &k, i->value, id, i->flags | mode | 16); } }
 { Count z(nb); while (z.dec() != -1) { SetFloat fn = self->vt->s44; Key k; k.id = (*b)->key; FItem *i = *b++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(nc); while (z.dec() != -1) { SetInt fn = self->vt->s36; Key k; k.id = (*c)->key; Item *i = *c++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(nd); while (z.dec() != -1) { SetInt fn = self->vt->s52; Key k; k.id = (*d)->key; Item *i = *d++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(ne); while (z.dec() != -1) { SetInt fn = self->vt->s56; Key k; k.id = (*e)->key; Item *i = *e++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(nf); while (z.dec() != -1) { SetInt fn = self->vt->s40; Key k; k.id = (*f)->key; Item *i = *f++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(ng); while (z.dec() != -1) { SetBlock fn = self->vt->s48; Key k; k.id = (*g)->key; AItem *i = *g++; fn(self, &k, i->value, id, i->flags | mode); } }
 { Count z(nh); while (z.dec() != -1) { SetBlock fn = self->vt->s64; Key k; k.id = (*h)->key; AItem *i = *h++; fn(self, &k, i->value, id, i->flags | mode); } }
 return 0;
}
