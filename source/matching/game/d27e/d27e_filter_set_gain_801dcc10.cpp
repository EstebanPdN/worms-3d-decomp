// (Worms 3D GameCube PAL, 0x801dcc10).
//
// Float property setter of a filter chain: clamps the value to [0, 1], then
// for ids 17, 18 and 19 finds the first child whose kind (slot 7) is 2, 4 or
// 1 and forwards the value to its slot 13; returns 1 when the id or the
// child is unknown. The filter meaning is inferred from the sibling setter
// 0x801dcdc0.

struct Child { void **vt; };
struct Array {
    unsigned count; int u; Child **items;
    unsigned size() const { return count; }
    Child *get(unsigned i) const { return items[i]; }
};
struct Filter { char u0[48]; Array children; };
extern "C" int w3d_d27e_filter_set_gain_801dcc10(Filter *self, int id, float *val) {
    unsigned i;
    if (*val > 1.0f) *val = 1.0f;
    else if (*val < 0.0f) *val = 0.0f;
    switch (id) {
    case 17:
        for (i = 0; i < self->children.size(); ++i) {
            Child *c = self->children.get(i);
            if (((int (*)(Child *))c->vt[7])(c) == 2) goto found2;
        }
        goto done;
    case 18:
        for (i = 0; i < self->children.size(); ++i) {
            Child *c = self->children.get(i);
            if (((int (*)(Child *))c->vt[7])(c) == 4) goto found4;
        }
        goto done;
    found2: {
            Child *d = self->children.get(i);
            return ((int (*)(Child *, float))d->vt[13])(d, *val);
        }
    found4: {
            Child *d = self->children.get(i);
            return ((int (*)(Child *, float))d->vt[13])(d, *val);
        }
    found1: {
            Child *d = self->children.get(i);
            return ((int (*)(Child *, float))d->vt[13])(d, *val);
        }
    case 19:
        for (i = 0; i < self->children.size(); ++i) {
            Child *c = self->children.get(i);
            if (((int (*)(Child *))c->vt[7])(c) == 1) goto found1;
        }
        goto done;
    }
done:
    return 1;
}
