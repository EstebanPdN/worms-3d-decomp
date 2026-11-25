// func: w3d_test_800bb4e4 0x800bb4e4
struct Child;
struct Group { char pad0[24]; unsigned count; void *pad28[1]; struct Child *items[1]; };
struct Child { char pad[44]; struct Group *group; };
unsigned w3d_test_800bb4e4(struct Child *c)
{
    struct Group *g = c->group;
    unsigned i = 0;
    unsigned n = g->count;
    unsigned sum = n;
    struct Child **items = g->items;
    if (i < sum) {
        struct Child **pp = items;
        do {
            struct Child *k = *pp;
            i++;
            pp++;
            sum += w3d_test_800bb4e4(k);
        } while (i < n);
    }
    return sum;
}
