typedef struct S10Node {
    char reserved[20];
    struct S10Node *parent;
} S10Node;
typedef struct S10NodeList {
    char reserved[40];
    S10Node **begin;
    S10Node **end;
} S10NodeList;
static __inline__ int s10_is_descendant(S10Node *node, const S10Node *ancestor)
{
    while (node != ancestor) {
        S10Node *parent = node->parent;
        if (node == parent)
            return 0;
        node = parent;
    }
    return 1;
}
int w3d_s10_has_ancestor_801b1de0(const S10NodeList *list, S10Node *node)
{
    S10Node **end = list->end;
    S10Node **entry = list->begin;
    while (entry != end) {
        if (s10_is_descendant(node, *entry))
            return 1;
        ++entry;
    }
    return 0;
}
