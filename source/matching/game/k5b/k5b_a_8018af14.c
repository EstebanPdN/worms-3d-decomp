struct K5bIface { void **vtable; };
struct K5bLinkedNode {
    char head[24];
    unsigned int flags;
    char pad[4];
    struct K5bIface *first;
    struct K5bIface *second;
    struct K5bIface *third;
};
static inline void k5b_release(struct K5bIface **slot, struct K5bIface *none)
{
    if (*slot != 0)
        ((void (*)(struct K5bIface *))(*slot)->vtable[4])(*slot);
    *slot = none;
}
int w3d_k5b_linked_node_detach_8018af14(struct K5bLinkedNode *self)
{
    struct K5bIface *none = 0;
    self->flags &= ~0x8000u;
    k5b_release(&self->third, none);
    k5b_release(&self->second, none);
    k5b_release(&self->first, none);
    return 0;
}
// desc: w3d_k5b_linked_node_detach_8018af14: Appears to clear flag 0x8000 at +24 and release the three held interfaces at +40, +36 and +32 through virtual slot 4, clearing each.
