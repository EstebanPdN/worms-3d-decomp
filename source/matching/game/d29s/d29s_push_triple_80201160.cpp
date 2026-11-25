/* Zeroes a three-word record, fills it from the arguments, appends it to the vector
 * at +44 and returns 0. */
#include "compat/stlport_sn_oom.h"
#include <vector>

extern "C" void *d29s_memset_802eefe0(void *, int, ...);
struct D29sTriple_80201160 {
    int a, b, c;
    D29sTriple_80201160() { d29s_memset_802eefe0(this, 0, sizeof(*this)); }
};
struct D29sOwner_80201160 { char head[44]; std::vector<D29sTriple_80201160> items; };

extern "C" int d29s_push_triple_80201160(D29sOwner_80201160 *owner, int a, int b, int c) {
    D29sTriple_80201160 item;
    item.a = a;
    item.b = b;
    item.c = c;
    owner->items.push_back(item);
    return 0;
}
