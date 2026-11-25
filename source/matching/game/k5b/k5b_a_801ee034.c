struct K5bClass { char pad[20]; struct K5bClass *parent; };
struct K5bComponent { void **vtable; };
struct K5bComponentSet {
    char pad[24];
    unsigned int count;
    char pad28[4];
    struct K5bComponent *items[1];
};
static inline int k5b_class_derives(struct K5bClass *cls, struct K5bClass *base)
{
    while (cls != base) {
        if (cls == cls->parent)
            return 0;
        cls = cls->parent;
    }
    return 1;
}
struct K5bComponent *w3d_k5b_component_set_find_class_801ee034(struct K5bComponentSet *self, struct K5bClass *base)
{
    unsigned int i;
    struct K5bComponent **items = self->items;
    for (i = 0; i < self->count; i++) {
        struct K5bClass *cls = ((struct K5bClass *(*)(struct K5bComponent *))items[i]->vtable[5])(items[i]);
        if (k5b_class_derives(cls, base))
            return items[i];
    }
    return 0;
}
// desc: w3d_k5b_component_set_find_class_801ee034: Appears to return the first component in the inline array at +32 reports a class (virtual slot 5) derived from the given class, or null.
