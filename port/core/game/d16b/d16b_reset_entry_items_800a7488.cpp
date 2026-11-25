#include "w3d_ptr.h"
#line 1 "d16b_reset_entry_items_800a7488.cpp"
// Input/selection state (same object as the 0x800a5fdc initializer): resets
// every item of one entry according to its type, announcing each item that
// returns to its idle state by sending the item's message and the entry name.
// Type 0 and 5 clear a latch, type 2 clears a word flag, type 1 resets a float
// value to 0.0 (sending it directly in mode 0, or clearing an armed flag in
// modes 1 and 2). Partial observed layouts; the 0.0 constant and cached names
// are original data referenced by address; no owned initialized data. Built
// with the original paired-single float switch (-mps-float), which reserves
// the 8 frame bytes that pair the saved FPR.
struct d16b_MessageKey { unsigned char bytes[8]; };
struct d16b_ResetItem {
    int unknown00;
    d16b_MessageKey key;
    int type;
    int unknown10;
    int idle;
    int latch;
    union { float level; int flag; };
    int mode;
    int armed;
};
struct d16b_ResetList {
    Ptr32<Ptr32<d16b_ResetItem>> first; Ptr32<Ptr32<d16b_ResetItem>> last;
    int capacity;
    Ptr32<Ptr32<d16b_ResetItem>> begin() { return first; }
    Ptr32<Ptr32<d16b_ResetItem>> end() { return last; }
};
struct d16b_ResetEntry {
    char name[36];
    d16b_ResetList items;
    int active;
};
struct d16b_ResetState;
extern "C" unsigned int w3d_cached_message_id(Ptr32<void>, int);
extern "C" void w3d_auto_800a7ab8(Ptr32<d16b_ResetState>, unsigned short);
extern "C" void s19_send_float_800a7ca0(Ptr32<d16b_ResetState>, unsigned short, float);
extern "C" void k5a_message_text_send_800a7b24(Ptr32<d16b_ResetState>, unsigned short, Ptr32<const char>);
extern d16b_MessageKey w3d_text_key_804ae298;
extern const float w3d_zero_80381490[];

extern "C" void d16b_reset_entry_items_800a7488(Ptr32<d16b_ResetState> self, Ptr32<d16b_ResetEntry> entry) {
    for (Ptr32<Ptr32<d16b_ResetItem>> p = entry->items.begin(); p != entry->items.end(); p++) {
        Ptr32<d16b_ResetItem> item = *p;
        switch (item->type) {
        case 0:
            if (item->latch != 0) {
                item->latch = 0;
                if (item->idle == 0) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                }
            }
            break;
        case 1:
            if (item->level != w3d_zero_80381490[0]) {
                switch (item->mode) {
                case 0:
                    s19_send_float_800a7ca0(self, w3d_cached_message_id(&item->key, 1), w3d_zero_80381490[0]);
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                    break;
                case 1:
                case 2:
                    if (item->armed != 0) {
                        item->level = w3d_zero_80381490[0];
                        item->armed = 0;
                        if (item->latch == 0) {
                            w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                            k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                        }
                    }
                    break;
                }
                item->level = w3d_zero_80381490[0];
            }
            break;
        case 2:
            if (item->flag != 0) {
                item->flag = 0;
                if (item->latch == 0) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                }
            }
            break;
        case 3:
        case 4:
            break;
        case 5:
            if (item->latch != 0) {
                item->latch = 0;
                if (item->idle == 0) {
                    w3d_auto_800a7ab8(self, w3d_cached_message_id(&item->key, 1));
                    k5a_message_text_send_800a7b24(self, w3d_cached_message_id(&w3d_text_key_804ae298, 1), entry->name + 1);
                }
            }
            break;
        }
    }
}


