#include "w3d_ptr.h"
#line 1 "cc18b_find_entry_801d21fc.cpp"
/* Original 0x801d21fc uses the embedded list at +20. Same source shape as the admitted list lookup 0x801d2098 (genparamc_801d2098.cpp): find an entry
 * through a helper returning an iterator; on success notify and return a pointer into the node. */
#define FIELD(p, T, o) (*(w3d::slot_t<T> *)w3d::AG((char *)w3d::AG(p) + (o)))
struct Cc18bIter {
    Ptr32<char> node;
    int pad;
    Cc18bIter() {}
    template <class W3dU> Cc18bIter(Ptr32<W3dU> w3d_p) : Cc18bIter((char *)w3d_p.get()) {}
 Cc18bIter(char *p) : node(p) {}
    Cc18bIter(const Cc18bIter &o) : node(o.node) {}
};
inline bool operator!=(const Cc18bIter &a, const Cc18bIter &b) { return a.node != b.node; }
struct Cc18bList {
    Ptr32<char> first;
    Ptr32<char> last;
    Cc18bIter end() const { return Cc18bIter(last); }
};
extern "C" Ptr32<void> fn_801d295c(Ptr32<Cc18bIter>, Ptr32<void>, Ptr32<void>, Ptr32<void>, Ptr32<Cc18bList>);
extern "C" void fn_801d2400(Ptr32<void>, Cc18bIter);

extern "C" int w3d_cc18b_find_entry_801d21fc(Ptr32<void> self, Ptr32<void> key, Ptr32<void> arg, Ptr32<Ptr32<void>> out)
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


