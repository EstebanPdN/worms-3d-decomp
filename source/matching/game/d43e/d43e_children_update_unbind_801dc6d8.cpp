// (Worms 3D GameCube PAL, 0x801dc6d8).
//
// Node teardown pass: updates every ready child of the child list (slot 7
// reports ready, slot 15 updates), then walks the bound list from the end
// calling the node's slot 21 with each entry's handle, keeps the last nonzero
// result, empties the bound list and returns that result.

struct Child {
    void **vt;
    char u4[32];
    void *handle;
    int Ready() { return ((int (*)(Child *))vt[7])(this); }
    int Update() { return ((int (*)(Child *))vt[15])(this); }
};
struct Array {
    unsigned count;
    int u4;
    Child **items;
    unsigned size() const { return count; }
    Child *get(unsigned i) const { return items[i]; }
};
extern "C" void w3d_d30k_compact_vector_resize_80210b90(Array *, int);
struct Self {
    void **vt;
    char u4[32];
    Array bound;
    Array children;
    int Detach(void *handle) { return ((int (*)(Self *, void *))vt[21])(this, handle); }
};
extern "C" int w3d_d43e_children_update_unbind_801dc6d8(Self *self) {
    int result = 0;
    unsigned i;
    Array *a;
    for (i = 0; i < self->children.size(); ++i) {
        a = &self->children;
        if (a->get(i) && a->get(i)->Ready() == 1)
            a->get(i)->Update();
    }
    a = &self->bound;
    for (unsigned t = a->size(); t != 0; --t) {
        Child *c = a->get(t - 1);
        if (c) {
            int r = self->Detach(c->handle);
            if (r) result = r;
        }
    }
    w3d_d30k_compact_vector_resize_80210b90(a, 0);
    return result;
}
