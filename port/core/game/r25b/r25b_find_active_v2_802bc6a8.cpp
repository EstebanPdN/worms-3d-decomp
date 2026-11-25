#include "w3d_ptr.h"
#line 1 "r25b_find_active_v2_802bc6a8.cpp"
// Inferred active-entry lookup. Observed: vector at +0x38, active word at
// entry +0x10. The key getter at 0x802bd2bc remains an external dependency.
struct R25bActiveEntry {
    unsigned reserved[4];
    int active;
};
struct R25bEntryVector {
    Ptr32<Ptr32<R25bActiveEntry>> begin;
    Ptr32<Ptr32<R25bActiveEntry>> end;
};
struct R25bActiveOwner {
    unsigned char reserved[0x38];
    R25bEntryVector entries;
};
extern int r25b_entry_key_802bd2bc(Ptr32<R25bActiveEntry>);
extern "C" int w3d_r25b_find_active_v2_802bc6a8(Ptr32<R25bActiveOwner> owner, int key)
{
    Ptr32<R25bEntryVector> entries = &owner->entries;
    int result = -1;
    int index = 0;
    for (Ptr32<Ptr32<R25bActiveEntry>> entry = entries->begin;
         entry != entries->end; ++index, ++entry) {
        if ((*entry)->active && r25b_entry_key_802bd2bc(*entry) == key) {
            result = index;
            break;
        }
    }
    return result;
}


