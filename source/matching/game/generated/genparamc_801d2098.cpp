/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family template, 2026-10-22 (third session): find an entry in a list
 * through a helper returning an iterator; return a pointer into it. */
#define FIELD(p, T, o) (*(T *)((char *)(p) + (o)))
struct W3dIter {
    char *node;
    int pad;
    W3dIter() {}
    W3dIter(char *p) : node(p) {}
    W3dIter(const W3dIter &o) : node(o.node) {}
};
inline bool operator!=(const W3dIter &a, const W3dIter &b) { return a.node != b.node; }
struct W3dList {
    char *first;
    char *last;
    W3dIter end() const { return W3dIter(last); }
};
extern "C" void * fn_801d295c(W3dIter *, void *, void *, void *, W3dList *);
extern "C" void fn_801d2400(void *, W3dIter);

extern "C" int w3d_find_entry_801d2098(void *self, void *key, void *arg, void **out)
{
    W3dList &list = FIELD(self, W3dList, 36);
    W3dIter it;
    fn_801d295c(&it, self, key, arg, &list);
    if (it != list.end()) {
        fn_801d2400(self, it);
        *out = it.node + 36;
        return 0;
    }
    *out = 0;
    return 0x80004005;
}
