#include "w3d_ptr.h"
#line 1 "genparamc_801d2098.cpp"
/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Family template, 2026-10-22 (third session): find an entry in a list
 * through a helper returning an iterator; return a pointer into it. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
struct W3dIter {
    Ptr32<char> node;
    int pad;
    W3dIter() {}
    template <class W3dU> W3dIter(Ptr32<W3dU> w3d_p) : W3dIter((char *)w3d_p.get()) {}
 W3dIter(char *p) : node(p) {}
    W3dIter(const W3dIter &o) : node(o.node) {}
};
inline bool operator!=(const W3dIter &a, const W3dIter &b) { return a.node != b.node; }
struct W3dList {
    Ptr32<char> first;
    Ptr32<char> last;
    W3dIter end() const { return W3dIter(last); }
};
extern "C" Ptr32<void> fn_801d295c(Ptr32<W3dIter>, Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<W3dList>);
extern "C" void fn_801d2400(Ptr32<void>, W3dIter);

extern "C" int w3d_find_entry_801d2098(Ptr32<void> self, Ptr32<void> key, Ptr32<void> arg, Ptr32<Ptr32<void>> out)
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


