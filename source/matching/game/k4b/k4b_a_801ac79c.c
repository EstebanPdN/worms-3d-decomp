struct K4bTreeNode {
    int color;
    struct K4bTreeNode *parent;
    struct K4bTreeNode *left;
    struct K4bTreeNode *right;
    int value;
};
struct K4bTree {
    int base;
    struct K4bTreeNode *header;
    int count;
    unsigned char compare;
};
struct K4bPair { int first; int second; };
struct K4bLink { void *node; int count; };
struct K4bLookupComponent {
    void **vtable;
    char base[36];
    int field_28;
    int field_2c;
    char pad30[36];
    int field_54;
    char pad58[8];
    int field_60;
    struct K4bTree tree;
    struct K4bPair range;
    struct K4bLink link;
    int field_84;
};
extern void *lbl_80414088[];
extern void *lbl_80414040[];
extern void * fn_801e81c8(void *member);
extern void *w3d_handle_storage_allocate(unsigned int bytes);
extern void *w3d_handle_storage_fallback(unsigned int bytes);
static inline void *k4b_node_allocate(unsigned int bytes)
{
    void *p = w3d_handle_storage_allocate(bytes);
    if (p == 0)
        p = w3d_handle_storage_fallback(bytes);
    return p;
}
static inline void k4b_tree_init(struct K4bTree *tree)
{
    tree->header = 0;
    tree->header = (struct K4bTreeNode *)k4b_node_allocate(sizeof(struct K4bTreeNode));
    tree->count = 0;
    tree->compare = 0;
    tree->header->color = 0;
    tree->header->parent = 0;
    tree->header->left = tree->header;
    tree->header->right = tree->header;
}
static inline void k4b_pair_init(struct K4bPair *p)
{
    p->first = 0;
    p->second = 0;
}
static inline void k4b_link_init(struct K4bLink *l)
{
    l->count = 0;
}
struct K4bLookupComponent *w3d_k4b_lookup_component_construct_801ac79c(struct K4bLookupComponent *self)
{
    volatile char pad[24];
    self->vtable = lbl_80414088;
    fn_801e81c8(self->base);
    self->vtable = lbl_80414040;
    self->field_28 = 0;
    self->field_60 = 0;
    k4b_tree_init(&self->tree);
    k4b_pair_init(&self->range);
    k4b_link_init(&self->link);
    self->field_84 = 0;
    self->field_54 = 0;
    self->field_2c = 0;
    return self;
}
// desc: w3d_k4b_lookup_component_construct_801ac79c: Appears to construct a component with an ordered tree (20-byte header node from handle storage), a zeroed range pair, a link and cleared fields.
