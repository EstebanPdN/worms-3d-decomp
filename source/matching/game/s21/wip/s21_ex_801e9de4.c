// desc: Appears to walk a circular chain of registry nodes from the given one and return the first node whose item list contains an entry with the requested class byte, or zero.
struct S21Info { char pad[6]; unsigned char klass; };
struct S21Item { struct S21Info *info; };
struct S21Node;
struct S21NodeMethods { void (*reserved[8])(void); int (*count)(struct S21Node *); };
struct S21Node { struct S21NodeMethods *methods; char pad[16]; struct S21Node *next; char pad1[24]; struct S21Item **items; };
extern struct S21Node lbl_80365788[];
struct S21Node *w3d_s21_find_node_801e9de4(struct S21Node *node, int klass)
{
    struct S21Node *end = lbl_80365788;
    if (node == end)
        return 0;
    do {
        int count = node->methods->count(node);
        int i = 0;
        if (i < count) {
            struct S21Item **item = node->items;
            do {
                struct S21Item *current = *item;
                item++;
                if (current->info->klass == klass)
                    return node;
                i++;
            } while (i < count);
        }
        node = node->next;
    } while (node != end);
    return 0;
}
