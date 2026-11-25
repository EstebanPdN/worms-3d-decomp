struct K4bIface { void **vtable; };
struct K4bRefVector {
    unsigned int count;
    unsigned int capacity;
    struct K4bIface **items;
};
struct K4bGroup {
    char pad0[52];
    struct K4bRefVector children;
};
extern void fn_801f29d0(struct K4bRefVector *vector, unsigned int count);
extern int w3d_s10_has_ancestor_801b1de0(struct K4bGroup *self, void *parent);
static inline void k4b_ref_assign(struct K4bIface **slot, struct K4bIface *value)
{
    if (value != 0)
        ((void (*)(struct K4bIface *))value->vtable[3])(value);
    if (*slot != 0)
        ((void (*)(struct K4bIface *))(*slot)->vtable[4])(*slot);
    *slot = value;
}
static inline void k4b_vec_push(struct K4bRefVector *v, struct K4bIface *x)
{
    fn_801f29d0(v, v->count + 1);
    k4b_ref_assign(&v->items[v->count], x);
    v->count++;
}
int w3d_k4b_group_add_child_801b1cb8(struct K4bGroup *self, struct K4bIface *child)
{
    if (child == 0)
        return 0x80070057;
    k4b_vec_push(&self->children, child);
    w3d_s10_has_ancestor_801b1de0(self, ((void *(*)(struct K4bIface *))child->vtable[5])(child));
    return 0;
}
// desc: w3d_k4b_group_add_child_801b1cb8: Appears to append a retained child interface to a group's child vector and check its parent through 0x801b1de0; returns E_INVALIDARG for a null child.
