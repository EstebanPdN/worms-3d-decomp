#include "w3d_ptr.h"
#line 1 "cc17c_find_entry_801d2360.cpp"
/* Same source shape as the admitted list lookup 0x801d2098 (genparamc_801d2098.cpp): find an entry
 * through a helper returning an iterator; on success notify and return a pointer into the node. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
struct Cc17cIter {
    Ptr32<char> node;
    int pad;
    Cc17cIter() {}
    template <class W3dU> Cc17cIter(Ptr32<W3dU> w3d_p) : Cc17cIter((char *)w3d_p.get()) {}
 Cc17cIter(char *p) : node(p) {}
    Cc17cIter(const Cc17cIter &o) : node(o.node) {}
};
inline bool operator!=(const Cc17cIter &a, const Cc17cIter &b) { return a.node != b.node; }
struct Cc17cList {
    Ptr32<char> first;
    Ptr32<char> last;
    Cc17cIter end() const { return Cc17cIter(last); }
};
extern "C" Ptr32<void> fn_801d295c(Ptr32<Cc17cIter>, Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<Cc17cList>);
extern "C" void fn_801d2400(Ptr32<void>, Cc17cIter);

extern "C" int w3d_cc17c_find_entry_801d2360(Ptr32<void> self, Ptr32<void> key, Ptr32<void> arg, Ptr32<Ptr32<void>> out)
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


