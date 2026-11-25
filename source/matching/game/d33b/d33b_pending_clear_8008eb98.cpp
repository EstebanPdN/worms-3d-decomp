// GWMP8P rev0 0x8008eb98. Clears the two pending lists. The list start pointer
// is plain; the arm reloads it because the pending value goes to the refresh
// helper by const reference, so it is an address-taken local while CSE runs.
/* Clear the two pending lists (0x8008eb98): for each entry of the list 0x80431e94
 * whose object has a +80 state with a non-zero +24 runs 0x801ef380 (80, 10, 0), then
 * erases all entries of the lists 0x80431e88 and 0x80431e94. Names are inferred; the
 * lists are external views of original data. */
extern "C" void w3d_notify_801ef380(void *, int, int, int, int);
extern "C" void *w3d_copy_802eee50(...);
struct State { char unknown00[24]; int pending; };
struct Item { char unknown00[80]; State *state; };
struct Pair { int key; Item *item; };
struct PairList {
    Pair *begin; Pair *end; Pair *capacity;
    unsigned size() const { return end - begin; }
    Pair &operator[](unsigned i) { return begin[i]; }
    void clear() {
        Pair *first = begin, *last = end;
        int removed = (char *)last - (char *)first;
        w3d_copy_802eee50(first, last, 0);
        end = (Pair *)((char *)end - removed);
    }
};
extern PairList w3d_list_80431e88, w3d_list_80431e94;
inline void Refresh(Item *item, const int &value) { w3d_notify_801ef380(item, 80, 10, 0, value); }

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
