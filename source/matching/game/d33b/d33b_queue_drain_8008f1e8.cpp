// GWMP8P rev0 0x8008f1e8. Queue drain. The list start pointer is plain; the arm
// reloads it because the value goes to the refresh helper by const reference.
/* Queue drain (0x8008f1e8): refreshes the items of the active list 0x80431e94 whose entry
 * has a pending value (0x801ef380), pops the entry list 0x80431e88 from the back until one
 * is handled, clearing +109 and running 0x8008ed58 and 0x8008e9c0 for entries with +107
 * set, and when the flag is set pops the active list while 0x8008ee80 reports progress,
 * clearing +108 and +104. Returns the handled flag. Field and type names are inferred
 * from the original instructions. The unit owns no data. */
struct Pending { char unknown00[24]; int value; };
struct Item {
    char unknown00[80];
    Pending *pending;   /* +80 */
    char unknown84[20];
    unsigned short count; /* +104 */
    char unknown106;
    unsigned char ready;  /* +107 */
    unsigned char active; /* +108 */
    unsigned char queued; /* +109 */
};
struct Entry { void *first; Item *item; };
struct EntryList {
    Entry *begin; Entry *end; Entry *capacity;
    unsigned size() const { return end - begin; }
    Entry &operator[](unsigned i) { return begin[i]; }
    Entry &back() { return (*this)[size() - 1]; }
    void pop_back() { --end; }
};
extern EntryList w3d_entries_80431e88;
extern EntryList w3d_active_80431e94;
struct Owner;
extern "C" void w3d_refresh_801ef380(Item *, int, int, int, int);
extern "C" int sol35a_camera_group_8008ed58(Owner *, Entry *);
extern "C" void w3d_d24b_queue_input_8008e9c0(void *, Item *);
extern "C" int w3d_step_8008ee80(Owner *, Entry *, int *);

inline void Refresh(Item *item, const int &value) { w3d_refresh_801ef380(item, 80, 10, 0, value); }

extern "C" int d33b_queue_drain_8008f1e8(Owner *self, int flag)
{
    int handled = 0;
    for (unsigned i = 0; i < w3d_active_80431e94.size(); i++) {
        int value = w3d_active_80431e94[i].item->pending->value;
        if (value) Refresh(w3d_active_80431e94[i].item, value);
    }
    while (w3d_entries_80431e88.size() != 0 && !handled) {
        Entry *b = w3d_entries_80431e88.begin;
        unsigned n = w3d_entries_80431e88.end - b;
        Entry &e = b[n - 1];
        e.item->queued = 0;
        if (e.item->ready) {
            if (sol35a_camera_group_8008ed58(self, &e)) w3d_d24b_queue_input_8008e9c0(e.first, e.item);
            handled = 1;
        }
        w3d_entries_80431e88.pop_back();
    }
    if (flag) {
        while (w3d_active_80431e94.size() != 0 && !handled) {
            Entry *b = w3d_active_80431e94.begin;
            unsigned n = w3d_active_80431e94.end - b;
            Entry &e = b[n - 1];
            if (w3d_step_8008ee80(self, &e, &handled)) {
                int zero = 0;
                e.item->active = zero;
                e.item->count = zero;
                w3d_active_80431e94.pop_back();
            }
        }
    }
    return handled;
}
