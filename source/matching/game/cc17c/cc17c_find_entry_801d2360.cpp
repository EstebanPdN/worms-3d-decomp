/* Same source shape as the admitted list lookup 0x801d2098 (genparamc_801d2098.cpp): find an entry
 * through a helper returning an iterator; on success notify and return a pointer into the node. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct Cc17cIter {
    char *node;
    int pad;
    Cc17cIter() {}
    Cc17cIter(char *p) : node(p) {}
    Cc17cIter(const Cc17cIter &o) : node(o.node) {}
};
inline bool operator!=(const Cc17cIter &a, const Cc17cIter &b) { return a.node != b.node; }
struct Cc17cList {
    char *first;
    char *last;
    Cc17cIter end() const { return Cc17cIter(last); }
};
extern "C" void * fn_801d295c(Cc17cIter *, void *, void *, void *, Cc17cList *);
extern "C" void fn_801d2400(void *, Cc17cIter);

extern "C" int w3d_cc17c_find_entry_801d2360(void *self, void *key, void *arg, void **out)
{
    Cc17cList &list = FIELD(self, Cc17cList, 52);
    Cc17cIter it;
    fn_801d295c(&it, self, key, arg, &list);
    if (it != list.end()) {
        fn_801d2400(self, it);
        *out = it.node + 36;
        return 0;
    }
    *out = 0;
    return 0x80004005;
}
