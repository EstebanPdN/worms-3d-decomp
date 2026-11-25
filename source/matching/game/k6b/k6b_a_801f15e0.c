struct K6bSpan { int start; int end; };
struct K6bValueNode {
    void *base;
    void **vtable;
    char body[4];
    struct K6bSpan first;
    struct K6bSpan second;
};
struct K6bValueSource {
    char head[20];
    struct K6bSpan first;
    struct K6bSpan second;
};
extern void *lbl_804179a0[];
extern void *w3d_heap_allocate_entry_a(unsigned int size);
extern void w3d_auto_801eb058(struct K6bValueNode *node);
extern void w3d_set_801eb0a8(struct K6bValueNode *node, struct K6bValueSource *source);
extern int w3d_s12_append_value_801e8bc4(void *owner, struct K6bValueNode *node);
struct K6bValueNode *w3d_k6b_value_node_clone_801f15e0(void *owner, struct K6bValueSource *source)
{
    struct K6bValueNode *node = (struct K6bValueNode *)w3d_heap_allocate_entry_a(28);
    w3d_auto_801eb058(node);
    node->vtable = lbl_804179a0;
    w3d_set_801eb0a8(node, source);
    {
        struct K6bSpan first = source->first;
        struct K6bSpan second = source->second;
        node->second = second;
        node->first = first;
    }
    w3d_s12_append_value_801e8bc4(owner, node);
    return node;
}
// desc: w3d_k6b_value_node_clone_801f15e0: Appears to allocate a 28-byte node, construct it with vtable 0x804179a0, copy the source through 0x801eb0a8 and two spans, and append it to the owner.
