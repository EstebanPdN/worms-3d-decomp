#include "w3d_ptr.h"
#line 1 "d33b_pending_clear_8008eb98.cpp"
// GWMP8P rev0 0x8008eb98. Clears the two pending lists. The list start pointer
// is plain; the arm reloads it because the pending value goes to the refresh
// helper by const reference, so it is an address-taken local while CSE runs.
/* Clear the two pending lists (0x8008eb98): for each entry of the list 0x80431e94
 * whose object has a +80 state with a non-zero +24 runs 0x801ef380 (80, 10, 0), then
 * erases all entries of the lists 0x80431e88 and 0x80431e94. Names are inferred; the
 * lists are external views of original data. */
extern "C" void w3d_notify_801ef380(Ptr32<void>, int, int, int, int);
extern "C" Ptr32<void> w3d_copy_802eee50(...);
struct State { char unknown00[24]; int pending; };
struct Item { char unknown00[80]; Ptr32<State> state; };
struct Pair { int key; Ptr32<Item> item; };
struct PairList {
    Ptr32<Pair> begin; Ptr32<Pair> end; Ptr32<Pair> capacity;
    unsigned size() const { return end - begin; }
    Pair &operator[](unsigned i) { return begin[i]; }
    void clear() {
        Ptr32<Pair> first = begin; Ptr32<Pair> last = end;
        int removed = (Ptr32<char>)last - (Ptr32<char>)first;
        w3d_copy_802eee50(w3d::VA(first), w3d::VA(last), 0);
        end = (Ptr32<Pair>)((Ptr32<char>)end - removed);
    }
};
extern PairList w3d_list_80431e88, w3d_list_80431e94;
inline void Refresh(Ptr32<Item> item, const int &value) { w3d_notify_801ef380(item, 80, 10, 0, value); }

extern "C" void d33b_pending_clear_8008eb98()
{
    for (unsigned i = 0; i < w3d_list_80431e94.size(); i++) {
        int pending = w3d_list_80431e94[i].item->state->pending;
        if (pending)
            Refresh(w3d_list_80431e94[i].item, pending);
    }
    w3d_list_80431e88.clear();
    w3d_list_80431e94.clear();
}


