/* Original 0x801d21fc uses the embedded list at +20. Same source shape as the admitted list lookup 0x801d2098 (genparamc_801d2098.cpp): find an entry
 * through a helper returning an iterator; on success notify and return a pointer into the node. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct Cc18bIter {
    char *node;
    int pad;
    Cc18bIter() {}
    Cc18bIter(char *p) : node(p) {}
    Cc18bIter(const Cc18bIter &o) : node(o.node) {}
};
inline bool operator!=(const Cc18bIter &a, const Cc18bIter &b) { return a.node != b.node; }
struct Cc18bList {
    char *first;
    char *last;
    Cc18bIter end() const { return Cc18bIter(last); }
};
extern "C" void * fn_801d295c(Cc18bIter *, void *, void *, void *, Cc18bList *);
extern "C" void fn_801d2400(void *, Cc18bIter);

extern "C" int w3d_cc18b_find_entry_801d21fc(void *self, void *key, void *arg, void **out)
{
    Cc18bList &list = FIELD(self, Cc18bList, 20);
    Cc18bIter it;
    fn_801d295c(&it, self, key, arg, &list);
    if (it != list.end()) {
        fn_801d2400(self, it);
        *out = it.node + 36;
        return 0;
    }
    *out = 0;
    return 0x80004005;
}
